#ifndef UTILS_HPP_INCLUDED
#define UTILS_HPP_INCLUDED

#include <string>

/**
* @brief Supprime les espaces et met la chaîne entièrement en minuscule.
* @details Tous les espaces, avant et après, sont supprimés.
*
* @param[in] chaine La chaine à traiter. 
* @returns Une copie de la chaîne sans espace ni majuscule.
*/
std::string traitement_chaine(std::string const & chaine);

#endif