# Raw capture: FUN_006bdc70

| Field | Value |
|---|---|
| **Stable ID** | `aa_006bdc70` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006bdc70` |
| **Canonical name** | `FUN_006bdc70` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006bdc70(int param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int local_10;
  
  iVar5 = *(int *)(param_1 + 4);
  local_10 = 0;
  if (0 < *(int *)(param_1 + 8)) {
    do {
      uVar6 = *(uint *)(*(int *)(param_1 + 4) + local_10 * 8);
      uVar8 = (uint)*(ushort *)(*(int *)(param_1 + 4) + 4 + local_10 * 8);
      if ((local_10 < (int)uVar8) &&
         (uVar10 = (uint)*(ushort *)(iVar5 + 4 + uVar8 * 8), local_10 < (int)uVar10)) {
        uVar3 = *(ushort *)(iVar5 + uVar8 * 8);
        uVar4 = *(ushort *)(iVar5 + uVar10 * 8);
        iVar7 = *(int *)(param_2 + 0x10);
        iVar1 = iVar7 + 1;
        uVar8 = *(uint *)(param_2 + 0x14) & 0x7fffffff;
        if ((int)uVar8 < iVar1) {
          iVar9 = uVar8 * 2;
          if (iVar9 <= iVar1) {
            iVar9 = iVar1;
          }
          FUN_005b3300((int *)(param_2 + 0xc),iVar9,0xc);
        }
        puVar2 = (uint *)(*(int *)(param_2 + 0xc) + iVar7 * 0xc);
        *(int *)(param_2 + 0x10) = iVar1;
        *puVar2 = uVar6 & 0xffff;
        puVar2[1] = (uint)uVar4;
        puVar2[2] = (uint)uVar3;
      }
      local_10 = local_10 + 1;
    } while (local_10 < *(int *)(param_1 + 8));
  }
  return;
}
```
