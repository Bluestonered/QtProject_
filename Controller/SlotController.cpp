//
// Created by blue on 31/03/23.
//

#include <QTextStream>
#include "SlotController.h"
#include "iostream"

SlotController::SlotController(SlotModel &SlotModel) {

if (SlotModel.SlotData.size() == NULL)
{
    for (int i = 0; i < 5; ++i) {
        std::vector<std::string> init;
        for (int j = 0; j < 5; ++j) {
            init.push_back(std::to_string(j)+ "|" +std::to_string(i) + ":" + "0" + ";");
        }
        SlotModel.SlotData.push_back(init);
    }
}


    //je le print vite fais
    for (const auto& row : SlotModel.SlotData) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

void SlotController::UpdateProject(QFile &file, SlotModel &SlotModel) {

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        std::cout << "ERREUR PAS D'ACCES AU FICHIER" << endl;
    }
    QTextStream out(&file);
    for (const auto &row : SlotModel.SlotData) {
        for (const auto &cell : row) {
            out << QString::fromStdString(cell) << " ";
        }
        out << endl;
    }
}

void SlotController::NewProject(QFile &file, SlotModel &SlotModel) {

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        std::cout << "ERREUR PAS D'ACCES AU FICHIER" << endl;
    }
    QTextStream out(&file);
    for (const auto &row : SlotModel.SlotData) {
        for (const auto &cell : row) {
            out << QString::fromStdString(cell) << " ";
        }
        out << endl;
    }

}

SlotModel SlotController::InitProject(QFile &file)
{
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cout << "Impossible d'ouvrir le fichier." << std::endl;
    }

    QTextStream in(&file);
    QString line;

    // Initialisation du tableau de vecteurs
    const int numVectors = 5;
    std::vector<std::vector<std::string>> donneededonnee;
    QStringList items;
    // Lecture des données du fichier texte
    while (!in.atEnd()) {
        line = in.readLine();
        if (line.trimmed().isEmpty() || line.startsWith("#")) {
            continue; // Ignorer les lignes vides et les commentaires
        }
        items = line.split(" ");
        std::vector<std::string> donnee;
        for (const auto& item : items) {
/*            std::cout << item.toStdString() << std::endl;*/
            donnee.push_back(item.toStdString());
        }
        donneededonnee.push_back(donnee);
    }

    // Affichage des données stockées dans le tableau de vecteurs
    for (const auto& vec : donneededonnee) {
        for (const auto& str : vec) {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }
    SlotModel slotModel;
    slotModel.SlotData = donneededonnee;
    return slotModel;
}





int SlotController::GetCellVal(int col, int row, SlotModel &SlotModel) {
        std::string cell = SlotModel.SlotData[col][row];
        return atoi(&cell[4]);
}

SlotModel SlotController::SetCellVal(int col, int row, SlotModel SlotModel, int val) {

        SlotModel.SlotData[row][col][4] = std::to_string(val)[0];

    for (const auto& row : SlotModel.SlotData) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }

    return SlotModel;


}