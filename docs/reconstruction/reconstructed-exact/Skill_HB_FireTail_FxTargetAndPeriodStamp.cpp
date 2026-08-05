// =============================================================================
// Skill_HB_FireTail_FxTargetAndPeriodStamp
// -----------------------------------------------------------------------------
// Stable ID: aa_00578b30
// Address:   0x00578b30 – 0x00578cda  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / heartbeat
// Dual:      W21-C 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   Shared skill HB fire tail used by multiple OnFire/OnHeartBeat paths:
//     empty hook → resolve target → owner FX (event 0x16) / target applies →
//     period finalize (one-shot Stop or min-frequency 300) → StampLastFireTime.
//
//   String: "Skill %d has invalid frequency %d" @ 0x009d4030.
//
// ABI:
//   ECX = this (skill HB host; CVOGHBBase head + large subclass tail)
//   void; plain RET after pop edi/esi/ebp/ebx/ecx
// =============================================================================

#include <cstdint>

extern "C" void FUN_004648a0(void* self, int zero); // empty; via PTR_FUN_00af31e4
extern "C" int* CVOGReaction_ResolveObjectTarget(/* stack packed args — see annotated */);
extern "C" int FUN_005408f0(std::uint32_t key, int evA, int evB); // FxCache; ECX=host global
extern "C" void CVOGReaction_FailMissionNotify(void* ctx);
extern "C" void FUN_004b7e50(int, int, int, int, int, int);
extern "C" void FUN_00518ca0(std::uint32_t, std::uint32_t, std::uint32_t, void*, std::uint32_t);
extern "C" void FUN_0051f880(int);
extern "C" void CVOGHBBase_Stop(void* self);              // 0x005081d0
extern "C" void CVOGHBBase_StampLastFireTime(void* self); // 0x00508270
extern "C" void FUN_007a4480(int level, const char* fmt, ...);

// Sealed CVOGHBBase head (sizeof 0x28):
//   +0x08 nPeriodMs, +0x0C nPeriodSentinel, +0x14 lastFire, +0x18 pOwner
// Skill subclass (this unit):
//   +0x140 char gate, +0x620 skillKey, +0x639 flags,
//   +0x658..+0x660 resolve args, +0x678.. effect block, +0x6ac FX out

// Ghidra types this as CVOGHBBase* and uses param_1[N] overlay for large offsets.
// Prefer absolute byte offsets in ports.

void __fastcall Skill_HB_FireTail_FxTargetAndPeriodStamp(void* param_1 /* ECX */)
{
  char* pcVar1;
  int* piVar2;
  int iVar3;
  int iVar4;

  // (*(code *)PTR_FUN_00af31e4)(param_1, 0) → FUN_004648a0
  FUN_004648a0(param_1, 0);

  // Live: packs +0x658 / +0x65c / +0x660 (and touches +0x688 before call)
  piVar2 = CVOGReaction_ResolveObjectTarget(
      /* decomp: CONCAT31(high(+0x65c), byte(+0x660)), ptr-related, +0x658 */);

  void* owner = *reinterpret_cast<void**>(reinterpret_cast<char*>(param_1) + 0x18);
  if (owner != nullptr) {
    std::uint8_t flags639 = *reinterpret_cast<std::uint8_t*>(
        reinterpret_cast<char*>(param_1) + 0x639);
    if ((flags639 & 0x10u) != 0) {
      pcVar1 = reinterpret_cast<char*>(owner) + 0x26;
      *pcVar1 = static_cast<char>(*pcVar1 + 1);
    }
    // ECX host = *(DAT_00b041fc) in live before call; key = +0x620; args 0x16, 1
    std::uint32_t skillKey = *reinterpret_cast<std::uint32_t*>(
        reinterpret_cast<char*>(param_1) + 0x620);
    iVar3 = FUN_005408f0(skillKey, 0x16, 1);
    if (iVar3 != 0) {
      auto** ovtbl = *reinterpret_cast<void***>(owner);
      using Fn0 = int(__thiscall*)(void*);
      using Fn3 = void(__thiscall*)(void*, int, int, void*);
      iVar4 = reinterpret_cast<Fn0>(ovtbl[0x19c / 4])(owner);
      void* fxOut = reinterpret_cast<char*>(param_1) + 0x6ac;
      if (iVar4 == 0) {
        reinterpret_cast<Fn3>(ovtbl[0xf8 / 4])(owner, iVar3, 0, fxOut);
      } else {
        // raw: (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0xf8))();
        int t1 = *reinterpret_cast<int*>(iVar4 + 4);
        int t2 = *reinterpret_cast<int*>(t1 + 4);
        int nested = t2 + 4 + iVar4;
        auto** nvtbl = *reinterpret_cast<void***>(nested);
        reinterpret_cast<Fn3>(nvtbl[0xf8 / 4])(reinterpret_cast<void*>(nested), iVar3, 0, fxOut);
      }
      CVOGReaction_FailMissionNotify(nullptr /* &stack local in live */);
      FUN_004b7e50(0, 0, 0, 0, 0, 0);
    }
  }

  if (piVar2 != nullptr) {
    auto** tvtbl = *reinterpret_cast<void***>(piVar2);
    using Fn0 = int(__thiscall*)(void*);
    using Fn1 = int(__thiscall*)(void*, int);
    iVar3 = reinterpret_cast<Fn0>(tvtbl[0x214 / 4])(piVar2);
    std::uint8_t flags639 = *reinterpret_cast<std::uint8_t*>(
        reinterpret_cast<char*>(param_1) + 0x639);
    if ((iVar3 != 0) && ((flags639 & 0x02u) != 0)) {
      char* base = reinterpret_cast<char*>(param_1);
      FUN_00518ca0(
          *reinterpret_cast<std::uint32_t*>(base + 0x620),
          *reinterpret_cast<std::uint32_t*>(base + 0x678),
          *reinterpret_cast<std::uint32_t*>(base + 0x67c),
          *reinterpret_cast<void**>(base + 0x680),
          *reinterpret_cast<std::uint32_t*>(base + 0x684));
    }
    if (*reinterpret_cast<char*>(reinterpret_cast<char*>(param_1) + 0x140) != '\0') {
      iVar3 = reinterpret_cast<Fn1>(tvtbl[0x210 / 4])(piVar2, 0);
      if (iVar3 != 0) {
        FUN_0051f880(1);
      }
    }
  }

  std::int32_t sentinel = *reinterpret_cast<std::int32_t*>(
      reinterpret_cast<char*>(param_1) + 0x0c);
  std::int32_t periodMs = *reinterpret_cast<std::int32_t*>(
      reinterpret_cast<char*>(param_1) + 0x08);

  if ((sentinel == -1000) && (periodMs == 0)) {
    CVOGHBBase_Stop(param_1);
    CVOGHBBase_StampLastFireTime(param_1);
    return;
  }
  if ((sentinel != 1) && (static_cast<std::uint32_t>(periodMs) < 300u)) {
    FUN_007a4480(
        1,
        "Skill %d has invalid frequency %d",
        *reinterpret_cast<std::uint32_t*>(reinterpret_cast<char*>(param_1) + 0x620),
        periodMs);
    *reinterpret_cast<std::int32_t*>(reinterpret_cast<char*>(param_1) + 0x08) = 300;
  }
  CVOGHBBase_StampLastFireTime(param_1);
}
