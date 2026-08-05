# Annotated low-level: FUN_005b4de0

| Field | Value |
|---|---|
| Stable ID | `aa_005b4de0` |
| VA | `0x005b4de0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005b4de0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __fastcall FUN_005b4de0(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a68bf;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0076cf00("SetupFrondForTreeType");
  local_4 = 0;
  FUN_0068a4d0(*(undefined4 *)(param_1 + 0x50),2,0xffffffff,0xffffffff,0xffffffff);
  if (*(short *)(*(int *)(param_1 + 0x50) + 0x40) != 0) {
    *(uint *)(*(int *)(param_1 + 0x10) + 0xc4) =
         *(ushort *)(*(int *)(param_1 + 0x70) + *(int *)(*(int *)(param_1 + 0x50) + 0x3c) * 2) - 2;
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xd0);
    cVar2 = FUN_0096fdf0();
    iVar3 = FUN_00752a00(uVar1,&DAT_00b05240);
    if ((iVar3 == -1) && (cVar2 != '\0')) {
      FUN_0096f5d0();
    }
    local_4 = 0xffffffff;
    FUN_0076cef0();
    ExceptionList = local_c;
    return 1;
  }
  local_4 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = local_c;
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
