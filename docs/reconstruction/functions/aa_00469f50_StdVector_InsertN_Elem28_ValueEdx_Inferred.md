# Function record: StdVector_InsertN_Elem28_ValueEdx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00469f50` |
| **Canonical name** | `StdVector_InsertN_Elem28_ValueEdx_Inferred` |
| **Address** | `0x00469f50` |
| **Body range** | `0x00469f50` – `0x0046a203` (692 bytes / `0x2B4`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / container (generic) |
| **Calling convention** | **EDX = value***; stack `vec*`, `where*`, `count`; **`ret 0x0C`** |
| **Completion status** | **Dual A/B sealed** — CF + triad + growth + ABI; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_00469f50_StdVector_InsertN_Elem28_ValueEdx_Inferred.md` |
| **Dual B** | `reviews/B_aa_00469f50_StdVector_InsertN_Elem28_ValueEdx_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W34-Q) |

## Alias

- Ghidra: `FUN_00469f50`
- Rejected scaffold: long `Named_CalleeOf_…` chain
- Algorithm peer: `StdVector_InsertN_Elem28_CountEcx_Inferred` @ `0x00466ea0`

## Purpose

MSVC-style `std::vector<T>` **insert-n** for **28-byte POD** elements. Value pointer in EDX; vec/where/count on stack. Generic — not domain logic.

## Signature

```c
void StdVector_InsertN_Elem28_ValueEdx_Inferred(
    /*EDX*/ const Elem28* value,
    /*stack*/ VectorElem28* vec,
    /*stack*/ Elem28* where,
    /*stack*/ uint32_t count);
/* ret 0x0C */
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

- SEH prolog; `mov ecx,7; mov esi,edx; lea edi,[ebp-0x30]; rep movsd`.
- count `@ [ebp+0x10]`; max imm `0x09249249`.
- Epilogue **`ret 0x0C`** (`C2 0C 00`).

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_004540b0`, `FUN_00469c50`, `FUN_0046a350`, `FUN_0046a260`, `FUN_0046a240`, `FUN_0045efe0`, new/delete |
| **Callers** | `FUN_00469e20` @ `0x00469e73` only |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00469f50_FUN_00469f50.md` (+ W34-Q append)
- Annotated: `docs/reconstruction/raw/aa_00469f50_FUN_00469f50.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_InsertN_Elem28_ValueEdx_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_00469f50.cpp`

## Confidence

| Claim | Level |
|---|---|
| Boundary + body size | **High** |
| Value-EDX + ret 0x0C ABI | **High** |
| Triad + stride 0x1c | **High** |
| 1.5× growth + max 0x9249249 | **High** |
| Product demangled name | **Inferred** |
| Runtime / bit-exact | **Open** |

## Open questions

1. Concrete element type T.
2. Nested helper dual seals.
3. Runtime verification.
