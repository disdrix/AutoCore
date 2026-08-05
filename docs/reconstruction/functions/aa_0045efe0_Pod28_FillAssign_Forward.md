# Function record: Pod28_FillAssign_Forward

| Field | Value |
|---|---|
| **Stable ID** | `aa_0045efe0` |
| **Canonical name** | `Pod28_FillAssign_Forward` (**Inferred** structural) |
| **Ghidra name** | `FUN_0045efe0` |
| **Address** | `0x0045efe0`–`0x0045effb` exclusive (**27 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC-style forward fill-assign, POD T **0x1c** |
| **Completion status** | **Dual sealed** W35-M — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Assign-fill every element in half-open `[dst_begin, dst_end)` from one template `*value`. Element size **0x1c** (inner `rep movsd` ECX=7). Leaf used by Pod28/Elem28 **insert-n** mid-hole paths after reverse-move.

## Signature

```c
// EAX=dst_begin, EDX=dst_end, EBX=value*; RET 0
void Pod28_FillAssign_Forward(
    Pod28* dst_begin,
    Pod28* dst_end,
    const Pod28* value);
```

## Related

| VA | Role |
|---|---|
| `0x0045cd30` | `StdVector_InsertN_Pod28` caller (W34-P) |
| `0x00466ea0` / `0x00469f50` | Elem28 InsertN callers (W34-Q) |
| `0x0046a240` | assign-backward sibling (not owned) |
| `0x0045f150` | fill-n (uninit-style) sibling family |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0045efe0_FUN_0045efe0.md` |
| Annotated | `docs/reconstruction/raw/aa_0045efe0_FUN_0045efe0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Pod28_FillAssign_Forward.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0045efe0.cpp` |
| A/B | `docs/reconstruction/reviews/A_aa_0045efe0_Pod28_FillAssign_Forward.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-0045efe0-0045c4b0-w35m-report.md` |
