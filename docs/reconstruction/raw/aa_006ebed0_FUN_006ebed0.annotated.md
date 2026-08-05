# Annotated low-level: FUN_006ebed0

| Field | Value |
|---|---|
| Stable ID | `aa_006ebed0` |
| VA | `0x006ebed0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006ebed0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006ebed0(undefined4 *param_1,undefined4 *param_2,int *param_3,undefined4 param_4)

{
  undefined8 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  char cVar4;
  int *piVar5;
  undefined1 local_3a1;
  code *local_3a0;
  int local_39c;
  undefined4 local_398;
  int *local_394;
  undefined1 local_390 [259];
  undefined1 local_28d;
  int *local_28c;
  int *local_288;
  undefined4 local_284;
  undefined4 local_280;
  undefined4 *local_27c;
  undefined4 *local_278;
  undefined4 *local_274;
  int local_270;
  int *local_26c;
  undefined4 local_264;
  undefined4 *local_260;
  undefined4 *local_258;
  int local_254;
  uint local_250;
  undefined4 local_24c [130];
  int *local_44;
  undefined1 local_40 [36];
  undefined4 local_1c;
  undefined4 *local_18;
  
  FUN_00404d00(DAT_00bc5644 < DAT_00bc5648);
  cVar4 = FUN_00404cf0();
  if (cVar4 != '\0') {
    local_18 = DAT_00bc5644;
    *DAT_00bc5644 = "LtBvTree";
    uVar1 = rdtsc();
    local_1c = (undefined4)uVar1;
    DAT_00bc5644[1] = local_1c;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  FUN_005edf20();
  FUN_006ea340(param_1,param_2,param_3,local_40);
  local_44 = (int *)*param_2;
  local_258 = local_24c;
  local_254 = 0;
  local_250 = 0x80000080;
  (**(code **)(*local_44 + 0x30))(local_40,&local_258);
  FUN_00404d00(DAT_00bc5644 < DAT_00bc5648);
  cVar4 = FUN_00404cf0();
  if (cVar4 != '\0') {
    local_260 = DAT_00bc5644;
    *DAT_00bc5644 = "StNarrowPhase";
    uVar1 = rdtsc();
    local_264 = (undefined4)uVar1;
    DAT_00bc5644[1] = local_264;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  local_26c = (int *)*param_1;
  local_270 = (**(code **)(*local_26c + 0x14))();
  local_274 = local_258;
  local_278 = local_258 + local_254;
  local_27c = param_2;
  local_280 = param_2[2];
  local_28c = (int *)FUN_00428050();
  for (; local_274 != local_278; local_274 = local_274 + 1) {
    (*(code *)**(undefined4 **)param_3[1])(&local_28d,param_3,param_1,param_2,local_28c,*local_274);
    cVar4 = FUN_00404cf0();
    if (cVar4 != '\0') {
      local_394 = (int *)(**(code **)(*local_28c + 0x34))(*local_274,local_390);
      local_398 = *local_274;
      local_288 = local_394;
      local_284 = local_398;
      local_39c = (**(code **)(*local_394 + 0x14))();
      local_3a0 = *(code **)(*param_3 + 0x118c + local_270 * 0x80 + local_39c * 4);
      (*local_3a0)(param_1,&local_288,param_3,param_4);
      FUN_006e7740(&local_3a1);
      cVar4 = FUN_00404cf0();
      if (cVar4 != '\0') break;
    }
  }
  FUN_00404d00(DAT_00bc5644 < DAT_00bc5648);
  cVar4 = FUN_00404cf0();
  uVar3 = local_250;
  puVar2 = local_258;
  if (cVar4 != '\0') {
    *DAT_00bc5644 = &DAT_009d282c;
    uVar1 = rdtsc();
    DAT_00bc5644[1] = (int)uVar1;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  if ((local_250 & 0x80000000) == 0) {
    piVar5 = (int *)FUN_0040ab80();
    (**(code **)(*piVar5 + 0x14))(puVar2,uVar3 << 2,0x12);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
