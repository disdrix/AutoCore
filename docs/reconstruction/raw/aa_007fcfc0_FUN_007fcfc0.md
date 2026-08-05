# Raw capture: FUN_007fcfc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fcfc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fcfc0` |
| **Canonical name** | `FUN_007fcfc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __fastcall FUN_007fcfc0(int param_1)

{
  int *piVar1;
  uint in_EAX;
  void *pvVar2;
  int iVar3;
  int unaff_EDI;
  
  pvVar2 = CNDHash_LookupByKey(*(void **)(*(int *)(unaff_EDI + 0xe98) + 0x548),in_EAX);
  if (pvVar2 != (void *)0x0) {
    if (*(int *)((int)pvVar2 + 0x158) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)((int)pvVar2 + 0x15c) - *(int *)((int)pvVar2 + 0x158) >> 2;
    }
    if (param_1 < iVar3) {
      piVar1 = *(int **)(*(int *)((int)pvVar2 + 0x158) + param_1 * 4);
      iVar3 = (**(code **)(*piVar1 + 0x50))();
      if (iVar3 == 0xc) {
        iVar3 = __RTDynamicCast(piVar1,0,&CVOGObjectiveRequirement::RTTI_Type_Descriptor,
                                &CVOGObjectiveRequirement_TimePlayed::RTTI_Type_Descriptor,0);
        if (iVar3 != 0) {
          FUN_007fb690(0,(float)*(int *)(iVar3 + 0x10),*(undefined4 *)(iVar3 + 0x18),0,DAT_00afdf0c,
                       0,0,0);
          return 1;
        }
      }
    }
  }
  return 0;
}
```
