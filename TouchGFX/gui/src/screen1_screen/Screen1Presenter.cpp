#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{
	view.setTrainerTemperatur(model->getTrainerTemperatur());
	view.setPreassure01(model->getPreassure01());
}

void Screen1Presenter::deactivate()
{

}


void Screen1Presenter::viewSetTrainerTemperature(int temp)
{
    model->setTrainerTemperatur(temp);
    view.setTrainerTemperatur(temp);
}

void Screen1Presenter::trainerTemperaturChanged()
{
    view.setTrainerTemperatur(model->getTrainerTemperatur());
}

void Screen1Presenter::viewSetPreassure01(int temp)
{
    model->setPreassure01(temp);
    view.setPreassure01(temp);
}

void Screen1Presenter::preassure01Changed()
{
    view.setPreassure01(model->getPreassure01());
}
