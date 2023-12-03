#include "Operations.h"

namespace VModel
{
    Model Operations::Sum(Model m1, Model m2)
    {
        if (m1.Size() != m2.Size())
            throw std::invalid_argument("Результирующие функций имеют разные области");

        Model result = new Model(m1.Size());

        for (int i = 0; i < m1.Value().size(); i++)
            result.Value().push_back(m1.Value()[i] + m2.Value()[i] + sqrt(m1.Value()[i] * m1.Value()[i] + m2.Value()[i] * m2.Value()[i]));

        return result;
    }

    Model Operations::Comp(Model m1, Model m2)
    {
        if (m1.Size() != m2.Size())
            throw std::invalid_argument("Результирующие функций имеют разные области");

        Model result = new Model(m1.Size());

        for (int i = 0; i < m1.Value().size(); i++)
            result.Value().push_back(m1.Value()[i] + m2.Value()[i] - sqrt(m1.Value()[i] * m1.Value()[i] + m2.Value()[i] * m2.Value()[i]));

        return result;
    }

    void Operations::Invert(Model m)
    {
        for (int i = 0; i < m.Value().size(); i++)
            m.Value()[i] = -m.Value()[i];
    }

    Model Operations::NewInvert(Model m)
    {
        Model result = new Model(m.Size());

        for each (double var in m.Value())
            result.Value().push_back(-var);

        return result;
    }
}