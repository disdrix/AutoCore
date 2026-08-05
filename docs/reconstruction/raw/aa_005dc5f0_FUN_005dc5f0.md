# Raw capture: FUN_005dc5f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005dc5f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005dc5f0` |
| **Canonical name** | `FUN_005dc5f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005dc5f0(int param_1,char param_2)

{
  CVOGHBBase *this;
  
  if (param_2 != *(char *)(param_1 + 0x160)) {
    this = *(CVOGHBBase **)(param_1 + 0xd8);
    *(char *)(param_1 + 0x160) = param_2;
    if (param_2 == '\0') {
      if (this != (CVOGHBBase *)0x0) {
        FUN_005081d0();
        return;
      }
    }
    else {
      if (this != (CVOGHBBase *)0x0) {
        CVOGHBBase_Start(this);
      }
      if (*(char *)(param_1 + 0x18b) != '\0') {
        FUN_005de1b0(0,0,0,0,0);
      }
    }
  }
  return;
}
```
