# Function record: CVOGHBBase_EndOrDestroy_SoftMarkEpilogue

| Field | Value |
|---|---|
| **Stable ID** | `aa_0050846f` |
| **Canonical name** | `CVOGHBBase_EndOrDestroy_SoftMarkEpilogue` |
| **Ghidra name** | `FUN_0050846f` |
| **Address** | `0x0050846f` |
| **Body** | `0x0050846f`–`0x00508488` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | heartbeat / CVOGHBBase |
| **Completion status** | **Dual A/B complete** (2026-07-29 W21-B) — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Soft-tail of `CVOGHBBase_EndOrDestroy`: mark HB soft-ended (`+0x20=1`), clear owner link (`+0x18`), restore SEH ExceptionList, complete parent frame with **`ret 8`**.

## Signature (image-sealed)

```c
// Fragment — not a normal __thiscall entry.
// Live-in: ESI=CVOGHBBase* this, EBX=clear (0), EBP=parent frame
// RET 8 (parent EndOrDestroy stack cleanup)
void CVOGHBBase_EndOrDestroy_SoftMarkEpilogue(void);
```

## Artifacts

| Role | Path |
|---|---|
| Raw scaffold + W21-B re-verify | `docs/reconstruction/raw/aa_0050846f_FUN_0050846f.md` |
| Annotated | `docs/reconstruction/raw/aa_0050846f_FUN_0050846f.annotated.md` |
| Raw named | `docs/reconstruction/raw/aa_0050846f_CVOGHBBase_EndOrDestroy_SoftMarkEpilogue.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBBase_EndOrDestroy_SoftMarkEpilogue.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_0050846f.cpp` |
| Legacy seed alias | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGHBMissionPatro_0050846f.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_0050846f_CVOGHBBase_EndOrDestroy_SoftMarkEpilogue.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0050846f_CVOGHBBase_EndOrDestroy_SoftMarkEpilogue.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0050846f_FUN_0050846f.md` |

## Callers / callees

| Direction | Address | Name / role |
|---|---|---|
| Caller | `0x0050843d` | `CVOGHBBase_EndOrDestroy_HardListUnlink` (4 sites → always soft tail) |
| Parent | `0x005083f0` | `CVOGHBBase_EndOrDestroy` |
| Callees | — | none (leaf) |

## Layout / constants

| Item | Value | Conf |
|---|---|---|
| Soft-ended flag | `this+0x20 = 1` | High |
| Owner link clear | `this+0x18 = ebx` (0) | High |
| ExceptionList slot | `[ebp-0xc]` → `fs:[0]` | High |
| Epilogue | `ret 8` | High |

## Confidence

| Claim | Level |
|---|---|
| Complete body CF / bytes | High |
| Register live-in contract | High (parent dual + bytes) |
| Leaf / sole caller family | High |
| Product C++ name | Tentative (`_SoftMarkEpilogue` inferred) |
| Runtime / bit-exact | Open |
