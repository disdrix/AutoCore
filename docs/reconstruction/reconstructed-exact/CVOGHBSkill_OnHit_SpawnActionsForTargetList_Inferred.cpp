// =============================================================================
// CVOGHBSkill_OnHit_SpawnActionsForTargetList_Inferred  (FUN_00617df0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00617df0
// Address:   0x00617df0  (autoassault.exe, image base 0x400000)
// Body:      0x00617df0 – 0x00617f2c inclusive (317 B / 0x13D)
// System:    skills-abilities
// Generated: 2026-08-05 R11-013 dual seal
//   (decompile_function + disassemble_function + read_memory + RTTI COL walk)
//
// Class:     CVOGHBSkill_OnHit  (RTTI Confirmed ".?AVCVOGHBSkill_OnHit@@")
// Vtbl:      PTR_FUN_009d0f1c
// Slot:      this function @ vtbl +0x2c (DATA xref 0x009d0f48)
// Size:      operator_new(0x6d0) per spawned action
//
// Purpose: Virtual multi-target factory for OnHit skill heartbeat actions.
//   Walk a 0x10-stride target descriptor list until terminator {-1,-1,type0}.
//   For each entry: ResolveObjectTarget → new OnHit HB (base ctor + vtbl) →
//   optional period from skill float +0x4c → Enqueue/Start or scalar dtor.
//
// ABI:     six stack args; RET 0x18; EAX = 1 on terminator.
//          Virtual thiscall ECX is ignored by the body.
// Exactness: Behavior-preserving CF (live decompile + assembly).
// Bit-for-bit / runtime: OPEN. Terminal: false.
// =============================================================================

#include <cstdint>

struct TargetEntry16 {
  std::int32_t id0;   // +0
  std::int32_t id1;   // +4
  std::uint8_t type;  // +8  (ResolveObjectTarget char gate)
  // +9..+0xf unused by this unit
};

// Named callees (not dualled here)
extern "C" void *__thiscall CVOGReaction_ResolveObjectTarget(
    void *pReaction, std::uint8_t type, std::uint32_t id0, std::uint32_t id1);
extern "C" void *__cdecl operator_new(std::uint32_t size);
extern "C" void *__thiscall CVOGHBSkillBase_ctor(
    void *thisHb, void *pSourceObj, void *pSkillBlob, void *pWorld,
    void *pTarget, void *pTfid16, std::uint32_t arg7);
extern "C" void __thiscall CVOGHBList_Enqueue(void *pList, void *pAction);
extern "C" void __thiscall CVOGHBBase_Start(void *pAction);

// OnHit vtbl in .rdata — COL 0x00aadbc4 → type_info 0x00af1d60
extern "C" void *PTR_FUN_009d0f1c;
// g_flZero @ 0x00a0f518 == 0.0f
extern "C" float g_flZero;

// Layout notes on spawned action (after base + subclass touch):
//   +0x00  pVTable → PTR_FUN_009d0f1c
//   +0x18  pOwnerObject (null ⇒ ValidateTarget reject / no attach)
//   +0x6c0 int  period ms (from skill float +0x4c, trunc)
//   +0x6c4 u8   period-enable flag
// Object size 0x6d0

extern "C" std::uint32_t __stdcall
CVOGHBSkill_OnHit_SpawnActionsForTargetList_Inferred(
    void *pSourceObj, void *pSkillBlob, void *pWorld, TargetEntry16 *pList,
    void *pTfid16, std::uint32_t arg7)
{
  // SEH frame LAB_009a86ab omitted (behavior-preserving control flow only)
  std::uint8_t index = 0;

  for (;;) {
    auto *entry = reinterpret_cast<TargetEntry16 *>(
        reinterpret_cast<char *>(pList) + static_cast<std::uint32_t>(index) * 0x10u);

    if (entry->id0 == -1 && entry->id1 == -1 && entry->type == 0) {
      return 1;
    }

    void *pReaction = *reinterpret_cast<void **>(
        reinterpret_cast<char *>(pWorld) + 0xe4e8);
    void *pTarget = CVOGReaction_ResolveObjectTarget(
        pReaction, entry->type,
        static_cast<std::uint32_t>(entry->id0),
        static_cast<std::uint32_t>(entry->id1));

    if (pTarget != nullptr) {
      auto *pAction = static_cast<std::uint32_t *>(operator_new(0x6d0));
      // SEH construct scope = 0
      if (pAction != nullptr) {
        CVOGHBSkillBase_ctor(pAction, pSourceObj, pSkillBlob, pWorld, pTarget,
                             pTfid16, arg7);
        *pAction = reinterpret_cast<std::uint32_t>(&PTR_FUN_009d0f1c);

        float periodF =
            *reinterpret_cast<float *>(reinterpret_cast<char *>(pSkillBlob) + 0x4c);
        if (periodF == g_flZero) {
          *reinterpret_cast<std::uint8_t *>(
              reinterpret_cast<char *>(pAction) + 0x6c4) = 0;
        } else {
          *reinterpret_cast<std::uint8_t *>(
              reinterpret_cast<char *>(pAction) + 0x6c4) = 1;
          // CVTTSS2SI — trunc toward zero
          *reinterpret_cast<std::int32_t *>(
              reinterpret_cast<char *>(pAction) + 0x6c0) =
              static_cast<std::int32_t>(periodF);
        }
      }
      // SEH construct scope = -1

      // Retail path: null new → load [ESI+0x18] with ESI=0 (UB). Preserve order.
      void *pOwner =
          *reinterpret_cast<void **>(reinterpret_cast<char *>(pAction) + 0x18);
      if (pOwner != nullptr) {
        void *pHbList = *reinterpret_cast<void **>(
            reinterpret_cast<char *>(pWorld) + 0xe4ec);
        CVOGHBList_Enqueue(pHbList, pAction);
        CVOGHBBase_Start(pAction);
      } else {
        // vtbl[0] scalar-deleting dtor FUN_00651190(this, 1)
        auto **vtbl = reinterpret_cast<void **>(*pAction);
        using DtorFn = void *(__thiscall *)(void *, std::uint8_t);
        reinterpret_cast<DtorFn>(vtbl[0])(pAction, 1);
      }
    }

    index = static_cast<std::uint8_t>(index + 1);
  }
}

// Ghidra alias
extern "C" std::uint32_t __stdcall FUN_00617df0(
    void *p1, void *p2, void *p3, TargetEntry16 *p4, void *p5, std::uint32_t p6)
{
  return CVOGHBSkill_OnHit_SpawnActionsForTargetList_Inferred(p1, p2, p3, p4, p5,
                                                              p6);
}
