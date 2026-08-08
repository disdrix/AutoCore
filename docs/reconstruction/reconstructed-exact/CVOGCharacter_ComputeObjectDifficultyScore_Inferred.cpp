// =============================================================================
// CVOGCharacter_ComputeObjectDifficultyScore_Inferred  (aka FUN_0052b080)
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
// PURPOSE:
//   Score how "difficult" a target object is relative to the character's
//   resource/level balance for the object's required type.
//
//   clone = *(*(target+0xa8)+0x3c)
//   typeId   = *(clone+0x4ac)
//   required = *(clone+0x4b0)
//   player   = find(character+0x584, typeId) → node+0x10, else -1
//
//   if player < required:            return 0.0f
//   if player == required:           return 100.0f
//   if (player - required) > 15:     return 0.0f
//   else:                            return 100.0f - (player - required) * 6.0f
//
// ABI (asm-sealed):
//   float __thiscall CVOGCharacter_ComputeObjectDifficultyScore_Inferred(
//       void *character /*ECX*/, void *targetObject /*stack*/);
//   - RET 4; return float on x87 ST0 (FLD)
//
// DISTINCT FROM:
//   CVOGCharacter_GetResourceBalanceByType (0x0052ada0) — returns int balance
//     only (same map); does not compute score.
//   UI_FormatObjectDifficultyTier_Inferred (0x008e4430) — maps score+balance
//     to Impossible/Trivial…Very Hard labels and packed colors (sole direct caller).
//   DisciplineDefMap_TryCopyPayloadById_Inferred (0x0052b040) — adjacent VA
//     partition sibling only; different map (global DisciplineDef).
//
// CONSTANTS (read_memory):
//   DAT_00aaa7ac = 100.0f   base score
//   DAT_00aaa8dc =   6.0f   per-overlevel penalty
//   DAT_00aaa7a4 =  15.0f   max gap before hard-zero
//   g_flZero @ 0x00a0f518 = 0.0f
// =============================================================================

#include <stdint.h>

// Ordered-map find on character resource map (nil @ node+0x19, key @ +0x0C).
// this = map header; writes *outNode = node or end; key via *pKey.
extern "C" void __thiscall FUN_00418b80(void *mapHeader, void **outNode, int *pKey);

// Image constants
static float const *const kBaseScore100 = (float const *)0x00aaa7ac; /* 100.0f */
static float const *const kPerLevel6    = (float const *)0x00aaa8dc; /*   6.0f */
static float const *const kMaxGap15     = (float const *)0x00aaa7a4; /*  15.0f */
static float const *const kFlZero       = (float const *)0x00a0f518; /*   0.0f */

extern "C" float __thiscall CVOGCharacter_ComputeObjectDifficultyScore_Inferred(
    void *character /*ECX*/,
    void *targetObject /*stack*/)
{
  void *holder;
  void *clone;
  int required;
  int typeId;
  void *node;
  int playerVal;
  float score;

  if (targetObject == 0) {
    return *kFlZero;
  }
  holder = *(void **)((char *)targetObject + 0xa8);
  if (holder == 0) {
    return *kFlZero;
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

  score = *kBaseScore100; /* 100.0f */
  if (playerVal < required) {
    return 0.0f;
  }
  if (playerVal == required) {
    return score;
  }
  /* playerVal > required */
  {
    int gap = playerVal - required;
    if ((float)gap > *kMaxGap15) {
      return 0.0f;
    }
    return score - (float)gap * (*kPerLevel6);
  }
}

// Ghidra twin export name
extern "C" float __thiscall FUN_0052b080(void *param_1, void *param_2)
{
  return CVOGCharacter_ComputeObjectDifficultyScore_Inferred(param_1, param_2);
}
