# Annotated low-level: FUN_008ed6d0

| Field | Value |
|---|---|
| Stable ID | `aa_008ed6d0` |
| VA | `0x008ed6d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008ed6d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008ed6d0(undefined4 param_1,uint param_2)

{
  byte bVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  char *pcVar9;
  void *apvStack_534 [4];
  undefined4 uStack_524;
  void *pvStack_520;
  int iStack_51c;
  int iStack_518;
  void *pvStack_514;
  char acStack_510 [4];
  char local_50c [280];
  void *pvStack_3f4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b1043;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar2 = (void *)FUN_00541a80();
  pvVar2 = CNDHash_LookupByKey(pvVar2,param_2);
  iVar5 = 0;
  if (pvVar2 != (void *)0x0) {
    sprintf(local_50c,"%S%s",(int)pvVar2 + 0x1c,&DAT_00a285c4);
    pcVar9 = local_50c;
    FUN_007b6a20(pcVar9);
    puVar3 = (undefined4 *)FUN_007b72b0(pcVar9);
    if (puVar3 != (undefined4 *)0x0) {
      FUN_004ad730();
      local_4 = 0;
      iVar4 = FUN_004a94e0(puVar3);
      if (iVar4 == -1) {
        (**(code **)*puVar3)();
      }
      else {
        (**(code **)*puVar3)(1);
        sprintf(acStack_510,"%S%s",(int)pvVar2 + 0x1c,&DAT_00a395dc);
        pcVar9 = acStack_510;
        FUN_007b6a20(pcVar9);
        iVar4 = FUN_007b7250(pcVar9);
        if (iVar4 != 0) {
          iVar4 = *(int *)(iVar4 + 4);
          if (iVar4 == 0) {
            iVar6 = 0;
            iVar4 = 0;
          }
          else {
            iVar6 = *(int *)(iVar4 + 0x10);
            iVar4 = *(int *)(iVar4 + 0xc);
          }
          pvStack_514 = operator_new__(iVar4 * iVar6);
          apvStack_534[0] = pvStack_514;
          if (0 < iVar6) {
            do {
              iVar7 = 0;
              if (0 < iVar4) {
                pbVar8 = (byte *)(iVar5 + (int)pvStack_514);
                do {
                  bVar1 = FUN_00788fd0(iVar7,iVar5);
                  *pbVar8 = bVar1 >> 3;
                  iVar7 = iVar7 + 1;
                  pbVar8 = pbVar8 + iVar6;
                  pvStack_514 = apvStack_534[0];
                } while (iVar7 < iVar4);
              }
              iVar5 = iVar5 + 1;
            } while (iVar5 < iVar6);
          }
          apvStack_534[0] = pvStack_3f4;
          uStack_524 = param_1;
          pvStack_520 = pvStack_3f4;
          iStack_51c = iVar6;
          iStack_518 = iVar4;
          FUN_0040e0c0(apvStack_534);
        }
      }
      puStack_8 = (undefined1 *)0xffffffff;
      FUN_004ac290();
    }
  }
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
