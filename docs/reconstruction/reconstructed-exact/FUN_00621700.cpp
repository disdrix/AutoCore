// =============================================================================
// FUN_00621700  (scaffold twin → CVOGHBSkill_OnDoHit_Execute_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00621700
// Address:   0x00621700  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 scaffold; refined 2026-08-05 R11-018 dual
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// Canonical: reconstructed-exact/CVOGHBSkill_OnDoHit_Execute_Inferred.cpp
// =============================================================================

// PURPOSE: CVOGHBSkill_OnDoHit vtbl+0x2C multi-target arm — resolve TFID table
// entries, construct 0x6c0 OnDoHit HBs, Enqueue+Start (or dtor on no owner).
// Class RTTI Confirmed: .?AVCVOGHBSkill_OnDoHit@@
// ABI: six stack args, ret 0x18, return 1; ECX unused.

#include <cstdint>

struct CVOGHBBase {
  void *pVTable;
  char _pad[0x14];
  void *pOwnerObject; // +0x18
};

extern "C" {
void *CVOGReaction_ResolveObjectTarget(void *ctx, unsigned char bGlobal,
                                       uint32_t coidLo, uint32_t coidHi);
void *CVOGHBSkillBase_ctor(void *self, void *a, void *b, void *c, void *d,
                           void *e, void *f);
void CVOGHBList_Enqueue(void *list, void *action);
void CVOGHBBase_Start(void *action);
void *operator_new(uint32_t size);
extern void *PTR_FUN_009d15c4;
}

uint32_t FUN_00621700(void *param_1, void *param_2, int param_3, int param_4,
                      void *param_5, void *param_6)
{
  int *piVar1;
  void *iVar2;
  CVOGHBBase *pAction;
  char local_d = 0;

  // SEH frame (LAB_009a891b) omitted

  for (;;) {
    piVar1 = reinterpret_cast<int *>(local_d * 0x10 + param_4);
    if (((*piVar1 == -1) && (piVar1[1] == -1)) &&
        (static_cast<char>(piVar1[2]) == '\0')) {
      return 1;
    }

    // Image: ECX = *(param_3 + 0xe4e8); stack bGlobal/coidLo/coidHi
    iVar2 = CVOGReaction_ResolveObjectTarget(
        *reinterpret_cast<void **>(param_3 + 0xe4e8),
        *reinterpret_cast<unsigned char *>(reinterpret_cast<char *>(piVar1) + 8),
        static_cast<uint32_t>(*piVar1),
        static_cast<uint32_t>(piVar1[1]));

    if (iVar2 != nullptr) {
      pAction = static_cast<CVOGHBBase *>(operator_new(0x6c0));
      if (pAction != nullptr) {
        CVOGHBSkillBase_ctor(pAction, param_1, param_2,
                             reinterpret_cast<void *>(param_3), iVar2, param_5,
                             param_6);
        pAction->pVTable = &PTR_FUN_009d15c4;
      }

      if (pAction->pOwnerObject != nullptr) {
        CVOGHBList_Enqueue(*reinterpret_cast<void **>(param_3 + 0xe4ec),
                           pAction);
        CVOGHBBase_Start(pAction);
      } else {
        (*reinterpret_cast<void(__thiscall **)(CVOGHBBase *, int)>(
            pAction->pVTable))(pAction, 1);
      }
    }
    local_d = static_cast<char>(local_d + 1);
  }
}
