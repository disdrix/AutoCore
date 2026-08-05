# Function record: CNDHash_Recreate_009cb45c

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcd40` |
| **Canonical name** | `CNDHash_Recreate_009cb45c` |
| **Address** | `0x004bcd40`–`0x004bcd94` (**84 B / `0x54`**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash (COList hashA/hashB; object vtbl `009cb45c`) |
| **Completion status** | **Dual A/B present** (2026-07-29 W30-G) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Ghidra: `FUN_004bcd40`
- Prior scaffold: `Named_VOG_DEBUG_STOP_004bcd40` (**rejected** as product id)

## Purpose

Tear down existing bucket table + freelist contents, then re-allocate empty power-of-two buckets for CNDHash stamp family `009cb45c` / Alloc sentinel `009cb350`. Param is **log2**, not count. Lock at `+0x1D` logs only.

## Signature

```c
void __thiscall CNDHash_Recreate_009cb45c(CNDHash *this, uint8_t log2); // ret 4
```

## Call surface

| Direction | Detail |
|---|---|
| Callees | `FUN_004bcca0` FreeBuckets; `FUN_004bc840` AllocBucketTable_009cb350; `FUN_007a4480` ×2 |
| Callers | **none** static (zero xrefs) |
| Twin | `CNDHash_Recreate_009cb450` @ `0x004bcce0` |

## Artifacts

- Dual A: `docs/reconstruction/reviews/A_aa_004bcd40_CNDHash_Recreate_009cb45c.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004bcd40_CNDHash_Recreate_009cb45c.md`
- Raw: `docs/reconstruction/raw/aa_004bcd40_FUN_004bcd40.md`
- Annotated: `docs/reconstruction/raw/aa_004bcd40_FUN_004bcd40.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/CNDHash_Recreate_009cb45c.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004bcd40.cpp`
- Legacy record: `docs/reconstruction/functions/aa_004bcd40_FUN_004bcd40.md`
- Agent report: `docs/agents/task-dual-ab-004bcd40-004bcce0-w30g-report.md`

## Confidence

| Claim | Level |
|---|---|
| ABI / CF / ret 4 / log2 polarity | **High** |
| CNDHash Recreate family (string + twin chain) | **High** |
| Stamp-qualified name | **Inferred** |
| FreeBuckets / Alloc callee post-conditions | **High** (siblings sealed W29-K) |
| Static callers | **High** (none) |
| Runtime / bit-exact | **Open** |
