# Function record: StdUninitFillN_RcElem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_00461c90` |
| **Canonical name** | `StdUninitFillN_RcElem28` (**Inferred** structural) |
| **Ghidra name** | `FUN_00461c90` |
| **Address** | `0x00461c90`–`0x00461d74` exclusive (**228 B** / `0xE4`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `_Uninit_fill_n`, T refcounted **0x1c** |
| **Completion status** | **Dual sealed** W35-O — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

MSVC-style **`_Uninit_fill_n`**: write `count` copies of `value` into uninitialized `dest` slots of stride **0x1c**, with shared-resource **AddRef** at **`+0x10`**. SEH protects each construction; unwind Releases partially built range.

## Signature

```c
void StdUninitFillN_RcElem28(
    const RcElem28* value,  /* ECX */
    int count,              /* EDX */
    RcElem28* dest);        /* stack */
// RET 0; callers may push extra unused dword + ADD ESP,8
```

## Element layout (0x1c)

| Off | Field |
|---|---|
| +0x00..+0x0C | 4× u32 |
| +0x10 | shared* (refcount @ obj+4; AddRef vtbl+4; Release vtbl+8) |
| +0x14..+0x16 | 3× u8 |
| +0x18 | u32 |

## Related

| VA | Role |
|---|---|
| `0x004617a0` | `StdVector_InsertN_RcElem28` (W34-P) — primary parent |
| `0x00461780` | `StdDestroyRange_RcElem28` (this dual) — destroy sibling |
| `0x00461ac0` | RC copy-ctor (W35-N) |
| `0x004620b0` | RC uninit-copy range (W35-N) |
| `0x00460f90` | push_back-style caller (count=1) |
| `0x00460d70` | per-elem Release leaf |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00461c90_FUN_00461c90.md` |
| Annotated | `docs/reconstruction/raw/aa_00461c90_FUN_00461c90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdUninitFillN_RcElem28.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00461c90.cpp` |
| A/B | `docs/reconstruction/reviews/A_aa_00461c90_StdUninitFillN_RcElem28.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-00461c90-00461780-w35o-report.md` |
