# Function record: FUN_0043bdf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043bdf0` |
| **Canonical name** | `NestedHash_Ctor_Sentinel0x14_Inferred` |
| **Ghidra name** | `FUN_0043bdf0` |
| **Address** | `0x0043bdf0`–`0x0043be51` (**98 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | containers / nested hash bag |
| **Wave** | W34-E OWN-ONLY dual 2026-07-29 |
| **Completion status** | **Sealed accept-with-gaps** — trio + dual A/B |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

- Inferred: `NestedHash_Ctor_Sentinel0x14_Inferred`
- Scaffold (reject as product): `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0043bdf0`

## Purpose

Placement constructor: circular sentinel `new(0x14)`, size 0, 9-bucket pointer table filled with sentinel, flags 1/1. NestedHash span **0x28**.

## Signature

```c
NestedHash_Sentinel0x14* NestedHash_Ctor_Sentinel0x14_Inferred(NestedHash_Sentinel0x14* self /*stack; RET 4*/);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0043bdf0_FUN_0043bdf0.md`
- Annotated: `docs/reconstruction/raw/aa_0043bdf0_FUN_0043bdf0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/NestedHash_Ctor_Sentinel0x14_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0043bdf0.cpp`
- Named record: `docs/reconstruction/functions/aa_0043bdf0_NestedHash_Ctor_Sentinel0x14_Inferred.md`
- Dual A/B: `reviews/A_aa_0043bdf0_NestedHash_Ctor_Sentinel0x14_Inferred.md`, `reviews/B_aa_0043bdf0_NestedHash_Ctor_Sentinel0x14_Inferred.md`

## Callers / callees

| Direction | Target |
|---|---|
| Callees | `FUN_0043c460`, `FUN_004646e0` (PtrVecShell_InitFill) |
| Callers | `FUN_0075d470` @ `0x0075d499`, `FUN_0074d750` @ `0x0074d797` |

## Confidence

| Claim | Level |
|---|---|
| ABI stack self / RET 4 / return self | **High** |
| Layout +8/+0xc/+0x10..+0x24 | **High** |
| Sentinel node size 0x14 | **High** (callee decompile) |
| Product English / flags | **Low / open** |
