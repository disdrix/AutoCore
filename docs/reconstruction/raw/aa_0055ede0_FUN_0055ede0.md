# Raw capture: FUN_0055ede0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055ede0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0055ede0` |
| **Canonical name** | `FUN_0055ede0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0055ede0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *unaff_ESI;
  int *piVar4;
  int local_c;
  int local_8;
  
  piVar3 = *(int **)(param_1 + 8);
  if (piVar3 != piVar3 + *(int *)(param_1 + 0xc)) {
    do {
      iVar1 = *(int *)(*piVar3 + 0x5c);
      piVar4 = (int *)(*piVar3 + 0x58);
      local_c = 0;
      if (0 < iVar1) {
        do {
          iVar2 = (**(code **)(**(int **)(*piVar4 + local_c * 4) + 0x20))();
          if (iVar2 != 0xb) {
            iVar2 = *piVar4;
            if (unaff_ESI[1] == (unaff_ESI[2] & 0x7fffffffU)) {
              FUN_005b3370();
            }
            *(undefined4 *)(*unaff_ESI + unaff_ESI[1] * 4) = *(undefined4 *)(iVar2 + local_c * 4);
            unaff_ESI[1] = unaff_ESI[1] + 1;
          }
          local_c = local_c + 1;
        } while (local_c < iVar1);
      }
      piVar3 = piVar3 + 1;
    } while (piVar3 != (int *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0xc) * 4));
  }
  piVar3 = *(int **)(param_1 + 0x14);
  if (piVar3 != piVar3 + *(int *)(param_1 + 0x18)) {
    do {
      iVar1 = *(int *)(*piVar3 + 0x5c);
      piVar4 = (int *)(*piVar3 + 0x58);
      local_8 = 0;
      if (0 < iVar1) {
        do {
          iVar2 = (**(code **)(**(int **)(*piVar4 + local_8 * 4) + 0x20))();
          if (iVar2 != 0xb) {
            iVar2 = *piVar4;
            if (unaff_ESI[1] == (unaff_ESI[2] & 0x7fffffffU)) {
              FUN_005b3370();
            }
            *(undefined4 *)(*unaff_ESI + unaff_ESI[1] * 4) = *(undefined4 *)(iVar2 + local_8 * 4);
            unaff_ESI[1] = unaff_ESI[1] + 1;
          }
          local_8 = local_8 + 1;
        } while (local_8 < iVar1);
      }
      piVar3 = piVar3 + 1;
    } while (piVar3 != (int *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x18) * 4));
  }
  return;
}
```
