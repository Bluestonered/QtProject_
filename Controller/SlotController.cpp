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

SlotModel *SlotController::InitProject(QFile &file)
{
    SlotModel slotModel;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cout<< "MWAMAW" << std::endl;
        return &slotModel;
    }

    QTextStream in(&file);
    QString line = in.readLine();

    while (!line.isNull()) {
        QStringList items = line.split("|");
        int row = items[0].toInt();
        QStringList cells = items[1].split(";");

        for (int col = 0; col < cells.size(); col++) {
            QStringList cellValues = cells[col].split(":");
            int value = cellValues[1].toInt();
            slotModel.SlotData[row][col] = value;
        }

        line = in.readLine();
    }

    file.close();
    return &slotModel;
}

int SlotController::GetCellVal(int col, int row, SlotModel &SlotModel) {
        std::string cell = SlotModel.SlotData[col][row];

        return atoi(&cell[4]);
}

void SlotController::SetCellVal(int col, int row, SlotModel SlotModel, int val) {

        SlotModel.SlotData[row][col][4] = std::to_string(val)[0];

    for (const auto& row : SlotModel.SlotData) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}