# Annotated low-level: FUN_0072cde0

| Field | Value |
|---|---|
| Stable ID | `aa_0072cde0` |
| VA | `0x0072cde0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0072cde0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

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

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
