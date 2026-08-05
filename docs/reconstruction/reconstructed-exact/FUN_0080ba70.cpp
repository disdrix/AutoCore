// =============================================================================
// FUN_0080ba70
// -----------------------------------------------------------------------------
// Stable ID: aa_0080ba70
// Address:   0x0080ba70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080ba70 @ 0x0080ba70
// Stable ID: aa_0080ba70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×8, return×3, while×2, do×1, goto×1.
//  - Notable callees: FUN_004022a0×2, LeaveCriticalSection×2, CONCAT31, CVOGHBList_Enqueue, FUN_00418820, FUN_004294f0, FUN_0080ba70, __RTDynamicCast.
//  - Return sites: 3.

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

void FUN_0080ba70(int param_1)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  CVOGHBBase *pAction;

  uint32_t /* width from decompiler */ uStack_8;

  int local_4;

  

  iVar1 = param_1;

  piVar2 = (int *)CVOGReaction_ResolveObjectTarget

                            (CONCAT31((int3)((uint)*(uint32_t /* width from decompiler */ *)(param_1 + 0x14) >> 8),

                                      *(uint8_t *)(param_1 + 0x18)),

                             *(uint32_t /* width from decompiler */ *)(param_1 + 0x10),*(uint32_t /* width from decompiler */ *)(param_1 + 0x14));

  if ((piVar2 != (int *)0x0) && (*(char *)(iVar1 + 0x21) != -1)) {

    local_4 = 0;

    do {

      iVar4 = local_4;

      if (local_4 == 0) {

        iVar3 = (**(code **)(*piVar2 + 0x210))(0);

        if (iVar3 != 0) {

          iVar4 = (**(code **)(*piVar2 + 0x210))(0);

LAB_0080bb1c:

          iVar3 = *(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xb4 + iVar4);

          iVar4 = local_4;

          if (iVar3 != 0) {

            uStack_8 = 0;

            FUN_004294f0();

            FUN_004022a0(&uStack_8,&param_1);

            while (param_1 != 0) {

              if (((*(int *)(param_1 + 0x1c) == 1) &&

                  (iVar4 = __RTDynamicCast(param_1,0,&CVOGHBBase::RTTI_Type_Descriptor,

                                           &CVOGHBSkillBase::RTTI_Type_Descriptor,0), iVar4 != 0))

                 && (*(uint *)(iVar4 + 0x620) == (uint)*(ushort *)(iVar1 + 0xc))) {

                if (*(char *)(iVar3 + 0x28) == '\0') {

                  return;

                }

                *(uint8_t *)(iVar3 + 0x28) = 0;

                LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 4));

                return;

              }

              FUN_004022a0(&uStack_8,&param_1);

            }

            iVar4 = local_4;

            if (*(char *)(iVar3 + 0x28) != '\0') {

              *(uint8_t *)(iVar3 + 0x28) = 0;

              LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 4));

              iVar4 = local_4;

            }

          }

        }

      }

      else if (((local_4 == 1) && (iVar3 = (**(code **)(*piVar2 + 0x210))(0), iVar3 != 0)) &&

              (iVar3 = (**(code **)(*piVar2 + 0x210))(0), *(int *)(iVar3 + 0x250) != 0)) {

        iVar4 = (**(code **)(*piVar2 + 0x210))(0);

        iVar4 = *(int *)(iVar4 + 0x250);

        goto LAB_0080bb1c;

      }

      local_4 = iVar4 + 1;

    } while (local_4 < 2);

    piVar5 = (int *)FUN_00418820(*(uint8_t *)(iVar1 + 0x21));

    pAction = (CVOGHBBase *)(**(code **)(*piVar5 + 0x48))();

    (**(code **)((int)pAction->pVTable + 0x24))(iVar1,piVar2);

    CVOGHBList_Enqueue(*(void **)(piVar2[0x29] + 0xe4ec),pAction);

  }

  return;

}
