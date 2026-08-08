// =============================================================================
// FUN_00621f50  (scaffold twin of CVOGHBSkill_HitCharge_Execute_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00621f50
// Address:   0x00621f50 – 0x0062205d  (autoassault.exe, image base 0x400000)
// Size:      0x10E (270 bytes); terminal ret 0x18
// System:    skills-abilities
// Preferred: CVOGHBSkill_HitCharge_Execute_Inferred
// Generated: 2026-08-05 R12-005 dual seal (raw 2026-07-23 + live re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

#include <cstdint>

struct CVOGHBBase {
  void *pVTable;
  void *pOwnerObject; // +0x18
};

extern "C" {
void *CVOGReaction_ResolveObjectTarget(void *ctx, unsigned char bGlobal,
                                       uint32_t coidLo, uint32_t coidHi);
CVOGHBBase *FUN_00621350(CVOGHBBase *self, void *pSourceObj, void *pSkillBlob,
                         void *arg4, void *pTarget, void *pTfid16,
                         uint32_t arg7);
void CVOGHBList_Enqueue(void *list, CVOGHBBase *action);
void CVOGHBBase_Start(CVOGHBBase *action);
void *operator_new(uint32_t size);
extern void *PTR_FUN_009d1624;
}

using del_dtor_fn = void(__thiscall *)(CVOGHBBase *self, int do_delete);

uint32_t FUN_00621f50(void *param_1, void *param_2, int param_3, int param_4,
                      void *param_5, uint32_t param_6) {
  char local_d = 0;

  for (;;) {
    int *piVar1 = reinterpret_cast<int *>(param_4 + local_d * 0x10);

    if (piVar1[0] == -1 && piVar1[1] == -1 &&
        *reinterpret_cast<char *>(&piVar1[2]) == 0) {
      return 1;
    }

    void *resolveCtx = *reinterpret_cast<void **>(param_3 + 0xe4e8);
    unsigned char bGlobal =
        *reinterpret_cast<unsigned char *>(reinterpret_cast<char *>(piVar1) + 8);
    int iVar2 = reinterpret_cast<int>(CVOGReaction_ResolveObjectTarget(
        resolveCtx, bGlobal, static_cast<uint32_t>(piVar1[0]),
        static_cast<uint32_t>(piVar1[1])));

    if (iVar2 != 0) {
      auto *pAction = static_cast<CVOGHBBase *>(operator_new(0x6d0));
      if (pAction != nullptr) {
        FUN_00621350(pAction, param_1, param_2,
                     reinterpret_cast<void *>(param_3),
                     reinterpret_cast<void *>(iVar2), param_5, param_6);
        pAction->pVTable = &PTR_FUN_009d1624;
        *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(pAction) + 0x6c0) =
            0;
        *reinterpret_cast<float *>(reinterpret_cast<char *>(pAction) + 0x6c4) =
            0.0f;
      }

      if (pAction->pOwnerObject != nullptr) {
        void *hbList = *reinterpret_cast<void **>(param_3 + 0xe4ec);
        CVOGHBList_Enqueue(hbList, pAction);
        CVOGHBBase_Start(pAction);
      } else {
        auto dtor = *reinterpret_cast<del_dtor_fn *>(pAction->pVTable);
        dtor(pAction, 1);
      }
    }

    local_d = static_cast<char>(local_d + 1);
  }
}
