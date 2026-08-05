# Raw capture: FUN_008ef9f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ef9f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008ef9f0` |
| **Canonical name** | `FUN_008ef9f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_008ef9f0(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  
  iVar2 = FUN_0040e490(param_1 + 0x16c);
  while (iVar2 != 0) {
    (**(code **)(*param_1 + 0xbc))(iVar2);
    iVar2 = FUN_0040e490(param_1 + 0x16c);
  }
  if (DAT_00d1b6d8 != 0) {
    iVar2 = *(int *)(DAT_00d1b6d8 + 0x534);
    iVar5 = 0;
    if (*(char *)(iVar2 + 0x1d) != '\0') {
      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");
      FUN_007a4480(0,"VOG_DEBUG_STOP");
    }
    *(undefined1 *)(iVar2 + 0x1d) = 1;
LAB_008efa60:
    iVar2 = *(int *)(DAT_00d1b6d8 + 0x534);
    if (*(char *)(iVar2 + 0x1d) == '\0') {
      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0,"VOG_DEBUG_STOP");
    }
    if (iVar5 == 0) {
      iVar5 = *(int *)(iVar2 + 0x14);
      if (iVar5 == 0) goto LAB_008efaa8;
      puVar3 = *(uint **)(iVar5 + 8);
    }
    else {
      iVar5 = *(int *)(iVar5 + 0x14);
      if (iVar5 == 0) {
LAB_008efaa8:
        puVar3 = (uint *)0x0;
      }
      else {
        puVar3 = *(uint **)(iVar5 + 8);
      }
    }
    if (puVar3 != (uint *)0x0) {
      uVar1 = *puVar3;
      iVar2 = FUN_00541a80();
      uVar4 = *(uint *)(iVar2 + 8) & uVar1;
      iVar2 = *(int *)(*(int *)(*(int *)(iVar2 + 0x10) + uVar4 * 4) + 4);
      if (iVar2 == 0) {
LAB_008efae2:
        iVar2 = 0;
      }
      else {
        do {
          if (uVar1 == *(uint *)(iVar2 + 0x10)) {
            if (iVar2 == 0) goto LAB_008efae2;
            iVar2 = *(int *)(iVar2 + 8);
            goto LAB_008efae9;
          }
          iVar2 = *(int *)(iVar2 + 0xc);
        } while (iVar2 != 0);
        iVar2 = 0;
      }
LAB_008efae9:
      if (iVar2 != 0) {
        FUN_008ef7d0(param_1,CONCAT31((int3)(uVar4 >> 8),(char)puVar3[1]));
      }
      goto LAB_008efa60;
    }
    *(undefined1 *)(*(int *)(DAT_00d1b6d8 + 0x534) + 0x1d) = 0;
  }
  return;
}
```
