/////////////////////////////////////////////////////////////////////////
//				TTHMainCore vTTHMain1.0 (DevBuild)
// Author: Pie
// Project: PieCore
// Creation Date: 10/7/2020
// Copyright2020: TTH and all registered domains
// frammework.h: Layout the main app framework
/////////////////////////////////////////////////////////

#pragma once

/* Setup main PieCore app definitions */

// Define platform used, assume and init undefined until the check can determine and set otherwise
#define WIN32_COMPATIBLE_PLATFORM false  
#define CROSS_COMPATINLE_PLATFORM false
#define UNDEFINED_PLATFORM true 
/* Win32 compatible includes*/
#if defined(WIN32) || (_WIN32) || (_WIN64) 
#include "targetver.h"
#define WIN32_LEAN_AND_MEAN // Exclude rarely used window features
/* Important window platform includes */
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#else
/* Not win32 compatible includes */
#endif

