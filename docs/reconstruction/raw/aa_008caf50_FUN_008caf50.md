# Raw capture: FUN_008caf50

| Field | Value |
|---|---|
| **Stable ID** | `aa_008caf50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008caf50` |
| **Canonical name** | `FUN_008caf50` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008caf50(void)

{
  int in_EAX;
  undefined1 *puVar1;
  int iVar2;
  
  *(undefined4 *)(in_EAX + 0x558) = 0;
  puVar1 = (undefined1 *)(in_EAX + 0x574);
  iVar2 = 0x10;
  do {
    *(undefined4 *)(puVar1 + -0x10) = 0xffffffff;
    *puVar1 = 0;
    *(undefined2 *)(puVar1 + -8) = 0;
    puVar1 = puVar1 + 0x3c;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}
```
