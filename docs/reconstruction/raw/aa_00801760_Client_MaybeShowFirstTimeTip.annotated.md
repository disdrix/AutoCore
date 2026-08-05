# Annotated low-level: Client_MaybeShowFirstTimeTip

| Field | Value |
|---|---|
| Stable ID | `aa_00801760` |
| VA | `0x00801760` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00801760`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Maybe show first-time tip UI (CDlgFirstTime).
   param_2 = tip id (0..0x31).
   Skips if tip bit already set in char+0xD30 dword[id>>5] bit(id&0x1f).
   If FirstFlags1 signed < 0 (hide-tips bit31), marks bit + SendUpdateFirstTimeFlags without showing
   UI.
   Else creates/shows CDlgFirstTime and queues tip.
   AutoCore persists bits on account.FirstFlags1..4. */

void __thiscall Client_MaybeShowFirstTimeTip(int param_1,uint param_2)

{
  int iVar1;
  char cVar2;
  void *pvVar3;
  undefined4 uVar4;
  void *unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b8073;
  local_c = ExceptionList;
  iVar1 = *(int *)(param_1 + 0xe98);
  if (iVar1 == 0) {
    return;
  }
  if (((byte)param_2 < 0x80) &&
     ((*(uint *)(iVar1 + 0xd30 + ((param_2 & 0xff) >> 5) * 4) & 1 << ((byte)param_2 & 0x1f)) != 0))
  {
    return;
  }
  if (0x31 < (int)param_2) {
    return;
  }
  if ("Controls"[param_2 * 0x1e] == '\0') {
    return;
  }
  if (*(int *)(iVar1 + 0xd30) < 0) {
    ExceptionList = &local_c;
    Client_SetFirstTimeTipBit();
    Client_SendUpdateFirstTimeFlags();
    ExceptionList = local_c;
    return;
  }
  ExceptionList = &local_c;
  if (*(int *)(param_1 + 0x1164) == 0) {
    ExceptionList = &local_c;
    pvVar3 = operator_new(0x5b0);
    local_4 = 0;
    if (pvVar3 == (void *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = CDlgFirstTime_ctor(pvVar3);
    }
    *(undefined4 *)(param_1 + 0x1164) = uVar4;
  }
  local_4 = 0xffffffff;
  cVar2 = (**(code **)(**(int **)(param_1 + 0x1164) + 0x3d8))();
  if ((cVar2 != '\0') && (param_2 != 6)) {
    (**(code **)(**(int **)(param_1 + 0x1164) + 0x46c))(param_2,0);
    ExceptionList = unaff_ESI;
    return;
  }
  if (*(int *)(param_1 + 0xf38) == 0) {
    ExceptionList = local_c;
    return;
  }
  if (*(int **)(param_1 + 0xf40) != (int *)0x0) {
    if (**(int **)(param_1 + 0xf40) == *(int *)(param_1 + 0xf38)) {
      cVar2 = (**(code **)(**(int **)(param_1 + 0x1164) + 0x3d8))();
      if (cVar2 == '\0') {
        (**(code **)(**(int **)(param_1 + 0xf38) + 0xa8))(*(undefined4 *)(param_1 + 0x1164));
        (**(code **)(**(int **)(param_1 + 0x1164) + 0x43c))();
      }
      (**(code **)(**(int **)(param_1 + 0x1164) + 0x460))(0);
      (**(code **)(**(int **)(param_1 + 0x1164) + 0x450))(param_2);
      (**(code **)(**(int **)(param_1 + 0x1164) + 0xfc))(1,0x3f000000);
      if (param_2 == 0) {
        (**(code **)(**(int **)(param_1 + 0x1164) + 0x464))(0);
      }
      else if (param_2 == 6) {
        (**(code **)(**(int **)(param_1 + 0x1164) + 0x464))(0);
      }
      cVar2 = (**(code **)(**(int **)(param_1 + 0x1164) + 0x468))();
      if ((cVar2 == '\x01') &&
         (((param_2 == 6 ||
           (cVar2 = (**(code **)(**(int **)(param_1 + 0x1164) + 0x470))(6), cVar2 != '\0')) &&
          ((DAT_00d17920 & 0x80) == 0)))) {
        DAT_00d17920 = DAT_00d17920 | 0x80;
      }
      (**(code **)(**(int **)(param_1 + 0xf38) + 0x3c4))(1);
      FUN_0092f000();
      ExceptionList = local_c;
      return;
    }
    ExceptionList = local_c;
    return;
  }
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
