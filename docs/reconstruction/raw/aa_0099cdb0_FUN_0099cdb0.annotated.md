# Annotated low-level: FUN_0099cdb0

| Field | Value |
|---|---|
| Stable ID | `aa_0099cdb0` |
| VA | `0x0099cdb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0099cdb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __fastcall FUN_0099cdb0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 uStack_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009b06c7;
  pvStack_10 = ExceptionList;
  uStack_18 = 0x99cdd3;
  local_14 = &stack0xffffefa0;
  ExceptionList = &pvStack_10;
  FUN_0076c500(1000);
  *(undefined1 *)(param_1 + 0x1c) = 1;
  local_8 = 0;
  do {
    Sleep(0x1e);
    iVar1 = FUN_0076c3c0();
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + iVar1;
    if (199 < *(uint *)(param_1 + 0x20)) {
      *(undefined4 *)(param_1 + 0x20) = 0;
      iVar1 = Client_GetMissionCompleteAudioTable();
      EnterCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x3f8));
      local_8 = CONCAT31(local_8._1_3_,1);
      iVar2 = Client_GetMissionCompleteAudioTable();
      if (*(char *)(iVar2 + 0x410) != '\0') {
        uVar3 = Client_GetMissionCompleteAudioTable();
        FUN_00723290(uVar3);
      }
      for (piVar4 = *(int **)(param_1 + 0x10); piVar4 != *(int **)(param_1 + 0x14);
          piVar4 = piVar4 + 1) {
        iVar2 = *piVar4;
        FUN_0071e820((int)&uStack_18 + 3);
        *(undefined1 *)(iVar2 + 0x1c4) = 0;
      }
      local_8 = local_8 & 0xffffff00;
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x3f8));
    }
    FUN_0076c4d0();
  } while (*(char *)(param_1 + 0x1c) != '\0');
  FUN_0099cf08();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
