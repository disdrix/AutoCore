# Function record: Object_CopyTfid16At228_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040aff0` |
| **Canonical name** | `Object_CopyTfid16At228_Inferred` |
| **Ghidra name** | `FUN_0040aff0` |
| **Address** | `0x0040aff0`–`0x0040b016` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | identity / TFID (cross-cutting; skills residual consumer) |
| **Name confidence** | **High** role (TFID_16 copy @ +0x228); product English **Inferred** |
| **Completion status** | **Dual residual sealed 2026-08-04 WQ9R-B** — accept |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Leaf helper: copy **16-byte TFID** from **`this+0x228..+0x234`** into caller out buffer. Used by skill filter, AI target find, combat/net, and mission paths after identity/`vtbl+0x214` resolution.

## Signature

```c
TFID_16* __thiscall Object_CopyTfid16At228_Inferred(void* thisObj, TFID_16* out);
// ret 4; EAX = out
```

## Sealed facts

| Claim | Confidence |
|---|---|
| Offset **+0x228**, size **16** | **High** (`add ecx,0x228` + 4 dwords) |
| `__thiscall` + `ret 4` | **High** |
| Leaf | **High** |
| Role = TFID extract (not position) | **High** (callers + `TFID_*` peers) |
| Product symbol | **Open** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0040aff0_FUN_0040aff0.md`
- Annotated: `docs/reconstruction/raw/aa_0040aff0_FUN_0040aff0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_CopyTfid16At228_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_0040aff0.cpp`
- Review A/B: `docs/reconstruction/reviews/A_aa_0040aff0_Object_CopyTfid16At228_Inferred.md`, `B_aa_0040aff0_Object_CopyTfid16At228_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_0040aff0_FUN_0040aff0.md`

## Prior alias

`Named_CalleeOf_CVOGHBAIBase_FindTargetToAttack_0040aff0` — superseded by role name.
