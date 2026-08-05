# Raw capture: InventoryGrid_CountItemsByCbid

| Field | Value |
|---|---|
| **Stable ID** | `aa_005711c0` |
| **VA** | `0x005711c0` |
| **Canonical name** | `InventoryGrid_CountItemsByCbid` |
| **Prior** | `FUN_005711c0` |
| **Capture** | 2026-07-29 Ghidra `batch_decompile` |
| **Integrity** | Do not overwrite raw body; append versioned sections only |

## Raw pseudocode

```c
int __thiscall FUN_005711c0(int param_1,int param_2,char param_3)

{
  int iVar1;
  int iVar2;
  int *local_8;
  undefined4 local_4;
  
  iVar2 = 0;
  local_4 = 0;
  FUN_004294f0();
  iVar1 = FUN_004022a0(&local_4,&local_8);
  while (iVar1 == 0) {
    if (((local_8 != (int *)0x0) && (*(int *)(local_8[0x2a] + 0x34) == param_2)) &&
       ((param_3 != '\0' || (((uint)local_8[0x5f] >> 0x13 & 1) == 0)))) {
      iVar1 = (**(code **)(*local_8 + 0x25c))();
      iVar2 = iVar2 + iVar1;
    }
    iVar1 = FUN_004022a0(&local_4,&local_8);
  }
  if (*(char *)(param_1 + 0x54) != '\0') {
    *(undefined1 *)(param_1 + 0x54) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  }
  return iVar2;
}
```

Legacy scaffold also at `aa_005711c0_FUN_005711c0.md`.
