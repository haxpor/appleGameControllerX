//
//  AppleGameControllerX_objc.mm
//  HelloCpp
//
//  Created by Wasin Thonkaew on 11/10/15.
//
//

#import "AppleGameControllerX_objc.h"
#import <GameController/GameController.h>

@implementation AppleGameControllerX_objc
{
    GCController *_controller;
}

- (instancetype)init
{
    self = [super init];
    if (self)
    {
        
    }
    return self;
}

- (void)startWirelessControllerDiscovery
{
    //Add observers here
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(internal_controllerDidConnected:) name:GCControllerDidConnectNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(internal_controllerDidDisconnected:) name:GCControllerDidDisconnectNotification object:nil];
    
    // start dicovery for wireless controller
    [GCController startWirelessControllerDiscoveryWithCompletionHandler:nil];
}

- (void)stopWirelessControllerDiscovery
{
    // remove observers
    [[NSNotificationCenter defaultCenter] removeObserver:self name:GCControllerDidConnectNotification object:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:GCControllerDidDisconnectNotification object:nil];
    
    [GCController stopWirelessControllerDiscovery];
}

#pragma mark - Internal listener to controllerDidConnected
- (void)internal_controllerDidConnected:(NSNotification*) notification
{
    _controller = [GCController controllers][GCControllerPlayerIndex1];
    _controller.playerIndex = GCControllerPlayerIndex1;
    
    __unsafe_unretained AppleGameControllerX_objc *weakSelf = self;
    
    _controller.controllerPausedHandler = ^(GCController *controller)
    {
        // pause
        if (weakSelf.controllerX_pauseHandlerDelegate)
            weakSelf.controllerX_pauseHandlerDelegate->onGameControllerPauseButtonPressed();
    };
    
    if (_controller.gamepad)
    {
        // Analog
        //      A, B, X, Y
        _controller.gamepad.buttonA.valueChangedHandler = ^(GCControllerButtonInput *button, float value, BOOL pressed)
        {
            if (weakSelf.controllerX_gamepadAnalogDelegate)
                weakSelf.controllerX_gamepadAnalogDelegate->onGamepadProfile_buttonA_valueChanged(value, pressed);
        };
        _controller.gamepad.buttonB.valueChangedHandler = ^(GCControllerButtonInput *button, float value, BOOL pressed)
        {
            if (weakSelf.controllerX_gamepadAnalogDelegate)
                weakSelf.controllerX_gamepadAnalogDelegate->onGamepadProfile_buttonB_valueChanged(value, pressed);
        };
        _controller.gamepad.buttonX.valueChangedHandler = ^(GCControllerButtonInput *button, float value, BOOL pressed)
        {
            if (weakSelf.controllerX_gamepadAnalogDelegate)
                weakSelf.controllerX_gamepadAnalogDelegate->onGamepadProfile_buttonX_valueChanged(value, pressed);
        };
        _controller.gamepad.buttonY.valueChangedHandler = ^(GCControllerButtonInput *button, float value, BOOL pressed)
        {
            if (weakSelf.controllerX_gamepadAnalogDelegate)
                weakSelf.controllerX_gamepadAnalogDelegate->onGamepadProfile_buttonY_valueChanged(value, pressed);
        };
        
        //      Dpad
        _controller.gamepad.dpad.left.valueChangedHandler = ^(GCControllerButtonInput *button, float value, BOOL pressed)
        {
            if (weakSelf.controllerX_gamepadAnalogDelegate)
                weakSelf.controllerX_gamepadAnalogDelegate->onGamepadProfile_DpadLeft_valueChanged(value, pressed);
        };
        _controller.gamepad.dpad.right.valueChangedHandler = ^(GCControllerButtonInput *button, float value, BOOL pressed)
        {
            if (weakSelf.controllerX_gamepadAnalogDelegate)
                weakSelf.controllerX_gamepadAnalogDelegate->onGamepadProfile_DpadRight_valueChanged(value, pressed);
        };
        _controller.gamepad.dpad.up.valueChangedHandler = ^(GCControllerButtonInput *button, float value, BOOL pressed)
        {
            if (weakSelf.controllerX_gamepadAnalogDelegate)
                weakSelf.controllerX_gamepadAnalogDelegate->onGamepadProfile_DpadUp_valueChanged(value, pressed);
        };
        _controller.gamepad.dpad.down.valueChangedHandler = ^(GCControllerButtonInput *button, float value, BOOL pressed)
        {
            if (weakSelf.controllerX_gamepadAnalogDelegate)
                weakSelf.controllerX_gamepadAnalogDelegate->onGamepadProfile_DpadDown_valueChanged(value, pressed);
        };
        
        //      shoulder buttons
        _controller.gamepad.leftShoulder.valueChangedHandler = ^(GCControllerButtonInput *button, float value, BOOL pressed)
        {
            if (weakSelf.controllerX_gamepadAnalogDelegate)
                weakSelf.controllerX_gamepadAnalogDelegate->onGamepadProfile_leftShoulder_valueChanged(value, pressed);
        };
        _controller.gamepad.rightShoulder.valueChangedHandler = ^(GCControllerButtonInput *button, float value, BOOL pressed)
        {
            if (weakSelf.controllerX_gamepadAnalogDelegate)
                weakSelf.controllerX_gamepadAnalogDelegate->onGamepadProfile_rightShoulder_valueChanged(value, pressed);
        };
        
        // Digital
        //      A, B, X, Y
        _controller.gamepad.buttonA.pressedChangedHandler = ^(GCControllerButtonInput *button, float value, BOOL pressed)
        {
            if (weakSelf.controllerX_gamepadDigitalDelegate)
                weakSelf.controllerX_gamepadDigitalDelegate->onGamepadProfile_buttonA_pressedChanged(value, pressed);
        };
        _controller.gamepad.buttonB.pressedChangedHandler = ^(GCControllerButtonInput *button, float value, BOOL pressed)
        {
            if (weakSelf.controllerX_gamepadDigitalDelegate)
                weakSelf.controllerX_gamepadDigitalDelegate->onGamepadProfile_buttonB_pressedChanged(value, pressed);
        };
        _controller.gamepad.buttonX.pressedChangedHandler = ^(GCControllerButtonInput *button, float value, BOOL pressed)
        {
            if (weakSelf.controllerX_gamepadDigitalDelegate)
                weakSelf.controllerX_gamepadDigitalDelegate->onGamepadProfile_buttonX_pressedChanged(value, pressed);
        };
        _controller.gamepad.buttonY.pressedChangedHandler = ^(GCControllerButtonInput *button, float value, BOOL pressed)
        {
            if (weakSelf.controllerX_gamepadDigitalDelegate)
                weakSelf.controllerX_gamepadDigitalDelegate->onGamepadProfile_buttonY_pressedChanged(value, pressed);
        };
        
        //      Dpad
        _controller.gamepad.dpad.left.pressedChangedHandler = ^(GCControllerButtonInput *button, float value, BOOL pressed)
        {
            if (weakSelf.controllerX_gamepadDigitalDelegate)
                weakSelf.controllerX_gamepadDigitalDelegate->onGamepadProfile_DpadLeft_pressedChanged(value, pressed);
        };
        _controller.gamepad.dpad.right.pressedChangedHandler = ^(GCControllerButtonInput *button, float value, BOOL pressed)
        {
            if (weakSelf.controllerX_gamepadDigitalDelegate)
                weakSelf.controllerX_gamepadDigitalDelegate->onGamepadProfile_DpadRight_pressedChanged(value, pressed);
        };
        _controller.gamepad.dpad.up.pressedChangedHandler = ^(GCControllerButtonInput *button, float value, BOOL pressed)
        {
            if (weakSelf.controllerX_gamepadDigitalDelegate)
                weakSelf.controllerX_gamepadDigitalDelegate->onGamepadProfile_DpadUp_pressedChanged(value, pressed);
        };
        _controller.gamepad.dpad.down.pressedChangedHandler = ^(GCControllerButtonInput *button, float value, BOOL pressed)
        {
            if (weakSelf.controllerX_gamepadDigitalDelegate)
                weakSelf.controllerX_gamepadDigitalDelegate->onGamepadProfile_DpadDown_pressedChanged(value, pressed);
        };
        
        //      shoulder buttons
        _controller.gamepad.leftShoulder.pressedChangedHandler = ^(GCControllerButtonInput *button, float value, BOOL pressed)
        {
            if (weakSelf.controllerX_gamepadDigitalDelegate)
                weakSelf.controllerX_gamepadDigitalDelegate->onGamepadProfile_leftShoulder_pressedChanged(value, pressed);
        };
        _controller.gamepad.rightShoulder.pressedChangedHandler = ^(GCControllerButtonInput *button, float value, BOOL pressed)
        {
            if (weakSelf.controllerX_gamepadDigitalDelegate)
                weakSelf.controllerX_gamepadDigitalDelegate->onGamepadProfile_rightShoulder_pressedChanged(value, pressed);
        };
    }
    if (_controller.extendedGamepad)
    {
        // Basic
        // two thumbsticks
        _controller.extendedGamepad.leftThumbstick.valueChangedHandler = ^(GCControllerDirectionPad *dpad, float xValue, float yValue)
        {
            if (weakSelf.controllerX_extendedGamepadDelegate)
                weakSelf.controllerX_extendedGamepadDelegate->onExtendedGamepadProfile_leftThumbstick_valueChanged(xValue, yValue);
        };
        _controller.extendedGamepad.rightThumbstick.valueChangedHandler = ^(GCControllerDirectionPad *dpad, float xValue, float yValue)
        {
            if (weakSelf.controllerX_extendedGamepadDelegate)
                weakSelf.controllerX_extendedGamepadDelegate->onExtendedGamepadProfile_rightThumbstick_valueChanged(xValue, yValue);
        };
        
        // Analog
        _controller.extendedGamepad.leftTrigger.valueChangedHandler = ^(GCControllerButtonInput *button, float value, BOOL pressed)
        {
            if (weakSelf.controllerX_extendedGamepadAnalogDelegate)
                weakSelf.controllerX_extendedGamepadAnalogDelegate->onExtendedGamepadProfile_leftTrigger_valueChanged(value, pressed);
        };
        _controller.extendedGamepad.rightTrigger.valueChangedHandler = ^(GCControllerButtonInput *button, float value, BOOL pressed)
        {
            if (weakSelf.controllerX_extendedGamepadAnalogDelegate)
                weakSelf.controllerX_extendedGamepadAnalogDelegate->onExtendedGamepadProfile_rightTrigger_valueChanged(value, pressed);
        };
        
        // Digital
        _controller.extendedGamepad.leftTrigger.pressedChangedHandler = ^(GCControllerButtonInput *button, float value, BOOL pressed)
        {
            if (weakSelf.controllerX_extendedGamepadDigitalDelegate)
                weakSelf.controllerX_extendedGamepadDigitalDelegate->onExtendedGamepadProfile_leftTrigger_pressedChanged(value, pressed);
        };
        _controller.extendedGamepad.rightTrigger.pressedChangedHandler = ^(GCControllerButtonInput *button, float value, BOOL pressed)
        {
            if (weakSelf.controllerX_extendedGamepadDigitalDelegate)
                weakSelf.controllerX_extendedGamepadDigitalDelegate->onExtendedGamepadProfile_rightTrigger_pressedChanged(value, pressed);
        };
    }
    
    if (self.controllerX_connectionDelegate)
        self.controllerX_connectionDelegate->onGameControllerDidConnect();
}

#pragma mark - Internal listener to controllerDidDisconnected
- (void)internal_controllerDidDisconnected:(NSNotification*) notification
{
    if (self.controllerX_connectionDelegate)
        self.controllerX_connectionDelegate->onGameControllerDidDisconnect();
}

- (void)dealloc
{
    // remove observers
    [[NSNotificationCenter defaultCenter] removeObserver:self name:GCControllerDidConnectNotification object:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:GCControllerDidDisconnectNotification object:nil];
}

- (BOOL)anyControllerConnected
{
    return [[GCController controllers] count] > 0 ? YES : NO;
}

- (NSUInteger)connectedControllersCount
{
    return [[GCController controllers] count];
}

- (controllerX::AppleGameControllerX_SupportExtendedGamepad)supportExtendedGamepadAt:(NSInteger)index
{
    if ([[GCController controllers] count] > index)
    {
        return [GCController controllers][index].extendedGamepad != nil ? controllerX::kAppleGameControllerX_supportExtendedGamepad : controllerX::kAppleGamecontrollerX_notSupportExtendedGamepad;
    }
    else
        return controllerX::kAppleGameControllerX_null;
}

@end
