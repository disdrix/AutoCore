# Function record: StdVector_InsertN_Elem0x10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00408640` |
| **Canonical name** | `StdVector_InsertN_Elem0x10_Inferred` |
| **Ghidra name** | `FUN_00408640` |
| **Prior aliases** | `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB_00408640` (**rejected** as role) |
| **Address** | `0x00408640`–`0x0040887c` exclusive (**572 B** / `0x23C`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / container |
| **Completion status** | **Dual-sealed 2026-08-04 WQ9H-H** — insert-N CF/ABI/stride0x10 **High**; product demangle open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Terminal** | false |

## Purpose

MSVC-style `std::vector` **insert-n** for **16-byte** POD elements. 1.5× capacity growth; triad at `+4/+8/+0xC`.

## Signature

```c
// ECX=count, EDX=vec*, stack where + const T* value; RET 8
void __fastcall StdVector_InsertN_Elem0x10_Inferred(
    uint32_t count,
    VectorElem0x10 *vec,
    uint8_t *where,
    const VecElem0x10 *value);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00408640_FUN_00408640.md`
- Annotated: `docs/reconstruction/raw/aa_00408640_FUN_00408640.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_InsertN_Elem0x10_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00408640.cpp`
- Reviews: `reviews/A_aa_00408640_StdVector_InsertN_Elem0x10_Inferred.md`, `reviews/B_aa_00408640_StdVector_InsertN_Elem0x10_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_00408640_FUN_00408640.md`
- Agent report: `docs/agents/task-dual-ab-00408590-00408640-wq9hh-report.md`

## Callers / callees

| Direction | VA / name | Notes |
|---|---|---|
| Caller | `FUN_00930360` @ `0x009305c5` | sole; count=1 at site |
| Callee | `FUN_00418130` | size overflow |
| Callee | `operator_new` / `operator_delete` | realloc |
| Callee | `FUN_00409b60` | range copy → `0040a670` |
| Callee | `FUN_00407000` | construct-N 0x10 |
| Callee | `FUN_0040a670` | move/copy range |
| Callee | `FUN_0045f050` | in-place fill |
| Callee | `FUN_00465bc0` | post-insert residual |

## Related units

| VA | Name | Relation |
|---|---|---|
| `0x004073a0` | `StdVector_InsertN_Dword_Inferred` | same role; stride **4**; thiscall |
| `0x00408050` | InsertN elem **0x28** residual | neighborhood InsertN twin family |
| `0x00407000` | construct-N 0x10 | fill helper used here |

## Confidence

| Claim | Level |
|---|---|
| Insert-N + 1.5× growth | **High** |
| Stride 0x10 + RET 8 ABI | **High** |
| Product POD English type | **Inferred** / open |
| Helper dual seals | Open residual |
