# Function record: StdVector_ConstructN_Elem0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409d40` |
| **Canonical name** | `StdVector_ConstructN_Elem0x28_Inferred` |
| **Ghidra name** | `FUN_00409d40` |
| **Address** | `0x00409d40` |
| **Body range** | `0x00409d40` – `0x00409da2` (**98 B** / `0x62`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / container (generic) |
| **Calling convention** | **ECX** = `const T* value`; stack `T* dest`, `int count`; plain **ret** (`C3`) |
| **Completion status** | **Dual A/B sealed** — accept-with-gaps (WQ9H-B 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_00409d40_StdVector_ConstructN_Elem0x28_Inferred.md` |
| **Dual B** | `reviews/B_aa_00409d40_StdVector_ConstructN_Elem0x28_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9H-B) |

## Alias

- Ghidra: `FUN_00409d40`
- Scaffold record: `functions/aa_00409d40_FUN_00409d40.md`
- Reject: domain-specific names — generic POD construct-N for Ufill/push

## Purpose

MSVC-style **construct-N / uninitialized_fill core** for **0x28-byte POD** vector elements: stamp `count` copies of `*value` at `dest`, stepping +0x28.

## Signature

```c
void StdVector_ConstructN_Elem0x28_Inferred(
    /*ECX*/ const Pod0x28* value,
    Pod0x28* dest,
    int count);
```

## Behavioral summary

1. SEH install (`LAB_009bc630`)
2. While count ≠ 0: `FUN_00409f30(dest, value)` (10 dwords); dest += 0x28; count--
3. SEH restore; return

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_00409f30` PodCopy 10 dwords |
| **Callers** | `FUN_00406e50` Ufill (WQ9G-H sealed); `FUN_00406220` push_back fast (WQ9H-C residual) |
| **Twin** | `00409db0` ConstructN elem 0xC |
| **Parent insert** | Used under InsertN `00408050` via Ufill `00406e50` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00409d40_FUN_00409d40.md` (+ WQ9H-B append)
- Annotated: `docs/reconstruction/raw/aa_00409d40_FUN_00409d40.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_ConstructN_Elem0x28_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00409d40.cpp`

## Confidence

| Claim | Level |
|---|---|
| Body size + plain ret | **Confirmed** |
| ECX value + stack dest/count | **Confirmed** |
| dest += 0x28 per iter | **Confirmed** |
| 10-dword PodCopy leaf | **Confirmed** |
| Product demangle | **Inferred** |
| Runtime / bit-exact | **Open** |
