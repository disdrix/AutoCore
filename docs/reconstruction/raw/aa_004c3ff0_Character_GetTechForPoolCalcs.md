# Raw capture: Character_GetTechForPoolCalcs

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c3ff0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004c3ff0` |
| **Canonical name** | `Character_GetTechForPoolCalcs` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Character_GetTechForPoolCalcs — clamp Tech for pool formulas.
   
   Parameters:
     pCharacter (ECX): character; Tech@+0x13c, bonus@+0x144 (INFERRED)
   Returns: int tech in [1,250]; raw Tech capped at 200 before bonus.
   
   Algorithm:
     capped = min(Tech, 200); sum = capped + bonus
     if sum < 2: return 1; if sum < 250: return sum; return 250
   
   AutoCore: VehicleHitPointCalculator.GetTechForPoolCalcs */

int __fastcall Character_GetTechForPoolCalcs(void *pCharacter)

{
  short nTechRaw;
  int nTechBonus;
  short nTechCapped;
  
  nTechRaw = *(short *)((int)pCharacter + 0x13c);
  nTechCapped = nTechRaw;
  if (199 < nTechRaw) {
    nTechCapped = 200;
  }
  nTechBonus = (int)*(short *)((int)pCharacter + 0x144);
  if (nTechCapped + nTechBonus < 0xfa) {
    nTechCapped = nTechRaw;
    if (199 < nTechRaw) {
      nTechCapped = 200;
    }
    if (nTechCapped + nTechBonus < 2) {
      return 1;
    }
  }
  nTechCapped = nTechRaw;
  if (199 < nTechRaw) {
    nTechCapped = 200;
  }
  if (nTechCapped + nTechBonus < 0xfa) {
    if (199 < nTechRaw) {
      nTechRaw = 200;
    }
    return nTechRaw + nTechBonus;
  }
  return 0xfa;
}
```
