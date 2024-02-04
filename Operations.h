#pragma once
#include "Model.h"
#include <vector>
#include <cmath>
#include <iostream>

namespace vmodel
{
    static class Operations {
    public:
        //R-�������������� ���������� ��������
        static Model sum(Model& m1, Model& m2);
        //R-�������������� ���������� ������������
        static Model comp(Model& m1, Model& m2);
        //�������������� �������
        static void invert(Model& m);
        //�������� ����� ��������������� �������
        static Model new_invert(Model& m);
    };
}