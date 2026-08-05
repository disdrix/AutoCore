// =============================================================================
// FUN_006189d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006189d0
// Address:   0x006189d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006189d0 @ 0x006189d0
// Stable ID: aa_006189d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: if×10, goto×2, do×1, return×1, while×1.
//  - Notable callees: CONCAT22, CONCAT31, CVOGHBBase_Start, CVOGHBList_Enqueue, CVOGReaction_RandomUnitScalar, FUN_00589b80, FUN_0058ab60, FUN_00618180.
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

bool FUN_006189d0(int *param_1,int param_2,int param_3,int param_4,uint32_t /* width from decompiler */ param_5,

                 uint32_t /* width from decompiler */ param_6)



{

  char cVar1;

  char cVar2;

  uint16_t uVar3;

  void *pvVar4;

  int iVar5;

  void *pvVar6;

  uint uVar7;

  CVOGHBBase *pAction;

  int *piVar8;

  int *piVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ uVar11;

  int local_18;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a871d;

  pvStack_c = ExceptionList;

  local_18 = 0;

  ExceptionList = &pvStack_c;

  pvVar4 = (void *)FUN_0058ab60(param_6);

  cVar1 = '\0';

LAB_00618a14:

  do {

    iVar5 = (int)cVar1;

    piVar9 = (int *)(param_4 + iVar5 * 0x10);

    if (((*piVar9 == -1) && (piVar9[1] == -1)) && ((char)piVar9[2] == '\0')) {

      if (pvVar4 != (void *)0x0) {

        operator_delete__(pvVar4);

      }

      ExceptionList = pvStack_c;

      return local_18 != 0;

    }

    cVar2 = FUN_00589b80(*(uint32_t /* width from decompiler */ *)(param_2 + 0xe4),

                         CONCAT22(cVar1 >> 7,*(uint16_t *)((int)pvVar4 + iVar5 * 2)));

    if (cVar2 == '\0') {

      piVar9 = (int *)CVOGReaction_ResolveObjectTarget

                                (CONCAT31((int3)((uint)piVar9[1] >> 8),(char)piVar9[2]),*piVar9,

                                 piVar9[1]);

      if (piVar9 != (int *)0x0) {

        pvVar6 = operator_new(0x6d0);

        local_4 = 0;

        if (pvVar6 == (void *)0x0) {

          pAction = (CVOGHBBase *)0x0;

        }

        else {

          uVar7 = (uint)*(ushort *)((int)pvVar4 + iVar5 * 2);

          uVar11 = 0x3f800000;

          uVar10 = 0;

          CVOGReaction_RandomUnitScalar(uVar7,0,0x3f800000);

          uVar3 = FUN_007a4120(uVar7);

          pAction = (CVOGHBBase *)

                    FUN_00618180(param_1,param_2,param_3,piVar9,param_5,uVar3,uVar10,uVar11);

        }

        local_4 = 0xffffffff;

        if (pAction->pOwnerObject == (void *)0x0) {

          (**(code **)pAction->pVTable)(1);

        }

        else {

          CVOGHBList_Enqueue(*(void **)(param_3 + 0xe4ec),pAction);

          CVOGHBBase_Start(pAction);

          local_18 = local_18 + 1;

          if (param_1 != (int *)0x0) {

            piVar8 = (int *)(**(code **)(*param_1 + 0x19c))();

            if (piVar8 != (int *)0x0) {

              piVar8 = (int *)(*(int *)(piVar8[1] + 4) + 4 + (int)piVar8);

            }

            if (piVar8 == piVar9) goto LAB_00618bab;

          }

          (**(code **)(*piVar9 + 0x238))

                    (0x14,*(uint32_t /* width from decompiler */ *)(param_2 + 0x5fc),

                     (int)(short)(*(short *)(param_2 + 0x174) + *(short *)(param_2 + 0x5f6)),

                     (int)*(short *)(param_2 + 0x14),param_1,0,0,0);

          if (param_1 != (int *)0x0) {

            (**(code **)(*param_1 + 0x238))

                      (0x15,*(uint32_t /* width from decompiler */ *)(param_2 + 0x5fc),

                       (int)(short)(*(short *)(param_2 + 0x174) + *(short *)(param_2 + 0x5f6)),

                       (int)*(short *)(param_2 + 0x14),piVar9,0,0,0);

            cVar1 = cVar1 + '\x01';

            goto LAB_00618a14;

          }

        }

      }

    }

LAB_00618bab:

    cVar1 = cVar1 + '\x01';

  } while( true );

}
