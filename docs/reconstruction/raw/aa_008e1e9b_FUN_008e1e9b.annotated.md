# Annotated low-level: FUN_008e1e9b

| Field | Value |
|---|---|
| Stable ID | `aa_008e1e9b` |
| VA | `0x008e1e9b` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008e1e9b`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_008e1e9b(int *param_1)

{
  char cVar1;
  int *piVar2;
  int in_EAX;
  char *pcVar3;
  char *pcVar4;
  char cVar5;
  int *unaff_EBX;
  bool in_ZF;
  
  cVar5 = (char)unaff_EBX;
  if (((!in_ZF) && (piVar2 = *(int **)(in_EAX + 0x4b4), piVar2 != unaff_EBX)) &&
     ((int *)piVar2[5] != unaff_EBX)) {
    pcVar3 = (char *)(**(code **)(*(int *)piVar2[5] + 0x70))();
    pcVar4 = pcVar3 + 1;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != cVar5);
    if (pcVar3 != pcVar4) {
      pcVar3 = "i_d_s_2d_btn_skill";
      pcVar4 = (char *)(**(code **)(**(int **)(DAT_00d1b778[0x12d] + 0x14) + 0x70))();
      pcVar4 = strstr(pcVar4,pcVar3);
      if (pcVar4 != (char *)0x0) {
        if (*(int **)(DAT_00d1b778[0x12d] + 0x1c) != unaff_EBX) {
          (**(code **)(*DAT_00d1b778 + 0xb0))(*(int **)(DAT_00d1b778[0x12d] + 0x1c));
          if (*(int **)(DAT_00d1b778[0x12d] + 0x1c) != unaff_EBX) {
            (**(code **)**(int **)(DAT_00d1b778[0x12d] + 0x1c))(1);
          }
          *(int **)(DAT_00d1b778[0x12d] + 0x1c) = unaff_EBX;
        }
        if ((int *)DAT_00d1b778[0x12d] != unaff_EBX) {
          (*(code *)**(undefined4 **)DAT_00d1b778[0x12d])(1);
        }
        DAT_00d1b778[0x12d] = (int)unaff_EBX;
      }
    }
  }
  DAT_00d1d8f6 = 1;
  DAT_00d1d8f7 = cVar5;
  if (DAT_00d1d8e0 != unaff_EBX) {
    (**(code **)(*DAT_00d1d8e0 + 4))();
    DAT_00d1d8e0[0x145] = (int)unaff_EBX;
    *(char *)(DAT_00d1d8e0 + 0x13f) = cVar5;
  }
  (**(code **)(*param_1 + 0x3ac))();
  FUN_00792490();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
