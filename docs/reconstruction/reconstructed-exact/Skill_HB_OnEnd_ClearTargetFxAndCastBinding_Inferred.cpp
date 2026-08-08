// =============================================================================
// Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00578ce0
// Address:   0x00578ce0 – 0x00578de0 exclusive (0x100 B)
// Module:    autoassault.exe (image base 0x400000)
// System:    skills-abilities / heartbeat (shared skill HB OnEnd)
// Generated: 2026-08-04 WQ9D-F dual (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   Shared skill HB OnEnd (vtbl+0x10 on many skill HB vtables). Inverse of
//   Skill_HB_FireTail_FxTargetAndPeriodStamp:
//     client end-hook → resolve target → clear +0x6b0 vector → owner notify
//     (vtbl+0x238 mode 1) → optional owner+0x26-- → clear cast binding when
//     flag 0x02 → optional FUN_0051f880(0) when +0x140 → tail empty base OnEnd.
//
// ABI:
//   __thiscall; ECX = skill HB this; no stack args.
//   Epilogue: pop ebx/esi/edi; tail-jmp CVOGHBBase_EmptyVFunc (0x005081f0).
//
// Dual: reviews/A|B_aa_00578ce0_Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred.md
// =============================================================================

#include <cstdint>

// Runtime-rebound: static FUN_004648a0 empty; Client_InitInstance → FUN_00802b70.
extern "C" void (*PTR_FUN_00af31e0)(void* hb, int zero);

extern "C" int* __thiscall CVOGReaction_ResolveObjectTarget(
    void* mapHost /*ECX*/,
    /* stack: packed TFID from HB+0x658 / +0x65c / +0x660 */);

extern "C" void __fastcall FUN_00578ac0(void* hb);  // destroy vector @ +0x6b0

extern "C" void __thiscall Skill_ClearCastBindingAndMaybeRestartCd(
    void* castOwner,
    void* skillId,
    int tfid0,
    int tfid1,
    int tfid2,
    char tfid3pad);

// Sets *(obj+0x6b8) = flag
extern "C" void __thiscall FUN_0051f880(void* obj, std::uint8_t flag);

// Empty base OnEnd body (tail target)
extern "C" void CVOGHBBase_EmptyVFunc(void);

// Layout (skill HB subclass — absolute offsets):
//   +0x18  pOwner
//   +0x140 char secondary gate
//   +0x198 / +0x61a  rank components (i16 sum)
//   +0x620 skillId / skillKey
//   +0x639 flags (bit0x02 cast-binding, bit0x10 owner+0x26)
//   +0x658..+0x660 resolve TFID pack
//   +0x678..+0x684 cast-binding TFID args
//   +0x688 world*
//   +0x6b0..+0x6b8 pointer vector (FUN_00578ac0)

void __fastcall Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred(void* hb /* ECX */)
{
  auto* base = reinterpret_cast<std::uint8_t*>(hb);

  // 1) Client/UI end hook
  PTR_FUN_00af31e0(hb, 0);

  // 2) Resolve target — ECX = *(world+0xe4e8); stack = TFID pack
  void* world = *reinterpret_cast<void**>(base + 0x688);
  void* mapHost = *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(world) + 0xe4e8);
  // Decomp shows CONCAT31 merge of +0x65c/+0x660; live push order matches
  // CVOGReaction_ResolveObjectTarget(thiscall mapHost, …TFID…).
  int* target = CVOGReaction_ResolveObjectTarget(mapHost /*, TFID from +0x658..*/);

  // 3) Free HB-owned pointer vector
  FUN_00578ac0(hb);

  void* owner = *reinterpret_cast<void**>(base + 0x18);
  if (owner != nullptr) {
    auto** ovtbl = *reinterpret_cast<void***>(owner);
    using OwnerNotify = void(__thiscall*)(
        void*, int mode, int skillId, int rank, int z0, int* tgt, int z1, int z2, int z3);
    int skillId = *reinterpret_cast<int*>(base + 0x620);
    int rank = static_cast<int>(static_cast<std::int16_t>(
        *reinterpret_cast<std::int16_t*>(base + 0x61a) +
        *reinterpret_cast<std::int16_t*>(base + 0x198)));
    reinterpret_cast<OwnerNotify>(ovtbl[0x238 / 4])(
        owner, 1, skillId, rank, 0, target, 0, 0, 0);

    if ((base[0x639] & 0x10u) != 0) {
      auto* ctr = reinterpret_cast<char*>(owner) + 0x26;
      *ctr = static_cast<char>(*ctr - 1);
    }
  }

  if (target != nullptr) {
    auto** tvtbl = *reinterpret_cast<void***>(target);
    using Fn0 = int(__thiscall*)(void*);
    using Fn1 = int(__thiscall*)(void*, int);
    int nested = reinterpret_cast<Fn0>(tvtbl[0x214 / 4])(target);
    if (nested != 0 && (base[0x639] & 0x02u) != 0) {
      // Nested cast-map owner: *(int*)(*(int*)(nested+4)+4) + 4 + nested
      int t1 = *reinterpret_cast<int*>(nested + 4);
      int t2 = *reinterpret_cast<int*>(t1 + 4);
      void* castOwner = reinterpret_cast<void*>(t2 + 4 + nested);
      Skill_ClearCastBindingAndMaybeRestartCd(
          castOwner,
          *reinterpret_cast<void**>(base + 0x620),
          *reinterpret_cast<int*>(base + 0x678),
          *reinterpret_cast<int*>(base + 0x67c),
          *reinterpret_cast<int*>(base + 0x680),
          static_cast<char>(*reinterpret_cast<int*>(base + 0x684)));
    }
    if (base[0x140] != 0) {
      int obj = reinterpret_cast<Fn1>(tvtbl[0x210 / 4])(target, 0);
      if (obj != 0) {
        FUN_0051f880(reinterpret_cast<void*>(obj), 0);
      }
    }
  }

  // 4) Tail empty base OnEnd (retail: jmp, not call)
  CVOGHBBase_EmptyVFunc();
}

// Scaffold alias
void __fastcall FUN_00578ce0(void* hb)
{
  Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred(hb);
}
