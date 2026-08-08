# Function record: StdVector_ConstructN_Elem12_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409db0` |
| **Canonical name** | `StdVector_ConstructN_Elem12_Inferred` |
| **Ghidra name** | `FUN_00409db0` |
| **Address** | `0x00409db0` |
| **Body range** | `0x00409db0` – `0x00409e12` (**99 B** / `0x63`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / container (generic) |
| **Calling convention** | **ECX** = `const T* value`; stack `T* dest`, `int count`; plain **ret** (`C3`) |
| **Completion status** | **Dual A/B sealed** — accept-with-gaps (WQ9I-A 2026-08-05) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_00409db0_StdVector_ConstructN_Elem12_Inferred.md` |
| **Dual B** | `reviews/B_aa_00409db0_StdVector_ConstructN_Elem12_Inferred.md` |
| **Last reviewed** | `2026-08-05` (WQ9I-A) |

## Alias

- Ghidra: `FUN_00409db0`
- Scaffold record: `functions/aa_00409db0_FUN_00409db0.md`
- Reject: domain-specific names — generic POD construct-N for Ufill/push
- Twin: `StdVector_ConstructN_Elem0x28_Inferred` @ `0x00409d40`

## Purpose

MSVC-style **construct-N / uninitialized_fill core** for **0x0C-byte POD** vector elements: stamp `count` copies of `*value` at `dest`, stepping +0x0C.

## Signature

```c
void StdVector_ConstructN_Elem12_Inferred(
    /*ECX*/ const Pod0x0C* value,
    Pod0x0C* dest,
    int count);
```

## Behavioral summary

1. SEH install (`LAB_009bc620`)
2. While count ≠ 0: `FUN_00409f50(dest, value)` (3 dwords); dest += 0x0C; count--
3. SEH restore; return

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_00409f50` PodCopy 3 dwords (EAX=dst, ECX=src) |
| **Callers** | `FUN_00406ee0` Ufill (WQ9G-I sealed); `FUN_004062a0` push_back fast (WQ9H-C sealed) |
| **Twin** | `00409d40` ConstructN elem 0x28 |
| **Parent insert** | Used under InsertN `004082f0` via Ufill `00406ee0` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00409db0_FUN_00409db0.md` (+ WQ9I-A append)
- Annotated: `docs/reconstruction/raw/aa_00409db0_FUN_00409db0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_ConstructN_Elem12_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00409db0.cpp`

## Confidence

| Claim | Level |
|---|---|
| Body size + plain ret | **Confirmed** |
| ECX value + stack dest/count | **Confirmed** |
| dest += 0x0C per iter | **Confirmed** |
| 3-dword PodCopy leaf | **Confirmed** |
| Product demangle | **Inferred** |
| Runtime / bit-exact | **Open** |
