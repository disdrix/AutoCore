// =============================================================================
// UI_FormatObjectDifficultyTier_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Map target object vs player into difficulty tier label + packed
//           color; optionally sprintf "Tier: requiredLevel" into caller buffer.
//
// Address:  0x008e4430  (autoassault.exe, image base 0x400000)
// Body:     0x008e4430–0x008e4726 (758 B / 0x2F6)
// Stable:   aa_008e4430
// System:   client mission / target UI difficulty
//
// ABI:      EAX = Object* target
//           ESI = char* textBuf or null (skip sprintf)
//           stack: uint32_t* outPackedColor
//           plain ret; void (*out carries color)
//
// Thresholds (rdata): 90, 70, 50, 30, 0  (Very Hard … Trivial)
// Labels: Impossible, Trivial, Easy, Moderate, Hard, Very Hard
// Format: "%s: %d" with localized tier + required level (+0x4b0)
//
// Exactness: CF from live decompile; *out success store from read_memory
//            epilogue (rejects raw always-0xFFFFFFFF tail).
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W29-J seal).
// =============================================================================

#include <stdint.h>
#include <stdio.h>

// Globals / helpers (not OWN) — names structural.
extern uint8_t *DAT_00d1b6d8; // global character / client context
extern float DAT_00aaa954;    // 90.0f
extern float DAT_00aaa950;    // 70.0f
extern float DAT_00a0f524;    // 50.0f
extern float DAT_00a0f694;    // 30.0f
extern float g_flZero;        // 0.0f
extern float DAT_00aaa6f8;    // 255.0f

// Runtime palette bases (BSS in static image; filled at run).
extern float DAT_00d1b424[4], DAT_00d1b434[4], DAT_00d1b444[4];
extern float DAT_00d1b454[4], DAT_00d1b464[4], DAT_00d1b474[4];
extern float DAT_00d1b484[4]; // Impossible (+0..+0xc as four floats)

extern int FUN_0052ada0(int resourceKey /*fastcall family*/);
extern float FUN_0052b080(void *character /*ecx*/, void *target);
extern void *FUN_007a69d0(void);
extern const char *FUN_007a6de0(void *locale /*ecx*/, const char *key, int lang /*-1*/);
extern void FUN_00973590(float a, float b, float c, float d); // dest via EAX
extern void FUN_00973820(uint8_t *dest /*ecx*/, const float *src);

static void pack_palette(uint8_t *dest, const float *rgba)
{
  FUN_00973820(dest, rgba);
}

// Register ABI expressed as explicit params for the port surface.
void UI_FormatObjectDifficultyTier_Inferred(void *target /*eax*/,
                                            char *textBuf /*esi*/,
                                            uint32_t *outPackedColor)
{
  uint8_t packed[4] = {0xFF, 0xFF, 0xFF, 0xFF};
  const char *label = 0;
  int required = 0;

  if (target == 0 || DAT_00d1b6d8 == 0) {
    *outPackedColor = 0xFFFFFFFFu;
    return;
  }

  // clone = *(*(target+0xa8)+0x3c)
  int *objA8 = *(int **)((uint8_t *)target + 0xa8);
  int *clone = *(int **)((uint8_t *)objA8 + 0x3c);
  required = clone[0x4b0 / 4];
  int playerVal = FUN_0052ada0(clone[0x4ac / 4]);
  float score = FUN_0052b080(DAT_00d1b6d8, target);
  void *locale = FUN_007a69d0();

  if (playerVal < required) {
    // Impossible: scale palette ×255, direct FUN_00973590 (image: EAX = local packed).
    float s = DAT_00aaa6f8;
    // Port surface: treat nested packer as writing into packed[] (EAX dest in image).
    (void)packed;
    FUN_00973590(DAT_00d1b484[0] * s, DAT_00d1b484[1] * s,
                 DAT_00d1b484[2] * s, DAT_00d1b484[3] * s);
    // After call, image local color holds packed Impossible palette (EAX was &packed).
    label = "Impossible";
  } else if (score > DAT_00aaa954) { // > 90
    pack_palette(packed, DAT_00d1b474);
    label = "Very Hard";
  } else if (score > DAT_00aaa950) { // > 70
    pack_palette(packed, DAT_00d1b464);
    label = "Hard";
  } else if (score > DAT_00a0f524) { // > 50
    pack_palette(packed, DAT_00d1b454);
    label = "Moderate";
  } else if (score > DAT_00a0f694) { // > 30
    pack_palette(packed, DAT_00d1b444);
    label = "Easy";
  } else if (score > g_flZero) {
    pack_palette(packed, DAT_00d1b434);
    label = "Trivial";
  } else {
    pack_palette(packed, DAT_00d1b424);
    label = "Trivial";
  }

  if (textBuf != 0) {
    const char *loc = FUN_007a6de0(locale, label, -1);
    sprintf(textBuf, "%s: %d", loc, required);
  }

  *outPackedColor = *(uint32_t *)packed;
}
