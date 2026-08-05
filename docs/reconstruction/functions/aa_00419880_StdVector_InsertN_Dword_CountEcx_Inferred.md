# Function record: StdVector_InsertN_Dword_CountEcx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00419880` |
| **Canonical name** | `StdVector_InsertN_Dword_CountEcx_Inferred` |
| **Address** | `0x00419880` |
| **Body range** | `0x00419880` – `0x00419ac4` (0x245 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / container (generic) |
| **Calling convention** | **ECX = count**; stack `vec*`, `where*`, `value*`; **`ret 0x0C`** |
| **Completion status** | **Dual A/B sealed** — CF + triad + growth + ABI; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_00419880_StdVector_InsertN_Dword_CountEcx_Inferred.md` |
| **Dual B** | `reviews/B_aa_00419880_StdVector_InsertN_Dword_CountEcx_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W23-D) |

## Alias

- Ghidra: `FUN_00419880`
- Twin (different ABI): `StdVector_InsertN_Dword_Inferred` @ `0x004073a0`

## Purpose

MSVC-style `std::vector<T>` **insert-n** for **4-byte** elements. Inserts `count` copies of `*value` at iterator `where`, growing capacity when needed (1.5× with exact-fit floor). Generic infrastructure — **not** domain logic.

## Signature

```c
void StdVector_InsertN_Dword_CountEcx_Inferred(
    /*ECX*/ uint32_t count,
    /*stack*/ VectorDword* vec,   // +4 begin, +8 end, +0xc capEnd
    /*stack*/ uint32_t* where,
    /*stack*/ uint32_t* value);
/* ret 0x0C */
```

## Behavioral summary

| Branch | Condition | Effect |
|---|---|---|
| Early-out | `count==0` | return |
| Throw | `size+count > 0x3fffffff` | `FUN_00418130` |
| Realloc | `cap < size+count` | 1.5× grow, relocate, rewrite triad |
| In-place near end | room && distance-to-end < count | shift + fill |
| In-place mid | room else | memmove + fill |

## Machine seal (`read_memory` 2026-07-29)

- SEH prolog; `mov esi,ecx` (count); stack triad args; epilogue **`ret 0x0C`**.
- rel32: `0x004198e4` → `0x00418130` (`StdVector_ThrowTooLong`).

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_0040c7c0`, `FUN_00418130`, `FUN_004651d0`, `memmove`, `operator_new`/`delete` |
| **Callers** | `FUN_00418690` (resize), `Client_UpdateMissionJournal`, many UI/mission/freelist sites |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00419880_FUN_00419880.md` (+ W23-D append)
- Annotated: `docs/reconstruction/raw/aa_00419880_StdVector_InsertN_Dword_CountEcx.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_InsertN_Dword_CountEcx_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00419880.cpp`

## Confidence

| Claim | Level |
|---|---|
| Boundary + body size | **High** |
| ECX=count + ret 0x0C ABI | **High** |
| Triad + stride 4 | **High** |
| 1.5× growth + max 0x3fffffff | **High** |
| Twin ABI difference vs `004073a0` | **High** |
| Product demangled name | **Inferred** |
| Runtime / bit-exact | **Open** |

## Open questions

1. Exact MSVC demangled template args.
2. Full caller taxonomy.
3. Whether any caller relies on non-POD dword element ctor (helpers are POD-style).
4. Runtime / differential.
