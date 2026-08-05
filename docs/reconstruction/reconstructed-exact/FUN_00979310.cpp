// =============================================================================
// FUN_00979310
// -----------------------------------------------------------------------------
// Stable ID: aa_00979310
// Address:   0x00979310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00979310 @ 0x00979310
// Stable ID: aa_00979310
// Embedded strings (evidence for future rename):
//   - "allocatenewobjectfromcbid failed %d Get a programmer"
//   - "obj_f_inc_mov_01_airlift_at.anm"
//   - "obj_f_inc_mov_01_airlift_aut.anm"
//   - "obj_f_inc_mov_01_airlift_at2.anm"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~107 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: FUN_005828b0×3, CONCAT31, CVOGReaction_GiveItemByCbid, CVOGReaction_RandomUnitScalar, FUN_00417e40, FUN_004bb010, FUN_004bc180, FUN_004e88e0.
//  - Strings: "allocatenewobjectfromcbid failed %d Get a programmer"; "obj_f_inc_mov_01_airlift_at.anm"; "obj_f_inc_mov_01_airlift_aut.anm"; "obj_f_inc_mov_01_airlift_at2.anm".
//  - Return sites: 4.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00979310(void)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint extraout_EDX;

  int unaff_EDI;

  float10 fVar5;

  float10 fVar6;

  uint64_t uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  float fStack_48;

  float fStack_44;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_34;

  float fStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  

  iVar1 = FUN_004bb010(unaff_EDI + 0x28);

  if ((iVar1 == 0) || (*(int *)(iVar1 + 8) == 0)) {

    *(uint8_t *)(unaff_EDI + 8) = 1;

    return;

  }

  *(uint8_t *)(unaff_EDI + 8) = 0;

  piVar2 = (int *)CVOGReaction_GiveItemByCbid(0xadc);

  if (piVar2 == (int *)0x0) {

    FUN_007a4480(1,"allocatenewobjectfromcbid failed %d Get a programmer",0xadc);

    return;

  }

  (**(code **)(*piVar2 + 8))

            (0xadc,*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xa8 + iVar1),1);

  uVar8 = 0;

  uVar7 = FUN_0092c760(0);

  FUN_00512160(uVar7,uVar8);

  FUN_004bc180(piVar2);

  uVar8 = (**(code **)(*piVar2 + 0x1cc))();

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x10) = uVar8;

  iVar3 = CVOGReaction_RandomUnitScalar();

  if (0xfffff < *(int *)(iVar3 + 0xc)) {

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

  }

  fStack_44 = g_flOne;

  *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;

  fStack_48 = 0.0;

  fStack_40 = 0.0;

  FUN_0076f5f0(&fStack_38,&fStack_48);

  fVar5 = (float10)(extraout_EDX & 0xffff) * (float10)_DAT_00aaaa84;

  fVar6 = (float10)fsin(fVar5);

  fStack_48 = (float)((float10)fStack_38 * fVar6);

  fStack_44 = (float)((float10)fStack_34 * fVar6);

  fStack_40 = (float)((float10)fStack_30 * fVar6);

  fVar5 = (float10)fcos(fVar5);

  fStack_3c = (float)fVar5;

  if (*(int *)(iVar1 + 8) == 0) {

    puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x84 + iVar1);

  }

  else {

    puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar1 + 8) + 0x3c) + 0xb0);

  }

  uStack_2c = *puVar4;

  uStack_28 = puVar4[1];

  uStack_24 = puVar4[2];

  uStack_20 = puVar4[3];

  FUN_004e88e0(&uStack_54,&uStack_2c);

  (**(code **)**(uint32_t /* width from decompiler */ **)(unaff_EDI + 0x10))

            (1,uStack_54,uStack_50,uStack_4c,fStack_48,fStack_44,fStack_40,fStack_3c,0);

  (**(code **)(**(int **)(unaff_EDI + 0x10) + 0x20))();

  (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_EDI + 0x10) + 4) + 4) + 4 +

                       *(int *)(unaff_EDI + 0x10)) + 0x100))();

  FUN_005828b0(1,"obj_f_inc_mov_01_airlift_at.anm",0);

  FUN_005828b0(2,"obj_f_inc_mov_01_airlift_aut.anm",0);

  FUN_005828b0(3,"obj_f_inc_mov_01_airlift_at2.anm",0);

  FUN_005816a0(1,0);

  iVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x210))(0);

  if (iVar3 == DAT_00d1b6d8) {

    FUN_007fc840();

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xc) = *(uint32_t /* width from decompiler */ *)(DAT_00d1b778 + 0x60c);

    *(uint32_t /* width from decompiler */ *)(DAT_00d1b778 + 0x60c) = 4;

    FUN_0090dd50();

    FUN_00417e40(DAT_00d1b778);

  }

  (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x1bc))(1);

  iVar3 = *(int *)(iVar1 + 8);

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x68) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x28);

  *(uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 8) + 0x28) = 0x10;

  FUN_00560e90(*(uint32_t /* width from decompiler */ *)(iVar1 + 8),CONCAT31((int3)((uint)iVar3 >> 8),1));

  FUN_0053d970(1);

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x18) = 0;

  if (*(int **)(iVar1 + 0x48) != (int *)0x0) {

    iVar1 = (**(code **)(**(int **)(iVar1 + 0x48) + 0x48))();

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x1c) = *(uint32_t /* width from decompiler */ *)(iVar1 + 4);

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x20) = 0;

    return;

  }

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x1c) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x20) = 0;

  return;

}
