# Function record: FUN_0051bfb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051bfb0` |
| **Canonical name** | `CNDHash_ReclaimAll_ValueOwning_009ce0a8` (prefer named plate) |
| **Ghidra name** | `FUN_0051bfb0` |
| **Address** | `0x0051bfb0`–`0x0051c021` (**0x72** bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash (medal family) |
| **Completion status** | **Dual A/B present** (2026-07-29 W25-F) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

| Name | Status |
|---|---|
| `CNDHash_ReclaimAll_ValueOwning_009ce0a8` | **Canonical** (sealed W25-F) |
| `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0051bfb0` | **Reject** product id |

## Purpose

See named record `aa_0051bfb0_CNDHash_ReclaimAll_ValueOwning_009ce0a8.md`.

## Signature (decompiler-derived)

```c
void __fastcall FUN_0051bfb0(int param_1) // ECX=this; plain ret
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051bfb0_FUN_0051bfb0.md`
- Annotated: `docs/reconstruction/raw/aa_0051bfb0_FUN_0051bfb0.annotated.md`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_0051bfb0.cpp`
- Clean named: `docs/reconstruction/reconstructed-exact/CNDHash_ReclaimAll_ValueOwning_009ce0a8.cpp`
- Dual A/B: `reviews/A_aa_0051bfb0_CNDHash_ReclaimAll_ValueOwning_009ce0a8.md`, `B_*`

## Callers / callees

| Direction | Symbol | Note |
|---|---|---|
| Caller | `FUN_0051d150` / `CNDHash_FreeBuckets` | sole @ `0x0051d15a` |
| Callee | `FUN_00604e30`, `operator_delete` | value destroy |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **Confirmed** |
| Parameter semantic names | **High** (this = CNDHash*) |
| Nested value type | **Tentative** / residual |
