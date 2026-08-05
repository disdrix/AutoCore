# Raw capture: FUN_0046dbb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046dbb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0046dbb0` |
| **Canonical name** | `FUN_0046dbb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0046dbb0(uint *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  float10 fVar8;
  float10 fVar9;
  undefined4 *local_c;
  undefined4 *puStack_8;
  
  puVar4 = param_2 + (((int)param_3 - (int)param_2 >> 2) - ((int)param_3 - (int)param_2 >> 0x1f) >>
                     1);
  FUN_0046df80(param_2,puVar4,param_3 + -1,param_4);
  puVar6 = puVar4 + 1;
  if (param_2 < puVar4) {
    while( true ) {
      piVar1 = *(int **)*puVar4;
      fVar8 = (float10)(**(code **)(**(int **)puVar4[-1] + 0x10))();
      fVar9 = (float10)(**(code **)(*piVar1 + 0x10))();
      if (fVar9 - (float10)DAT_00aaa620 <= (float10)(float)fVar8) break;
      piVar1 = *(int **)puVar4[-1];
      fVar8 = (float10)(**(code **)(**(int **)*puVar4 + 0x10))();
      fVar9 = (float10)(**(code **)(*piVar1 + 0x10))();
      if ((fVar9 - (float10)DAT_00aaa620 <= (float10)(float)fVar8) ||
         (puVar4 = puVar4 + -1, puVar4 <= param_2)) break;
    }
  }
  puVar3 = puVar6;
  local_c = puVar6;
  puStack_8 = puVar4;
  puVar7 = puVar4;
  if (puVar6 < param_3) {
    while( true ) {
      piVar1 = *(int **)*puVar4;
      fVar8 = (float10)(**(code **)(**(int **)*puVar6 + 0x10))();
      fVar9 = (float10)(**(code **)(*piVar1 + 0x10))();
      puVar3 = puVar6;
      local_c = puVar6;
      if (fVar9 - (float10)DAT_00aaa620 <= (float10)(float)fVar8) break;
      piVar1 = *(int **)*puVar6;
      fVar8 = (float10)(**(code **)(**(int **)*puVar4 + 0x10))();
      fVar9 = (float10)(**(code **)(*piVar1 + 0x10))();
      if ((fVar9 - (float10)DAT_00aaa620 <= (float10)(float)fVar8) ||
         (puVar6 = puVar6 + 1, puVar3 = puVar6, local_c = puVar6, param_3 <= puVar6)) break;
    }
  }
joined_r0x0046dcc4:
  do {
    puVar5 = puVar4;
    if (param_3 <= puVar3) {
joined_r0x0046dd3c:
      while (param_2 < puVar4) {
        puVar5 = puVar5 + -1;
        piVar1 = *(int **)*puVar7;
        fVar8 = (float10)(**(code **)(**(int **)*puVar5 + 0x10))();
        fVar9 = (float10)(**(code **)(*piVar1 + 0x10))();
        puVar6 = local_c;
        if ((float10)(float)fVar8 < fVar9 - (float10)DAT_00aaa620) {
          piVar1 = *(int **)*puVar5;
          fVar8 = (float10)(**(code **)(**(int **)*puVar7 + 0x10))();
          fVar9 = (float10)(**(code **)(*piVar1 + 0x10))();
          puVar4 = puStack_8;
          if (fVar9 - (float10)DAT_00aaa620 <= (float10)(float)fVar8) break;
          uVar2 = puVar7[-1];
          puVar7 = puVar7 + -1;
          *puVar7 = *puVar5;
          *puVar5 = uVar2;
        }
        puStack_8 = puStack_8 + -1;
        puVar4 = puStack_8;
      }
      if (puVar4 == param_2) {
        if (puVar3 == param_3) {
          *param_1 = (uint)puVar7;
          param_1[1] = (uint)puVar6;
          return;
        }
        if (puVar6 != puVar3) {
          uVar2 = *puVar7;
          *puVar7 = *puVar6;
          *puVar6 = uVar2;
        }
        uVar2 = *puVar7;
        *puVar7 = *puVar3;
        puVar6 = puVar6 + 1;
        *puVar3 = uVar2;
        puVar3 = puVar3 + 1;
        local_c = puVar6;
        puVar7 = puVar7 + 1;
      }
      else {
        puVar4 = puVar4 + -1;
        puStack_8 = puVar4;
        if (puVar3 == param_3) {
          puVar7 = puVar7 + -1;
          if (puVar4 != puVar7) {
            uVar2 = *puVar4;
            *puVar4 = *puVar7;
            *puVar7 = uVar2;
          }
          puVar5 = puVar6 + -1;
          uVar2 = *puVar7;
          puVar6 = puVar6 + -1;
          *puVar7 = *puVar5;
          *puVar6 = uVar2;
          local_c = puVar6;
        }
        else {
          uVar2 = *puVar3;
          *puVar3 = *puVar4;
          *puVar4 = uVar2;
          puVar3 = puVar3 + 1;
        }
      }
      goto joined_r0x0046dcc4;
    }
    piVar1 = *(int **)*puVar3;
    fVar8 = (float10)(**(code **)(**(int **)*puVar7 + 0x10))();
    fVar9 = (float10)(**(code **)(*piVar1 + 0x10))();
    puVar4 = puStack_8;
    if ((float10)(float)fVar8 < fVar9 - (float10)DAT_00aaa620) {
      piVar1 = *(int **)*puVar7;
      fVar8 = (float10)(**(code **)(**(int **)*puVar3 + 0x10))();
      fVar9 = (float10)(**(code **)(*piVar1 + 0x10))();
      puVar5 = puStack_8;
      local_c = puVar6;
      if (fVar9 - (float10)DAT_00aaa620 <= (float10)(float)fVar8) goto joined_r0x0046dd3c;
      uVar2 = *puVar6;
      *puVar6 = *puVar3;
      puVar6 = puVar6 + 1;
      *puVar3 = uVar2;
    }
    puVar3 = puVar3 + 1;
    local_c = puVar6;
  } while( true );
}
```
