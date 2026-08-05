# Annotated low-level: stoChunkWriter_WriteI32

| Field | Value |
|---|---|
| Stable ID | `aa_00439870` |
| VA | `0x00439870` |
| Canonical name | `stoChunkWriter_WriteI32` |
| System | storage / arda2.stoChunk |
| Date | 2026-07-29 (W19-Q dual seal) |

## Role

Write one **signed 32-bit integer** through a `stoChunkWriter`:

| Mode (`writer+0x1c` / `[7]`) | Behavior |
|---|---|
| **0 binary** | `stream->vtbl[0x18](&value, 4)` — raw little-endian 4 bytes |
| **nonzero text** | `stoChunkWriter_WriteFormatted(writer, "%i", value)` then `textCol=0` then write `"\r\n"` (2) |

Return: cumulative **status** OR at `writer+0x04` (`[1]`).

## ABI (register)

| Register | Role | Evidence |
|---|---|---|
| **ESI** | `stoChunkWriter*` | Entry uses `[esi+0x1c]`; call sites leave ESI as writer |
| **EAX** | `const int32_t*` (value pointer) | `mov eax,[eax]` load; callers `lea eax, [obj+field]` |
| **Return EAX** | `writer->status` | `mov eax,[esi+4]; ret` both paths |

Not classic `__thiscall` (ECX unused for writer). Sibling `WriteU32` @ `0x00439810` identical with `"%u"`.

## Writer layout (fields used)

| Off | Decomp | Field |
|---|---|---|
| +0x00 | `*ESI` | `stream*` (interface; write at vtbl +0x18) |
| +0x04 | `ESI[1]` | `status` (OR of write results; return) |
| +0x1c | `ESI[7]` | `mode` (0 binary / text) |
| +0x20 | `ESI[8]` | `textColumn` (zeroed after text value line) |

## String DATs

| VA | Content |
|---|---|
| `0x00a37c64` | `"%i"` |
| `0x00a97b84` | `"\r\n"` |

## Pseudocode (annotated)

```c
// ESI = stoChunkWriter* writer
// EAX = const int32_t* pValue
uint32_t stoChunkWriter_WriteI32(void)
{
  int32_t value = *pValue;   // local_4
  if (writer->mode == 0) {
    writer->status |= stream_write(&value, 4);   // vtbl+0x18
    return writer->status;
  }
  // text:
  writer->status |= stoChunkWriter_WriteFormatted(writer, "%i", value);  // EAX=writer ABI inside helper
  writer->textColumn = 0;
  writer->status |= stream_write("\r\n", 2);
  return writer->status;
}
```

Note: decompiler shows `FUN_00767160(&DAT_00a37c64, local_4)` without explicit writer arg; helper expects writer in **EAX** (`mov esi,eax` at its entry). Entry of this unit uses ESI as writer; text path does `mov eax,esi` before the call (sealed in body bytes: `8b c6 e8 …`).

## Open questions

- Exact stream interface type behind `*writer` (write method signature).
- Whether any caller relies on text column mid-line (this unit forces col=0 + CRLF after the number).
