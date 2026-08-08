# Function record: FUN_004bb0d0 (scaffold alias)

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bb0d0` |
| **Canonical name** | `Object_ResolveTfIdVtbl1dc_Inferred` |
| **Ghidra / scaffold name** | `FUN_004bb0d0` |
| **Address** | `0x004bb0d0`–`0x004bb0f9` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object-resolve / TFID |
| **Completion status** | **Sealed** — dual A/B 2026-08-04 WQ9R-D; see named record |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept-with-gaps** |

## Alias

Canonical: **`Object_ResolveTfIdVtbl1dc_Inferred`**.  
Prior human plate: `Named_CalleeOf_CVOGHBAIBase_FindTargetToAttack_004bb0d0`.

## Purpose

Resolve TFID blob → `vtbl+0x1dc()`. Full sealed facts in named record.

## Signature (sealed)

```c
// ECX = resolve ctx; stack blob*; RET 4
void * __thiscall Object_ResolveTfIdVtbl1dc_Inferred(void *ctx, TFID_Head *pBlob);
```

## Artifacts

- Named record: `docs/reconstruction/functions/aa_004bb0d0_Object_ResolveTfIdVtbl1dc_Inferred.md`
- Raw: `docs/reconstruction/raw/aa_004bb0d0_FUN_004bb0d0.md`
- Annotated: `docs/reconstruction/raw/aa_004bb0d0_FUN_004bb0d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_ResolveTfIdVtbl1dc_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_004bb0d0.cpp`
- Review A/B: `docs/reconstruction/reviews/A_aa_004bb0d0_Object_ResolveTfIdVtbl1dc_Inferred.md`, `B_aa_004bb0d0_Object_ResolveTfIdVtbl1dc_Inferred.md`
- Report: `docs/agents/task-dual-ab-00943520-004bb0d0-wq9rd-report.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| ECX passthrough + slot `+0x1dc` | **High** |
| Product name of `+0x1dc` | **Tentative** |
