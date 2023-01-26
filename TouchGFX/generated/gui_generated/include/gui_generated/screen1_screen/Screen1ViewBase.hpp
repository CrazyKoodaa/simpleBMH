/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREEN1VIEWBASE_HPP
#define SCREEN1VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/ScalableImage.hpp>
#include <touchgfx/widgets/Gauge.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>

class Screen1ViewBase : public touchgfx::View<Screen1Presenter>
{
public:
    Screen1ViewBase();
    virtual ~Screen1ViewBase();
    virtual void setupScreen();
    virtual void handleTickEvent();

    /*
     * Virtual Action Handlers
     */
    virtual void updateGauges()
    {
        // Override and implement this function in Screen1
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::ScalableImage imageBG;
    touchgfx::Gauge gaugeLeft;
    touchgfx::Gauge gaugeMid;
    touchgfx::Gauge gaugeRight;
    touchgfx::ScalableImage logoBMH;
    touchgfx::ScalableImage logoDLR;
    touchgfx::ScalableImage logoGDS2;
    touchgfx::TextArea textAreaTitel;
    touchgfx::TextAreaWithOneWildcard textAreaMiddle;
    touchgfx::TextAreaWithOneWildcard textAreaLeft;
    touchgfx::TextAreaWithOneWildcard textAreaRight;
    touchgfx::TextAreaWithOneWildcard textAreaLeftValue;
    touchgfx::TextAreaWithOneWildcard textAreaMiddleValue;
    touchgfx::TextAreaWithOneWildcard textAreaRightValue;
    touchgfx::ImageButtonStyle< touchgfx::ClickButtonTrigger >  flexButton1;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTAREAMIDDLE_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaMiddleBuffer[TEXTAREAMIDDLE_SIZE];
    static const uint16_t TEXTAREALEFT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaLeftBuffer[TEXTAREALEFT_SIZE];
    static const uint16_t TEXTAREARIGHT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaRightBuffer[TEXTAREARIGHT_SIZE];
    static const uint16_t TEXTAREALEFTVALUE_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaLeftValueBuffer[TEXTAREALEFTVALUE_SIZE];
    static const uint16_t TEXTAREAMIDDLEVALUE_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaMiddleValueBuffer[TEXTAREAMIDDLEVALUE_SIZE];
    static const uint16_t TEXTAREARIGHTVALUE_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaRightValueBuffer[TEXTAREARIGHTVALUE_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Screen1ViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

    /*
     * Tick Counter Declarations
     */
    static const uint32_t TICK_INTERACTION1_INTERVAL = 10;
    uint32_t frameCountInteraction1Interval;

};

#endif // SCREEN1VIEWBASE_HPP
