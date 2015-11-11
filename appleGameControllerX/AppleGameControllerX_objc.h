//
//  AppleGameControllerX_objc.h
//  HelloCpp
//
//  Created by Wasin Thonkaew on 11/10/15.
//
//

#import <Foundation/Foundation.h>

#include "IAppleGameControllerXProtocol.h"

#pragma mark Interface typedef
/*typedef controllerX::IAppleGameControllerXConnectionProtocol* IAppleGameControllerXConnectionProtocol;
typedef controllerX::IAppleGameControllerXPauseHandlerProtocol* IAppleGameControllerXPauseHandlerProtocol;
typedef controllerX::IAppleGameControllerXGamepadProfileProtocol* IAppleGameControllerXGamepadProfileProtocol;*/

@interface AppleGameControllerX_objc : NSObject

@property (nonatomic, assign) controllerX::IAppleGameControllerXConnectionProtocol* controllerX_connectionDelegate;
@property (nonatomic, assign) controllerX::IAppleGameControllerXPauseHandlerProtocol* controllerX_pauseHandlerDelegate;
@property (nonatomic, assign) controllerX::IAppleGameControllerXGamepadProfileAnalogProtocol* controllerX_gamepadAnalogDelegate;
@property (nonatomic, assign) controllerX::IAppleGameControllerXGamepadProfileDigitalProtocol* controllerX_gamepadDigitalDelegate;

- (instancetype)init;
- (void)startWirelessControllerDiscovery;
- (void)stopWirelessControllerDiscovery;
- (BOOL)anyControllerConnected;
- (NSUInteger)connectedControllersCount;
- (controllerX::AppleGameControllerX_SupportExtendedGamepad)supportExtendedGamepadAt:(NSInteger)index;

@end
