# Annotated low-level: FUN_008bee80

| Field | Value |
|---|---|
| Stable ID | `aa_008bee80` |
| VA | `0x008bee80` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008bee80`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008bee80(void)

{
  int in_EAX;
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  piVar2 = (int *)(in_EAX + 0x54c);
  do {
    if (*(int *)(in_EAX + 0x52c) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(int *)(in_EAX + 0x530) - *(int *)(in_EAX + 0x52c) >> 3;
    }
    if ((uint)(*(int *)(in_EAX + 0x524) + iVar3) < uVar1) {
      FUN_008becd0();
    }
    else {
      if (piVar2[-3] != 0) {
        (**(code **)(*(int *)piVar2[-3] + 4))(0);
      }
      if (*piVar2 != 0) {
        (**(code **)(*(int *)*piVar2 + 4))(0);
      }
      if (piVar2[9] != 0) {
        (**(code **)(*(int *)piVar2[9] + 4))(0);
      }
      if (piVar2[3] != 0) {
        (**(code **)(*(int *)piVar2[3] + 4))(0);
      }
      if (piVar2[0xc] != 0) {
        (**(code **)(*(int *)piVar2[0xc] + 4))(0);
      }
      if (piVar2[6] != 0) {
        (**(code **)(*(int *)piVar2[6] + 4))(0);
      }
    }
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar3 < 3);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
