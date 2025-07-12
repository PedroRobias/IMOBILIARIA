#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <sstream>

#include "Corretor.h"
#include "Cliente.h"
#include "Imovel.h"

constexpr double EARTH_R = 6371.0; // raio da Terra em km

double haversine(double lat1, double lon1, double lat2, double lon2) {
    auto deg2rad = [](double d){ return d * M_PI / 180.0; };
    double dlat = deg2rad(lat2 - lat1);
    double dlon = deg2rad(lon2 - lon1);
    double a = std::pow(std::sin(dlat/2), 2) +
               std::cos(deg2rad(lat1)) * std::cos(deg2rad(lat2)) *
               std::pow(std::sin(dlon/2), 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    return EARTH_R * c;
}

std::string minutoshora(int minutos) {   //conversão de minutos para hora
    int h = minutos / 60;
    int m = minutos % 60;
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << h << ":"
        << std::setfill('0') << std::setw(2) << m;
    return oss.str();
}

int main() {
    std::istream& entrada = std::cin;

    int nCorretores, nClientes, nImoveis;   //define a quantidade de cada "classe"

    entrada >> nCorretores;
    entrada.ignore();
    std::vector<Corretor> corretores(nCorretores);
    for (auto& c : corretores) c.lerDados(entrada);

    entrada >> nClientes;
    entrada.ignore();
    std::vector<Cliente> clientes(nClientes);
    for (auto& c : clientes) c.lerDados(entrada);

    entrada >> nImoveis;
    entrada.ignore();
    std::vector<Imovel> imoveis(nImoveis);
    for (auto& i : imoveis) i.lerDados(entrada);

    // verificação de corretores que são avaliadores
    std::vector<Corretor*> avaliadores;
    for (auto& c : corretores)
        if (c.isAvaliador())
            avaliadores.push_back(&c);

    if (avaliadores.empty()) {
        std::cout << "Nenhum avaliador encontrado.\n";
        return 1;
    }

    // Distribuir imóveis para avaliadores sequencialmente
    std::vector<std::vector<const Imovel*>> visitas(avaliadores.size());
    for (size_t i = 0; i < imoveis.size(); ++i) {
        visitas[i % avaliadores.size()].push_back(&imoveis[i]);
    }

    const int horaInicial = 9 * 60; // 9:00 em minutos

    // Imprimir agenda de visitas
    for (size_t i = 0; i < avaliadores.size(); ++i) {
        std::cout << "Corretor " << avaliadores[i]->getId() << "\n";
        int minutosAtual = horaInicial;
        double latAtual = avaliadores[i]->getLat();
        double lngAtual = avaliadores[i]->getLng();

        for (const Imovel* im : visitas[i]) {
            double dist = haversine(latAtual, lngAtual, im->getLat(), im->getLng());
            minutosAtual += static_cast<int>(dist * 2); // 2 minutos por km
            std::cout << minutoshora(minutosAtual) << " Imóvel " << im->getId() << "\n";
            minutosAtual += 60; // duração da visita
            latAtual = im->getLat();
            lngAtual = im->getLng();
        }
        std::cout << "\n";
    }

    return 0;
}
