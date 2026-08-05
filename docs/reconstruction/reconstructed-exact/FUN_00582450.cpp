// =============================================================================
// FUN_00582450
// -----------------------------------------------------------------------------
// Stable ID: aa_00582450
// Address:   0x00582450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00582450 @ 0x00582450
// Stable ID: aa_00582450
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_005134e0, FUN_00582450.
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

void __thiscall FUN_00582450(int param_1,byte param_2)



{

  uint *puVar1;

  int *piVar2;

  bool bVar3;

  char cVar4;

  int iVar5;

  int iVar6;

  

  piVar2 = *(int **)(*(int *)(*(int *)(param_1 + -0x8c) + 4) + 0x20 + param_1);

  if (piVar2 != (int *)0x0) {

    iVar5 = (**(code **)(*piVar2 + 0x19c))();

    iVar6 = *(int *)(*(int *)(iVar5 + 4) + 4);

    puVar1 = (uint *)(iVar6 + iVar5 + 0x188);

    *puVar1 = *puVar1 ^ ((uint)param_2 * 8 ^ *(uint *)(iVar6 + 0x188 + iVar5)) & 8;

  }

  iVar6 = *(int *)(*(int *)(param_1 + -0x8c) + 4);

  puVar1 = (uint *)(iVar6 + param_1 + 0xf8);

  *puVar1 = *puVar1 ^ ((uint)param_2 * 8 ^ *(uint *)(iVar6 + 0xf8 + param_1)) & 8;

  if (*(int *)(param_1 + -0x88) != 0) {

    if (((*(uint *)(*(int *)(*(int *)(param_1 + -0x8c) + 4) + 0xf0 + param_1) >> 3 & 1) == 0) &&

       (cVar4 = FUN_005134e0(), cVar4 == '\0')) {

      bVar3 = true;

    }

    else {

      bVar3 = false;

    }

    iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x8c) + 4) + -0x8c + param_1) + 0x1d4

                        ))();

    if ((iVar6 != 0) &&

       (iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x8c) + 4) + -0x8c + param_1) +

                            0x1d4))(), *(char *)(iVar6 + 0x103) != '\0')) {

      bVar3 = true;

    }

    (**(code **)(*(int *)(param_1 + -0x90) + 0x1c))(0);

    if (bVar3) {

      (**(code **)(*(int *)(param_1 + -0x90) + 0x1c))(1);

    }

    return;

  }

  return;

}
