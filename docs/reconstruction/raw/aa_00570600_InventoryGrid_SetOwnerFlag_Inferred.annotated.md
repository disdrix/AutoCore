# Annotated low-level: InventoryGrid_SetOwnerFlag_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_00570600` |
| VA | `0x00570600` |
| System | inventory-transfer |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00570600`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* InventoryGrid_SetOwnerFlag_Inferred — write int flag at grid+0x4.
   
   Parameters: this grid; nFlag (cargo path always passes 1 after ctor).
   Returns: void.
   
   Trivial setter. Name INFERRED from cargo create call site only. */

void __thiscall InventoryGrid_SetOwnerFlag_Inferred(void *this,int nFlag)

{
  *(int *)((int)this + 4) = nFlag;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
