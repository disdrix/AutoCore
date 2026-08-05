# Raw capture: hkDefaultSuspension_update

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064de50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0064de50` |
| **Canonical name** | `hkDefaultSuspension_update` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall hkDefaultSuspension_update(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 0xc);
  fVar6 = *(float *)(*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30) + 0x3c) + 0x2c);
  if (fVar6 == 0.0) {
    fVar6 = 0.0;
  }
  else {
    fVar6 = g_flOne / fVar6;
  }
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x40)) {
    iVar5 = 0;
    do {
      iVar2 = *(int *)(iVar1 + 0x80) + iVar5;
      if (*(char *)(iVar2 + 0x80) == '\0') {
        *(undefined4 *)(*(int *)(param_1 + 0x34) + iVar4 * 4) = 0;
      }
      else {
        if (0.0 <= *(float *)(iVar2 + 0xb4)) {
          iVar3 = *(int *)(param_1 + 0x5c);
        }
        else {
          iVar3 = *(int *)(param_1 + 0x50);
        }
        *(float *)(*(int *)(param_1 + 0x34) + iVar4 * 4) =
             ((*(float *)(*(int *)(param_1 + 0x28) + iVar4 * 4) - *(float *)(iVar2 + 0xb0)) *
              *(float *)(*(int *)(param_1 + 0x44) + iVar4 * 4) * *(float *)(iVar2 + 0xac) -
             *(float *)(iVar3 + iVar4 * 4) * *(float *)(iVar2 + 0xb4)) * fVar6;
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0xc0;
    } while (iVar4 < *(int *)(param_1 + 0x40));
  }
  return;
}
```
