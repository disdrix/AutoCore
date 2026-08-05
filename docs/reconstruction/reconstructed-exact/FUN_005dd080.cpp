// =============================================================================
// FUN_005dd080
// -----------------------------------------------------------------------------
// Stable ID: aa_005dd080
// Address:   0x005dd080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005dd080 @ 0x005dd080
// Stable ID: aa_005dd080
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~118 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_0055ff20×2, FUN_006343a0×2, FUN_00642b50×2, CONCAT31, FUN_00581220, FUN_0058e0b0, FUN_005dd080, FUN_005eb8d0.
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

void __fastcall FUN_005dd080(int param_1)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint8_t auStack_c8 [8];

  int local_c0;

  uint32_t /* width from decompiler */ uStack_bc;

  int iStack_b4;

  float local_a0;

  float local_9c;

  float local_98;

  uint32_t /* width from decompiler */ local_94;

  float local_90;

  float local_8c;

  float local_88;

  uint32_t /* width from decompiler */ *local_84;

  uint32_t /* width from decompiler */ uStack_7c;

  int iStack_74;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  void *pvStack_24;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a7372;

  pvStack_1c = ExceptionList;

  if (*(char *)(param_1 + 0xdd) == '\0') {

    ExceptionList = &pvStack_1c;

    FUN_0058e0b0();

    local_c0 = (int)(char)(&DAT_00af43b8)[*(char *)(param_1 + 0xdc)];

    iVar2 = *(int *)(*(int *)(param_1 + 4) + 4);

    local_98 = *(float *)(iVar2 + 0xbc + param_1);

    local_84 = *(uint32_t /* width from decompiler */ **)(iVar2 + param_1 + 0x90);

    local_8c = *(float *)(iVar2 + 0x88 + param_1) + local_98;

    local_88 = *(float *)(iVar2 + 0x8c + param_1) + local_98;

    local_90 = local_98 + *(float *)(iVar2 + 0x84 + param_1);

    iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);

    iVar2 = iVar1 + 0x84 + param_1;

    local_94 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc);

    local_a0 = *(float *)(iVar1 + 0x84 + param_1) - local_98;

    local_9c = *(float *)(iVar2 + 4) - local_98;

    local_98 = *(float *)(iVar2 + 8) - local_98;

    local_14 = 0;

    iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(0x90,0x2c);

    *(uint16_t *)(iVar2 + 4) = 0x90;

    pvStack_1c._0_1_ = 1;

    uVar3 = FUN_00581220(auStack_c8);

    pvStack_1c._0_1_ = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xd0) = uVar3;

    pvVar4 = operator_new(8);

    pvStack_1c._0_1_ = 2;

    if (pvVar4 == (void *)0x0) {

      uVar3 = 0;

    }

    else {

      uVar3 = FUN_00642b50(param_1);

    }

    pvStack_1c = (void *)((uint)pvStack_1c._1_3_ << 8);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xd4) = uVar3;

    FUN_006343a0(uVar3);

    FUN_0055ff20(*(uint32_t /* width from decompiler */ *)(param_1 + 0xd0));

    uStack_7c = uStack_bc;

    iStack_74 = iStack_b4;

  }

  else {

    ExceptionList = &pvStack_1c;

    iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(0x10,0x22);

    *(uint16_t *)(iVar2 + 4) = 0x10;

    pvStack_1c = (void *)0x3;

    puVar5 = (uint32_t /* width from decompiler */ *)

             FUN_006c7fa0(*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xbc + param_1));

    pvStack_1c = (void *)0xffffffff;

    FUN_005eb8d0();

    local_88 = (float)(int)(char)(&DAT_00af43b8)[*(char *)(param_1 + 0xdc)];

    iVar2 = *(int *)(*(int *)(param_1 + 4) + 4);

    uStack_38 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x84 + param_1);

    iVar2 = iVar2 + 0x84 + param_1;

    uStack_34 = *(uint32_t /* width from decompiler */ *)(iVar2 + 4);

    uStack_30 = *(uint32_t /* width from decompiler */ *)(iVar2 + 8);

    uStack_2c = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc);

    pvStack_1c = (void *)0x4;

    local_84 = puVar5;

    iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(0xd0,0x2c);

    *(uint16_t *)(iVar2 + 4) = 0xd0;

    pvStack_1c._0_1_ = 5;

    uVar3 = FUN_005ebec0(&local_88);

    pvStack_1c._0_1_ = 4;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xd0) = uVar3;

    pvVar4 = operator_new(8);

    pvStack_1c._0_1_ = 6;

    if (pvVar4 == (void *)0x0) {

      uVar3 = 0;

    }

    else {

      uVar3 = FUN_00642b50(param_1);

    }

    pvStack_1c = (void *)CONCAT31(pvStack_1c._1_3_,4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xd4) = uVar3;

    FUN_006343a0(uVar3);

    *(short *)((int)puVar5 + 6) = *(short *)((int)puVar5 + 6) + -1;

    if (*(short *)((int)puVar5 + 6) == 0) {

      (**(code **)*puVar5)(1);

    }

    FUN_0055ff20(*(uint32_t /* width from decompiler */ *)(param_1 + 0xd0));

  }

  if (-1 < iStack_74) {

    pvStack_1c = (void *)0xffffffff;

    (**(code **)(*DAT_00b05060 + 0x14))(uStack_7c,iStack_74 * 8,0x12);

  }

  ExceptionList = pvStack_24;

  return;

}
