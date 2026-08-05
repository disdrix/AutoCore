# Function record: CNDHash_ReclaimAll_ValueOwning_009cb360

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e2bd0` |
| **Canonical name** | `CNDHash_ReclaimAll_ValueOwning_009cb360` |
| **Address** | `0x004e2bd0`–`0x004e2c2e` (**94 B** / `0x5E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash (node freelist stamp `009cb360`) |
| **Completion status** | **Dual A/B present** (2026-08-04 W37-J) — accept-with-gaps |
| **Name status** | Stamp-qualified ValueOwning role; no body string |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

| Name | Status |
|---|---|
| `FUN_004e2bd0` | Ghidra scaffold |
| `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004e2bd0` | **Reject** as product id |

## Purpose

Owning full-bucket reclaim: for each bucket `0..mask` inclusive, destroy owned values (`node+0xC` via vtbl(1)), push nodes onto freelist `+0x20`, clear heads. Does **not** zero count or free the bucket table.

## Signature

```c
void __thiscall CNDHash_ReclaimAll_ValueOwning_009cb360(CNDHash *this); // plain ret
```

## Callers / callees

| Direction | Symbol | VA / note |
|---|---|---|
| Caller | `CNDHash_FreeBuckets_009cb45c` | `0x004bccaa` (sole) |
| Callee | virtual `(*value_vtbl)(1)` | owned payload |

## Family

| Sibling | Role |
|---|---|
| `CNDHash_FreeBuckets_009cb45c` `0x004bcca0` | parent FreeBuckets (W31-M) |
| `FUN_004bcae0` `0x004bcae0` | twin reclaim stamp `009cb358` (W37-G) |
| `CNDHash_ReclaimAll_ValueOwning_009cefec` `0x00538200` | medal parallel (W18-J) |
| `CNDHash_ReleaseNodesToFreelist_Inferred` `0x00413ea0` | u64 family same slots |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004e2bd0_FUN_004e2bd0.md`
- Annotated: `docs/reconstruction/raw/aa_004e2bd0_FUN_004e2bd0.annotated.md`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_004e2bd0.cpp`
- Clean named: `docs/reconstruction/reconstructed-exact/CNDHash_ReclaimAll_ValueOwning_009cb360.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004e2bd0_CNDHash_ReclaimAll_ValueOwning_009cb360.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004e2bd0_CNDHash_ReclaimAll_ValueOwning_009cb360.md`
- FUN_ record: `docs/reconstruction/functions/aa_004e2bd0_FUN_004e2bd0.md`
- Dual report: `docs/agents/task-dual-ab-004e2bd0-0055ca90-w37j-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF reclaim / freelist / clear heads | **Confirmed** |
| `__thiscall` plain ret | **Confirmed** |
| Value@+0xC next@+0x10 stamp `009cb360` | **Confirmed** |
| Sole FreeBuckets caller | **Confirmed** |
| Role ValueOwning reclaim | **High** |
| Product/PDB English | **Open** |
| Runtime / bit-exact / diff | **Open** |
