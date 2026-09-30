# Compilateur C++
CXX = g++

# Options de compilation
CXXFLAGS = -std=c++20 -I./src

# Bibliothèques Google Test
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Nom de l'exécutable
TARGET = AppliScores

# Compilation du programme de test
$(TARGET): AfficheurCourbe.cpp AppliScores.cpp
	$(CXX) $(CXXFLAGS) AfficheurCourbe.cpp AppliScores.cpp -o $(TARGET) $(LDFLAGS)

# Exécution des tests
test: $(TARGET)
	./$(TARGET)

# Suppression de l'exécutable
clean:
	rm -f $(TARGET)




