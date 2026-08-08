// =============================================================================
// CVOGHBSkill_OnKill_SpawnPerTargetHB_Inferred  (FUN_006226a0)
// -----------------------------------------------------------------------------
// Stable ID: aa_006226a0
// Address:   0x006226a0 – 0x006227a7  (autoassault.exe, image base 0x400000)
// Size:      0x108 (264 B); epilogue RET 0x18
// System:    skills-abilities
// Class:     CVOGHBSkill_OnKill  (RTTI Confirmed: .?AVCVOGHBSkill_OnKill@@)
// Vtbl:      PTR_FUN_009d16e4 + 0x2c  (DATA @ 0x009d1710)
// Generated: 2026-08-05 R11-020 dual (decompile + disassemble_function + read_memory + RTTI)
// Exactness: Behavior-preserving rewrite of decompiler CF with asm-sealed ABI fixes.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Virtual multi-target fanout for CVOGHBSkill_OnKill: walk a 0x10-stride
//   target table, resolve each TFID via CVOGReaction @ world+0xe4e8, allocate
//   a 0x6c0 skill HB, run CVOGHBSkillBase_ctor with resolved target, install
//   OnKill vtbl, then Enqueue+Start on world+0xe4ec (or scalar-delete if no
//   owner after ValidateTarget reject). Sentinel (-1,-1,type0) → return 1.
//
// ABI (sealed)
//   uint32_t __thiscall (ECX=this unused, 6 stack args) → always 1 at sentinel
//   RET 0x18
//
// STRINGS / RTTI
//   ".?AVCVOGHBSkill_OnKill@@" @ type_info 0x00af1dc8 (COL 0x00aae288)
//

#include <cstdint>

struct CVOGHBBase {
  void* pVTable;       // +0x00
  // ...
  void* pOwnerObject;  // +0x18
};

struct TargetEntry {
  int32_t idLo;   // +0
  int32_t idHi;   // +4
  int8_t  type;   // +8
  // pad to 0x10
};

extern "C" void* operator_new(unsigned int);
extern "C" CVOGHBBase* CVOGHBSkillBase_ctor(
    CVOGHBBase* self,
    void* pSourceObj,
    void* pSkillBlob,
    void* pWorldOrArg4,
    void* pTarget,
    uint32_t* pTfid16,
    uint32_t arg7);
extern "C" void* __thiscall CVOGReaction_ResolveObjectTarget(
    void* reactionThis,
    char type,
    uint32_t idLo,
    uint32_t idHi);
extern "C" unsigned CVOGHBList_Enqueue(void* list, CVOGHBBase* action);
extern "C" void CVOGHBBase_Start(CVOGHBBase* action);

// OnKill vtbl base (slot 0 = scalar dtor)
extern "C" void* PTR_FUN_009d16e4[];

// -----------------------------------------------------------------------------
uint32_t __thiscall CVOGHBSkill_OnKill_SpawnPerTargetHB_Inferred(
    void* /*this_unused*/,
    void* pSourceObj,
    void* pSkillBlob,
    void* pWorld,
    TargetEntry* pTargetTable,
    uint32_t* pTfid16,
    uint32_t arg7)
{
  // SEH: LAB_009a897b (omitted)
  char index = 0;

  for (;;) {
    TargetEntry* entry =
        reinterpret_cast<TargetEntry*>(
            reinterpret_cast<char*>(pTargetTable) + (index * 0x10));

    if (entry->idLo == -1 && entry->idHi == -1 && entry->type == 0) {
      return 1;
    }

    void* reaction = *reinterpret_cast<void**>(
        reinterpret_cast<char*>(pWorld) + 0xe4e8);
    void* resolved = CVOGReaction_ResolveObjectTarget(
        reaction, entry->type,
        static_cast<uint32_t>(entry->idLo),
        static_cast<uint32_t>(entry->idHi));

    if (resolved != nullptr) {
      auto* pAction = static_cast<CVOGHBBase*>(operator_new(0x6c0));
      if (pAction != nullptr) {
        CVOGHBSkillBase_ctor(pAction, pSourceObj, pSkillBlob, pWorld,
                             resolved, pTfid16, arg7);
        pAction->pVTable = &PTR_FUN_009d16e4[0];
      }
      // retail: null new is unreachable; would fault on +0x18 load
      if (pAction->pOwnerObject != nullptr) {
        void* list = *reinterpret_cast<void**>(
            reinterpret_cast<char*>(pWorld) + 0xe4ec);
        CVOGHBList_Enqueue(list, pAction);
        CVOGHBBase_Start(pAction);
      } else {
        auto** vt = reinterpret_cast<void**>(pAction->pVTable);
        using DtorFn = void(__thiscall*)(CVOGHBBase*, int);
        reinterpret_cast<DtorFn>(vt[0])(pAction, 1);
      }
    }
    index = static_cast<char>(index + 1);
  }
}
