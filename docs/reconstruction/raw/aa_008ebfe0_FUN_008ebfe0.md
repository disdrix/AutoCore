# Raw capture: FUN_008ebfe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ebfe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008ebfe0` |
| **Canonical name** | `FUN_008ebfe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008ebfe0(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *unaff_ESI;
  int iStack_58;
  undefined1 *puStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined1 *puStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined1 *puStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  undefined1 local_20 [32];
  
  if ((unaff_ESI != (int *)0x0) && (*(int *)(in_EAX + 0x568) != 0)) {
    uStack_34 = 0;
    uStack_38 = 1;
    puStack_3c = local_20;
    uStack_40 = 0x8ec00f;
    iVar1 = (**(code **)(**(int **)(in_EAX + 0x568) + 0x120))();
    uStack_40 = 0;
    uStack_44 = 1;
    puStack_48 = auStack_24;
    uStack_4c = 0x8ec024;
    iVar2 = (**(code **)(*unaff_ESI + 0x120))();
    iVar1 = *(int *)(iVar1 + 4);
    iVar2 = *(int *)(iVar2 + 4);
    uStack_4c = 0;
    uStack_50 = 1;
    puStack_54 = auStack_28;
    iStack_58 = 0x8ec041;
    piVar3 = (int *)(**(code **)(**(int **)(in_EAX + 0x568) + 0x120))();
    iStack_58 = 0;
    piVar4 = (int *)(**(code **)(*unaff_ESI + 0x120))(&stack0xffffffd4,1);
    iStack_58 = *piVar4 + *piVar3;
    puStack_54 = (undefined1 *)(iVar1 + iVar2);
    (**(code **)(*unaff_ESI + 0x110))(&iStack_58);
  }
  return;
}
```
