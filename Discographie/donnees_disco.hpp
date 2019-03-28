#ifndef DONNEES_DISCO_HPP_INCLUDED
#define DONNEES_DISCO_HPP_INCLUDED

#include <string>
#include <iostream>
#include <vector>


/** @struct Artiste
* @brief Tout ce qui concerne un artiste.
*/
struct Artiste
{
    /// @brief Le nom de l'artiste.
    std::string nom;
};

/**
* @brief Permet d'écrire un objet de type `Artiste` sur un flux de sortie.
* @param[in,out] sortie Le flux de sortie en question.
* @param[in] artiste L'artiste à écrire.
* @returns Retourne le flux de sortie `sortie`.
*/ 
std::ostream & operator<<(std::ostream & sortie, Artiste const & artiste);

/** @struct Album
* @brief Tout ce qui concerne un album.
*/
struct Album
{
    /// @brief Le nom de l'album.
    std::string nom;
};

/**
* @brief Permet d'écrire un objet de type `Album` sur un flux de sortie.
* @param[in,out] sortie Le flux de sortie en question.
* @param[in] album L'album à écrire.
* @returns Retourne le flux de sortie `sortie`.
*/
std::ostream & operator<<(std::ostream & sortie, Album const & album);

/** @struct Morceau
* @brief Tout ce qui concerne un morceau.
*/
struct Morceau
{
    /// @brief Le nom du morceau.
    std::string nom;
    /// @brief L'artiste ayant fait ce morceau.
    Artiste compositeur;
    /// @brief L'album auquel appartient ce morceau.
    Album album;
};

/**
* @brief Permet d'écrire un objet de type `Morceau` sur un flux de sortie.
* @param[in,out] sortie Le flux de sortie en question.
* @param[in] morceau Le morceau à écrire.
* @returns Retourne le flux de sortie `sortie`.
*/
std::ostream & operator<<(std::ostream & sortie, Morceau const & morceau);

/**
* @brief Permet de lire un objet de type `Morceau` depuis un flux d'entrée.
* @param[in,out] entree Le flux d'entrée en question.
* @param[out] morceau Le morceau à lire. 
* @returns Retourne le flux d'entrée `entree`.
*/
std::istream & operator>>(std::istream & entree, Morceau & morceau);

// Une discographie est un ensemble de morceaux.
using Discographie = std::vector<Morceau>;

#endif