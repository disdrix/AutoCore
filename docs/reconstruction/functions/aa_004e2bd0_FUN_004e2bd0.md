# Function record: FUN_004e2bd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e2bd0` |
| **Canonical name** | `FUN_004e2bd0` (scaffold) |
| **Named** | `CNDHash_ReclaimAll_ValueOwning_009cb360` |
| **Address** | `0x004e2bd0`–`0x004e2c2e` (**94 B** / `0x5E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash |
| **Completion status** | **Dual A/B present** (2026-08-04 W37-J) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

| Name | Status |
|---|---|
| `CNDHash_ReclaimAll_ValueOwning_009cb360` | **Accept** (W37-J) |
| `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004e2bd0` | **Reject** |

## Purpose

Owning CNDHash reclaim: destroy values at node+0xC, push nodes to freelist+0x20, clear bucket heads for indices 0..mask. Sole caller FreeBuckets `004bcca0`.

## Signature

```c
void __thiscall CNDHash_ReclaimAll_ValueOwning_009cb360(CNDHash *this);
```

## Artifacts

- Named record: `docs/reconstruction/functions/aa_004e2bd0_CNDHash_ReclaimAll_ValueOwning_009cb360.md`
- Raw: `docs/reconstruction/raw/aa_004e2bd0_FUN_004e2bd0.md`
- Annotated: `docs/reconstruction/raw/aa_004e2bd0_FUN_004e2bd0.annotated.md`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_004e2bd0.cpp`
- Clean named: `docs/reconstruction/reconstructed-exact/CNDHash_ReclaimAll_ValueOwning_009cb360.cpp`
- Dual A/B under `docs/reconstruction/reviews/`
- Report: `docs/agents/task-dual-ab-004e2bd0-0055ca90-w37j-report.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow | **Confirmed** |
| Role / stamp | **High** |
| Product English | **Open** |
