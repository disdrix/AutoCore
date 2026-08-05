# Raw capture: FUN_004fbf40

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fbf40` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004fbf40` |
| **Canonical name** | `FUN_004fbf40` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004fbf40(int param_1,undefined4 param_2,byte param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 local_118 [2];
  byte local_110;
  byte local_10f;
  
  if ((byte)param_2 < 8) {
    FUN_00512670();
    if (param_3 == 0xffffffff) {
      FUN_004f8ce0(param_2,0xffffffff);
      return;
    }
    iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c);
    bVar1 = *(byte *)(iVar2 + 0x716);
    uVar5 = 0;
    if (bVar1 != 0) {
      iVar2 = *(int *)(iVar2 + 0x720);
      while( true ) {
        puVar6 = (undefined4 *)(uVar5 * 0x110 + iVar2);
        puVar7 = local_118;
        for (iVar3 = 0x44; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
        if (((local_10f == param_3) && (local_110 == (byte)param_2)) && (local_10f < 0x24)) break;
        bVar4 = (char)uVar5 + 1;
        uVar5 = (uint)bVar4;
        if (bVar1 <= bVar4) {
          return;
        }
      }
      FUN_004f8ce0(param_2,local_118[0]);
    }
  }
  return;
}
```
