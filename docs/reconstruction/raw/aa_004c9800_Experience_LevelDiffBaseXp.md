# Raw capture: Experience_LevelDiffBaseXp

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c9800` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004c9800` |
| **Canonical name** | `Experience_LevelDiffBaseXp` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Experience_LevelDiffBaseXp — kill XP level-diff table (FUN_004c9800)
   
   uint (victimLevel, playerLevel, enableGreyCheck)
   
   diff = playerLevel - victimLevel  (after call-site ±3 prep clamp)
   
   Easy / grey (diff >= 0):
     base = Experience_GetCreatureXpForLevel(victimLevel)
     if enableGreyCheck && diff >= 10: return 0   // grey = worthless
     if diff > 0: base += round(|diff| * 1.5 * base * -0.1)  // ~-15%/level
     return max(0, base)
   
   Hard (diff < 0):
     hardDiff = max(diff, -9)
     base = Experience_GetCreatureXpForLevel(victim - hardDiff adjusted)
     + floor(|extra| * base * 0.005)   // DAT_00aaa6a4
   
   Constants: 1.5 @ 0x009CBB68, -0.1 @ 0x009CBB60, 0.005 @ 0x00AAA6A4
   AutoCore: ExperienceService.LevelDiffBase */

uint __cdecl Experience_LevelDiffBaseXp(int nVictimLevel,int nPlayerLevel,bool bEnableGreyCheck)

{
  uint nBaseXp;
  uint nAbsExtraSign;
  uint nLevelDiff;
  uint nHardDiffClamped;
  undefined4 nEasyAdj;
  
  nLevelDiff = nPlayerLevel - nVictimLevel;
  if ((int)nLevelDiff < 0) {
    nHardDiffClamped = 0xfffffff7;
    if (-10 < (int)nLevelDiff) {
      nHardDiffClamped = nLevelDiff;
    }
    nBaseXp = Experience_GetCreatureXpForLevel(nPlayerLevel - nHardDiffClamped);
    if ((int)nLevelDiff < (int)nHardDiffClamped) {
      nAbsExtraSign = (int)(nLevelDiff - nHardDiffClamped) >> 0x1f;
      return nBaseXp + (int)((float)(int)((nLevelDiff - nHardDiffClamped ^ nAbsExtraSign) -
                                         nAbsExtraSign) * (float)(int)nBaseXp *
                            g_flHardKillInterpolate);
    }
  }
  else {
    if ((9 < (int)nLevelDiff) && (bEnableGreyCheck)) {
      return 0;
    }
    nBaseXp = Experience_GetCreatureXpForLevel(nVictimLevel);
    if ((bEnableGreyCheck) && (0 < (int)nLevelDiff)) {
      nEasyAdj = (int)(longlong)
                      ROUND((double)(int)((nLevelDiff ^ (int)nLevelDiff >> 0x1f) -
                                         ((int)nLevelDiff >> 0x1f)) * g_dGreyKillSlopeA *
                            (double)(int)nBaseXp * g_dGreyKillSlopeB);
      nBaseXp = nBaseXp + nEasyAdj & ((int)(nBaseXp + nEasyAdj) < 0) - 1;
    }
  }
  return nBaseXp;
}
```
