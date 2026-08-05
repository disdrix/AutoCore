# Raw capture: Mission_ComputeObjectiveXp

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059dde0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0059dde0` |
| **Canonical name** | `Mission_ComputeObjectiveXp` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Mission_ComputeObjectiveXp — mission complete XP amount (INFERRED field offsets verified vs
   wad).
   
   Algorithm:
     frac = tQuestXPLookup[objective.wXPIndex @ +0x13c].rlLevelXP
     flSpanMult = fXPBalanceScaler(+0x144) * frac * fXPScaler(+0x140)
     nLevelSpan = tExperienceLevel[TargetLevel].intExperience
                  - tExperienceLevel[TargetLevel-1]  (if TargetLevel>1)
     return (int)(nLevelSpan * flSpanMult)  // trunc toward zero here
   
   Parameters: this/pObjective — CVOGObjective*
   Returns: int XP to grant (complete path applies ±0.5001 via g_flMissionXpRoundBias).
   
   Final objective only. Advance path does not call this. */

int __fastcall Mission_ComputeObjectiveXp(void *pObjective)

{
  void *pvVar1;
  int *extraout_EAX;
  int *extraout_EAX_00;
  int *extraout_EAX_01;
  int *unaff_EDI;
  int nLevelSpan;
  int nLookupKey;
  float flSpanMult;
  void *local_4;
  int nPrevThreshold;
  short nTargetLevel;
  
                    /* Mission XP calculator — tQuestXPLookup + tExperienceLevel span */
  if (*(int *)((int)pObjective + 0x14c) == 0) {
    return 0;
  }
  nLookupKey = (int)*(short *)((int)pObjective + 0x13c);
  if (g_nQuestXpLookupReady == 0) {
    Experience_EnsureQuestXpTableLoaded_INFERRED();
  }
                    /* Lookup frac by XPIndex (objective+0x13c) */
  Map_LowerBoundFindByIntKey(&g_pQuestXpLookupMap_INFERRED,&flSpanMult,&nLookupKey,unaff_EDI);
  pvVar1 = (void *)*extraout_EAX;
  if (g_nQuestXpLookupReady == 0) {
    Experience_EnsureQuestXpTableLoaded_INFERRED();
  }
  if (pvVar1 != g_pQuestXpLookupMapEnd) {
                    /* spanMult = XPBalanceScaler * frac * XPScaler */
    nLookupKey = (int)*(short *)(*(int *)((int)pObjective + 0x14c) + 0x11c);
    flSpanMult = *(float *)((int)pObjective + 0x144) * *(float *)((int)pvVar1 + 0x10) *
                 *(float *)((int)pObjective + 0x140);
    if (g_nExperienceLevelTableReady == 0) {
      Experience_EnsureLevelTableLoaded_INFERRED();
    }
    StdMap_LowerBoundByIntKey_INFERRED(&g_pExperienceLevelMap_INFERRED,&local_4,&nLookupKey);
    pvVar1 = (void *)*extraout_EAX_00;
    if (g_nExperienceLevelTableReady == 0) {
      Experience_EnsureLevelTableLoaded_INFERRED();
    }
    if (pvVar1 != g_pExperienceLevelMapEnd) {
      nTargetLevel = *(short *)(*(int *)((int)pObjective + 0x14c) + 0x11c);
      nLevelSpan = *(int *)((int)pvVar1 + 0x10);
      if (1 < nTargetLevel) {
        nLookupKey = nTargetLevel + -1;
        if (g_nExperienceLevelTableReady == 0) {
          Experience_EnsureLevelTableLoaded_INFERRED();
        }
        StdMap_LowerBoundByIntKey_INFERRED(&g_pExperienceLevelMap_INFERRED,&local_4,&nLookupKey);
        nPrevThreshold = *extraout_EAX_01;
        if (g_nExperienceLevelTableReady == 0) {
          Experience_EnsureLevelTableLoaded_INFERRED();
        }
        if ((void *)nPrevThreshold != g_pExperienceLevelMapEnd) {
          nLevelSpan = nLevelSpan - *(int *)(nPrevThreshold + 0x10);
        }
      }
      return (int)((float)nLevelSpan * flSpanMult);
    }
  }
  return 0;
}
```

---

## Version note — 2026-07-29 dual residual (append only; body immutable)

Re-verified live Ghidra decompile **≡** raw body above. Residual seal (not a body rewrite):

1. Map helpers image `ret 8`; post-call `mov reg,[eax]` → node*; payload `+0x10`; exact key.
2. Xrefs: CompleteObjective grant; toast×2; `FUN_0051f510` float wrap. No advance.
3. Bias `0x00aaa6d0` = 0.5001f is **caller-only**.

See `tmp/a_0059dde0.md`, dual A/B, annotated, function record.

## Version note — 2026-07-29 dual residual strengthen (append only)

Re-pass OWN ONLY: live decompile still **≡** raw body. Strengthened dual A/B + function record with:

1. Helper exact-match gate (`key < node.key → end`) + both `C2 08 00`.
2. Body mulss product order Balance×frac×Scaler; globals `0x00b04240..54`.
3. Grant bias contract: `f>=0 ? +0.5001f : -0.5001f` then `(int)f` in CompleteObjective only.
4. Presentation partition reconfirmed (toast / `FUN_0051f510` no AddExperience).

Verdict remains **accept-with-gaps** (R2 payloads / R4 scalers / R5 runtime open).
