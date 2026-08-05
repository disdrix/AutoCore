# Raw capture: CVOGCharacter_SetQuickBarSkill

| Field | Value |
|---|---|
| **Stable ID** | `aa_005208c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005208c0` |
| **Canonical name** | `CVOGCharacter_SetQuickBarSkill` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGCharacter_SetQuickBarSkill
   
   Writes one quick-bar skill id into the local player character.
     this+0x74c + slot*4 = int32 skillId  (0 or -1 = empty depending on path)
     this+0x634 |= 2       dirty bit for quick-bar state
   
   slot must be < 100; otherwise no-op.
   CreateCharacterExtended skill array is at absolute packet offset 0x730 (100 x int32).
   Empty check for auto-map uses skillId == -1 AND item COID both half-words == 0xFFFFFFFF.
   
   __thiscall: RET 0x8 (slot + skillId).
   Verified: AutoCore QuickBarUpdate session RE (2026-07). */

void __thiscall CVOGCharacter_SetQuickBarSkill(void *this,byte slot,int skillId)

{
  if (slot < 100) {
                    /* char+0x74c + slot*4 = skillId int32 */
    *(int *)((int)this + (uint)slot * 4 + 0x74c) = skillId;
    *(uint *)((int)this + 0x634) = *(uint *)((int)this + 0x634) | 2;
  }
  return;
}
```
