# Function record: StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004062a0` |
| **Canonical name** | `StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred` |
| **Ghidra name** | `FUN_004062a0` |
| **Address** | `0x004062a0`–`0x00406316` exclusive (**118 B** / `0x76`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / container (generic; elem stride **0xC** / 12) |
| **Classification** | worker |
| **Calling convention** | **EAX** = vector*; **ECX** = `const T*` value; **`ret 0`** |
| **Completion status** | **Dual A/B sealed** — accept-with-gaps (WQ9H-C 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_004062a0_StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred.md` |
| **Dual B** | `reviews/B_aa_004062a0_StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred.md` |
| **Name confidence** | Inferred (structural; single static consumer still generic util) |
| **Last reviewed** | `2026-08-04` (WQ9H-C) |

## Alias

- Ghidra: `FUN_004062a0`
- Prior scaffold: partial raw/annotated/clean only
- Reject: merge with 0x28 twin; tree/skill naming; product demangle without PDB

## Purpose

MSVC-style **`vector::push_back`** for **12-byte** POD elements:

1. If `begin != 0` and `size < capacity` (both `/0xC`): ConstructN at `end` count=1 (`FUN_00409db0`), then `end += 0xC`.
2. Else: insert-one + rebind at `end` via dualed `StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred` (`0x00406e70`); out discarded.

## Signature

```c
void StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred(
    /*EAX*/ void* vec,
    /*ECX*/ const void* value);
/* ret 0 */
```

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_00409db0` ConstructN (undualed); `FUN_00406e70` insert-one (dualed WQ9G-I) |
| **Callers** | 1 UNCONDITIONAL_CALL @ `0x00930d53` — static vector `DAT_00d1a82c` / `0x00d1a82c` |
| **Twin** | `StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred` (`0x00406220`) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004062a0_FUN_004062a0.md`
- Annotated: `docs/reconstruction/raw/aa_004062a0_FUN_004062a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_004062a0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_004062a0_FUN_004062a0.md`
- Report: `docs/agents/task-dual-ab-00406220-004062a0-wq9hc-report.md`

## Confidence

| Claim | Level |
|---|---|
| Body + ret 0 + EAX/ECX ABI | **High** |
| Dual-path push_back CF /0xC | **High** |
| Callee links | **High** |
| Product demangle | **Inferred** |
| Runtime / bit-exact | **Open** |
