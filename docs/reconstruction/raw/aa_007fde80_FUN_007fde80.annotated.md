# Annotated low-level: FUN_007fde80

| Field | Value |
|---|---|
| Stable ID | `aa_007fde80` |
| VA | `0x007fde80` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fde80`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007fde80(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  int in_EAX;
  int *piVar1;
  
  FUN_007fb7f0();
  if ((*(char *)(in_EAX + 0x9d) == '\0') && (*(int **)(in_EAX + 0xf40) != (int *)0x0)) {
    piVar1 = *(int **)(in_EAX + 0x1124);
    if (param_5 == 2) {
      piVar1 = *(int **)(in_EAX + 0x1128);
    }
    else if (param_5 == 3) {
      piVar1 = *(int **)(in_EAX + 0x112c);
    }
    else if (param_5 == 4) {
      piVar1 = *(int **)(in_EAX + 0x1130);
    }
    else if (param_5 == 5) {
      piVar1 = *(int **)(in_EAX + 0x1134);
    }
    if (piVar1 != (int *)0x0) {
      if (**(int **)(in_EAX + 0xf40) != 0) {
        (**(code **)(*(int *)**(undefined4 **)(in_EAX + 0xf40) + 0x3ec))();
        (**(code **)(*(int *)**(undefined4 **)(in_EAX + 0xf40) + 0x3f4))(1);
        (**(code **)(*(int *)**(undefined4 **)(in_EAX + 0xf40) + 0xa8))(piVar1);
      }
      (**(code **)(*piVar1 + 0x43c))();
      piVar1[0x148] = param_3;
      piVar1[0x149] = param_4;
      (**(code **)(*piVar1 + 0x444))(param_1,param_2,1);
      (**(code **)(*piVar1 + 0x13c))();
      piVar1[0x146] = -1;
      piVar1[0x147] = -1;
      (**(code **)(*piVar1 + 0x34c))();
      FUN_0092f000();
      return;
    }
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
