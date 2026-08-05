// =============================================================================
// FUN_005c0100
// -----------------------------------------------------------------------------
// Stable ID: aa_005c0100
// Address:   0x005c0100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c0100 @ 0x005c0100
// Stable ID: aa_005c0100
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_005c0100, FUN_007464e0, FUN_0096fdf0.
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

int __thiscall FUN_005c0100(int *param_1,int *param_2)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  int *piVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uVar7;

  

  param_1[0x2f] = param_1[0x2f] | 1;

  if (*(int *)(param_1[5] + 0x10) != 0) {

    FUN_007464e0();

  }

  param_1[0x2a] = param_1[0x35] / 3;

  param_1[0x2b] = 4;

  (**(code **)(*param_1 + 0x20))(*(uint32_t /* width from decompiler */ *)(*param_2 + 0x390));

  iVar6 = (**(code **)(**(int **)(*param_2 + 0x390) + 0xc))();

  iVar2 = *param_1;

  param_1[0x19] = iVar6;

  uVar7 = (**(code **)(**(int **)(*param_2 + 0x390) + 100))();

  (**(code **)(iVar2 + 0x34))(uVar7);

  piVar3 = (int *)param_2[0x13];

  piVar4 = (int *)*piVar3;

  if ((piVar4 != (int *)0x0) && (piVar4[1] = piVar4[1] + 1, piVar4[1] == 1)) {

    (**(code **)(*piVar4 + 4))();

  }

  piVar5 = (int *)param_1[8];

  if (piVar5 != (int *)0x0) {

    piVar1 = piVar5 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar5 + 8))();

    }

  }

  param_1[8] = (int)piVar4;

  *(char *)(param_1 + 9) = (char)piVar3[1];

  *(uint8_t *)((int)param_1 + 0x25) = *(uint8_t *)((int)piVar3 + 5);

  *(uint8_t *)((int)param_1 + 0x26) = *(uint8_t *)((int)piVar3 + 6);

  FUN_0096fdf0();

  return param_1[0x35];

}
