//-------------------------------------------------------------------------------------------------------
// Copyright (C) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.txt file in the project root for full license information.
//-------------------------------------------------------------------------------------------------------
#pragma once

namespace Js
{
    class DefaultListLockPolicy;

#if defined(_M_X64_OR_ARM64) || defined(BIT64)
    // Some data structures such as jmp_buf expect to be 16 byte aligned on AMD64.
    static const size_t ArenaAllocatorObjectAlignmentBitShift = 4;
    static const bool ArenaAllocatorRequireObjectAlignment = false;
    static const size_t ArenaAllocatorMaxObjectSize = 0;
#else
    static const size_t ArenaAllocatorObjectAlignmentBitShift = 3;
    static const bool ArenaAllocatorRequireObjectAlignment = false;
    static const size_t ArenaAllocatorMaxObjectSize = 0;
#endif

    static const unsigned int HeapConstantsObjectAllocationShift = 4;        // 16
    static const unsigned int HeapConstantsObjectGranularity = 1 << HeapConstantsObjectAllocationShift;
}

