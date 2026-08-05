# Raw capture: CVOGHBBase_GetRemainingSeconds

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508280` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00508280` |
| **Canonical name** | `CVOGHBBase_GetRemainingSeconds` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* TimedAction_GetRemainingSeconds — UI helper: remaining time until next fire as float seconds
   (integer ms * 0.001). Used for "Remaining" tooltips. */

float __fastcall CVOGHBBase_GetRemainingSeconds(CVOGHBBase *this)

{
  float fVar1;
  int iVar2;
  
  iVar2 = (this->dwLastFireTickMs - g_dwClientTickMs) + this->nPeriodMs;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  iVar2 = (this->nPeriodCounter + -1) * this->nPeriodMs + iVar2;
  fVar1 = (float)iVar2;
  if (iVar2 < 0) {
    fVar1 = fVar1 + _DAT_00aaa5dc;
  }
  return fVar1 * g_flMsToSeconds_Inferred;
}
```

---

## Residual seal notes (2026-07-29) — append only

- Live tools: `decompile_function` + `read_memory` (no `disassemble_bytes`).
- Body range: `00508280`–`005082b5` (54 bytes). Hex:
  `51 8b 41 14 2b 05 cc 41 b0 00 8b 51 08 03 c2 79 02 33 c0 8b 49 10 83 e9 01 0f af ca 03 c8 85 c9 89 0c 24 db 04 24 7d 06 d8 05 dc a5 aa 00 d8 0d 2c f7 a0 00 59 c3`
- Period load is **`[ecx+0x08]`** (`nPeriodMs`); counter **`[ecx+0x10]`**; lastFire **`[ecx+0x14]`**. **No** `+0x0C` access.
- `0x00aaa5dc` → `00 00 80 4f` = 4294967296.0f; `0x00a0f72c` → `6f 12 83 3a` = 0.001f.
- Dual A/B: accept (sealed High). See reviews for inventory.
