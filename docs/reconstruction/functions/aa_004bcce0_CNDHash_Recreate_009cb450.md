# Function record: CNDHash_Recreate_009cb450

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcce0` |
| **Canonical name** | `CNDHash_Recreate_009cb450` |
| **Address** | `0x004bcce0`–`0x004bcd34` (**84 B / `0x54`**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash (COList tableC; object vtbl `009cb450`) |
| **Completion status** | **Dual A/B present** (2026-07-29 W30-G) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Ghidra: `FUN_004bcce0`
- Prior scaffold: `Named_VOG_DEBUG_STOP_004bcce0` (**rejected**)

## Purpose

Tear down + re-allocate empty CNDHash buckets for stamp family `009cb450` / Alloc sentinel `009cb348`. Sole static caller always uses **log2=5** (N=32 → mask 31 after Alloc).

## Signature

```c
void __thiscall CNDHash_Recreate_009cb450(CNDHash *this, uint8_t log2); // ret 4
```

## Call surface

| Direction | Detail |
|---|---|
| Callees | `FUN_004bcc60` FreeBuckets; `FUN_004bc7a0` AllocBucketTable_009cb348; `FUN_007a4480` ×2 |
| Callers | `FUN_004bbeb0` @ `0x004bbeb8` → always `(5)` |
| Twin | `CNDHash_Recreate_009cb45c` @ `0x004bcd40` |

## Artifacts

- Dual A: `docs/reconstruction/reviews/A_aa_004bcce0_CNDHash_Recreate_009cb450.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004bcce0_CNDHash_Recreate_009cb450.md`
- Raw: `docs/reconstruction/raw/aa_004bcce0_FUN_004bcce0.md`
- Annotated: `docs/reconstruction/raw/aa_004bcce0_FUN_004bcce0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/CNDHash_Recreate_009cb450.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004bcce0.cpp`
- Legacy record: `docs/reconstruction/functions/aa_004bcce0_FUN_004bcce0.md`
- Agent report: `docs/agents/task-dual-ab-004bcd40-004bcce0-w30g-report.md`

## Confidence

| Claim | Level |
|---|---|
| ABI / CF / ret 4 / log2 polarity | **High** |
| Sole caller log2=5 | **High** |
| Stamp-qualified name | **Inferred** |
| Runtime / bit-exact | **Open** |
