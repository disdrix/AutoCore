# Annotated low-level: FUN_006fafb0

| Field | Value |
|---|---|
| Stable ID | `aa_006fafb0` |
| VA | `0x006fafb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006fafb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006fafb0(int param_1)

{
  char *pcVar1;
  int iVar2;
  undefined1 local_5d;
  char local_5c [4];
  undefined4 local_58;
  undefined2 local_54;
  undefined1 local_50 [76];
  
  FUN_006f8f00();
  FUN_006fa360(param_1);
  FUN_006f8200(local_5c,param_1);
  if ((*(char *)(param_1 + 0x58) == '\0') || (local_5c[0] != '\0')) {
    pcVar1 = (char *)FUN_006f91d0(&local_5d);
    if (*pcVar1 != '\0') {
      local_54 = 0;
      iVar2 = FUN_006fabe0(param_1,&local_58,local_50);
      if ((local_5c[0] != '\0') && (iVar2 != 0)) {
        FUN_006f8160(param_1,&local_58,local_50,iVar2 == 2);
        if (*(char *)(param_1 + 0x59) != '\0') {
          FUN_006fa550(param_1);
        }
      }
      if (iVar2 == 2) {
        FUN_006f88a0(param_1,local_50,&local_58);
        FUN_006fa7d0(param_1,local_58,local_54);
      }
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
