#ifndef CORRETOR_H
#define CORRETOR_H

#include <string>
#include <iostream>

enum AvaliadorStatus { FALSE = 0, TRUE = 1 };   //Boolean Avaliador

class Corretor {
private:
    static int nextId;
    int id;
    std::string telefone;
    std::string nome;
    bool avaliador;
    double lat, lng;

public:
    Corretor();
    void lerDados(std::istream& in);
    int getId() const;
    std::string getNome() const;
    std::string getTelefone() const;
    bool isAvaliador() const;
    double getLat() const;
    double getLng() const;
};

#endif
