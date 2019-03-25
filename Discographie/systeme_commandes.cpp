#include "discographie.hpp"
#include "systeme_commandes.hpp"
#include "utils.hpp"

#include <sstream>
#include <stdexcept>
#include <string>

std::string recuperer_commande()
{
    std::cout << "> ";

    std::string commande {};
    std::getline(std::cin, commande);
    return commande;
}

std::tuple<Commande, std::string> analyser_commande(std::string const & commande_texte)
{
    std::istringstream flux { commande_texte };

    std::string premier_mot {};
    flux >> premier_mot;
    premier_mot = traitement_chaine(premier_mot);

    std::string instructions {};
    std::getline(flux, instructions);
    instructions = traitement_chaine(instructions);

    if (premier_mot == "afficher")
    {
        return { Commande::Afficher, instructions };
    }
    else if (premier_mot == "ajouter")
    {
        return { Commande::Ajouter, instructions };
    }
    else if (premier_mot == "enregistrer")
    {
        return{ Commande::Enregistrer, instructions };
    }
    else if (premier_mot == "charger")
    {
        return { Commande::Charger, instructions };
    }
    else if (premier_mot == "quitter")
    {
        return { Commande::Quitter, std::string {} };
    }
    else
    {
        throw std::runtime_error("Commande invalide.");
    }
}

bool executer_commande(Discographie & discographie, Commande commande, std::string const & instructions)
{
    if (commande == Commande::Afficher)
    {
        if (instructions == "artistes")
        {
            affichage(discographie, Affichage::Artiste);
        }
        else if (instructions == "albums")
        {
            affichage(discographie, Affichage::Album);
        }
        else if (instructions == "morceaux")
        {
            affichage(discographie, Affichage::Morceau);
        }
        else
        {
            throw std::runtime_error("Commande d'affichage inconnue.");
        }
    }
    else if (commande == Commande::Ajouter)
    {
        std::istringstream flux { instructions };
        Morceau morceau {};
        flux >> morceau;
        discographie.push_back(morceau);
    }
    else if (commande == Commande::Charger)
    {
        chargement(discographie, instructions);
    }
    else if (commande == Commande::Enregistrer)
    {
        enregistrement(discographie, instructions);
    }
    else if (commande == Commande::Quitter)
    {
        return false;
    }

    return true;
}