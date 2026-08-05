# Function record: CNDHash_ValueClearOwnedPtrs

| Field | Value |
|---|---|
| **Stable ID** | `aa_00604e30` |
| **Canonical name** | `CNDHash_ValueClearOwnedPtrs` |
| **Ghidra name** | `FUN_00604e30` |
| **Address** | `0x00604e30`–`0x00604e84` (**85 B** / `0x55`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash (medal family; nested value teardown for stamp `009ce0a8`) |
| **Completion status** | **Dual A/B present** (2026-07-29 W26-P) — accept-with-gaps |
| **Name status** | Role inferred from callers + field matrix; no body string |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

| Name | Status |
|---|---|
| `FUN_00604e30` | Ghidra scaffold |
| `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00604e30` | **Reject** as product id |

## Purpose

Clear four owned heap pointer slots on a CNDHash node **value** (`+4/+8/+0xC/+0x10`): delete-if-nonnull then zero. Does not free the value object; parent reclaim/dtor does.

## Signature

```c
void __fastcall CNDHash_ValueClearOwnedPtrs(void *value); // MSVC thiscall; plain ret
```

## Callers / callees

| Direction | Symbol | VA / note |
|---|---|---|
| Caller | `CNDHash_ReclaimAll_ValueOwning_009ce0a8` (`FUN_0051bfb0`) | `0x0051bfe4` |
| Caller | `FUN_0051bd90` (scalar dtor `009ce0a8`) | `0x0051bda3` |
| Callee | `operator_delete` | ×4; cdecl; returns |

## Family

| Sibling | Role |
|---|---|
| `CNDHash_ReclaimAll_ValueOwning_009ce0a8` `0x0051bfb0` | parent reclaim (calls this then free value) |
| Plain owning reclaim `009cefec` / `009cefe4` | free value only — no nested clear |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00604e30_FUN_00604e30.md`
- Annotated: `docs/reconstruction/raw/aa_00604e30_FUN_00604e30.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/CNDHash_ValueClearOwnedPtrs.cpp`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_00604e30.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00604e30_CNDHash_ValueClearOwnedPtrs.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00604e30_CNDHash_ValueClearOwnedPtrs.md`
- FUN_ record: `docs/reconstruction/functions/aa_00604e30_FUN_00604e30.md`

## Confidence

| Claim | Level |
|---|---|
| Four-slot delete-if-nonnull + zero | **Confirmed** |
| thiscall ECX=value; plain ret | **Confirmed** |
| `operator_delete` returns | **Confirmed** |
| Callers reclaim + scalar dtor | **Confirmed** (2 xrefs) |
| Role nested value clear | **High** |
| Product/PDB symbol | **Open** |
| Pointee types of 4 slots | **Open** |
| Runtime / bit-exact / diff | **Open** |
