// =============================================================================
// CVOGHBWakeupSkill_Fire_Inferred  (was FUN_00606180)
// -----------------------------------------------------------------------------
// Stable ID: aa_00606180
// Address:   0x00606180 – 0x006061de  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / heartbeat
// Generated: 2026-07-29 W18-I OWN dual A/B seal (three-rep: raw 2026-07-23 ≡ live
//            decompile ≡ read_memory body/call-site bytes)
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte-sealed ABI.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Class:     CVOGHBWakeupSkill (RTTI Confirmed ".?AVCVOGHBWakeupSkill@@")
// Vtbl:      PTR_FUN_009de7b4 slot +0x14 (DATA @ 0x009de7c8)
// =============================================================================

// PURPOSE
// Virtual fire/complete body for delayed skill apply heartbeat.
// Invoked via CVOGHBBase_EndOrDestroy (vtbl+0x18 path) when list Remove runs
// with flag_onEnd!=0 — after TryFire → OnHeartBeat(RescheduleAfterFire) returns
// status bit 0x10. Not the TryFire OnHeartBeat slot (+0x0C) and not Stop OnEnd (+0x10).
//
// When owner (this+0x18) is non-null:
//   1) If flag@+0x658 == 0: FUN_00514e00(owner) — dec active-cast counter on owner+0x64.
//   2) Skill_LocalCastValidate(owner, skipBusy=flag@+0x658, pSkill=NULL, rangeExtra=0).
//   3) If allow (0): Skill_ApplyEffectsOnTarget_Inferred(
//          skill=this+0x24, caster=*(this+0x18), world=*(this+0x654),
//          targetTfid=*(this+0x660), pos=*(this+0x66c), seed=*(this+0x670)).
// Always tails through empty FUN_005081f0.

#include <cstdint>

extern void __fastcall FUN_00514e00(void* owner /* ECX */);
extern int  __thiscall Skill_LocalCastValidate(void* caster, uint8_t skipBusy,
                                               void* pSkill, void* rangeExtra);
extern unsigned __thiscall Skill_ApplyEffectsOnTarget_Inferred(
    void* skill, void* caster, void* world, void* targetTfid,
    void* posOrArg, unsigned randomSeed);
extern void FUN_005081f0(void); // empty ret stub

void __thiscall CVOGHBWakeupSkill_Fire_Inferred(void* thisHb /* ECX */)
{
  // ESI = this (byte seal: push esi; mov esi, ecx)
  void* owner = *reinterpret_cast<void**>(reinterpret_cast<char*>(thisHb) + 0x18);
  if (owner == nullptr) {
    FUN_005081f0();
    return;
  }

  uint8_t skipBusy = *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(thisHb) + 0x658);
  if (skipBusy == 0) {
    // ECX still owner from prior load (test ecx,ecx path) — dec counter
    FUN_00514e00(owner);
    skipBusy = *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(thisHb) + 0x658);
  }

  int allow = Skill_LocalCastValidate(owner, skipBusy, nullptr, nullptr);
  if (allow == 0) {
    void* skill   = reinterpret_cast<char*>(thisHb) + 0x24;
    void* world   = *reinterpret_cast<void**>(reinterpret_cast<char*>(thisHb) + 0x654);
    void* tfid    = *reinterpret_cast<void**>(reinterpret_cast<char*>(thisHb) + 0x660);
    void* pos     = *reinterpret_cast<void**>(reinterpret_cast<char*>(thisHb) + 0x66c);
    unsigned seed = *reinterpret_cast<unsigned*>(reinterpret_cast<char*>(thisHb) + 0x670);
    Skill_ApplyEffectsOnTarget_Inferred(skill, owner, world, tfid, pos, seed);
  }

  // mov ecx, esi; pop esi; jmp FUN_005081f0
  FUN_005081f0();
}

// Ghidra alias
void __fastcall FUN_00606180(int param_1)
{
  CVOGHBWakeupSkill_Fire_Inferred(reinterpret_cast<void*>(param_1));
}
