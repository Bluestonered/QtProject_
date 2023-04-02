//
// Created by blue on 31/03/23.
//

#ifndef QTPROJECT_SLOTCONTROLLER_H
#define QTPROJECT_SLOTCONTROLLER_H
#include "../Model/SlotModel.h"
#include "QFile"

class SlotController {

public:
    SlotController(SlotModel &SlotModel);

    void NewProject(QFile &a, SlotModel &SlotModel);

    void InitProject(QFile &a);

    int GetCellVal(int col, int row, SlotModel &SlotModel);

    void SetCellVal(int col, int row, SlotModel SlotModel, int val);

};


#endif //QTPROJECT_SLOTCONTROLLER_H
