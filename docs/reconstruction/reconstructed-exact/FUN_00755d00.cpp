// =============================================================================
// FUN_00755d00
// -----------------------------------------------------------------------------
// Stable ID: aa_00755d00
// Address:   0x00755d00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00755d00 @ 0x00755d00
// Stable ID: aa_00755d00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_00755d00.
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

void FUN_00755d00(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  

  iVar2 = 0;

  if (*(int *)(param_1 + 0x50) != 0) {

    iVar2 = (*(int *)(param_1 + 0x54) - *(int *)(param_1 + 0x50)) / 0x14;

  }

  if (iVar2 == 0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = param_2;

    return;

  }

  iVar4 = 0;

  do {

    piVar1 = *(int **)(*(int *)(param_1 + 0x50) + 4 + iVar4);

    puVar3 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x50) + iVar4);

    if (*(char *)(puVar3 + 3) == '\0') {

      (**(code **)(*piVar1 + 8))(param_2);

    }

    else {

      (**(code **)(*piVar1 + 8))();

    }

    (**(code **)(*(int *)*puVar3 + 0x30))(3);

    iVar4 = iVar4 + 0x14;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = param_2;

  return;

}
