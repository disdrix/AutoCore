# Function record: StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406220` |
| **Canonical name** | `StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred` |
| **Ghidra name** | `FUN_00406220` |
| **Address** | `0x00406220`–`0x00406298` exclusive (**120 B** / `0x78`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / container (generic; elem stride **0x28**) |
| **Classification** | worker |
| **Calling convention** | **EAX** = vector*; **ECX** = `const T*` value; **`ret 0`** |
| **Completion status** | **Dual A/B sealed** — accept-with-gaps (WQ9H-C 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_00406220_StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred.md` |
| **Dual B** | `reviews/B_aa_00406220_StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred.md` |
| **Name confidence** | Inferred (structural; multi-caller generic util) |
| **Last reviewed** | `2026-08-04` (WQ9H-C) |

## Alias

- Ghidra: `FUN_00406220`
- Prior scaffold: partial raw/annotated/clean only
- Reject: tree/buynode naming; dword push_back `EAX`/`ESI` family; product demangle without PDB

## Purpose

MSVC-style **`vector::push_back`** for **0x28-byte** POD elements:

1. If `begin != 0` and `size < capacity` (both `/0x28`): ConstructN at `end` count=1 (`FUN_00409d40`), then `end += 0x28`.
2. Else: insert-one + rebind at `end` via dualed `StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred` (`0x00406de0`); out-iterator discarded.

## Signature

```c
void StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred(
    /*EAX*/ void* vec,
    /*ECX*/ const void* value);
/* ret 0 */
```

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_00409d40` ConstructN (undualed; WQ9H-B owns); `FUN_00406de0` insert-one (dualed WQ9G-H) |
| **Callers** | `FUN_00933480` @ `0x009335fb` (`EAX=*(ESI+0xc80)+0x68`); `FUN_00976900` @ `0x00976b7c` (`EAX=ESI+0x68`) |
| **Twin** | `StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred` (`0x004062a0`) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00406220_FUN_00406220.md`
- Annotated: `docs/reconstruction/raw/aa_00406220_FUN_00406220.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00406220.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00406220_FUN_00406220.md`
- Report: `docs/agents/task-dual-ab-00406220-004062a0-wq9hc-report.md`

## Confidence

| Claim | Level |
|---|---|
| Body + ret 0 + EAX/ECX ABI | **High** |
| Dual-path push_back CF /0x28 | **High** |
| Callee links | **High** |
| Product demangle | **Inferred** |
| Runtime / bit-exact | **Open** |
