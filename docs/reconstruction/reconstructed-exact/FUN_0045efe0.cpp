// =============================================================================
// FUN_0045efe0  (== Pod28_FillAssign_Forward)
// -----------------------------------------------------------------------------
// Stable ID: aa_0045efe0
// Address:   0x0045efe0–0x0045effb exclusive (27 B)  autoassault.exe @ 0x400000
// Wave:      W35-M OWN-ONLY 2026-07-29
// Exactness: Twin of Pod28_FillAssign_Forward.cpp (Ghidra symbol).
// =============================================================================

#include <cstdint>

struct Pod28 {
    uint32_t w[7];
};

// EAX=dst_begin, EDX=dst_end, EBX=value*; RET 0; leaf
extern "C" void FUN_0045efe0(
    Pod28* dst_begin,        /* EAX */
    Pod28* dst_end,          /* EDX */
    const Pod28* value)      /* EBX */
{
    Pod28* cursor = dst_begin;
    while (cursor != dst_end) {
        Pod28* slot = cursor;
        cursor = reinterpret_cast<Pod28*>(
            reinterpret_cast<char*>(cursor) + 0x1c);
        *slot = *value;  // 7 dwords (rep movsd)
    }
}
