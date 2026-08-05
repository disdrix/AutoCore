// =============================================================================
// FUN_008ed6d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008ed6d0
// Address:   0x008ed6d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008ed6d0 @ 0x008ed6d0
// Stable ID: aa_008ed6d0
// Embedded strings (evidence for future rename):
//   - "%S%s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~91 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, while×2, return×1.
//  - Notable callees: FUN_007b6a20×2, sprintf×2, CNDHash_LookupByKey, FUN_0040e0c0, FUN_004a94e0, FUN_004ac290, FUN_004ad730, FUN_00541a80.
//  - Strings: "%S%s".
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

void FUN_008ed6d0(uint32_t /* width from decompiler */ param_1,uint param_2)



{

  byte bVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  byte *pbVar8;

  char *pcVar9;

  void *apvStack_534 [4];

  uint32_t /* width from decompiler */ uStack_524;

  void *pvStack_520;

  int iStack_51c;

  int iStack_518;

  void *pvStack_514;

  char acStack_510 [4];

  char local_50c [280];

  void *pvStack_3f4;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1043;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pvVar2 = (void *)FUN_00541a80();

  pvVar2 = CNDHash_LookupByKey(pvVar2,param_2);

  iVar5 = 0;

  if (pvVar2 != (void *)0x0) {

    sprintf(local_50c,"%S%s",(int)pvVar2 + 0x1c,&DAT_00a285c4);

    pcVar9 = local_50c;

    FUN_007b6a20(pcVar9);

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_007b72b0(pcVar9);

    if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

      FUN_004ad730();

      local_4 = 0;

      iVar4 = FUN_004a94e0(puVar3);

      if (iVar4 == -1) {

        (**(code **)*puVar3)();

      }

      else {

        (**(code **)*puVar3)(1);

        sprintf(acStack_510,"%S%s",(int)pvVar2 + 0x1c,&DAT_00a395dc);

        pcVar9 = acStack_510;

        FUN_007b6a20(pcVar9);

        iVar4 = FUN_007b7250(pcVar9);

        if (iVar4 != 0) {

          iVar4 = *(int *)(iVar4 + 4);

          if (iVar4 == 0) {

            iVar6 = 0;

            iVar4 = 0;

          }

          else {

            iVar6 = *(int *)(iVar4 + 0x10);

            iVar4 = *(int *)(iVar4 + 0xc);

          }

          pvStack_514 = operator_new__(iVar4 * iVar6);

          apvStack_534[0] = pvStack_514;

          if (0 < iVar6) {

            do {

              iVar7 = 0;

              if (0 < iVar4) {

                pbVar8 = (byte *)(iVar5 + (int)pvStack_514);

                do {

                  bVar1 = FUN_00788fd0(iVar7,iVar5);

                  *pbVar8 = bVar1 >> 3;

                  iVar7 = iVar7 + 1;

                  pbVar8 = pbVar8 + iVar6;

                  pvStack_514 = apvStack_534[0];

                } while (iVar7 < iVar4);

              }

              iVar5 = iVar5 + 1;

            } while (iVar5 < iVar6);

          }

          apvStack_534[0] = pvStack_3f4;

          uStack_524 = param_1;

          pvStack_520 = pvStack_3f4;

          iStack_51c = iVar6;

          iStack_518 = iVar4;

          FUN_0040e0c0(apvStack_534);

        }

      }

      puStack_8 = (uint8_t *)0xffffffff;

      FUN_004ac290();

    }

  }

  ExceptionList = local_c;

  return;

}
