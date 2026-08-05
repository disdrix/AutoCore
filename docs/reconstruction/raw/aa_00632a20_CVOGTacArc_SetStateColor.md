# Raw capture: CVOGTacArc_SetStateColor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00632a20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00632a20` |
| **Canonical name** | `CVOGTacArc_SetStateColor` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall CVOGTacArc_SetStateColor(int param_1,int param_2)

{
  undefined1 local_10 [16];
  
  *(int *)(param_1 + 0x24) = param_2;
  *(undefined1 *)(param_1 + 0x33) = 0x66;
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 0x32) = 0x1d;
    *(undefined1 *)(param_1 + 0x31) = 0x50;
    *(undefined1 *)(param_1 + 0x30) = 0xff;
    *(undefined1 *)(param_1 + 0x36) = 8;
    *(undefined1 *)(param_1 + 0x35) = 0x14;
    *(undefined1 *)(param_1 + 0x34) = 0x3d;
    *(undefined1 *)(param_1 + 0x37) = 0x53;
  }
  else if (param_2 == 1) {
    *(undefined1 *)(param_1 + 0x32) = 0x6b;
    *(undefined1 *)(param_1 + 0x31) = 0xff;
    *(undefined1 *)(param_1 + 0x30) = 0x40;
    *(undefined1 *)(param_1 + 0x36) = 0x14;
    *(undefined1 *)(param_1 + 0x35) = 0x33;
    *(undefined1 *)(param_1 + 0x34) = 0xc;
    *(undefined1 *)(param_1 + 0x37) = 0x4b;
  }
  else if (param_2 == 2) {
    *(undefined1 *)(param_1 + 0x32) = 0xfb;
    *(undefined1 *)(param_1 + 0x31) = 0x7d;
    *(undefined1 *)(param_1 + 0x30) = 10;
    *(undefined1 *)(param_1 + 0x36) = 0x33;
    *(undefined1 *)(param_1 + 0x35) = 0x17;
    *(undefined1 *)(param_1 + 0x34) = 2;
    *(undefined1 *)(param_1 + 0x37) = 0x4e;
  }
  else {
    *(undefined1 *)(param_1 + 0x32) = 0;
    *(undefined1 *)(param_1 + 0x31) = 0x33;
    *(undefined1 *)(param_1 + 0x30) = 0xff;
    *(undefined1 *)(param_1 + 0x36) = 0xd;
    *(undefined1 *)(param_1 + 0x35) = 0;
    *(undefined1 *)(param_1 + 0x34) = 0x33;
    *(undefined1 *)(param_1 + 0x37) = 0x5a;
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    FUN_009733d0(param_1 + 0x34);
    FUN_009700f0("MatZFailColor",local_10);
  }
  return;
}
```
