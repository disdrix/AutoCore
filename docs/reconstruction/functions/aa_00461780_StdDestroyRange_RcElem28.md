# Function record: StdDestroyRange_RcElem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_00461780` |
| **Canonical name** | `StdDestroyRange_RcElem28` (**Inferred** structural) |
| **Ghidra name** | `FUN_00461780` |
| **Address** | `0x00461780`–`0x00461797` exclusive (**23 B** / `0x17`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC destroy-range, T refcounted **0x1c** |
| **Completion status** | **Dual sealed** W35-O — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

MSVC-style **destroy range**: for each element in `[begin, end)`, call per-elem Release leaf (`FUN_00460d70`) on shared resource `@+0x10`. Thin worker used by `StdVector_InsertN_RcElem28` grow teardown and EH catch paths.

## Signature

```c
void StdDestroyRange_RcElem28(
    RcElem28* begin,  /* EAX */
    RcElem28* end);   /* EDI exclusive */
// RET 0
```

## Related

| VA | Role |
|---|---|
| `0x004617a0` | `StdVector_InsertN_RcElem28` (W34-P) — primary parent |
| `0x00461c90` | `StdUninitFillN_RcElem28` (this dual) — fill sibling |
| `0x00460d70` | per-elem Release leaf (refcount-- / vtbl+8) |
| `0x00461ac0` / `0x004620b0` | RC copy-ctor / uninit-copy (W35-N) |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00461780_FUN_00461780.md` |
| Annotated | `docs/reconstruction/raw/aa_00461780_FUN_00461780.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdDestroyRange_RcElem28.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00461780.cpp` |
| A/B | `docs/reconstruction/reviews/A_aa_00461780_StdDestroyRange_RcElem28.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-00461c90-00461780-w35o-report.md` |
