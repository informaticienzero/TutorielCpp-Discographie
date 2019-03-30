#include "utils.hpp"

#include <algorithm>

std::string traitement_chaine(std::string const & chaine)
{
    std::string copie { chaine };

    auto premier_non_espace { std::find_if_not(std::begin(copie), std::end(copie), isspace) };
    copie.erase(std::begin(copie), premier_non_espace);

    std::reverse(std::begin(copie), std::end(copie));
    premier_non_espace = std::find_if_not(std::begin(copie), std::end(copie), isspace);
    copie.erase(std::begin(copie), premier_non_espace);
    std::reverse(std::begin(copie), std::end(copie));

    return copie;
}