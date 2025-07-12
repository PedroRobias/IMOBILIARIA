#include "Imovel.h"
#include <stdexcept>
#include <sstream>

int Imovel::nextId = 1;

TipoImovel stringParaTipo(const std::string& s) {
    if (s == "Casa") return Casa;
    if (s == "Apartamento") return Apartamento;
    if (s == "Terreno") return Terreno;
    throw std::invalid_argument("Tipo inválido");
}

Imovel::Imovel() {
    id = nextId++;
}

void Imovel::lerDados(std::istream& in) {
    std::string tipoStr;
    in >> tipoStr >> proprietarioId >> lat >> lng >> preco;
    std::getline(in >> std::ws, endereco);
    tipo = stringParaTipo(tipoStr);
}

int Imovel::getId() const { return id; }
TipoImovel Imovel::getTipo() const { return tipo; }
int Imovel::getProprietarioId() const { return proprietarioId; }
double Imovel::getLat() const { return lat; }
double Imovel::getLng() const { return lng; }
std::string Imovel::getEndereco() const { return endereco; }
double Imovel::getPreco() const { return preco; }
