// =============================================================================
// StdList_AllocSentinel_0xC_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004933f0
// Address:   0x004933f0–0x00493409 inclusive (26 B / 0x1A)
// Module:    autoassault.exe (image base 0x400000)
// System:    shared std::list-style sentinel factory
// Wave:      W32-P 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + body hex.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Allocate a 0xC-byte circular empty-list sentinel:
//     node->next = node; node->prev = node;
//   Returns node* in EAX. Decompiler wrongly shows void.
//   Non-SEH twin of StdList_AllocEmptySentinel_Inferred (0x0040fb90).
//   Sibling of StdList_AllocSentinel_0x18_Inferred (0x00457c60).
//
// CALLERS: 20+ (PalantirEnv_Ctor, NDSpecialFX_Ctor x6, map/UI ctors, ...).
//   Typical pair: head = Alloc(); size = 0;
//
// =============================================================================

#include <cstdint>

// MSVC CRT
void* __cdecl operator_new(unsigned int size);

// Ghidra: FUN_004933f0 / void FUN_004933f0(void)  — return type WRONG
extern "C" void* StdList_AllocSentinel_0xC_Inferred(void)
{
    void* node = operator_new(0x0C);
    if (node != nullptr) {
        *reinterpret_cast<void**>(node) = node; // +0 next = self
    }
    // Matches retail: test (node+4); store prev even when node null would
    // target 0x4 — relies on non-null operator_new.
    if (reinterpret_cast<std::uint32_t*>(static_cast<char*>(node) + 4) != nullptr) {
        *reinterpret_cast<void**>(static_cast<char*>(node) + 4) = node; // +4 prev = self
    }
    return node; // EAX
}

// Ghidra twin name
extern "C" void* FUN_004933f0(void)
{
    return StdList_AllocSentinel_0xC_Inferred();
}
