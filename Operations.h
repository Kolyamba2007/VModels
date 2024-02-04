#pragma once
#include "Model.h"
#include <vector>
#include <cmath>
#include <iostream>

namespace vmodel
{
    static class Operations {
    public:
        //R-функциональное логическое сложение
        static Model sum(Model& m1, Model& m2);
        //R-функциональное логическое произведение
        static Model comp(Model& m1, Model& m2);
        //Инвертирование функции
        static void invert(Model& m);
        //Создание копии инвертированной функции
        static Model new_invert(Model& m);
    };
}