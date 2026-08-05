# Function record: CVOGHBToken_OnEnd

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ffc20` |
| **Canonical name** | `CVOGHBToken_OnEnd` (**RTTI Confirmed**) |
| **Ghidra** | `FUN_005ffc20` |
| **Address** | `0x005ffc20` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | heartbeat / CVOGHBToken |
| **Completion status** | **partial** — dual A/B 2026-07-29 (W17-K); flag English open |
| **Dual** | `reviews/A_aa_005ffc20_CVOGHBToken_OnEnd.md`, `B_*` |
| **Bit-for-bit / runtime / diff** | Open (not run) |

## Purpose

`CVOGHBToken` virtual **OnEnd** (`vtbl+0x14`). When the related object at `this+0x18` resolves a host via `vtbl+0x1d4` and `this+0x10 < 1`, set character flag byte `+0x529 = 1` with net dirty mask `0x100` (via `FUN_005208e0`). Always ends in empty stub `FUN_005081f0`.

## Signature

```c
// __thiscall  ECX = CVOGHBToken*
void CVOGHBToken_OnEnd(CVOGHBToken *this);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005ffc20_FUN_005ffc20.md`
- Annotated: `docs/reconstruction/raw/aa_005ffc20_FUN_005ffc20.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_005ffc20.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_005ffc20_CVOGHBToken_OnEnd.md`
- Dual B: `docs/reconstruction/reviews/B_aa_005ffc20_CVOGHBToken_OnEnd.md`

## Callers / callees

| Dir | VA / symbol | Role |
|---|---|---|
| Dispatch | DATA `0x009dde40` | vtbl+0x14 OnEnd only |
| Callee | `0x005208e0` | `Character_SetFlagByte_plus529_WithNetDirty` |
| Callee | `0x005081f0` | empty nop vfunc (tail) |
| Callee | indirect `+0x1d4`, `+0x210` | related resolve / character resolve |

## Confidence

| Claim | Level |
|---|---|
| RTTI class `CVOGHBToken` + OnEnd slot | **High** |
| CF gates `+0x18` / `+0x10` / set flag 1 | **High** |
| English meaning of `+0x529` / `+0x10` | **Open** / **Tentative** |
