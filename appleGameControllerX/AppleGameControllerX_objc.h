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

#pragma mark - Polling
@property (nonatomic, readonly) BOOL dpadLeftPressed;
@property (nonatomic, readonly) BOOL dpadRightPressed;
@property (nonatomic, readonly) BOOL dpadUpPressed;
@property (nonatomic, readonly) BOOL dpadDownPressed;

@property (nonatomic, readonly) BOOL buttonAPressed;
@property (nonatomic, readonly) BOOL buttonBPressed;
@property (nonatomic, readonly) BOOL buttonXPressed;
@property (nonatomic, readonly) BOOL buttonYPressed;

@property (nonatomic, readonly) BOOL leftShoulderPressed;
@property (nonatomic, readonly) BOOL rightShoulderPressed;

- (instancetype)init;
- (void)startWirelessControllerDiscovery;
- (void)stopWirelessControllerDiscovery;
- (BOOL)anyControllerConnected;
- (NSUInteger)connectedControllersCount;
- (controllerX::AppleGameControllerX_SupportExtendedGamepad)supportExtendedGamepadAt:(NSInteger)index;

@end
