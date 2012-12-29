#import <Foundation/Foundation.h>

#define kYandexGeocoderBaseUrl @"http://geocode-maps.yandex.ru"
#define kYandexGeocoderEarthRadius 6371000.01

@class YandexGeocoderClient;
@protocol YandexGeocoderDelegate;


@interface YandexGeocoder : NSObject

+ (id)sharedInstance;

- (void)cancelAllRequestsForDelegate:(id <YandexGeocoderDelegate>)delegate;

- (void)reversedGeocodingForLatitude:(double)latitude longitude:(double)longitude delegate:(id <YandexGeocoderDelegate>)delegate;

- (void)forwardGeocoding:(NSString *)address delegate:(id <YandexGeocoderDelegate>)delegate;

- (void)forwardGeocoding:(NSString *)address limitCenterLat:(double)limitCenterLat limitCenterLng:(double)limitCenterLng radius:(double)radius limitToBounds:(BOOL)limitToBounds delegate:(id <YandexGeocoderDelegate>)delegate;


@end


@protocol YandexGeocoderDelegate

/** Called if request was successful
*
* @param places List of found places
*/
- (void)yandexGeocoderRequestFinished:(NSMutableDictionary *)places;

/** Called if request failed
*/
- (void)yandexGeocoderRequestFailed;

@end