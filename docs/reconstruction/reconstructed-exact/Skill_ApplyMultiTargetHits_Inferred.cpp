// =============================================================================
// Skill_ApplyMultiTargetHits_Inferred  (was FUN_0058c850)
// -----------------------------------------------------------------------------
// Stable ID: aa_0058c850
// Address:   0x0058c850–0x0058cc3f  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / combat multi-target apply
// Generated: 2026-07-29 W20-Q dual A/B seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual: reviews/A|B_aa_0058c850_Skill_ApplyMultiTargetHits_Inferred.md
// =============================================================================
//
// PURPOSE:
//   Resolve a TFID target list into a CS-guarded object list, then for each target:
//   accuracy-check (skip first), roll/compute damage from damageSource fields,
//   scale via FUN_004cf080, apply via Client_Combat_ApplySingleHitMaybeDefer_Inferred,
//   or enqueue a combat floater on miss. Return summed damage.
//
// NAME: INFERRED — no product string/RTTI. Prior scaffold Named_CalleeOf_Named_VOG_DEBUG_STOP.
// =============================================================================

// External (Ghidra / sealed sibling names) — declarations for documentation only:
//   CVOGReaction_ResolveObjectTarget, FUN_004024d0, FUN_0040b020, FUN_004bcbf0,
//   Skill_AccuracyHitCheck_Inferred, FUN_004cf080,
//   Client_Combat_ApplySingleHitMaybeDefer_Inferred, Client_EnqueueCombatFloater_INFERRED,
//   InitializeCriticalSection, g_flOne, DAT_009d4d28..34

#include <cstdint>

// __cdecl — SEH frame in retail (LAB_009a5758); bare ret
int Skill_ApplyMultiTargetHits_Inferred(
    void *param_1,           // skill/caster host (AccuracyHitCheck this)
    uint32_t *param_2,       // TFID list head (stride 16)
    void *param_3,           // damage source (min/max @ +0x54..)
    uint32_t /*param_4*/,    // unused by body (still on stack from callers)
    void *param_5,           // ushort roll table base
    int param_6)             // roll seed index
{
  unsigned char missFlag;
  int targetIndex;
  int totalDamage;
  int rollIndex;
  int *target;
  int damage;
  long double scale;
  float scaleF;
  uint32_t hitKindPack;
  unsigned short *rollPtr;
  uint32_t *pClear;
  int i;
  int resolved;
  uint32_t nodeMask;
  int listNonEmpty;

  int minA, minB, minC;
  uint32_t maxA;
  int maxB;
  uint32_t maxC;
  uint32_t hitMeta0, hitMeta1;
  unsigned char hitMeta2;
  uint32_t hitMetaExtra;
  uint32_t floaterBlock[14];

  // Retail: SEH install + dual CRITICAL_SECTION on list object (PTR_FUN_009cb368)
  if (param_2 == 0) {
    return 0;
  }

  // InitializeCriticalSection x2 (list object) — omitted as opaque RT call
  listNonEmpty = 0;
  nodeMask = param_2[0] & param_2[1];
  while (nodeMask != 0xffffffffu) {
    resolved = CVOGReaction_ResolveObjectTarget(
        (char)param_2[2], param_2[0], param_2[1]);
    if (resolved != 0) {
      FUN_004024d0(resolved);
      listNonEmpty = 1;
    }
    param_2 = param_2 + 4;
    nodeMask = param_2[0] & param_2[1];
  }

  if (listNonEmpty == 0) {
    FUN_004bcbf0();
    return 0;
  }

  targetIndex = 0;
  totalDamage = 0;
  rollIndex = param_6 * 6;
  target = (int *)FUN_0040b020();
  if (target != 0) {
    do {
      missFlag = 0;
      rollPtr = (unsigned short *)((char *)param_5 + (rollIndex % 600) * 2);

      // Live decompile: FUN_00553240(param_1, target, *rollPtr, &missFlag)
      // (skill thiscall packing; sibling dual documents full Accuracy ABI)
      if ((targetIndex < 1) ||
          ((char)Skill_AccuracyHitCheck_Inferred(
               param_1, target, *rollPtr, &missFlag) != '\0')) {

        minA = *(int *)((char *)param_3 + 0x54);
        minB = *(int *)((char *)param_3 + 0x58);
        minC = *(int *)((char *)param_3 + 0x5c);
        maxA = *(uint32_t *)((char *)param_3 + 0x60);
        maxB = *(int *)((char *)param_3 + 0x64);
        maxC = *(uint32_t *)((char *)param_3 + 0x68);
        hitMeta0 = 0;
        hitMeta1 = 0;
        hitMeta2 = 0;

        if (*(char *)((char *)param_3 + 0x140) == '\0') {
          hitMetaExtra = *(uint32_t *)((char *)param_3 + 0x144);
          damage = (*(int (**)(void *, int *, uint32_t *, int, int, int, int,
                               unsigned short *, uint32_t *, uint32_t))(
                       *(int *)*target + 0x4c))(
              param_1, &minA, &maxA, 1, 1, 1, 0, rollPtr, &hitMeta0, hitMetaExtra);
        } else {
          int minSum =
              (int)(short)minA + (minA >> 16) + (int)(short)minB + (minB >> 16) +
              (int)(short)minC + (minC >> 16);
          int maxHi = (int)(short)maxA + (int)(short)maxB + (maxB >> 16) +
                      (int)(short)maxC + ((int)maxC >> 16) +
                      (int)(short)(maxA >> 16);
          damage = (int)((unsigned long long)*rollPtr %
                         (unsigned long long)((maxHi - minSum) + 1)) +
                   minSum;
        }

        scale = FUN_004cf080(param_1, target, *rollPtr);
        scaleF = (float)scale;
        hitKindPack = 0;
        if (g_flOne < scaleF) {
          damage = (int)((float)damage * scaleF);
          hitKindPack = 1;
        }

        if (((int)(short)(maxA >> 16) > 0) || ((int)(short)(maxC >> 16) > 0)) {
          target[0x33] = 4;
        }

        Client_Combat_ApplySingleHitMaybeDefer_Inferred(
            hitKindPack, damage, param_1, target, 1, 1, 0,
            DAT_009d4d28, DAT_009d4d2c, DAT_009d4d30, DAT_009d4d34, &hitMeta0);
        totalDamage = totalDamage + damage;
      } else {
        pClear = floaterBlock;
        for (i = 0xe; i != 0; i = i + -1) {
          *pClear = 0;
          pClear = pClear + 1;
        }
        uint32_t *srcTfid = (uint32_t *)((char *)param_1 + 0x160);
        if (param_1 == 0) {
          srcTfid = &DAT_009d4d28;
        }
        floaterBlock[0] = srcTfid[0];
        floaterBlock[1] = srcTfid[1];
        floaterBlock[2] = srcTfid[2];
        floaterBlock[3] = srcTfid[3];
        floaterBlock[4] = (uint32_t)target[0x58];
        floaterBlock[5] = (uint32_t)target[0x59];
        floaterBlock[6] = (uint32_t)target[0x5a];
        floaterBlock[7] = (uint32_t)target[0x5b];
        ((unsigned char *)floaterBlock)[0x28] = 0;
        ((unsigned char *)floaterBlock)[0x2a] = 1;
        floaterBlock[0xc] = 0;
        Client_EnqueueCombatFloater_INFERRED(floaterBlock);
      }

      targetIndex = targetIndex + 1;
      rollIndex = rollIndex + 6;
      target = (int *)FUN_0040b020();
    } while (target != 0);
  }

  FUN_004bcbf0();
  return totalDamage;
}
