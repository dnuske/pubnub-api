#import <stdio.h>
#import <Cocoa/Cocoa.h>
#import <CommonCrypto/CommonDigest.h>
#import "JSON/JSON.h"
#import "request.h"

@interface Pubnub: NSObject {
    NSString* publish_key;
    NSString* subscribe_key;
    NSString* secret_key;
    NSString* scheme;
    NSString* host;
    NSString* current_uuid;
    NSMutableDictionary* subscriptions;
    NSMutableDictionary*  _connections;
    NSAutoreleasePool* pool;
    SBJsonParser* parser;
    SBJsonWriter* writer;
}

-(Pubnub*)
    publishKey:   (NSString*) pub_key
    subscribeKey: (NSString*) sub_key
    secretKey:    (NSString*) sec_key
    sslOn:        (BOOL)      ssl_on
    origin:       (NSString*) origin;

-(void)
    publish:  (NSString*) channel
    message:  (id)        message
    delegate: (id)        delegate;

-(void)
    subscribe: (NSString*) channel
    delegate:  (id)        delegate;

-(void) subscribe: (NSDictionary*) args;
-(BOOL) subscribed: (NSString*) channel;

- (void)
    hereNow:(NSString *)channel
    delegate: (id)delegate;

- (void)detailedHistory:(NSDictionary * )arg1;

-(void)
    history:  (NSString*) channel
    limit:    (int)       limit
    delegate: (id)        delegate;

-(void) unsubscribe: (NSString*) channel;
-(void) removeConnection: (NSString*) channel;

-(void) time: (id) delegate;
+ (NSString*) uuid;

-(void)
presence: (NSString*) channel
delegate:  (id)        delegate;
@end

@interface SubscribeDelegate: Response @end
@interface PresenceDelegate:  Response @end
@interface TimeDelegate:      Response @end

