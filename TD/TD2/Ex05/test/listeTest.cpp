#include <gtest/gtest.h>
#include "../src/liste.hpp"


// ============================================================
// Test 1 : une liste nouvellement créée est vide
// ============================================================
TEST(ListeTest, ListeVide) {
    Liste liste;

    EXPECT_EQ(liste.getDebut(), nullptr);
}


// ============================================================
// Test 2 : insertion dans une liste vide
// ============================================================
TEST(ListeTest, InsererDansListeVide) {
    Liste liste;

    liste.inserer(5);

    ASSERT_NE(liste.getDebut(), nullptr);

    EXPECT_EQ(liste.getDebut()->getInfo(), 5);
    EXPECT_EQ(liste.getDebut()->getSuivant(), nullptr);
}

// ============================================================
// Test 3 : insertion au milieu
// ============================================================
TEST(ListeTest, InsererAuMilieu) {
    Liste liste;

    liste.inserer(2);
    liste.inserer(8);
    liste.inserer(5);

    auto courant = liste.getDebut();
    ASSERT_NE(courant, nullptr);
    EXPECT_EQ(courant->getInfo(), 2);

    courant = courant->getSuivant();
    ASSERT_NE(courant, nullptr);
    EXPECT_EQ(courant->getInfo(), 5);

    courant = courant->getSuivant();
    ASSERT_NE(courant, nullptr);
    EXPECT_EQ(courant->getInfo(), 8);


    
}



