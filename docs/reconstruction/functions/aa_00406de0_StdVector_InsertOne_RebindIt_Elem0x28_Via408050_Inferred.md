# Function record: StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406de0` |
| **Canonical name** | `StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred` |
| **Ghidra name** | `FUN_00406de0` |
| **Address** | `0x00406de0` |
| **Body range** | `0x00406de0` – `0x00406e48` (**104 B** / `0x68`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / container (generic; elem stride **0x28**) |
| **Calling convention** | **EDI** = vector*; stack `outIt**`, `where*`, `value*`; **`ret 0xC`**; EAX=outIt |
| **Completion status** | **Dual A/B sealed** — accept-with-gaps (WQ9G-H 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_00406de0_StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred.md` |
| **Dual B** | `reviews/B_aa_00406de0_StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9G-H) |

## Alias

- Ghidra: `FUN_00406de0`
- Prior scaffold: partial raw/annotated/clean only
- Reject: tree/buynode naming — this is **vector insert-one rebind**, co-located near tree insert `0x00406c40` but not a tree op

## Purpose

MSVC-style **insert exactly one 0x28-byte element** then **rebind out-iterator** after possible realloc. Bridges to insert-N engine `FUN_00408050` with **count = 1**.

## Signature

```c
// customcc
void** StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred(
    /*EDI*/ void* vec,           // +4 begin, +8 end, +0xC capEnd
    /*stack*/ void** outIt,
    /*stack*/ void* where,
    /*stack*/ const void* value); // pointer to 0x28 POD
/* ret 0xC; EAX = outIt */
```

## Behavioral summary

1. `index = (begin!=0 && size!=0) ? (where - begin) / 0x28 : 0`
2. `InsertN(vec, where, value, count=1)` via `FUN_00408050` (ECX=vec, EDX=value)
3. `*outIt = begin' + index * 0x28`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_00408050` (insert-N elem 0x28; undualed residual) |
| **Callers** | `FUN_00406220` only (push_back slow path @ `0x0040628e`) |
| **Twins** | dword rebind `0040b6d0`/`0040dbf0`/`00466da0` (different stride/engine) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00406de0_FUN_00406de0.md` (+ WQ9G-H append)
- Annotated: `docs/reconstruction/raw/aa_00406de0_FUN_00406de0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00406de0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00406de0_FUN_00406de0.md`
- Report: `docs/agents/task-dual-ab-00406de0-00406e50-wq9gh-report.md`

## Confidence

| Claim | Level |
|---|---|
| Body size + ret 0xC | **High** |
| EDI + 3 stack args ABI | **High** |
| count=1 + rebind formula /0x28 | **High** |
| Callee `00408050` insert-N | **High** (link sealed; callee dual open) |
| Product demangle | **Inferred** |
| Runtime / bit-exact | **Open** |
