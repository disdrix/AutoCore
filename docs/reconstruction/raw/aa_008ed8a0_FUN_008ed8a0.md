# Raw capture: FUN_008ed8a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ed8a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008ed8a0` |
| **Canonical name** | `FUN_008ed8a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_008ed8a0(int param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined2 *puVar7;
  undefined1 auStack_164 [4];
  undefined **ppuStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  _RTL_CRITICAL_SECTION _Stack_150;
  _RTL_CRITICAL_SECTION _Stack_138;
  undefined4 uStack_120;
  undefined2 uStack_118;
  undefined4 auStack_116 [64];
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009b1058;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  *(undefined4 *)(param_1 + 0x50c) = 0;
  FUN_008eba20();
  *(undefined4 *)(param_1 + 0x540) = 0xffffffff;
  if (*(int **)(param_1 + 0x59c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x59c) + 0x1d8))("Central Wastelands",1,1);
    (**(code **)(**(int **)(param_1 + 0x59c) + 0x34c))();
  }
  if (*(int **)(param_1 + 0x574) != (int *)0x0) {
    pcVar2 = (char *)(**(code **)(**(int **)(param_1 + 0x574) + 0x2b8))();
    pcVar5 = (char *)&uStack_118;
    do {
      cVar1 = *pcVar2;
      *pcVar5 = cVar1;
      pcVar2 = pcVar2 + 1;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    (**(code **)(**(int **)(param_1 + 0x574) + 0x50))("i_d_cont_2d_wnd_continent-map.dds",1,0);
    *(undefined1 *)(*(int *)(param_1 + 0x574) + 0xd7) = 1;
    (**(code **)(**(int **)(param_1 + 0x574) + 0x34c))();
    FUN_007b6a20();
    FUN_00989e00(auStack_164,&uStack_118);
    FUN_0075e2d0(auStack_164);
  }
  if ((*(int **)(param_1 + 0x67c) != (int *)0x0) &&
     (iVar3 = (**(code **)(**(int **)(param_1 + 0x67c) + 700))(), iVar3 != 0)) {
    uStack_118 = 0;
    puVar6 = auStack_116;
    for (iVar3 = 0x3f; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    piVar4 = *(int **)(param_1 + 0x67c);
    *(undefined2 *)puVar6 = 0;
    iVar3 = (**(code **)(*piVar4 + 0x2b8))();
    if (iVar3 != 0) {
      pcVar2 = (char *)(**(code **)(**(int **)(param_1 + 0x67c) + 0x2b8))();
      pcVar5 = (char *)&uStack_118;
      do {
        cVar1 = *pcVar2;
        *pcVar5 = cVar1;
        pcVar2 = pcVar2 + 1;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
    }
    (**(code **)(**(int **)(param_1 + 0x67c) + 0x58))();
    (**(code **)(**(int **)(param_1 + 0x67c) + 4))(0);
    if ((char)uStack_118 != '\0') {
      puVar7 = &uStack_118;
      FUN_007b6a20(puVar7);
      FUN_007b70b0(puVar7);
    }
  }
  ppuStack_160 = &PTR_FUN_00a39350;
  uStack_15c = 0;
  uStack_158 = 0;
  uStack_154 = 0;
  uStack_120 = 0xffffffff;
  InitializeCriticalSection(&_Stack_150);
  InitializeCriticalSection(&_Stack_138);
  uStack_c = 0;
  param_1 = param_1 + 0x5b0;
  piVar4 = (int *)FUN_0040e490(param_1);
  while (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 4))(1);
    FUN_0040e230(&ppuStack_160);
    piVar4 = (int *)FUN_0040e490(param_1);
  }
  iVar3 = FUN_0040e490(&ppuStack_160);
  while (iVar3 != 0) {
    FUN_0040e230(param_1);
    iVar3 = FUN_0040e490(&ppuStack_160);
  }
  FUN_008ec980();
  uStack_c = 0xffffffff;
  FUN_0040e1e0();
  ExceptionList = pvStack_14;
  return;
}
```
