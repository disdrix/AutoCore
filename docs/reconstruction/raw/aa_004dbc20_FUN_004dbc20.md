# Raw capture: FUN_004dbc20

| Field | Value |
|---|---|
| **Stable ID** | `aa_004dbc20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004dbc20` |
| **Canonical name** | `FUN_004dbc20` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004dbc20(void *param_1,int *param_2)

{
  undefined4 *puVar1;
  char cVar2;
  void *pvVar3;
  int iVar4;
  void *pvVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  int unaff_EBP;
  int unaff_ESI;
  undefined4 *puVar9;
  void *pvStack_1c;
  void *pvStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a2321;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (*(int *)(*(int *)((int)param_1 + 0xe5c8) + 0xc) != 0) {
    ExceptionList = &pvStack_c;
    FUN_004e4a50();
  }
  (**(code **)(*param_2 + 0x14))();
  iStack_4 = 0;
  pvVar5 = param_1;
  if (0 < unaff_EBP) {
    do {
      iVar4 = 0;
      pvVar3 = operator_new(0x14);
      pvStack_c = (void *)0x0;
      if (pvVar3 != (void *)0x0) {
        iVar4 = FUN_005e1dd0();
      }
      puVar1 = (undefined4 *)(iVar4 + 4);
      pvStack_c = (void *)0xffffffff;
      puVar9 = puVar1;
      (**(code **)(*param_2 + 0x14))(puVar1,4);
      (**(code **)(*param_2 + 0x14))(iVar4 + 8,4);
      if (*(int *)((int)pvVar5 + 0x8c) < 0x12) {
        *(undefined1 *)(iVar4 + 0xc) = 0;
      }
      else {
        (**(code **)(*param_2 + 0x14))(iVar4 + 0xc,1);
      }
      (**(code **)(*param_2 + 0x14))(&stack0xffffffcc,4);
      pvVar5 = operator_new__((int)puVar9 + 1);
      *(void **)(iVar4 + 0x10) = pvVar5;
      pcVar6 = operator_new__((int)puVar9 + 1);
      (**(code **)(*param_2 + 0x14))(*(undefined4 *)(iVar4 + 0x10),puVar9);
      pcVar6[unaff_ESI] = '\0';
      pcVar8 = *(char **)(iVar4 + 0x10);
      pcVar7 = pcVar6;
      do {
        cVar2 = *pcVar7;
        *pcVar8 = cVar2;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      } while (cVar2 != '\0');
      *(undefined1 *)(unaff_ESI + *(int *)(iVar4 + 0x10)) = 0;
      FUN_004e7b30(*puVar1,iVar4,0);
      if (pcVar6 != (char *)0x0) {
        operator_delete__(pcVar6);
      }
      iStack_4 = iStack_4 + 1;
      pvVar5 = pvStack_1c;
    } while (iStack_4 < unaff_EBP);
  }
  ExceptionList = param_1;
  return;
}
```
