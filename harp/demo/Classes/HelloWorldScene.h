#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "PushRewardManager.h"
#include "AppleGameControllerX.h"

class HelloWorld : public cocos2d::CCLayer, private harp::IPushRewardDelegate, public controllerX::IAppleGameControllerXConnectionProtocol, public controllerX::IAppleGameControllerXGamepadProfileDigitalProtocol, public controllerX::IAppleGameControllerXPauseHandlerProtocol, public controllerX::IAppleGameControllerXExtendedGamepadProfileProtocol, public controllerX::IAppleGameControllerXExtendedGamepadProfileDigitalProtocol
{
public:
    virtual ~HelloWorld();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    virtual void onExit();
    virtual void update(float dt);
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    void openFacebookURL(CCObject* pSender);
    void openTwitterURL(CCObject* pSender);
    
    // handle rewards as registered via PushRewardManager
    virtual void handleReward(intptr_t rewardKey, int rewardValue, bool isLastReward);
    
    // override interfaces from controllerX
    virtual void onGameControllerDidConnect();
    virtual void onGameControllerDidDisconnect();
    virtual void onGameControllerPauseButtonPressed();
    
    // - Digital
    virtual void onGamepadProfile_buttonA_pressedChanged(float value, bool pressed);
    virtual void onGamepadProfile_buttonB_pressedChanged(float value, bool pressed);
    virtual void onGamepadProfile_buttonY_pressedChanged(float value, bool pressed);
    virtual void onGamepadProfile_buttonX_pressedChanged(float value, bool pressed);
    
    // D-Pad
    virtual void onGamepadProfile_DpadLeft_pressedChanged(float value, bool pressed);
    virtual void onGamepadProfile_DpadRight_pressedChanged(float value, bool pressed);
    virtual void onGamepadProfile_DpadUp_pressedChanged(float value, bool pressed);
    virtual void onGamepadProfile_DpadDown_pressedChanged(float value, bool pressed);
    
    // shoulder button
    virtual void onGamepadProfile_leftShoulder_pressedChanged(float value, bool pressed);
    virtual void onGamepadProfile_rightShoulder_pressedChanged(float value, bool pressed);
    
    // thumbstick
    virtual void onExtendedGamepadProfile_leftThumbstick_valueChanged(float xValue, float yValue);
    virtual void onExtendedGamepadProfile_rightThumbstick_valueChanged(float xValue, float yValue);
    
    virtual void onExtendedGamepadProfile_leftTrigger_pressedChanged(float value, bool pressed);
    virtual void onExtendedGamepadProfile_rightTrigger_pressedChanged(float value, bool pressed);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
    
protected:
    cocos2d::CCLabelTTF *m_rewardIdLabel;
    cocos2d::CCLabelTTF *m_rewardValueLabel;
};

#endif // __HELLOWORLD_SCENE_H__
