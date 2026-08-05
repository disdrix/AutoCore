// =============================================================================
// Phy_NDPhysicsDebug
// -----------------------------------------------------------------------------
// Stable ID: aa_00502970
// Address:   0x00502970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Phy_NDPhysicsDebug @ 0x00502970
// Stable ID: aa_00502970
// Embedded strings (evidence for future rename):
//   - "NDPhysicsDebug.fx"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~215 non-empty decompiler lines.
//  - Control keywords: if×13, return×5, do×1, while×1.
//  - Notable callees: FUN_004507a0×2, FUN_00748960×2, FUN_00749d10×2, FUN_007638d0×2, FUN_00764030×2, FUN_007647c0×2, FUN_009701d0×2, FUN_00987a00×2.
//  - Strings: "NDPhysicsDebug.fx".
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "NDPhysicsDebug.fx"
 * Domain alias of FUN_00502970 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Phy_NDPhysicsDebug(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *pvVar3;

  int *piVar4;

  int *piVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint8_t auStack_c0 [4];

  int local_bc;

  uint32_t /* width from decompiler */ local_b8;

  uint32_t /* width from decompiler */ local_b4;

  uint32_t /* width from decompiler */ local_b0;

  int *local_ac;

  int *local_a8;

  float local_a4;

  float local_a0;

  float local_9c;

  undefined **ppuStack_98;

  void *pvStack_90;

  uint32_t /* width from decompiler */ uStack_8c;

  uint32_t /* width from decompiler */ uStack_88;

  void *pvStack_80;

  uint32_t /* width from decompiler */ uStack_7c;

  int iStack_78;

  uint32_t /* width from decompiler */ uStack_74;

  uint32_t /* width from decompiler */ uStack_70;

  int *piStack_6c;

  float fStack_68;

  float fStack_64;

  void *apvStack_54 [3];

  void *pvStack_48;

  void *pvStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  int iStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a2f5f;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_004fecb0();

  pvVar3 = operator_new(0x10);

  if (pvVar3 == (void *)0x0) {

    pvVar3 = (void *)0x0;

  }

  else {

    *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 4) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 0xc) = 0;

  }

  *(void **)(param_1 + 0x3ac) = pvVar3;

  local_bc = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xbc + param_1);

  local_4 = 0xffffffff;

  local_bc = FUN_004f1530(local_bc);

  iVar1 = *(int *)(param_1 + 0x3ac);

  iVar6 = *(int *)(iVar1 + 4);

  if ((iVar6 == 0) ||

     ((uint)(*(int *)(iVar1 + 0xc) - iVar6 >> 2) <= (uint)(*(int *)(iVar1 + 8) - iVar6 >> 2))) {

    FUN_004507a0(*(uint32_t /* width from decompiler */ *)(iVar1 + 8),1,&local_bc);

  }

  else {

    piVar4 = *(int **)(iVar1 + 8);

    *piVar4 = local_bc;

    *(int **)(iVar1 + 8) = piVar4 + 1;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3a8) = 1;

  if ((*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +

                0x5f0) & 0x10) != 0) {

    local_ac = operator_new(0x14c);

    local_4 = 1;

    if (local_ac == (int *)0x0) {

      piVar4 = (int *)0x0;

    }

    else {

      piVar4 = (int *)FUN_00764030();

    }

    local_4 = 0xffffffff;

    local_a8 = piVar4;

    FUN_007638d0(1);

    local_ac = operator_new(0xc4);

    local_4 = 2;

    if (local_ac == (int *)0x0) {

      piVar5 = (int *)0x0;

    }

    else {

      piVar5 = (int *)FUN_00748960();

    }

    local_4 = 0xffffffff;

    iVar6 = (**(code **)(*piVar4 + 0xc))();

    iVar1 = *piVar5;

    piVar5[0x19] = iVar6;

    uVar7 = (**(code **)(*piVar4 + 100))();

    (**(code **)(iVar1 + 0x34))(uVar7);

    FUN_00989e00(auStack_c0,"NDPhysicsDebug.fx");

    FUN_009701d0(auStack_c0);

    FUN_00987a00();

    uStack_30 = 0;

    uStack_2c = 0;

    uStack_28 = 0;

    iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c);

    local_b8 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x728);

    local_b4 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x72c);

    local_bc = *(int *)(iVar1 + 0x724);

    puStack_8 = (uint8_t *)0x3;

    iStack_24 = local_bc;

    uStack_20 = local_b8;

    uStack_1c = local_b4;

    FUN_00987a90();

    FUN_00749d10(apvStack_54);

    FUN_007647c0(piVar5);

    (**(code **)(*piVar4 + 0x50))();

    FUN_004506a0(&local_a8);

    *(int *)(param_1 + 0x3a8) = *(int *)(param_1 + 0x3a8) + 1;

    local_4 = 0xffffffff;

    if (pvStack_38 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(pvStack_38);

    }

    pvStack_38 = (void *)0x0;

    uStack_34 = 0;

    uStack_30 = 0;

    if (pvStack_48 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(pvStack_48);

    }

  }

  local_bc = 0;

  if ('\0' < *(char *)(*(int *)(param_1 + 600) + 0xb0)) {

    local_b8 = 0;

    local_b4 = DAT_009cd0d8;

    local_b0 = 0;

    local_a4 = g_flMultiKillCountBlend;

    local_a0 = g_flOne;

    local_9c = g_flMultiKillCountBlend;

    do {

      local_ac = operator_new(0x14c);

      local_4 = 4;

      if (local_ac == (int *)0x0) {

        piVar4 = (int *)0x0;

      }

      else {

        piVar4 = (int *)FUN_00764030();

      }

      local_4 = 0xffffffff;

      local_ac = piVar4;

      FUN_007638d0(1);

      apvStack_54[0] = operator_new(0xc4);

      local_4 = 5;

      if (apvStack_54[0] == (void *)0x0) {

        piVar5 = (int *)0x0;

      }

      else {

        piVar5 = (int *)FUN_00748960();

      }

      local_4 = 0xffffffff;

      iVar6 = (**(code **)(*piVar4 + 0xc))();

      iVar1 = *piVar5;

      piVar5[0x19] = iVar6;

      uVar7 = (**(code **)(*piVar4 + 100))();

      (**(code **)(iVar1 + 0x34))(uVar7);

      FUN_00989e00(&local_ac,"NDPhysicsDebug.fx");

      FUN_009701d0(&local_ac);

      FUN_00987a00();

      uStack_74 = local_b8;

      iStack_78 = local_bc;

      uStack_70 = local_b4;

      fStack_68 = local_a4;

      puStack_8 = (uint8_t *)0x6;

      piStack_6c = local_a8;

      fStack_64 = local_a0;

      FUN_00987a90();

      FUN_00749d10(&local_9c);

      FUN_007647c0(piVar5);

      (**(code **)(*piVar4 + 0x50))();

      iVar1 = *(int *)(param_1 + 0x3ac);

      iVar6 = *(int *)(iVar1 + 4);

      if ((iVar6 == 0) ||

         ((uint)(*(int *)(iVar1 + 0xc) - iVar6 >> 2) <= (uint)(*(int *)(iVar1 + 8) - iVar6 >> 2))) {

        FUN_004507a0(*(uint32_t /* width from decompiler */ *)(iVar1 + 8),1,&local_ac);

      }

      else {

        puVar2 = *(uint32_t /* width from decompiler */ **)(iVar1 + 8);

        *puVar2 = piVar4;

        *(uint32_t /* width from decompiler */ **)(iVar1 + 8) = puVar2 + 1;

      }

      local_4 = 0xffffffff;

      if (pvStack_80 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvStack_80);

      }

      pvStack_80 = (void *)0x0;

      uStack_7c = 0;

      iStack_78 = 0;

      if (pvStack_90 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvStack_90);

      }

      local_bc = local_bc + 1;

      pvStack_90 = (void *)0x0;

      uStack_8c = 0;

      uStack_88 = 0;

      ppuStack_98 = &PTR_LAB_009cd118;

    } while (local_bc < *(char *)(*(int *)(param_1 + 600) + 0xb0));

  }

  ExceptionList = pvStack_c;

  return;

}
