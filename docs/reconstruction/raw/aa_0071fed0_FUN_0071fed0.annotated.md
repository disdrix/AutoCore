# Annotated low-level: FUN_0071fed0

| Field | Value |
|---|---|
| Stable ID | `aa_0071fed0` |
| VA | `0x0071fed0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0071fed0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0071fed0(undefined4 *param_1)

{
  int *piVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  
  iVar5 = (int)param_1;
  lpCriticalSection = (LPCRITICAL_SECTION)((int)param_1 + 0x170);
  EnterCriticalSection(lpCriticalSection);
  puVar8 = *(undefined4 **)((int)param_1 + 0x44);
  piVar1 = (int *)((int)param_1 + 0x48);
  param_1 = puVar8;
  if (puVar8 != (undefined4 *)*piVar1) {
    do {
      if (puVar8[0x2e] == 4) {
        puVar2 = *(undefined4 **)(iVar5 + 0x48);
        puVar3 = puVar8;
        puVar4 = puVar8;
        while (puVar4 = puVar4 + 0x32, puVar4 != puVar2) {
          puVar7 = puVar3 + 0x32;
          puVar9 = puVar4;
          puVar10 = puVar3;
          for (iVar6 = 0x32; puVar3 = puVar7, puVar8 = param_1, iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
        }
        *(int *)(iVar5 + 0x48) = *(int *)(iVar5 + 0x48) + -200;
      }
      else {
        puVar8 = puVar8 + 0x32;
        param_1 = puVar8;
      }
    } while (puVar8 != *(undefined4 **)(iVar5 + 0x48));
  }
  puVar8 = *(undefined4 **)(iVar5 + 0x54);
  param_1 = puVar8;
  if (puVar8 != *(undefined4 **)(iVar5 + 0x58)) {
    do {
      if (puVar8[0x2e] == 4) {
        puVar2 = *(undefined4 **)(iVar5 + 0x58);
        puVar3 = puVar8;
        puVar4 = puVar8;
        while (puVar4 = puVar4 + 0x32, puVar4 != puVar2) {
          puVar7 = puVar3 + 0x32;
          puVar9 = puVar4;
          puVar10 = puVar3;
          for (iVar6 = 0x32; puVar3 = puVar7, puVar8 = param_1, iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
        }
        *(int *)(iVar5 + 0x58) = *(int *)(iVar5 + 0x58) + -200;
      }
      else {
        puVar8 = puVar8 + 0x32;
        param_1 = puVar8;
      }
    } while (puVar8 != *(undefined4 **)(iVar5 + 0x58));
  }
                    /* WARNING: Could not recover jumptable at 0x0071ffb5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LeaveCriticalSection(lpCriticalSection);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
