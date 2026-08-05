# Function record: FUN_0045efe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0045efe0` |
| **Canonical name** | `Pod28_FillAssign_Forward` (**Inferred**) — Ghidra `FUN_0045efe0` |
| **Address** | `0x0045efe0`–`0x0045effb` exclusive (**27 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC POD fill-assign, elem **0x1c** |
| **Completion status** | **Dual sealed** W35-M — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

Human scaffold (rejected): `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_anmTrackMast_0045efe0`

## Purpose

Forward fill-assign half-open range `[dst_begin, dst_end)` from a single POD template (`*value`), element stride **0x1c** (7 dwords / `rep movsd`). Leaf helper for insert-n mid-hole fill.

## Signature (sealed)

```c
// EAX=dst_begin, EDX=dst_end, EBX=value*; RET 0; leaf
void Pod28_FillAssign_Forward(Pod28* dst_begin, Pod28* dst_end, const Pod28* value);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0045efe0_FUN_0045efe0.md`
- Annotated: `docs/reconstruction/raw/aa_0045efe0_FUN_0045efe0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Pod28_FillAssign_Forward.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0045efe0.cpp`
- Named record: `docs/reconstruction/functions/aa_0045efe0_Pod28_FillAssign_Forward.md`
- A/B: `docs/reconstruction/reviews/A_aa_0045efe0_Pod28_FillAssign_Forward.md`, `B_…`

## Callers / callees

| Callers (3) | `FUN_0045cd30`, `FUN_00466ea0`, `FUN_00469f50` |
| Callees | none (leaf) |

## Confidence

| Claim | Level |
|---|---|
| Stride 0x1c + 7×dword assign | **High** (bytes) |
| Register ABI EAX/EDX/EBX | **High** (bytes + callers) |
| Product T English | Gap |
