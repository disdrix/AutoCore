# Annotated low-level: CVOGCharacter_IsAreaExplored

| Field | Value |
|---|---|
| Stable ID | `aa_0052b310` |
| VA | `0x0052b310` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0052b310`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* thiscall on CVOGCharacter: is explored-area bit set?
   Looks up USContinentUnlocked hash at this+0x534; tests ExploredBits bit (areaId-1).
   Area ids valid 1..32. */

bool __thiscall CVOGCharacter_IsAreaExplored(void *this,int continentId,char areaId)

{
  void *pvVar1;
  
  if (('\0' < areaId) && (areaId < '!')) {
    pvVar1 = CNDHash_LookupByKey(*(void **)((int)this + 0x534),continentId);
    if (pvVar1 != (void *)0x0) {
      return (*(uint *)((int)pvVar1 + 8) & 1 << (areaId - 1U & 0x1f)) != 0;
    }
  }
  return false;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
