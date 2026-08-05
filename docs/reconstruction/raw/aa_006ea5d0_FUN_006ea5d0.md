# Raw capture: FUN_006ea5d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006ea5d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006ea5d0` |
| **Canonical name** | `FUN_006ea5d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_006ea5d0(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  
  piVar2 = DAT_00b05060;
  uVar3 = param_1[4] * 0xc + 0xfU & 0xfffffff0;
  if ((uVar3 == 0) || ((param_1[3] != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {
    piVar1 = DAT_00b05060 + 3;
    DAT_00b05060[2] = DAT_00b05060[2] - uVar3;
    piVar2[3] = *piVar1 + uVar3;
  }
  else {
    (**(code **)(*DAT_00b05060 + 0x28))(param_1[3],uVar3);
  }
  if (-1 < (int)param_1[2]) {
    (**(code **)(*DAT_00b05060 + 0x14))(*param_1,(param_1[2] & 0x7fffffff) * 0xc,0x12);
  }
  return;
}
```
