# Annotated (named): InventoryGrid_SortAndRepack_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_00572730` |
| VA | `0x00572730` |
| Canonical | `InventoryGrid_SortAndRepack_Inferred` |
| Date | 2026-07-29 W20-S |

Full annotated body: `docs/reconstruction/raw/aa_00572730_FUN_00572730.annotated.md`.

## Role (one-liner)

Sort inventory items under a caller-supplied comparator by extracting them, selection-picking best each round, placing into a **temporary** same-size grid via FindFree+Place, then committing back to **this** grid (or abort/restore on place failure).
