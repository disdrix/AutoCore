# Raw capture: CVOGHBBase_SetPeriodAndCounter

| Field | Value |
|---|---|
| **Stable ID** | `aa_005081a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005081a0` |
| **Canonical name** | `CVOGHBBase_SetPeriodAndCounter` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGHBBase_SetPeriodAndCounter — write nPeriodSentinel (+0x0C) and optionally nPeriodCounter
   (+0x10).
   
   Parameters:
     this (ECX): CVOGHBBase* [API shows void*]
     nPeriodSentinel: value written to +0x0C
     bAlsoSetCounter: if true also write +0x10
   
   Algorithm: combat pool passes (-1000, true) for always-ready reschedule mode.
   
   Returns: void */

void __thiscall CVOGHBBase_SetPeriodAndCounter(void *this,int nPeriodSentinel,bool bAlsoSetCounter)

{
  *(int *)((int)this + 0xc) = nPeriodSentinel;
  if (bAlsoSetCounter) {
    *(int *)((int)this + 0x10) = nPeriodSentinel;
  }
  return;
}
```

---

## Append: 2026-07-29 residual seal (`decompile_function` + `read_memory`)

| Field | Value |
|---|---|
| Body range | `0x005081a0`–`0x005081b3` |
| Bytes (hex) | `80 7c 24 08 00 8b 44 24 04 89 41 0c 74 03 89 41 10 c2 08 00` |
| Stores | `[ecx+0x0C]` always; `[ecx+0x10]` if byte `[esp+8] != 0` |
| Epilogue | `ret 8` (two stack formals) |

Decoded ops (from bytes; not `disassemble_bytes`):

```
80 7C 24 08 00    cmp  byte ptr [esp+0x8], 0
8B 44 24 04       mov  eax, [esp+0x4]
89 41 0C          mov  [ecx+0x0C], eax
74 03             jz   skip
89 41 10          mov  [ecx+0x10], eax
C2 08 00          ret  8
```

Decompile re-fetch 2026-07-29: identical to original raw body.
Callers re-fetch: 24 UNCONDITIONAL_CALL sites (see function record).
