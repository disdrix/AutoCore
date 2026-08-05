// =============================================================================
// FUN_008c52a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008c52a0
// Address:   0x008c52a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c52a0 @ 0x008c52a0
// Stable ID: aa_008c52a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_008c52a0.
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

void __fastcall FUN_008c52a0(int param_1)



{

  char cVar1;

  

  if ((((*(int **)(param_1 + 0x5b8) != (int *)0x0) && (DAT_00d1b6d8 != 0)) &&

      (*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac + DAT_00d1b6d8) +

                         0x3c) + 0x532) == '\0')) &&

     ((*(int *)(DAT_00d1b6d8 + 0x250) != 0 && (0 < *(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x144))

      ))) {

    cVar1 = (**(code **)(**(int **)(param_1 + 0x5b8) + 0xf8))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(param_1 + 0x5b8) + 0x100))();

    }

    (**(code **)(**(int **)(param_1 + 0x5b8) + 0xcc))(1);

    (**(code **)(**(int **)(param_1 + 0x5b8) + 0xfc))(0,0x3f0a3d71);

    (**(code **)(**(int **)(param_1 + 0x5b8) + 0x34c))();

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5cc) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5dc) = 0xffffffff;

  }

  return;

}
