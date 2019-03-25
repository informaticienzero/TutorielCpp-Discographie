#ifndef DONNEES_DISCO_HPP_INCLUDED
#define DONNEES_DISCO_HPP_INCLUDED

#include <string>
#include <iostream>
#include <vector>

struct Artiste
{
    std::string nom;
};

std::ostream & operator<<(std::ostream & sortie, Artiste const & artiste);

struct Album
{
    std::string nom;
};

std::ostream & operator<<(std::ostream & sortie, Album const & album);

struct Morceau
{
    std::string nom;
    Artiste compositeur;
    Album album;
};

std::ostream & operator<<(std::ostream & sortie, Morceau const & morceau);
std::istream & operator>>(std::istream & entree, Morceau & morceau);

using Discographie = std::vector<Morceau>;

#endif