// =============================================================================
// Pod28_FillAssign_Forward  (aa_0045efe0)
// -----------------------------------------------------------------------------
// Address:   0x0045efe0–0x0045effb exclusive (27 B)  autoassault.exe @ 0x400000
// System:    MSVC-style forward fill-assign for POD elem size 0x1c
// Wave:      W35-M OWN-ONLY 2026-07-29
// Exactness: Behavior-preserving reconstruction from decompile + read_memory.
//            Not modernization. Bit-for-bit / runtime: DEFERRED.
// =============================================================================

#include <cstdint>

struct Pod28 {
    // 7× dword/float lanes (0x1c). Copied via rep movsd (ECX=7).
    uint32_t w[7];
};

// ABI (register, no stack, RET 0):
//   EAX = dst_begin (cursor; advanced by 0x1c per element)
//   EDX = dst_end   (exclusive)
//   EBX = value*    (template re-read each slot)
// Decompiler phantom param_1 is unused.
//
// Semantics: for each element in [dst_begin, dst_end), assign *slot = *value.
// Leaf. Used by Pod28 / Elem28 insert-n mid-hole fill paths.

extern "C" void Pod28_FillAssign_Forward(
    Pod28* dst_begin,        /* EAX */
    Pod28* dst_end,          /* EDX */
    const Pod28* value)      /* EBX */
{
    Pod28* cursor = dst_begin;
    while (cursor != dst_end) {
        Pod28* slot = cursor;
        cursor = reinterpret_cast<Pod28*>(
            reinterpret_cast<char*>(cursor) + 0x1c);
        // Retail: ECX=7; ESI=value; EDI=slot; rep movsd
        *slot = *value;
    }
}

// Ghidra twin name
extern "C" void FUN_0045efe0(
    Pod28* dst_begin,
    Pod28* dst_end,
    const Pod28* value)
{
    Pod28_FillAssign_Forward(dst_begin, dst_end, value);
}
