#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::updateGauges()
{

	// Override and implement this function in Screen1
}

void Screen1View::setTrainerTemperatur(int temp)
{

	Unicode::itoa(temp, textAreaLeftValueBuffer, TEXTAREALEFTVALUE_SIZE, 10);
	textAreaLeftValue.invalidate();

	if (temp != gaugeLeft.getValue())
	{
		gaugeLeft.setValue(temp);
	}

}

void Screen1View::setPreassure01(int temp)
{

	Unicode::itoa(temp, textAreaMiddleValueBuffer, TEXTAREAMIDDLEVALUE_SIZE, 10);
	textAreaMiddleValue.invalidate();

	if (temp != gaugeMid.getValue())
	{
		gaugeMid.setValue(temp);
	}

}
