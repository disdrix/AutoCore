# Annotated low-level: FUN_007a4ae0

| Field | Value |
|---|---|
| Stable ID | `aa_007a4ae0` |
| VA | `0x007a4ae0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007a4ae0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_007a4ae0(int *param_1,char *param_2,char param_3,int param_4)

{
  char *pcVar1;
  time_t tVar2;
  int unaff_retaddr;
  
  if (param_3 == '\0') {
    *(undefined4 *)(param_2 + 0x210) = *(undefined4 *)(param_2 + 0x208);
    *(undefined4 *)(param_2 + 0x214) = *(undefined4 *)(param_2 + 0x20c);
    param_2[0x1d3] = '\0';
    if (param_2 + 0x1c2 != (char *)0x0) {
      strncpy(param_2 + 0x1d3,param_2 + 0x1c2,0x10);
      param_2[0x1e3] = '\0';
    }
    pcVar1 = (char *)(**(code **)(*param_1 + 0x38))
                               (*(undefined4 *)(param_2 + 0x1f0),*(undefined4 *)(param_2 + 500),
                                *(undefined4 *)(param_2 + 0x1f8));
    *param_2 = '\0';
    if (pcVar1 != (char *)0x0) {
      strncpy(param_2,pcVar1,0x31);
      param_2[0x31] = '\0';
    }
    if (((unaff_retaddr == 0) || (*(int *)(unaff_retaddr + 0x208) != *(int *)(param_2 + 0x208))) ||
       (*(int *)(unaff_retaddr + 0x20c) != *(int *)(param_2 + 0x20c))) {
      param_2[0x224] = '\x04';
    }
    else {
      param_2[0x224] = '\x05';
    }
  }
  else {
    if (param_4 != 0) {
      *(undefined4 *)(param_2 + 0x210) = *(undefined4 *)(param_4 + 0x208);
      *(undefined4 *)(param_2 + 0x214) = *(undefined4 *)(param_4 + 0x20c);
      param_2[0x1d3] = '\0';
      if ((char *)(param_4 + 0x1c2) != (char *)0x0) {
        strncpy(param_2 + 0x1d3,(char *)(param_4 + 0x1c2),0x10);
        param_2[0x1e3] = '\0';
      }
    }
    pcVar1 = (char *)(**(code **)(*param_1 + 0x38))
                               (*(undefined4 *)(param_2 + 0x1f0),*(undefined4 *)(param_2 + 500),
                                *(undefined4 *)(param_2 + 0x1f8));
    *param_2 = '\0';
    if (pcVar1 != (char *)0x0) {
      strncpy(param_2,pcVar1,0x31);
      param_2[0x31] = '\0';
    }
    param_2[0x224] = '\x03';
  }
  param_2[0x208] = -1;
  param_2[0x209] = -1;
  param_2[0x20a] = -1;
  param_2[0x20b] = -1;
  param_2[0x20c] = -1;
  param_2[0x20d] = -1;
  param_2[0x20e] = -1;
  param_2[0x20f] = -1;
  param_2[0x1c2] = '\0';
  strncpy(param_2 + 0x1c2,"",0x10);
  param_2[0x1d2] = '\0';
  param_2[0x1e8] = '\0';
  param_2[0x1e9] = '\0';
  param_2[0x1ea] = '\0';
  param_2[0x1eb] = '\0';
  param_2[0x1ec] = '\0';
  param_2[0x1ed] = '\0';
  param_2[0x1ee] = '\0';
  param_2[0x1ef] = '\0';
  tVar2 = time((time_t *)0x0);
  *(int *)(param_2 + 0x218) = (int)tVar2;
  param_2[0x248] = '\0';
  *(int *)(param_2 + 0x21c) = (int)tVar2 + 0x278d00;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
