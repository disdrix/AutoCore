# Function record: stoChunkWriter_WriteU32

| Field | Value |
|---|---|
| **Stable ID** | `aa_00439810` |
| **Canonical name** | `stoChunkWriter_WriteU32` |
| **Former name** | `FUN_00439810` |
| **Address** | `0x00439810` |
| **Body range** | `0x00439810`–`0x00439861` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | storage / arda2.stoChunk |
| **Completion status** | **complete** (dual A/B **accept**; runtime/diff open) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00439810_stoChunkWriter_WriteU32.md`, `reviews/B_aa_00439810_stoChunkWriter_WriteU32.md` |
| **Last reviewed** | `2026-07-29` (W20-D) |

## Alias

- `FUN_00439810` (Ghidra default)
- `Named_CalleeOf_Named_effEffect_00439810` (prior parent-seed alias; superseded)

## Purpose

Serialize one **unsigned int32** onto a stoChunk writer stream: raw LE dword when binary (`writer+0x1c == 0`), or a text line `"%u\r\n"` when text.

## Signature

```c
// Register ABI (not ECX thiscall):
//   ESI = stoChunkWriter*
//   EAX = const uint32_t* pValue
//   returns writer->status at +0x04
uint32_t stoChunkWriter_WriteU32(void);
```

## Layout (writer)

| Off | Field |
|---:|---|
| `+0x00` | stream* (vtbl write @ `+0x18`) |
| `+0x04` | status (OR flags; return) |
| `+0x1c` | mode (0 binary / nonzero text) |
| `+0x20` | text column (zeroed in text path) |

## Algorithm

1. `v = *pValue`.
2. If mode == 0: `status |= stream.write(&v, 4); return status`.
3. Else: `status |= WriteFormatted("%u", v)`; `textCol = 0`; `status |= write("\r\n", 2)`; return status.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00439810_FUN_00439810.md`
- Annotated: `docs/reconstruction/raw/aa_00439810_FUN_00439810.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/stoChunkWriter_WriteU32.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_00439810.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-own-w20d-00439810-006082e0-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | stream vtbl `+0x18`; `stoChunkWriter_WriteFormatted` `0x00767160` |
| **Callers** | Many serializers (gfx geometry piece, index/vertex, chunk writers `0x00458xxx`…, etc.) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + body bytes | **High** |
| Format `"%u"` + CRLF | **High** |
| Mode gate + binary size 4 | **High** |
| ESI/EAX register ABI | **High** |
| Twin relationship to WriteI32 | **High** |
| Stream iface product type | **Tentative** |
| Product class English | **Inferred** (`stoChunkWriter` family) |

## Related

- `aa_00439870` `stoChunkWriter_WriteI32` (`"%i"`)
- `aa_00767160` `stoChunkWriter_WriteFormatted`
