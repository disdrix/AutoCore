# Function record: stoChunkReader_readF32Array

| Field | Value |
|---|---|
| **Stable ID** | `aa_00436090` |
| **Canonical name** | `stoChunkReader_readF32Array` |
| **Address** | `0x00436090` |
| **Body span** | `00436090` – `00436127` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `sto-chunk` / asset serialize |
| **Completion status** | **Dual complete (accept-with-gaps)** — three-rep present; A/B dual 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Read **N** float32 values from a sto chunk reader into a destination array. **N** in **EAX**, **dest** in **ECX**, **reader** on stack (`ret 4`). Binary mode (`reader+0x4044==0`): bulk via `FUN_00435f30` when `N>=16`, else per-element LE load with optional `FUN_00435df0` refill. Non-zero mode: per-element `FUN_00767fd0(reader, dest_elem)`.

## Signature (decompiler-derived + asm sealed)

```c
/* count in EAX; dest in ECX; reader stack; returns 0 or bulk status */
uint32_t __fastcall stoChunkReader_readF32Array(float *dest /*ECX*/,
                                                void *reader /*stack*/,
                                                int count /*EAX*/);
/* Ghidra: undefined4 __thiscall (undefined4 *param_1_dest, int param_2_reader) + in_EAX */
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00436090_stoChunkReader_readF32Array.md`
- Annotated: `docs/reconstruction/raw/aa_00436090_stoChunkReader_readF32Array.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/stoChunkReader_readF32Array.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00436090_stoChunkReader_readF32Array.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00436090_stoChunkReader_readF32Array.md`

## Callers / callees

**Callees (from own body):** `FUN_00435df0` (refill), `FUN_00435f30` (bulk bytes @ `reader+0x14`), `FUN_00767fd0` (alt per-element).

**Callers (xrefs sample):** `phyBoneSharedData_unserialize`, `FUN_0045d810` / `FUN_0045daf0` / … KEYR-style readers, `FUN_0074ce60`, `FUN_0043edb0`, `FUN_0095dc70`, others.

## Confidence

| Claim | Level |
|---|---|
| Control flow from live decompile + asm | **High** |
| EAX count / ECX dest / stack reader | **High** |
| Mode `+0x4044`, cursor/window offsets | **High** |
| Bulk `this = reader+0x14` | **High (asm)**; clean plate 2-arg residual |
| Alt-path `FUN_00767fd0` product semantics | **Tentative** |
| Parameter semantic names for full class layout | **Probable** |
| Runtime / differential | **Open** |
