# Raw capture: NetObject_SetMaskBits

| Field | Value |
|---|---|
| **Stable ID** | `aa_00786c10` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00786c10` |
| **Canonical name** | `NetObject_SetMaskBits` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* NetObject_SetMaskBits — dirty ghost update mask bits for next pack.
   
   Parameters (INFERRED calling convention / arg order — verify if masks fail):
     pNetObject — ghost/net object
     dwMaskLow / dwMaskHigh — 64-bit mask split; combat pool uses single 32-bit values in low slot
   
   Combat-pool masks (GHOST_VEHICLE_MASK):
     POWER_MASK  0x08000000
     SHIELD_MASK 0x04000000
     HEAT_MASK   0x20000000
   
   Observed call sites sometimes pass (object, mask, 0) or (object, 0, mask) — arg order may vary
   by site. */

void __thiscall NetObject_SetMaskBits(void *this,uint dwMaskLo,uint dwMaskHi)

{
  void *pvVar1;
  
  pvVar1 = g_pNetObjectDirtyListHead;
  if ((*(int *)((int)this + 0x18) == 0 && *(int *)((int)this + 0x1c) == 0) &&
     (pvVar1 = this, g_pNetObjectDirtyListHead != (void *)0x0)) {
    *(void **)((int)this + 0x10) = g_pNetObjectDirtyListHead;
    *(void **)((int)g_pNetObjectDirtyListHead + 0xc) = this;
    pvVar1 = this;
  }
  g_pNetObjectDirtyListHead = pvVar1;
  *(uint *)((int)this + 0x18) = *(uint *)((int)this + 0x18) | dwMaskLo;
  *(uint *)((int)this + 0x1c) = *(uint *)((int)this + 0x1c) | dwMaskHi;
  return;
}
```
