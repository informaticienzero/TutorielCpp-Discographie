#ifndef UTILS_HPP_INCLUDED
#define UTILS_HPP_INCLUDED

#include <string>

/**
* @brief Supprime les espaces et met la cha�ne enti�rement en minuscule.
* @details Tous les espaces, avant et apr�s, sont supprim�s.
*
* @param[in] chaine La chaine � traiter. 
* @returns Une copie de la cha�ne sans espace ni majuscule.
*/
std::string traitement_chaine(std::string const & chaine);

#endif