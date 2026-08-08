# Function record: StdVector_PodCopyElement_0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409f30` |
| **Canonical name** | `StdVector_PodCopyElement_0x28_Inferred` |
| **Ghidra name** | `FUN_00409f30` |
| **Address** | `0x00409f30`–`0x00409f43` inclusive (**20 B** / `0x14`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL vector POD helpers (elem **0x28**) |
| **Wave** | WQ9I-B OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |

## Alias history

- Ghidra: `FUN_00409f30`
- Structural: `StdVector_PodCopyElement_0x28_Inferred` (product demangle open)

## Purpose

Null-safe POD copy of one **0x28**-byte element (**10 dwords** via `REP MOVSD`). Shared leaf for ConstructN and range-copy of the elem-0x28 vector family.

## Signature

```c
// Register ABI: EAX = dest, EDX = src; plain RET (C3)
void StdVector_PodCopyElement_0x28_Inferred(
    /*EAX*/ void* dest,
    /*EDX*/ const void* src);
// if (dest) copy 10 dwords from src → dest
```

## Family / peers

| VA | Name | Role |
|---|---|---|
| `0x00409d40` | `StdVector_ConstructN_Elem0x28_Inferred` | construct-N loop (caller) |
| `0x0040a520` | (range copy / uninit_copy 0x28) | step +0x28 both cursors (caller) |
| `0x00406e50` | Ufill elem 0x28 | uses ConstructN |
| `0x00406220` | push_back elem 0x28 | uses ConstructN |
| `0x004046f0` | CombatFloater_PodCopyElement_0x38 | peer leaf (14 dwords) |
| `0x00404710` | UiToast_PodCopyElement_0x98 | peer leaf (0x26 dwords) |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_00409f30_FUN_00409f30.md`
- Annotated: `docs/reconstruction/raw/aa_00409f30_FUN_00409f30.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_PodCopyElement_0x28_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00409f30.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00409f30_StdVector_PodCopyElement_0x28_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00409f30_StdVector_PodCopyElement_0x28_Inferred.md`
- Report: `docs/agents/task-dual-ab-00409f30-00407200-wq9ib-report.md`

## Callers / callees

| **Callers (2)** | `FUN_00409d40`, `FUN_0040a520` |
| **Callees** | none (leaf) |
| **Xrefs** | 2 UNCONDITIONAL_CALL |

## Confidence

| Claim | Level |
|---|---|
| CF / 10 dwords / null-dst | **Confirmed** (bytes) |
| EAX/EDX ABI + plain RET | **Confirmed** (call sites + epilogue) |
| Stride 0x28 family | **High** (callers +0x28) |
| Product English | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
