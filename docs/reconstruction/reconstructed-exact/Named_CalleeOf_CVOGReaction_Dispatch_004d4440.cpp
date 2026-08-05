// =============================================================================
// Named_CalleeOf_CVOGReaction_Dispatch_004d4440
// -----------------------------------------------------------------------------
// Stable ID: aa_004d4440
// Callee of CVOGReaction_Dispatch (+1 other named callers)
// Address:   0x004d4440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. CVOGReaction_Dispatch (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~150 non-empty decompiler lines.
//  - Control keywords: if×18, return×5, while×2, goto×1, for×1, do×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×2, CNDHash_LookupByKey, CONCAT31, FUN_004ce940, FUN_004d2820, FUN_004d4440, FUN_00508dc0, FUN_00509c70.
//  - Strings: "%s:%i\n".
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_Dispatch (+1 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



uint __thiscall

Named_CalleeOf_CVOGReaction_Dispatch_004d4440(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,char param_6,

            FILE *param_7)



{

  float fVar1;

  ushort uVar2;

  char cVar3;

  int iVar4;

  uint uVar5;

  int *piVar6;

  void *pvVar7;

  uint32_t /* width from decompiler */ uVar8;

  char *pcVar9;

  int iVar10;

  uint64_t uVar11;

  int iStack_1030;

  uint8_t auStack_1028 [4];

  void *pvStack_1024;

  int iStack_1020;

  uint32_t /* width from decompiler */ uStack_101c;

  char acStack_1018 [4092];

  uint32_t /* width from decompiler */ uStack_1c;

  int iStack_18;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009a208e;

  pvStack_14 = ExceptionList;

  uStack_1c = 0x4d4466;

  ExceptionList = &pvStack_14;

  iStack_18 = param_1;

  iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_3 + 4) + 4) + 4 + param_3) + 0x27c))();

  uVar5 = iVar4 - param_2;

  if ((int)uVar5 < 0xb) {

    FUN_004ce940(param_5);

    iVar4 = FUN_00508dc0(param_5);

    uVar5 = 0;

    if (iVar4 != 0) {

      fVar1 = *(float *)(iVar4 + 0x10);

      iVar4 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar4 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

      }

      uVar2 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

      *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

      uVar5 = (uint)uVar2;

      if (fVar1 <= (float)uVar5 * DAT_00aaa638) {

LAB_004d476f:

        ExceptionList = pvStack_14;

        return CONCAT31((int3)(uVar5 >> 8),1);

      }

      pvStack_1024 = (void *)0x0;

      iStack_1020 = 0;

      uStack_101c = 0;

      uStack_c = 0;

      FUN_0050b890(auStack_1028,param_2,

                   *(uint8_t *)

                    (*(int *)(*(int *)(*(int *)(*(int *)(param_3 + 4) + 4) + 0xac + param_3) + 0x3c)

                    + 0x532),1);

      if (pvStack_1024 != (void *)0x0) {

        if (iStack_1020 - (int)pvStack_1024 >> 2 != 0) {

          iStack_1030 = 0;

          while( true ) {

            if (pvStack_1024 == (void *)0x0) {

              iVar4 = 0;

            }

            else {

              iVar4 = iStack_1020 - (int)pvStack_1024 >> 2;

            }

            if (iVar4 <= iStack_1030) {

              uVar5 = 0;

              if (pvStack_1024 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

                operator_delete(pvStack_1024);

              }

              goto LAB_004d476f;

            }

            piVar6 = (int *)CVOGReaction_GiveItemByCbid

                                      (*(int *)(iStack_1030 * 4 + (int)pvStack_1024));

            if (piVar6 == (int *)0x0) {

              if (pvStack_1024 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

                operator_delete(pvStack_1024);

              }

              ExceptionList = pvStack_14;

              return 0;

            }

            iVar4 = (**(code **)(*piVar6 + 8))

                              (*(uint32_t /* width from decompiler */ *)(iStack_1030 * 4 + (int)pvStack_1024),param_1,1);

            if (iVar4 != 0) break;

            if (*(int *)(piVar6[0x2a] + 0x3c) != 0) {

              FUN_00509c70(piVar6,(int)*(short *)(*(int *)(piVar6[0x2a] + 0x3c) + 0x3f0),0x80000000,

                           1,0);

            }

            uVar11 = FUN_00521510(param_4);

            *(uint64_t *)(piVar6 + 0x5c) = uVar11;

            cVar3 = FUN_00513cf0();

            if (cVar3 != '\0') {

              iVar4 = CVOGReaction_RandomUnitScalar();

              if (0xfffff < *(int *)(iVar4 + 0xc)) {

                *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

              }

              fVar1 = DAT_00aaa8ec;

              uVar2 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

              *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

              if ((float)uVar2 * DAT_00aaa638 <= fVar1) {

                uVar5 = *(uint *)(param_1 + 0xfc);

                pvVar7 = (void *)FUN_00541a80();

                pvVar7 = CNDHash_LookupByKey(pvVar7,uVar5);

                if ((pvVar7 != (void *)0x0) && (*(int *)((int)pvVar7 + 0x150) != 0)) {

                  FUN_00513de0(1);

                }

              }

            }

            if (param_6 == '\0') {

              FUN_004d2820(piVar6,param_4,0x40a00000,1);

              iStack_1030 = iStack_1030 + 1;

            }

            else {

              iVar4 = *piVar6;

              pcVar9 = acStack_1018;

              for (iVar10 = 0x400; iVar10 != 0; iVar10 = iVar10 + -1) {

                pcVar9[0] = '\0';

                pcVar9[1] = '\0';

                pcVar9[2] = '\0';

                pcVar9[3] = '\0';

                pcVar9 = pcVar9 + 4;

              }

              uVar8 = (**(code **)(iVar4 + 0x15c))(*(uint32_t /* width from decompiler */ *)(piVar6[0x2a] + 0x34));

              sprintf(acStack_1018,"%s:%i\n",uVar8);

              pcVar9 = acStack_1018;

              do {

                cVar3 = *pcVar9;

                pcVar9 = pcVar9 + 1;

              } while (cVar3 != '\0');

              fwrite(acStack_1018,1,(int)pcVar9 - (int)(acStack_1018 + 1),param_7);

              (**(code **)*piVar6)(1);

              iStack_1030 = iStack_1030 + 1;

            }

          }

        }

      }

      uVar5 = FUN_00691630();

    }

  }

  ExceptionList = pvStack_14;

  return uVar5 & 0xffffff00;

}
