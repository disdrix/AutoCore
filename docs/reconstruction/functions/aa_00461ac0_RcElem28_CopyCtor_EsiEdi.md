# Function record: RcElem28_CopyCtor_EsiEdi

| Field | Value |
|---|---|
| **Stable ID** | `aa_00461ac0` |
| **Canonical name** | `RcElem28_CopyCtor_EsiEdi` (**Inferred** structural) |
| **Ghidra name** | `FUN_00461ac0` |
| **Address** | `0x00461ac0`–`0x00461b11` exclusive (**81 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC-style copy-ctor for refcounted **T** size **0x1c** |
| **Completion status** | **Dual sealed** W35-N — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Copy-construct one element: POD lanes + shared resource `@+0x10` with refcount AddRef (vtbl+4 when count becomes 1 after increment). Register ABI **ESI→EDI**.

## Signature

```c
// ESI = const RcElem28* src; EDI = RcElem28* dst; returns dst in EAX; RET
RcElem28* RcElem28_CopyCtor_EsiEdi(void);
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
| `0x004617a0` | parent `StdVector_InsertN_RcElem28` (sole caller) |
| `0x004620b0` | range uninit-copy sibling (same element + AddRef) |
| `0x0045cd30` | POD insert-n sibling family (no AddRef) |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00461ac0_FUN_00461ac0.md` |
| Annotated | `docs/reconstruction/raw/aa_00461ac0_FUN_00461ac0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RcElem28_CopyCtor_EsiEdi.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00461ac0.cpp` |
| A/B | `docs/reconstruction/reviews/A_aa_00461ac0_RcElem28_CopyCtor_EsiEdi.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-00461ac0-004620b0-w35n-report.md` |
