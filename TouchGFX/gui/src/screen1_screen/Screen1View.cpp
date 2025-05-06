#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/Color.hpp>

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

void Screen1View::handleTickEvent()
{
	if(digitsEntered==1)
	{
		Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d",codeEntered/1000);
		textArea1.resizeToCurrentTextWithAlignment();
		textArea1.invalidate();
	}
	if(digitsEntered==2)
	{
		Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d",codeEntered/100);
		textArea1.resizeToCurrentTextWithAlignment();
		textArea1.invalidate();
	}
	if(digitsEntered==3)
	{
		Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d",codeEntered/10);
		textArea1.resizeToCurrentTextWithAlignment();
		textArea1.invalidate();
	}
	if(digitsEntered==4)
	{
		Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d",codeEntered);
		textArea1.resizeToCurrentTextWithAlignment();
		textArea1.invalidate();
	}

	title.setAlpha(tickCounter);
	title.invalidate();
	tickCounter++;
	if(tickCounter>255)
		tickCounter=50;
}

void Screen1View::enterDigit(int digit)
{
	switch(digitsEntered)
	{
	case 0:
		codeEntered=digit*1000;
		break;
	case 1:
		codeEntered += digit*100;
		break;
	case 2:
		codeEntered += digit*10;
		break;
	case 3:
		codeEntered += digit;
		break;

	default:
	break;
	}
	digitsEntered++;
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

void Screen1View::enter() {
	if(codeEntered!=3486)
	{
		codeEntered=0;
		digitsEntered=0;
		Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "");
		textArea1.resizeToCurrentText();
		textArea1.invalidate();
	}
	else
	{
		btn0.setTouchable(false);
		btn1.setTouchable(false);
		btn2.setTouchable(false);
		btn3.setTouchable(false);
		btn4.setTouchable(false);
		btn5.setTouchable(false);
		btn6.setTouchable(false);
		btn7.setTouchable(false);
		btn8.setTouchable(false);
		btn9.setTouchable(false);
		btn0.setAlpha(0);
		btn1.setAlpha(0);
		btn2.setAlpha(0);
		btn3.setAlpha(0);
		btn4.setAlpha(0);
		btn5.setAlpha(0);
		btn6.setAlpha(0);
		btn7.setAlpha(0);
		btn8.setAlpha(0);
		btn9.setAlpha(0);
		enterButton.setTouchable(false);
		enterButton.setAlpha(0);
		btn0.invalidate();
		btn1.invalidate();
		btn2.invalidate();
		btn3.invalidate();
		btn4.invalidate();
		btn5.invalidate();
		btn6.invalidate();
		btn7.invalidate();
		btn8.invalidate();
		btn9.invalidate();
		enterButton.invalidate();

		textArea1.setAlpha(0);

		title.setColor(touchgfx::Color::getColorFromRGB(0,255,0));
		Unicode::snprintf(titleBuffer, TEXTAREA1_SIZE, "DISARMED");
		title.resizeToCurrentTextWithAlignment();
		title.invalidate();
	}
}

