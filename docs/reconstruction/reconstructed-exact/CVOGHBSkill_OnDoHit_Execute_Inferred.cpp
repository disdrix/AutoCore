// =============================================================================
// CVOGHBSkill_OnDoHit_Execute_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00621700
// Address:   0x00621700 – 0x00621807  (autoassault.exe, image base 0x400000)
// Size:      0x108 (264 bytes); terminal ret 0x18
// System:    skills-abilities
// Class:     CVOGHBSkill_OnDoHit  (RTTI Confirmed: .?AVCVOGHBSkill_OnDoHit@@)
// Vtbl:      PTR_FUN_009d15c4 + 0x2C @ 0x009d15f0
// Generated: 2026-08-05 R11-018 dual (raw 2026-07-23 + live re-verify)
// Exactness: Behavior-preserving rewrite of decompiler/assembly control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   CVOGHBSkill_OnDoHit virtual slot +0x2C: walk a TFID target table (stride
//   0x10), resolve each entry, and for every live target allocate a 0x6c0
//   OnDoHit skill HB (base CVOGHBSkillBase_ctor + subclass vtbl), then
//   Enqueue+Start on world HB list — or deleting-dtor if owner attach failed.
//
// ABI:
//   Six stack formals; ret 0x18; return 1 on sentinel. ECX (this) unused.
//
// NOT the subclass ctor (that is FUN_00621350 / inlined here as base+vtbl).
// =============================================================================

#include <cstdint>

// External symbols (image names / dualed peers)
struct CVOGHBBase {
  void *pVTable;          // +0x00
  // ...
  void *pOwnerObject;     // +0x18
};

extern "C" {
void *CVOGReaction_ResolveObjectTarget(void *ctx, unsigned char bGlobal,
                                       uint32_t coidLo, uint32_t coidHi);
CVOGHBBase *CVOGHBSkillBase_ctor(CVOGHBBase *self, void *pSourceObj,
                                 void *pSkillBlob, void *arg4, void *pTarget,
                                 void *pTfid16, uint32_t arg7);
void CVOGHBList_Enqueue(void *list, CVOGHBBase *action);
void CVOGHBBase_Start(CVOGHBBase *action);
void *operator_new(uint32_t size);
extern void *PTR_FUN_009d15c4; // CVOGHBSkill_OnDoHit vtbl
}

using del_dtor_fn = void(__thiscall *)(CVOGHBBase *self, int do_delete);

uint32_t CVOGHBSkill_OnDoHit_Execute_Inferred(
    void *pSourceObj,   // stack+0x04
    void *pSkillBlob,   // stack+0x08
    int pWorldCtx,      // stack+0x0C  — +0xe4e8 resolve, +0xe4ec HB list
    int pTargetTable,   // stack+0x10  — TFID entries, stride 0x10
    void *pTfid16,      // stack+0x14
    uint32_t arg7)      // stack+0x18
{
  // SEH: LAB_009a891b (omitted in clean; present in image)
  char index = 0;

  for (;;) {
    int *entry = reinterpret_cast<int *>(pTargetTable + index * 0x10);

    // Sentinel: coidLo==-1 && coidHi==-1 && bGlobal==0
    if (entry[0] == -1 && entry[1] == -1 &&
        *reinterpret_cast<char *>(&entry[2]) == 0) {
      return 1;
    }

    void *resolveCtx = *reinterpret_cast<void **>(pWorldCtx + 0xe4e8);
    unsigned char bGlobal =
        *reinterpret_cast<unsigned char *>(reinterpret_cast<char *>(entry) + 8);
    void *target = CVOGReaction_ResolveObjectTarget(
        resolveCtx, bGlobal,
        static_cast<uint32_t>(entry[0]),
        static_cast<uint32_t>(entry[1]));

    if (target != nullptr) {
      auto *pAction = static_cast<CVOGHBBase *>(operator_new(0x6c0));
      if (pAction != nullptr) {
        CVOGHBSkillBase_ctor(pAction, pSourceObj, pSkillBlob,
                             reinterpret_cast<void *>(pWorldCtx), target,
                             pTfid16, arg7);
        pAction->pVTable = &PTR_FUN_009d15c4;
      }

      // Base ctor accept path attaches owner at +0x18; reject leaves null
      if (pAction->pOwnerObject != nullptr) {
        void *hbList = *reinterpret_cast<void **>(pWorldCtx + 0xe4ec);
        CVOGHBList_Enqueue(hbList, pAction);
        CVOGHBBase_Start(pAction);
      } else {
        auto dtor = *reinterpret_cast<del_dtor_fn *>(pAction->pVTable);
        dtor(pAction, 1);
      }
    }

    index = static_cast<char>(index + 1);
  }
}
