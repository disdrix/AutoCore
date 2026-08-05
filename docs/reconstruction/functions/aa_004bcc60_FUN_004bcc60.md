# Function record: FUN_004bcc60

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcc60` |
| **Canonical name** | `FUN_004bcc60` (Ghidra scaffold) |
| **Named** | `CNDHash_FreeBuckets_009cb450` |
| **Address** | `0x004bcc60`–`0x004bcc94` (**52 B / `0x34`**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash (tableC) |
| **Completion status** | **Dual A/B present** (2026-07-29 W31-M) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

| Name | Status |
|---|---|
| `CNDHash_FreeBuckets_009cb450` | **Accept** role name (object family `009cb450`) |
| `Named_CalleeOf_Named_VOG_DEBUG_STOP_004bcc60` | **Reject** as product id |

## Purpose

CNDHash FreeBuckets twin for tableC family: zero count → owning reclaim (`FUN_004bcae0`) → free sentinel slab + delete[] bucket table.

## Signature

```c
void __thiscall CNDHash_FreeBuckets_009cb450(CNDHash *this); // plain ret
// Ghidra: void __fastcall FUN_004bcc60(int param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bcc60_FUN_004bcc60.md`
- Annotated: `docs/reconstruction/raw/aa_004bcc60_FUN_004bcc60.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004bcc60.cpp`
- Named: `docs/reconstruction/reconstructed-exact/CNDHash_FreeBuckets_009cb450.cpp`
- Named function: `docs/reconstruction/functions/aa_004bcc60_CNDHash_FreeBuckets_009cb450.md`
- Dual A/B: `docs/reconstruction/reviews/A_aa_004bcc60_CNDHash_FreeBuckets_009cb450.md`, `B_…`

## Confidence

| Claim | Level |
|---|---|
| CF from decompile ≡ bytes | **Confirmed** |
| Twin of `004bcca0` (reloc-only) | **Confirmed** |
| `__thiscall` plain ret | **Confirmed** |
| Role FreeBuckets | **High** |
| Product/PDB symbol | **Open** |
