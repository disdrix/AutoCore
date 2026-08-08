// =============================================================================
// FUN_0061c590  /  CVOGHBSkill_XP_ApplyToTargetList_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0061c590
// Address:   0x0061c590–0x0061c6af  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-08-05 R11-015 (scaffold twin; named clean is primary)
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte fixups.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Multi-target arm of CVOGHBSkill_XP — resolve TFID rows, spawn 0x6c0
// skill HBs with XP vtbl, Enqueue+Start or dtor. See named clean for types.

// READABILITY:
//  - Body size: 288 B; ret 0x18; return 1.
//  - Notable callees: CVOGHBSkillBase_ctor, CVOGReaction_ResolveObjectTarget,
//    CVOGHBBase_SetPeriodAndCounter, CVOGHBList_Enqueue, CVOGHBBase_Start.
//  - RTTI: .?AVCVOGHBSkill_XP@@ via COL 0x00aade00 / type_info 0x00af29ec.

/*
 * Behavioral notes:
 * - ResolveObjectTarget this = *(param_3 + 0xe4e8) (bytes; decompiler omit).
 * - Child vtbl PTR_FUN_009d119c; period -1000/true after blob[+0x1c]→HB[+0x08].
 * - Sole inbound xref: DATA vtbl+0x2C @ 0x009d11c8.
 * - Runtime / differential verification: OPEN.
 */

#include <cstdint>

struct CVOGHBBase;

extern "C" {
void *operator_new(unsigned size);
void *CVOGReaction_ResolveObjectTarget(void *ctx, unsigned char bGlobal,
                                       unsigned coidLo, unsigned coidHi);
// Ghidra may still show FUN_005788d0 — sealed name CVOGHBSkillBase_ctor
CVOGHBBase *CVOGHBSkillBase_ctor(CVOGHBBase *self, void *pSourceObj,
                                 void *pSkillBlob, void *pWorld, void *pTarget,
                                 void *pTfid16, unsigned arg7);
void CVOGHBBase_SetPeriodAndCounter(CVOGHBBase *self, int nPeriodSentinel,
                                    int bAlsoSetCounter);
void CVOGHBList_Enqueue(void *list, CVOGHBBase *action);
void CVOGHBBase_Start(CVOGHBBase *action);
}

extern "C" void *PTR_FUN_009d119c[];

struct CVOGHBBase {
  void **pVTable;
};

using code = void (*)();

std::uint32_t FUN_0061c590(void *param_1, int param_2, int param_3, int param_4,
                           void *param_5, std::uint32_t param_6) {
  int *piVar1;
  int iVar2;
  CVOGHBBase *pAction;
  char local_d;

  local_d = '\0';

LAB_0061c5c0:
  do {
    piVar1 = reinterpret_cast<int *>(local_d * 0x10 + param_4);
    if (((*piVar1 == -1) && (piVar1[1] == -1)) &&
        (reinterpret_cast<char *>(piVar1)[8] == '\0')) {
      return 1;
    }

    // Byte fixup: thiscall ECX = *(param_3 + 0xe4e8)
    void *resolveCtx =
        *reinterpret_cast<void **>(reinterpret_cast<char *>(param_3) + 0xe4e8);
    iVar2 = reinterpret_cast<int>(CVOGReaction_ResolveObjectTarget(
        resolveCtx, static_cast<unsigned char>(reinterpret_cast<char *>(piVar1)[8]),
        static_cast<unsigned>(*piVar1), static_cast<unsigned>(piVar1[1])));

    if (iVar2 != 0) {
      pAction = static_cast<CVOGHBBase *>(operator_new(0x6c0));
      if (pAction == nullptr) {
        pAction = nullptr;
      } else {
        CVOGHBSkillBase_ctor(pAction, param_1,
                             reinterpret_cast<void *>(param_2),
                             reinterpret_cast<void *>(param_3),
                             reinterpret_cast<void *>(iVar2), param_5, param_6);
        pAction->pVTable = PTR_FUN_009d119c;
        *reinterpret_cast<int *>(reinterpret_cast<char *>(pAction) + 0x08) =
            *reinterpret_cast<int *>(reinterpret_cast<char *>(param_2) + 0x1c);
        CVOGHBBase_SetPeriodAndCounter(pAction, -1000, 1);
      }
      if (*reinterpret_cast<void **>(reinterpret_cast<char *>(pAction) + 0x18) !=
          nullptr) {
        CVOGHBList_Enqueue(
            *reinterpret_cast<void **>(reinterpret_cast<char *>(param_3) + 0xe4ec),
            pAction);
        CVOGHBBase_Start(pAction);
        local_d = static_cast<char>(local_d + 1);
        goto LAB_0061c5c0;
      }
      // vtbl[0](1) scalar deleting dtor
      reinterpret_cast<void(__thiscall *)(CVOGHBBase *, int)>(pAction->pVTable[0])(
          pAction, 1);
    }
    local_d = static_cast<char>(local_d + 1);
  } while (true);
}
