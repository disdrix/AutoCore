# Annotated low-level: FUN_004ec7b0

| Field | Value |
|---|---|
| Stable ID | `aa_004ec7b0` |
| VA | `0x004ec7b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004ec7b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004ec7b0(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined1 local_118 [4];
  undefined4 local_114;
  char local_110 [260];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a2816;
  local_c = ExceptionList;
  local_114 = DAT_00d1f040;
  ExceptionList = &local_c;
  FUN_0076cf00("CollectAllPhysicsPreloads");
  iVar2 = *(int *)(param_1 + 0x3c);
  local_4 = 0;
  if (iVar2 != 0) {
    iVar2 = iVar2 + 0x40a;
  }
  _snprintf(local_110,0x104,"%S%s",iVar2,&DAT_009cb318);
  pcVar3 = local_110;
  uVar4 = 0xffffffff;
  FUN_007b6a20(pcVar3,0xffffffff);
  cVar1 = FUN_007b6730(pcVar3,uVar4);
  if (cVar1 != '\0') {
    FUN_00989e00(local_118,local_110);
    FUN_0043d670(local_118);
  }
  FUN_004eb3b0();
  if (*(int *)(param_1 + 0x88) != 0) {
    FUN_004a04f0(param_2,0,0,1);
  }
  local_4 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
