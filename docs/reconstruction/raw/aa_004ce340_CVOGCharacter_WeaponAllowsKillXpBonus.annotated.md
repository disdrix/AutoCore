# Annotated low-level: CVOGCharacter_WeaponAllowsKillXpBonus

| Field | Value |
|---|---|
| Stable ID | `aa_004ce340` |
| VA | `0x004ce340` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004ce340`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

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

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
