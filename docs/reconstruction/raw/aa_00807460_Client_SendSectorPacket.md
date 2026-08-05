# Raw capture: Client_SendSectorPacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_00807460` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00807460` |
| **Canonical name** | `Client_SendSectorPacket` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Client_SendSectorPacket — send a sector game packet via connection vtable +0x18.
   
   __thiscall this = game state (uses this+0xc78 connection).
   Stack: size (short), buffer pointer.
   EAX bits influence reliability flags: ~(EAX>>2)&2.
   
   Call sites include AutoPatrol (0x20B3 size 0x18) and FailMission C2S (0x20B2 size 0x18). */

undefined4 __thiscall Client_SendSectorPacket(void *this,short size,void *buffer)

{
  uint in_EAX;
  
  if (*(int *)((int)this + 0xc78) != 0) {
    (**(code **)(**(int **)((int)this + 0xc78) + 0x18))
              (0xffffffff,buffer,(int)size,~(in_EAX >> 2) & 2);
  }
  return 0;
}
```
