# Function record: StdVector_PodCopyElement_0x10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409f70` |
| **Canonical name** | `StdVector_PodCopyElement_0x10_Inferred` |
| **Ghidra name** | `FUN_00409f70` |
| **Address** | `0x00409f70`–`0x00409f8a` inclusive (**27 B** / `0x1B`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation / STL vector POD helpers (elem **0x10**) |
| **Wave** | R10-023 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |

## Alias history

- Ghidra: `FUN_00409f70`
- Structural: `StdVector_PodCopyElement_0x10_Inferred` (product demangle open)
- Scaffold: `Named_CalleeOf_*Cli_00409f70` (**retired**)

## Purpose

Null-safe POD copy of one **0x10**-byte element (**4 dwords** via four MOV pairs). Shared leaf for ConstructN and range-copy of the Elem0x10 vector family.

## Signature

```c
// Register ABI: EAX = dest, ECX = src; plain RET (C3)
void StdVector_PodCopyElement_0x10_Inferred(
    /*EAX*/ void* dest,
    /*ECX*/ const void* src);
// if (dest) copy 4 dwords from src → dest
```

## Family / peers

| VA | Name | Role |
|---|---|---|
| `0x00409e20` | `StdVector_ConstructN_Elem0x10_Inferred` | construct-N loop (caller; MEGA-044 dualed) |
| `0x0040a670` | (range copy / uninit_copy Elem0x10) | step +0x10 both cursors (caller; residual) |
| `0x00408640` | `StdVector_InsertN_Elem0x10_Inferred` | insert-N parent of ConstructN wrapper |
| `0x00407000` | construct-N wrapper → end pointer | residual peer of ConstructN |
| `0x00409f30` | `StdVector_PodCopyElement_0x28_Inferred` | peer leaf (**EAX/EDX**, 10 dwords) — **do not merge ABI** |
| `0x00409f50` | `StdVector_PodCopyElement_Elem12_Inferred` | peer leaf (**EAX/ECX**, 3 dwords / 0x0C) — **do not merge size** |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_00409f70_FUN_00409f70.md`
- Annotated: `docs/reconstruction/raw/aa_00409f70_FUN_00409f70.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_PodCopyElement_0x10_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00409f70.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00409f70_StdVector_PodCopyElement_0x10_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00409f70_StdVector_PodCopyElement_0x10_Inferred.md`
- Report: `docs/agents/task-dual-ab-00409f70-r10-report.md`

## Callers / callees

| **Callers (2)** | `FUN_00409e20`, `FUN_0040a670` |
| **Callees** | none (leaf) |
| **Xrefs** | 2 UNCONDITIONAL_CALL |

## Confidence

| Claim | Level |
|---|---|
| CF / 4 dwords / null-dst | **Confirmed** (bytes) |
| EAX/ECX ABI + plain RET | **Confirmed** (call sites + epilogue) |
| Stride 0x10 family | **High** (callers +0x10) |
| Product English | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
