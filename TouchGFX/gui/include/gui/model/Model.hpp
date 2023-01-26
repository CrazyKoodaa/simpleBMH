#ifndef MODEL_HPP
#define MODEL_HPP

#include <stdint.h>

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    void setTrainerTemperatur(int temp) { trainerTemperatur = temp; }
    int getTrainerTemperatur() { return trainerTemperatur; }

    void setPreassure01(int temp) { preassure01 = temp;}
    int getPreassure01() { return preassure01; }

protected:
    ModelListener* modelListener;
    int trainerTemperatur;
    int preassure01;
};

#endif // MODEL_HPP
