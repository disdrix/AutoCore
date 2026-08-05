// =============================================================================
// FUN_00814d80
// -----------------------------------------------------------------------------
// Stable ID: aa_00814d80
// Address:   0x00814d80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00814d80 @ 0x00814d80
// Stable ID: aa_00814d80
// Embedded strings (evidence for future rename):
//   - "%s %d"
//   - "Scores"
//   - "%I64d, K:%d OK:%d D:%d DMG:%d P:%d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~151 non-empty decompiler lines.
//  - Control keywords: if×10, do×3, while×3, return×1.
//  - Notable callees: FUN_007a4480, FUN_007a69d0, FUN_007a6de0, FUN_007fd970, FUN_00814d80, FUN_00870070, FUN_008704f0, FUN_008718d0.
//  - Strings: "%s %d"; "Scores"; "%I64d, K:%d OK:%d D:%d DMG:%d P:%d".
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

void FUN_00814d80(int param_1,int param_2)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iVar7;

  int iVar8;

  int *piVar9;

  uint32_t /* width from decompiler */ *puVar10;

  int local_64;

  uint32_t /* width from decompiler */ local_50;

  uint8_t local_4c;

  uint8_t local_4b;

  uint8_t local_4a;

  uint8_t local_49;

  uint8_t local_48;

  uint8_t local_47;

  uint8_t local_46;

  uint8_t local_45;

  uint8_t local_44;

  uint8_t local_43;

  uint8_t local_42;

  uint8_t local_41;

  uint local_40 [4];

  int iStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint uStack_28;

  int iStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint uStack_1c;

  int iStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint uStack_10;

  int iStack_c;

  uint32_t /* width from decompiler */ uStack_8;

  uint uStack_4;

  

  FUN_007a69d0();

  iVar8 = 0;

  local_50._2_1_ = 0xff;

  local_50._1_1_ = 0xff;

  local_50._0_1_ = 0xff;

  local_50._3_1_ = 0xff;

  local_4a = 0xff;

  local_4b = 0xff;

  local_4c = 0xff;

  local_49 = 0xff;

  local_46 = 0xff;

  local_47 = 0xff;

  local_48 = 0xff;

  local_45 = 0xff;

  local_42 = 0xff;

  local_43 = 0xff;

  local_44 = 0xff;

  local_41 = 0xff;

  local_64 = 0;

  iVar2 = __RTDynamicCast(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10cc),0,&CVOGDialog::RTTI_Type_Descriptor,

                          &CDlgArenaResults::RTTI_Type_Descriptor,0);

  if (((iVar2 == 0) || (*(int *)(iVar2 + 0x50c) == -1)) &&

     (*(char *)(*(int *)(*(int *)(param_1 + 0xe04) + 0xe894) + 0x8c) != '\0')) {

    puVar3 = operator_new__(0x10);

    piVar9 = (int *)(param_2 + 4);

    puVar10 = puVar3;

    do {

      if (*piVar9 == 0) {

        puVar3[iVar8] = 0;

      }

      else {

        pvVar4 = operator_new__(0x100);

        puVar3[iVar8] = pvVar4;

        iVar7 = *piVar9 + -9999;

        *(uint *)(((int)local_40 - (int)puVar3) + (int)puVar10) = (uint)*(ushort *)(piVar9 + 1);

        uVar5 = FUN_007a6de0(&DAT_00a5cb2c,0xffffffff);

        sprintf((char *)*puVar10,"%s %d",uVar5,iVar7);

        puVar6 = (uint32_t /* width from decompiler */ *)FUN_007fd970();

        local_64 = local_64 + 1;

        *(uint32_t /* width from decompiler */ *)(((int)&local_50 - (int)puVar3) + (int)puVar10) = *puVar6;

        puVar10 = puVar10 + 1;

      }

      iVar8 = iVar8 + 1;

      piVar9 = piVar9 + 2;

    } while (iVar8 < 4);

    piVar9 = *(int **)(param_1 + 0x10ec);

    if (piVar9 != (int *)0x0) {

      FUN_00892430(piVar9,999,0,1);

      FUN_00891b60(999,0,local_64,puVar3,local_40,&local_50,"Scores");

      cVar1 = (**(code **)(*piVar9 + 0x3d8))();

      if (cVar1 != '\0') {

        FUN_008908c0(piVar9);

      }

      (**(code **)(*piVar9 + 0x94))();

    }

    iVar8 = 0;

    do {

      operator_delete__((void *)puVar3[iVar8]);

      iVar8 = iVar8 + 1;

    } while (iVar8 < 4);

    operator_delete__(puVar3);

  }

  if (iVar2 != 0) {

    iVar8 = 0;

    if (*(char *)(param_2 + 0x24) != '\0') {

      puVar10 = (uint32_t /* width from decompiler */ *)(param_2 + 0x38);

      do {

        FUN_008718d0(iVar2);

        FUN_007a4480(0,"%I64d, K:%d OK:%d D:%d DMG:%d P:%d",puVar10[-4],puVar10[-3],

                     *(uint16_t *)(puVar10 + -2),*(uint16_t *)((int)puVar10 + -6),

                     *(uint16_t *)(puVar10 + -1),*puVar10,*(uint16_t *)((int)puVar10 + -2));

        iVar8 = iVar8 + 1;

        puVar10 = puVar10 + 0xc;

      } while (iVar8 < (int)(uint)*(byte *)(param_2 + 0x24));

    }

    iStack_30 = *(int *)(param_2 + 4);

    if (iStack_30 == 0) {

      iStack_30 = 0;

    }

    else {

      uStack_28 = (uint)*(ushort *)(param_2 + 8);

      uStack_2c = 0;

    }

    iStack_24 = *(int *)(param_2 + 0xc);

    if (iStack_24 == 0) {

      iStack_24 = 0;

    }

    else {

      uStack_1c = (uint)*(ushort *)(param_2 + 0x10);

      uStack_20 = 0;

    }

    iStack_18 = *(int *)(param_2 + 0x14);

    if (iStack_18 == 0) {

      iStack_18 = 0;

    }

    else {

      uStack_10 = (uint)*(ushort *)(param_2 + 0x18);

      uStack_14 = 0;

    }

    iStack_c = *(int *)(param_2 + 0x1c);

    if (iStack_c == 0) {

      iStack_c = 0;

    }

    else {

      uStack_4 = (uint)*(ushort *)(param_2 + 0x20);

      uStack_8 = 0;

    }

    FUN_008704f0(iVar2,0);

    FUN_00870070();

  }

  return;

}
