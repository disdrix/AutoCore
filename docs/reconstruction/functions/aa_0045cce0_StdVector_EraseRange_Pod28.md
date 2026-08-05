# Function record: StdVector_EraseRange_Pod28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0045cce0` |
| **Canonical name** | `StdVector_EraseRange_Pod28` (**Inferred** structural) |
| **Ghidra name** | `FUN_0045cce0` |
| **Address** | `0x0045cce0`–`0x0045cd2b` exclusive (**75 B** / `0x4B`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `vector<T>::erase(first,last)`, T POD **0x1c** |
| **Completion status** | **Dual sealed** W36-L — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- `FUN_0045cce0` (Ghidra)
- ~~`Named_CalleeOf_*anmTrackMaster*0045cce0`~~ — **rejected** scaffold

## Purpose

Erase half-open POD range `[first, last)` from a stride-0x1c vector: forward-shift the tail, publish new end, return iterator via out-param. Shrink path of `StdVector_Resize_Pod28` (W35-M) when last==end (truncate only).

## Signature

```c
// stack (vec*, out_it*, first, last); RET 0x10; returns out_it*
Pod28** StdVector_EraseRange_Pod28(
    StdVectorPod28* vec,
    Pod28** out_it,
    Pod28* first,
    Pod28* last);
```

## Layout

| Off | Field |
|---|---|
| vec+0x04 | begin |
| vec+0x08 | end (read + written) |
| vec+0x0C | capEnd (unused) |

## Related

| VA | Role |
|---|---|
| `0x0045c4b0` | `StdVector_Resize_Pod28` shrink caller (W35-M) |
| `0x0045cd30` | `StdVector_InsertN_Pod28` next symbol (W34-P) |
| `0x00466df0` | other erase parent (W36-P OWN) |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0045cce0_FUN_0045cce0.md` |
| Annotated | `docs/reconstruction/raw/aa_0045cce0_FUN_0045cce0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_EraseRange_Pod28.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0045cce0.cpp` |
| A/B | `docs/reconstruction/reviews/A_aa_0045cce0_StdVector_EraseRange_Pod28.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-007647c0-0045cce0-w36l-report.md` |
