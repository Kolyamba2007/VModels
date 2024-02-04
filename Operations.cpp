#include "Operations.h"

namespace vmodel
{
    Model Operations::sum(Model& m1, Model& m2)
    {
        if (m1.size() != m2.size())
            throw std::invalid_argument("�������������� ������� ����� ������ �������");

        Model result = Model(m1.size());

        for (int i = 0; i < m1.value()->size(); ++i) {
            result.value()->push_back(m1[i] + m2[i] + sqrt(m1[i] * m1[i] + m2[i] * m2[i]));
        }
        return result;
    }

    Model Operations::comp(Model& m1, Model& m2)
    {
        if (m1.size() != m2.size())
            throw std::invalid_argument("�������������� ������� ����� ������ �������");

        Model result = Model(m1.size());

        for (int i = 0; i < m1.value()->size(); i++)
            result.value()->push_back(m1[i] + m2[i] - sqrt(m1[i] * m1[i] + m2[i] * m2[i]));

        return result;
    }

    void Operations::invert(Model& m)
    {
        for (int i = 0; i < m.value()->size(); i++)
            m[i] = -m[i];
    }

    Model Operations::new_invert(Model& m)
    {
        Model result = Model(m.size());

        for (double var : *m.value()) {
            result.value()->push_back(-var);
        }
        return result;
    }
}