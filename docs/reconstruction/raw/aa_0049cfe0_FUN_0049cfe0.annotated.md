# Annotated low-level: FUN_0049cfe0

| Field | Value |
|---|---|
| Stable ID | `aa_0049cfe0` |
| VA | `0x0049cfe0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0049cfe0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_0049cfe0(int param_1,int *param_2)

{
  float fVar1;
  char cVar2;
  int iVar3;
  int *local_4;
  
  if (param_2 != (int *)0x0) {
    iVar3 = (**(code **)(*param_2 + 0x44))(param_2,&local_4);
    fVar1 = g_flOne;
    if ((iVar3 == 0) && (local_4 != (int *)0x0)) {
      *(byte *)(param_1 + 0x3e3) = *(byte *)(param_1 + 0x3e3) | 8;
      *(float *)(param_1 + 0x3c) = fVar1;
      cVar2 = FUN_00799200(local_4,L"speed",(float *)(param_1 + 0x3c),param_1 + 0x40,&param_2);
      if (cVar2 != '\0') {
        *(byte *)(param_1 + 0x1e4) = *(byte *)(param_1 + 0x1e4) & 0x7f | (char)param_2 << 7;
      }
      (**(code **)(*local_4 + 8))(local_4);
      return 1;
    }
  }
  FUN_007a4480(0,"VOG_DEBUG_STOP");
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
