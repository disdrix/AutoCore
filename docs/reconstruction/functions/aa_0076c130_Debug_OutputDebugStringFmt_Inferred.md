# Function record: Debug_OutputDebugStringFmt_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076c130` |
| **Canonical name** | `Debug_OutputDebugStringFmt_Inferred` |
| **Ghidra name** | `FUN_0076c130` |
| **Address** | `0x0076c130` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | debug / OutputDebugString |
| **Name class** | **Inferred** (structural; no product string on body) |
| **Completion status** | Dual A/B **accept** (W38-Y) |
| **Classification** | worker |

## Signature

```c
void Debug_OutputDebugStringFmt_Inferred(const char *format, ...);
```

## Behavior

1. If `format == NULL`, return.
2. `_vsnprintf(buf, 0x800, format, va_list_after_format)`.
3. `OutputDebugStringA(buf)`.

## Evidence

Live Ghidra `batch_decompile` + full-body `read_memory` (59 B) + 78 xrefs + call-site `ADD ESP` cleanup patterns. **No** `disassemble_bytes`.

## Related

- Consumer dual: `aa_0075eff0` `GfxDevice_Reset` (W37-N) — D3D ERROR map via this unit.
- Distinct from `FUN_0076cec0` (vog log string builder).
