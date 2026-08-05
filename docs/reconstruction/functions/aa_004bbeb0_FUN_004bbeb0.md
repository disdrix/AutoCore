# Function record: FUN_004bbeb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bbeb0` |
| **Canonical name** | `FUN_004bbeb0` (scaffold; prefer `Host_ResetHashQueuesVectors_Inferred`) |
| **Address** | `0x004bbeb0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | host table reset |
| **Completion status** | **Dual-reviewed** W31-N — **accept-with-gaps** (see named record) |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

Canonical: `Host_ResetHashQueuesVectors_Inferred`.  
**Reject** scaffold `Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update_004bbeb0`.

## Purpose

See `aa_004bbeb0_Host_ResetHashQueuesVectors_Inferred.md`.

## Signature

```c
void __fastcall FUN_004bbeb0(Host_ResetTables* self);
```

## Artifacts

- Named: `docs/reconstruction/functions/aa_004bbeb0_Host_ResetHashQueuesVectors_Inferred.md`
- Raw: `docs/reconstruction/raw/aa_004bbeb0_FUN_004bbeb0.md`
- Annotated: `docs/reconstruction/raw/aa_004bbeb0_FUN_004bbeb0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Host_ResetHashQueuesVectors_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004bbeb0.cpp`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_004d98f0`, `FUN_00943b80` |
| Callees | `FUN_004bcce0`, `FUN_004bc580`×3, `FUN_00410420`×3 |

## Confidence

| Claim | Level |
|---|---|
| Control flow from bytes | **High** |
| Product class name | **Low** |
