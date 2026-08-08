// =============================================================================
// FUN_00822cb0  (scaffold twin of UI_TabChrome_SetSelected_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00822cb0
// Address:   0x00822cb0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer (UI tab chrome helper — no inventory wire)
// Generated: 2026-07-23 scaffold; R12-002 dual seal 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Canonical: UI_TabChrome_SetSelected_Inferred
// Named clean: reconstructed-exact/UI_TabChrome_SetSelected_Inferred.cpp
// Dual reviews:
//   reviews/A_aa_00822cb0_UI_TabChrome_SetSelected_Inferred.md
//   reviews/B_aa_00822cb0_UI_TabChrome_SetSelected_Inferred.md
// =============================================================================

// PURPOSE: Set selected chrome on a tab control (ESI=widget, BL=selected,
// force@stack, RET 4). Restyle childA@+0x818, show/hide childB@+0x814, resize
// by deltas +0x80C/+0x810 when state changes, store selected at +0x4FC.
//
// READABILITY: control flow preserved from Ghidra decompile + sealed disasm.
// Vcall bodies left as indirect; product English for ordinals is OPEN.

#include <cstdint>

// Decompiler-shaped entry: force on stack; ESI/BL are register formals.
extern "C" void FUN_00822cb0(char force /*stack*/)
{
    // Register formals (not portable C — documented for fidelity):
    //   int*  unaff_ESI  = widget*
    //   char  unaff_BL   = selected

    char selected;      // BL
    int* widget;        // ESI  (as int* for dword index math matching decomp)

    // Live early-out (disasm):
    //   if force==0 && *(char*)(ESI+0x4FC) == BL → RET 4
    if (force == '\0' && (char)widget[0x13f] == selected) {
        return;
    }

    int* childA = (int*)widget[0x206]; // +0x818

    if (selected == '\0') {
        // unselect arm
        if (childA != nullptr) {
            // vcall +0xF0 / +0xE8 or +0x164/+0x15C with (+0x4FD)>>1; +0x34C
        }
        if ((int*)widget[0x205] != nullptr) {
            // childB vtbl +0x3C8(1, 0)
        }
        if ((char)widget[0x13f] == '\0') {
            goto store;
        }
        // GetSize +0x120; h += [+0x810]; w += [+0x80C]; SetSize +0x110
    } else {
        // select arm
        if (childA != nullptr) {
            // same style path with full +0x4FD
        }
        if ((int*)widget[0x205] != nullptr) {
            // childB vtbl +0x3C8(1, 1)
        }
        if ((char)widget[0x13f] == selected) {
            goto store;
        }
        // GetSize; h -= [+0x810]; w -= [+0x80C]; SetSize
    }

store:
    *(char*)(widget + 0x13f) = selected; // +0x4FC
}
