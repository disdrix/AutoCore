// =============================================================================
// FUN_0095d060
// -----------------------------------------------------------------------------
// Stable ID: aa_0095d060
// Address:   0x0095d060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0095d060 @ 0x0095d060
// Stable ID: aa_0095d060
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~128 non-empty decompiler lines.
//  - Control keywords: if×8, do×1, while×1, return×1.
//  - Notable callees: FUN_00767160×6, CONCAT31×5, FUN_0044cbd0×2, FUN_00480b50×2, FUN_0095d060.
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

uint32_t /* width from decompiler */ __thiscall FUN_0095d060(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint uVar2;

  int iVar3;

  byte *pbVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint *puVar6;

  uint32_t /* width from decompiler */ uVar7;

  undefined *puVar8;

  uint32_t /* width from decompiler */ uStack_24;

  undefined *puStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ *puStack_18;

  uint uStack_14;

  

  puVar1 = param_2;

  uStack_14 = 0x95d074;

  FUN_0044cbd0();

  if (*(int *)(param_1 + 0x14) == 0) {

    param_2 = (uint32_t /* width from decompiler */ *)((uint)param_2._1_3_ << 8);

  }

  else {

    iVar3 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14);

    param_2 = (uint32_t /* width from decompiler */ *)

              CONCAT31(param_2._1_3_,

                       ((char)(iVar3 / 0x14) + (char)(iVar3 >> 0x1f)) -

                       (char)((longlong)iVar3 * 0x66666667 >> 0x3f));

  }

  uStack_14 = 0x95d0a6;

  FUN_0044cbd0();

  pbVar4 = *(byte **)(param_1 + 0x14);

  if (pbVar4 != *(byte **)(param_1 + 0x18)) {

    do {

      if (puVar1[7] == 0) {

        uStack_14 = 1;

        puStack_18 = &param_2;

        param_2 = (uint32_t /* width from decompiler */ *)CONCAT31(param_2._1_3_,*pbVar4);

      }

      else {

        uStack_14 = (uint)*pbVar4;

        puStack_18 = (uint32_t /* width from decompiler */ *)&DAT_00a9d718;

        uStack_1c = 0x95d0d6;

        uVar2 = FUN_00767160();

        puVar1[1] = puVar1[1] | uVar2;

        uStack_14 = 2;

        puVar1[8] = 0;

        puStack_18 = (uint32_t /* width from decompiler */ *)&DAT_00a97b84;

      }

      uStack_1c = 0x95d0ed;

      uVar2 = (**(code **)(*(int *)*puVar1 + 0x18))();

      puVar1[1] = puVar1[1] | uVar2;

      uStack_1c = *(uint32_t /* width from decompiler */ *)(pbVar4 + 4);

      if (puVar1[7] == 0) {

        uStack_1c = 4;

        puStack_20 = &stack0xfffffffc;

      }

      else {

        puStack_20 = &DAT_00a9d718;

        uStack_24 = 0x95d112;

        uVar2 = FUN_00767160();

        puVar1[1] = puVar1[1] | uVar2;

        uStack_1c = 2;

        puVar1[8] = 0;

        puStack_20 = &DAT_00a97b84;

      }

      uStack_24 = 0x95d129;

      uVar2 = (**(code **)(*(int *)*puVar1 + 0x18))();

      puVar1[1] = puVar1[1] | uVar2;

      uStack_24 = *(uint32_t /* width from decompiler */ *)(pbVar4 + 8);

      if (puVar1[7] == 0) {

        uStack_24 = 4;

        puVar8 = &stack0xfffffff4;

      }

      else {

        uVar2 = FUN_00767160(&DAT_00a9d718);

        puVar1[1] = puVar1[1] | uVar2;

        uStack_24 = 2;

        puVar1[8] = 0;

        puVar8 = &DAT_00a97b84;

      }

      uVar2 = (**(code **)(*(int *)*puVar1 + 0x18))(puVar8);

      puVar1[1] = puVar1[1] | uVar2;

      if (puVar1[7] == 0) {

        uStack_14 = CONCAT31(uStack_14._1_3_,pbVar4[0xc]);

        uVar7 = 1;

        puVar6 = &uStack_14;

      }

      else {

        uVar2 = FUN_00767160(&DAT_00a9d718,pbVar4[0xc]);

        puVar1[1] = puVar1[1] | uVar2;

        uVar7 = 2;

        puVar1[8] = 0;

        puVar6 = (uint *)&DAT_00a97b84;

      }

      uVar2 = (**(code **)(*(int *)*puVar1 + 0x18))(puVar6,uVar7);

      puVar1[1] = puVar1[1] | uVar2;

      if (puVar1[7] == 0) {

        uStack_1c = CONCAT31(uStack_1c._1_3_,pbVar4[0xd]);

        uVar7 = 1;

        puVar5 = &uStack_1c;

      }

      else {

        uVar2 = FUN_00767160(&DAT_00a9d718,pbVar4[0xd]);

        puVar1[1] = puVar1[1] | uVar2;

        uVar7 = 2;

        puVar1[8] = 0;

        puVar5 = (uint32_t /* width from decompiler */ *)&DAT_00a97b84;

      }

      uVar2 = (**(code **)(*(int *)*puVar1 + 0x18))(puVar5,uVar7);

      puVar1[1] = puVar1[1] | uVar2;

      FUN_00480b50(pbVar4 + 0xe);

      FUN_00480b50(pbVar4 + 0x10);

      if (puVar1[7] == 0) {

        uStack_24 = CONCAT31(uStack_24._1_3_,pbVar4[0x12]);

        uVar2 = (**(code **)(*(int *)*puVar1 + 0x18))(&uStack_24,1);

      }

      else {

        uVar2 = FUN_00767160(&DAT_00a9d718,pbVar4[0x12]);

        puVar1[1] = puVar1[1] | uVar2;

        puVar1[8] = 0;

        uVar2 = (**(code **)(*(int *)*puVar1 + 0x18))(&DAT_00a97b84,2);

      }

      puVar1[1] = puVar1[1] | uVar2;

      pbVar4 = pbVar4 + 0x14;

    } while (pbVar4 != *(byte **)(param_1 + 0x18));

  }

  return 0;

}
