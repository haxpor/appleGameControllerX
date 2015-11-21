//
//  AppleGameControllerX.cpp
//
//
//  Created by haxpor on 11/9/15.
//
//

#import "AppleGameControllerX.h"
#import <GameController/GameController.h>
#import "AppleGameControllerX_objc.h"
#import "AppleGameControllerX_objc.h"

using namespace controllerX;

static AppleGameControllerX *s_sharedInstance = NULL;
AppleGameControllerX_objcPtr AppleGameControllerX::_controllerObjcPtr = nil;

AppleGameControllerX::AppleGameControllerX()
{
}

AppleGameControllerX::~AppleGameControllerX()
{

}

AppleGameControllerX* AppleGameControllerX::sharedInstance()
{
    if (s_sharedInstance == NULL)
    {
        s_sharedInstance = new AppleGameControllerX();
        _controllerObjcPtr = [[AppleGameControllerX_objc alloc] init];
    }
    return s_sharedInstance;
}

void AppleGameControllerX::setControllerXConnectionDelegate(controllerX::IAppleGameControllerXConnectionProtocol *delegate)
{
    _controllerObjcPtr.controllerX_connectionDelegate = delegate;
}

void AppleGameControllerX::setControllerXPauseHandlerDelegate(controllerX::IAppleGameControllerXPauseHandlerProtocol *delegate)
{
    _controllerObjcPtr.controllerX_pauseHandlerDelegate = delegate;
}

void AppleGameControllerX::setControllerXGamepadProfileAnalogDelegate(controllerX::IAppleGameControllerXGamepadProfileAnalogProtocol *delegate)
{
    _controllerObjcPtr.controllerX_gamepadAnalogDelegate = delegate;
}

void AppleGameControllerX::setControllerXGamepadProfileDigitalDelegate(controllerX::IAppleGameControllerXGamepadProfileDigitalProtocol *delegate)
{
    _controllerObjcPtr.controllerX_gamepadDigitalDelegate = delegate;
}

void AppleGameControllerX::setControllerXExtendedGamepadProfileDelegate(controllerX::IAppleGameControllerXExtendedGamepadProfileProtocol *delegate)
{
    _controllerObjcPtr.controllerX_extendedGamepadDelegate = delegate;
}

void AppleGameControllerX::setControllerXExtendedGamepadProfileAnalogDelegete(controllerX::IAppleGameControllerXExtendedGamepadProfileAnalogProtocol *delegate)
{
    _controllerObjcPtr.controllerX_extendedGamepadAnalogDelegate = delegate;
}

void AppleGameControllerX::setControllerXExtendedGamepadProfileDigitalDelegate(controllerX::IAppleGameControllerXExtendedGamepadProfileDigitalProtocol *delegate)
{
    _controllerObjcPtr.controllerX_extendedGamepadDigitalDelegate = delegate;
}

bool AppleGameControllerX::isDPadLeftPressed()
{
    return _controllerObjcPtr.dpadLeftPressed ? true : false;
}

bool AppleGameControllerX::isDPadRightPressed()
{
    return _controllerObjcPtr.dpadRightPressed ? true : false;
}

bool AppleGameControllerX::isDPadUpPressed()
{
    return _controllerObjcPtr.dpadUpPressed ? true : false;
}

bool AppleGameControllerX::isDPadDownPressed()
{
    return _controllerObjcPtr.dpadDownPressed ? true : false;
}

bool AppleGameControllerX::isButtonAPressed()
{
    return _controllerObjcPtr.buttonAPressed ? true : false;
}

bool AppleGameControllerX::isButtonBPressed()
{
    return _controllerObjcPtr.buttonBPressed ? true : false;
}

bool AppleGameControllerX::isButtonXPressed()
{
    return _controllerObjcPtr.buttonXPressed ? true : false;
}

bool AppleGameControllerX::isButtonYPressed()
{
    return _controllerObjcPtr.buttonYPressed ? true : false;
}

bool AppleGameControllerX::isLeftShoulderPressed()
{
    return _controllerObjcPtr.leftShoulderPressed ? true : false;
}

bool AppleGameControllerX::isRightShoulderPressed()
{
    return _controllerObjcPtr.rightShoulderPressed ? true : false;
}

float AppleGameControllerX::leftThumbstickXAxisValue()
{
    return _controllerObjcPtr.leftThumbstickXAxisValue;
}

float AppleGameControllerX::leftThumbstickYAxisValue()
{
    return _controllerObjcPtr.leftThumbstickYAxisValue;
}

float AppleGameControllerX::rightThumbstickXAxisValue()
{
    return _controllerObjcPtr.rightThumbstickXAxisValue;
}

float AppleGameControllerX::rightThumbstickYAxisValue()
{
    return _controllerObjcPtr.rightThumbstickYAxisValue;
}

void AppleGameControllerX::startWirelessControllerDiscovery()
{
    [_controllerObjcPtr startWirelessControllerDiscovery];
}

void AppleGameControllerX::stopWirelessControllerDiscovery()
{
    [_controllerObjcPtr stopWirelessControllerDiscovery];
}

bool AppleGameControllerX::anyControllerConnected()
{
    return [_controllerObjcPtr anyControllerConnected] == YES ? true : false;
}

int AppleGameControllerX::connectedControllersCount()
{
    return [_controllerObjcPtr connectedControllersCount];
}

controllerX::AppleGameControllerX_SupportExtendedGamepad AppleGameControllerX::supportExtendedGamepadAt(int index)
{
    return [_controllerObjcPtr supportExtendedGamepadAt:index];
}

void AppleGameControllerX::unsetAllDelegatesExceptConnectionDelegete()
{
    this->setControllerXPauseHandlerDelegate(nil);
    this->setControllerXGamepadProfileAnalogDelegate(nil);
    this->setControllerXGamepadProfileDigitalDelegate(nil);
    this->setControllerXExtendedGamepadProfileDelegate(nil);
}

void AppleGameControllerX::unsetAllDelegates()
{
    this->setControllerXConnectionDelegate(nil);
    this->setControllerXPauseHandlerDelegate(nil);
    this->setControllerXGamepadProfileAnalogDelegate(nil);
    this->setControllerXGamepadProfileDigitalDelegate(nil);
    this->setControllerXExtendedGamepadProfileDelegate(nil);
}

void AppleGameControllerX::purgeInstance()
{
    if (s_sharedInstance != NULL)
    {
        delete s_sharedInstance;
        s_sharedInstance = NULL;
        
        _controllerObjcPtr = nil;
    }
}