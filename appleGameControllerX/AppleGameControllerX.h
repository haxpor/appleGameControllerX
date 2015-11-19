//
//  AppleGameControllerX.h
//
//
//  Created by Wasin Thonkaew on 11/9/15.
//
//

#ifndef __AppleGameControllerX_AppleGameControllerX__
#define __AppleGameControllerX_AppleGameControllerX__

#include "IAppleGameControllerXProtocol.h"

#ifdef __OBJC__
@class AppleGameControllerX_objc;
typedef AppleGameControllerX_objc *AppleGameControllerX_objcPtr;
#else
typedef void* AppleGameControllerX_objcPtr;
#endif

namespace controllerX {

class AppleGameControllerX
{
public:
    AppleGameControllerX();
    virtual ~AppleGameControllerX();
    
    void setControllerXConnectionDelegate(controllerX::IAppleGameControllerXConnectionProtocol* delegate);
    void setControllerXPauseHandlerDelegate(controllerX::IAppleGameControllerXPauseHandlerProtocol* delegate);
    void setControllerXGamepadProfileAnalogDelegate(controllerX::IAppleGameControllerXGamepadProfileAnalogProtocol* delegate);
    void setControllerXGamepadProfileDigitalDelegate(controllerX::IAppleGameControllerXGamepadProfileDigitalProtocol* delegate);
    void setControllerXExtendedGamepadProfileDelegate(controllerX::IAppleGameControllerXExtendedGamepadProfileProtocol* delegate);
    void setControllerXExtendedGamepadProfileAnalogDelegete(controllerX::IAppleGameControllerXExtendedGamepadProfileAnalogProtocol* delegate);
    void setControllerXExtendedGamepadProfileDigitalDelegate(controllerX::IAppleGameControllerXExtendedGamepadProfileDigitalProtocol* delegate);
    
    bool isDPadLeftPressed();
    bool isDPadRightPressed();
    bool isDPadUpPressed();
    bool isDPadDownPressed();
    
    bool isButtonAPressed();
    bool isButtonBPressed();
    bool isButtonXPressed();
    bool isButtonYPressed();
    
    bool isLeftShoulderPressed();
    bool isRightShoulderPressed();
    
    void startWirelessControllerDiscovery();
    void stopWirelessControllerDiscovery();
    bool anyControllerConnected();
    int connectedControllersCount();
    controllerX::AppleGameControllerX_SupportExtendedGamepad supportExtendedGamepadAt(int index);
    
    void unsetAllDelegatesExceptConnectionDelegete();
    void unsetAllDelegates();
    
    void purgeInstance();
    static AppleGameControllerX* sharedInstance();
    
private:
    static AppleGameControllerX_objcPtr _controllerObjcPtr;
};
    
}

#endif
