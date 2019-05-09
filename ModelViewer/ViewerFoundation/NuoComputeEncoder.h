//
//  NuoComputeEncoder.h
//  ModelViewer
//
//  Created by middleware on 7/8/18.
//  Copyright © 2018 middleware. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Metal/Metal.h>



@class NuoComputeEncoder;
@class NuoCommandBuffer;



@interface NuoComputePipeline : NSObject



@property (nonatomic, strong) NSString* name;


- (instancetype)initWithDevice:(id<MTLDevice>)device withFunction:(NSString*)function
                 withParameter:(BOOL)param;


- (NuoComputeEncoder*)encoderWithCommandBuffer:(NuoCommandBuffer*)commandBuffer;


@end



@interface NuoComputeEncoder : NSObject


@property (nonatomic, assign) CGSize dataSize;


- (void)pushParameterState:(NSString*)name;
- (void)popParameterState;

- (void)setTargetTexture:(id<MTLTexture>)texture atIndex:(uint)index;
- (void)setTexture:(id<MTLTexture>)texture atIndex:(uint)index;
- (void)setSamplerState:(id<MTLSamplerState>)sampler atIndex:(uint)index;
- (void)setBuffer:(id<MTLBuffer>)buffer offset:(uint)offset atIndex:(uint)index;

- (void)dispatch;


@end

