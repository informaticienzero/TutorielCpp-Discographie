#ifndef DISCOGRAPHIE_HPP_INCLUDED
#define DISCOGRAPHIE_HPP_INCLUDED

#include "donnees_disco.hpp"
#include <string>

void tri_morceau(Discographie& discographie);
void tri_album(Discographie& discographie);
void tri_artiste(Discographie& discographie);

void affichage_morceau(Discographie const & discographie);
void affichage_album(Discographie const & discographie);
void affichage_artiste(Discographie const & discographie);

enum class Affichage { Artiste, Album, Morceau };

void affichage(Discographie& discographie, Affichage type_affichage);

void enregistrement(Discographie const & discographie, std::string const & nom_fichier);
void chargement(Discographie & discographie, std::string const & nom_fichier);

#endif