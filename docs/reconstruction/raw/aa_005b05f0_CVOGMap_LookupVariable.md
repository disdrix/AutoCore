# Raw capture: CVOGMap_LookupVariable

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b05f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005b05f0` |
| **Canonical name** | `CVOGMap_LookupVariable` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall CVOGMap_LookupVariable(int param_1,uint param_2,undefined4 *param_3)



{

  int iVar1;

  undefined4 uVar2;

  

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x10) + (*(uint *)(param_1 + 8) & param_2) * 4) + 4);

  if (iVar1 == 0) {

LAB_005b061a:

    iVar1 = 0;

  }

  else {

    do {

      if (param_2 == *(uint *)(iVar1 + 0x10)) {

        if (iVar1 == 0) goto LAB_005b061a;

        iVar1 = *(int *)(iVar1 + 8);

        goto LAB_005b0621;

      }

      iVar1 = *(int *)(iVar1 + 0xc);

    } while (iVar1 != 0);

    iVar1 = 0;

  }

LAB_005b0621:

  if (iVar1 == 0) {

    return 0;

  }

  if (*(char *)(iVar1 + 0x40) == '\0') {

    *param_3 = *(undefined4 *)(iVar1 + 0x48);

    return CONCAT31((int3)((uint)iVar1 >> 8),1);

  }

  uVar2 = CVOGVariable_EvaluateComputed();

  return uVar2;

}
```
