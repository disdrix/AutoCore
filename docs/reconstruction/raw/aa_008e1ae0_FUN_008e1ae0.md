# Raw capture: FUN_008e1ae0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e1ae0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008e1ae0` |
| **Canonical name** | `FUN_008e1ae0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008e1ae0(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_EBX;
  int unaff_ESI;
  undefined4 *puVar3;
  undefined1 local_108 [2];
  undefined4 uStack_106;
  char cStack_102;
  char cStack_101;
  char local_100 [252];
  
  if ((*(int *)(unaff_EBX + 0x564 + unaff_ESI * 4) != 0) && (DAT_00d1b6d8 != 0)) {
    _local_108 = _local_108 & 0xffff0000;
    puVar3 = (undefined4 *)(local_108 + 2);
    for (iVar2 = 0x3f; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    *(undefined2 *)puVar3 = 0;
    iVar2 = FUN_0052ad60(*(undefined4 *)(unaff_EBX + 0x5e4 + unaff_ESI * 4));
    uVar1 = FUN_0052ada0(*(undefined4 *)(unaff_EBX + 0x5e4 + unaff_ESI * 4));
    if (0 < iVar2) {
      sprintf(local_108,"%i/%i",uVar1,iVar2);
      (**(code **)(**(int **)(unaff_EBX + 0x564 + unaff_ESI * 4) + 0x34c))();
      return;
    }
    uStack_106._2_1_ = s_UNLEARNED_00a3be84[4];
    uStack_106._3_1_ = s_UNLEARNED_00a3be84[5];
    cStack_102 = s_UNLEARNED_00a3be84[6];
    cStack_101 = s_UNLEARNED_00a3be84[7];
    local_108[0] = s_UNLEARNED_00a3be84[0];
    local_108[1] = s_UNLEARNED_00a3be84[1];
    uStack_106._0_1_ = s_UNLEARNED_00a3be84[2];
    uStack_106._1_1_ = s_UNLEARNED_00a3be84[3];
    local_100[0] = s_UNLEARNED_00a3be84[8];
    local_100[1] = s_UNLEARNED_00a3be84[9];
    (**(code **)(**(int **)(unaff_EBX + 0x564 + unaff_ESI * 4) + 0x34c))();
  }
  return;
}
```
