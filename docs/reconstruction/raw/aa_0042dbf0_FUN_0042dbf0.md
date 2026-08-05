# Raw capture: FUN_0042dbf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042dbf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0042dbf0` |
| **Canonical name** | `FUN_0042dbf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0042dbf0(undefined4 param_1)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  
  cVar1 = FUN_00974620(in_EAX + 0x14c,in_EAX + 0x138,in_EAX + 0x140,*(undefined4 *)(in_EAX + 0x148))
  ;
  if (cVar1 != '\0') {
    iVar2 = FUN_007833a0();
    FUN_00783aa0("Client puzzle solved in %d ms.",iVar2 - *(int *)(in_EAX + 0x1a4));
    *(undefined4 *)(in_EAX + 0x1b8) = 4;
    FUN_0042dc60(param_1);
  }
  return;
}
```
