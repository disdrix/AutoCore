# Function record: StdVector_PodCopyElement_Elem12_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409f50` |
| **Canonical name** | `StdVector_PodCopyElement_Elem12_Inferred` |
| **Ghidra name** | `FUN_00409f50` |
| **Address** | `0x00409f50`–`0x00409f64` inclusive (**21 B** / `0x15`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL vector POD helpers (elem **0x0C**) |
| **Wave** | WQ9J-A OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |

## Alias history

- Ghidra: `FUN_00409f50`
- Structural: `StdVector_PodCopyElement_Elem12_Inferred` (product demangle open)

## Purpose

Null-safe POD copy of one **0x0C**-byte element (**3 dwords** via three MOV pairs). Shared leaf for ConstructN and range-copy of the Elem12 vector family.

## Signature

```c
// Register ABI: EAX = dest, ECX = src; plain RET (C3)
void StdVector_PodCopyElement_Elem12_Inferred(
    /*EAX*/ void* dest,
    /*ECX*/ const void* src);
// if (dest) copy 3 dwords from src → dest
```

## Family / peers

| VA | Name | Role |
|---|---|---|
| `0x00409db0` | `StdVector_ConstructN_Elem12_Inferred` | construct-N loop (caller) |
| `0x0040a590` | (range copy / uninit_copy Elem12) | step +0x0C both cursors (caller; residual) |
| `0x00406ee0` | Ufill Elem12 | uses ConstructN |
| `0x004062a0` | push_back Elem12 | uses ConstructN |
| `0x00409f30` | `StdVector_PodCopyElement_0x28_Inferred` | peer leaf (**EAX/EDX**, 10 dwords) — **do not merge ABI** |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_00409f50_FUN_00409f50.md`
- Annotated: `docs/reconstruction/raw/aa_00409f50_FUN_00409f50.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_PodCopyElement_Elem12_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00409f50.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00409f50_StdVector_PodCopyElement_Elem12_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00409f50_StdVector_PodCopyElement_Elem12_Inferred.md`
- Report: `docs/agents/task-dual-ab-00409f50-0040a520-wq9ja-report.md`

## Callers / callees

| **Callers (2)** | `FUN_00409db0`, `FUN_0040a590` |
| **Callees** | none (leaf) |
| **Xrefs** | 2 UNCONDITIONAL_CALL |

## Confidence

| Claim | Level |
|---|---|
| CF / 3 dwords / null-dst | **Confirmed** (bytes) |
| EAX/ECX ABI + plain RET | **Confirmed** (call sites + epilogue) |
| Stride 0x0C family | **High** (callers +0x0C) |
| Product English | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
