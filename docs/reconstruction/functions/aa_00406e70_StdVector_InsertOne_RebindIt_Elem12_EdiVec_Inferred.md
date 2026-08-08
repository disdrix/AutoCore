# Function record: StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406e70` |
| **Canonical name** | `StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred` |
| **Ghidra name** | `FUN_00406e70` |
| **Address** | `0x00406e70` |
| **Body range** | `0x00406e70` – `0x00406ed8` (**104 B** / `0x68`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / container (generic) |
| **Calling convention** | **EDI** = vector host; stack `T** out`, `T* where`, `const T* value`; **`ret 0x0C`**; EAX=out* |
| **Completion status** | **Dual A/B sealed** — accept-with-gaps (WQ9G-I 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_00406e70_StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred.md` |
| **Dual B** | `reviews/B_aa_00406e70_StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9G-I) |

## Alias

- Ghidra: `FUN_00406e70`
- Scaffold record: `functions/aa_00406e70_FUN_00406e70.md`
- Reject: skill/mission-domain names — generic vector helper

## Purpose

MSVC-style **insert exactly one 12-byte POD element** then **rebind out-iterator** after possible realloc of `begin`. Bridges to residual InsertN `FUN_004082f0` with **count = 1**.

## Signature

```c
// customcc
Pod12** StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred(
    /*EDI*/ void* vec,           // +4 begin, +8 end, +0xC capEnd
    /*stack*/ Pod12** outIt,
    /*stack*/ Pod12* where,
    /*stack*/ const Pod12* value);
/* ret 0x0C; EAX = outIt */
```

## Behavioral summary

1. `index = empty ? 0 : (where - begin) / 12`
2. `InsertN(vec, where, count=1, value)` via `004082f0`
3. `*outIt = begin' + index * 12`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_004082f0` (InsertN elem 0xC; undualed residual) |
| **Callers** | `FUN_004062a0` only (push_back slow path @ `0x0040630c`) |
| **Pair** | `aa_00406ee0` `StdVector_UninitializedFillN_Elem12_Inferred` (Ufill used inside InsertN) |
| **Twins** | `0040dbf0` thiscall dword; `0040b6d0` EDI dword; `00406de0` InsertOne elem 0x28 |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00406e70_FUN_00406e70.md` (+ WQ9G-I append)
- Annotated: `docs/reconstruction/raw/aa_00406e70_FUN_00406e70.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00406e70.cpp`

## Confidence

| Claim | Level |
|---|---|
| Body size + ret 0x0C | **Confirmed** |
| EDI + stack ABI | **Confirmed** |
| count=1 + rebind formula + stride 12 | **Confirmed** |
| Callee InsertN role | **High** |
| Product demangle | **Inferred** |
| Runtime / bit-exact | **Open** |
