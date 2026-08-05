# Raw capture: Outpost_ComputePulseXp

| Field | Value |
|---|---|
| **Stable ID** | `aa_00607830` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00607830` |
| **Canonical name** | `Outpost_ComputePulseXp` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Outpost_ComputePulseXp — periodic outpost XP amount (docs/XP.md)
   
   Parameters:
     this        - outpost/state object
     pCharacter  - player character
   
   Fields (INFERRED):
     this+0x238  - active/state gate (<1 → return 0)
     this+0x21c  - pulse scalar (float) used with percent table
   
   Algorithm:
     if state < 1: return 0
     levelSpan = Threshold(level) - Threshold(level-1)  [level<=1 edge]
     percent = Outpost_GetPulseXpPercent(...)
     amount = round(levelSpan * percent * scalar)
   
   Some callers gate player level >= 60. Pulse interval data: 900000 ms.
   Returns: XP amount (decompiler may show as longlong via helper) */

longlong __thiscall Outpost_ComputePulseXp(void *this,void *pCharacter)

{
  ushort wPlayerLevel;
  short sLevelMinus1;
  int nLevelInt;
  longlong lVar1;
  
  if (*(int *)((int)this + 0x238) < 1) {
    return 0;
  }
  wPlayerLevel = (**(code **)(*(int *)(*(int *)(*(int *)((int)pCharacter + 4) + 4) + 4 +
                                      (int)pCharacter) + 0x27c))();
  Experience_GetCumulativeThreshold(wPlayerLevel);
  nLevelInt = (**(code **)(*(int *)(*(int *)(*(int *)((int)pCharacter + 4) + 4) + 4 +
                                   (int)pCharacter) + 0x27c))();
  if (1 < nLevelInt) {
    sLevelMinus1 = (**(code **)(*(int *)(*(int *)(*(int *)((int)pCharacter + 4) + 4) + 4 +
                                        (int)pCharacter) + 0x27c))();
    Experience_GetCumulativeThreshold(sLevelMinus1 - 1);
  }
  Outpost_GetPulseXpPercent();
  lVar1 = FUN_006a3db0();
  return lVar1;
}
```
