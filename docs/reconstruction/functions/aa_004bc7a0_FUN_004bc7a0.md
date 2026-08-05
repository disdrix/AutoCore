# Function record: FUN_004bc7a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bc7a0` |
| **Canonical name** | `CNDHash_AllocBucketTable_009cb348` (prefer named plate) |
| **Ghidra name** | `FUN_004bc7a0` |
| **Address** | `0x004bc7a0`–`0x004bc830` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash (COList tableC) |
| **Completion status** | **Dual A/B present** (2026-07-29 W29-K) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

| Name | Status |
|---|---|
| `CNDHash_AllocBucketTable_009cb348` | **Canonical** (sealed W29-K) |
| `Named_VOG_DEBUG_STOP_004bc7a0` | **Reject** product id |

## Purpose

See named record `aa_004bc7a0_CNDHash_AllocBucketTable_009cb348.md`.

## Signature (decompiler-derived)

```c
void __fastcall FUN_004bc7a0(int param_1) // ECX=this; plain ret or throw
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bc7a0_FUN_004bc7a0.md`
- Annotated: `docs/reconstruction/raw/aa_004bc7a0_FUN_004bc7a0.annotated.md`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_004bc7a0.cpp`
- Clean named: `docs/reconstruction/reconstructed-exact/CNDHash_AllocBucketTable_009cb348.cpp`
- Dual A/B: `reviews/A_aa_004bc7a0_CNDHash_AllocBucketTable_009cb348.md`, `B_*`

## Callers / callees

| Direction | Symbol | Note |
|---|---|---|
| Caller | `FUN_004bce90` ctor `CNDHash_Ctor_009cb450` | `@ 0x004bceea` |
| Caller | `FUN_004bcce0` Recreate | `@ 0x004bcd2c` |
| Callee | `operator_new[]`, `malloc`, throw helpers | |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **Confirmed** |
| Parameter semantic names | **High** (this = CNDHash*) |
| Types (sentinel / table) | **High** structural |
