# Annotated low-level: FUN_0066fcf0

| Field | Value |
|---|---|
| Stable ID | `aa_0066fcf0` |
| VA | `0x0066fcf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0066fcf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __fastcall FUN_0066fcf0(int param_1)

{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined3 uVar5;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a8fb1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)(param_1 + 0x1c8) == 4) {
    ExceptionList = &local_c;
    iVar1 = FUN_0066f000();
    if (iVar1 < 0) {
      FUN_0066f910();
      ExceptionList = local_c;
      return 0xffffffff;
    }
    pvVar2 = operator_new__((uint)*(byte *)(param_1 + 0x14) * 4);
    *(void **)(param_1 + 0x208) = pvVar2;
    uVar3 = 0;
    if (*(char *)(param_1 + 0x14) != '\0') {
      do {
        *(undefined4 *)(*(int *)(param_1 + 0x208) + uVar3 * 4) = 0;
        uVar3 = uVar3 + 1;
      } while (uVar3 != *(byte *)(param_1 + 0x14));
    }
  }
  if (*(int *)(param_1 + 0x2c) == 0) {
    pvVar2 = operator_new(0x9b0);
    local_4 = 0;
    if (pvVar2 == (void *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_00672de0();
    }
    local_4 = 0xffffffff;
    *(undefined4 *)(param_1 + 0x2c) = uVar4;
  }
  if (*(int *)(param_1 + 0x30) == 0) {
    pvVar2 = operator_new(0x16c);
    local_4 = 1;
    if (pvVar2 == (void *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_00675010();
    }
    local_4 = 0xffffffff;
    *(undefined4 *)(param_1 + 0x30) = uVar4;
  }
  iVar1 = FUN_00671f00(*(undefined1 *)(param_1 + 0x28),*(undefined1 *)(param_1 + 0x185),
                       *(undefined4 *)(param_1 + 0x1f0));
  if (-1 < iVar1) {
    iVar1 = FUN_00673c90(*(undefined4 *)(param_1 + 0x24),*(undefined1 *)(param_1 + 0x15),
                         *(undefined1 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 500),
                         *(undefined4 *)(param_1 + 0x200),param_1 + 0x1ec);
    if (-1 < iVar1) {
      FUN_0071af70();
      FUN_0071af70();
      FUN_00671b90(param_1 + 0x5c);
      FUN_00673e00(param_1 + 0x5c);
      pvVar2 = operator_new__((uint)*(byte *)(param_1 + 0x14));
      *(void **)(param_1 + 0x1f8) = pvVar2;
      uVar3 = 0;
      if (*(char *)(param_1 + 0x14) != '\0') {
        do {
          *(undefined1 *)(uVar3 + *(int *)(param_1 + 0x1f8)) = 0;
          uVar3 = uVar3 + 1;
        } while (uVar3 != *(byte *)(param_1 + 0x14));
      }
      uVar5 = (undefined3)((uint)*(undefined4 *)(param_1 + 0x18) >> 8);
      pvVar2 = (void *)CONCAT31(uVar5,*(undefined1 *)(param_1 + 0x14));
      (**(code **)(**(int **)(param_1 + 0x54) + 0x14))
                (*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 8),
                 CONCAT31(uVar5,*(undefined1 *)(param_1 + 0xc)),pvVar2,
                 CONCAT31(uVar5,*(undefined1 *)(param_1 + 0x15)),
                 CONCAT31(uVar5,*(undefined1 *)(param_1 + 0x20)),*(undefined4 *)(param_1 + 0x18),
                 *(undefined4 *)(param_1 + 0x1c),
                 CONCAT31((int3)((uint)(param_1 + 0x1d0) >> 8),*(undefined1 *)(param_1 + 0x1c8)),
                 param_1 + 0x1d0);
      ExceptionList = pvVar2;
      return 0;
    }
    vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\ChatClientImpl.cpp"
                   ,0x17d,3,"Unable to initialize audio output.");
    ExceptionList = local_c;
    return 0xffffffff;
  }
  vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\ChatClientImpl.cpp"
                 ,0x172,3,"Unable to initialize audio input.");
  ExceptionList = local_c;
  return 0xffffffff;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
