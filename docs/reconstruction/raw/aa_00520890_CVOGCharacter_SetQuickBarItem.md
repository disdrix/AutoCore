# Raw capture: CVOGCharacter_SetQuickBarItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_00520890` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00520890` |
| **Canonical name** | `CVOGCharacter_SetQuickBarItem` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGCharacter_SetQuickBarItem
   
   Writes one quick-bar item COID into the local player character.
     this+0x930 + slot*8 = int64 itemCoid  (-1 = empty)
     this+0x634 |= 2       dirty bit for quick-bar state
   
   slot must be < 100; otherwise no-op.
   Called from Client_RecvCreateCharacter when applying CreateCharacterExtended offsets
   0x410 (100 x int64 item COIDs) and from QuickBar UI clear/assign paths.
   
   __thiscall: RET 0xC (slot + valueLo + valueHi).
   Verified: AutoCore QuickBarUpdate session RE (2026-07). */

void __thiscall CVOGCharacter_SetQuickBarItem(void *this,byte slot,uint valueLo,uint valueHi)

{
  if (slot < 100) {
                    /* char+0x930 + slot*8 = itemCoid int64 */
    *(uint *)((int)this + (uint)slot * 8 + 0x930) = valueLo;
    *(uint *)((int)this + (uint)slot * 8 + 0x934) = valueHi;
    *(uint *)((int)this + 0x634) = *(uint *)((int)this + 0x634) | 2;
  }
  return;
}
```
