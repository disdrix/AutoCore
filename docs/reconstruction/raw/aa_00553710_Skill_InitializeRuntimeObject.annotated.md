# Annotated low-level: Skill_InitializeRuntimeObject

| Field | Value |
|---|---|
| Stable ID | `aa_00553710` |
| VA | `0x00553710` |
| System | skills-abilities |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00553710`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Skill_InitializeRuntimeObject(...)
   
   Fills skill runtime from template args: id +0x5fc, category +0x5e8, flags +0x614.
   Clears casting. If flags byte+0x615 bit1 set → +0x61c=1 (defer cast-again start).
   
   INFERRED: full parameter list from many ctor args. */

void * __thiscall
Skill_InitializeRuntimeObject
          (void *param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,undefined1 param_5
          ,undefined1 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
          undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,
          undefined4 param_14,undefined4 param_15,undefined1 param_16,undefined4 param_17,
          undefined4 param_18,char *param_19,char *param_20,char *param_21,undefined4 param_22,
          undefined4 param_23,undefined4 param_24)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  *(undefined4 *)((int)param_1 + 0x17c) = param_14;
  *(undefined4 *)((int)param_1 + 0x5e8) = param_17;
  *(undefined1 *)((int)param_1 + 0x5f8) = param_2;
  *(undefined4 *)((int)param_1 + 0x180) = param_13;
  *(undefined1 *)((int)param_1 + 0x5e7) = param_16;
  *(undefined1 *)((int)param_1 + 0x5fb) = param_5;
  *(undefined4 *)((int)param_1 + 0x5ec) = param_18;
  *(undefined1 *)((int)param_1 + 0x5f4) = param_6;
  *(undefined4 *)((int)param_1 + 0x610) = param_11;
  *(undefined1 *)((int)param_1 + 0x5f9) = param_3;
  *(undefined1 *)((int)param_1 + 0x5fa) = param_4;
  *(undefined4 *)((int)param_1 + 0x620) = param_12;
  *(undefined4 *)((int)param_1 + 0x5fc) = param_7;
  *(undefined4 *)((int)param_1 + 0x60c) = param_10;
  *(undefined4 *)((int)param_1 + 0x170) = 0;
  *(undefined2 *)((int)param_1 + 0x174) = 0;
  *(undefined4 *)((int)param_1 + 0x178) = 0;
  *(undefined2 *)((int)param_1 + 0x5f6) = 0;
  *(undefined4 *)((int)param_1 + 0x614) = param_8;
  *(undefined4 *)((int)param_1 + 0x618) = param_9;
  *(undefined1 *)((int)param_1 + 0x61c) = 0;
  *(undefined1 *)((int)param_1 + 0x628) = 0;
  *(undefined4 *)((int)param_1 + 0x62c) = param_15;
  uVar3 = FUN_00418820(param_15);
  *(undefined4 *)((int)param_1 + 0x5f0) = uVar3;
  *(undefined4 *)((int)param_1 + 0x604) = param_23;
  *(undefined4 *)((int)param_1 + 0x608) = param_24;
  *(undefined4 *)((int)param_1 + 0x600) = param_22;
  iVar2 = 0x184 - (int)param_19;
  do {
    cVar1 = *param_19;
    param_19[(int)param_1 + iVar2] = cVar1;
    param_19 = param_19 + 1;
  } while (cVar1 != '\0');
  iVar2 = 0x1a5 - (int)param_20;
  do {
    cVar1 = *param_20;
    param_20[(int)param_1 + iVar2] = cVar1;
    param_20 = param_20 + 1;
  } while (cVar1 != '\0');
  if (param_21 == (char *)0x0) {
    *(undefined1 *)((int)param_1 + 0x5a6) = 0;
  }
  else {
    iVar2 = 0x5a6 - (int)param_21;
    do {
      cVar1 = *param_21;
      param_21[(int)param_1 + iVar2] = cVar1;
      param_21 = param_21 + 1;
    } while (cVar1 != '\0');
  }
  Skill_ReevaluateForCurrentRank(param_1);
  if ((*(byte *)((int)param_1 + 0x615) & 2) != 0) {
    *(undefined1 *)((int)param_1 + 0x61c) = 1;
  }
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
