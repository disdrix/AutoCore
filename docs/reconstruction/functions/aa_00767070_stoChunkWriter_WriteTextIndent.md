# Function record: stoChunkWriter_WriteTextIndent

| Field | Value |
|---|---|
| **Stable ID** | `aa_00767070` |
| **Canonical name** | `stoChunkWriter_WriteTextIndent` |
| **Prior / Ghidra name** | `FUN_00767070` |
| **Address** | `0x00767070`–`0x0076709d` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `storage` / arda2 `stoChunk` |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-07-29 (W17-R OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_00767070`
- `Named_CalleeOf_Named_CalleeOf_Named_stoChunk_00767070` (auto scaffold)

## Purpose

Text-mode **line-start indent** helper for `stoChunkWriter`:

1. `count = depth * 4` (`depth` @ `writer+0x18`).
2. `textCol = count` (`textCol` @ `writer+0x20`).
3. Write `count` single-space characters via stream `vtbl+0x18` (`DAT_00a2a000` = `" "`).
4. Sticky-OR each write status into `writer+0x04`; return that status.

Called only from `stoChunkWriter_WriteFormatted` when `textCol == 0` (after optional wrap-to-newline).

## Signature (sealed)

```c
// Register ABI: writer in ESI. No stack args. Plain RET.
// Returns sticky status (writer+0x04) in EAX.
uint32_t stoChunkWriter_WriteTextIndent(/* ESI: StoChunkWriter* writer */);
```

Ghidra prints `undefined FUN_00767070(void)` — **bytes own the ESI ABI**.

## Writer fields touched

| Off | Field | Role |
|---:|---|---|
| `+0x00` | `stream*` | write target |
| `+0x04` | `status` | sticky OR in/out |
| `+0x18` | `depth` | indent units (×4 spaces) |
| `+0x20` | `textCol` | set to `depth*4` before/without mid-line space path |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00767070_FUN_00767070.md` |
| Annotated | `docs/reconstruction/raw/aa_00767070_FUN_00767070.annotated.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/stoChunkWriter_WriteTextIndent.cpp` |
| Clean (FUN_*) | `docs/reconstruction/reconstructed-exact/FUN_00767070.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00767070_stoChunkWriter_WriteTextIndent.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00767070_stoChunkWriter_WriteTextIndent.md` |

## Callers / callees

| Direction | Symbol | VA |
|---|---|---|
| Caller | `stoChunkWriter_WriteFormatted` | `0x00767160` (call site `0x007671ba`) |
| Callee | stream `vt+0x18` write | virtual |

## Confidence

| Claim | Level |
|---|---|
| CF: depth×4 → textCol → write N spaces → return status | **High** |
| ESI = writer register ABI | **High** |
| DAT_00a2a000 = `" "` | **High** |
| depth @ +0x18, textCol @ +0x20, status @ +0x04 | **High** (sibling EndChunk/WriteFormatted duals + bytes) |
| Product English plate name | **Low** |
| Runtime / bit-exact | **Open** |
