# Raw capture: FUN_0071eec0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071eec0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0071eec0` |
| **Canonical name** | `FUN_0071eec0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
uint __fastcall FUN_0071eec0(int param_1)

{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  undefined1 *unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0x28) = *(undefined4 *)(param_1 + 0x28);
  iVar1 = *(int *)(param_1 + 0x20);
  *(int *)(unaff_ESI + 0x34) = iVar1 >> 0x1f;
  *(int *)(unaff_ESI + 0x30) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x38) = 0;
  *(undefined4 *)(unaff_ESI + 0x3c) = 0;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *(undefined4 *)(unaff_ESI + 0xc) = 0;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  *(undefined2 *)(unaff_ESI + 0x18) = 0;
  *(undefined2 *)(unaff_ESI + 0x18) = 0x12;
  *(undefined2 *)(unaff_ESI + 10) = *(undefined2 *)(param_1 + 10);
  *(undefined2 *)(unaff_ESI + 0x16) = 0x10;
  *(undefined4 *)(unaff_ESI + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(uint *)(unaff_ESI + 0x10) = (uint)*(ushort *)(unaff_ESI + 10) * *(int *)(param_1 + 0xc) * 2;
  *(short *)(unaff_ESI + 0x14) = *(short *)(param_1 + 10) * 2;
  *(undefined2 *)(unaff_ESI + 8) = 1;
  *(undefined1 **)(unaff_ESI + 0x44) = &LAB_0071ee00;
  *(undefined1 **)(unaff_ESI + 0x4c) = &LAB_0071ed30;
  *(undefined1 **)(unaff_ESI + 0x48) = &LAB_0071ed40;
  *(undefined1 **)(unaff_ESI + 0x50) = &LAB_0071ed20;
  unaff_ESI[2] = 0;
  *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  pvVar2 = operator_new(0x2d0);
  *(void **)(unaff_ESI + 0x40) = pvVar2;
  uVar3 = ov_open_callbacks(unaff_ESI + 0x28,pvVar2,0,0,*(undefined4 *)(unaff_ESI + 0x44),
                            *(undefined4 *)(unaff_ESI + 0x48),*(undefined4 *)(unaff_ESI + 0x4c),
                            *(undefined4 *)(unaff_ESI + 0x50));
  if (uVar3 != 0) {
    return uVar3 & 0xffffff00;
  }
  *unaff_ESI = 1;
  return 1;
}
```
