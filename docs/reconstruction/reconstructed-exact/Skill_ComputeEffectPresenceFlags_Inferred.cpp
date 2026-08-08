// =============================================================================
// Skill_ComputeEffectPresenceFlags_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00627be0
// Address:   0x00627be0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-08-04 WQ9D-E dual A/B (from raw + live re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE
//   After Skill_EvaluateRankedElements / rank reevaluate materializes ranked
//   effect magnitudes into the skill runtime, scan those fields for non-zero
//   presence and build a capability/targeting bitmask. Result is ORed with
//   base dword skill+0xc.
//
//   Primary consumers:
//     Skill_ReevaluateForCurrentRank (0x00553390) — stores to skill+0x624
//     FUN_0054fec0 (0x0054fec0)                  — same store pattern
//     FUN_00627ec0 (0x00627ec0)                  — uses bits for score weights
//
// ABI: __fastcall / thiscall — ECX = skill runtime; EAX = flags; ret
// Body: 0x00627be0–0x00627eb3 (211 B); leaf (no callees)
// Name: _Inferred — role High from callers; product English open.
// =============================================================================

#include <stdint.h>

uint32_t __fastcall Skill_ComputeEffectPresenceFlags_Inferred(void *pSkill)
{
  uint32_t flags = 0;
  int i;
  int16_t *ps;
  float *pf;
  uint8_t *base = (uint8_t *)pSkill;

  // --- bit 0x1: any of 6× int16 @ +0x60 ---
  ps = (int16_t *)(base + 0x60);
  for (i = 0; i < 6; i++, ps++) {
    if (*ps != 0) {
      flags = 1;
      break;
    }
  }

  // --- bit 0x8: any of 6× int16 @ +0x6c ---
  ps = (int16_t *)(base + 0x6c);
  for (i = 0; i < 6; i++, ps++) {
    if (*ps != 0) {
      flags |= 8u;
      break;
    }
  }

  // --- bit 0x80: any of 6× float @ +0xa8 ---
  pf = (float *)(base + 0xa8);
  for (i = 0; i < 6; i++, pf++) {
    if (*pf != 0.0f) {
      flags |= 0x80u;
      break;
    }
  }

  // --- bit 0x100: paired int16 banks +0x78 and +0x90 (offset +0x18 / [0xc]) ---
  ps = (int16_t *)(base + 0x78);
  for (i = 0; i < 6; i++, ps++) {
    if (ps[0xc] != 0 || *ps != 0) {
      flags |= 0x100u;
      break;
    }
  }

  // --- bit 0x200: paired int16 banks +0x84 and +0x9c ---
  ps = (int16_t *)(base + 0x84);
  for (i = 0; i < 6; i++, ps++) {
    if (ps[0xc] != 0 || *ps != 0) {
      flags |= 0x200u;
      break;
    }
  }

  // --- bit 0x400: misc float presence group A ---
  if (*(float *)(base + 0x4c) != 0.0f || *(float *)(base + 0xc4) != 0.0f ||
      *(float *)(base + 0xc0) != 0.0f || *(float *)(base + 0xcc) != 0.0f ||
      *(float *)(base + 0xc8) != 0.0f || *(float *)(base + 0x44) != 0.0f ||
      *(float *)(base + 0x48) != 0.0f || *(float *)(base + 0x24) != 0.0f ||
      *(float *)(base + 0xf8) != 0.0f || *(float *)(base + 0xfc) != 0.0f ||
      *(float *)(base + 0x104) != 0.0f || *(float *)(base + 0x100) != 0.0f) {
    flags |= 0x400u;
  }

  // --- bit 0x40: any of 5× int16 @ +0xd0..+0xd8 ---
  if (*(int16_t *)(base + 0xd0) != 0 || *(int16_t *)(base + 0xd2) != 0 ||
      *(int16_t *)(base + 0xd4) != 0 || *(int16_t *)(base + 0xd6) != 0 ||
      *(int16_t *)(base + 0xd8) != 0) {
    flags |= 0x40u;
  }

  // --- bit 0x20 ---
  if (*(float *)(base + 0x38) != 0.0f || *(float *)(base + 0x13c) != 0.0f) {
    flags |= 0x20u;
  }

  // --- bit 0x10 ---
  if (*(char *)(base + 0xda) != 0) {
    flags |= 0x10u;
  }

  // --- bit 0x2 ---
  if (*(float *)(base + 0x3c) != 0.0f) {
    flags |= 2u;
  }

  // --- bit 0x8000 ---
  if (*(float *)(base + 0x40) != 0.0f) {
    flags |= 0x8000u;
  }

  // --- bit 0x10000 ---
  if (*(float *)(base + 0x110) != 0.0f || *(float *)(base + 0x114) != 0.0f ||
      *(float *)(base + 0x118) != 0.0f || *(float *)(base + 0x10c) != 0.0f) {
    flags |= 0x10000u;
  }

  // --- bit 0x20000 (float pair) ---
  if (*(float *)(base + 0x124) != 0.0f || *(float *)(base + 0x128) != 0.0f) {
    flags |= 0x20000u;
  }

  // --- bit 0x400 again (second float pair @ +0x12c / +0x130) ---
  if (*(float *)(base + 0x12c) != 0.0f || *(float *)(base + 0x130) != 0.0f) {
    flags |= 0x400u;
  }

  // --- bit 0x20000 again (int gate + float) ---
  if (*(int32_t *)(base + 0x134) != 0 && *(float *)(base + 0x138) != 0.0f) {
    flags |= 0x20000u;
  }

  return *(uint32_t *)(base + 0xc) | flags;
}
