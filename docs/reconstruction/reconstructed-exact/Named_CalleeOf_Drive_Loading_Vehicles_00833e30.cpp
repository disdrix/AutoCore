// =============================================================================
// Named_CalleeOf_Drive_Loading_Vehicles_00833e30
// -----------------------------------------------------------------------------
// Stable ID: aa_00833e30
// Callee of Drive_Loading_Vehicles (+1 other named callers)
// Address:   0x00833e30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_Loading_Vehicles: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Drive_Loading_Vehicles (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~99 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: CVOGReaction_GiveItemByCbid, FUN_004f8ce0, FUN_004faaf0, FUN_004fab40, FUN_004fd970, FUN_00501970, FUN_007a4480, FUN_00833ca0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Drive_Loading_Vehicles (+1 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_CalleeOf_Drive_Loading_Vehicles_00833e30(int *param_1,int param_2)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  byte bVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  float fStack_48;

  int iStack_44;

  int iStack_40;

  void *pvStack_18;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b02fd;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00833d50();

  param_1[0x143] = param_2;

  pvVar1 = operator_new(0x800);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_00501970();

  }

  local_4 = 0xffffffff;

  param_1[0x142] = iVar2;

  (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 8))();

  iVar2 = param_1[0x143];

  iVar6 = *(int *)(iVar2 + 600);

  if (((iVar6 != 0) &&

      (iVar6 = *(int *)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0xac + iVar6) + 0x34),

      iVar6 != -1)) ||

     (iVar6 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xac + iVar2) + 0x3c) +

                      0x6f4), iVar6 != -1)) {

    iStack_40 = 0x833f14;

    piVar3 = (int *)CVOGReaction_GiveItemByCbid(iVar6);

    if (piVar3 == (int *)0x0) {

      iStack_40 = 1;

      iStack_44 = 0x833f2a;

      FUN_007a4480();

      ExceptionList = pvStack_18;

      return;

    }

    iStack_44 = 0x833f52;

    iStack_40 = iVar6;

    (**(code **)(*piVar3 + 8))();

    if (*(int *)(piVar3[0x2a] + 0x38) == 0x10) {

      iStack_44 = 0x833f6c;

      iVar2 = (*(code *)((uint32_t /* width from decompiler */ *)*piVar3)[0x7c])();

      *(uint8_t *)(iVar2 + 0xcc) = 1;

      fStack_48 = 1.2053231e-38;

      iStack_44 = iVar2;

      Vehicle_SetWheelset();

      iStack_44 = 0x833f95;

      puVar4 = (uint32_t /* width from decompiler */ *)

               (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x1f0))();

      iStack_44 = 0;

      uStack_54 = 0;

      uStack_50 = 0;

      uStack_4c = 0;

      fStack_48 = g_flOne;

      (**(code **)*puVar4)(0);

    }

    else {

      iStack_44 = 1;

      fStack_48 = 1.2053407e-38;

      (**(code **)*piVar3)();

    }

  }

  fStack_48 = 0.0;

  iStack_44 = 0;

  iStack_40 = 0;

  puStack_8 = (uint8_t *)&uStack_54;

  uStack_54 = 0;

  uStack_50 = 0;

  uStack_4c = 0;

  pvVar1 = (void *)g_flOne;

  (*(code *)**(uint32_t /* width from decompiler */ **)(param_1[0x142] + 0x40))();

  bVar5 = 0;

  do {

    FUN_004f8ce0();

    bVar5 = bVar5 + 1;

  } while (bVar5 < 8);

  FUN_004faaf0();

  FUN_004fab40();

  FUN_004fd970();

  (**(code **)(*param_1 + 0x3bc))();

  FUN_00833ca0();

  ExceptionList = pvVar1;

  return;

}
