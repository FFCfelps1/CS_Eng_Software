# Compilateur C++
CXX = g++

# Options de compilation
CXXFLAGS = -std=c++20 -Wall -Wextra -I./src
TESTFLAGS = $(CXXFLAGS) -DCAPTEUR_METEO_TEST

# Bibliothèques Google Test
LDFLAGS = -lgtest -lgtest_main -pthread

# Nom de l'exécutable
TARGET = capteurMeteoTest


# Compilation du programme de test
$(TARGET): CapteurMeteo.cpp CapteurMeteoTest.cpp
	$(CXX) $(TESTFLAGS) CapteurMeteo.cpp CapteurMeteoTest.cpp -o $(TARGET) $(LDFLAGS)


# Exécution des tests
test: $(TARGET)
	./$(TARGET)


# Suppression de l'exécutable
clean:
	rm -f $(TARGET)




