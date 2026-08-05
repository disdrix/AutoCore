// =============================================================================
// Named_CalleeOf_CVOGHBAIFollowVehicle_FireWeapons_005021d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005021d0
// Callee of CVOGHBAIFollowVehicle_FireWeapons
// Address:   0x005021d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGHBAIFollowVehicle_FireWeapons: vehicle helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: FUN_0056a260×2, CVOGHBBase_Start, CVOGHBList_Enqueue, Client_SendLogicUiPacket, FUN_005021d0, FUN_0056d160, FUN_005fe6a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGHBAIFollowVehicle_FireWeapons
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

void __thiscall Named_CalleeOf_CVOGHBAIFollowVehicle_FireWeapons_005021d0(int param_1,char param_2)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  void *pvVar4;

  CVOGHBBase *pAction;

  int iVar5;

  bool bVar6;

  int aiStack_144 [7];

  uint32_t /* width from decompiler */ uStack_128;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a2edf;

  pvStack_c = ExceptionList;

  iVar5 = 0;

  ExceptionList = &pvStack_c;

  do {

    piVar1 = *(int **)(*(int *)(param_1 + 0x260) + iVar5 * 4);

    pAction = (CVOGHBBase *)0x0;

    if (piVar1 != (int *)0x0) {

      bVar6 = ((int)param_2 & 1 << ((byte)iVar5 & 0x1f)) != 0;

      if (((bVar6) && (*(char *)((int)piVar1 + 0xcb) == '\0')) &&

         (*(char *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0x7e) != '\0'))

      {

        cVar2 = (**(code **)(*piVar1 + 0x4c))(0);

        FUN_0056a260(cVar2);

        if (cVar2 != '\0') {

          FUN_0056d160(&DAT_00b041b0,0);

          iVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x210))

                            (0);

          if (iVar3 == 0) {

            iVar3 = 0;

          }

          else {

            iVar3 = *(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3;

          }

          if (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xe8a0) ==

              iVar3) {

            uStack_128 = 0x31;

            aiStack_144[0] = iVar5;

            Client_SendLogicUiPacket(aiStack_144);

          }

          pvVar4 = operator_new(0x24);

          uStack_4 = 0;

          if (pvVar4 != (void *)0x0) {

            pAction = (CVOGHBBase *)

                      FUN_005fe6a0(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x260) + iVar5 * 4),1000);

          }

          uStack_4 = 0xffffffff;

          CVOGHBList_Enqueue(*(void **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 +

                                                param_1) + 0xe4ec),pAction);

          CVOGHBBase_Start(pAction);

        }

      }

      else {

        FUN_0056a260(bVar6);

      }

    }

    iVar5 = iVar5 + 1;

  } while (iVar5 < 3);

  ExceptionList = pvStack_c;

  return;

}
