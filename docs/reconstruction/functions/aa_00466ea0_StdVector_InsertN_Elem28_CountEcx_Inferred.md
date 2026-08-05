# Function record: StdVector_InsertN_Elem28_CountEcx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00466ea0` |
| **Canonical name** | `StdVector_InsertN_Elem28_CountEcx_Inferred` |
| **Address** | `0x00466ea0` |
| **Body range** | `0x00466ea0` – `0x00467174` (725 bytes / `0x2D5`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / container (generic) |
| **Calling convention** | **ECX = count**; **EDX = vec***; stack `where*`, `value*`; **`ret 8`** |
| **Completion status** | **Dual A/B sealed** — CF + triad + growth + ABI; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_00466ea0_StdVector_InsertN_Elem28_CountEcx_Inferred.md` |
| **Dual B** | `reviews/B_aa_00466ea0_StdVector_InsertN_Elem28_CountEcx_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W34-Q) |

## Alias

- Ghidra: `FUN_00466ea0`
- Rejected scaffold: `Named_CalleeOf_…_anmAnimMaste_00466ea0`
- ABI peer (stride 4): `StdVector_InsertN_Dword_CountEcx_Inferred` @ `0x00419880`
- Algorithm peer (different ABI): `StdVector_InsertN_Elem28_ValueEdx_Inferred` @ `0x00469f50`

## Purpose

MSVC-style `std::vector<T>` **insert-n** for **28-byte POD** elements. Inserts `count` copies of `*value` at iterator `where`, growing capacity when needed (1.5× with exact-fit floor). Generic infrastructure — **not** domain logic; **not** `basic_string` insert.

## Signature

```c
void StdVector_InsertN_Elem28_CountEcx_Inferred(
    /*ECX*/ uint32_t count,
    /*EDX*/ VectorElem28* vec,   // +4 begin, +8 end, +0xc capEnd
    /*stack*/ Elem28* where,
    /*stack*/ const Elem28* value);
/* ret 8 */
```

## Behavioral summary

| Branch | Condition | Effect |
|---|---|---|
| Early-out | `count==0` | return |
| Throw | `size+count > 0x9249249` | `FUN_004540b0` |
| Realloc | `cap < size+count` | 1.5× grow, relocate, rewrite triad |
| In-place near end | room && distance-to-end < count | shift + fill |
| In-place mid | room else | reverse-move + assign |

## Machine seal (`read_memory` 2026-07-29)

- SEH prolog; `mov ebx,ecx` (count); `mov esi,edx` (vec); value snapshot from `[ebp+0xC]`.
- Max imm `BA 49 92 24 09`; div magic `B8 93 24 49 92`.
- Epilogue **`ret 8`** (`C2 08 00`) at realloc-early and fallthrough.

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_004540b0`, `FUN_00469c50`, `FUN_004673b0`, `FUN_00467320`, `FUN_0046a240`, `FUN_0045efe0`, new/delete |
| **Callers** | `FUN_00466df0` @ `0x00466e46` only |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00466ea0_FUN_00466ea0.md` (+ W34-Q append)
- Annotated: `docs/reconstruction/raw/aa_00466ea0_FUN_00466ea0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_InsertN_Elem28_CountEcx_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_00466ea0.cpp`

## Confidence

| Claim | Level |
|---|---|
| Boundary + body size | **High** |
| ECX=count + EDX=vec + ret 8 ABI | **High** |
| Triad + stride 0x1c | **High** |
| 1.5× growth + max 0x9249249 | **High** |
| POD not basic_string | **High** |
| Product demangled name | **Inferred** |
| Runtime / bit-exact | **Open** |

## Open questions

1. Concrete element type T.
2. Nested helper dual seals.
3. Runtime verification.
