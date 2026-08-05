# Raw capture: FUN_006bed00

| Field | Value |
|---|---|
| **Stable ID** | `aa_006bed00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006bed00` |
| **Canonical name** | `FUN_006bed00` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006bed00(int param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint extraout_ECX;
  int *piVar5;
  int *piVar6;
  int local_14;
  int local_10;
  char local_8 [4];
  char local_4 [4];
  
  local_10 = 0;
  if (0 < param_3[1]) {
    local_14 = 0;
    do {
      param_4[1] = 0;
      piVar5 = (int *)(*param_3 + local_14);
      if ((param_4[2] & 0x7fffffffU) == 0) {
        FUN_005b3300(param_4,1,0x10);
      }
      piVar2 = (int *)*param_4;
      param_4[1] = 1;
      *piVar2 = *piVar5;
      piVar2[1] = piVar5[1];
      for (piVar2 = (int *)piVar5[2]; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[2]) {
        if (((*piVar2 == *piVar5) && (piVar2[1] == piVar5[1])) && (piVar2[3] == piVar5[3])) {
          FUN_006be870(local_8,param_1,*(undefined4 *)(param_2 + 4),
                       CONCAT31((int3)((uint)piVar2[1] >> 8),1),param_4);
          FUN_006be870(local_4,param_2,*(undefined4 *)(param_1 + 4),extraout_ECX & 0xffffff00,
                       param_4);
          if ((local_8[0] != '\0') && (local_4[0] != '\0')) {
            return;
          }
        }
        iVar3 = param_4[1];
        iVar1 = iVar3 + 1;
        if ((int)(param_4[2] & 0x7fffffffU) < iVar1) {
          iVar4 = (param_4[2] & 0x7fffffffU) * 2;
          if (iVar4 <= iVar1) {
            iVar4 = iVar1;
          }
          FUN_005b3300(param_4,iVar4,0x10);
        }
        param_4[1] = iVar1;
        piVar6 = (int *)(iVar3 * 0x10 + *param_4);
        *piVar6 = *piVar2;
        piVar6[1] = piVar2[1];
      }
      local_10 = local_10 + 1;
      local_14 = local_14 + 0x14;
    } while (local_10 < param_3[1]);
  }
  param_4[1] = 0;
  return;
}
```
