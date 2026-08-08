# Function record: StdVector_UninitializedCopy_Elem0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040a520` |
| **Canonical name** | `StdVector_UninitializedCopy_Elem0x28_Inferred` |
| **Ghidra name** | `FUN_0040a520` |
| **Address** | `0x0040a520`–`0x0040a584` inclusive (**101 B** / `0x65`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL vector POD helpers (elem **0x28**) |
| **Wave** | WQ9J-A OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |

## Alias history

- Ghidra: `FUN_0040a520`
- Structural: `StdVector_UninitializedCopy_Elem0x28_Inferred` (product demangle open)
- Scaffold: partial raw/annotated from 2026-07-23

## Purpose

Range **uninitialized_copy** of **0x28**-byte POD elements from half-open `[src_begin, src_end)` into `dest`, returning advanced `dest_end`. Element work is dualed PodCopy leaf `0x00409f30`.

## Signature

```c
// ECX = src_end; stack: src_begin, dest; EAX = dest_end; plain RET (C3)
void* StdVector_UninitializedCopy_Elem0x28_Inferred(
    /*ECX*/ const void* src_end,
    /*stack*/ const void* src_begin,
    /*stack*/ void* dest);
// while (begin != end) { PodCopy0x28(dest, begin); begin+=0x28; dest+=0x28; } return dest;
```

## Family / peers

| VA | Name | Role |
|---|---|---|
| `0x00409f30` | `StdVector_PodCopyElement_0x28_Inferred` | element leaf (callee) |
| `0x00409d40` | `StdVector_ConstructN_Elem0x28_Inferred` | construct-N peer (same leaf) |
| `0x00408050` | InsertN / reallocate (elem 0x28) | primary consumer (caller) |
| `0x00409ae0` | thin trampoline → this | reorders args; RET 8 |
| `0x0040a590` | range uninit_copy Elem12 | twin stride 0x0C / leaf `00409f50` |
| `0x0045f360` | `StdUninitCopy_Pod28` | different family (elem 0x1c) |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_0040a520_FUN_0040a520.md`
- Annotated: `docs/reconstruction/raw/aa_0040a520_FUN_0040a520.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_UninitializedCopy_Elem0x28_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0040a520.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0040a520_StdVector_UninitializedCopy_Elem0x28_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0040a520_StdVector_UninitializedCopy_Elem0x28_Inferred.md`
- Report: `docs/agents/task-dual-ab-00409f50-0040a520-wq9ja-report.md`

## Callers / callees

| **Callers** | `FUN_00408050` (2), `FUN_00409ae0` |
| **Callees** | `FUN_00409f30` |
| **Xrefs** | 3 UNCONDITIONAL_CALL |

## Confidence

| Claim | Level |
|---|---|
| CF / stride 0x28 / SEH | **Confirmed** (bytes) |
| ECX end + stack begin/dest | **Confirmed** (body + call sites) |
| Leaf PodCopy 0x28 | **Confirmed** |
| Product English | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
