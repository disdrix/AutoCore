# Raw capture: FUN_004f6ee0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f6ee0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004f6ee0` |
| **Canonical name** | `FUN_004f6ee0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004f6ee0(int param_1)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  **(undefined1 **)(param_1 + 0x1a4) = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x3c);
  iVar2 = *(int *)(param_1 + 0x1a4);
  *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar1 + 0xb0);
  *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar1 + 0xb4);
  *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(iVar1 + 0xb8);
  *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar1 + 0xbc);
  iVar1 = *(int *)(param_1 + 0x1a4);
  fVar3 = (float10)FUN_004cd220(*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x18));
  *(float *)(*(int *)(param_1 + 0x1a4) + 0x20) = (float)((float10)*(float *)(iVar1 + 0x14) - fVar3);
  iVar1 = *(int *)(param_1 + 0x1a4);
  *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(iVar1 + 0x18);
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x3c);
  iVar2 = *(int *)(param_1 + 0x1a4);
  *(undefined4 *)(iVar2 + 0x30) = *(undefined4 *)(iVar1 + 0x30);
  *(undefined4 *)(iVar2 + 0x34) = *(undefined4 *)(iVar1 + 0x34);
  *(undefined4 *)(iVar2 + 0x38) = *(undefined4 *)(iVar1 + 0x38);
  *(undefined4 *)(iVar2 + 0x3c) = *(undefined4 *)(iVar1 + 0x3c);
  *(undefined4 *)(*(int *)(param_1 + 0x1a4) + 0x80) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x1a4) + 0x7c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x1a4) + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x118) = 1;
  return;
}
```
