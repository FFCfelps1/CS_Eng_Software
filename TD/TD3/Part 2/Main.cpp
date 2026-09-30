#include "ConsoleLogger.hpp"
#include "EncryptLogger.hpp"
#include "FileLogger.hpp"
#include "HTMLLogger.hpp"

#include <string>
#include <memory>

int main() {
    // cas n°1 : on relie un objet de type EncryptLogger à un objet de type ConsoleLogger
    // Création d'un objet de type ConsoleLogger
    std::shared_ptr<ConsoleLogger> cLogger1 = std::make_shared<ConsoleLogger>();

    // Création d'un objet de type EncryptLogger
    std::shared_ptr<EncryptLogger> eLogger1 = std::make_shared<EncryptLogger>(cLogger1);

    // On génère 10 messages de Log qui sont cryptés
    // puis affichés dans une console
    for (int i = 0; i < 10; i++) {
        eLogger1->log(std::to_string(i) + " : A message to log");
    }

    // cas n°2 : on relie un objet de type HTMLLogger à un objet de type FileLogger
    // Création d'un objet de type FileLogger
    std::shared_ptr<FileLogger> fLogger1 = std::make_shared<FileLogger>("FichierLog1.html");

    // Création d'un objet de type HTMLLogger
    std::shared_ptr<HTMLLogger> hLogger1 = std::make_shared<HTMLLogger>(fLogger1);
    
    // On génère 10 messages de Log qui sont formatés
    // en HTML puis enregistrés dans un fichier
    for (int i = 0; i < 10; i++) {
        hLogger1->log(std::to_string(i) + " : A message to log");
    }
    return 0;
}