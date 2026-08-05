// =============================================================================
// Emitter_UpdateTick_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005bc3c0
// Address:   0x005bc3c0 – 0x005bdce6 exclusive  (6438 B / 0x1926)
// Module:    autoassault.exe  image base 0x400000
// System:    client::fx / emitter
// Ghidra:    FUN_005bc3c0
// Generated: 2026-07-29 W28-I dual seal (decompile_function + read_memory)
// Exactness: Staged CF reconstruction from full decompile; nested FUN_* retained.
//            Full line-for-line body lives in raw capture (authority for bit-level).
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B:  accept-with-gaps (W28-I).
// =============================================================================
//
// PURPOSE:
//   Per-frame emitter host update used by NDSpecialFX_HostTick list +0x1E0.
//   Advances tick counters and timers, refreshes world/basis pose from attached
//   object or skybox/UI/attachment paths, applies motion/offset/velocity, and
//   when interval mode is armed and no active child list, calls
//   Emitter_SpawnOnIntervalTick_Inferred.
//
// ABI:
//   __thiscall  ECX = emitter*
//   stack:      float *dt, int host_field_2c (motion/ctx), int camera_or_world
//   epilogue:   ret 0x0C  (C2 0C 00)
//   return:     0 = remove emitter from HostTick list; 1 = keep
//
// CALLER (1):
//   NDSpecialFX_HostTick_Inferred (FUN_004b8ed0) @ 0x004b90ef
//   ECX = list node payload; on return 0 unlink/delete node + FUN_005be310;
//   on return 1 call ObjectMotion_SlotListTick on same payload.
//
// KEY CALLEE:
//   Emitter_SpawnOnIntervalTick_Inferred (FUN_005bc120) @ call 0x005bdcc1
//
// STRING:
//   "Emitter found at 0,0,0: %d %I64d" via FUN_007a4480 (rate-limited)
//
// CONSTANTS (read_memory):
//   g_flLevelUpUiBase_Inferred / DAT_00a10e74 = 2.0f  (quat factor; name misnomer)
//   DAT_00aaa668 = -1.0f  (mode-3 axis scale)
//   DAT_00af3f70 = -10.0f (skybox/UI scale path)
// =============================================================================

#include <cstdint>

// Nested callees (not OWN for this dual) — Ghidra names retained.
extern "C" void FUN_005b83e0(void);
extern "C" void FUN_005bb1d0(uint32_t q);
extern "C" void FUN_005bb1f0(float *dt, int flag);
extern "C" void FUN_005bc120(float *dt, uint32_t motionCtx); // Emitter_SpawnOnIntervalTick
extern "C" void FUN_004b8dc0(int a, int b);
extern "C" char FUN_0040cf00(uint32_t key);
extern "C" void FUN_007a4480(uint32_t level, const char *fmt, ...);
extern "C" void *FUN_004a6930(void *basis);
extern "C" uint32_t FUN_004ba6f0(void *quat);
extern "C" void *FUN_004e88e0(void *out, void *in);
extern "C" void FUN_004e8ad0(void *src, void *out);
extern "C" void FUN_004e8a40(void *src, void *out);
extern "C" void FUN_004e8b60(void *src, void *out);
extern "C" uint32_t FUN_004f2e70(void *src);
extern "C" void FUN_004e8860(void *a, void *b);
extern "C" void FUN_004e8910(void *a, void *b);
extern "C" void FUN_004e8bf0(void *a, void *b, void *c, void *d);
extern "C" void FUN_004e88a0(void *a, void *b);
extern "C" void FUN_0040cf90(void *v);
extern "C" float FUN_00404bd0(void *pos);
extern "C" void *CVOGReaction_RandomUnitScalar(void);
extern "C" void FUN_005552c0(float s, void *dst);
extern "C" void *operator_new(uint32_t n);
extern "C" int FUN_005c4e70(void);
extern "C" void FUN_005c4f00(uint32_t phys);

extern "C" float g_flZero;
extern "C" float g_flOne;
extern "C" float g_flLevelUpUiBase_Inferred; // 2.0f @ 0x00a10e74
extern "C" float DAT_00aaa668;               // -1.0f
extern "C" float DAT_00af3f70;               // -10.0f
extern "C" float DAT_00aaa638;
extern "C" float DAT_009cc4dc;
extern "C" float DAT_00a0f298;
extern "C" float DAT_00aaa7dc;
extern "C" int DAT_00d17958;
extern "C" char DAT_00b03e64;
extern "C" char DAT_00b454f9;
extern "C" char DAT_00b454f8;
extern "C" float _DAT_00b454f4;
extern "C" char DAT_00af3f6d;
extern "C" char DAT_00af3f6c;

// Staged CF — full expression detail in raw decompile.
// Offsets are dword indices on emitter* unless noted as byte offsets.

uint32_t __thiscall Emitter_UpdateTick_Inferred(
    int *emitter /* ECX */,
    float *dt,
    int host_field_2c,
    int camera_or_world)
{
  // --- prologue / SEH: LAB_009a6bd4; counter bump ---
  emitter[0x233] += 1;                                    // +0x8CC tick age
  *reinterpret_cast<int *>(DAT_00d17958 + 0x148) += 1;

  // --- object destroy-flag snapshot (object@+0x8, flag object+0x90e & 1) ---
  // Capture pos/basis from phys xform vtable+0xC or static object slots;
  // may set byte +0x7f9; clear emitter[2].
  // (full math: quat→basis with factor 2.0f — see raw)

  // --- hard stop flag +0x7ff → clear, return keep ---
  if (*reinterpret_cast<char *>(reinterpret_cast<char *>(emitter) + 0x7ff) != 0) {
    *reinterpret_cast<char *>(reinterpret_cast<char *>(emitter) + 0x7ff) = 0;
    return 1;
  }

  // --- primary countdown +0x810 (dword 0x204): subtract *dt; still >0 → keep ---
  {
    float prev = *reinterpret_cast<float *>(&emitter[0x204]);
    *reinterpret_cast<float *>(&emitter[0x204]) = prev - *dt;
    if (g_flZero < prev - *dt)
      return 1;
  }

  // --- early remove: invalid/expired vtable identity + flag +0x7f9 + empty +0xA28 ---
  // return 0  → HostTick unlinks emitter from +0x1E0
  // (exact predicate in raw)

  // --- flag +0x989 & 8 with live object → keep ---
  // --- optional vtable call on *emitter ---
  // --- secondary lifetime timer +0x808 (dword 0x202) when byte 0x1fe ---
  //     may set +0x7fa or call FUN_004b8dc0 and keep

  // --- snapshot previous pose +0x20e..+0x216 → +0x205..+0x20d via FUN_005b83e0 ---
  // --- ring walk emitter+5 stride 0xbd: FUN_005b83e0 per node ---

  // --- pose update branches ---
  // A) object present, sign(flag +0x989) >= 0:
  //    static slots or phys xform → basis @ +0x220..+0x22f;
  //    optional FUN_004a6930 / FUN_004ba6f0 / FUN_005bb1d0 into *emitter;
  //    debug string "Emitter found at 0,0,0..." rate-limited;
  //    mode +0x261 scale by DAT_00aaa668 (-1) when == 3;
  //    velocity from object +0x87c..
  // B) no parent / skybox path: UI projection via host_field + camera_or_world
  // C) attachment path (flags on parent object): quat extract family 004e88*
  //    or vtable +0x108 bone path; angular vel from +0x1c8 chain
  // join LAB_005bd44d

  // --- compose local offset +0x23a.. into +0x21a scaled by +0x22f ---
  // --- motion integrate / spawn path when byte 0x1ff ---
  //     FUN_005bb1f0; random interval table; optional screen shake / reaction
  // --- else velocity = delta(pos)/dt ---
  // --- if +0x7fe==0: recompute vel from pose deltas /dt ---
  // --- else optional operator_new(0x10)+FUN_005c4e70 helper at emitter[3] ---

  // --- stamp previous pos +0x21d = +0x220 ---
  // --- if interval mode (byte 0x1fe): ---
  //     if +0x7fa && !+0x7fe: maybe set +0x7f9 and keep
  //     else FUN_005b83e0 ring; if *emitter==0 → Emitter_SpawnOnIntervalTick(dt, host_field_2c)

  *reinterpret_cast<char *>(reinterpret_cast<char *>(emitter) + 0x7fe) = 0;
  return 1;
}
