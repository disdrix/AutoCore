# Function record: FUN_004bcd40

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcd40` |
| **Canonical name** | `FUN_004bcd40` → prefer **`CNDHash_Recreate_009cb45c`** |
| **Address** | `0x004bcd40` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash |
| **Completion status** | **Dual A/B present** (2026-07-29 W30-G) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Named: `CNDHash_Recreate_009cb45c`
- Prior: `Named_VOG_DEBUG_STOP_004bcd40` (rejected)

## Purpose

CNDHash Recreate for object vtbl family `009cb45c`: FreeBuckets `FUN_004bcca0` → set log2/N/head/tail → AllocBucketTable `FUN_004bc840`.

## Signature (decompiler-derived)

```c
void __thiscall FUN_004bcd40(int param_1, byte param_2); // ret 4
```

## Artifacts

- Named record: `docs/reconstruction/functions/aa_004bcd40_CNDHash_Recreate_009cb45c.md`
- Dual A/B under reviews/
- Raw / annotated / clean as listed in named record

## Callers / callees

- Callers: **none** static
- Callees: `FUN_004bcca0`, `FUN_004bc840`, `FUN_007a4480`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| Parameter is log2 | **High** |
| Types / product English | Tentative / Open |
