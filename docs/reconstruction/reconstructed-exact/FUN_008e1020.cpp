// =============================================================================
// FUN_008e1020  (twin of UI_DtHost_CreateChildWidgets_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_008e1020
// Address:   0x008e1020  (autoassault.exe, image base 0x400000)
// Body:      0x008e1020-0x008e17be inclusive (1951 B / 0x79F)
// System:    inventory-transfer
// Generated: 2026-08-05 R13-014 dual seal (ASM-STRUCTURAL)
// Exactness: Control-flow recovered from disassembly; not bit-identical C.
// Bit-for-bit vs retail EXE: DEFERRED (decompiler FAILED).
// Dispatch:  vtable DATA 0x00a3c3a0 -> this VA
// Canonical: UI_DtHost_CreateChildWidgets_Inferred
// =============================================================================

// See UI_DtHost_CreateChildWidgets_Inferred.cpp for full plate + algorithm.

void __thiscall FUN_008e1020(void* host)
{
    // ECX = host; RET 0; virtual CreateChildWidgets for i_d_dt_2d_* host.
    // Assembly authority: docs/reconstruction/raw/aa_008e1020_FUN_008e1020.md (R13-014 append).
    UI_DtHost_CreateChildWidgets_Inferred(host);
}

// Forward-declare for twin compilation notes only (not a build unit):
void __thiscall UI_DtHost_CreateChildWidgets_Inferred(void* host);
