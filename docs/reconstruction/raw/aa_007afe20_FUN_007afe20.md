# Raw capture: FUN_007afe20

| Field | Value |
|---|---|
| **Stable ID** | `aa_007afe20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007afe20` |
| **Canonical name** | `FUN_007afe20` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_007afe20(int *param_1)

{
  int iVar1;
  
  if ((param_1[0xaa] != 0) && (param_1[0xa6] != 0)) {
    iVar1 = (**(code **)(*param_1 + 0x1a0))();
    if ((iVar1 != 0) && ((char)param_1[0x2e] == '\0')) {
      FUN_007560a0();
      if ((undefined4 *)param_1[0xad] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)param_1[0xad])(param_1[0xa6]);
      }
      *(undefined1 *)(param_1 + 0x2e) = 1;
    }
  }
  return;
}
```
