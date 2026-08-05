# Function record: stoChunkReader_ReadTextToken

| Field | Value |
|---|---|
| **Stable ID** | `aa_00767840` |
| **Canonical name** | `stoChunkReader_ReadTextToken` |
| **Address** | `0x00767840`–`0x007679d3` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `storage` / arda2 `stoChunk` |
| **Completion status** | **Sealed** — dual A/B **accept** (2026-07-29 W25-S) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept** |

## Alias

- Ghidra: `FUN_00767840`
- Scaffold: `Named_CalleeOf_Named_stoChunk_00767840`
- Structural: text tokenizer / ReadToken (product spelling residual)

## Purpose

Read the next text token from a `stoChunkReader` into a caller-owned `std::string` (EDI):

1. Optional early fail when sticky already `<0` and `allowEndBrace==0`.
2. Consume pushback string (`+0x404c` when `+0x4060!=0`) **or** scan the stream window (whitespace skip, optional `'`/`"` quotes, refill via `FUN_00435df0`).
3. If token is `"}"` and `allowEndBrace==0`: log past-end, sticky=`-1`, re-stash pushback, clear out → **−1**.
4. Else return **0** with token in `*out` (quotes kept if quoted).

LeaveChunk calls with `allowEndBrace=1` so brace tokens are normal success results.

## Signature (sealed)

```c
/* stoChunkReader text tokenizer [arda2\storage\stoChunk.cpp] */
/* EDI = std::string *outToken (register) */
uint32_t __stdcall stoChunkReader_ReadTextToken(
    stoChunkReader *reader,   /* stack */
    char allowEndBrace);      /* stack; ret 8 */
/* EAX: 0 success, 0xffffffff fail */
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
| `+0x4060` | pushback non-empty (size@string+0x14) | High |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00767840_FUN_00767840.md`
- Annotated: `docs/reconstruction/raw/aa_00767840_FUN_00767840.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/stoChunkReader_ReadTextToken.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00767840.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00767840_stoChunkReader_ReadTextToken.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00767840_stoChunkReader_ReadTextToken.md`
- Report: `docs/agents/task-dual-ab-00767840-00769b70-w25s-report.md`

## Callers / callees

**Callees:** `FUN_00435df0`, `vog_LogMessage`, `isspace`, `std::string` resize/`=`/`+=`/`==`.

**Callers (2):**
- `stoChunkReader_LeaveChunk` `0x00769e40` @ `00769f07` (`allowEndBrace=1`)
- `stoChunkReader_PeekChunkTag` `0x0076a900` @ `0076a96d`

**Siblings:** `stoChunkReader_ReadQuotedTag` `0x00769b70`; typed text readers (`readF32`, TextReadU32) share scan family.

## Confidence

| Claim | Level |
|---|---|
| Body span + `ret 8` | High |
| EDI out + stack reader/flag | High |
| Pushback / scan / quote / isspace CF | High |
| `}` past-end gated by allowEndBrace | High |
| Offsets `+0x18/+0x1c/+0x20/+0x2c/+0x402c/+0x404c/+0x4060` | High |
| Product English spelling | Probable |
| Runtime / differential | Open |
