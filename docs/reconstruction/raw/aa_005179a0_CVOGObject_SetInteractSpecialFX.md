# Raw capture: CVOGObject_SetInteractSpecialFX

| Field | Value |
|---|---|
| **Stable ID** | `aa_005179a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005179a0` |
| **Canonical name** | `CVOGObject_SetInteractSpecialFX` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGObject_SetInteractSpecialFX  (thiscall)
   
   Replace interact FX on object: if this+0x130 (offset 0x4c dwords) non-null, tear down old FX.
   If newFx non-null, call virtual +0xf8(newFx, 1, 0) to attach.
   Stores newFx at this+0x4c*4. */

void __thiscall CVOGObject_SetInteractSpecialFX(void *this,void *pSpecialFx)

{
  if (*(int *)((int)this + 0x130) != 0) {
    FUN_00517250(*(int *)((int)this + 0x130));
  }
  if (pSpecialFx != (void *)0x0) {
    (**(code **)(*(int *)this + 0xf8))(pSpecialFx,1,0);
  }
  *(void **)((int)this + 0x130) = pSpecialFx;
  return;
}
```
