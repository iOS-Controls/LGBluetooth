// The MIT License (MIT)
//
// Created by : l0gg3r
// Copyright (c) 2014 l0gg3r. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

@class CBCharacteristic;
@class CBService;
@class CBPeripheral;
@class LGCharacteristic;

typedef void(^LGServiceDiscoverCharacterisitcsCallback)(NSArray *characteristics, NSError *error);

@interface LGService : NSObject

/**
 * Core Bluetooth's CBService instance
 */
@property (strong, nonatomic, readonly) CBService *cbService;

/**
 * Core Bluetooth's CBPeripheral instance, which this instance belongs
 */
@property (weak, nonatomic, readonly) CBPeripheral *cbPeripheral;

/**
 * NSString representation of 16/128 bit CBUUID
 */
@property (weak, nonatomic, readonly) NSString *UUIDString;

/**
 * Flag to indicate discovering characteristics or not
 */
@property (assign, nonatomic, readonly, getter = isDiscoveringCharacteristics) BOOL discoveringCharacteristics;

/**
 * Available characteristics for this service, 
 * will be updated after discoverCharacteristicsWithCompletion: call
 */
@property (strong, nonatomic) NSArray *characteristics;

/**
 * Discoveres All characteristics of this service
 * @param aCallback Will be called after successfull/failure ble-operation
 */
- (void)discoverCharacteristicsWithCompletion:(LGServiceDiscoverCharacterisitcsCallback)aCallback;

/**
 * Discoveres Input characteristics of this service
 * @param uuids Array of CBUUID's that contain characteristic UUIDs which
 * we need to discover
 * @param aCallback Will be called after successfull/failure ble-operation
 */
- (void)discoverCharacteristicsWithUUIDs:(NSArray *)uuids
                              completion:(LGServiceDiscoverCharacterisitcsCallback)aCallback;


// ----- Used for input events -----/

- (void)handleDiscoveredCharacteristics:(NSArray *)aCharacteristics error:(NSError *)aError;

- (LGCharacteristic *)wrapperByCharacteristic:(CBCharacteristic *)aChar;

/**
 * @return Wrapper object over Core Bluetooth's CBService
 */
- (instancetype)initWithService:(CBService *)aService;

@end
