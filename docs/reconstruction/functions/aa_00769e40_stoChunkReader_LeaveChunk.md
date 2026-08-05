# Function record: stoChunkReader_LeaveChunk

| Field | Value |
|---|---|
| **Stable ID** | `aa_00769e40` |
| **Canonical name** | `stoChunkReader_LeaveChunk` |
| **Address** | `0x00769e40`–`0x00769fcc` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `storage` / arda2 `stoChunk` |
| **Completion status** | **Partial** — three-rep present; dual A/B **accept-with-gaps** (2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept-with-gaps** |

## Alias

- Ghidra: `FUN_00769e40`
- Scaffold: `Named_stoChunk_00769e40` (string-driven)

## Purpose

Leave the current open storage chunk on a `stoChunkReader`:

1. Clear sticky error `this+0x402c`.
2. **Binary** (`+0x4044 == 0`): compute ring-top index, load entry **end absolute** at `entry+0x10`, reposition stream window (`+0x18/+0x1c/+0x20`) or set sticky fail if end invalid vs `+0x28`.
3. **Text** (`+0x4044 != 0`): read tokens via `FUN_00767840(this,1)` balancing `{`/`}` from depth 1; on sticky fail log `"Could not find end of text chunk"` and return `-1`.
4. Pop ring write index `+0x4040`; if write becomes 0 clear base `+0x403c`.
5. Return sticky.

## Signature (sealed)

```c
/* stoChunkReader::LeaveChunk()  [arda2\storage\stoChunk.cpp] */
uint32_t __fastcall stoChunkReader_LeaveChunk(stoChunkReader *this /* ECX */);
/* returns 0 success, 0xffffffff failure (sticky at this+0x402c) */
```

## Key reader offsets touched

| Offset | Role | Confidence |
|---:|---|---|
| `+0x18` | stream cursor | High |
| `+0x1c` | stream base partner | High |
| `+0x20` | remaining / available | High |
| `+0x28` | stream limit (binary end check) | High (role) / Probable English |
| `+0x402c` | sticky error (clear + OR) | High |
| `+0x4034` | ring entry pointer array | High |
| `+0x4038` | ring capacity | High |
| `+0x403c` | ring base index | High |
| `+0x4040` | ring write / depth index | High |
| `+0x4044` | text-mode flag (0 = binary) | High |
| ring entry `+0x10` | end absolute position | High (use) / Probable English |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00769e40_FUN_00769e40.md`
- Annotated: `docs/reconstruction/raw/aa_00769e40_FUN_00769e40.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/stoChunkReader_LeaveChunk.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00769e40.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00769e40_stoChunkReader_LeaveChunk.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00769e40_stoChunkReader_LeaveChunk.md`
- Report: `docs/agents/task-dual-ab-00769e40-stochunkreader-leavechunk-report.md`

## Callers / callees

**Callees:** `FUN_00767840` (text tokenizer), `vog_LogMessage`, `std::string` ctor/dtor/`operator==`.

**Callers:** very wide Unserialize leave surface (Ghidra ≥50 listed; inventory xref_count **196**), including `FUN_00437120` okFlag thunk, geometry/index/vertex/effect/physics Unserialize, many `0x0045xxxx` KEYR-style readers.

**Siblings (not owned):**
- `stoChunkReader_EnterChunkScope` `0x004370b0`
- `stoChunkReader_OpenChunk` `0x0076a2c0`
- okFlag leave thunk `FUN_00437120` `0x00437120`

## Confidence

| Claim | Level |
|---|---|
| ABI ECX-this, no stack args, plain RET | High |
| Mode / sticky / ring pop | High |
| Binary end seek via entry+0x10 | High |
| Text brace-nest CF + log line | High |
| Ring entry full layout / endPos English | Probable |
| Tokenizer product name | Tentative |
| Runtime / differential | Open |
