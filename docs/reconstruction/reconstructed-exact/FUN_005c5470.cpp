// =============================================================================
// FUN_005c5470
// -----------------------------------------------------------------------------
// Stable ID: aa_005c5470
// Address:   0x005c5470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c5470 @ 0x005c5470
// Stable ID: aa_005c5470
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~221 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, while×2, for×2, return×1.
//  - Notable callees: free×2, FUN_005c5470, malloc.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_005c5470(uint32_t /* width from decompiler */ *param_1)



{

  uint16_t *puVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  int iVar5;

  byte unaff_BP;

  uint32_t /* width from decompiler */ unaff_EDI;

  float fVar6;

  float *pfVar7;

  float *pfStack_138;

  uint uVar8;

  uint uStack_124;

  float fStack_120;

  float local_11c;

  uint8_t local_118 [4];

  uint8_t auStack_114 [8];

  uint32_t /* width from decompiler */ local_10c;

  void *local_108;

  uint16_t *local_104;

  float local_100 [9];

  uint32_t /* width from decompiler */ uStack_dc;

  uint32_t /* width from decompiler */ uStack_d8;

  uint32_t /* width from decompiler */ uStack_d4;

  uint32_t /* width from decompiler */ uStack_d0;

  float fStack_cc;

  uint32_t /* width from decompiler */ uStack_c8;

  uint16_t uStack_c4;

  uint32_t /* width from decompiler */ uStack_c0;

  uint32_t /* width from decompiler */ uStack_bc;

  uint32_t /* width from decompiler */ uStack_b8;

  void *pvStack_b4;

  int *piStack_b0;

  int *piStack_ac;

  int *piStack_a8;

  uint8_t auStack_a0 [8];

  undefined **ppuStack_98;

  uint32_t /* width from decompiler */ uStack_94;

  float fStack_90;

  uint32_t /* width from decompiler */ uStack_8c;

  uint32_t /* width from decompiler */ uStack_88;

  uint32_t /* width from decompiler */ uStack_84;

  float fStack_80;

  uint32_t /* width from decompiler */ uStack_7c;

  uint32_t /* width from decompiler */ uStack_78;

  uint32_t /* width from decompiler */ uStack_74;

  float fStack_70;

  uint32_t /* width from decompiler */ uStack_6c;

  uint32_t /* width from decompiler */ uStack_68;

  uint uStack_64;

  uint32_t /* width from decompiler */ uStack_60;

  uint16_t uStack_5c;

  uint16_t uStack_5a;

  uint32_t /* width from decompiler */ uStack_58;

  float fStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  void *pvStack_24;

  uint16_t uStack_20;

  uint16_t uStack_1e;

  uint32_t /* width from decompiler */ uStack_1c;

  uint8_t uStack_18;

  uint32_t /* width from decompiler */ uStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a6d96;

  pvStack_c = ExceptionList;

  pfStack_138 = &local_11c;

  local_108 = (void *)0x0;

  local_10c = 0;

  local_104 = (uint16_t *)0x1;

  local_100[0] = 0.0;

  local_100[1] = 0.0;

  local_100[2] = 0.0;

  local_100[3] = 0.0;

  local_100[4] = 0.0;

  ExceptionList = &pvStack_c;

  (*(code *)**(uint32_t /* width from decompiler */ **)*param_1)(local_118);

  local_100[0] = DAT_00aaaaa0;

  local_100[1] = 0.0;

  puVar1 = operator_new__((int)fStack_120 * uStack_124 * 4);

  local_108 = (void *)0x4;

  uVar8 = 0;

  local_104 = puVar1;

  if (uStack_124 != 0) {

    do {

      fVar6 = 0.0;

      if (fStack_120 != 0.0) {

        do {

          (**(code **)(*(int *)*param_1 + 0x10))(uVar8,fVar6,&local_11c);

          *puVar1 = (short)uVar8;

          (**(code **)(*(int *)*param_1 + 0x14))(unaff_EDI,fVar6,&pfStack_138);

          *(byte *)(puVar1 + 1) = *(byte *)(puVar1 + 1) ^ (*(byte *)(puVar1 + 1) ^ unaff_BP) & 0x7f;

          *(byte *)(puVar1 + 1) = *(byte *)(puVar1 + 1) & 0x7f;

          *(byte *)((int)puVar1 + 3) =

               *(byte *)((int)puVar1 + 3) ^ (*(byte *)((int)puVar1 + 3) ^ unaff_BP) & 0x7f;

          puVar1 = (uint16_t *)((int)puVar1 + (int)local_108);

          fVar6 = (float)((int)fVar6 + 1);

        } while ((uint)fVar6 < (uint)fStack_120);

      }

      uVar8 = uVar8 + 1;

    } while (uVar8 < uStack_124);

  }

  piVar2 = (int *)(**(code **)(*(int *)param_1[1] + 0xec))();

  fStack_30 = (float)(**(code **)(*piVar2 + 0x28))(auStack_114);

  if (local_108 != (void *)0x0) {

    operator_delete__(local_108);

  }

  uStack_8c = 0;

  uStack_88 = 0;

  uStack_84 = 0;

  uStack_7c = 0;

  uStack_78 = 0;

  uStack_74 = 0;

  uStack_64 = 0;

  uStack_68 = 0;

  uStack_6c = 0;

  local_108 = (void *)0x0;

  uStack_94 = 7;

  ppuStack_98 = &PTR_FUN_009d9e58;

  fStack_90 = g_flOne;

  fStack_80 = g_flOne;

  fStack_70 = g_flOne;

  uStack_5c = 0;

  uStack_5a = 0;

  uStack_58 = 0;

  uStack_4c = DAT_00aaa668;

  fStack_54 = g_flOne;

  uStack_50 = DAT_00aaa668;

  uStack_48 = 0;

  uStack_44 = 0;

  uStack_40 = 0;

  uStack_3c = 0;

  uStack_38 = 0;

  uStack_34 = 0;

  fStack_2c = g_flOne;

  fStack_28 = g_flOne;

  pvStack_24 = (void *)g_flOne;

  uStack_20 = 0;

  uStack_1e = 0;

  uStack_1c = 0;

  uStack_60 = 0;

  local_11c = g_flOne;

  uStack_10 = 0;

  (**(code **)(*(int *)*param_1 + 8))(&local_11c);

  fStack_30 = fStack_120 / _DAT_00af40e8;

  (**(code **)(*(int *)*param_1 + 4))(&fStack_2c);

  fStack_2c = fStack_30;

  piStack_b0 = (int *)0x0;

  piStack_a8 = (int *)0x0;

  pfVar7 = local_100;

  for (iVar5 = 0x18; iVar5 != 0; iVar5 = iVar5 + -1) {

    *pfVar7 = 0.0;

    pfVar7 = pfVar7 + 1;

  }

  fStack_28 = 0.0;

  uStack_64 = uStack_64 & 0xffff0000;

  uStack_d0 = 0;

  fStack_cc = 0.0;

  local_100[0] = g_flOne;

  local_100[1] = 0.0;

  local_100[2] = 0.0;

  local_100[3] = 0.0;

  local_100[4] = g_flOne;

  local_100[5] = 0.0;

  local_100[6] = 0.0;

  local_100[7] = 0.0;

  local_100[8] = g_flOne;

  uStack_d4 = 0;

  uStack_d8 = 0;

  uStack_dc = 0;

  uStack_c8 = 0;

  uStack_c0 = 0;

  uStack_bc = 0;

  uStack_c4 = 0;

  uStack_b8 = 0;

  piStack_ac = piStack_b0;

  pvStack_b4 = (void *)0x1;

  uStack_18 = 1;

  if ((piStack_a8 <= piStack_b0) &&

     ((piStack_b0 == (int *)0x0 || ((uint)((int)piStack_a8 - (int)piStack_b0 >> 2) < 2)))) {

    piVar3 = malloc(8);

    piVar2 = piVar3;

    for (piVar4 = piStack_b0; piVar4 != piStack_ac; piVar4 = piVar4 + 1) {

      *piVar2 = *piVar4;

      piVar2 = piVar2 + 1;

    }

    if (piStack_b0 != (int *)0x0) {

      free(piStack_b0);

    }

    piStack_a8 = piVar3 + 2;

    piStack_ac = piVar3 + ((int)piStack_ac - (int)piStack_b0 >> 2);

    piStack_b0 = piVar3;

  }

  fStack_cc = g_flOne;

  *piStack_ac = (int)auStack_a0;

  piStack_ac = piStack_ac + 1;

  uStack_d0 = 0;

  uStack_dc = 0;

  uStack_d8 = 0;

  uStack_d4 = 0;

  (**(code **)(*(int *)param_1[1] + 0x18))(local_100);

  if (pvStack_b4 != (void *)0x0) {

    free(pvStack_b4);

  }

  ExceptionList = pvStack_24;

  return;

}
