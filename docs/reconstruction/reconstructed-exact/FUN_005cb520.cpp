// =============================================================================
// FUN_005cb520
// -----------------------------------------------------------------------------
// Stable ID: aa_005cb520
// Address:   0x005cb520  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005cb520 @ 0x005cb520
// Stable ID: aa_005cb520
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×6, do×3, while×3, return×1.
//  - Notable callees: CONCAT12×2, CONCAT31, FUN_00512160, FUN_00512670, FUN_00513de0, FUN_00513e30, FUN_005c96c0, FUN_005c9a00.
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

void __thiscall FUN_005cb520(int param_1,int *param_2,uint8_t *param_3)



{

  uint *puVar1;

  char cVar2;

  int *piVar3;

  short sVar4;

  int iVar5;

  char *pcVar6;

  char *pcVar7;

  int *piVar8;

  int iVar9;

  uint32_t /* width from decompiler */ *puVar10;

  int iStack_8;

  

  piVar3 = param_2;

  if ((param_2 != (int *)0x0) &&

     (FUN_00512160(param_2[0x24],param_2[0x25],(char)param_2[0x26]), param_3 == (uint8_t *)0x2))

  {

    *(int *)(param_1 + -0x34) = piVar3[4];

    *(int *)(param_1 + -0x30) = piVar3[5];

    (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xbc + param_1) + 0x48))();

    *(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + 0xc + param_1) = piVar3[9];

    *(int *)(param_1 + -0x2c) = piVar3[0x21];

    *(char *)(param_1 + -0x24) = (char)piVar3[0x22];

    *(uint8_t *)(param_1 + -0x23) = *(uint8_t *)((int)piVar3 + 0x89);

    *(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + 8 + param_1) = piVar3[6];

    *(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xac + param_1) = piVar3[7];

    *(int *)(param_1 + -0x38) = piVar3[8];

    puVar1 = (uint *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + 0xc0 + param_1);

    *puVar1 = *puVar1 ^ ((uint)*(byte *)((int)piVar3 + 0x8a) << 8 ^ *puVar1) & 0x100;

    *(uint8_t *)(param_1 + -0x22) = *(uint8_t *)((int)piVar3 + 0xa3);

    *(char *)(param_1 + -0x21) = (char)piVar3[0x29];

    *(uint8_t *)(param_1 + -0x20) = *(uint8_t *)((int)piVar3 + 0xa5);

    FUN_00513e30(*(uint8_t *)((int)piVar3 + 0xab));

    *(short *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + 0xc4 + param_1) = (short)piVar3[0x2b];

    pcVar6 = (char *)((int)piVar3 + 0xae);

    pcVar7 = (char *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + 0x45 + param_1);

    do {

      cVar2 = *pcVar6;

      *pcVar7 = cVar2;

      pcVar6 = pcVar6 + 1;

      pcVar7 = pcVar7 + 1;

    } while (cVar2 != '\0');

    *(uint8_t *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + 0x44 + param_1) =

         *(uint8_t *)((int)piVar3 + 0xbf);

    iVar5 = *(int *)(*(int *)(param_1 + -0xbc) + 4);

    iVar9 = iVar5 + -0xbc + param_1;

    puVar1 = (uint *)(iVar9 + 0x17c);

    *puVar1 = *puVar1 ^ ((uint)*(byte *)(piVar3 + 0x2a) * 4 ^ *(uint *)(iVar9 + 0x17c)) & 4;

    FUN_00513de0(CONCAT31((int3)((uint)iVar5 >> 8),*(uint8_t *)((int)piVar3 + 0xa9)));

    iVar9 = *(int *)(*(int *)(param_1 + -0xbc) + 4);

    puVar1 = (uint *)(iVar9 + 0xc0 + param_1);

    *puVar1 = *puVar1 ^ ((uint)*(byte *)((int)piVar3 + 0xaa) << 0xf ^

                        *(uint *)(iVar9 + 0xc0 + param_1)) & 0x8000;

    param_2 = piVar3 + 0x14;

    iVar9 = 0;

    piVar8 = piVar3 + 10;

    do {

      if (*piVar8 == -1) break;

      puVar10 = &param_3;

      param_3._0_3_ = CONCAT12((char)*param_2,(short)*piVar8);

      FUN_005c9a00(puVar10);

      FUN_005cb3d0(puVar10);

      param_2 = (int *)((int)param_2 + 2);

      iVar9 = iVar9 + 1;

      piVar8 = piVar8 + 1;

    } while (iVar9 < 5);

    *(uint16_t *)(param_1 + -0x3c) = *(uint16_t *)((int)piVar3 + 0xc2);

    param_3 = (uint8_t *)((int)piVar3 + 0x5a);

    piVar8 = piVar3 + 0xf;

    *(int *)(param_1 + -0x28) = piVar3[0x34];

    iStack_8 = 0;

    do {

      if (*piVar8 == -1) break;

      param_2._0_3_ = CONCAT12(*param_3,(short)*piVar8);

      iVar5 = FUN_005c9a60();

      iVar9 = *(int *)(iVar5 + 4);

      if ((iVar9 == 0) ||

         ((uint)(*(int *)(iVar5 + 0xc) - iVar9 >> 2) <= (uint)(*(int *)(iVar5 + 8) - iVar9 >> 2))) {

        FUN_005c9cc0(*(uint32_t /* width from decompiler */ *)(iVar5 + 8),1,&param_2);

      }

      else {

        iVar9 = *(int *)(iVar5 + 8);

        FUN_005c96c0(iVar9,1,&param_2,iVar5,param_2);

        *(int *)(iVar5 + 8) = iVar9 + 4;

      }

      param_3 = param_3 + 2;

      iStack_8 = iStack_8 + 1;

      piVar8 = piVar8 + 1;

    } while (iStack_8 < 5);

    if (*piVar3 == 0x2012) {

      (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xbc + param_1) + 100))();

    }

    sVar4 = (short)piVar3[0x31];

    if (0x50 < sVar4) {

      sVar4 = 0x50;

    }

    *(short *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + param_1 + 0x2e) = sVar4;

    *(uint16_t *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + 0x30 + param_1) =

         *(uint16_t *)((int)piVar3 + 0xc6);

    *(short *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + 0x32 + param_1) = (short)piVar3[0x32];

    *(uint16_t *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + 0x34 + param_1) =

         *(uint16_t *)((int)piVar3 + 0xca);

    *(short *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + 0x36 + param_1) = (short)piVar3[0x33];

    puVar1 = (uint *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + 0xc0 + param_1);

    *puVar1 = *puVar1 | 0x10;

    FUN_00512670();

  }

  return;

}
