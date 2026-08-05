# Annotated low-level: FUN_006eda50

| Field | Value |
|---|---|
| Stable ID | `aa_006eda50` |
| VA | `0x006eda50` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006eda50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006eda50(int *param_1,undefined4 *param_2,int *param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *local_50;
  int local_4c;
  int local_48;
  int *local_44;
  undefined **ppuStack_40;
  undefined4 uStack_3c;
  char cStack_38;
  undefined4 uStack_24;
  
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = "LthkBvAgent";
    uVar1 = rdtsc();
    DAT_00bc5644[1] = (int)uVar1;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  local_48 = param_1[2];
  iVar4 = *param_1;
  local_44 = param_1;
  local_50 = *(int **)(iVar4 + 0xc);
  local_4c = param_1[1];
  iVar2 = (**(code **)(*local_50 + 0x14))();
  iVar3 = (**(code **)(*(int *)*param_2 + 0x14))();
  ppuStack_40 = &PTR_LAB_00a0e9d8;
  cStack_38 = '\0';
  uStack_24 = 0x7f7fffff;
  uStack_3c = 0x7f7fffff;
  (**(code **)(*param_3 + 0x318c + (iVar2 * 0x20 + iVar3) * 4))
            (&local_50,param_2,param_3,&ppuStack_40,&ppuStack_40);
  if (cStack_38 != '\0') {
    if (DAT_00bc5644 < DAT_00bc5648) {
      *DAT_00bc5644 = "Stchild";
      uVar1 = rdtsc();
      DAT_00bc5644[1] = (int)uVar1;
      DAT_00bc5644 = DAT_00bc5644 + 3;
    }
    local_50 = *(int **)(iVar4 + 0x10);
    local_4c = local_44[1];
    iVar4 = (**(code **)(*local_50 + 0x14))();
    (**(code **)(*param_3 + 0x318c + (iVar4 * 0x20 + iVar3) * 4))
              (&local_50,param_2,param_3,param_4,param_5);
  }
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = &DAT_009d282c;
    uVar1 = rdtsc();
    DAT_00bc5644[1] = (int)uVar1;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
