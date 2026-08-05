# Annotated low-level: FUN_004eb0f0

| Field | Value |
|---|---|
| Stable ID | `aa_004eb0f0` |
| VA | `0x004eb0f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004eb0f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_004eb0f0(void)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 *unaff_EDI;
  undefined4 uVar5;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a274d;
  local_c = ExceptionList;
  pcVar4 = (char *)*unaff_EDI;
  pcVar3 = pcVar4;
  if (pcVar4 == (char *)0x0) {
    pcVar3 = PTR_DAT_00afa2bc;
  }
  pcVar1 = pcVar3 + 1;
  do {
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  if (4 < (uint)((int)pcVar3 - (int)pcVar1)) {
    if (pcVar4 == (char *)0x0) {
      pcVar4 = PTR_DAT_00afa2bc;
    }
    uVar5 = 0xffffffff;
    ExceptionList = &local_c;
    FUN_007b6a20(pcVar4,0xffffffff);
    cVar2 = FUN_007b6730(pcVar4,uVar5);
    if (cVar2 != '\0') {
      cVar2 = FUN_0099bfc0(unaff_EDI);
      if (cVar2 == '\0') {
        FUN_00764030();
        local_4 = 0;
        FUN_00764830(unaff_EDI);
        local_4 = 0xffffffff;
        FUN_00763f60();
        ExceptionList = local_c;
        return 1;
      }
    }
  }
  ExceptionList = local_c;
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
