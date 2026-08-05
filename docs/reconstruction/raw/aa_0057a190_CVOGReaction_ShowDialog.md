# Raw capture: CVOGReaction_ShowDialog

| Field | Value |
|---|---|
| **Stable ID** | `aa_0057a190` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0057a190` |
| **Canonical name** | `CVOGReaction_ShowDialog` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall CVOGReaction_ShowDialog(int param_1,int param_2)

{
  undefined4 *puVar1;
  char *pcVar2;
  undefined4 *puVar3;
  
  if (param_2 != 0) {
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_2 + 0x160);
    *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_2 + 0x164);
    puVar1 = *(undefined4 **)(param_1 + 0x10);
    puVar3 = *(undefined4 **)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_2 + 0x168);
    *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_2 + 0x16c);
    for (; puVar3 != puVar1; puVar3 = puVar3 + 1) {
      pcVar2 = (char *)*puVar3;
      if (*pcVar2 == '\0') {
        CVOGMap_LookupVariable(*(undefined4 *)(pcVar2 + 4),pcVar2 + 8,param_2);
      }
    }
  }
  return;
}
```
