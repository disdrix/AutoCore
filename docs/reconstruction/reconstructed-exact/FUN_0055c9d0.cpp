// =============================================================================
// FUN_0055c9d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0055c9d0
// Address:   0x0055c9d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055c9d0 @ 0x0055c9d0
// Stable ID: aa_0055c9d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_004148e0, FUN_00416160, FUN_0055c9d0.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ __thiscall FUN_0055c9d0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  

  if (*(int *)(param_1 + 0x94) == 0) {

    return 0xffffffff;

  }

  if (*(char *)(param_1 + 0x80) != '\0') {

    *(uint8_t *)(DAT_00d1f048 + 0xf) = 0;

    *(uint8_t *)(DAT_00d1f048 + 0x2d) = 0;

    FUN_00416160(*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(*(int *)(param_1 + 0x94) + 0xe894) + 0xc0) + 8));

    if ((((*(char *)(*(int *)(param_1 + 0x9c) + 0x88) != '\0') && (*(int *)(param_1 + 0x94) != 0))

        && (iVar1 = *(int *)(*(int *)(param_1 + 0x94) + 0xe89c), iVar1 != 0)) &&

       ((*(int *)(iVar1 + 0x1d4) != 0 && (*(int *)(iVar1 + 0x1d8) != 0)))) {

      FUN_004148e0(param_1 + 0x84);

      (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 0x94) + 0xe89c) + 0x1d4) + 0x3c))(param_2)

      ;

    }

  }

  return 0;

}
