# Annotated low-level: Skill_CopyRuntimeFieldsFromTemplate

| Field | Value |
|---|---|
| Stable ID | `aa_00553480` |
| VA | `0x00553480` |
| System | skills-abilities |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00553480`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Skill_CopyRuntimeFieldsFromTemplate(pDst, pSrc)
   
   Copies rank/flags/category/name fields; clears casting flag and cast start tick;
   calls Skill_ReevaluateForCurrentRank. */

void __thiscall Skill_CopyRuntimeFieldsFromTemplate(void *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  *(undefined2 *)((int)param_1 + 0x5f6) = *(undefined2 *)(param_2 + 0x5f6);
  *(undefined1 *)((int)param_1 + 0x5f8) = *(undefined1 *)(param_2 + 0x5f8);
  *(undefined1 *)((int)param_1 + 0x5f9) = *(undefined1 *)(param_2 + 0x5f9);
  *(undefined1 *)((int)param_1 + 0x5fa) = *(undefined1 *)(param_2 + 0x5fa);
  *(undefined1 *)((int)param_1 + 0x5fb) = *(undefined1 *)(param_2 + 0x5fb);
  *(undefined1 *)((int)param_1 + 0x5f4) = *(undefined1 *)(param_2 + 0x5f4);
  *(undefined4 *)((int)param_1 + 0x614) = *(undefined4 *)(param_2 + 0x614);
  *(undefined4 *)((int)param_1 + 0x618) = *(undefined4 *)(param_2 + 0x618);
  *(undefined4 *)((int)param_1 + 0x60c) = *(undefined4 *)(param_2 + 0x60c);
  *(undefined4 *)((int)param_1 + 0x610) = *(undefined4 *)(param_2 + 0x610);
  *(undefined4 *)((int)param_1 + 0x620) = *(undefined4 *)(param_2 + 0x620);
  *(undefined4 *)((int)param_1 + 0x180) = *(undefined4 *)(param_2 + 0x180);
  *(undefined4 *)((int)param_1 + 0x17c) = *(undefined4 *)(param_2 + 0x17c);
  *(undefined1 *)((int)param_1 + 0x628) = 0;
  *(short *)((int)param_1 + 0x174) = (short)(int)*(float *)(param_2 + 0xf4);
  *(undefined1 *)((int)param_1 + 0x5e7) = *(undefined1 *)(param_2 + 0x5e7);
  *(undefined4 *)((int)param_1 + 0x5e8) = *(undefined4 *)(param_2 + 0x5e8);
  pcVar3 = (char *)(param_2 + 0x1a5);
  *(undefined4 *)((int)param_1 + 0x5ec) = *(undefined4 *)(param_2 + 0x5ec);
  iVar2 = 0x1a5 - (int)pcVar3;
  do {
    cVar1 = *pcVar3;
    pcVar3[(int)param_1 + iVar2] = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  *(undefined4 *)((int)param_1 + 0x170) = 0;
  *(undefined4 *)((int)param_1 + 0x178) = 0;
  Skill_ReevaluateForCurrentRank(param_1);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
