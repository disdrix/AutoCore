# Raw capture: FUN_006bbc60

| Field | Value |
|---|---|
| **Stable ID** | `aa_006bbc60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006bbc60` |
| **Canonical name** | `FUN_006bbc60` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006bbc60(int *param_1,int param_2,int *param_3,float *param_4)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  int local_40;
  
  iVar2 = *param_1;
  *param_3 = param_1[1];
  param_3[1] = *(int *)(param_2 + 4);
  param_3[2] = 0;
  param_3[4] = 0;
  param_3[3] = -1;
  pfVar7 = (float *)((uint)*(ushort *)param_3[1] * 0x10 + iVar2);
  pfVar8 = (float *)((uint)*(ushort *)*param_3 * 0x10 + iVar2);
  FUN_006bba50(pfVar8,pfVar7,param_4);
  iVar5 = (param_1[2] + *(int *)(param_2 + 8)) * 2;
  local_40 = 0;
  if (0 < iVar5) {
    do {
      iVar3 = param_1[2];
      bVar4 = false;
      while (iVar3 = iVar3 + -1, -1 < iVar3) {
        pfVar6 = (float *)((uint)*(ushort *)(param_1[1] + iVar3 * 8) * 0x10 + iVar2);
        if (_DAT_00a0d15c <
            param_4[2] * (pfVar6[2] - pfVar8[2]) +
            param_4[1] * (pfVar6[1] - pfVar8[1]) + *param_4 * (*pfVar6 - *pfVar8)) {
          *param_3 = param_1[1] + iVar3 * 8;
          FUN_006bba50(pfVar6,pfVar7,param_4);
          bVar4 = true;
          pfVar8 = pfVar6;
        }
      }
      iVar3 = *(int *)(param_2 + 8);
      while (iVar3 = iVar3 + -1, -1 < iVar3) {
        puVar1 = (ushort *)(*(int *)(param_2 + 4) + iVar3 * 8);
        pfVar6 = (float *)((uint)*puVar1 * 0x10 + iVar2);
        if (_DAT_00a0d15c <
            param_4[2] * (pfVar6[2] - pfVar7[2]) +
            param_4[1] * (pfVar6[1] - pfVar7[1]) + *param_4 * (*pfVar6 - *pfVar7)) {
          param_3[1] = (int)puVar1;
          FUN_006bba50(pfVar8,pfVar6,param_4);
          bVar4 = true;
          pfVar7 = pfVar6;
        }
      }
      if (!bVar4) {
        return;
      }
      FUN_006bba50(pfVar8,pfVar7,param_4);
      local_40 = local_40 + 1;
    } while (local_40 < iVar5);
  }
  return;
}
```
