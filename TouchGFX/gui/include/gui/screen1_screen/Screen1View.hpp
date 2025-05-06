#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleTickEvent();
    int tickCounter=50;
    int codeEntered=0;
    int digitsEntered=0;

    virtual void enterDigit(int digit);
    virtual void number1();
    virtual void number2();
    virtual void number3();
    virtual void number4();
    virtual void number5();
    virtual void number6();
    virtual void number7();
    virtual void number8();
    virtual void number9();
    virtual void number0();
    virtual void enter();
protected:
};

#endif // SCREEN1VIEW_HPP
