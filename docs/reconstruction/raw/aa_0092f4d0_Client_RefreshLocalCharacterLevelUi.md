# Raw capture: Client_RefreshLocalCharacterLevelUi

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092f4d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0092f4d0` |
| **Canonical name** | `Client_RefreshLocalCharacterLevelUi` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Client_RefreshLocalCharacterLevelUi — after CharacterLevel applies to local player,
   refresh level/rank UI fields from character clonebase (not money itself).
   Called from Client_RecvCharacterLevel when packet TFID matches local character. */

void Client_RefreshLocalCharacterLevelUi(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0xe98);
  if (iVar1 != 0) {
    *(uint *)(unaff_ESI + 0xeec) =
         (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xac + iVar1) + 0x3c)
                        + 0x531);
    uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x27c))();
    *(undefined4 *)(unaff_ESI + 0xee4) = uVar2;
    *(uint *)(unaff_ESI + 0xee8) =
         (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0xe98) + 4) + 4) +
                                           0xac + *(int *)(unaff_ESI + 0xe98)) + 0x3c) + 0x532);
  }
  return;
}
```
