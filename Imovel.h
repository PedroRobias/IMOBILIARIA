#ifndef IMOVEL_H
#define IMOVEL_H

#include <string>
#include <iostream>

enum TipoImovel { Casa, Apartamento, Terreno };

TipoImovel stringParaTipo(const std::string& s);

class Imovel {
private:
    static int nextId;
    int id;
    TipoImovel tipo;
    int proprietarioId;
    double lat, lng;
    std::string endereco;
    double preco;

public:
    Imovel();
    void lerDados(std::istream& in);
    int getId() const;
    TipoImovel getTipo() const;
    int getProprietarioId() const;
    double getLat() const;
    double getLng() const;
    std::string getEndereco() const;
    double getPreco() const;
};

#endif
