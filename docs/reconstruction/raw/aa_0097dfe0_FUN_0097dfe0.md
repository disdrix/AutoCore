# Raw capture: FUN_0097dfe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0097dfe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0097dfe0` |
| **Canonical name** | `FUN_0097dfe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* UI_CooldownGaugeWidget_ctor(this)
   
   Constructs quickbar cooldown gauge widget (0x4bc) used by
   i_d_qb_2d_btn_quickbar_cooldown.xml. */

void * UI_CooldownGaugeWidget_ctor(void *this)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b4a8a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00863f10(this);
  *(undefined4 *)((int)this + 0x4a8) = DAT_00d1e504;
  *(undefined ***)this = &PTR_FUN_00a62454;
  *(undefined4 *)((int)this + 0x4b4) = 0xf;
  *(undefined4 *)((int)this + 0x4ac) = 0;
  *(undefined1 *)((int)this + 0x4b0) = 1;
  *(undefined4 *)((int)this + 0x4b8) = 4;
  ExceptionList = local_c;
  return this;
}
```
