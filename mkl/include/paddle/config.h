#ifndef __PADDLE_PADDLE_CAPI_CONFIG_H_INCLUDED__
#define __PADDLE_PADDLE_CAPI_CONFIG_H_INCLUDED__

typedef float paddle_real;

// Since we only support linux and macos in compile, always use clang or
// gcc 4.8+. DLL_IMPORT/DLL_EXPORT is as simple as below.
#define PD_API __attribute__((visibility("default")))

#endif