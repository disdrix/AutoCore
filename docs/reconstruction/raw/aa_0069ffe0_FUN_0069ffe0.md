# Raw capture: FUN_0069ffe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0069ffe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0069ffe0` |
| **Canonical name** | `FUN_0069ffe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_0069ffe0(int param_1)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  fVar3 = (float10)g_flZero;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009ab02e;
  local_c = ExceptionList;
  if ((*(int *)(param_1 + 0x40) != 0) &&
     ((*(int *)(param_1 + 0x44) - *(int *)(param_1 + 0x40)) / 0x18 == 500)) {
    ExceptionList = &local_c;
    iVar2 = FUN_006a3db0();
    fVar1 = *(float *)(*(int *)(param_1 + 0x40) + iVar2 * 0x18 + 4);
    if ((_DAT_00d08f88 & 1) == 0) {
      _DAT_00d08f88 = _DAT_00d08f88 | 1;
      local_4 = 0;
      FUN_006a1cd0();
      _atexit((_func_4879 *)&LAB_009c5580);
      local_4 = 0xffffffff;
    }
    fVar1 = fVar1 * *(float *)(param_1 + 8);
    fVar3 = (float10)FUN_006a1be0(-fVar1,fVar1);
  }
  ExceptionList = local_c;
  return fVar3;
}
```
