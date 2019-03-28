#define BOOST_TEST_STATIC_LIB
#define BOOST_TEST_MODULE TestEntrees
#include <boost/test/unit_test.hpp>

#include <sstream>
#include "../Discographie/donnees_disco.hpp"

BOOST_AUTO_TEST_SUITE(TestEntrees)

BOOST_AUTO_TEST_CASE(CreationMorceauEntreeComplete)
{
    std::istringstream entree { "Frica | Frica | Carla's Dreams" };
    Morceau morceau {};

    entree >> morceau;

    BOOST_CHECK(morceau.nom == "Frica" && u8"Le nom du morceau doit être Frica.");
    BOOST_CHECK(morceau.album.nom == "Frica" && u8"Le nom de l'album doit être Frica.");
    BOOST_CHECK(morceau.compositeur.nom == "Carla's Dreams" && u8"Le nom du compositeur doit être Carla's Dreams.");
}

BOOST_AUTO_TEST_SUITE_END()