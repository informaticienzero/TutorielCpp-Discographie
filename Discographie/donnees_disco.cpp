#include "donnees_disco.hpp"

#include "utils.hpp"
#include <sstream>

std::ostream & operator<<(std::ostream & sortie, Artiste const & artiste)
{
    sortie << artiste.nom;
    return sortie;
}

std::ostream & operator<<(std::ostream & sortie, Album const & album)
{
    sortie << album.nom;
    return sortie;
}

std::ostream & operator<<(std::ostream & sortie, Morceau const & morceau)
{
    sortie << morceau.nom << " | " << morceau.album << " | " << morceau.compositeur;
    return sortie;
}

std::istream & operator>>(std::istream & entree, Morceau & morceau)
{
    std::string mot {};
    std::ostringstream flux {};

    while (entree >> mot && mot != "|")
    {
        flux << mot << " ";
    }

    std::string nom_morceau { flux.str() };
    if (std::empty(nom_morceau))
    {
        nom_morceau = "Morceau inconnu";
    }
    morceau.nom = traitement_chaine(nom_morceau);
    flux.str(std::string {});

    while (entree >> mot && mot != "|")
    {
        flux << mot << " ";
    }

    std::string nom_album { flux.str() };
    if (std::empty(nom_album))
    {
        nom_album = "Album inconnu";
    }
    morceau.album.nom = traitement_chaine(nom_album);
    flux.str(std::string {});

    while (entree >> mot)
    {
        flux << mot << " ";
    }

    std::string nom_artiste { flux.str() };
    if (std::empty(nom_artiste))
    {
        nom_artiste = "Artiste inconnu";
    }
    morceau.compositeur.nom = traitement_chaine(nom_artiste);
    flux.str(std::string {});

    return entree;
}