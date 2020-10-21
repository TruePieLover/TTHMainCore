/////////////////////////////////////////////////////////////////////////
//				TTHMainCore vTTHMain1.0 (DevBuild)
// Author: Pie
// Project: PieCore
// Creation Date: 10/7/2020
// Copyright2020: TTH and all registered domains
// frammework.h: Layout the main app framework
/////////////////////////////////////////////////////////

#pragma once
#include "pch.h"
#include "targetver.h"

/* Define our compatible systems for app */
#define WIN32_SYSTEM auto // For Win32 compatibler systems
#define CONSOLE_SYSTEM auto // For c++ compatible console systems
#define LINUX_SYSTEM auto // Linux only based systems
#define SYSTEM_ERROR auto // Error 

#if defined(WIN32) 
#define WIN32_SYSTEM true
#endif
#if defined(__cplusplus)
#define CONSOLE_SYSTEM true
#include <iostream>
#elif defined(__linux__)
#define LINUX_SYSTEM true
#else
#define SYSTEM ERROR "Error, no compatible system found"
#endif

#if(WIN32_SYSTEM)
#define USE_WIN32_SUBSYSTEM
#endif

#if(CONSOLE_SYSTEM)
#undef USING_CONSOLE_SUBSYSTEM
#endif