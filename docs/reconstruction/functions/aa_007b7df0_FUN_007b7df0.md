# Function record: FUN_007b7df0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b7df0` |
| **Canonical name** | `FUN_007b7df0` |
| **Address** | `0x007b7df0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | unknown |
| **Completion status** | **Dual A/B sealed** (accept-with-gaps) — leave bookend for XP/credits table Ensures |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

Human name: `DBReader_ReleaseDataConnection` (INFERRED; refcount−− + COM Release)

## Alias_prev

Human name: `Named_CalleeOf_Named_VOG_DEBUG_STOP_007b7df0`

## Purpose

DBReader **connection leave**: `this+0x20` refcount−−; at zero (and not XML mode `DAT_00d1793c`) Releases `+0x28` then `+0x24` (vtbl+8), clears `*this`. Twin of `FUN_007e1d80`. Full body asm-sealed (64 bytes).

## Signature (decompiler-derived)

```c
uint32_t /* always 0 */ __fastcall FUN_007b7df0(uint8_t *pDbReaderCtx);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007b7df0_FUN_007b7df0.md`
- Annotated: `docs/reconstruction/raw/aa_007b7df0_FUN_007b7df0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_007b7df0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_007b7df0_FUN_007b7df0.md`
- Review B: `docs/reconstruction/reviews/B_aa_007b7df0_FUN_007b7df0.md`

## Callers / callees

- **Callers:** same Ensure* family as enter + other table loaders
- **Callees:** COM `Release` only (indirect)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + asm | High |
| Refcount / release order | High |
| Types | Tentative |
