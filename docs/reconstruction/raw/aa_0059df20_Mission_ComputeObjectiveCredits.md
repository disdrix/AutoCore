# Raw capture: Mission_ComputeObjectiveCredits

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059df20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0059df20` |
| **Canonical name** | `Mission_ComputeObjectiveCredits` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Mission_ComputeObjectiveCredits — mission complete credit amount.
   
   Algorithm:
     nTableKey = mission.wTargetLevel (@ mission+0x11c)
     pRow = Map_LowerBoundFindByIntKey(tQuestBaseCredits, nTableKey)
     flBaseCredits = (float)pRow->nBaseCredits (@ row+0x10)
     nTableKey = objective.wCreditsIndex (@ +0x13e)
     pRow = Map_LowerBoundFindByIntKey(tQuestCreditsLookup, nTableKey)
     flFrac = pRow->fLevelCreditsFrac (@ row+0x10)
     return (int)ceil(objective.fCreditScaler(+0x148) * flFrac * flBaseCredits)
   
   Parameters: this/pObjective — CVOGObjective*
   Returns: int credits to ADD into char+0x720 (not absolute).
   
   Tables: g_nQuestBaseCreditsLoaded_Inferred / g_nQuestCreditsLookupLoaded_Inferred. */

int __fastcall Mission_ComputeObjectiveCredits(void *pObjective)

{
  void *pvVar1;
  undefined4 *extraout_EAX;
  int *extraout_EAX_00;
  int *unaff_EDI;
  double dVar2;
  int nTableKey;
  float flBaseCredits;
  undefined1 abLookupScratch [4];
  void *pTableRow;
  
                    /* Mission credit calculator — tables tQuestBaseCredits + tQuestCreditsLookup
                        */
  nTableKey = (int)*(short *)(*(int *)((int)pObjective + 0x14c) + 0x11c);
  if (g_nQuestBaseCreditsLoaded_Inferred == 0) {
    EnsureQuestBaseCreditsLoaded();
  }
  Map_LowerBoundFindByIntKey(&g_pQuestBaseCreditsMap_Inferred,&flBaseCredits,&nTableKey,unaff_EDI);
  pTableRow = (void *)*extraout_EAX;
  if (g_nQuestBaseCreditsLoaded_Inferred == 0) {
    EnsureQuestBaseCreditsLoaded();
  }
  if (pTableRow != g_pQuestBaseCreditsEndSentinel_Inferred) {
    nTableKey = (int)*(short *)((int)pObjective + 0x13e);
                    /* Lookup frac by objective CreditsIndex (objective+0x13e) */
    flBaseCredits = (float)*(int *)((int)pTableRow + 0x10);
    if (g_nQuestCreditsLookupLoaded_Inferred == 0) {
      EnsureQuestCreditsLookupLoaded();
    }
    Map_LowerBoundFindByIntKey
              (&g_pQuestCreditsLookupMap_Inferred,abLookupScratch,&nTableKey,unaff_EDI);
    pvVar1 = (void *)*extraout_EAX_00;
    if (g_nQuestCreditsLookupLoaded_Inferred == 0) {
      EnsureQuestCreditsLookupLoaded();
    }
                    /* ceil(CreditScaler * frac * base) → grant amount */
    if (pvVar1 != g_pQuestCreditsLookupEndSentinel_Inferred) {
      dVar2 = ceil((double)(*(float *)((int)pObjective + 0x148) * *(float *)((int)pvVar1 + 0x10) *
                           flBaseCredits));
      return (int)ROUND(dVar2);
    }
  }
  return 0;
}
```
