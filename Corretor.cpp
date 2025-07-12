#include "Corretor.h"
#include <sstream>
#include <iostream>

int Corretor::nextId = 1;

Corretor::Corretor() {
    id = nextId++;
}

void Corretor::lerDados(std::istream& in) {
    int av;
    in >> telefone >> av >> lat >> lng;
    avaliador = (av == 1);
    std::getline(in >> std::ws, nome);
}

int Corretor::getId() const { return id; }
std::string Corretor::getNome() const { return nome; }
std::string Corretor::getTelefone() const { return telefone; }
bool Corretor::isAvaliador() const { return avaliador; }
double Corretor::getLat() const { return lat; }
double Corretor::getLng() const { return lng; }
