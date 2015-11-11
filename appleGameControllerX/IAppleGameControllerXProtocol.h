//
//  IAppleGameControllerXProtocol.h
//  HelloCpp
//
//  Created by Wasin Thonkaew on 11/10/15.
//
//

#ifndef IAppleGameControllerXProtocol_h
#define IAppleGameControllerXProtocol_h

namespace controllerX {
    
    typedef enum AppleGameControllerX_SupportExtendedGamepadTypes
    {
        kAppleGamecontrollerX_notSupportExtendedGamepad = -1,
        kAppleGameControllerX_supportExtendedGamepad = 0,
        kAppleGameControllerX_null = 1
    } AppleGameControllerX_SupportExtendedGamepad;

    class IAppleGameControllerXConnectionProtocol
    {
    public:
        virtual ~IAppleGameControllerXConnectionProtocol() {}
        
        virtual void onGameControllerDidConnect() = 0;
        virtual void onGameControllerDidDisconnect() = 0;
    };

    class IAppleGameControllerXPauseHandlerProtocol
    {
    public:
        virtual ~IAppleGameControllerXPauseHandlerProtocol() {}
        
        virtual void onGameControllerPauseButtonPressed() = 0;
    };

    class IAppleGameControllerXGamepadProfileAnalogProtocol
    {
    public:
        virtual ~IAppleGameControllerXGamepadProfileAnalogProtocol() {}
        
        // A, B, X, Y
        virtual void onGamepadProfile_buttonA_valueChanged(float value, bool pressed) = 0;
        virtual void onGamepadProfile_buttonB_valueChanged(float value, bool pressed) = 0;
        virtual void onGamepadProfile_buttonY_valueChanged(float value, bool pressed) = 0;
        virtual void onGamepadProfile_buttonX_valueChanged(float value, bool pressed) = 0;
        
        // D-Pad
        virtual void onGamepadProfile_DpadLeft_valueChanged(float value, bool pressed) = 0;
        virtual void onGamepadProfile_DpadRight_valueChanged(float value, bool pressed) = 0;
        virtual void onGamepadProfile_DpadUp_valueChanged(float value, bool pressed) = 0;
        virtual void onGamepadProfile_DpadDown_valueChanged(float value, bool pressed) = 0;
        
        // shoulder button
        virtual void onGamepadProfile_leftShoulder_valueChanged(float value, bool pressed) = 0;
        virtual void onGamepadProfile_rightShoulder_valueChanged(float value, bool pressed) = 0;
    };
        
    class IAppleGameControllerXGamepadProfileDigitalProtocol
    {
    public:
        virtual ~IAppleGameControllerXGamepadProfileDigitalProtocol() {}
        
        // A, B, X, Y
        virtual void onGamepadProfile_buttonA_pressedChanged(float value, bool pressed) = 0;
        virtual void onGamepadProfile_buttonB_pressedChanged(float value, bool pressed) = 0;
        virtual void onGamepadProfile_buttonY_pressedChanged(float value, bool pressed) = 0;
        virtual void onGamepadProfile_buttonX_pressedChanged(float value, bool pressed) = 0;
        
        // D-Pad
        virtual void onGamepadProfile_DpadLeft_pressedChanged(float value, bool pressed) = 0;
        virtual void onGamepadProfile_DpadRight_pressedChanged(float value, bool pressed) = 0;
        virtual void onGamepadProfile_DpadUp_pressedChanged(float value, bool pressed) = 0;
        virtual void onGamepadProfile_DpadDown_pressedChanged(float value, bool pressed) = 0;
        
        // shoulder button
        virtual void onGamepadProfile_leftShoulder_pressedChanged(float value, bool pressed) = 0;
        virtual void onGamepadProfile_rightShoulder_pressedChanged(float value, bool pressed) = 0;
    };
        
    class   IAppleGameControllerXExtendedGamepadProfileProtocol
    {
    public:
        virtual ~IAppleGameControllerXExtendedGamepadProfileProtocol() {}
        
        virtual void onExtendedGamepadProfile_leftThumbstick_valueChanged(float xValue, float yValue) = 0;
        virtual void onExtendedGamepadProfile_rightThumbstick_valueChanged(float xValue, float yValue) = 0;
    };
}

#endif /* IAppleGameControllerXProtocol_h */
