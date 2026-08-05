# Raw capture: FUN_005aa5c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005aa5c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005aa5c0` |
| **Canonical name** | `FUN_005aa5c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x005aa654) */

void __fastcall FUN_005aa5c0(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  char local_80 [128];
  
  uVar2 = *(uint *)(*(int *)(param_1 + 8) + 0xfc);
  iVar3 = FUN_00541a80();
  iVar3 = *(int *)(*(int *)(*(int *)(iVar3 + 0x10) + (*(uint *)(iVar3 + 8) & uVar2) * 4) + 4);
  if (iVar3 == 0) {
LAB_005aa604:
    iVar3 = 0;
  }
  else {
    do {
      if (uVar2 == *(uint *)(iVar3 + 0x10)) {
        if (iVar3 == 0) goto LAB_005aa604;
        iVar3 = *(int *)(iVar3 + 8);
        goto LAB_005aa60b;
      }
      iVar3 = *(int *)(iVar3 + 0xc);
    } while (iVar3 != 0);
    iVar3 = 0;
  }
LAB_005aa60b:
  if (iVar3 != 0) {
    pcVar5 = local_80;
    uVar4 = (*(code *)PTR_FUN_00af8c9c)();
    FUN_00403450(iVar3 + 0xb4,uVar4);
    param_1 = param_1 - (int)pcVar5;
    do {
      cVar1 = *pcVar5;
      pcVar5[param_1 + 0xc] = cVar1;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
  }
  return;
}
```
