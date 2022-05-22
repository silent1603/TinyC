#ifndef DEFINE_H
#define DEFINE_H
#include <assert.h>
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

typedef float f32;
typedef double f64;


typedef int  b32;
typedef char b8;

static_assert(sizeof(u8) == 1,"Expected u8 to be 1 byte");
static_assert(sizeof(u16) == 2,"Expected u8 to be 2 bytes");
static_assert(sizeof(u32) == 4,"Expected u8 to be 4 bytes");
static_assert(sizeof(u64) == 8,"Expected u8 to be 6 bytes");

static_assert(sizeof(i8) == 1,"Expected u8 to be 1 byte");
static_assert(sizeof(i16) == 2,"Expected u8 to be 2 bytes");
static_assert(sizeof(i32) == 4,"Expected u8 to be 4 bytes");
static_assert(sizeof(i64) == 8,"Expected u8 to be 6 bytes");

static_assert(sizeof(f32) == 4,"Expected u8 to be 4 bytes");
static_assert(sizeof(f64) == 8,"Expected u8 to be 8 bytes");

#define TRUE 1
#define FALSE 0

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#define TPLATFORM_WINDOWS 1
#ifndef _WIN64
#error "64-bit is required on Window "
#endif
#elif defined(__linux__) || defined(__gbu_linux__)
#define TPLATFORM_LINUX 1
#if defined(__ANDROID__)
#define TPLATFORM_ANDROID 1
#endif
#elif defined(__unix__)
#define TPLATFORM_UNIX 1
#elif defined(_POSIX_VERSION)
#define TPLATFORM_POSXI 1
#elif __APPLE__
#define TPLATFORM_APPLE 1
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
#define TPLATFORM_APPLE 1
#define TPLATFORM_IOS_SIMULATOR 1
#elif TARGET_OS_IPHONE
#define TPLATFORM_OS_IPHONE
#elif TARGET_OS_MAC
#else
#error "Unknown Apple platform"
#endif
#else 
#error "Unknown platform"
#endif

#ifndef TEXPORT
#ifdef _MSC_VER
#define TAPI __declspec(dllexport)
#else
#define TAPI __attribute__((visibility("default")))
#endif
#else
#ifdef _MSC_VER
#define KAPI __declspec(dllimport)
#else
#define KAPI
#endif
#endif

#endif