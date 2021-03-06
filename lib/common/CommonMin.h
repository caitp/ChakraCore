//-------------------------------------------------------------------------------------------------------
// Copyright (C) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.txt file in the project root for full license information.
//-------------------------------------------------------------------------------------------------------
#pragma once

#include "CommonBasic.h"

// === C Runtime Header Files ===
#pragma warning(push)
#pragma warning(disable: 4995) /* 'function': name was marked as #pragma deprecated */
#include <stdio.h>
#pragma warning(pop)
#ifdef _MSC_VER
#include <intrin.h>
#endif


#if !defined(_MSC_VER) && !defined(_countof)
// TODO(caitp): are there compiler builtins for this in other toolchains?
#if !defined(__cplusplus) || (__cplusplus < 201103L)
#error "C++11 required."
#else
template <typename T, size_t N>
static inline char (&Chakra_ArraySizeHelper(T (&array)[N]))[N];
#define _countof(array) (sizeof(Chakra_ArraySizeHelper(array)))
#endif // (__cplusplus >= 201103L)
#endif

// === Core Header Files ===
#include "core/CommonMinMax.h"

#include "EnumHelp.h"
#include "core/Assertions.h"
#include "core/SysInfo.h"

#include "core/PerfCounter.h"
#include "core/PerfCounterSet.h"

#include "common/MathUtil.h"
#include "core/AllocSizeMath.h"
#include "core/FaultInjection.h"

#include "core/BasePtr.h"
#include "core/AutoFILE.h"
#include "core/Output.h"

// === Basic Memory Header Files ===
namespace Memory {
	class ArenaAllocator;
}
using namespace Memory;
#include "Memory/Allocator.h"
#include "Memory/HeapAllocator.h"

// === Data structures Header Files ===
#include "DataStructures/comparer.h"
#include "DataStructures/SizePolicy.h"
#include "DataStructures/BitVector.h"
#include "DataStructures/SList.h"
#include "DataStructures/DList.h"
#include "DataStructures/KeyValuePair.h"
#include "DataStructures/BaseDictionary.h"
#include "DataStructures/DictionaryEntry.h"

// === Configurations Header ===
#include "core/ConfigFlagsTable.h"

// === Page/Arena Memory Header Files ===
#include "Memory/VirtualAllocWrapper.h"
#include "Memory/MemoryTracking.h"
#include "Memory/AllocationPolicyManager.h"
#include "Memory/PageAllocator.h"
#include "Memory/ArenaAllocator.h"
