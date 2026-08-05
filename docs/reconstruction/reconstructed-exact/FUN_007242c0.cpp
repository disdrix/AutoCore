// =============================================================================
// FUN_007242c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007242c0
// Address:   0x007242c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007242c0 @ 0x007242c0
// Stable ID: aa_007242c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×2, while×2.
//  - Notable callees: FUN_0071f810, FUN_00723b20, FUN_00723dc0, FUN_007242c0.
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

void __thiscall FUN_007242c0(int param_1,char param_2)



{

  int iVar1;

  int *piVar2;

  

  if (param_2 != '\0') {

    *(char *)(param_1 + 600) = param_2;

    return;

  }

  FUN_00723dc0(param_1);

  piVar2 = *(int **)(param_1 + 0x29c);

  if (piVar2 != *(int **)(param_1 + 0x2a0)) {

    do {

      iVar1 = *piVar2;

      FUN_00723b20(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x128),*(uint32_t /* width from decompiler */ *)(iVar1 + 300),

                   *(uint32_t /* width from decompiler */ *)(iVar1 + 0x130),iVar1 + 0x20,0);

      piVar2 = piVar2 + 1;

    } while (piVar2 != *(int **)(param_1 + 0x2a0));

  }

  piVar2 = (int *)(param_1 + 0x2a8);

  iVar1 = 5;

  do {

    if (*piVar2 != 0) {

      FUN_0071f810();

    }

    piVar2 = piVar2 + 1;

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  *(uint8_t *)(param_1 + 600) = 0;

  return;

}
