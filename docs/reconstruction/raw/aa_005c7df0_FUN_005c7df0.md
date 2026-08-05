# Raw capture: FUN_005c7df0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c7df0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005c7df0` |
| **Canonical name** | `FUN_005c7df0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_005c7df0(int param_1,float *param_2,undefined4 param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a6e88;
  local_c = ExceptionList;
  iVar2 = *(int *)(param_1 + 0x10);
  ExceptionList = &local_c;
  if ((iVar2 == 0) && (ExceptionList = &local_c, iVar2 = FUN_004baf50(param_1 + 0x18), iVar2 == 0))
  {
    ExceptionList = local_c;
    return 1;
  }
  if ((DAT_00bc5558 & 1) == 0) {
    DAT_00bc5558 = DAT_00bc5558 | 1;
    local_4 = 0;
    FUN_0076c500(10000);
    local_4 = 0xffffffff;
  }
  uStack_10 = 0;
  FUN_0076c4d0();
  while( true ) {
    iVar3 = FUN_005c7cd0(iVar2,param_3);
    iVar4 = FUN_0076c3c0();
    fVar1 = (float)iVar4;
    if (iVar4 < 0) {
      fVar1 = fVar1 + _DAT_00aaa5dc;
    }
    fVar1 = fVar1 * DAT_00aaa664;
    if (iVar3 == 2) break;
    if ((iVar3 == 3) || (*param_2 <= fVar1)) goto LAB_005c7ed9;
  }
  uStack_10 = 0x1000000;
  *(undefined1 *)(param_1 + 0x53) = 1;
LAB_005c7ed9:
  *param_2 = *param_2 - fVar1;
  ExceptionList = local_c;
  return uStack_10 >> 0x18;
}
```
