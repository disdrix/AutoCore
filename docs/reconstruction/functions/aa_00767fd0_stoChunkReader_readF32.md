# Function record: stoChunkReader_readF32

| Field | Value |
|---|---|
| **Stable ID** | `aa_00767fd0` |
| **Canonical name** | `stoChunkReader_readF32` |
| **Address** | `0x00767fd0` |
| **Body span** | `00767fd0` – `00768254` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `sto-chunk` / arda2 storage (`stoChunk.cpp`) |
| **Completion status** | **Dual complete (accept-with-gaps)** — three-rep + A/B 2026-07-29 W17-G |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_00767fd0`
- Prior auto-name: `Named_stoChunk_00767fd0`
- Scaffold: `FUN_00767fd0.cpp`

## Purpose

Read **one float32** from a `stoChunkReader` via the **text/token** path: scan a whitespace- or quote-delimited token (or consume pushback at `+0x404c`), reject past-end `"}"`, then `sscanf("%f")` into the caller’s out pointer. Sticky-fail when stream validity `+0x402c < 0` or token is not a float.

Primary consumer of non-binary mode in `stoChunkReader_readF32Array` (`0x00436090`); also direct callees from physics/asset unserialize (`phyBone_unserialize`, KEYR-style readers, etc.).

## Signature (decompiler + epilogue sealed)

```c
/* __thiscall; ECX = reader; stack = float *out; ret 4 */
uint32_t __thiscall stoChunkReader_readF32(void *reader /*ECX*/, float *out /*stack*/);
/* return 0 success; 0xffffffff fail */
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00767fd0_FUN_00767fd0.md` (live seal append 2026-07-29)
- Annotated: `docs/reconstruction/raw/aa_00767fd0_FUN_00767fd0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/stoChunkReader_readF32.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00767fd0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00767fd0_stoChunkReader_readF32.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00767fd0_stoChunkReader_readF32.md`

## Callers / callees

**Callees:** `FUN_00435df0`, `FUN_00436250`, `FUN_0076cec0`, `vog_LogMessage`, `isspace`, `sscanf`, `std::string` ops.

**Callers (Ghidra sample):** `stoChunkReader_readF32Array`, `phyBone_unserialize`, `FUN_0043b570`, `FUN_006346d0`, `FUN_0072cde0`, `FUN_0074ce60`, `FUN_0075a980`, `FUN_007614d0`, `FUN_00769990`, `FUN_0095dc70`, `FUN_00981ac0`, `FUN_009895c0`, `FUN_0098dbb0`.

## Confidence

| Claim | Level |
|---|---|
| Control flow from live decompile | **High** |
| `__thiscall` + `ret 4` + float out | **High** |
| Text/token + `sscanf %f` role | **High** (strings + CF) |
| Offsets `+0x18/+0x1c/+0x20/+0x2c/+0x402c/+0x404c/+0x4060` | **High** |
| Product class field names beyond offsets | **Probable / Tentative** |
| Outer quote-loop exact boundary | **Probable** (decompiler `while(true)`) |
| Runtime / differential | **Open** |
