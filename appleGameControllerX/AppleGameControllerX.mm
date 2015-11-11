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

AppleGameControllerX::AppleGameControllerX():
_controllerObjcPtr(nil)
{
    _controllerObjcPtr = [[AppleGameControllerX_objc alloc] init];
}

AppleGameControllerX::~AppleGameControllerX()
{
    
}

AppleGameControllerX* AppleGameControllerX::sharedInstance()
{
    if (s_sharedInstance == NULL)
    {
        s_sharedInstance = new AppleGameControllerX();
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

void AppleGameControllerX::purgeInstance()
{
    if (s_sharedInstance != NULL)
    {
        delete s_sharedInstance;
        s_sharedInstance = NULL;
    }
}