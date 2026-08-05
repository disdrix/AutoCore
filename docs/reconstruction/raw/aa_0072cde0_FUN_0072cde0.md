# Raw capture: FUN_0072cde0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0072cde0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0072cde0` |
| **Canonical name** | `FUN_0072cde0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __thiscall FUN_0072cde0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  char local_18;
  int local_14;
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b1776;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  stoChunkReader_EnterChunkScope(param_2);
  local_4 = 0;
  if (local_14 == 0x42564f4c) {
    if (local_10 == 1) {
      if (*(int *)(param_2 + 0x4044) == 0) {
        FUN_00435fe0(param_1 + 4);
      }
      else {
        FUN_00767fd0(param_1 + 4);
      }
      iVar1 = *(int *)(param_2 + 0x402c);
      local_4 = 0xffffffff;
      if (local_18 != '\0') {
        FUN_00769e40();
      }
      ExceptionList = local_c;
      return (-1 < iVar1) - 1;
    }
    pcVar3 = "Invalid chunk version unserializing phyBoundingVolume";
    uVar2 = 0x52;
  }
  else {
    pcVar3 = "Invalid TAG unserializing phyBoundingVolume";
    uVar2 = 0x44;
  }
  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBoundingVolume.cpp",uVar2,3,
                 pcVar3);
  local_4 = 0xffffffff;
  if (local_18 != '\0') {
    FUN_00769e40();
  }
  ExceptionList = local_c;
  return -1;
}
```
