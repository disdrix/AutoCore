# Raw capture: FUN_006cb4b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006cb4b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006cb4b0` |
| **Canonical name** | `FUN_006cb4b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006cb4b0(int param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (*(char *)(param_1 + 0x4d8c) != '\0') {
    FUN_006cafd0();
    uVar2 = *(undefined1 *)(param_1 + 0x4d8d);
    iVar6 = 0;
    if (0 < *(int *)(param_1 + 0x4da0)) {
      iVar5 = 0;
      do {
        puVar3 = (undefined4 *)(*(int *)(param_1 + 0x4d9c) + iVar5);
        *(undefined1 *)(param_1 + 0x4d8d) = *(undefined1 *)(*(int *)(param_1 + 0x4d9c) + 8 + iVar5);
        FUN_006cb390(puVar3 + 3,*puVar3,puVar3[1]);
        iVar6 = iVar6 + 1;
        iVar5 = iVar5 + 0x1c;
      } while (iVar6 < *(int *)(param_1 + 0x4da0));
    }
    *(undefined1 *)(param_1 + 0x4d8d) = uVar2;
  }
  iVar6 = 0;
  if (0 < *(int *)(param_1 + 0x4d94)) {
    do {
      if ((*(int *)(*(int *)(param_1 + 0x4d90) + iVar6 * 8) == param_2) &&
         (*(int *)(*(int *)(param_1 + 0x4d90) + iVar6 * 8 + 4) == param_3)) {
        iVar4 = *(int *)(param_1 + 0x4d94) + -1;
        *(int *)(param_1 + 0x4d94) = iVar4;
        iVar5 = iVar6;
        if (iVar6 < iVar4) {
          do {
            puVar3 = (undefined4 *)(*(int *)(param_1 + 0x4d90) + iVar5 * 8);
            *puVar3 = *(undefined4 *)(*(int *)(param_1 + 0x4d90) + 8 + iVar5 * 8);
            puVar3[1] = puVar3[3];
            iVar5 = iVar5 + 1;
          } while (iVar5 < *(int *)(param_1 + 0x4d94));
        }
        iVar6 = iVar6 + -1;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(param_1 + 0x4d94));
  }
  FUN_006cb320(param_2,param_3,0);
  if (*(uint *)(param_1 + 0x4d94) == (*(uint *)(param_1 + 0x4d98) & 0x7fffffff)) {
    FUN_005b3370((int *)(param_1 + 0x4d90),8);
  }
  piVar1 = (int *)(*(int *)(param_1 + 0x4d90) + *(int *)(param_1 + 0x4d94) * 8);
  *(int *)(param_1 + 0x4d94) = *(int *)(param_1 + 0x4d94) + 1;
  *piVar1 = param_2;
  piVar1[1] = param_3;
  return;
}
```
