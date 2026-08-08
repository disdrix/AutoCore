// =============================================================================
// FUN_006226a0  — twin of CVOGHBSkill_OnKill_SpawnPerTargetHB_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_006226a0
// Address:   0x006226a0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-08-05 R11-020 dual (refresh of 2026-07-23 scaffold)
// Exactness: Behavior-preserving; see named clean for typed plate.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: CVOGHBSkill_OnKill vtbl+0x2c multi-target HB fanout.
// RTTI: .?AVCVOGHBSkill_OnKill@@  (COL 0x00aae288 → type_info 0x00af1dc8)
// Named clean: CVOGHBSkill_OnKill_SpawnPerTargetHB_Inferred.cpp

// READABILITY:
//  - Body: 0x006226a0–0x006227a7 (0x108 B); RET 0x18
//  - Loop over TargetEntry[i] stride 0x10 until sentinel (-1,-1,type0)
//  - Resolve via world+0xe4e8; new(0x6c0)+CVOGHBSkillBase_ctor+OnKill vtbl
//  - Owner → Enqueue(world+0xe4ec)+Start; else vtbl[0](1)
//  - Return 1 only at sentinel

#include <cstdint>

struct CVOGHBBase {
  void* pVTable;
  void* pOwnerObject; // +0x18
};

extern void* operator_new(unsigned);
extern CVOGHBBase* CVOGHBSkillBase_ctor(CVOGHBBase*, void*, void*, void*, void*, uint32_t*, uint32_t);
extern void* __thiscall CVOGReaction_ResolveObjectTarget(void*, char, uint32_t, uint32_t);
extern unsigned CVOGHBList_Enqueue(void*, CVOGHBBase*);
extern void CVOGHBBase_Start(CVOGHBBase*);
extern void* PTR_FUN_009d16e4[];

uint32_t __thiscall FUN_006226a0(
    void* /*this_unused*/,
    void* param_1,
    void* param_2,
    void* param_3,
    int param_4,
    uint32_t* param_5,
    uint32_t param_6)
{
  char local_d = 0;
  // SEH omitted

  for (;;) {
    int* piVar1 = reinterpret_cast<int*>(local_d * 0x10 + param_4);
    if (piVar1[0] == -1 && piVar1[1] == -1 &&
        *reinterpret_cast<char*>(reinterpret_cast<char*>(piVar1) + 8) == 0) {
      return 1;
    }

    void* reaction = *reinterpret_cast<void**>(
        reinterpret_cast<char*>(param_3) + 0xe4e8);
    char type = *reinterpret_cast<char*>(reinterpret_cast<char*>(piVar1) + 8);
    int iVar2 = reinterpret_cast<int>(CVOGReaction_ResolveObjectTarget(
        reaction, type,
        static_cast<uint32_t>(piVar1[0]),
        static_cast<uint32_t>(piVar1[1])));

    if (iVar2 != 0) {
      CVOGHBBase* pAction = static_cast<CVOGHBBase*>(operator_new(0x6c0));
      if (pAction != nullptr) {
        CVOGHBSkillBase_ctor(pAction, param_1, param_2, param_3,
                             reinterpret_cast<void*>(iVar2), param_5, param_6);
        pAction->pVTable = &PTR_FUN_009d16e4[0];
      }
      if (pAction->pOwnerObject != nullptr) {
        CVOGHBList_Enqueue(
            *reinterpret_cast<void**>(reinterpret_cast<char*>(param_3) + 0xe4ec),
            pAction);
        CVOGHBBase_Start(pAction);
      } else {
        auto** vt = reinterpret_cast<void**>(pAction->pVTable);
        using DtorFn = void(__thiscall*)(CVOGHBBase*, int);
        reinterpret_cast<DtorFn>(vt[0])(pAction, 1);
      }
    }
    local_d = static_cast<char>(local_d + 1);
  }
}
