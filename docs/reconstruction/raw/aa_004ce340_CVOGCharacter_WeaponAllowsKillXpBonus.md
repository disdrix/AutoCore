# Raw capture: CVOGCharacter_WeaponAllowsKillXpBonus

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ce340` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004ce340` |
| **Canonical name** | `CVOGCharacter_WeaponAllowsKillXpBonus` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGCharacter_WeaponAllowsKillXpBonus
   
   Parameters: this/character context (fastcall INFERRED)
   Returns: non-zero if kill-path spree bonus table may scale amount
   in CVOGReaction_AddExperience.
   
   Checks weapon/object state near +0xa0 / +0x100 / +0xac (INFERRED layout).
   Returns: bool-ish int */

int __fastcall CVOGCharacter_WeaponAllowsKillXpBonus(int param_1)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)(param_1 + 0xa0) >> 8);
  if (((param_1 + 0xa0 != 0) && (*(char *)(param_1 + 0x100) == '\0')) &&
     (*(int *)(param_1 + 0xac) != 2)) {
    return CONCAT31(uVar1,1);
  }
  return (uint)uVar1 << 8;
}
```
