# Raw capture: CVOGHBBase_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508200` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00508200` |
| **Canonical name** | `CVOGHBBase_ctor` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* TimedAction_ctorBase — zero/init common TimedAction fields; vtable = base.
   Sets lastFireTick(+0x14) = g_ActionSchedulerTickMs. */

void __thiscall CVOGHBBase_ctor(void *this)

{
  *(undefined ***)this = &PTR_FUN_009cdab0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined1 *)((int)this + 0x21) = 1;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(uint *)((int)this + 0x14) = g_dwClientTickMs;
  *(undefined1 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 4) = 0;
  return;
}
```
