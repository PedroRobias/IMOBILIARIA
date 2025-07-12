#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <iostream>

class Cliente {
private:
    static int nextId;    //ID dinâmico
    int id;
    std::string telefone;
    std::string nome;

public:
    Cliente();
    void lerDados(std::istream& in);   
    int getId() const;
    std::string getNome() const; //ler dados em string
    std::string getTelefone() const; //ler dados em string
};

#endif
