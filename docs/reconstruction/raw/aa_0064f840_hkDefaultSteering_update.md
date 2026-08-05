# Raw capture: hkDefaultSteering_update

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064f840` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0064f840` |
| **Canonical name** | `hkDefaultSteering_update` |
| **System** | input-drive-control |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall hkDefaultSteering_update(int param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  iVar1 = *(int *)(param_1 + 8);
  fVar2 = *(float *)(*(int *)(iVar1 + 0x14) + 0x14) * *(float *)(param_1 + 0x24);
  FUN_005d6ae0(*(int *)(*(int *)(iVar1 + 0x30) + 0x3c) + 0x80,*(int *)(iVar1 + 0x10) + 0x10);
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30) + 0x3c);
  fVar3 = *(float *)(iVar1 + 0x48) * local_18 + *(float *)(iVar1 + 0x44) * local_1c +
          *(float *)(iVar1 + 0x40) * local_20;
  if (*(float *)(param_1 + 0x28) <= fVar3) {
    fVar3 = *(float *)(param_1 + 0x28) / fVar3;
    fVar2 = fVar3 * fVar3 * fVar2;
  }
  iVar1 = 0;
  *(float *)(param_1 + 0x10) = fVar2;
  if (0 < *(int *)(param_1 + 0x30)) {
    do {
      if (*(char *)(iVar1 + *(int *)(param_1 + 0x2c)) == '\0') {
        *(undefined4 *)(*(int *)(param_1 + 0x14) + iVar1 * 4) = 0;
      }
      else {
        *(undefined4 *)(*(int *)(param_1 + 0x14) + iVar1 * 4) = *(undefined4 *)(param_1 + 0x10);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x30));
  }
  return;
}
```
