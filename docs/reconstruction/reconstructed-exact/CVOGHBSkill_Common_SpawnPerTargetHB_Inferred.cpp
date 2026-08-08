// =============================================================================
// CVOGHBSkill_Common_SpawnPerTargetHB_Inferred  (FUN_006189d0)
// -----------------------------------------------------------------------------
// Stable ID: aa_006189d0
// Address:   0x006189d0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Class:     CVOGHBSkill_Common  (RTTI Confirmed ".?AVCVOGHBSkill_Common@@")
// Vtbl slot: PTR_FUN_009e1f2c + 0x2c  (DATA @ 0x009e1f58)
// Dual:      R12-040 OWN-ONLY 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler CF + byte seals.
//            Not modernization. Never Runtime Confirmed.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   CVOGHBSkill_Common virtual method at vtbl+0x2c: walk a 0x10-stride target
//   table, chance-gate each entry with a seeded RNG ushort slice, resolve the
//   TFID via world reaction object, allocate a 0x6d0 Common skill HB, construct
//   via CVOGHBSkill_Common_ctor(flag=0, scale=1.0f), Enqueue+Start (or scalar
//   delete if no owner), then fire combat events 0x14 (target) / 0x15 (source)
//   unless self-target. Sentinel {-1,-1,type0} frees the RNG table and returns
//   whether any HB was successfully started.

#include <cstdint>

struct CVOGHBBase;
struct CVOGHBSkill_Common;

extern "C" {
  std::uint32_t *Rng_CloneSeededTable_Inferred(std::uint32_t seedIndex); // 0x0058ab60
  std::uint32_t FUN_00589b80(float chance, std::uint16_t rngU16);
  void *CVOGReaction_ResolveObjectTarget(void *reactionThis, char type,
                                         int idLo, int idHi); // 0x004bae70 thiscall
  void *operator_new(std::size_t);
  void operator_delete__(void *);
  float CVOGReaction_RandomUnitScalar(std::uint32_t, int, float);
  std::uint16_t FUN_007a4120(void *rngThis, std::uint32_t index);
  CVOGHBBase *__thiscall CVOGHBSkill_Common_ctor(
      CVOGHBSkill_Common *self, void *pSource, void *pSkill, void *pWorld,
      void *pTarget, void *pTfid16, std::uint16_t arg7, std::uint8_t flag,
      float scale); // 0x00618180
  void CVOGHBList_Enqueue(void *list, CVOGHBBase *action); // 0x005078f0
  void CVOGHBBase_Start(CVOGHBBase *action);               // 0x005081c0
}

// Target table entry (stride 0x10) — structural
struct TargetEntry {
  int idLo;          // +0
  int idHi;          // +4
  char type;         // +8
  char pad[7];
};

// Retail: virtual; ECX = Common HB this (unused); 6 stack args; ret 0x18
// Returns true if at least one child Common HB was Enqueue+Start'd.
bool __thiscall CVOGHBSkill_Common_SpawnPerTargetHB_Inferred(
    CVOGHBSkill_Common * /*this_unused*/,
    int *source,      // param_1
    int skill,        // param_2 skill blob
    int world,        // param_3
    int table,        // param_4 TargetEntry*
    std::uint32_t tfid16, // param_5
    std::uint32_t seed)   // param_6
{
  void *seh_prev;
  int spawnCount = 0;
  // SEH frame omitted (LAB_009a871d)

  std::uint16_t *rngSlice =
      reinterpret_cast<std::uint16_t *>(Rng_CloneSeededTable_Inferred(seed));
  char index = 0;

  for (;;) {
    TargetEntry *e =
        reinterpret_cast<TargetEntry *>(table + static_cast<int>(index) * 0x10);

    if (e->idLo == -1 && e->idHi == -1 && e->type == 0) {
      if (rngSlice != nullptr)
        operator_delete__(rngSlice);
      return spawnCount != 0;
    }

    // Chance gate: non-zero → skip this table slot
    std::uint32_t gate = FUN_00589b80(
        *reinterpret_cast<float *>(skill + 0xe4),
        rngSlice[static_cast<int>(index)]);
    if (static_cast<char>(gate) != 0)
      goto next;

    // ResolveObjectTarget thiscall: ECX = *(world+0xe4e8)
    void *reaction = *reinterpret_cast<void **>(world + 0xe4e8);
    int *target = reinterpret_cast<int *>(CVOGReaction_ResolveObjectTarget(
        reaction, e->type, e->idLo, e->idHi));
    if (target == nullptr)
      goto next;

    CVOGHBBase *action = nullptr;
    void *mem = operator_new(0x6d0);
    if (mem == nullptr) {
      action = nullptr;
    } else {
      std::uint32_t u = rngSlice[static_cast<int>(index)];
      CVOGReaction_RandomUnitScalar(u, 0, 1.0f /*0x3f800000*/);
      std::uint16_t arg7 = FUN_007a4120(/*rng singleton*/ nullptr, u);
      action = CVOGHBSkill_Common_ctor(
          reinterpret_cast<CVOGHBSkill_Common *>(mem), source,
          reinterpret_cast<void *>(skill), reinterpret_cast<void *>(world),
          target, reinterpret_cast<void *>(tfid16), arg7,
          /*commonFlag*/ 0, /*commonScale*/ 1.0f);
    }

    // pOwnerObject @ +0x18 on CVOGHBBase
    if (*reinterpret_cast<void **>(reinterpret_cast<char *>(action) + 0x18) ==
        nullptr) {
      // scalar deleting dtor vtbl[0](1)
      auto **vt = *reinterpret_cast<void ***>(action);
      reinterpret_cast<void(__thiscall *)(CVOGHBBase *, int)>(vt[0])(action, 1);
    } else {
      CVOGHBList_Enqueue(*reinterpret_cast<void **>(world + 0xe4ec), action);
      CVOGHBBase_Start(action);
      spawnCount++;

      if (source != nullptr) {
        auto **srcVt = *reinterpret_cast<void ***>(source);
        int *related = reinterpret_cast<int *>(
            reinterpret_cast<void *(__thiscall *)(int *)>(srcVt[0x19c / 4])(
                source));
        if (related != nullptr) {
          related = reinterpret_cast<int *>(
              reinterpret_cast<char *>(related) +
              *reinterpret_cast<int *>(related[1] + 4) + 4);
        }
        if (related == target)
          goto next;
      }

      auto **tgtVt = *reinterpret_cast<void ***>(target);
      auto emit = reinterpret_cast<void(__thiscall *)(
          int *, int, std::uint32_t, int, int, int *, int, int, int)>(
          tgtVt[0x238 / 4]);
      int payload =
          static_cast<int>(static_cast<std::int16_t>(
              *reinterpret_cast<std::int16_t *>(skill + 0x174) +
              *reinterpret_cast<std::int16_t *>(skill + 0x5f6)));
      emit(target, 0x14, *reinterpret_cast<std::uint32_t *>(skill + 0x5fc),
           payload, static_cast<int>(*reinterpret_cast<std::int16_t *>(skill + 0x14)),
           source, 0, 0, 0);

      if (source != nullptr) {
        auto **srcVt = *reinterpret_cast<void ***>(source);
        auto emitSrc = reinterpret_cast<void(__thiscall *)(
            int *, int, std::uint32_t, int, int, int *, int, int, int)>(
            srcVt[0x238 / 4]);
        emitSrc(source, 0x15, *reinterpret_cast<std::uint32_t *>(skill + 0x5fc),
                payload,
                static_cast<int>(*reinterpret_cast<std::int16_t *>(skill + 0x14)),
                target, 0, 0, 0);
      }
    }

  next:
    index = static_cast<char>(index + 1);
  }
}

// Ghidra twin symbol
extern "C" bool FUN_006189d0(int *param_1, int param_2, int param_3, int param_4,
                             std::uint32_t param_5, std::uint32_t param_6) {
  return CVOGHBSkill_Common_SpawnPerTargetHB_Inferred(
      /*this*/ nullptr, param_1, param_2, param_3, param_4, param_5, param_6);
}
