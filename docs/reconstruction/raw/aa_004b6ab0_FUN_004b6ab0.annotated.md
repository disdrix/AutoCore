# Annotated low-level: FUN_004b6ab0

| Field | Value |
|---|---|
| Stable ID | `aa_004b6ab0` |
| VA | `0x004b6ab0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004b6ab0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004b6ab0(int param_1,char param_2,char param_3)

{
  float fVar1;
  undefined4 *puVar2;
  uint3 uVar3;
  char cVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined2 extraout_var;
  undefined2 uVar11;
  undefined4 uVar9;
  char *pcVar10;
  int *piVar12;
  float local_168;
  undefined1 local_160 [4];
  undefined1 *local_15c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a1529;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_3 != '\0') {
    ExceptionList = &local_c;
    FUN_00764030();
    piVar12 = (int *)**(int **)(param_1 + 0x204);
    local_4 = 0;
    if (piVar12 != *(int **)(param_1 + 0x204)) {
      do {
        pcVar10 = (char *)(piVar12[2] + 0x33d);
        pcVar5 = pcVar10;
        do {
          cVar4 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar4 != '\0');
        if (3 < (uint)((int)pcVar5 - (piVar12[2] + 0x33e))) {
          FUN_00989e00(local_160,pcVar10);
          cVar4 = FUN_0075d610(local_160);
          if (cVar4 == '\0') {
            FUN_007a4480(0xffffffff,"PreLoading FX %s",piVar12[2] + 0x33d);
            FUN_00764830(local_160);
          }
        }
        piVar12 = (int *)*piVar12;
      } while (piVar12 != (int *)*(int *)(param_1 + 0x204));
    }
    iVar6 = Client_GetMissionCompleteAudioTable();
    if ((*(char *)(iVar6 + 600) != '\0') &&
       (piVar12 = (int *)**(int **)(param_1 + 0x1ec), piVar12 != *(int **)(param_1 + 0x1ec))) {
      do {
        pcVar10 = (char *)piVar12[2];
        pcVar5 = pcVar10;
        do {
          cVar4 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar4 != '\0');
        if (pcVar5 == pcVar10 + 1) {
          FUN_007a4480(0,"Missing sound! Name:%s, Event:%d",pcVar10,*(undefined4 *)(param_1 + 0x28))
          ;
        }
        piVar12 = (int *)*piVar12;
      } while (piVar12 != (int *)*(int *)(param_1 + 0x1ec));
    }
    local_4 = 0xffffffff;
    FUN_00763f60();
  }
  if ((param_2 != '\0') &&
     (piVar12 = (int *)**(int **)(param_1 + 0x204), piVar12 != *(int **)(param_1 + 0x204))) {
    do {
      iVar6 = piVar12[2];
      pcVar10 = (char *)(iVar6 + 0x2be);
      pcVar5 = pcVar10;
      do {
        cVar4 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar4 != '\0');
      if (3 < (uint)((int)pcVar5 - (iVar6 + 0x2bf))) {
        FUN_007a4480(0xffffffff,"PreLoading RB %s\n",piVar12[2] + 0x2be);
        iVar7 = *(int *)(iVar6 + 0x28);
        local_168 = g_flOne;
        if (((iVar7 != 0) && ((*(byte *)(iVar7 + 0x3c9) & 2) != 0)) &&
           (g_flZero < *(float *)(iVar6 + 0x8d8))) {
          local_168 = *(float *)(iVar7 + 800) * *(float *)(iVar6 + 0x8d8);
        }
        iVar7 = piVar12[2];
        iVar7 = FUN_00590cb0(iVar7 + 0x2be,local_168,*(undefined4 *)(iVar7 + 0xb4),
                             *(undefined4 *)(iVar7 + 0xb8),*(undefined4 *)(iVar6 + 0x284));
        if (iVar7 == 0) {
          puVar8 = operator_new(0x180);
          local_4 = 1;
          local_15c = puVar8;
          if (puVar8 == (undefined1 *)0x0) {
            puVar8 = (undefined1 *)0x0;
            uVar11 = 0;
          }
          else {
            FUN_004ebe50();
            fVar1 = g_flOne;
            *puVar8 = 0;
            *(float *)(puVar8 + 0x170) = fVar1;
            uVar11 = extraout_var;
          }
          *(undefined4 *)(puVar8 + 0x108) = 0;
          fVar1 = *(float *)(iVar6 + 0x284);
          uVar3 = CONCAT21(uVar11,(fVar1 == g_flZero) << 6 | (NAN(fVar1) || NAN(g_flZero)) << 2 | 2U
                                  | fVar1 < g_flZero);
          local_4 = 0xffffffff;
          if (fVar1 == g_flZero) {
            iVar7 = CONCAT31(uVar3,1);
          }
          else {
            iVar7 = (uint)uVar3 << 8;
          }
          uVar9 = FUN_004ee080(pcVar10,*(undefined4 *)(iVar6 + 0x284),local_168,puVar8 + 0x100,1,
                               iVar7,1,0,0x3f800000,0x3f000000,0,0);
          *(undefined4 *)(puVar8 + 0x108) = uVar9;
          *(float *)(puVar8 + 0x170) = local_168;
          iVar6 = (int)puVar8 - (int)pcVar10;
          do {
            cVar4 = *pcVar10;
            pcVar10[iVar6] = cVar4;
            pcVar10 = pcVar10 + 1;
          } while (cVar4 != '\0');
          if (*(int *)(puVar8 + 0x108) == 0) {
LAB_004b6db0:
            FUN_004ebee0();
                    /* WARNING: Subroutine does not return */
            operator_delete(puVar8);
          }
          cVar4 = FUN_00590190(puVar8);
          if (cVar4 == '\0') {
            puVar2 = *(undefined4 **)(puVar8 + 0x108);
            *(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1;
            if (*(short *)((int)puVar2 + 6) == 0) {
              (**(code **)*puVar2)(1);
            }
            goto LAB_004b6db0;
          }
        }
      }
      piVar12 = (int *)*piVar12;
    } while (piVar12 != (int *)*(int *)(param_1 + 0x204));
  }
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
