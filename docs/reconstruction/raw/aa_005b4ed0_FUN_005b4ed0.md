# Raw capture: FUN_005b4ed0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b4ed0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005b4ed0` |
| **Canonical name** | `FUN_005b4ed0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005b4ed0(int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_0068a4d0(*(undefined4 *)(param_1 + 0x50),2,0xffffffff,0xffffffff,0xffffffff);
  if (g_flZero < *(float *)(*(int *)(param_1 + 0x50) + 0x74)) {
    FUN_005b4a30();
    (**(code **)(*DAT_00d1f610 + 0x1c))
              (DAT_00d1f610,0x18,(int)ROUND(*(float *)(*(int *)(param_1 + 0x50) + 0x74)));
    iVar1 = *(int *)(param_1 + 0x70);
    if (((iVar1 != 0) && (iVar2 = *(int *)(*(int *)(param_1 + 0x50) + 0x3c), -1 < iVar2)) &&
       (*(short *)(iVar1 + iVar2 * 2) != 0)) {
      (**(code **)(*DAT_00b05340 + 0x148))
                (DAT_00b05340,5,0,0,*(undefined2 *)(*(int *)(param_1 + 0x50) + 0x4c),0,
                 *(ushort *)(iVar1 + *(int *)(*(int *)(param_1 + 0x50) + 0x3c) * 2) - 2);
    }
  }
  return;
}
```
