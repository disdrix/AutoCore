// =============================================================================
// CVOGHBMissionEscort_ReactionFactory_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0060c860
// Address:   0x0060c860–0x0060c991  (autoassault.exe @ 0x400000; 306 B / 0x132)
// System:    missions-progression / heartbeat
// Dual A/B:  2026-08-04 WQ9H-E
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Reaction path that may factory-spawn a CVOGHBMissionEscort heartbeat:
//     gate on ownerObj flags/keys → ResolveSkillTargets → optional CastSkill
//     → stamp score float slot → optional operator_new(0x78) + ctor + Enqueue
//     + Start → always delete target list on success path.
//
// CLASS identity (via ctor)
//   CVOGHBMissionEscort — RTTI dualed with CVOGHBMissionEscort_ctor (0x006507c0)
//
// ABI
//   __thiscall; ECX = reqHost; stack ownerCtx, scoreFloats*; ret 8; returns bool (AL)
//
// Factory size
//   operator_new(0x78) matches Escort ctor dual field map / sizeof note
//
// Rejected
//   Outpost HB identity (nearby string litter; ctor RTTI is Escort)
//   Claiming this body is the ctor (ctor is 006507c0)
//   Decompiler noreturn on operator_delete
// =============================================================================

#include <cstdint>

extern void *CVOGReaction_ResolveSkillTargets(void *skillRef, std::uint32_t packedId);
extern int   CVOGReaction_CastSkillOnTarget(
    void *targets, void *a, void *b, int c, int d, void *e, int f, int g, int h, int i);
extern void *operator_new(std::uint32_t size);
extern void  operator_delete(void *p);
extern void *CVOGHBMissionEscort_ctor(void *self, void *ownerCtx, void *reqHost);
extern void  CVOGHBList_Enqueue(void *list, void *action);
extern void  CVOGHBBase_Start(void *action);

extern float g_flOne;   // 0x00a0f2a0
extern float g_flZero;  // 0x00a0f518
extern void *DAT_00d02a90;

// bool __thiscall (ECX=reqHost); ret 8
bool __thiscall CVOGHBMissionEscort_ReactionFactory_Inferred(
    void *reqHost,
    void *ownerCtx,
    float *scoreFloats)
{
  // ownerObj = *(*(ownerCtx+4)+4 + 0xa8 + ownerCtx)
  int base = *reinterpret_cast<int *>(
      *reinterpret_cast<int *>(reinterpret_cast<char *>(ownerCtx) + 4) + 4);
  void *ownerObj = *reinterpret_cast<void **>(base + 0xa8 + reinterpret_cast<int>(ownerCtx));

  if (*reinterpret_cast<char *>(reinterpret_cast<char *>(ownerObj) + 0x7e) == '\0') {
    return false;
  }
  if (*reinterpret_cast<int *>(reinterpret_cast<char *>(reqHost) + 0x40) !=
      *reinterpret_cast<int *>(reinterpret_cast<char *>(ownerObj) + 0xfc)) {
    return false;
  }

  std::uint32_t packed =
      (static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(ownerObj)) & 0xffff0000u) |
      *reinterpret_cast<std::uint16_t *>(reinterpret_cast<char *>(reqHost) + 0x14);

  void **targets = reinterpret_cast<void **>(CVOGReaction_ResolveSkillTargets(
      *reinterpret_cast<void **>(reinterpret_cast<char *>(reqHost) + 0x10), packed));
  if (targets == nullptr) {
    return false;
  }

  if (*reinterpret_cast<char *>(reinterpret_cast<char *>(reqHost) + 0x20) != '\0') {
    int castBase = *reinterpret_cast<int *>(
                        *reinterpret_cast<int *>(reinterpret_cast<char *>(ownerCtx) + 4) + 4) +
                    reinterpret_cast<int>(ownerCtx);
    void *castCtx = reinterpret_cast<void *>(castBase + 4);
    int castRc = CVOGReaction_CastSkillOnTarget(
        targets, castCtx, castCtx, 1, 0, &DAT_00d02a90, 0, -1, 0, 0);
    if (castRc != 0) {
      operator_delete(targets);
      return false; // AL=0; ret 8
    }
  }

  // scoreFloats[1 + reqHost[8]] = 1.0f
  std::uint32_t slot =
      static_cast<std::uint32_t>(*reinterpret_cast<std::uint8_t *>(
          reinterpret_cast<char *>(reqHost) + 8));
  scoreFloats[1 + slot] = g_flOne;

  bool wantSpawn =
      (g_flZero < *reinterpret_cast<float *>(reinterpret_cast<char *>(reqHost) + 0x1c)) ||
      (*reinterpret_cast<char *>(reinterpret_cast<char *>(reqHost) + 0x18) != '\0');
  // targets[0x53] is dword index 0x53 → byte offset 0x14c
  if (wantSpawn &&
      *reinterpret_cast<int *>(reinterpret_cast<char *>(targets) + 0x14c) != -1) {
    void *mem = operator_new(0x78);
    void *action = nullptr;
    if (mem != nullptr) {
      // thiscall ctor: ECX=mem; stack ownerCtx, reqHost; ret 8; returns this
      action = CVOGHBMissionEscort_ctor(mem, ownerCtx, reqHost);
    }
    void *hbList =
        *reinterpret_cast<void **>(reinterpret_cast<char *>(ownerObj) + 0xe4ec);
    CVOGHBList_Enqueue(hbList, action);
    CVOGHBBase_Start(action);
  }

  operator_delete(targets);
  return true; // AL=1; ret 8
}
