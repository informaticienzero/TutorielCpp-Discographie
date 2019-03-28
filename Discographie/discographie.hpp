#ifndef DISCOGRAPHIE_HPP_INCLUDED
#define DISCOGRAPHIE_HPP_INCLUDED

#include "donnees_disco.hpp"
#include <string>

/**
* @brief Trie la discographie par morceaux.
* @details Trie une discographie existante par ordre alphabétique en se basant sur les morceaux.
* La discographie peut être vide, auquel cas la fonction ne fait rien.
* 
* @param[in,out] discographie La discographie à trier.
*/
void tri_morceau(Discographie& discographie);

/**
* @brief Trie la discographie par albums.
* @details Trie une discographie existante par ordre alphabétique en se basant sur les noms d'albums.
* La discographie peut être vide, auquel cas la fonction ne fait rien.
*
* @param[in,out] discographie La discographie à trier.
*/
void tri_album(Discographie& discographie);

/**
* @brief Trie la discographie par artistes.
* @details Trie une discographie existante par ordre alphabétique en se basant sur les noms d'artistes.
* La discographie peut être vide, auquel cas la fonction ne fait rien.
*
* @param[in,out] discographie La discographie à trier.
*/
void tri_artiste(Discographie& discographie);

/**
* @brief Affiche la discographie en classant par ordre alphabétique des morceaux.
* @details Affiche l'ensemble des morceaux de la discographie sous la forme suivante.
* @code
* --> Blue Rondo a la Turk | Time Out | Dave Brubeck
* --> J'ai demand├® ├á la lune | Paradize | Indochine
* --> L'aventurier | L'aventurier | Indochine
* --> Nocturne | Songs from a Secret Garden | Secret Garden
* --> Take Five | Time Out | Dave Brubeck
* @endcode
* 
* La discographie peut être vide, auquel cas la fonction ne fait rien.
*
* @param[in] discographie La discographie à afficher.
*/
void affichage_morceau(Discographie const & discographie);

/**
* @brief Affiche la discographie en classant par ordre alphabétique des albums.
* @details Affiche l'ensemble des morceaux de la discographie sous la forme suivante.
* @code
* --> L'aventurier | Indochine
*         /--> L'aventurier
* --> Paradize | Indochine
*         /--> J'ai demandé à la lune
* --> Songs from a Secret Garden | Secret Garden
*         /--> Nocturne
* --> Time Out | Dave Brubeck
*         /--> Blue Rondo a la Turk
*         /--> Take Five
* @endcode
*
* La discographie peut être vide, auquel cas la fonction ne fait rien.
*
* @param[in] discographie La discographie à afficher.
*/
void affichage_album(Discographie const & discographie);

/**
* @brief Affiche la discographie en classant par ordre alphabétique des artistes.
* @details Affiche l'ensemble des morceaux de la discographie sous la forme suivante.
* 
* @code
* --> Dave Brubeck
*     /--> Time Out
*         /--> Blue Rondo a la Turk
*         /--> Take Five
* --> Indochine
*     /--> L'aventurier
*         /--> L'aventurier
*     /--> Paradize
*         /--> J'ai demandé à la lune.
* @endcode 
* 
* La discographie peut être vide, auquel cas la fonction ne fait rien.
*
* @param[in] discographie La discographie à afficher.
*/
void affichage_artiste(Discographie const & discographie);

/** @enum Affichage
* @brief Le type d'affichage voulu pour la discographie.
* @details En fonction de la valeur choisie, l'affichage de la discographie se
* fera par ordre alphabétique des artistes, des albums ou des morceaux.
*/
enum class Affichage
{
    /// @brief Affiche par artiste.
    Artiste,
    /// @brief Affiche par album.
    Album,
    /// @brief Affiche par morceau.
    Morceau
};

/**
* @brief Affiche la discographie selon l'affichage voulu.
* @details Tri d'abord la discographie puis l'affiche selon le mode demandé.
* Si l'énumération `Affichage` est modifiée, la fonction est à modifier. Par défaut,
* lance une `std::runtime_error` si le nouvel affichage n'est pas implémenté.
* 
* @param[in,out] discographie La discographie à afficher.
* @param[in] type_affichage Le type d'affichage voulu.
* 
* @exception std::runtime_error Si un nouveau type d'affichage est demandé mais pas implémenté.
*/
void affichage(Discographie& discographie, Affichage type_affichage);

/**
* @brief Enregistre la discographie dans un fichier.
* @details Écrit toutes les informations de la discographie dans le fichier désigné par `nom_fichier`.
* Si celui-ci ne peut pas être ouvert, lance une `std::runtime_error`.
* 
* @param[in] discographie La discographie à enregistrer.
* @param[in] nom_fichier Le nom du fichier dans lequel la discographie sera enregistrée.
* 
* @exception std::runtime_error Si le fichier ne peut être ouvert.
*/
void enregistrement(Discographie const & discographie, std::string const & nom_fichier);

/**
* @brief Charge la discographie depuis un fichier.
* @details Lit toutes les informations du fichier désigné par `nom_fichier` pour les écrire dans la discographie.
* Si celui-ci ne peut pas être ouvert, lance une `std::runtime_error`.
*
* @param[out] discographie La discographie à créer.
* @param[in] nom_fichier Le nom du fichier depuis lequel la discographie sera chargée.
*
* @exception std::runtime_error Si le fichier ne peut être ouvert.
*/
void chargement(Discographie & discographie, std::string const & nom_fichier);

#endif