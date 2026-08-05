# Function record: stoChunkReader_ReadQuotedTag

| Field | Value |
|---|---|
| **Stable ID** | `aa_00769b70` |
| **Canonical name** | `stoChunkReader_ReadQuotedTag` |
| **Address** | `0x00769b70`–`0x00769d79` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `storage` / arda2 `stoChunk` |
| **Completion status** | **Sealed** — dual A/B **accept** (2026-07-29 W25-S) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept** |

## Alias

- Ghidra: `FUN_00769b70`
- Scaffold: `Named_CalleeOf_Named_stoChunk_00769b70`
- OpenChunk review name: text ReadQuotedTag

## Purpose

Read a **double-quoted** chunk tag token from a `stoChunkReader` into a caller-owned `std::string` (EDI), stripping the surrounding `"` characters:

1. Fail immediately if sticky `<0`.
2. Obtain token via pushback or the shared text scan loop.
3. `"}"` → past-end log + sticky fail + re-stash → **−1**.
4. Else if `size>1` and first/last are `"` → `substr(1, size-2)` → **0**.
5. Else → **−1** (bare / single-quoted / brace tokens rejected).

OpenChunk text path uses this after optional pushback handling; PeekChunkTag and expected-string helper also call it.

## Signature (sealed)

```c
/* stoChunkReader quoted tag reader [arda2\storage\stoChunk.cpp] */
/* EDI = std::string *outTag (register) */
uint32_t __stdcall stoChunkReader_ReadQuotedTag(
    stoChunkReader *reader);   /* stack; ret 4; SEH */
/* EAX: 0 success (stripped), 0xffffffff fail */
```

## Key reader offsets touched

| Offset | Role | Confidence |
|---:|---|---|
| `+0x18` | stream cursor | High |
| `+0x1c` | stream base partner | High |
| `+0x20` | remaining / available | High |
| `+0x2c` | window buffer base | High |
| `+0x402c` | sticky error | High |
| `+0x404c` | pushback `std::string` | High |
| `+0x4060` | pushback non-empty | High |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00769b70_FUN_00769b70.md`
- Annotated: `docs/reconstruction/raw/aa_00769b70_FUN_00769b70.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/stoChunkReader_ReadQuotedTag.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00769b70.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00769b70_stoChunkReader_ReadQuotedTag.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00769b70_stoChunkReader_ReadQuotedTag.md`
- Report: `docs/agents/task-dual-ab-00767840-00769b70-w25s-report.md`

## Callers / callees

**Callees:** `FUN_00435df0`, `vog_LogMessage`, `isspace`, `std::string` resize/`=`/`+=`/`==`/`substr`/dtor.

**Callers (3):**
- `FUN_0076a200` @ `0076a21c` (expected-string helper)
- `stoChunkReader_OpenChunk` `0x0076a2c0` @ `0076a539`
- `stoChunkReader_PeekChunkTag` `0x0076a900` @ `0076a9b8`

**Siblings:** `stoChunkReader_ReadTextToken` `0x00767840`; OpenChunk / PeekChunkTag / LeaveChunk.

## Confidence

| Claim | Level |
|---|---|
| Body span + SEH + `ret 4` | High |
| EDI out + stack reader | High |
| Scan/pushback twin of ReadTextToken | High |
| Success only on double-quoted strip | High (bytes `substr(1,size-2)`) |
| Product English spelling | Probable |
| Runtime / differential | Open |
