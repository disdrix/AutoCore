# Raw capture: FUN_004ce8d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ce8d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004ce8d0` |
| **Canonical name** | `FUN_004ce8d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_004ce8d0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 local_4;
  
  local_4 = 0;
  iVar1 = FUN_004bae00(0,&local_4);
  while (iVar1 != 0) {
    if (*(int *)(*(int *)(iVar1 + 0xa8) + 0x38) == 0x38) {
      piVar2 = (int *)__RTDynamicCast(iVar1,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                      &CVOGTrigger::RTTI_Type_Descriptor,0);
      (**(code **)(*piVar2 + 0x7c))();
    }
    iVar1 = FUN_004bae00(0,&local_4);
  }
  return;
}
```
