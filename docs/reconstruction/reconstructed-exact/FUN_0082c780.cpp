// =============================================================================
// FUN_0082c780  (scaffold twin of UI_Window_OnCommand_Base_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0082c780
// Address:   0x0082c780  (autoassault.exe, image base 0x400000)
// System:    UI OnCommand base (inventory-transfer partition host)
// Generated: 2026-07-23 scaffold; R11-027 dual seal 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named clean: reconstructed-exact/UI_Window_OnCommand_Base_Inferred.cpp
// =============================================================================

// PURPOSE: Base UI window OnCommand — 70000 dismiss for classes {8,0xb,0xe}
// via FUN_0090d400, else forward child@+0x2b0 vtbl+0x338 if vtbl+0xd8 ok.
// ABI: __thiscall ECX=this; stack (cmdClass, cmdId); RET 8.
// Body: 108 B; DATA vtable @ 0x00a732a4.

// READABILITY:
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_0090d400; indirect vtbl+0xd8 / +0x338.
//  - Return sites: 3 (child result / 0 / 1).

/*
 * Behavioral notes:
 * - Live decompile ≡ 2026-07-23 raw CF (R11-027).
 * - Asm seals EDI=[this+0x2b0] before FUN_0090d400 (decompiler omits).
 * - param_1[0xac] == byte offset +0x2b0 (child pointer).
 * - Runtime / differential verification: OPEN.
 */

#include <cstdint>

extern "C" void FUN_0090d400(void);

uint32_t __thiscall FUN_0082c780(int* param_1, int param_2, int param_3)
{
    char cVar1;
    uint32_t uVar2;

    // param_2 = cmdClass; param_3 = cmdId
    if ((param_3 == 70000) && (((param_2 == 8) || (param_2 == 0xb)) || (param_2 == 0xe))) {
        // EDI = param_1[+0x2b0] for FUN_0090d400 (unaff_EDI); ESI = this
        FUN_0090d400();
        return 1;
    }
    cVar1 = (**(char(**)())(*param_1 + 0xd8))();
    if ((cVar1 != '\0') && (param_1[0xac] != 0)) {
        uVar2 = (**(uint32_t(**)(int, int))(*(int*)param_1[0xac] + 0x338))(param_2, param_3);
        return uVar2;
    }
    return 0;
}
