//
// Created by blue on 31/03/23.
//

#include <QTextStream>
#include "SlotController.h"
#include "iostream"

SlotController::SlotController(SlotModel &SlotModel) {


    for (int i = 0; i < 5; ++i) {
        std::vector<std::string> init;
        for (int j = 0; j < 5; ++j) {
            init.push_back(std::to_string(j)+ "|" +std::to_string(i) + ":" + "0" + ";");
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
    for (const auto &row : SlotModel.SlotData) {
        for (const auto &cell : row) {
            out << QString::fromStdString(cell) << " ";
        }
        out << endl;
    }

}

int SlotController::GetCellVal(int col, int row, SlotModel &SlotModel) {
    if (col >= 0 && col < 5 && row >= 0 && row < 5) {
        std::string cell = SlotModel.SlotData[col][row];

        return atoi(&cell[4]);
    }
    return 0;
}

void SlotController::SetCellVal(int col, int row, SlotModel &SlotModel, int val) {
    if (col >= 0 && col < 5 && row >= 0 && row < 5) {
        SlotModel.SlotData[col][row][4] = std::to_string(val)[0];
    }

    for (const auto& row : SlotModel.SlotData) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}