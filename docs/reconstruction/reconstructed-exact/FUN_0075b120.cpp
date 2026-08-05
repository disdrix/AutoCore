// =============================================================================
// FUN_0075b120
// -----------------------------------------------------------------------------
// Stable ID: aa_0075b120
// Address:   0x0075b120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075b120 @ 0x0075b120
// Stable ID: aa_0075b120
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×5, for×2, return×1.
//  - Notable callees: FUN_0043ffb0×2, FUN_0075b120, FUN_007633d0, FUN_007647c0.
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

void FUN_0075b120(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  char in_AL;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  puVar4 = *(uint32_t /* width from decompiler */ **)(param_2 + 0xc0);

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_2 + 0xc4);

  if (param_2 == *(int *)(param_1 + 4)) {

    in_AL = '\0';

  }

  for (; puVar4 != puVar1; puVar4 = puVar4 + 1) {

    piVar3 = (int *)*puVar4;

    if (in_AL != '\0') {

      piVar3 = (int *)(**(code **)(*piVar3 + 0x7c))();

    }

    FUN_0043ffb0(0,0,0,0);

    iVar2 = *(int *)(param_1 + 0x10);

    *(uint32_t /* width from decompiler */ *)(iVar2 + -8) = param_3;

    *(int **)(iVar2 + -0x10) = piVar3;

    *(uint8_t *)(iVar2 + -0xc) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar2 + -4) = param_4;

    if (in_AL != '\0') {

      FUN_007647c0(piVar3);

    }

  }

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_2 + 0xd4);

  for (puVar4 = *(uint32_t /* width from decompiler */ **)(param_2 + 0xd0); puVar4 != puVar1; puVar4 = puVar4 + 1) {

    piVar3 = (int *)*puVar4;

    if (in_AL != '\0') {

      piVar3 = (int *)(**(code **)(*piVar3 + 0x7c))();

    }

    FUN_0043ffb0(0,0,0,0);

    iVar2 = *(int *)(param_1 + 0x20);

    *(uint32_t /* width from decompiler */ *)(iVar2 + -8) = param_3;

    *(int **)(iVar2 + -0x10) = piVar3;

    *(uint8_t *)(iVar2 + -0xc) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar2 + -4) = param_4;

    if (in_AL != '\0') {

      FUN_007633d0(*(uint32_t /* width from decompiler */ *)(param_1 + 4),piVar3);

    }

  }

  return;

}
