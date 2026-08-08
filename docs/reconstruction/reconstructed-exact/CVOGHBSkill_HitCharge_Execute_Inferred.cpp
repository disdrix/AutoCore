// =============================================================================
// CVOGHBSkill_HitCharge_Execute_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00621f50
// Address:   0x00621f50 – 0x0062205d  (autoassault.exe, image base 0x400000)
// Size:      0x10E (270 bytes); terminal ret 0x18
// System:    skills-abilities
// Class:     CVOGHBSkill_HitCharge  (RTTI Confirmed: .?AVCVOGHBSkill_HitCharge@@)
// Vtbl:      PTR_FUN_009d1624 + 0x2C @ 0x009d1650
// Parent:    CVOGHBSkill_OnDoHit_Ctor @ 0x00621350 (called per target)
// Generated: 2026-08-05 R12-005 dual (raw 2026-07-23 + live re-verify)
// Exactness: Behavior-preserving rewrite of decompiler/assembly control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   CVOGHBSkill_HitCharge virtual slot +0x2C: walk a TFID target table (stride
//   0x10), resolve each entry, and for every live target allocate a 0x6d0
//   HitCharge skill HB (OnDoHit ctor + HitCharge vtbl + tail zeros), then
//   Enqueue+Start on world HB list — or deleting-dtor if owner attach failed.
//
// ABI:
//   Six stack formals; ret 0x18; return 1 on sentinel. ECX (this) unused.
//
// NOT the OnDoHit subclass ctor (that is FUN_00621350 / called here).
// Distinct from OnDoHit execute FUN_00621700 (size 0x6c0, vtbl 009d15c4).
// =============================================================================

#include <cstdint>

// External symbols (image names / dualed peers)
struct CVOGHBBase {
  void *pVTable;          // +0x00
  // ...
  void *pOwnerObject;     // +0x18
  // HitCharge extends OnDoHit (0x6c0) with:
  //   +0x6c0 dword (zeroed here)
  //   +0x6c4 float (zeroed here)
  // object size 0x6d0
};

extern "C" {
void *CVOGReaction_ResolveObjectTarget(void *ctx, unsigned char bGlobal,
                                       uint32_t coidLo, uint32_t coidHi);
// Parent dual R11-017 — OnDoHit ctor (base + OnDoHit vtbl)
CVOGHBBase *CVOGHBSkill_OnDoHit_Ctor(CVOGHBBase *self, void *pSourceObj,
                                     void *pSkillBlob, void *arg4, void *pTarget,
                                     void *pTfid16, uint32_t arg7);
void CVOGHBList_Enqueue(void *list, CVOGHBBase *action);
void CVOGHBBase_Start(CVOGHBBase *action);
void *operator_new(uint32_t size);
extern void *PTR_FUN_009d1624; // CVOGHBSkill_HitCharge vtbl
}

using del_dtor_fn = void(__thiscall *)(CVOGHBBase *self, int do_delete);

uint32_t CVOGHBSkill_HitCharge_Execute_Inferred(
    void *pSourceObj,   // stack+0x04
    void *pSkillBlob,   // stack+0x08
    int pWorldCtx,      // stack+0x0C  — +0xe4e8 resolve, +0xe4ec HB list
    int pTargetTable,   // stack+0x10  — TFID entries, stride 0x10
    void *pTfid16,      // stack+0x14
    uint32_t arg7)      // stack+0x18
{
  // SEH: LAB_009a893b (omitted in clean; present in image)
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
      auto *pAction = static_cast<CVOGHBBase *>(operator_new(0x6d0));
      if (pAction != nullptr) {
        CVOGHBSkill_OnDoHit_Ctor(pAction, pSourceObj, pSkillBlob,
                                 reinterpret_cast<void *>(pWorldCtx), target,
                                 pTfid16, arg7);
        pAction->pVTable = &PTR_FUN_009d1624;
        *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(pAction) + 0x6c0) =
            0;
        *reinterpret_cast<float *>(reinterpret_cast<char *>(pAction) + 0x6c4) =
            0.0f;
      }

      // Parent/base accept path attaches owner at +0x18; reject leaves null
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
