// =============================================================================
// FUN_0052b080  (twin of CVOGCharacter_ComputeObjectDifficultyScore_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0052b080
// Address:   0x0052b080  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Dual:      R13-035 OWN-ONLY 2026-08-05 (dual start 2686)
// Exactness: Behavior-preserving rewrite of decompiler + asm-sealed CF.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime Confirmed: NOT claimed.
// =============================================================================
//
// Scaffold twin retained for FUN_* path stability. Prefer the named clean:
//   CVOGCharacter_ComputeObjectDifficultyScore_Inferred.cpp
//
// PURPOSE:
//   Character thiscall difficulty score for a target object from resource-gap
//   math (base 100, −6 per overlevel, clamp gap 15; 0 if under-level / null /
//   gap>15). Sole direct caller: UI_FormatObjectDifficultyTier (0x008e4430).
// =============================================================================

#include <stdint.h>

extern "C" void __thiscall FUN_00418b80(void *mapHeader, void **outNode, int *pKey);

static float const *const DAT_00aaa7ac = (float const *)0x00aaa7ac; /* 100.0f */
static float const *const DAT_00aaa8dc = (float const *)0x00aaa8dc; /*   6.0f */
static float const *const DAT_00aaa7a4 = (float const *)0x00aaa7a4; /*  15.0f */
static float const *const g_flZero     = (float const *)0x00a0f518; /*   0.0f */

// Decompiler shows float stack arg — asm uses it as object*. Keep pointer type.
extern "C" float __thiscall FUN_0052b080(void *character /*ECX*/, void *targetObject /*stack*/)
{
  void *holder;
  void *clone;
  int required;
  int typeId;
  void *node;
  int playerVal;
  float score;

  if (targetObject == 0) {
    return *g_flZero;
  }
  holder = *(void **)((char *)targetObject + 0xa8);
  if (holder == 0) {
    return *g_flZero;
  }

  clone = *(void **)((char *)holder + 0x3c);
  required = *(int *)((char *)clone + 0x4b0);
  typeId   = *(int *)((char *)clone + 0x4ac);

  {
    void *outNode = 0;
    int key = typeId;
    FUN_00418b80((char *)character + 0x584, &outNode, &key);
    node = outNode;
  }

  if (node == *(void **)((char *)character + 0x588)) {
    playerVal = -1;
  } else {
    playerVal = *(int *)((char *)node + 0x10);
  }

  score = *DAT_00aaa7ac;
  if (playerVal < required) {
    return 0.0f;
  }
  if (playerVal == required) {
    return score;
  }
  {
    int gap = playerVal - required;
    if ((float)gap > *DAT_00aaa7a4) {
      return 0.0f;
    }
    return score - (float)gap * (*DAT_00aaa8dc);
  }
}
