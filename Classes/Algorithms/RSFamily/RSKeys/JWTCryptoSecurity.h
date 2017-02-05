//
//  JWTCryptoSecurity.h
//  JWT
//
//  Created by Lobanov Dmitry on 04.02.17.
//  Copyright © 2017 JWTIO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Security/Security.h>
@interface JWTCryptoSecurity : NSObject
+ (SecKeyRef)addKeyWithData:(NSData *)data asPublic:(BOOL)public tag:(NSString *)tag error:(NSError *__autoreleasing*)error;
+ (SecKeyRef)keyByTag:(NSString *)tag error:(NSError *__autoreleasing*)error;
+ (void)removeKeyByTag:(NSString *)tag error:(NSError *__autoreleasing*)error;
@end

@interface JWTCryptoSecurity (Certificates)
+ (OSStatus)extractIdentityAndTrustFromPKCS12:(CFDataRef)inPKCS12Data password:(CFStringRef)password identity:(SecIdentityRef *)outIdentity trust:(SecTrustRef *)outTrust;
+ (SecKeyRef)publicKeyFromCertificate:(NSData *)certificateData;
@end

@interface JWTCryptoSecurity (Pem)
+ (NSString *)stringByRemovingPemHeadersFromString:(NSString *)string;
@end

@interface JWTCryptoSecurity (PublicKey)
+ (NSData *)dataByRemovingPublicKeyHeader:(NSData *)data;
@end
