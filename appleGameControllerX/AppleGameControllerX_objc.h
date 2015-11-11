//
//  AppleGameControllerX_objc.h
//  HelloCpp
//
//  Created by Wasin Thonkaew on 11/10/15.
//
//

#import <Foundation/Foundation.h>

#include "IAppleGameControllerXProtocol.h"

@interface AppleGameControllerX_objc : NSObject

@property (nonatomic, assign) controllerX::IAppleGameControllerXConnectionProtocol* controllerX_connectionDelegate;
@property (nonatomic, assign) controllerX::IAppleGameControllerXPauseHandlerProtocol* controllerX_pauseHandlerDelegate;
@property (nonatomic, assign) controllerX::IAppleGameControllerXGamepadProfileAnalogProtocol* controllerX_gamepadAnalogDelegate;
@property (nonatomic, assign) controllerX::IAppleGameControllerXGamepadProfileDigitalProtocol* controllerX_gamepadDigitalDelegate;
@property (nonatomic, assign) controllerX::IAppleGameControllerXExtendedGamepadProfileProtocol* controllerX_extendedGamepadDelegate;
@property (nonatomic, assign) controllerX::IAppleGameControllerXExtendedGamepadProfileAnalogProtocol* controllerX_extendedGamepadAnalogDelegate;
@property (nonatomic, assign) controllerX::IAppleGameControllerXExtendedGamepadProfileDigitalProtocol* controllerX_extendedGamepadDigitalDelegate;

- (instancetype)init;
- (void)startWirelessControllerDiscovery;
- (void)stopWirelessControllerDiscovery;
- (BOOL)anyControllerConnected;
- (NSUInteger)connectedControllersCount;
- (controllerX::AppleGameControllerX_SupportExtendedGamepad)supportExtendedGamepadAt:(NSInteger)index;

@end
