# Annotated low-level: FUN_0098dbb0

| Field | Value |
|---|---|
| Stable ID | `aa_0098dbb0` |
| VA | `0x0098dbb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0098dbb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __thiscall FUN_0098dbb0(int param_1,int param_2)

{
  float *pfVar1;
  int iVar2;
  char local_18;
  int local_14;
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b1788;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  stoChunkReader_EnterChunkScope(param_2);
  local_4 = 0;
  if (local_14 != 0x42564350) {
    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBVCapsule.cpp",0x3c,3,
                   "Invalid TAG unserializing phyBVCapsule");
    local_4 = 0xffffffff;
    if (local_18 != '\0') {
      FUN_00769e40();
    }
    ExceptionList = local_c;
    return -1;
  }
  iVar2 = FUN_0072cde0(param_2);
  if (iVar2 != 0) {
    local_4 = 0xffffffff;
    if (local_18 != '\0') {
      FUN_00769e40();
    }
    ExceptionList = local_c;
    return iVar2;
  }
  if (local_10 != 1) {
    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBVCapsule.cpp",0x55,3,
                   "Invalid chunk version unserializing phyBVCapsule");
    local_4 = 0xffffffff;
    if (local_18 != '\0') {
      FUN_00769e40();
    }
    ExceptionList = local_c;
    return -1;
  }
  stoChunkReader_readF32Array(param_2);
  stoChunkReader_readF32Array(param_2);
  pfVar1 = (float *)(param_1 + 0x20);
  if (*(int *)(param_2 + 0x4044) == 0) {
    FUN_00435fe0(pfVar1);
  }
  else {
    FUN_00767fd0(pfVar1);
  }
  *(float *)(param_1 + 0x24) =
       SQRT(*(float *)(param_1 + 0x14) * *(float *)(param_1 + 0x14) +
            *(float *)(param_1 + 0x18) * *(float *)(param_1 + 0x18) +
            *(float *)(param_1 + 0x1c) * *(float *)(param_1 + 0x1c)) + *pfVar1;
  iVar2 = *(int *)(param_2 + 0x402c);
  local_4 = 0xffffffff;
  if (local_18 != '\0') {
    FUN_00769e40();
  }
  ExceptionList = local_c;
  return iVar2;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
