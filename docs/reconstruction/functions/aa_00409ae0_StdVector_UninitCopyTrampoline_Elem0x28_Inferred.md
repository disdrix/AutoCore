# Function record: StdVector_UninitCopyTrampoline_Elem0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409ae0` |
| **Canonical name** | `StdVector_UninitCopyTrampoline_Elem0x28_Inferred` |
| **Ghidra name** | `FUN_00409ae0` |
| **Address** | `0x00409ae0`–`0x00409afa` inclusive (**27 B** / `0x1b`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL vector POD helpers (elem **0x28**) |
| **Wave** | WQ9K-A OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |

## Alias history

- Ghidra: `FUN_00409ae0`
- Structural: `StdVector_UninitCopyTrampoline_Elem0x28_Inferred` (product demangle open)
- Scaffold: partial raw/annotated from 2026-07-23

## Purpose

ABI trampoline for MSVC-style vector **uninitialized_copy** of **0x28**-byte elements. Forwards to dualed worker `StdVector_UninitializedCopy_Elem0x28_Inferred` after remapping InsertN register/stack layout.

## Signature

```c
// ECX = host/vector this (unused by target body)
// EDX = dest
// stack: src_begin, src_end
// EAX = dest_end; RET 8
void* __fastcall StdVector_UninitCopyTrampoline_Elem0x28_Inferred(
    void* host_unused,
    void* dest,
    const void* src_begin,
    const void* src_end);
// ≡ UninitializedCopy_Elem0x28(ECX=src_end, begin, dest)
```

## Family / peers

| VA | Name | Role |
|---|---|---|
| `0x0040a520` | `StdVector_UninitializedCopy_Elem0x28_Inferred` | real range worker (callee) |
| `0x00409f30` | `StdVector_PodCopyElement_0x28_Inferred` | element leaf of worker |
| `0x00408050` | InsertN / reallocate elem 0x28 | sole external caller |
| `0x0040a590` | range uninit_copy Elem12 | twin stride 0x0C — keep distinct |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_00409ae0_FUN_00409ae0.md`
- Annotated: `docs/reconstruction/raw/aa_00409ae0_FUN_00409ae0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_UninitCopyTrampoline_Elem0x28_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00409ae0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00409ae0_StdVector_UninitCopyTrampoline_Elem0x28_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00409ae0_StdVector_UninitCopyTrampoline_Elem0x28_Inferred.md`
- Report: `docs/agents/task-dual-ab-00409ae0-00409b80-wq9ka-report.md`

## Callers / callees

| **Callers** | `FUN_00408050` (2 grow sites) |
| **Callees** | `FUN_0040a520` |
| **Xrefs** | 2 |

## Confidence

| Claim | Level |
|---|---|
| Trampoline CF + RET 8 | **Confirmed** (bytes) |
| Call-site prefix/suffix roles | **Confirmed** |
| Product English | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
