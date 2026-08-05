# Raw capture: Client_ActionMap_Init

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f9110` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007f9110` |
| **Canonical name** | `Client_ActionMap_Init` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* ActionMap ctor/init: zero tables, Client_InitActionDisplayNames, Client_InitDefaultKeybinds. Slot
   stride 0x34. Called from FUN_009495c0. */

void Client_ActionMap_Init(void)

{
  int iVar1;
  undefined4 *unaff_ESI;
  undefined4 *puVar2;
  
  *unaff_ESI = &PTR_LAB_00a84e08;
  puVar2 = (undefined4 *)((int)unaff_ESI + 6);
  for (iVar1 = 0x41; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)unaff_ESI + 0x10a);
  for (iVar1 = 0x4e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)unaff_ESI + 0x242);
  for (iVar1 = 0x618; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)unaff_ESI + 0x1aa2);
  for (iVar1 = 0x104; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  Client_InitActionDisplayNames();
  Client_InitDefaultKeybinds();
  *(undefined1 *)((int)unaff_ESI + 5) = 0;
  return;
}
```
