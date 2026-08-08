# Function record: StdVector_UninitializedFillN_Elem0x10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00407000` |
| **Canonical name** | `StdVector_UninitializedFillN_Elem0x10_Inferred` |
| **Ghidra name** | `FUN_00407000` |
| **Address** | `0x00407000` |
| **Body range** | `0x00407000` – `0x0040701d` (**29 B** / `0x1d`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / container (generic) |
| **Calling convention** | **EDI** = dest*; **ESI** = count; stack `const T* value`; **`ret 4`**; EAX=`dest+count*0x10` |
| **Completion status** | **Dual A/B sealed** — accept-with-gaps (R10-007 2026-08-05) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_00407000_StdVector_UninitializedFillN_Elem0x10_Inferred.md` |
| **Dual B** | `reviews/B_aa_00407000_StdVector_UninitializedFillN_Elem0x10_Inferred.md` |
| **Last reviewed** | `2026-08-05` (R10-007) |

## Alias

- Ghidra: `FUN_00407000`
- Scaffold record: `functions/aa_00407000_FUN_00407000.md`
- Retired: `Named_CalleeOf_*Cli_00407000` — generic POD Ufill, not domain

## Purpose

MSVC-style **uninitialized_fill_n** for **16-byte POD** vector elements: construct `count` copies of `value` at `dest`, return end pointer.

## Signature

```c
// customcc
Pod16* StdVector_UninitializedFillN_Elem0x10_Inferred(
    /*EDI*/ Pod16* dest,
    /*ESI*/ int count,
    /*stack*/ const Pod16* value);
/* ret 4; EAX = dest + count*0x10 */
```

## Behavioral summary

1. `FUN_00409e20(dest, count)` with ECX=value* — loop POD-assign 4 dwords, advance +0x10  
2. `return dest + count * 0x10`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_00409e20` (`StdVector_ConstructN_Elem0x10_Inferred`) → `FUN_00409f70` (4-dword assign) |
| **Callers** | `FUN_00408640` only (`StdVector_InsertN_Elem0x10_Inferred`; 2 sites @ `0x00408746`, `0x0040880c`) |
| **Twins** | `00406e50` Ufill 0x28; `00406ee0` Ufill 0xC; construct-N `00409e20`; InsertN `00408640` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00407000_FUN_00407000.md` (+ R10-007 append)
- Annotated: `docs/reconstruction/raw/aa_00407000_FUN_00407000.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_UninitializedFillN_Elem0x10_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_00407000.cpp`

## Confidence

| Claim | Level |
|---|---|
| Body size + ret 4 | **Confirmed** |
| EDI/ESI + stack value ABI | **Confirmed** |
| End = dest + count×0x10 | **Confirmed** |
| InsertN Ufill role | **High** |
| Product demangle | **Inferred** |
| Runtime / bit-exact | **Open** |
