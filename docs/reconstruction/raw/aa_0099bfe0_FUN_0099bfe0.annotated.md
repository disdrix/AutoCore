# Annotated low-level: FUN_0099bfe0

| Field | Value |
|---|---|
| Stable ID | `aa_0099bfe0` |
| VA | `0x0099bfe0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0099bfe0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
bool FUN_0099bfe0(char *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  BOOL BVar4;
  undefined **local_148;
  undefined4 local_144;
  HANDLE local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined ***local_134;
  undefined4 local_130;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  char local_110 [260];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009add85;
  local_c = ExceptionList;
  iVar3 = -(int)param_1;
  do {
    cVar1 = *param_1;
    param_1[(int)(local_110 + iVar3)] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &local_c;
  pcVar2 = strrchr(local_110,0x2e);
  pcVar2[1] = 'c';
  pcVar2[2] = 'a';
  pcVar2[3] = 't';
  local_148 = &PTR_FUN_00a9d84c;
  local_144 = 0;
  local_140 = (HANDLE)0xffffffff;
  local_13c = 0;
  local_138 = 0;
  local_4 = 0;
  iVar3 = FUN_007669d0(local_110,6,0x8000000);
  if (iVar3 == 0) {
    local_134 = &local_148;
    local_130 = 0;
    local_128 = 0;
    local_124 = 0;
    local_120 = 0;
    local_11c = 0;
    local_4._0_1_ = 1;
    local_118 = 0;
    local_114 = 0;
    FUN_007670a0();
    local_4._0_1_ = 2;
    FUN_00744820();
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_005b2ba0();
  }
  cVar1 = (*(code *)local_148[8])();
  if (cVar1 != '\0') {
    BVar4 = CloseHandle(local_140);
    if (BVar4 == 0) goto LAB_0099c0ff;
  }
  local_140 = (HANDLE)0xffffffff;
LAB_0099c0ff:
  local_4 = 0xffffffff;
  FUN_00766750();
  ExceptionList = local_c;
  return iVar3 == 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
