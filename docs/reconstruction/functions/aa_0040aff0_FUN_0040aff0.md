# Function record: FUN_0040aff0 (scaffold)

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040aff0` |
| **Canonical name** | `Object_CopyTfid16At228_Inferred` (prefer named record) |
| **Ghidra name** | `FUN_0040aff0` |
| **Address** | `0x0040aff0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | identity / TFID |
| **Completion status** | **Dual residual sealed 2026-08-04 WQ9R-B** — see named record |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- **Named:** `Object_CopyTfid16At228_Inferred`
- Prior scaffold: `Named_CalleeOf_CVOGHBAIBase_FindTargetToAttack_0040aff0`

## Purpose

Copy TFID_16 from `this+0x228` to out buffer. Leaf; `ret 4`.

## Signature (decompiler-derived)

```c
void __thiscall FUN_0040aff0(int param_1, uint32_t *param_2)
```

## Artifacts

- Named record: `docs/reconstruction/functions/aa_0040aff0_Object_CopyTfid16At228_Inferred.md`
- Raw / annotated / clean under `aa_0040aff0` / `Object_CopyTfid16At228_Inferred`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **High** |
| Parameter semantic names | **High** (out TFID); this type product open |
| Types | **High** as TFID_16 layout; field English Tentative |
