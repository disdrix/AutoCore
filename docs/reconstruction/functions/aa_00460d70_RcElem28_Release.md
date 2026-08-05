# Function record: RcElem28_Release

| Field | Value |
|---|---|
| **Stable ID** | `aa_00460d70` |
| **Canonical name** | `RcElem28_Release` (**Inferred** structural) |
| **Ghidra name** | `FUN_00460d70` |
| **Address** | `0x00460d70`–`0x00460d83` exclusive (**19 B** / `0x13`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | Per-element Release of shared resource `@+0x10` on RC-elem **0x1c** |
| **Completion status** | **Dual sealed** W36-O — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Release one element's shared resource: null-check `@+0x10`, decrement refcount at `shared+4`, tail-transfer to `vtbl[+8]` when the count hits zero. Leaf used by destroy-range, erase, clear, and EH unwind for the RcElem28 family.

## Signature

```c
void RcElem28_Release(RcElem28* elem /* EAX */);
// RET 0, or tail JMP [vtbl+8]
```

## Related

| VA | Role |
|---|---|
| `0x00461780` | `StdDestroyRange_RcElem28` (W35-O) — primary walker |
| `0x00461720` | erase-range helper |
| `0x00461350` | vector clear/dtor |
| `0x00461c90` | fill-n AddRef twin shape (refcount++ / vtbl+4) |
| `0x00460f90` | push_back sibling (this dual) |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00460d70_FUN_00460d70.md` |
| Annotated | `docs/reconstruction/raw/aa_00460d70_FUN_00460d70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RcElem28_Release.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00460d70.cpp` |
| A/B | `docs/reconstruction/reviews/A_aa_00460d70_RcElem28_Release.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-00460f90-00460d70-w36o-report.md` |
