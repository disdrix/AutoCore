// =============================================================================
// Skill_ApplyEffectsOnTarget_Inferred  (was FUN_005538a0)
// Address:  0x005538a0–0x00553c46  Stable: aa_005538a0
// System:   skills-abilities
// Callers:  Skill_ApplyStatusEffectLocal (delay<1); Client_RecvSkillStatusEffect
//           (null source + 'c'); FUN_00606180 (active-skill HB); FUN_00514e70;
//           FUN_00620480
// Role:     Resolve primary TFID target; combat events 4/0xc/0xe/5/6; optional
//           accuracy (skill+0x624 bit0); handler skill+0x5f0 vtbl+0x2c;
//           conditional power drain (skip when no-accuracy handler fails).
//           Return 1=ok, 0=fail/miss/no-world.
// Name INFERRED — no product string/RTTI; role from skill-cast call graph.
// Dual: reviews/A|B_aa_005538a0_Skill_ApplyEffectsOnTarget_Inferred.md
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

#include <cstdint>

// External symbols (Ghidra names / prior renames)
extern "C" void* CVOGReaction_ResolveObjectTarget(std::uint32_t bGlobal, std::uint32_t coidLo, std::uint32_t coidHi);
extern "C" void  Client_EnqueueCombatFloater_INFERRED(void* entry);
extern "C" void* FUN_0058ab60(std::uint32_t randomSeed);
extern "C" char  FUN_00553240(void* caster, void* target, std::uint32_t rollWord, int unused);
extern "C" void  FUN_004c2f20(std::uint32_t skillId);
extern "C" void  operator_delete__(void* p);
extern "C" float ROUND(float);

// skill offsets (from body)
// +0x008  short forwarded to power drain
// +0x014  short event arg
// +0x028  float ROUND'd into fail/success events
// +0x174  short rank component
// +0x5f0  handler*
// +0x5f6  short rank component
// +0x5fc  skillId
// +0x624  byte flags (bit0 = accuracy check)

namespace {

inline int SkillRank(const std::uint8_t* s) {
  return static_cast<int>(static_cast<std::int16_t>(
      *reinterpret_cast<const std::int16_t*>(s + 0x5f6) +
      *reinterpret_cast<const std::int16_t*>(s + 0x174)));
}

inline std::uint32_t SkillId(const std::uint8_t* s) {
  return *reinterpret_cast<const std::uint32_t*>(s + 0x5fc);
}

inline int SkillArg14(const std::uint8_t* s) {
  return static_cast<int>(*reinterpret_cast<const std::int16_t*>(s + 0x14));
}

inline int SkillRound28(const std::uint8_t* s) {
  return static_cast<int>(ROUND(*reinterpret_cast<const float*>(s + 0x28)));
}

using Event238 = void(__thiscall*)(void*, int, std::uint32_t, int, int, void*, int, int, int);
using Event238Char = char(__thiscall*)(void*, int, std::uint32_t, int, int, void*, int, int, int);

inline void* CasterVtblSlot(void* caster, unsigned off) {
  auto** vtbl = *reinterpret_cast<void***>(caster);
  return vtbl[off / 4];
}

// LAB_00553a7e — power/stamina drain path (INFERRED product English)
void PowerDrainLab(void* caster, std::uint8_t* s) {
  if (caster == nullptr) {
    return;
  }
  auto fn210 = reinterpret_cast<std::intptr_t*(__thiscall*)(void*, int)>(CasterVtblSlot(caster, 0x210));
  auto* p0 = fn210(caster, 0);
  if (p0 != nullptr) {
    // plant[0x1ad] == byte offset +0x6b4
    if (*reinterpret_cast<int*>(reinterpret_cast<std::uint8_t*>(p0) + 0x6b4) > 0) {
      return; // suppress drain
    }
  }
  auto fn214 = reinterpret_cast<std::intptr_t*(__thiscall*)(void*)>(CasterVtblSlot(caster, 0x214));
  if (fn214(caster) == nullptr) {
    return;
  }
  auto* pwr = fn214(caster);
  auto** pvt = reinterpret_cast<void***>(pwr);
  auto fnB0 = reinterpret_cast<void(__thiscall*)(void*, std::uint32_t)>((*pvt)[0xb0 / 4]);
  fnB0(pwr, *reinterpret_cast<std::uint16_t*>(s + 8));
}

int InvokeHandler(void* handler, void* caster, void* skill, void* world, void* targetTfid,
                  void* posOrArg, std::uint32_t randomSeed) {
  auto** hvt = *reinterpret_cast<void***>(handler);
  auto fn2c = reinterpret_cast<int(__thiscall*)(void*, void*, void*, void*, void*, void*, std::uint32_t)>(
      hvt[0x2c / 4]);
  return fn2c(handler, caster, skill, world, targetTfid, posOrArg, randomSeed);
}

} // namespace

std::uint32_t __thiscall Skill_ApplyEffectsOnTarget_Inferred(
    void* skill,
    void* caster,
    void* world,
    void* targetTfid,
    void* posOrArg,
    std::uint32_t randomSeed)
{
  auto* s = reinterpret_cast<std::uint8_t*>(skill);
  auto* tf = reinterpret_cast<std::uint32_t*>(targetTfid);

  if (world == nullptr || *reinterpret_cast<int*>(reinterpret_cast<std::uint8_t*>(world) + 0xe4e8) == 0) {
    return 0;
  }

  // TFID: [0]=lo [1]=hi byte@+8 = bGlobal (decompiler packing)
  const auto bGlobal = static_cast<std::uint32_t>(
      *reinterpret_cast<std::uint8_t*>(reinterpret_cast<std::uint8_t*>(targetTfid) + 8));
  auto* target = reinterpret_cast<std::intptr_t*>(
      CVOGReaction_ResolveObjectTarget(bGlobal, tf[0], tf[1]));

  if (caster != nullptr) {
    auto fn238 = reinterpret_cast<Event238>(CasterVtblSlot(caster, 0x238));
    fn238(caster, 4, SkillId(s), SkillRank(s), SkillArg14(s), target, 0, 0, 0);

    auto fn214 = reinterpret_cast<std::intptr_t*(__thiscall*)(void*)>(CasterVtblSlot(caster, 0x214));
    if (fn214(caster) != nullptr) {
      // decompiler re-calls +0x214 with skillId then FUN_004c2f20
      FUN_004c2f20(SkillId(s));
    }
  }

  bool missFloater = false;
  bool handlerFail = false;
  auto* handler = *reinterpret_cast<void**>(s + 0x5f0);

  if (handler == nullptr || target == nullptr) {
    PowerDrainLab(caster, s);
  } else if ((*reinterpret_cast<std::uint8_t*>(s + 0x624) & 1) != 0) {
    // accuracy path: always enter power LAB after miss or handler
    auto* slice = reinterpret_cast<std::uint16_t*>(FUN_0058ab60(randomSeed));
    const char hit = FUN_00553240(caster, target, *slice, 0);
    if (hit == 0) {
      // Build 0x38 floater entry: from caster TFID@+0x160, to target TFID@+0x160, flag@+0x2a=1
      alignas(4) std::uint8_t entry[0x38]{};
      auto* fromTfid = (caster != nullptr)
                           ? reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(caster) + 0x160)
                           : reinterpret_cast<std::uint32_t*>(0x009d1ca8);
      auto* e32 = reinterpret_cast<std::uint32_t*>(entry);
      e32[0] = fromTfid[0];
      e32[1] = fromTfid[1];
      e32[2] = fromTfid[2];
      e32[3] = fromTfid[3];
      // target int indices 0x58..0x5b == byte +0x160
      e32[4] = static_cast<std::uint32_t>(target[0x58]);
      e32[5] = static_cast<std::uint32_t>(target[0x59]);
      e32[6] = static_cast<std::uint32_t>(target[0x5a]);
      e32[7] = static_cast<std::uint32_t>(target[0x5b]);
      entry[0x2a] = 1;
      Client_EnqueueCombatFloater_INFERRED(entry);
      missFloater = true;
      operator_delete__(slice);
    } else {
      handlerFail = (InvokeHandler(handler, caster, skill, world, targetTfid, posOrArg, randomSeed) == 0);
      operator_delete__(slice);
    }
    PowerDrainLab(caster, s);
  } else {
    // no accuracy: power LAB only on handler success
    handlerFail = (InvokeHandler(handler, caster, skill, world, targetTfid, posOrArg, randomSeed) == 0);
    if (!handlerFail) {
      PowerDrainLab(caster, s);
    }
  }

  if (handlerFail || missFloater) {
    if (caster != nullptr) {
      auto fn238 = reinterpret_cast<Event238>(CasterVtblSlot(caster, 0x238));
      fn238(caster, 0xc, SkillId(s), SkillRank(s), SkillArg14(s), target, SkillRound28(s), 0, 0);
    }
    return 0;
  }

  if (target != nullptr) {
    if (caster != nullptr) {
      auto fn238 = reinterpret_cast<Event238>(CasterVtblSlot(caster, 0x238));
      fn238(caster, 0xe, SkillId(s), SkillRank(s), SkillArg14(s), target, SkillRound28(s), 0, 0);
    }

    // target type field at target[0x2a]+0x38 == 0x0e → special event 6
    auto* typeBase = reinterpret_cast<std::uint8_t*>(target[0x2a]);
    if (*reinterpret_cast<int*>(typeBase + 0x38) == 0xe) {
      auto t238 = reinterpret_cast<Event238Char>(
          (*reinterpret_cast<void***>(target))[0x238 / 4]);
      if (t238(target, 6, SkillId(s), SkillRank(s), SkillArg14(s), caster, SkillRound28(s), 0, 0) != 0) {
        return 1;
      }
    }
    {
      auto t238 = reinterpret_cast<Event238>(
          (*reinterpret_cast<void***>(target))[0x238 / 4]);
      t238(target, 5, SkillId(s), SkillRank(s), SkillArg14(s), caster, SkillRound28(s), 0, 0);
    }
  }
  return 1;
}
