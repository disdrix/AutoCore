// =============================================================================
// FUN_006124b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006124b0
// Address:   0x006124b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006124b0 @ 0x006124b0
// Stable ID: aa_006124b0
// Embedded strings (evidence for future rename):
//   - "%s: %d / %d"
//   - "Level"
//   - " %s: %d-%d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~103 non-empty decompiler lines.
//  - Control keywords: if×7, do×3, while×3, for×2, return×1.
//  - Notable callees: FUN_005711c0×2, FUN_007a6de0×2, sprintf×2, FUN_00402d50, FUN_00404d70, FUN_004eb010, FUN_004f1e20, FUN_006124b0.
//  - Strings: "%s: %d / %d"; "Level"; " %s: %d-%d".
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

int __thiscall FUN_006124b0(int param_1,uint32_t /* width from decompiler */ param_2,char *param_3,size_t param_4)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  char *pcVar8;

  uint uVar9;

  uint uVar10;

  char *pcVar11;

  bool bVar12;

  int unaff_retaddr;

  uint32_t /* width from decompiler */ uVar13;

  char acStack_314 [128];

  uint8_t *puStack_294;

  uint8_t auStack_290 [127];

  char cStack_211;

  char acStack_210 [512];

  void *pvStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a8545;

  pvStack_c = ExceptionList;

  pvStack_10 = (void *)(uint)(uint3)pvStack_10;

  puStack_294 = (uint8_t *)(uint)(uint3)puStack_294;

  ExceptionList = &pvStack_c;

  iVar2 = FUN_00404d70(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10));

  FUN_007a69d0();

  if (iVar2 == 0) {

    iVar2 = 0;

  }

  else {

    bVar12 = *(int *)(iVar2 + 0x3c) == 0;

    if (bVar12) {

      FUN_004f1e20(0,1);

    }

    if (((unaff_retaddr == 0) || (*(int *)(unaff_retaddr + 0x250) == 0)) ||

       (*(int *)(*(int *)(unaff_retaddr + 0x250) + 0x2b0) == 0)) {

      iVar2 = 0;

    }

    else {

      iVar4 = *(int *)(param_1 + 0x14);

      iVar3 = FUN_005711c0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10),0);

      if (iVar3 < iVar4) {

        iVar4 = FUN_005711c0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10),0);

      }

      puVar5 = (uint32_t /* width from decompiler */ *)FUN_00402d50(*(int *)(iVar2 + 0x3c) + 0x92);

      uVar13 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14);

      puStack_8 = (uint8_t *)0x0;

      uVar6 = FUN_007a6de0(*puVar5,0xffffffff);

      sprintf(acStack_210,"%s: %d / %d",uVar6,iVar4,uVar13);

      puStack_8 = (uint8_t *)0xffffffff;

      if (puStack_294 != auStack_290) {

        free(puStack_294);

      }

      if (*(char *)(param_1 + 0x58) != '\0') {

        uVar13 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x60);

        uVar6 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c);

        uVar7 = FUN_007a6de0("Level",0xffffffff);

        sprintf(acStack_314," %s: %d-%d",uVar7,uVar6,uVar13);

        pcVar8 = acStack_314;

        do {

          cVar1 = *pcVar8;

          pcVar8 = pcVar8 + 1;

        } while (cVar1 != '\0');

        uVar9 = (int)pcVar8 - (int)acStack_314;

        pcVar8 = &cStack_211;

        do {

          pcVar11 = pcVar8 + 1;

          pcVar8 = pcVar8 + 1;

        } while (*pcVar11 != '\0');

        pcVar11 = acStack_314;

        for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar8 = *(uint32_t /* width from decompiler */ *)pcVar11;

          pcVar11 = pcVar11 + 4;

          pcVar8 = pcVar8 + 4;

        }

        for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {

          *pcVar8 = *pcVar11;

          pcVar11 = pcVar11 + 1;

          pcVar8 = pcVar8 + 1;

        }

      }

      if (bVar12) {

        FUN_004eb010();

      }

      strncat(param_3,acStack_210,param_4);

      pcVar8 = acStack_210;

      do {

        cVar1 = *pcVar8;

        pcVar8 = pcVar8 + 1;

      } while (cVar1 != '\0');

      iVar2 = (int)pcVar8 - (int)(acStack_210 + 1);

    }

  }

  ExceptionList = pvStack_10;

  return iVar2;

}
