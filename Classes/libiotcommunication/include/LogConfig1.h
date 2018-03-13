//
//  Log_config.h
//  LogDemo
//
//  Created by ly on 15/12/1.
//  Copyright © 2015年 leno. All rights reserved.


#ifndef Log_config_h
#define Log_config_h

#define ENABLE_LOG 1
#define LOG_LEVEL  4
#if ENABLE_LOG

#if LOG_LEVEL <= 0 || LOG_LEVEL>4
#define LogError(fmt, ...) {}
#define LogWarning(fmt, ...) {}
#define LogDebug(fmt, ...)  {}
#define LogInfo(fmt, ...)   {}
#endif

#if LOG_LEVEL == 1
//#define LogError(fmt, ...) {NSLog((@"Error:%@ [Line %d] " fmt), NSStringFromClass(self.class), __LINE__, ##__VA_ARGS__);}
#define LogError(fmt,...)\
do {\
if([LibProperty isLogEnable]){\
NSLog((@"Error:%@ [Line %d] " fmt), NSStringFromClass(self.class), __LINE__, ##__VA_ARGS__);\
}\
}while(0)
#define LogWarning(fmt, ...) {}
#define LogDebug(fmt, ...)  {}
#define LogInfo(fmt, ...)   {}
#endif

#if LOG_LEVEL == 2
#define LogError(fmt,...)\
do {\
if([LibProperty isLogEnable]){\
NSLog((@"Error:%@ [Line %d] " fmt), NSStringFromClass(self.class), __LINE__, ##__VA_ARGS__);\
}\
}while(0)

#define LogWarning(fmt,...)\
do {\
if([LibProperty isLogEnable]){\
NSLog((@"Warning:%@ [Line %d] " fmt), NSStringFromClass(self.class), __LINE__, ##__VA_ARGS__);\
}\
}while(0)
#define LogDebug(fmt, ...)  {}
#define LogInfo(fmt, ...)   {}
#endif

#if LOG_LEVEL == 3
#define LogError(fmt,...)\
do {\
if([LibProperty isLogEnable]){\
NSLog((@"Error:%@ [Line %d] " fmt), NSStringFromClass(self.class), __LINE__, ##__VA_ARGS__);\
}\
}while(0)

#define LogWarning(fmt,...)\
do {\
if([LibProperty isLogEnable]){\
NSLog((@"Warning:%@ [Line %d] " fmt), NSStringFromClass(self.class), __LINE__, ##__VA_ARGS__);\
}\
}while(0)

#define LogDebug(fmt,...)\
do {\
if([LibProperty isLogEnable]){\
NSLog((@"Debug:%@ [Line %d] " fmt), NSStringFromClass(self.class), __LINE__, ##__VA_ARGS__);\
}\
}while(0)
#define LogInfo(fmt, ...)   {}
#endif

#if LOG_LEVEL == 4
#define LogError(fmt,...)\
do {\
if([LibProperty isLogEnable]){\
NSLog((@"Error:%@ [Line %d] " fmt), NSStringFromClass(self.class), __LINE__, ##__VA_ARGS__);\
}\
}while(0)

#define LogWarning(fmt,...)\
do {\
if([LibProperty isLogEnable]){\
NSLog((@"Warning:%@ [Line %d] " fmt), NSStringFromClass(self.class), __LINE__, ##__VA_ARGS__);\
}\
}while(0)

#define LogDebug(fmt,...)\
do {\
if([LibProperty isLogEnable]){\
NSLog((@"Debug:%@ [Line %d] " fmt), NSStringFromClass(self.class), __LINE__, ##__VA_ARGS__);\
}\
}while(0)

#define LogInfo(fmt,...)\
do {\
if([LibProperty isLogEnable]){\
NSLog((@"Info:%@ [Line %d] " fmt), NSStringFromClass(self.class), __LINE__, ##__VA_ARGS__);\
}\
}while(0)
#endif

#else  //如果log开关关闭
#define LogError(fmt, ...) {}
#define LogWarning(fmt, ...) {}
#define LogDebug(fmt, ...)  {}
#define LogInfo(fmt, ...)   {}

#endif



#endif /* Log_config_h */
