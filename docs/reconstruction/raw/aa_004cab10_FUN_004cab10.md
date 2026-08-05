# Raw capture: FUN_004cab10

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cab10` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cab10` |
| **Canonical name** | `FUN_004cab10` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004cab10(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_2 != 0) {
    FUN_005cbcb0(param_2,param_3,param_4);
    *(undefined4 *)(param_1 + -0x3d8) = *(undefined4 *)(param_2 + 0xd8);
    *(undefined4 *)(param_1 + -0x3a0) = *(undefined4 *)(param_2 + 0x110);
    *(undefined4 *)(param_1 + -0x2f0) = *(undefined4 *)(param_2 + 0xf8);
    *(undefined4 *)(param_1 + -0x2ec) = *(undefined4 *)(param_2 + 0xfc);
    *(bool *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4b4 + param_1) =
         (*(uint *)(param_2 + 0x130) & *(uint *)(param_2 + 0x134)) != 0xffffffff;
    iVar1 = *(int *)(*(int *)(param_1 + -0x4fc) + 4);
    *(undefined4 *)(iVar1 + -0x4bc + param_1) = *(undefined4 *)(param_2 + 0x130);
    *(undefined4 *)(iVar1 + -0x4b8 + param_1) = *(undefined4 *)(param_2 + 0x134);
    iVar2 = *(int *)(param_2 + 0x114);
    if (iVar2 < 2) {
      iVar2 = 1;
    }
    *(int *)(param_1 + -0x3b0) = iVar2;
    if (*(char *)(param_2 + 0x126) != '\0') {
      *(undefined1 *)(param_1 + -0x1f5) = 1;
    }
    CVOGWaypoint_InitFromSpawn
              (*(int *)(param_2 + 0x118),*(int *)(param_2 + 0x118) >> 0x1f,
               *(undefined4 *)(param_2 + 0x11c),*(undefined4 *)(param_2 + 0x120),1,
               CONCAT31((int3)((uint)iVar1 >> 8),*(undefined1 *)(param_2 + 0x124)));
    FUN_004ca910(param_2 + 0xe0,*(char *)(param_2 + 0xf0) == '\0');
  }
  return;
}
```
