#include "HelloWorldScene.h"
#include "AppMacros.h"
#include "CCDeviceLocale.h"
#include "CCURLOpener.h"
#include "DummyScene.hpp"

USING_NS_CC;
USING_NS_CC_EXT;

using namespace harp;
using namespace controllerX;

HelloWorld::~HelloWorld()
{
    CCLOGINFO("Destroying DummyScene");
    
    CC_SAFE_RELEASE_NULL(m_rewardIdLabel);
    CC_SAFE_RELEASE_NULL(m_rewardValueLabel);
}

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

void HelloWorld::onExit()
{
    // unset all delegates as set in this scene for AppleGameController
    AppleGameControllerX::sharedInstance()->unsetAllDelegates();
    
    CCLayer::onExit();
}

void HelloWorld::handleReward(intptr_t rewardKey, int rewardValue, bool isLastReward)
{
    if(rewardKey == 1)
    {
        m_rewardIdLabel->setString("Coin");
        m_rewardValueLabel->setString(CCString::createWithFormat("%d", rewardValue)->getCString());
    }
    
    if(isLastReward)
    {
        CCLOG("This is a last reward");
    }
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    // labels to show value of remote notification we got
    m_rewardIdLabel = new CCLabelTTF();
    m_rewardIdLabel->initWithString("", "Arial", 30);
    m_rewardIdLabel->setPosition(ccp(origin.x + visibleSize.width / 2.5 - m_rewardIdLabel->getContentSize().width/2, 70));
    
    m_rewardValueLabel = new CCLabelTTF();
    m_rewardValueLabel->initWithString("", "Arial", 30);
    m_rewardValueLabel->setPosition(ccp(origin.x + visibleSize.width / 1.5 - m_rewardIdLabel->getContentSize().width/2, 70));
    
    this->addChild(m_rewardIdLabel, 1);
    this->addChild(m_rewardValueLabel, 1);
    
    // flush push reward
    PushRewardManager::sharedInstance()->flush(this);

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));
    
    // add a facebook button
    CCMenuItemFont *fbItem = CCMenuItemFont::create("Facebook", this, menu_selector(HelloWorld::openFacebookURL));
    fbItem->setPosition(ccp(origin.x + visibleSize.width/1.5 - fbItem->getContentSize().width/2,
                            origin.y + visibleSize.height/2 - fbItem->getContentSize().height/2));
    
    // add a twitter button
    CCMenuItemFont *twitterItem = CCMenuItemFont::create("Twitter", this, menu_selector(HelloWorld::openTwitterURL));
    twitterItem->setPosition(ccp(origin.x + visibleSize.width/2.5 - twitterItem->getContentSize().width/2,
                            origin.y + visibleSize.height/2 - twitterItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, fbItem, twitterItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", TITLE_FONT_SIZE);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    // test device's locale
    CCLOG("Device language (raw): %s", ccdeviceLocale_getLanguage());
    CCLOG("Device language (code): %d", ccdeviceLocale_getLanguageK());
    
    this->scheduleUpdate();
    
    // controller X
    AppleGameControllerX::sharedInstance()->setControllerXConnectionDelegate(this);
    AppleGameControllerX::sharedInstance()->setControllerXPauseHandlerDelegate(this);
    AppleGameControllerX::sharedInstance()->setControllerXGamepadProfileDigitalDelegate(this);
    AppleGameControllerX::sharedInstance()->setControllerXExtendedGamepadProfileDelegate(this);
    AppleGameControllerX::sharedInstance()->setControllerXExtendedGamepadProfileDigitalDelegate(this);
    AppleGameControllerX::sharedInstance()->startWirelessControllerDiscovery();
    
    if (AppleGameControllerX::sharedInstance()->getConnectionDelegate() != NULL)
        printf("Connection delegate is set\n");
    if (AppleGameControllerX::sharedInstance()->getPauseHandlerDelegate() != NULL)
        printf("Pause handler delegate is set\n");
    if (AppleGameControllerX::sharedInstance()->getGamepadProfileAnalogDelegate() != NULL)
        printf("Gamepad analog delegate is set\n");
    if (AppleGameControllerX::sharedInstance()->getGamepadProfileDigitalDelegate() != NULL)
        printf("Gamepad digital delegate is set\n");
    if (AppleGameControllerX::sharedInstance()->getExtendedGamepadProfileDelegate() != NULL)
        printf("Extended gamepad delegate is set\n");
    if (AppleGameControllerX::sharedInstance()->getExtendedGamepadProfileAnalogDelegate() != NULL)
        printf("Extended gamepad - analog is set\n");
    if (AppleGameControllerX::sharedInstance()->getExtendedGamepadProfileDigitalDelegate() != NULL)
        printf("Extended gamepad - digital is set\n");
    
    return true;
}

void HelloWorld::update(float dt)
{
    // test polling
    if (AppleGameControllerX::sharedInstance()->isDPadLeftPressed())
    {
        CCLOG("Dpad left is pressed");
    }
    if (AppleGameControllerX::sharedInstance()->isDPadRightPressed())
    {
        CCLOG("Dpad right is pressed");
    }
    if (AppleGameControllerX::sharedInstance()->isDPadUpPressed())
    {
        CCLOG("Dpad up is pressed");
    }
    if (AppleGameControllerX::sharedInstance()->isDPadDownPressed())
    {
        CCLOG("Dpad down is pressed");
    }
    
    if (AppleGameControllerX::sharedInstance()->isButtonAPressed())
    {
        CCLOG("Button A is pressed");
    }
    if (AppleGameControllerX::sharedInstance()->isButtonBPressed())
    {
        CCLOG("Button B is pressed");
    }
    if (AppleGameControllerX::sharedInstance()->isButtonXPressed())
    {
        CCLOG("Button X is pressed");
    }
    if (AppleGameControllerX::sharedInstance()->isButtonYPressed())
    {
        CCLOG("Button Y is pressed");
    }
    
    if (AppleGameControllerX::sharedInstance()->isLeftShoulderPressed())
    {
        CCLOG("Left shoulder is pressed");
    }
    if (AppleGameControllerX::sharedInstance()->isRightShoulderPressed())
    {
        CCLOG("Right shoulder is pressed");
    }
    
    if (AppleGameControllerX::sharedInstance()->leftThumbstickXAxisValue() != 0.0f &&
        AppleGameControllerX::sharedInstance()->leftThumbstickYAxisValue() != 0.0f)
    {
        CCLOG("Left thumbstick: %.2f %.2f", AppleGameControllerX::sharedInstance()->leftThumbstickXAxisValue(), AppleGameControllerX::sharedInstance()->leftThumbstickYAxisValue());
    }
    
    if (AppleGameControllerX::sharedInstance()->rightThumbstickXAxisValue() != 0.0f &&
        AppleGameControllerX::sharedInstance()->rightThumbstickYAxisValue() != 0.0f)
    {
        CCLOG("Right thumbstick: %.2f %.2f", AppleGameControllerX::sharedInstance()->rightThumbstickXAxisValue(), AppleGameControllerX::sharedInstance()->rightThumbstickYAxisValue());
    }
}

void HelloWorld::openFacebookURL(cocos2d::CCObject *pSender)
{
    CCURLOpener *urlOpener = CCURLOpener::create();
    
    // try to open app-link of facebook
    if(!urlOpener->openURL("fb://profile/374701732647919"))
    {
        // open it with browser
        urlOpener->openURL("https://www.facebook.com/secretcharsg");
    }
}

void HelloWorld::openTwitterURL(cocos2d::CCObject *pSender)
{
    CCURLOpener *urlOpener = CCURLOpener::create();
    
    // try to open app-link of facebook
    if(!urlOpener->openURL("twitter://user?screen_name=secretcharsg"))
    {
        // open it with browser
        urlOpener->openURL("https://twitter.com/secretcharsg");
    }
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    // go to dummy scene
    CCDirector::sharedDirector()->replaceScene(DummyScene::scene());
}

void HelloWorld::onGameControllerDidConnect()
{
    CCLOG("[ControllerX] Game controller did connected");
}

void HelloWorld::onGameControllerDidDisconnect()
{
    CCLOG("[ControllerX] Game controller did dis-connected");
}

void HelloWorld::onGameControllerPauseButtonPressed()
{
    CCLOG("[ControllerX] Pause button is pressed.");
}

void HelloWorld::onGamepadProfile_buttonA_pressedChanged(float value, bool pressed)
{
    if (pressed)
        CCLOG("[ControllerX] Button A is pressed");
}

void HelloWorld::onGamepadProfile_buttonB_pressedChanged(float value, bool pressed)
{
    if (pressed)
        CCLOG("[ControllerX] Button B is pressed");
}

void HelloWorld::onGamepadProfile_buttonX_pressedChanged(float value, bool pressed)
{
    if (pressed)
        CCLOG("[ControllerX] Button X is pressed");
}

void HelloWorld::onGamepadProfile_buttonY_pressedChanged(float value, bool pressed)
{
    if (pressed)
        CCLOG("[ControllerX] Button Y is pressed");
}

void HelloWorld::onGamepadProfile_DpadLeft_pressedChanged(float value, bool pressed)
{
    if (pressed)
        CCLOG("[ControllerX] D-Pad left is pressed");
}

void HelloWorld::onGamepadProfile_DpadRight_pressedChanged(float value, bool pressed)
{
    if (pressed)
        CCLOG("[ControllerX] D-Pad right is pressed");
}

void HelloWorld::onGamepadProfile_DpadUp_pressedChanged(float value, bool pressed)
{
    if (pressed)
        CCLOG("[ControllerX] D-Pad up is pressed");
}

void HelloWorld::onGamepadProfile_DpadDown_pressedChanged(float value, bool pressed)
{
    if (pressed)
        CCLOG("[ControllerX] D-Pad down is pressed");
}

void HelloWorld::onGamepadProfile_leftShoulder_pressedChanged(float value, bool pressed)
{
    if (pressed)
        CCLOG("[ControllerX] Left shoulder button is pressed");
}

void HelloWorld::onGamepadProfile_rightShoulder_pressedChanged(float value, bool pressed)
{
    if (pressed)
        CCLOG("[ControllerX] Right shoulder button is pressed");
}

void HelloWorld::onExtendedGamepadProfile_leftThumbstick_valueChanged(float xValue, float yValue)
{
    //CCLOG("Left thumbstick : %f %f", xValue, yValue);
}

void HelloWorld::onExtendedGamepadProfile_rightThumbstick_valueChanged(float xValue, float yValue)
{
    // uncommen
    //CCLOG("Right thumbstick : %f %f", xValue, yValue);
}

void HelloWorld::onExtendedGamepadProfile_leftTrigger_pressedChanged(float value, bool pressed)
{
    if (pressed)
        CCLOG("Left trigger is pressed");
    else
        CCLOG("Left trigger is released");
}

void HelloWorld::onExtendedGamepadProfile_rightTrigger_pressedChanged(float value, bool pressed)
{
    if (pressed)
        CCLOG("Right trigger is pressed");
    else
        CCLOG("Right trigger is released");
}
