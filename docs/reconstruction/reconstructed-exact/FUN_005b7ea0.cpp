// =============================================================================
// FUN_005b7ea0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b7ea0
// Address:   0x005b7ea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b7ea0 @ 0x005b7ea0
// Stable ID: aa_005b7ea0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, for×1.
//  - Notable callees: FUN_005b7b30×2, FUN_006759b0×2, FUN_004933f0, FUN_005b7bd0, FUN_005b7ea0.
//  - Return sites: 3.

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

void __thiscall FUN_005b7ea0(int param_1,uint32_t /* width from decompiler */ param_2,int *param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar1 = (int)param_3;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6aed;

  local_c = ExceptionList;

  for (piVar5 = *(int **)(param_1 + 0x14); piVar5 != *(int **)(param_1 + 0x18); piVar5 = piVar5 + 1)

  {

    if ((int *)*(int *)*piVar5 == param_3) {

      iVar1 = *(int *)(*piVar5 + 8);

      ExceptionList = &local_c;

      iVar4 = FUN_006759b0(iVar1,*(uint32_t /* width from decompiler */ *)(iVar1 + 4),param_2);

      FUN_005b7b30(1);

      *(int *)(iVar1 + 4) = iVar4;

      **(int **)(iVar4 + 4) = iVar4;

      ExceptionList = local_c;

      return;

    }

  }

  ExceptionList = &local_c;

  piVar3 = operator_new(0x10);

  local_4 = 0;

  piVar5 = (int *)0x0;

  if (piVar3 != (int *)0x0) {

    param_3 = piVar3;

    iVar4 = FUN_004933f0();

    piVar3[3] = 0;

    piVar3[2] = iVar4;

    piVar5 = piVar3;

  }

  *piVar5 = iVar1;

  iVar1 = piVar5[2];

  local_4 = 0xffffffff;

  param_3 = piVar5;

  iVar4 = FUN_006759b0(iVar1,*(uint32_t /* width from decompiler */ *)(iVar1 + 4),param_2);

  FUN_005b7b30(1);

  *(int *)(iVar1 + 4) = iVar4;

  **(int **)(iVar4 + 4) = iVar4;

  iVar1 = *(int *)(param_1 + 0x14);

  if ((iVar1 != 0) &&

     ((uint)(*(int *)(param_1 + 0x18) - iVar1 >> 2) < (uint)(*(int *)(param_1 + 0x1c) - iVar1 >> 2))

     ) {

    puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x18);

    *puVar2 = piVar5;

    *(uint32_t /* width from decompiler */ **)(param_1 + 0x18) = puVar2 + 1;

    ExceptionList = local_c;

    return;

  }

  FUN_005b7bd0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),1,&param_3);

  ExceptionList = local_c;

  return;

}
