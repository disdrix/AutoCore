// =============================================================================
// FUN_00523430
// -----------------------------------------------------------------------------
// Stable ID: aa_00523430
// Address:   0x00523430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00523430 @ 0x00523430
// Stable ID: aa_00523430
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~144 non-empty decompiler lines.
//  - Control keywords: if×7, return×7, do×5, while×5, for×4, switch×1.
//  - Notable callees: CONCAT31×6, FUN_00403450, FUN_00404ba0, FUN_00523430, FUN_00764030, block.
//  - Return sites: 7.

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

/* WARNING: Removing unreachable block (ram,0x00523527) */



uint __thiscall FUN_00523430(int param_1,uint param_2,uint32_t /* width from decompiler */ *param_3,char *param_4)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  char *pcVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ uVar6;

  void *pvVar7;

  uint32_t /* width from decompiler */ uVar8;

  int iVar9;

  undefined3 uVar10;

  uint uVar11;

  char *pcVar12;

  char local_18c [127];

  char cStack_10d;

  char local_10c [4];

  char acStack_108 [252];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a3824;

  local_c = ExceptionList;

  if (((-1 < (int)param_2) && ((int)param_2 < 10)) && (param_3 != (uint32_t /* width from decompiler */ *)0x0)) {

    local_10c[0] = '\0';

    pcVar4 = param_4;

    if (param_4 != (char *)0x0) {

      do {

        cVar1 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      uVar5 = (int)pcVar4 - (int)param_4;

      pcVar4 = &cStack_10d;

      do {

        pcVar12 = pcVar4 + 1;

        pcVar4 = pcVar4 + 1;

      } while (*pcVar12 != '\0');

      for (uVar11 = uVar5 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)param_4;

        param_4 = param_4 + 4;

        pcVar4 = pcVar4 + 4;

      }

      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

        *pcVar4 = *param_4;

        param_4 = param_4 + 1;

        pcVar4 = pcVar4 + 1;

      }

    }

    ExceptionList = &local_c;

    uVar6 = (*(code *)PTR_FUN_00af8c9c)();

    FUN_00403450(param_3 + 3,uVar6);

    pcVar4 = local_18c;

    do {

      cVar1 = *pcVar4;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    uVar5 = (int)pcVar4 - (int)local_18c;

    pcVar4 = &cStack_10d;

    do {

      pcVar12 = pcVar4 + 1;

      pcVar4 = pcVar4 + 1;

    } while (*pcVar12 != '\0');

    pcVar12 = local_18c;

    for (uVar11 = uVar5 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)pcVar12;

      pcVar12 = pcVar12 + 4;

      pcVar4 = pcVar4 + 4;

    }

    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

      *pcVar4 = *pcVar12;

      pcVar12 = pcVar12 + 1;

      pcVar4 = pcVar4 + 1;

    }

    puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x67c + param_2 * 4);

    if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*puVar2)(1);

    }

    uVar6 = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x67c + param_2 * 4) = 0;

    if ((local_10c[0] != '\0') && (local_10c[0] != ' ')) {

      pvVar7 = operator_new(0x14c);

      uStack_4 = 0;

      if (pvVar7 == (void *)0x0) {

        uVar8 = 0;

      }

      else {

        uVar8 = FUN_00764030();

      }

      uStack_4 = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x67c + param_2 * 4) = uVar8;

      pcVar4 = &cStack_10d;

      do {

        pcVar12 = pcVar4;

        pcVar4 = pcVar12 + 1;

      } while (pcVar12[1] != '\0');

      piVar3 = *(int **)(param_1 + 0x67c + param_2 * 4);

      *(uint32_t /* width from decompiler */ *)(pcVar12 + 1) = DAT_00a28904;

      pcVar12[5] = DAT_00a28908;

      iVar9 = *piVar3;

      uVar8 = FUN_00404ba0(local_10c);

      iVar9 = (**(code **)(iVar9 + 0x5c))(uVar8);

      if (iVar9 < 0) {

        puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x67c + param_2 * 4);

        if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

          (**(code **)*puVar2)(1);

        }

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x67c + param_2 * 4) = 0;

      }

      else {

        uVar6 = *param_3;

      }

    }

    uVar10 = (undefined3)(param_2 - 1 >> 8);

    switch(param_2 - 1) {

    case 0:

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x700) = uVar6;

      ExceptionList = local_c;

      return CONCAT31(uVar10,1);

    case 2:

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x708) = uVar6;

      ExceptionList = local_c;

      return CONCAT31(uVar10,1);

    case 3:

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x70c) = uVar6;

      ExceptionList = local_c;

      return CONCAT31(uVar10,1);

    case 5:

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x710) = uVar6;

      ExceptionList = local_c;

      return CONCAT31(uVar10,1);

    case 6:

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x704) = uVar6;

      ExceptionList = local_c;

      return CONCAT31(uVar10,1);

    case 7:

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x714) = uVar6;

    }

    ExceptionList = local_c;

    return CONCAT31(uVar10,1);

  }

  return param_2 & 0xffffff00;

}
