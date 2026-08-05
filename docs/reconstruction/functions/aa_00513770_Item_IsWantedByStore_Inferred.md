# Function record: Item_IsWantedByStore_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513770` |
| **Canonical name** | `Item_IsWantedByStore_Inferred` |
| **Address** | `0x00513770` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Completion status** | **Human-refined** — dual A/B sealed 2026-07-29 (store-want predicate + toast polarity); runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

| Name | Status |
|------|--------|
| `FUN_00513770` | Ghidra default |
| `Named_CalleeOf_Client_UI_InventoryDropToGrid_00513770` | parent-seed scaffold |

## Purpose

Item thiscall bool: ensure clonebase definition loaded, then accept for store/vendor paths iff def missing **or** `*(i32*)(def+0x3B4)==1`. False → UI **"The store does not want that item."** Does not price, place, or send packets.

## Signature (asm-sealed)

```c
// bool in AL; plain RET
unsigned char __thiscall Item_IsWantedByStore_Inferred(void* /*Item**/ this);
```

## Behavioral summary

1. `clonebase = *(this+0xA8)`
2. If `*(clonebase+0x3C)==0` → `FUN_004f1e20(clonebase, 0, 1)`
3. Re-read `def = *(clonebase+0x3C)`
4. `def==0` → return **1** (fail-open)
5. Else return `*(def+0x3B4)==1` as bool

## Callers / callees

**Callees:** `FUN_004f1e20` only.

**Callers (7 sites):** `Client_UI_InventoryDropToGrid` (`0x00860C6E`), UI sell siblings (`0x008613C1`, `0x008903A8`), trade UI (`0x008B8F56`, `0x0090960C`), `FUN_00587970` (credits), `FUN_00942530` (bulk `0x2027` sell).

**Sibling:** `FUN_005142A0` — same gate then sell-value math.

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary / CF | **High** |
| Signature (thiscall, 0 stack) | **High** |
| Clonebase `+0xA8` / def `+0x3C` | **High** |
| Flag `def+0x3B4==1` | **High** |
| Toast polarity | **High** |
| Naming (product) | **Probable** (`_Inferred`) |
| Runtime / diff | **Open** |
| Overall | **Probable** — dual accept-with-gaps |

## Open questions

- Product/PDB name for VA and field `+0x3B4`
- Full ensure-load semantics of `FUN_004f1e20`
- Runtime golden paths

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_00513770_FUN_00513770.md` |
| Annotated | `raw/aa_00513770_FUN_00513770.annotated.md` |
| Clean | `reconstructed-exact/Item_IsWantedByStore_Inferred.cpp` |
| Dual A | `reviews/A_aa_00513770_Item_IsWantedByStore_Inferred.md` |
| Dual B | `reviews/B_aa_00513770_Item_IsWantedByStore_Inferred.md` |
| Residual | `reviews/a_00513770.md` |
| Scaffold clean (legacy) | `reconstructed-exact/FUN_00513770.cpp` |
