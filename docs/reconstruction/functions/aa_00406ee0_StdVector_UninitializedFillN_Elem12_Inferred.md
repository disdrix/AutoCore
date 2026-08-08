# Function record: StdVector_UninitializedFillN_Elem12_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406ee0` |
| **Canonical name** | `StdVector_UninitializedFillN_Elem12_Inferred` |
| **Ghidra name** | `FUN_00406ee0` |
| **Address** | `0x00406ee0` |
| **Body range** | `0x00406ee0` – `0x00406efd` (**29 B** / `0x1d`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / container (generic) |
| **Calling convention** | **EDI** = dest*; **ESI** = count; stack `const T* value`; **`ret 4`**; EAX=`dest+count*0xC` |
| **Completion status** | **Dual A/B sealed** — accept-with-gaps (WQ9G-I 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_00406ee0_StdVector_UninitializedFillN_Elem12_Inferred.md` |
| **Dual B** | `reviews/B_aa_00406ee0_StdVector_UninitializedFillN_Elem12_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9G-I) |

## Alias

- Ghidra: `FUN_00406ee0`
- Scaffold record: `functions/aa_00406ee0_FUN_00406ee0.md`
- Reject: domain-specific names — generic POD Ufill

## Purpose

MSVC-style **uninitialized_fill_n** for **12-byte POD** vector elements: construct `count` copies of `value` at `dest`, return end pointer.

## Signature

```c
// customcc
Pod12* StdVector_UninitializedFillN_Elem12_Inferred(
    /*EDI*/ Pod12* dest,
    /*ESI*/ int count,
    /*stack*/ const Pod12* value);
/* ret 4; EAX = dest + count*12 */
```

## Behavioral summary

1. `FUN_00409db0(dest, count)` with ECX=value* — loop POD-assign 3 dwords, advance +0xC  
2. `return dest + count * 12`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_00409db0` → `FUN_00409f50` (3-dword assign) |
| **Callers** | `FUN_004082f0` only (InsertN hole fill; 2 sites) |
| **Pair** | `aa_00406e70` InsertOne rebind elem 0xC |
| **Twins** | `00406e50` Ufill 0x28; `00467320` Ufill Elem28; toast/floater Ufill wrappers |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00406ee0_FUN_00406ee0.md` (+ WQ9G-I append)
- Annotated: `docs/reconstruction/raw/aa_00406ee0_FUN_00406ee0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_UninitializedFillN_Elem12_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00406ee0.cpp`

## Confidence

| Claim | Level |
|---|---|
| Body size + ret 4 | **Confirmed** |
| EDI/ESI + stack value ABI | **Confirmed** |
| End = dest + count×12 | **Confirmed** |
| InsertN Ufill role | **High** |
| Product demangle | **Inferred** |
| Runtime / bit-exact | **Open** |
