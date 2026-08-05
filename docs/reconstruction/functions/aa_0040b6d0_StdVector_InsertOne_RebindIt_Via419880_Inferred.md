# Function record: StdVector_InsertOne_RebindIt_Via419880_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040b6d0` |
| **Canonical name** | `StdVector_InsertOne_RebindIt_Via419880_Inferred` |
| **Ghidra name** | `FUN_0040b6d0` |
| **Address** | `0x0040b6d0` |
| **Body range** | `0x0040b6d0` – `0x0040b713` (**68 B** / `0x44`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / container (generic) |
| **Calling convention** | **EDI** = vector host; **EBX** = out-iterator (`T**`); stack `where*`, `value*`; **`ret 8`**; EAX=EBX |
| **Completion status** | **Dual A/B sealed** — accept (WQ7R-E 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_0040b6d0_StdVector_InsertOne_RebindIt_Via419880_Inferred.md` |
| **Dual B** | `reviews/B_aa_0040b6d0_StdVector_InsertOne_RebindIt_Via419880_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ7R-E) |

## Alias

- Ghidra: `FUN_0040b6d0`
- Prior scaffold: `Named_CalleeOf_Named_CalleeOf_Client_UpdateMissionJournal_0040b6d0`
- Reject: mission-domain name — generic vector helper (journal path is only known consumer chain)

## Purpose

MSVC-style **insert exactly one dword** then **rebind out-iterator** after possible realloc. Bridges to sealed `StdVector_InsertN_Dword_CountEcx_Inferred` (`0x00419880`) with **count = 1**.

## Signature

```c
// customcc
uint32_t** StdVector_InsertOne_RebindIt_Via419880_Inferred(
    /*EDI*/ void* vec,           // +4 begin, +8 end, +0xC capEnd
    /*EBX*/ uint32_t** outIt,
    /*stack*/ uint32_t* where,
    /*stack*/ const uint32_t* value);
/* ret 8; EAX = outIt */
```

## Behavioral summary

1. `index = empty ? 0 : (where - begin) >> 2`
2. `InsertN(count=1, vec, where, value)` via `00419880`
3. `*outIt = begin' + index * 4`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_00419880` (`StdVector_InsertN_Dword_CountEcx_Inferred`) |
| **Callers** | `FUN_00411180` only (push_back slow path @ `0x004111c1`) |
| **Twins** | `0040dbf0` thiscall/`004073a0`; `00466da0` EDI/EBX/`00456960` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0040b6d0_FUN_0040b6d0.md` (+ WQ7R-E append)
- Annotated: `docs/reconstruction/raw/aa_0040b6d0_FUN_0040b6d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_InsertOne_RebindIt_Via419880_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0040b6d0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_0040b6d0_FUN_0040b6d0.md`

## Confidence

| Claim | Level |
|---|---|
| Body size + ret 8 | **High** |
| EDI/EBX + stack ABI | **High** |
| count=1 + rebind formula | **High** |
| Callee CountEcx engine | **High** |
| Product demangle | **Inferred** |
| Runtime / bit-exact | **Open** |
