# Annotated low-level: FUN_004d6ff0

| Field | Value |
|---|---|
| Stable ID | `aa_004d6ff0` |
| VA | `0x004d6ff0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004d6ff0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004d6ff0(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  undefined4 *puVar3;
  undefined1 local_2f4 [4];
  undefined4 auStack_2f0 [181];
  void *pvStack_1c;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009a214f;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  FUN_007a4400("ReadMusicRegions");
  iVar2 = 0;
  *(undefined4 *)(param_1 + 0xe7cc) = 0;
  local_c = 0;
  (**(code **)(*param_2 + 0x14))(local_2f4,4);
  if (0 < unaff_ESI) {
    do {
      (**(code **)(*param_2 + 0x14))(local_2f4,4);
      puVar3 = auStack_2f0;
      for (iVar1 = 0x32; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
      }
      FUN_0071f4d0(param_2,param_3);
      FUN_004804d0(auStack_2f0);
      iVar2 = iVar2 + 1;
    } while (iVar2 < unaff_ESI);
  }
  pvStack_14 = (void *)0xffffffff;
  FUN_007a4390();
  ExceptionList = pvStack_1c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
