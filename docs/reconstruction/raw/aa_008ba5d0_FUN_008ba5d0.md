# Raw capture: FUN_008ba5d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ba5d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008ba5d0` |
| **Canonical name** | `FUN_008ba5d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_008ba5d0(int param_1,undefined4 param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  int *piVar5;
  bool bVar6;
  int local_10;
  
  iVar4 = *(int *)(param_1 + 0x5b0);
  if (((-1 < iVar4) && (iVar4 < 0xf)) && (*(int *)(param_1 + 0x568 + iVar4 * 4) != 0)) {
    piVar5 = (int *)(param_1 + 0x54c);
    local_10 = 0;
    do {
      if ((local_10 < 0) || (4 < local_10)) {
        pbVar3 = (byte *)0x0;
      }
      else {
        pbVar3 = *(byte **)(*(int *)(param_1 + 0x568 + *(int *)(param_1 + 0x5b0) * 4) +
                            (-0x48 - param_1) + (int)piVar5);
      }
      if (*piVar5 == 0) {
        pbVar2 = (byte *)0x0;
      }
      else {
        pbVar2 = (byte *)(**(code **)(*(int *)*piVar5 + 0x1dc))();
      }
      if ((pbVar3 == (byte *)0x0) || (pbVar2 == (byte *)0x0)) {
LAB_008ba696:
        FUN_008b9370(*(undefined4 *)(param_1 + 0x5b0));
      }
      else {
        do {
          bVar1 = *pbVar3;
          bVar6 = bVar1 < *pbVar2;
          if (bVar1 != *pbVar2) {
LAB_008ba685:
            iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
            goto LAB_008ba68a;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar3[1];
          bVar6 = bVar1 < pbVar2[1];
          if (bVar1 != pbVar2[1]) goto LAB_008ba685;
          pbVar3 = pbVar3 + 2;
          pbVar2 = pbVar2 + 2;
        } while (bVar1 != 0);
        iVar4 = 0;
LAB_008ba68a:
        if (iVar4 != 0) goto LAB_008ba696;
      }
      local_10 = local_10 + 1;
      piVar5 = piVar5 + 1;
    } while (local_10 < 5);
    pbVar3 = *(byte **)(*(int *)(param_1 + 0x568 + *(int *)(param_1 + 0x5b0) * 4) + 0x518);
    if (*(int *)(param_1 + 0x564) == 0) {
      pbVar2 = (byte *)0x0;
    }
    else {
      pbVar2 = (byte *)(**(code **)(**(int **)(param_1 + 0x564) + 0x1dc))();
    }
    if ((pbVar3 != (byte *)0x0) && (pbVar2 != (byte *)0x0)) {
      do {
        bVar1 = *pbVar3;
        bVar6 = bVar1 < *pbVar2;
        if (bVar1 != *pbVar2) {
LAB_008ba724:
          iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
          goto LAB_008ba729;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar6 = bVar1 < pbVar2[1];
        if (bVar1 != pbVar2[1]) goto LAB_008ba724;
        pbVar3 = pbVar3 + 2;
        pbVar2 = pbVar2 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_008ba729:
      if (iVar4 == 0) goto LAB_008ba745;
    }
    FUN_008b92f0();
  }
LAB_008ba745:
  FUN_00791f30(param_2);
  return;
}
```
