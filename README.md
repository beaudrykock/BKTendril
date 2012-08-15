#BKTendril README#

##PURPOSE##

Simple iOS implementation of 0-legged OAuth for the Tendril Connect API. Does NOT include the UI to collect credentials from the user. Intended for testing only. ARC only.

##DEPENDENCIES##

- JSON and SBJSON
- PDKeychainBindingsController
- Security.framework

but you should feel free to use the JSON library of your choice, and/or implement keychain access yourself.

##USE##

1. Copy the following to your project

	* BKTendrilAuth.h
	* BKTendrilAuth.m
	* BKTendrilConnect.h
	* BKTendrilConnect.m
	* SharedConstants.h
	* JSON folder (SBJson.h + others)
	* PDKeychainBindingsController folder

2. In SharedConstants.h, define your client ID and client secret (obtained from dev.tendrilinc.com after you create an app - look for app key and app secret). If testing, choose your preferred test user, also available from Tendril website. Also set your preferred scope (note that this will be overriden on a refresh token request).
3. Implement the delegate method in your view controller
<pre><code>-(void)tendrilConnectDidReturnData:(NSDictionary*)jsonDict forConnectionType:(NSInteger)connectionType</pre></code>
4. To initialize in your view controller, create a tendrilConnect ivar and property of type BKTendrilConnect, then:
	<pre><code>self.tendrilConnect = [[BKTendrilConnect alloc] init];
    [self.tendrilConnect authorize];</pre></code>
5. To use, call one of the public methods in BKTendrilConnect, e.g.
<pre><code>-(void)getConsumptionDataFrom:(NSTimeInterval)fromSecs to:(NSTimeInterval)toSecs;
-(void)getUserInformation;
-(void)printAccessToken;
-(void)getMeterReadingFrom:(NSTimeInterval)fromSecs to:(NSTimeInterval)toSecs;</pre></code>