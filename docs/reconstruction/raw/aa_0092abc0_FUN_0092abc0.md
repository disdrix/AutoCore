# Raw capture: FUN_0092abc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092abc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0092abc0` |
| **Canonical name** | `FUN_0092abc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0092abc0(float *param_1,int *param_2,float *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *unaff_EDI;
  float fVar5;
  float fVar6;
  float fVar7;
  int local_20;
  int *piStack_1c;
  int *local_18;
  undefined4 local_14 [4];
  
  iVar2 = *(int *)(*(int *)(*unaff_EDI + 0xd34) + 0x18);
  iVar2 = *(int *)(*(int *)(*(int *)(iVar2 + 0x10) + (*(uint *)(iVar2 + 8) & 0xe) * 4) + 4);
  if (iVar2 == 0) {
LAB_0092ac09:
    local_20 = 0;
  }
  else {
    do {
      if (*(int *)(iVar2 + 0x10) == 0xe) {
        if (iVar2 == 0) goto LAB_0092ac09;
        local_20 = *(int *)(iVar2 + 8);
        goto LAB_0092ac1a;
      }
      iVar2 = *(int *)(iVar2 + 0xc);
    } while (iVar2 != 0);
    local_20 = 0;
  }
LAB_0092ac1a:
  if (local_20 == 0) {
    return 0;
  }
  local_14[0] = 0;
  local_18 = (int *)0x0;
  FUN_004294f0();
  iVar2 = FUN_004022a0(local_14,&local_18);
  while (iVar2 == 0) {
    iVar2 = (**(code **)(*local_18 + 0x1d4))();
    iVar4 = 0;
    if (0 < unaff_EDI[0x20]) {
      piStack_1c = unaff_EDI + 0x21;
      do {
        if ((((*(int *)(iVar2 + 0x14c) == *piStack_1c) && (cVar1 = FUN_005134e0(), cVar1 == '\0'))
            && ((*(uint *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0x180 + iVar2) >> 3 & 1) == 0)) &&
           (((unaff_EDI[0x42] == -1 ||
             (iVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x27c))
                                (), unaff_EDI[0x42] <= iVar3)) &&
            ((unaff_EDI[0x43] == -1 ||
             (iVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x27c))
                                (), iVar3 <= unaff_EDI[0x43])))))) {
          (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x144))();
          iVar3 = *(int *)(*(int *)(iVar2 + 4) + 4);
          fVar6 = *(float *)(iVar3 + 0x84 + iVar2) - *param_1;
          fVar5 = *(float *)(iVar3 + 0x8c + iVar2) - param_1[2];
          fVar7 = *(float *)(iVar3 + 0x88 + iVar2) - param_1[1];
          fVar5 = fVar5 * fVar5 + fVar6 * fVar6 + fVar7 * fVar7;
          if (fVar5 < *param_3) {
            *param_3 = fVar5;
            *param_2 = *(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2;
          }
        }
        piStack_1c = piStack_1c + 1;
        iVar4 = iVar4 + 1;
      } while (iVar4 < unaff_EDI[0x20]);
    }
    iVar2 = FUN_004022a0(local_14,&local_18);
  }
  if (*(char *)(local_20 + 0x28) != '\0') {
    *(undefined1 *)(local_20 + 0x28) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(local_20 + 4));
  }
  return 1;
}
```
