#include "Cliente.h"
#include <sstream>

int Cliente::nextId = 1;

Cliente::Cliente() {
    id = nextId++;   //Incrementa o ID
}

void Cliente::lerDados(std::istream& in) {
    in >> telefone;
    std::getline(in >> std::ws, nome);
}

int Cliente::getId() const { return id; }     //DEFINE ID
std::string Cliente::getNome() const { return nome; }  //obtém o nome na string
std::string Cliente::getTelefone() const { return telefone; } //obtém o telefone na string
