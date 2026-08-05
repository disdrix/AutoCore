// =============================================================================
// FUN_0073b7f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073b7f0
// Address:   0x0073b7f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073b7f0 @ 0x0073b7f0
// Stable ID: aa_0073b7f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: FUN_0074e9d0×2, FUN_00464640, FUN_00469ea0, FUN_0073b7f0, FUN_0074e910, FUN_0074ed90, FUN_0074ee40.
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

uint32_t /* width from decompiler */ __thiscall FUN_0073b7f0(int *param_1,uint32_t /* width from decompiler */ param_2,float param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  float fVar4;

  void *pvVar5;

  int iVar6;

  int iVar7;

  uint *puVar8;

  uint32_t /* width from decompiler */ uVar9;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1190;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  pvVar5 = operator_new(0x78);

  local_4 = 0;

  if (pvVar5 == (void *)0x0) {

    iVar6 = 0;

  }

  else {

    iVar6 = FUN_0074ed90();

  }

  local_4 = 0xffffffff;

  FUN_0074ee40(param_2);

  FUN_0074e9d0(0);

  FUN_0074e910(0,param_1[2]);

  puVar1 = (uint32_t /* width from decompiler */ *)param_1[4];

  for (puVar2 = (uint32_t /* width from decompiler */ *)*puVar1; puVar2 != puVar1; puVar2 = (uint32_t /* width from decompiler */ *)*puVar2) {

    if (((puVar2[2] & 2) == 0) || (0.0 <= (float)puVar2[4])) {

      puVar2[3] = 0;

      puVar2[4] = 0.0 - *(float *)(puVar2[5] + 0x10) / param_3;

      puVar2[2] = puVar2[2] | 3;

    }

  }

  local_4 = 1;

  iVar3 = param_1[4];

  iVar7 = FUN_00464640(iVar3,*(uint32_t /* width from decompiler */ *)(iVar3 + 4));

  FUN_00469ea0();

  *(int *)(iVar3 + 4) = iVar7;

  fVar4 = g_flOne;

  local_4 = 0xffffffff;

  uVar9 = 0;

  **(int **)(iVar7 + 4) = iVar7;

  iVar3 = *(int *)(param_1[4] + 4);

  puVar8 = (uint *)(iVar3 + 8);

  *(int *)(iVar3 + 0x14) = iVar6;

  *(float *)(iVar3 + 0xc) = fVar4;

  *puVar8 = 0;

  if (0.0 < param_3) {

    *puVar8 = 3;

    *(float *)(iVar3 + 0x10) = (fVar4 - *(float *)(iVar6 + 0x10)) / param_3;

  }

  else {

    FUN_0074e9d0(0x3f800000);

    *puVar8 = *puVar8 | 1;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x10) = uVar9;

  }

  (**(code **)(*param_1 + 0x20))(iVar6,puVar8);

  ExceptionList = (void *)0x0;

  return 1;

}
