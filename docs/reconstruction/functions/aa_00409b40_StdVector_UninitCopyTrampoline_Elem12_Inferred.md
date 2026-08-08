# Function record: StdVector_UninitCopyTrampoline_Elem12_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409b40` |
| **Canonical name** | `StdVector_UninitCopyTrampoline_Elem12_Inferred` |
| **Ghidra name** | `FUN_00409b40` |
| **Address** | `0x00409b40`–`0x00409b5a` inclusive (**27 B** / `0x1b`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL vector POD helpers (elem **0x0C**) |
| **Wave** | R10-008 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |

## Alias history

- Ghidra: `FUN_00409b40`
- Structural: `StdVector_UninitCopyTrampoline_Elem12_Inferred` (product demangle open)
- Scaffold: partial raw/annotated from 2026-07-23

## Purpose

ABI trampoline for MSVC-style vector **uninitialized_copy** of **0x0C**-byte elements. Forwards to dualed worker `StdVector_UninitializedCopy_Elem12_Inferred` after remapping InsertN register/stack layout.

## Signature

```c
// ECX = host/vector this (unused by target body)
// EDX = dest
// stack: src_begin, src_end
// EAX = dest_end; RET 8
void* __fastcall StdVector_UninitCopyTrampoline_Elem12_Inferred(
    void* host_unused,
    void* dest,
    const void* src_begin,
    const void* src_end);
// ≡ UninitializedCopy_Elem12(ECX=src_end, begin, dest)
```

## Family / peers

| VA | Name | Role |
|---|---|---|
| `0x0040a590` | `StdVector_UninitializedCopy_Elem12_Inferred` | real range worker (callee) |
| `0x00409f50` | `StdVector_PodCopyElement_Elem12_Inferred` | element leaf of worker |
| `0x004082f0` | `StdVector_InsertN_Elem12_Inferred` | sole external caller (grow path) |
| `0x00409ae0` | `StdVector_UninitCopyTrampoline_Elem0x28_Inferred` | twin trampoline 0x28 — keep distinct |
| `0x0040a520` | `StdVector_UninitializedCopy_Elem0x28_Inferred` | twin worker 0x28 — keep distinct |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_00409b40_FUN_00409b40.md`
- Annotated: `docs/reconstruction/raw/aa_00409b40_FUN_00409b40.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_UninitCopyTrampoline_Elem12_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00409b40.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00409b40_FUN_00409b40.md`
- Dual A: `docs/reconstruction/reviews/A_aa_00409b40_StdVector_UninitCopyTrampoline_Elem12_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00409b40_StdVector_UninitCopyTrampoline_Elem12_Inferred.md`
- Report: `docs/agents/task-dual-ab-00409b40-r10-report.md`

## Callers / callees

| **Callers** | `FUN_004082f0` (2 grow sites @ `00408413`, `0040843a`) |
| **Callees** | `FUN_0040a590` |
| **Xrefs** | 2 |

## Confidence

| Claim | Level |
|---|---|
| Trampoline CF + RET 8 | **Confirmed** (bytes) |
| Call-site prefix/suffix roles | **Confirmed** |
| Product English | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
