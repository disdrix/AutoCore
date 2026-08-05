# Function record: InventoryGrid_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00572650` |
| **Canonical name** | `InventoryGrid_ctor_Inferred` |
| **Address** | `0x00572650` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined clean C++** — runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

In-place construct a `0x68`-byte inventory grid: vtables, critical section, RB-tree sentinel, width/height/pages (clamped ≥1), then `InventoryGrid_AllocateCellArray_Inferred`.

## Signature (decompiler-derived)

```c
void* __thiscall InventoryGrid_ctor_Inferred(void* this, int nWidth, int nHeight, int nPages);
```

Cargo default: width `6`, height `pages*13`, pages from chassis `InventorySlots`.

## Behavioral summary

Init nested CS-host at `+0x2C`, tree at `+0x60`, store dims at `+0x08/+0x0C/+0x14`, allocate empty cells.

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | High |
| Signature | Probable |
| Control flow | High |
| Naming | Probable (INFERRED) |
| Side effects | High |
| Overall | Probable — clean refined |

## Open questions

- Retail ctor symbol; full field map for `+0x20..+0x58`

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_00572650_InventoryGrid_ctor_Inferred.md` |
| Annotated | `raw/aa_00572650_InventoryGrid_ctor_Inferred.annotated.md` |
| Clean | `reconstructed-exact/InventoryGrid_ctor_Inferred.cpp` |
