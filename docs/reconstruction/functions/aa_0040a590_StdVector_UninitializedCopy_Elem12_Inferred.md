# Function record: StdVector_UninitializedCopy_Elem12_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040a590` |
| **Canonical name** | `StdVector_UninitializedCopy_Elem12_Inferred` |
| **Ghidra name** | `FUN_0040a590` |
| **Address** | `0x0040a590`–`0x0040a5f4` inclusive (**101 B** / `0x65`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL vector POD helpers (elem **0x0C**) |
| **Wave** | WQ9K-J OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |

## Alias history

- Ghidra: `FUN_0040a590`
- Structural: `StdVector_UninitializedCopy_Elem12_Inferred` (product demangle open)

## Purpose

Range **POD uninitialized_copy** for **elem stride 0x0C**: while begin≠end, PodCopy leaf then advance both cursors +0x0C; return advanced dest. Feeds InsertN Elem12 grow/shift paths.

## Signature

```c
// ECX = src_end; stack src_begin, dest; EAX = dest_end; plain RET (C3)
void* StdVector_UninitializedCopy_Elem12_Inferred(
    /*ECX*/ const void* src_end,
    /*stack*/ const void* src_begin,
    /*stack*/ void* dest);
```

## Family / peers

| VA | Name | Role |
|---|---|---|
| `0x00409f50` | `StdVector_PodCopyElement_Elem12_Inferred` | leaf (EAX dest / ECX src) |
| `0x0040a520` | `StdVector_UninitializedCopy_Elem0x28_Inferred` | twin 0x28 (do not merge) |
| `0x004082f0` | InsertN Elem12 | consumer residual |
| `0x00409b40` | trampoline | residual |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_0040a590_FUN_0040a590.md`
- Annotated: `docs/reconstruction/raw/aa_0040a590_FUN_0040a590.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_UninitializedCopy_Elem12_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0040a590.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0040a590_StdVector_UninitializedCopy_Elem12_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0040a590_StdVector_UninitializedCopy_Elem12_Inferred.md`
- Report: `docs/agents/task-dual-ab-0042a840-0040a590-wq9kj-report.md`

## Callers / callees

| **Callers (2)** | `FUN_004082f0`, `FUN_00409b40` (`xref_count=3`) |
| **Callees** | `FUN_00409f50` only |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / stride / leaf | **Confirmed** |
| Product English | **Open** |
| Runtime / bit-exact | **Open** |
