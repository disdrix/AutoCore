# Raw capture: FUN_004fca70

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fca70` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004fca70` |
| **Canonical name** | `FUN_004fca70` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004fca70(int param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  FUN_00512670();
  cVar2 = '\0';
  do {
    if (*(int *)(*(int *)(param_1 + 0x260) + cVar2 * 4) != 0) {
      iVar1 = *(int *)(cVar2 * 4 + *(int *)(param_1 + 0x260));
      iVar3 = *(int *)(*(int *)(iVar1 + 4) + 4);
      if ((*(int *)(iVar3 + 0x164 + iVar1) == param_2) &&
         (*(int *)(iVar3 + 0x168 + iVar1) == param_3)) {
        iVar3 = (int)cVar2;
        iVar1 = *(int *)(*(int *)(param_1 + 0x260) + iVar3 * 4);
        *param_4 = iVar1;
        if (iVar1 != 0) {
          iVar1 = *(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1;
        }
        FUN_004fbb50(iVar1);
        if (*(int *)(*(int *)(param_1 + 0x260) + iVar3 * 4) != 0) {
          iVar1 = *(int *)(*(int *)(param_1 + 0x260) + iVar3 * 4);
          (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x158))
                    (*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1);
        }
        *(undefined4 *)(*(int *)(param_1 + 0x260) + iVar3 * 4) = 0;
        *(undefined4 *)(param_1 + 0x630 + iVar3 * 8) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x634 + iVar3 * 8) = 0xffffffff;
        return;
      }
    }
    cVar2 = cVar2 + '\x01';
    if ('\x02' < cVar2) {
      return;
    }
  } while( true );
}
```
