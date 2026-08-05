# Raw capture: hkVehicleFramework_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064cd30` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0064cd30` |
| **Canonical name** | `hkVehicleFramework_ctor` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall hkVehicleFramework_ctor(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  FUN_00636b30(param_2);
  *param_1 = &PTR_FUN_009e4a40;
  param_1[0xe] = 0;
  param_1[0x7d] = 0;
  param_1[0x7c] = &PTR_FUN_009e4a38;
  param_1[0xb7] = 0;
  param_1[0xb3] = 0;
  param_1[0xb4] = 0;
  param_1[0xb5] = 0;
  param_1[0xb8] = 0;
  param_1[0xb9] = 0;
  param_1[0xbe] = 0;
  param_1[0xba] = 0;
  param_1[0xbb] = 0;
  param_1[0xbc] = 0;
  param_1[0xbf] = 0;
  param_1[0xc0] = 0;
  piVar1 = param_1 + 0xcc;
  *piVar1 = 0;
  param_1[0xcd] = 0;
  param_1[0xce] = 0x80000000;
  hkVehicleFramework_initFromDescriptor(param_2);
  iVar2 = *(int *)(param_2 + 0x54);
  if ((int)(param_1[0xce] & 0x7fffffff) < iVar2) {
    iVar3 = (param_1[0xce] & 0x7fffffff) * 2;
    if (iVar3 <= iVar2) {
      iVar3 = iVar2;
    }
    FUN_005b3300(piVar1,iVar3,4);
  }
  iVar3 = 0;
  param_1[0xcd] = iVar2;
  if (0 < *(int *)(param_2 + 0x54)) {
    do {
      *(undefined4 *)(*piVar1 + iVar3 * 4) = *(undefined4 *)(*(int *)(param_2 + 0x50) + iVar3 * 4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_2 + 0x54));
  }
  param_1[0x7e] = *(undefined4 *)(*(int *)(param_2 + 4) + 8);
  *(short *)(param_1[0xc] + 6) = *(short *)(param_1[0xc] + 6) + 1;
  return param_1;
}
```
