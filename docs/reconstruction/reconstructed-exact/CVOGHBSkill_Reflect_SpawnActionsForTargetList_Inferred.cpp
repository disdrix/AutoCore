// =============================================================================
// CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred  (FUN_00617fc0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00617fc0
// Address:   0x00617fc0  (autoassault.exe, image base 0x400000)
// Body:      0x00617fc0 – 0x006180fb inclusive (316 B / 0x13C)
// System:    skills-abilities
// Generated: 2026-08-05 R12-039 dual seal
//   (decompile_function + analyze_function_complete + disassemble_function +
//    read_memory + callers/xrefs + RTTI COL walk)
//
// Class:     CVOGHBSkill_Reflect  (RTTI Confirmed ".?AVCVOGHBSkill_Reflect@@")
// Vtbl:      PTR_FUN_009d0f7c
// Slot:      this function @ vtbl +0x2c (DATA xref 0x009d0fa8)
// Size:      operator_new(0x6d0) per spawned action
//
// Purpose: Virtual multi-target factory for Reflect skill heartbeat actions.
//   Walk a 0x10-stride target descriptor list until terminator {-1,-1,type0}.
//   For each entry: ResolveObjectTarget → if vehicle type 0xe remap target to
//   vehicle host at COM +0xb0 → new via OnHit ctor → overwrite Reflect vtbl →
//   Enqueue/Start or scalar dtor.
//
// ABI:     six stack args; RET 0x18; EAX = 1 on terminator.
//          Virtual thiscall ECX is ignored by the body.
// Exactness: Behavior-preserving CF (live decompile + assembly).
// Bit-for-bit / runtime: OPEN. Terminal: false.
// Dual: reviews/A|B_aa_00617fc0_CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred.md
// =============================================================================

#include <cstdint>

struct TargetEntry16 {
  std::int32_t id0;   // +0
  std::int32_t id1;   // +4
  std::uint8_t type;  // +8  (ResolveObjectTarget char gate)
  // +9..+0xf unused by this unit
};

// Named callees (not dualled here except parent OnHit_ctor dual R11-012)
extern "C" void *__thiscall CVOGReaction_ResolveObjectTarget(
    void *pReaction, std::uint8_t type, std::uint32_t id0, std::uint32_t id1);
extern "C" void *__cdecl operator_new(std::uint32_t size);
extern "C" void *__thiscall CVOGHBSkill_OnHit_ctor(
    void *thisHb, void *pSourceObj, void *pSkillBlob, void *pWorld,
    void *pTarget, void *pTfid16, std::uint32_t arg7);
extern "C" void __thiscall CVOGHBList_Enqueue(void *pList, void *pAction);
extern "C" void __thiscall CVOGHBBase_Start(void *pAction);
extern "C" void *__cdecl __RTDynamicCast(void *in, long vfDelta, void *srcTd,
                                         void *targetTd, int isRef);

// RTTI type descriptors used by vehicle branch
extern "C" void CVOGClonedObjectBase_RTTI_Type_Descriptor;
extern "C" void CVOGVehicle_RTTI_Type_Descriptor;

// Reflect vtbl in .rdata — COL 0x00aadc14 → type_info 0x00af28f4
extern "C" void *PTR_FUN_009d0f7c;

// Layout notes on spawned action (after OnHit ctor + Reflect vtbl overwrite):
//   +0x00  pVTable → PTR_FUN_009d0f7c
//   +0x18  pOwnerObject (null ⇒ ValidateTarget reject / no attach)
//   +0x6c0 int  period ms (seeded inside OnHit_ctor from skill float +0x4c)
//   +0x6c4 u8   period-enable flag
// Object size 0x6d0

extern "C" std::uint32_t __stdcall
CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred(
    void *pSourceObj, void *pSkillBlob, void *pWorld, TargetEntry16 *pList,
    void *pTfid16, std::uint32_t arg7)
{
  // SEH frame LAB_009a86cb omitted (behavior-preserving control flow only)
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
      // Clone-base type field: *(target+0xa8)+0x38 == 0x0e → vehicle
      void *pCloneBase = *reinterpret_cast<void **>(
          reinterpret_cast<char *>(pTarget) + 0xa8);
      if (*reinterpret_cast<std::int32_t *>(
              reinterpret_cast<char *>(pCloneBase) + 0x38) == 0xe) {
        void *pVeh = __RTDynamicCast(
            pTarget, 0, &CVOGClonedObjectBase_RTTI_Type_Descriptor,
            &CVOGVehicle_RTTI_Type_Descriptor, 0);
        // Vehicle COM host chain (family +0xb0 gate):
        //   wobj = *(*(*(veh+4)+4) + veh + 0xb0)
        // Retail does not null-check cast result (UB if cast fails).
        void *p0 = *reinterpret_cast<void **>(
            reinterpret_cast<char *>(pVeh) + 4);
        void *p1 = *reinterpret_cast<void **>(
            reinterpret_cast<char *>(p0) + 4);
        pTarget = *reinterpret_cast<void **>(
            reinterpret_cast<char *>(p1) +
            reinterpret_cast<std::uintptr_t>(pVeh) + 0xb0);
      }

      auto *pAction = static_cast<std::uint32_t *>(operator_new(0x6d0));
      // SEH construct scope = 0
      if (pAction != nullptr) {
        // Parent dual R11-012: OnHit intermediate ctor (vtbl + period)
        CVOGHBSkill_OnHit_ctor(pAction, pSourceObj, pSkillBlob, pWorld,
                               pTarget, pTfid16, arg7);
        // Overwrite OnHit vtbl with Reflect product vtbl
        *pAction = reinterpret_cast<std::uint32_t>(&PTR_FUN_009d0f7c);
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
extern "C" std::uint32_t __stdcall FUN_00617fc0(
    void *p1, void *p2, void *p3, TargetEntry16 *p4, void *p5,
    std::uint32_t p6)
{
  return CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred(p1, p2, p3, p4,
                                                                p5, p6);
}
