//
// Created by blue on 31/03/23.
//

#include <QTextStream>
#include "SlotController.h"
#include "iostream"

SlotController::SlotController(SlotModel &SlotModel) {


    for (int i = 1; i < 6; ++i) {
        std::vector<std::string> init;
        for (int j = 1; j < 6; ++j) {
            init.push_back(std::to_string(i)+ "|" +std::to_string(j) + ":" + "0" + ";");
        }
        SlotModel.SlotData.push_back(init);
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
    for (const auto& row : SlotModel.SlotData) {
        for (const auto& cell : row) {
            out << QString::fromStdString(cell) << " ";
        }
        out << endl;
    }

}