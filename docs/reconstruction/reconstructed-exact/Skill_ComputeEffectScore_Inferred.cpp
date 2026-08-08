// =============================================================================
// Skill_ComputeEffectScore_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00627ec0
// Address:   0x00627ec0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-08-04 WQ9E-B dual A/B (from raw + live re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE
//   Score consumer of dualed Skill_ComputeEffectPresenceFlags_Inferred.
//   Builds a weighted float magnitude from ranked skill effect banks that the
//   presence mask marks non-empty, applies duration/charge scales, clamps to
//   >= 1.0, and returns (int)ceil(score). Used by HB/conflict comparators that
//   score two skill blobs and pick the higher priority.
//
// ABI: __fastcall / thiscall — ECX = skill runtime; EAX = int score; plain ret
// Body: 0x00627ec0–0x00628516 exclusive (1878 B / 0x756)
// Name: _Inferred — role High from presence gates + dual-score callers; product English open.
// =============================================================================

#include <stdint.h>
#include <math.h>

// Dual sealed WQ9D-E
extern uint32_t __fastcall Skill_ComputeEffectPresenceFlags_Inferred(void *pSkill);

// Sealed float pool (read_memory 2026-08-04)
static const float kFlOne = 1.0f;           // g_flOne @ 0x00a0f2a0
static const float kFlTwo = 2.0f;           // g_flLevelUpUiBase_Inferred @ 0x00a10e74 (literal 2.0 here)
static const float kFlTenth = 0.1f;         // g_flMultiKillCountBlend @ 0x00a0f730
static const float kFlMsToSec = 0.001f;     // g_flMsToSeconds_Inferred @ 0x00a0f72c
static const float kFl035 = 0.35f;          // DAT_00a0f728
static const float kFl05 = 0.5f;           // DAT_00a0f298
static const float kFl12 = 1.2f;           // DAT_00aaab3c
static const float kFl02 = 0.2f;           // DAT_00a0f70c
static const float kFl0125 = 0.125f;       // DAT_00a110c0
static const float kFl5 = 5.0f;            // DAT_00aaa688
static const float kFl08 = 0.8f;           // DAT_00a0f698
static const float kFl10000 = 10000.0f;    // DAT_00aaa880
static const float kFlThird = 0.333333f;   // DAT_009dbf08 (~1/3)
static const float kFlZero = 0.0f;         // g_flZero

static float pair_term(int16_t a, int16_t b)
{
  return (float)(int)a * kFl035 + (float)(int)b * kFl05;
}

int __fastcall Skill_ComputeEffectScore_Inferred(void *pSkill)
{
  uint8_t *base = (uint8_t *)pSkill;
  int16_t *s = (int16_t *)pSkill;
  float score = 0.0f;
  float weight = kFlOne;
  float one = kFlOne;
  uint32_t flags = Skill_ComputeEffectPresenceFlags_Inferred(pSkill);

  // --- bit 0x1: primary short bank +0x60 with companions +0x54 ---
  if ((flags & 1u) != 0) {
    weight = one;
    if (s[0x30] != 0) { // +0x60
      score = pair_term(s[0x2a], s[0x30]); // +0x54, +0x60
      weight = kFl12;
    }
    if (s[0x31] != 0) {
      score = pair_term(s[0x2b], s[0x31]) * weight + score;
      weight = weight + kFl02;
    }
    if (s[0x32] != 0) {
      score = pair_term(s[0x2c], s[0x32]) * weight + score;
      weight = weight + kFl02;
    }
    if (s[0x33] != 0) {
      score = pair_term(s[0x2d], s[0x33]) * weight + score;
      weight = weight + kFl02;
    }
    if (s[0x34] != 0) {
      score = pair_term(s[0x2e], s[0x34]) * weight + score;
      weight = weight + kFl02;
    }
    if (s[0x35] != 0) {
      score = pair_term(s[0x2f], s[0x35]) * weight + score;
    }
    // (2 - f32@+0x34) * f32@+0x28 * score * 0.1 * ((byte@+0x52 & 1)*0.2 + 1)
    score = (kFlTwo - *(float *)(base + 0x34)) *
            *(float *)(base + 0x28) * score * kFlTenth *
            ((float)(base[0x52] & 1) * kFl02 + one);
    weight = kFl12;
  }

  // --- bit 0x100: paired banks +0x78 / +0x90 ---
  if ((flags & 0x100u) != 0) {
    float term = 0.0f;
    float w2 = one;
    if (s[0x48] != 0) { // +0x90
      term = pair_term(s[0x3c], s[0x48]); // +0x78, +0x90
      w2 = kFl12;
    }
    if (s[0x49] != 0) {
      term = pair_term(s[0x3d], s[0x49]) * w2 + term;
      w2 = w2 + kFl02;
      one = kFlOne;
    }
    if (s[0x4a] != 0) {
      term = pair_term(s[0x3e], s[0x4a]) * w2 + term;
      w2 = w2 + kFl02;
      one = kFlOne;
    }
    if (s[0x4b] != 0) {
      term = pair_term(s[0x3f], s[0x4b]) * w2 + term;
      w2 = w2 + kFl02;
      one = kFlOne;
    }
    if (s[0x4c] != 0) {
      term = pair_term(s[0x40], s[0x4c]) * w2 + term;
      w2 = w2 + kFl02;
      one = kFlOne;
    }
    if (s[0x4d] != 0) {
      term = pair_term(s[0x41], s[0x4d]) * w2 + term;
      one = kFlOne;
    }
    score = term * weight + score;
    weight = weight + kFl02;
  }

  // --- bit 0x40: i16 +0xd0..+0xd6 * int@+0x18 * ms-to-sec * weight ---
  if ((flags & 0x40u) != 0) {
    float sum4 = (float)(int)s[0x6b] + (float)(int)s[0x6a] +
                 (float)(int)s[0x69] + (float)(int)s[0x68];
    score = sum4 * (float)(*(int *)(base + 0x18)) * kFlMsToSec * weight + score;
    weight = weight + kFl02;
  }

  // --- bit 0x8: signed shorts @ +0x6c ---
  if ((flags & 8u) != 0) {
    float acc = 0.0f;
    float w3 = one;
    int16_t v;

    v = s[0x36]; // +0x6c
    if (v < 1) {
      w3 = one;
      if (v < 0) acc = (float)(int)v * kFl02;
    } else {
      acc = (float)(int)v * kFl0125;
      w3 = kFl12;
    }

    v = s[0x37];
    if (v < 1) {
      if (v < 0) acc = (float)(int)v * kFl02 + acc;
    } else {
      acc = (float)(int)v * w3 * kFl0125 + acc;
      w3 = w3 + kFl02;
    }

    v = s[0x38];
    if (v < 1) {
      if (v < 0) acc = (float)(int)v * kFl02 + acc;
    } else {
      acc = (float)(int)v * w3 * kFl0125 + acc;
      w3 = w3 + kFl02;
    }

    v = s[0x39];
    if (v < 1) {
      if (v < 0) acc = (float)(int)v * kFl02 + acc;
    } else {
      acc = (float)(int)v * w3 * kFl0125 + acc;
      w3 = w3 + kFl02;
    }

    v = s[0x3a];
    if (v < 1) {
      if (v < 0) acc = (float)(int)v * kFl02 + acc;
    } else {
      acc = (float)(int)v * w3 * kFl0125 + acc;
      w3 = w3 + kFl02;
    }

    v = s[0x3b];
    if (v < 1) {
      if (v < 0) acc = (float)(int)v * kFl02 + acc;
    } else {
      acc = (float)(int)v * w3 * kFl0125 + acc;
    }

    score = acc * weight + score;
    weight = weight + kFl02;
  }

  // --- bit 0x2: f32 @ +0x3c ---
  if ((flags & 2u) != 0) {
    score = *(float *)(base + 0x3c) * weight + score;
    weight = weight + kFl02;
  }

  // --- bit 0x800: int16 @ +0 (from base flags skill+0xc) ---
  if ((flags & 0x800u) != 0) {
    score = (float)(int)s[0] * weight + score;
    weight = weight + kFl02;
  }

  // --- bit 0x10: byte @ +0xda * weight * 2 ---
  if ((flags & 0x10u) != 0) {
    score = (float)base[0xda] * weight * kFlTwo + score;
    weight = weight + kFl02;
  }

  // --- bit 0x1000: multiply score by weight * 5 ---
  if ((flags & 0x1000u) != 0) {
    score = weight * score * kFl5;
    weight = weight + kFl02;
  }

  // --- ungated bonus: f32 @ +0x4c ---
  if (kFlZero < *(float *)(base + 0x4c)) {
    score = *(float *)(base + 0x4c) * kFlThird * weight + score;
  }

  // --- duration scale via int@+0x18 / int@+0x10 ---
  {
    int d18 = *(int *)(base + 0x18);
    if (d18 == -1000) {
      score = score * kFlTwo;
    } else if (*(int *)(base + 0x10) < 5000) {
      score = (kFlTwo - (float)(*(int *)(base + 0x10)) + kFl08) * score;
    } else {
      score = score * kFl08;
    }
  }

  // --- charge-like scale via int@+0x1c ---
  if (*(int *)(base + 0x1c) != 0) {
    score = ((kFl10000 - (float)(*(int *)(base + 0x1c))) * kFlMsToSec + one) * score;
  }

  if (score < one) {
    score = one;
  }

  return (int)ceil((double)score);
}
