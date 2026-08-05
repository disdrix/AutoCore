# Raw capture: FUN_0071ddd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071ddd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0071ddd0` |
| **Canonical name** | `FUN_0071ddd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_0071ddd0(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  
  puVar1 = param_2;
  FUN_0044cbd0();
  if (*(int *)(param_1 + 0x14) == 0) {
    param_2 = (undefined4 *)((uint)param_2._1_3_ << 8);
  }
  else {
    iVar3 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14);
    param_2 = (undefined4 *)
              CONCAT31(param_2._1_3_,
                       ((char)(iVar3 / 0xc) + (char)(iVar3 >> 0x1f)) -
                       (char)((longlong)iVar3 * 0x2aaaaaab >> 0x3f));
  }
  FUN_0044cbd0();
  puVar4 = *(undefined1 **)(param_1 + 0x14);
  if (puVar4 != *(undefined1 **)(param_1 + 0x18)) {
    do {
      if (puVar1[7] == 0) {
        uVar7 = 1;
        puVar6 = &param_2;
        param_2 = (undefined4 *)CONCAT31(param_2._1_3_,*puVar4);
      }
      else {
        uVar2 = FUN_00767160(&DAT_00a9d718,*puVar4);
        puVar1[1] = puVar1[1] | uVar2;
        uVar7 = 2;
        puVar1[8] = 0;
        puVar6 = (undefined4 *)&DAT_00a97b84;
      }
      uVar2 = (**(code **)(*(int *)*puVar1 + 0x18))(puVar6,uVar7);
      puVar1[1] = puVar1[1] | uVar2;
      if (puVar1[7] == 0) {
        uVar7 = 4;
        puVar5 = &stack0xfffffffc;
      }
      else {
        uVar2 = FUN_00767160(&DAT_00a9d718,*(undefined4 *)(puVar4 + 4));
        puVar1[1] = puVar1[1] | uVar2;
        uVar7 = 2;
        puVar1[8] = 0;
        puVar5 = &DAT_00a97b84;
      }
      uVar2 = (**(code **)(*(int *)*puVar1 + 0x18))(puVar5,uVar7);
      puVar1[1] = puVar1[1] | uVar2;
      FUN_00718d10(puVar1,*(undefined4 *)(puVar4 + 8));
      puVar4 = puVar4 + 0xc;
    } while (puVar4 != *(undefined1 **)(param_1 + 0x18));
  }
  return 0;
}
```
