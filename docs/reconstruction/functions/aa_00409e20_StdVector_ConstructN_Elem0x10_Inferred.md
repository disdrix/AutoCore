# Function record: StdVector_ConstructN_Elem0x10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409e20` |
| **Canonical name** | `StdVector_ConstructN_Elem0x10_Inferred` |
| **Ghidra name** | `FUN_00409e20` |
| **Prior aliases** | `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB_00409e20` (**rejected** as role) |
| **Address** | `0x00409e20`–`0x00409e82` inclusive (**99 B** / `0x63`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / container |
| **Completion status** | **Dual-sealed 2026-08-05 MEGA-044** — ConstructN CF/ABI/stride0x10 **High**; product demangle open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Terminal** | false |

## Purpose

MSVC-style `std::vector` **ConstructN** (uninitialized fill-N from one template) for **16-byte** POD elements. SEH-framed loop; PodCopy leaf `FUN_00409f70`.

## Signature

```c
// cdecl; ECX=value*; stack dest*, count; RET (C3)
void StdVector_ConstructN_Elem0x10_Inferred(
    /*ECX*/ const void* value,
    /*stack*/ void* dest,
    /*stack*/ int count);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00409e20_FUN_00409e20.md`
- Annotated: `docs/reconstruction/raw/aa_00409e20_FUN_00409e20.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_ConstructN_Elem0x10_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00409e20.cpp`
- Reviews: `reviews/A_aa_00409e20_StdVector_ConstructN_Elem0x10_Inferred.md`, `reviews/B_aa_00409e20_StdVector_ConstructN_Elem0x10_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_00409e20_FUN_00409e20.md`
- Agent report: `docs/agents/task-dual-ab-00409e20-mega-044-report.md`

## Callers / callees

| Direction | VA / name | Notes |
|---|---|---|
| Caller | `FUN_00407000` @ `0x0040700c` | wrapper returns dest+count*0x10; used by InsertN `00408640` |
| Caller | `FUN_00930360` @ `0x009305a5` | SortTargetListByViewAngle; count=1 capacity path |
| Callee | `FUN_00409f70` | PodCopy 4 dwords if dest≠null |

## Related units

| VA | Name | Relation |
|---|---|---|
| `0x00408640` | `StdVector_InsertN_Elem0x10_Inferred` | dualed insert-N parent (via `00407000`) |
| `0x00407000` | construct-N wrapper / end pointer | residual |
| `0x00409f70` | PodCopy elem 0x10 | residual leaf |
| `0x00409d40` | `StdVector_ConstructN_Elem0x28_Inferred` | twin ConstructN other stride |
| `0x00409db0` | `StdVector_ConstructN_Elem12_Inferred` | twin ConstructN other stride |
| `0x00930360` | Client_SortTargetListByViewAngle | direct count=1 consumer |

## Confidence

| Claim | Level |
|---|---|
| ConstructN fill-from-template | **High** |
| Stride 0x10 + cdecl RET ABI | **High** |
| Product POD English type | **Inferred** / open |
| Helper dual seals (`00409f70`, `00407000`) | Open residual |

