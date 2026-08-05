// =============================================================================
// FUN_005557a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005557a0
// Address:   0x005557a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005557a0 @ 0x005557a0
// Stable ID: aa_005557a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×10, return×1.
//  - Notable callees: FUN_004b8dc0×3, FUN_00553d20×3, FUN_004b73c0, FUN_00553fc0, FUN_005554d0, FUN_005557a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall FUN_005557a0(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  

  iVar2 = *(int *)(param_1 + 0x150);

  if (iVar2 != param_2) {

    *(uint *)(param_1 + 0x158) = g_dwClientTickMs;

    if (*(int *)(param_1 + 0x17c) != 0) {

      if ((-1 < iVar2) && (iVar2 < 4)) {

        iVar2 = FUN_00553d20(0);

        if (iVar2 != 0) {

          FUN_004b8dc0(0,0);

        }

      }

      if ((-1 < *(int *)(param_1 + 0x154)) && (*(int *)(param_1 + 0x154) < 4)) {

        iVar2 = FUN_00553d20(0);

        if (iVar2 != 0) {

          FUN_004b8dc0(0,0);

        }

      }

      if ((-1 < param_2) && (param_2 < 4)) {

        iVar2 = FUN_00553d20(0);

        if (iVar2 != 0) {

          iVar2 = FUN_00553fc0(param_2);

          if ((iVar2 != 0) && (iVar1 = *(int *)(param_1 + 0x188), iVar1 != 0)) {

            FUN_004b73c0(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1);

            FUN_004b8dc0(1,0);

            *(float *)(iVar2 + 0x38) = g_flOne;

            *(uint32_t /* width from decompiler */ *)(iVar2 + 0x2c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x40);

          }

        }

      }

    }

    if (*(int *)(param_1 + 0x180) != 0) {

      FUN_005554d0();

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x180) = 0;

    *(int *)(param_1 + 0x154) = param_2;

    *(int *)(param_1 + 0x150) = param_2;

  }

  return;

}
