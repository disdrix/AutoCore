# Function record: PalantirSub10_DestroyOwnedPtrVecAndComUninit

| Field | Value |
|---|---|
| **Stable ID** | `aa_00964d00` |
| **Canonical name** | `PalantirSub10_DestroyOwnedPtrVecAndComUninit` |
| **Ghidra name** | `FUN_00964d00` |
| **Address** | `0x00964d00`–`0x00964DAA` exclusive (**170 B** / `0xAA`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / Palantir nested subobject at `host+0x10` |
| **Classification** | worker |
| **Completion status** | **Dual A/B filed** (W35-J 2026-07-29) — ABI/CF sealed; element dual open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Preferred: `PalantirSub10_DestroyOwnedPtrVecAndComUninit` (**Inferred** structural; nest under sealed Palantir complete dtor)
- Ghidra: `FUN_00964d00`
- Parent: `Palantir_CompleteDtor` (`aa_00754320`) destroys this as `host+0x10` after `+0x30`

## Purpose

MSVC-style nested cleanup for the Palantir+0x10 embedded subobject: destroy owned heap objects in a pointer vector, free the buffer, Release a held COM interface, and call `CoUninitialize`.

## Signature (sealed)

```c
// stdcall; RET 4; void
void __stdcall PalantirSub10_DestroyOwnedPtrVecAndComUninit(PalantirSub10* self);
```

## Layout (relative to self)

| Off | Role |
|---|---|
| +0x00 | unused in body |
| +0x04 | `void** begin` |
| +0x08 | `void** end` |
| +0x0C | `void** capEnd` |
| +0x10 | COM iface* (`Release` @ vtbl+8) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00964d00_FUN_00964d00.md` (+ W35-J append)
- Annotated: `docs/reconstruction/raw/aa_00964d00_FUN_00964d00.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/PalantirSub10_DestroyOwnedPtrVecAndComUninit.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00964d00.cpp`
- Function (Ghidra id): `docs/reconstruction/functions/aa_00964d00_FUN_00964d00.md`
- Review A/B: `reviews/A_aa_00964d00_PalantirSub10_DestroyOwnedPtrVecAndComUninit.md`, `reviews/B_aa_00964d00_PalantirSub10_DestroyOwnedPtrVecAndComUninit.md`

## Callers / callees

| Callers | Callees |
|---|---|
| `Palantir_CompleteDtor`; Unwind `@009afcef`/`@009afd2b` | `FUN_00735390` (unowned), `operator_delete`, `CoUninitialize` |

## Confidence

| Claim | Level |
|---|---|
| ABI / CF / COM / CoUninit | **High** |
| Element product plate | **Low** |
