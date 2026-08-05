// =============================================================================
// FUN_004de760  (alias of CVOGReaction_ScanPendingDeliverAndRegisterLinks_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004de760
// Address:   0x004de760–0x004de9e6  (autoassault.exe, image base 0x400000)
// System:    missions-progression / object-hash links
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W23-M)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - __thiscall: ECX = host*; stack character*, optionalObject*; ret 8.
 * - Locks character+0x55c TraversalLock; walks pending objectives.
 * - Deliver type 3 + RTTI cast; match host+0xfc / deliver[7]; object +0x34 / deliver[6].
 * - FUN_004dbef0 modes 5 (predicate fail) / 8 (pass).
 * - Named: CVOGReaction_ScanPendingDeliverAndRegisterLinks_Inferred.
 * - NOT an RTTI type descriptor (false coverage alias).
 */

#include <cstdint>

extern "C" void FUN_007a4480(int, const char *, ...);
extern "C" void *__RTDynamicCast(void *, long, void *, void *, int);
extern "C" void FUN_004dbef0(void *, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t);
extern "C" void CVOGObjectiveRequirement_RTTI_Type_Descriptor;
extern "C" void CVOGObjectiveRequirement_Deliver_RTTI_Type_Descriptor;

void __thiscall FUN_004de760(int param_1 /*host ECX*/, unsigned int param_2 /*character*/, int param_3 /*opt object*/)
{
  int iVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  std::uint32_t uVar8;
  std::uint32_t uVar9;
  int local_8;

  iVar1 = (int)param_2;
  iVar7 = *(int *)(param_2 + 0x55c);
  local_8 = 0;
  if (*(char *)(iVar7 + 0x1d) != '\0') {
    FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  *(std::uint8_t *)(iVar7 + 0x1d) = 1;
  iVar7 = param_3;
  do {
    iVar5 = *(int *)(iVar1 + 0x55c);
    if (*(char *)(iVar5 + 0x1d) == '\0') {
      FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0, "VOG_DEBUG_STOP");
    }
    if (local_8 == 0) {
      local_8 = *(int *)(iVar5 + 0x14);
      if (local_8 == 0)
        goto LAB_004de7eb;
      piVar3 = *(int **)(local_8 + 8);
    } else {
      local_8 = *(int *)(local_8 + 0x14);
      if (local_8 == 0) {
      LAB_004de7eb:
        piVar3 = (int *)0x0;
      } else {
        piVar3 = *(int **)(local_8 + 8);
      }
    }
    if (piVar3 == (int *)0x0) {
      *(std::uint8_t *)(*(int *)(iVar1 + 0x55c) + 0x1d) = 0;
      return;
    }
    param_3 = 0;
    while (true) {
      iVar5 = *piVar3;
      if (*(int *)(iVar5 + 0x158) == 0) {
        iVar4 = 0;
      } else {
        iVar4 = *(int *)(iVar5 + 0x15c) - *(int *)(iVar5 + 0x158) >> 2;
      }
      if (iVar4 <= param_3)
        break;
      piVar6 = *(int **)(*(int *)(iVar5 + 0x158) + param_3 * 4);
      iVar5 = (**(int(__thiscall ***)(int *))(*piVar6 + 0x50))(piVar6);
      if ((iVar5 == 3) &&
          (piVar6 = (int *)__RTDynamicCast(
               piVar6, 0, &CVOGObjectiveRequirement_RTTI_Type_Descriptor,
               &CVOGObjectiveRequirement_Deliver_RTTI_Type_Descriptor, 0),
           piVar6[7] == *(int *)(param_1 + 0xfc))) {
        if (iVar7 == 0) {
          param_2 = 0;
          while (true) {
            iVar5 = *(int *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xa8 + iVar1) + 0xe4e8);
            if ((*(int *)(iVar5 + 0x2c) == 0) ||
                ((unsigned)(*(int *)(iVar5 + 0x30) - *(int *)(iVar5 + 0x2c) >> 2) <= param_2))
              break;
            iVar7 = (**(int(__thiscall ***)(int *))(
                **(int **)(*(int *)(iVar5 + 0x2c) + param_2 * 4) + 0x1d8))(
                *(int **)(*(int *)(iVar5 + 0x2c) + param_2 * 4));
            if ((iVar7 == 0) ||
                (*(int *)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 0xac + iVar7) + 0x34) !=
                 piVar6[6])) {
            LAB_004de94d:
              param_2 = param_2 + 1;
            } else {
              cVar2 = (**(char(__thiscall ***)(int *, int, int *))(*piVar6 + 0xc))(
                  piVar6, iVar1, piVar3);
              if (cVar2 == '\0') {
                FUN_004dbef0(
                    (void *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7), 5, 0xffffffffu,
                    0xffffffffu, *(std::uint32_t *)(*piVar3 + 0x10));
                goto LAB_004de94d;
              }
              FUN_004dbef0((void *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7), 8, 0xffffffffu,
                           0xffffffffu, *(std::uint32_t *)(*piVar3 + 0x10));
              param_2 = param_2 + 1;
            }
          }
        } else if (*(int *)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 0xac + iVar7) + 0x34) ==
                   piVar6[6]) {
          cVar2 = (**(char(__thiscall ***)(int *, int, int *))(*piVar6 + 0xc))(
              piVar6, iVar1, piVar3);
          if (cVar2 == '\0') {
            iVar5 = *(int *)(*(int *)(iVar7 + 4) + 4);
            uVar9 = *(std::uint32_t *)(*piVar3 + 0x10);
            uVar8 = 5;
          } else {
            iVar5 = *(int *)(*(int *)(iVar7 + 4) + 4);
            uVar9 = *(std::uint32_t *)(*piVar3 + 0x10);
            uVar8 = 8;
          }
          FUN_004dbef0((void *)(iVar5 + 4 + iVar7), uVar8, 0xffffffffu, 0xffffffffu, uVar9);
        }
      }
      param_3 = param_3 + 1;
    }
  } while (true);
}
