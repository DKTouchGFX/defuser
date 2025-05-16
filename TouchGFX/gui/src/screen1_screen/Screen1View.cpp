#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/Color.hpp>

#define FADE_ANIMATION_DURATION 60
#define GREEN_COLOR 			touchgfx::Color::getColorFromRGB(0, 255, 0)
#define RED_COLOR 				touchgfx::Color::getColorFromRGB(255, 0, 0)

Screen1View::Screen1View() :
	currentAlpha(255),
	nextAlpha(50),
	codeEntered(0),
	digitsEntered(0),
	fadeAnimationCallback(this, &Screen1View::fadeAnimationCallbackHandler)
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();

	title.setFadeAnimationEndedAction(fadeAnimationCallback);
	title.startFadeAnimation(nextAlpha, FADE_ANIMATION_DURATION, &EasingEquations::linearEaseNone);
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::enterDigit(int digit)
{
	if (4 <= digitsEntered)
	{
		return;
	}

	codeEntered = codeEntered * 10 + digit;
	digitsEntered++;

	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%0*d", digitsEntered, codeEntered);
	textArea1.invalidate();
}


void Screen1View::number1() { enterDigit(1); }
void Screen1View::number2() { enterDigit(2); }
void Screen1View::number3() { enterDigit(3); }
void Screen1View::number4() { enterDigit(4); }
void Screen1View::number5() { enterDigit(5); }
void Screen1View::number6() { enterDigit(6); }
void Screen1View::number7() { enterDigit(7); }
void Screen1View::number8() { enterDigit(8); }
void Screen1View::number9() { enterDigit(9); }
void Screen1View::number0() { enterDigit(0); }

void Screen1View::enter()
{
	digitsEntered = 0;
	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "");
	textArea1.invalidate();

	if(presenter->getCode() != codeEntered)
	{
		codeEntered = 0;
		return;
	}

	setTitle("DISARMED", GREEN_COLOR);

	codeEntered = 0;
	digitsEntered = 0;

	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "");
	textArea1.invalidate();

	enterButton.setTouchable(false);
	enterButton.setVisible(false);
	enterButton.invalidate();

	armButton.setTouchable(true);
	armButton.setVisible(true);
	armButton.invalidate();
}

void Screen1View::arm()
{
	if (4 > digitsEntered)
	{
		return;
	}

	presenter->setCode(codeEntered);

	setTitle("ARMED", RED_COLOR);

	codeEntered=0;
	digitsEntered=0;

	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "");
	textArea1.invalidate();

	enterButton.setTouchable(true);
	enterButton.setVisible(true);
	enterButton.invalidate();

	armButton.setTouchable(false);
	armButton.setVisible(false);
	armButton.invalidate();
}

void Screen1View::setTitle(const char * text, touchgfx::colortype color)
{
	title.setColor(color);
	Unicode::snprintf(titleBuffer, TEXTAREA1_SIZE, text);
	title.invalidate();
}

void Screen1View::fadeAnimationCallbackHandler(const touchgfx::FadeAnimator<touchgfx::TextAreaWithOneWildcard>& src)
{
	int tmp = currentAlpha;
	currentAlpha = nextAlpha;
	nextAlpha = tmp;

	title.startFadeAnimation(nextAlpha, FADE_ANIMATION_DURATION, &EasingEquations::linearEaseNone);
}
