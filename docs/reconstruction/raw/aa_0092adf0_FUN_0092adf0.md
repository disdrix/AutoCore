# Raw capture: FUN_0092adf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092adf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0092adf0` |
| **Canonical name** | `FUN_0092adf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0092adf0(float *param_1,undefined4 *param_2,float *param_3)

{
  int *piVar1;
  int iVar2;
  int *unaff_EDI;
  float fVar3;
  int *local_1c;
  int *local_18;
  undefined4 local_14 [4];
  
  local_18 = (int *)0x0;
  local_14[0] = 0;
  FUN_004294f0();
  iVar2 = FUN_004022a0(local_14,&local_18);
  piVar1 = local_18;
  while (local_18 = piVar1, iVar2 == 0) {
    if (piVar1 != (int *)0x0) {
      iVar2 = *(int *)(*(int *)(*unaff_EDI + 0xe98) + 0x250);
      if (iVar2 != 0) {
        iVar2 = *(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2;
      }
      if (((piVar1[0x2b] != iVar2) && (iVar2 = FUN_00571010(piVar1[0x58],piVar1[0x59]), iVar2 == 0))
         && (iVar2 = 0, 0 < unaff_EDI[10])) {
        local_1c = unaff_EDI + 0xb;
        do {
          if (*local_1c == *(int *)(piVar1[0x2a] + 0x34)) {
            (**(code **)(*piVar1 + 0x144))();
            fVar3 = ((float)piVar1[0x22] - param_1[2]) * ((float)piVar1[0x22] - param_1[2]) +
                    ((float)piVar1[0x21] - param_1[1]) * ((float)piVar1[0x21] - param_1[1]) +
                    ((float)piVar1[0x20] - *param_1) * ((float)piVar1[0x20] - *param_1);
            if (fVar3 < *param_3) {
              *param_3 = fVar3;
              *param_2 = piVar1;
            }
          }
          local_1c = local_1c + 1;
          iVar2 = iVar2 + 1;
        } while (iVar2 < unaff_EDI[10]);
      }
    }
    iVar2 = FUN_004022a0(local_14,&local_18);
    piVar1 = local_18;
  }
  iVar2 = *(int *)(*(int *)(*unaff_EDI + 0xd34) + 0x20);
  if (*(char *)(iVar2 + 0x28) != '\0') {
    *(undefined1 *)(iVar2 + 0x28) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 4));
  }
  return 1;
}
```
