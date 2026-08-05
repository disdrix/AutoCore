// =============================================================================
// FUN_009847c0  →  AssPackManager_PrepReplaceExistingEntry_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_009847c0
// Address:   0x009847c0–0x0098488c exclusive (204 B)
// Wave:      W37-Y OWN-ONLY 2026-08-04
// Twin of:   reconstructed-exact/AssPackManager_PrepReplaceExistingEntry_Inferred.cpp
// =============================================================================

#include <cstdint>

// ABI: ECX=pathBuf*, EDX=host*, stack nameOrCookie*; RET 4; returns 0 / 0xFFFFFFFF.

extern "C" int AssPackManager_PrepReplaceExistingEntry_Inferred(
    char* pathBuf,
    void* host,
    const char* nameOrCookie);

extern "C" int FUN_009847c0(const char* nameOrCookie) {
    // Decompiler __fastcall (path/name, host) omits stack formal — use named twin.
    // This thunk exists for Ghidra-name linkage only.
    (void)nameOrCookie;
    return AssPackManager_PrepReplaceExistingEntry_Inferred(nullptr, nullptr, nameOrCookie);
}
