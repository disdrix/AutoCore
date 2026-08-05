# Raw capture: Experience_XpToReachRelativeLevel

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052dec0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0052dec0` |
| **Canonical name** | `Experience_XpToReachRelativeLevel` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Experience_XpToReachRelativeLevel — XP needed to reach level+delta
   
   Parameters:
     this        - Character*
     nLevelDelta - relative level steps (can be negative)
   
   Algorithm:
     curLevel = vtable GetLevel (+0x27c)
     if curLevel + nLevelDelta < 1: return 0
     thr = Experience_GetCumulativeThreshold(curLevel + nLevelDelta - 1)
     return (int)(thr / flPersonalXpGain) - nTotalXp + 1
   
   Used by reaction SetLevel / relative-level helpers.
   Returns: int XP amount to grant (may be negative for de-level) */

int __thiscall Experience_XpToReachRelativeLevel(void *this,int nLevelDelta)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 4 + (int)this) + 0x27c))();
  if (iVar1 + nLevelDelta < 1) {
    return 0;
  }
  uVar2 = Experience_GetCumulativeThreshold((short)(iVar1 + nLevelDelta) - 1);
  return ((int)((float)(int)uVar2 / *(float *)((int)this + 0xc54)) - *(int *)((int)this + 0x730)) +
         1;
}
```
