# Annotated low-level: FUN_006fa6f0

| Field | Value |
|---|---|
| Stable ID | `aa_006fa6f0` |
| VA | `0x006fa6f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006fa6f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006fa6f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  char cVar1;
  char cVar2;
  ushort uVar3;
  ushort local_8;
  ushort local_6 [3];
  
  local_6[1] = 0;
  FUN_006f8340(&local_8,local_6);
  FUN_006fa670(param_1,&local_8,param_8);
  if (param_4 == 0) {
    cVar1 = '\x03';
  }
  else {
    cVar1 = (param_4 == 1) + '\x01';
  }
  if (param_5 == 0) {
    cVar2 = '\x03';
  }
  else {
    cVar2 = (param_5 == 1) + '\x01';
  }
  uVar3 = (ushort)(1 << cVar1 + 4);
  local_8 = local_8 ^ uVar3;
  FUN_006fa670(param_1,&local_8,param_8);
  local_6[0] = local_6[0] ^ (ushort)(1 << cVar2 + 4);
  FUN_006fa670(param_1,&local_8,param_8);
  local_8 = local_8 ^ uVar3;
  FUN_006fa670(param_1,&local_8,param_8);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
