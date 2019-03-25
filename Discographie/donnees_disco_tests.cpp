#include "donnees_disco_tests.hpp"

#include <sstream>
#include <cassert>
#include "donnees_disco.hpp"

void test_creation_morceau_entree_complete()
{
    std::istringstream entree { "Frica | Frica | Carla's Dreams" };
    Morceau morceau {};

    entree >> morceau;

    assert(morceau.nom == "Frica" && u8"Le nom du morceau doit être Frica.");
    assert(morceau.album.nom == "Frica" && u8"Le nom de l'album doit être Frica.");
    assert(morceau.compositeur.nom == "Carla's Dreams" && u8"Le nom du compositeur doit être Carla's Dreams.");
}

void test_creation_morceau_entree_espaces_partout()
{
    std::istringstream entree { "Levels      |  Levels     |  Avicii" };
    Morceau morceau {};

    entree >> morceau;

    assert(morceau.nom == "Levels" && u8"Le nom du morceau doit être Levels.");
    assert(morceau.album.nom == "Levels" && u8"Le nom de l'album doit être Levels.");
    assert(morceau.compositeur.nom == "Avicii" && u8"Le nom du compositeur doit être Avicii.");
}

void test_creation_morceau_entree_chanson_artiste()
{
    std::istringstream entree { "Subeme la radio | | Enrique Iglesias" };
    Morceau morceau {};

    entree >> morceau;

    assert(morceau.nom == "Subeme la radio" && u8"Le nom du morceau doit être Subeme la radio.");
    assert(morceau.album.nom == "Album inconnu" && u8"Le nom de l'album doit être Album inconnu.");
    assert(morceau.compositeur.nom == "Enrique Iglesias" && u8"Le nom du compositeur doit être Enrique Iglesias.");
}

void test_creation_morceau_entree_chanson_uniquement()
{
    std::istringstream entree { "Duel of the fates | |" };
    Morceau morceau {};

    entree >> morceau;

    assert(morceau.nom == "Duel of the fates" && u8"Le nom du morceau doit être Duel of the Fates.");
    assert(morceau.album.nom == "Album inconnu" && u8"Le nom de l'album doit être Album inconnu.");
    assert(morceau.compositeur.nom == "Artiste inconnu" && u8"Le nom du compositeur doit être Artiste inconnu.");
}

void test_creation_morceau_entree_vide()
{
    std::istringstream entree { "| |" };
    Morceau morceau {};

    entree >> morceau;

    assert(morceau.nom == "Morceau inconnu" && u8"Le nom du morceau doit être Morceau inconnu.");
    assert(morceau.album.nom == "Album inconnu" && u8"Le nom de l'album doit être Album inconnu.");
    assert(morceau.compositeur.nom == "Artiste inconnu" && u8"Le nom du compositeur doit être Artiste inconnu.");
}