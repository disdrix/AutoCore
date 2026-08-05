# Function record: FUN_004bcce0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcce0` |
| **Canonical name** | `FUN_004bcce0` → prefer **`CNDHash_Recreate_009cb450`** |
| **Address** | `0x004bcce0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash |
| **Completion status** | **Dual A/B present** (2026-07-29 W30-G) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Named: `CNDHash_Recreate_009cb450`
- Prior: `Named_VOG_DEBUG_STOP_004bcce0` (rejected)

## Purpose

CNDHash Recreate for object vtbl family `009cb450`: FreeBuckets `FUN_004bcc60` → set log2/N/head/tail → AllocBucketTable `FUN_004bc7a0`.

## Signature (decompiler-derived)

```c
void __thiscall FUN_004bcce0(int param_1, byte param_2); // ret 4
```

## Artifacts

- Named record: `docs/reconstruction/functions/aa_004bcce0_CNDHash_Recreate_009cb450.md`
- Dual A/B under reviews/
- Raw / annotated / clean as listed in named record

## Callers / callees

- Callers: `FUN_004bbeb0` (always log2=5)
- Callees: `FUN_004bcc60`, `FUN_004bc7a0`, `FUN_007a4480`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| Parameter is log2 | **High** |
| Types / product English | Tentative / Open |
