# Raw capture: FUN_0073bea0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073bea0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0073bea0` |
| **Canonical name** | `FUN_0073bea0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __thiscall FUN_0073bea0(int *param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  
  iVar4 = 0;
  if (0 < *param_1) {
    pbVar6 = (byte *)(param_1 + 2);
    do {
      pbVar2 = pbVar6;
      pbVar5 = param_2;
      if (0xf < *(uint *)(pbVar6 + 0x14)) {
        pbVar2 = *(byte **)pbVar6;
      }
      do {
        bVar1 = *pbVar2;
        bVar7 = bVar1 < *pbVar5;
        if (bVar1 != *pbVar5) {
LAB_0073bee4:
          iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_0073bee9;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar2[1];
        bVar7 = bVar1 < pbVar5[1];
        if (bVar1 != pbVar5[1]) goto LAB_0073bee4;
        pbVar2 = pbVar2 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_0073bee9:
      if (iVar3 == 0) {
        return iVar4;
      }
      iVar4 = iVar4 + 1;
      pbVar6 = pbVar6 + 0x2c;
    } while (iVar4 < *param_1);
  }
  return -1;
}
```
