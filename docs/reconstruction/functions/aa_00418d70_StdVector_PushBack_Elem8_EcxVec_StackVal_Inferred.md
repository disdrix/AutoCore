# Function record: StdVector_PushBack_Elem8_EcxVec_StackVal_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00418d70` |
| **Canonical name** | `StdVector_PushBack_Elem8_EcxVec_StackVal_Inferred` |
| **Ghidra name** | `FUN_00418d70` |
| **Address** | `0x00418d70`–`0x00418dc6` exclusive (**86 B** / `0x56`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / container (generic; elem stride **8**) |
| **Classification** | worker |
| **Calling convention** | **ECX** = vector*; stack `const T*` value; **`RET 4`** |
| **Completion status** | **Dual A/B sealed** — accept-with-gaps (R10-025 2026-08-05) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_00418d70_StdVector_PushBack_Elem8_EcxVec_StackVal_Inferred.md` |
| **Dual B** | `reviews/B_aa_00418d70_StdVector_PushBack_Elem8_EcxVec_StackVal_Inferred.md` |
| **Name confidence** | Inferred (structural; multi-domain consumers) |
| **Last reviewed** | `2026-08-05` (R10-025) |

## Alias

- Ghidra: `FUN_00418d70`
- Prior scaffold: `FUN_00418d70` / `Named_CalleeOf_Named_VOG_DEBUG_STOP_00418d70`
- Reject: VOG_DEBUG_STOP plate; crew-only product lock; merge with Elem12/Elem0x28 push twins

## Purpose

MSVC-style **`vector::push_back`** for **8-byte** POD elements:

1. If `begin != 0` and `size < capacity` (both `/8`): raw-copy two dwords at `end`, then `end += 8`.
2. Else: insert-one + rebind at `end` via `FUN_00418e10` (undualed residual).

## Signature

```c
void StdVector_PushBack_Elem8_EcxVec_StackVal_Inferred(
    /*ECX*/ void* vec,
    /*stack*/ const uint32_t* value);
/* RET 4 */
```

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_00418e10` insert-one/rebind (undualed) |
| **Callers** | 13 UNCONDITIONAL_CALL — parent `0x005755b0` VehicleCrew_InsertMember_Inferred @ `0x0057567e`; multi-domain peers |
| **Related** | Elem12 push `0x004062a0`; Elem0x28 push `0x00406220` (different ABI/stride) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00418d70_FUN_00418d70.md`
- Annotated: `docs/reconstruction/raw/aa_00418d70_FUN_00418d70.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_PushBack_Elem8_EcxVec_StackVal_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_00418d70.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00418d70_FUN_00418d70.md`
- Report: `docs/agents/task-dual-ab-00418d70-r10-report.md`

## Confidence

| Claim | Level |
|---|---|
| Body + RET 4 + ECX/stack ABI | **Confirmed** |
| Dual-path push_back CF /8 | **Confirmed** |
| Callee link `00418e10` | **Confirmed** |
| Product demangle | **Inferred** |
| Runtime / bit-exact | **Open** |
