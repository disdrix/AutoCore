# Raw capture: CVOGHBBase_StampLastFireTime

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508270` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00508270` |
| **Canonical name** | `CVOGHBBase_StampLastFireTime` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall CVOGHBBase_StampLastFireTime(CVOGHBBase *this)

{
  this->dwLastFireTickMs = g_dwClientTickMs;
  return;
}
```

---

## Append: 2026-07-29 residual seal (`decompile_function` + `read_memory`)

| Field | Value |
|---|---|
| Body range | `0x00508270`–`0x00508278` |
| Bytes (hex) | `a1 cc 41 b0 00 89 41 14 c3` |
| Global | `g_dwClientTickMs` @ `0x00b041cc` |
| Store | `[ecx+0x14]` only |

Decoded ops (from bytes; not `disassemble_bytes`):

``
A1 CC41B000    mov  eax, [0x00b041cc]
89 41 14       mov  [ecx+0x14], eax
C3             ret
``

Decompile re-fetch 2026-07-29: identical to original raw body.
