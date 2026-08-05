# Raw capture: FUN_0040fde0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040fde0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0040fde0` |
| **Canonical name** | `FUN_0040fde0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0040fde0(uint param_1)

{
  size_t sVar1;
  uint uVar2;
  undefined4 *_Dst;
  void *pvVar3;
  uint uVar4;
  undefined4 *puVar5;
  int unaff_EBX;
  int iVar6;
  undefined4 *puVar7;
  
  uVar2 = *(uint *)(unaff_EBX + 8);
  if (0xfffffff - uVar2 < param_1) {
    uVar2 = FUN_0040ff30();
  }
  uVar4 = uVar2 >> 1;
  if (uVar4 < 8) {
    uVar4 = 8;
  }
  if ((param_1 < uVar4) && (uVar2 <= 0xfffffff - uVar4)) {
    param_1 = uVar4;
  }
  uVar4 = *(uint *)(unaff_EBX + 0xc) >> 2;
  _Dst = operator_new((uVar2 + param_1) * 4);
  iVar6 = uVar4 * 4;
  pvVar3 = (void *)(iVar6 + *(int *)(unaff_EBX + 4));
  sVar1 = ((*(int *)(unaff_EBX + 8) * 4 - (int)pvVar3) + *(int *)(unaff_EBX + 4) >> 2) * 4;
  pvVar3 = memmove(_Dst + uVar4,pvVar3,sVar1);
  pvVar3 = (void *)((int)pvVar3 + sVar1);
  if (param_1 < uVar4) {
    memmove(pvVar3,*(void **)(unaff_EBX + 4),((int)(param_1 * 4) >> 2) * 4);
    pvVar3 = (void *)(*(int *)(unaff_EBX + 4) + param_1 * 4);
    sVar1 = ((iVar6 - (int)pvVar3) + *(int *)(unaff_EBX + 4) >> 2) * 4;
    pvVar3 = memmove(_Dst,pvVar3,sVar1);
    puVar7 = (undefined4 *)((int)pvVar3 + sVar1);
    uVar4 = param_1;
  }
  else {
    sVar1 = (iVar6 >> 2) * 4;
    iVar6 = param_1 - uVar4;
    pvVar3 = memmove(pvVar3,*(void **)(unaff_EBX + 4),sVar1);
    puVar5 = (undefined4 *)((int)pvVar3 + sVar1);
    puVar7 = _Dst;
    if (iVar6 != 0) {
      for (; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
    }
  }
  if (uVar4 != 0) {
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
  }
  if (*(void **)(unaff_EBX + 4) == (void *)0x0) {
    *(int *)(unaff_EBX + 8) = *(int *)(unaff_EBX + 8) + param_1;
    *(undefined4 **)(unaff_EBX + 4) = _Dst;
    return;
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(*(void **)(unaff_EBX + 4));
}
```
