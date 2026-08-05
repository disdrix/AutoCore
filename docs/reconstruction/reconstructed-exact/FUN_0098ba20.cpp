// =============================================================================
// FUN_0098ba20
// -----------------------------------------------------------------------------
// Stable ID: aa_0098ba20
// Address:   0x0098ba20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0098ba20 @ 0x0098ba20
// Stable ID: aa_0098ba20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~139 non-empty decompiler lines.
//  - Control keywords: if×12, for×4, return×1.
//  - Notable callees: malloc×3, FUN_0077a590×2, FUN_007787a0, FUN_0077a730, FUN_0077bb70, FUN_0077bc40, FUN_0098ba20.
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

uint32_t /* width from decompiler */ * __thiscall FUN_0098ba20(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  void *pvVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint uVar8;

  uint uVar9;

  uint32_t /* width from decompiler */ *puVar10;

  

  param_1[1] = 0;

  param_1[2] = 0;

  *param_1 = &PTR_LAB_00a9b370;

  param_1[6] = 0;

  param_1[7] = 0;

  *(uint8_t *)(param_1 + 8) = 0;

  FUN_007787a0();

  pvVar4 = malloc(0x48);

  if (DAT_00d179d9 == '\0') {

    DAT_00d179d9 = '\x01';

    FUN_0077bc40(&DAT_00d0a3b8);

    FUN_0077bb70(&DAT_00d0a3b8);

  }

  uVar2 = param_2;

  iVar5 = FUN_0077a730(&DAT_00d0a3b8);

  if (iVar5 == 0) {

    param_1[4] = uVar2;

    param_1[3] = pvVar4;

    DAT_00d0d6a0._0_1_ = 0;

    uVar2 = param_1[4];

    DAT_00d0d6a0._1_1_ = (uint8_t)((uint)uVar2 >> 0x18);

    DAT_00d0d6a0._2_1_ = (uint8_t)((uint)uVar2 >> 0x10);

    DAT_00d0d6a4 = (uint8_t)uVar2;

    param_2 = 0x7fb;

    DAT_00d0d6a0._3_1_ = (uint8_t)((uint)uVar2 >> 8);

    FUN_0077a590(&param_2,0,pvVar4);

    iVar5 = param_2 + 5;

    puVar6 = operator_new(0x18);

    if (puVar6 == (uint32_t /* width from decompiler */ *)0x0) {

      puVar6 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      puVar6[4] = iVar5;

      puVar6[1] = 0;

      puVar6[2] = 0;

      *puVar6 = &PTR_LAB_009d7b00;

      puVar6[3] = &DAT_00d0d6a0;

      *(uint8_t *)(puVar6 + 5) = 0;

    }

    piVar3 = (int *)param_1[7];

    if (piVar3 != (int *)0x0) {

      piVar1 = piVar3 + 2;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar3 + 8))();

      }

    }

    param_1[7] = puVar6;

    if (puVar6 != (uint32_t /* width from decompiler */ *)0x0) {

      puVar6[2] = puVar6[2] + 1;

    }

    iVar5 = param_1[7];

    if (*(char *)(iVar5 + 0x14) == '\0') {

      puVar7 = malloc(*(size_t *)(iVar5 + 0x10));

      uVar9 = *(uint *)(iVar5 + 0x10);

      puVar6 = *(uint32_t /* width from decompiler */ **)(iVar5 + 0xc);

      puVar10 = puVar7;

      for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

        *puVar10 = *puVar6;

        puVar6 = puVar6 + 1;

        puVar10 = puVar10 + 1;

      }

      for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {

        *(uint8_t *)puVar10 = *(uint8_t *)puVar6;

        puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

        puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

      }

      *(uint32_t /* width from decompiler */ **)(iVar5 + 0xc) = puVar7;

      *(uint8_t *)(iVar5 + 0x14) = 1;

    }

    DAT_00d0d6a0._0_1_ = 1;

    uVar2 = param_1[4];

    DAT_00d0d6a0._1_1_ = (uint8_t)((uint)uVar2 >> 0x18);

    DAT_00d0d6a0._2_1_ = (uint8_t)((uint)uVar2 >> 0x10);

    DAT_00d0d6a4 = (uint8_t)uVar2;

    param_2 = 0x7fb;

    DAT_00d0d6a0._3_1_ = (uint8_t)((uint)uVar2 >> 8);

    FUN_0077a590(&param_2,1,pvVar4);

    iVar5 = param_2 + 5;

    puVar6 = operator_new(0x18);

    if (puVar6 == (uint32_t /* width from decompiler */ *)0x0) {

      puVar6 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      puVar6[4] = iVar5;

      puVar6[1] = 0;

      puVar6[2] = 0;

      *puVar6 = &PTR_LAB_009d7b00;

      puVar6[3] = &DAT_00d0d6a0;

      *(uint8_t *)(puVar6 + 5) = 0;

    }

    piVar3 = (int *)param_1[6];

    if (piVar3 != (int *)0x0) {

      piVar1 = piVar3 + 2;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar3 + 8))();

      }

    }

    param_1[6] = puVar6;

    if (puVar6 != (uint32_t /* width from decompiler */ *)0x0) {

      puVar6[2] = puVar6[2] + 1;

    }

    iVar5 = param_1[6];

    if (*(char *)(iVar5 + 0x14) == '\0') {

      puVar7 = malloc(*(size_t *)(iVar5 + 0x10));

      uVar9 = *(uint *)(iVar5 + 0x10);

      puVar6 = *(uint32_t /* width from decompiler */ **)(iVar5 + 0xc);

      puVar10 = puVar7;

      for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

        *puVar10 = *puVar6;

        puVar6 = puVar6 + 1;

        puVar10 = puVar10 + 1;

      }

      for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {

        *(uint8_t *)puVar10 = *(uint8_t *)puVar6;

        puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

        puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

      }

      *(uint32_t /* width from decompiler */ **)(iVar5 + 0xc) = puVar7;

      *(uint8_t *)(iVar5 + 0x14) = 1;

    }

    *(uint8_t *)(param_1 + 5) = 1;

    *(uint8_t *)(param_1 + 8) = 1;

  }

  return param_1;

}
