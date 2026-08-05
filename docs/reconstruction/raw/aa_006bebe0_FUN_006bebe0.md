# Raw capture: FUN_006bebe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006bebe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006bebe0` |
| **Canonical name** | `FUN_006bebe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006bebe0(undefined4 param_1,int *param_2,undefined4 param_3,ushort param_4,int param_5,
                 undefined4 param_6,undefined4 param_7,int *param_8)

{
  int iVar1;
  ushort *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ushort *puVar8;
  float10 fVar9;
  float local_10;
  
  if (param_2[2] != 1) {
    iVar4 = param_2[1];
    iVar5 = *param_2;
    puVar2 = (ushort *)(iVar4 + (uint)*(ushort *)(param_5 + 2) * 8);
    puVar8 = puVar2;
    do {
      if (*puVar8 == param_4) {
        local_10 = 4.0;
      }
      else {
        fVar9 = (float10)FUN_006bbe80(param_1,(uint)*puVar8 * 0x10 + iVar5,param_3,param_6,param_7);
        local_10 = (float)fVar9;
      }
      iVar6 = param_8[1];
      iVar1 = iVar6 + 1;
      if ((int)(param_8[2] & 0x7fffffffU) < iVar1) {
        iVar7 = (param_8[2] & 0x7fffffffU) * 2;
        if (iVar7 <= iVar1) {
          iVar7 = iVar1;
        }
        FUN_005b3300(param_8,iVar7,8);
      }
      puVar3 = (undefined4 *)(*param_8 + iVar6 * 8);
      param_8[1] = iVar1;
      *puVar3 = puVar8;
      puVar3[1] = local_10;
      puVar8 = (ushort *)(iVar4 + (uint)*(ushort *)(iVar4 + 2 + (uint)puVar8[2] * 8) * 8);
    } while (puVar8 != puVar2);
    if (1 < param_8[1]) {
      FUN_006bafb0(*param_8,0,param_8[1] + -1,&LAB_006bac90);
    }
    FUN_006be360(param_1,param_2,param_3,param_5,param_6,param_7,param_8);
  }
  return;
}
```
