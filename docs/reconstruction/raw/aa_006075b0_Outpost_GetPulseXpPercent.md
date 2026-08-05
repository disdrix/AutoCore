# Raw capture: Outpost_GetPulseXpPercent

| Field | Value |
|---|---|
| **Stable ID** | `aa_006075b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006075b0` |
| **Canonical name** | `Outpost_GetPulseXpPercent` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Outpost_GetPulseXpPercent — fPercentLevelXP table pick
   
   INFERRED: returns pulse percent float for Outpost_ComputePulseXp.
   Tables differ for true outpost vs non-outpost (bIsOutpost).
   Session dependency of outpost XP only. */

float10 __fastcall Outpost_GetPulseXpPercent(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  float10 fVar5;
  
  puVar4 = &DAT_00d029e0;
  if (*(char *)(param_1 + 0x220) == '\0') {
    puVar4 = &DAT_00d029f0;
  }
  uVar1 = *(uint *)(param_1 + 0x23c);
  if (-1 < (int)uVar1) {
    iVar2 = *(int *)(puVar4 + 4);
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(int *)(puVar4 + 8) - iVar2 >> 4;
    }
    if (uVar1 < uVar3) {
      if ((iVar2 != 0) && (uVar1 < (uint)(*(int *)(puVar4 + 8) - iVar2 >> 4))) {
        return (float10)*(float *)(uVar1 * 0x10 + 8 + iVar2);
      }
      fVar5 = (float10)FUN_00608620();
      return fVar5;
    }
  }
  return (float10)g_flZero;
}
```
