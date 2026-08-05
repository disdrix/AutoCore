# Raw capture: FUN_0095abe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0095abe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0095abe0` |
| **Canonical name** | `FUN_0095abe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0095abe0(void)

{
  float fVar1;
  undefined4 uVar2;
  float fVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  undefined4 *unaff_ESI;
  
  uVar5 = DAT_00b036f0;
  uVar4 = DAT_00aaa700;
  uVar2 = DAT_00a0f698;
  fVar1 = g_flOne;
  unaff_ESI[0xf] = DAT_00a0f698;
  unaff_ESI[0x12] = uVar2;
  unaff_ESI[0x19] = DAT_00a0f708;
  *unaff_ESI = &PTR_FUN_00a141a0;
  unaff_ESI[0x3a] = 0;
  *(undefined2 *)(unaff_ESI + 0x16) = 0;
  *(undefined1 *)(unaff_ESI + 1) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x21) = 1;
  *(undefined1 *)((int)unaff_ESI + 5) = 1;
  *(undefined1 *)((int)unaff_ESI + 6) = 1;
  *(undefined1 *)((int)unaff_ESI + 7) = 0;
  *(undefined1 *)(unaff_ESI + 2) = 1;
  *(undefined1 *)((int)unaff_ESI + 9) = 0;
  *(undefined1 *)((int)unaff_ESI + 10) = 0;
  *(undefined1 *)((int)unaff_ESI + 0xb) = 1;
  *(undefined1 *)(unaff_ESI + 3) = 1;
  *(undefined1 *)((int)unaff_ESI + 0xd) = 1;
  *(undefined1 *)((int)unaff_ESI + 0xe) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x11) = 0;
  *(undefined1 *)((int)unaff_ESI + 0xf) = 0;
  *(undefined1 *)(unaff_ESI + 4) = 1;
  *(undefined1 *)((int)unaff_ESI + 0x12) = 1;
  *(undefined1 *)((int)unaff_ESI + 0x13) = 0;
  *(undefined1 *)(unaff_ESI + 5) = 1;
  *(undefined1 *)((int)unaff_ESI + 0x15) = 1;
  *(undefined1 *)((int)unaff_ESI + 0x16) = 1;
  *(undefined1 *)((int)unaff_ESI + 0x17) = 1;
  *(undefined1 *)(unaff_ESI + 6) = 1;
  *(undefined1 *)((int)unaff_ESI + 0x19) = 1;
  *(undefined1 *)((int)unaff_ESI + 0x1a) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x1b) = 0;
  *(undefined1 *)(unaff_ESI + 7) = 1;
  *(undefined1 *)((int)unaff_ESI + 0x1d) = 1;
  *(undefined1 *)((int)unaff_ESI + 0x1e) = 1;
  *(undefined1 *)((int)unaff_ESI + 0x1f) = 0;
  *(undefined1 *)(unaff_ESI + 8) = 1;
  *(undefined1 *)((int)unaff_ESI + 0x22) = 1;
  *(undefined1 *)((int)unaff_ESI + 0x23) = 0;
  *(undefined1 *)(unaff_ESI + 9) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x25) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x26) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x27) = 1;
  *(undefined1 *)(unaff_ESI + 10) = 1;
  *(undefined1 *)((int)unaff_ESI + 0x29) = 1;
  *(undefined1 *)((int)unaff_ESI + 0x2a) = 1;
  *(undefined1 *)((int)unaff_ESI + 0x2b) = 1;
  *(undefined1 *)(unaff_ESI + 0xb) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x2d) = 1;
  *(undefined1 *)((int)unaff_ESI + 0x2e) = 1;
  unaff_ESI[0xc] = fVar1;
  unaff_ESI[0xd] = fVar1;
  unaff_ESI[0xe] = fVar1;
  unaff_ESI[0x10] = uVar4;
  unaff_ESI[0x11] = fVar1;
  unaff_ESI[0x13] = fVar1;
  *(undefined1 *)(unaff_ESI + 0x14) = uVar5;
  *(undefined1 *)((int)unaff_ESI + 0x51) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x52) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x53) = 0;
  *(undefined1 *)(unaff_ESI + 0x15) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x55) = 1;
  *(undefined1 *)((int)unaff_ESI + 0x56) = 0;
  *(undefined1 *)(unaff_ESI + 0x1c) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x71) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x72) = 1;
  unaff_ESI[0x37] = fVar1;
  unaff_ESI[0x17] = 800;
  unaff_ESI[0x18] = 600;
  *(undefined1 *)(unaff_ESI + 0x1a) = 1;
  unaff_ESI[0x1b] = fVar1;
  unaff_ESI[0x1d] = 0;
  unaff_ESI[0x1e] = 0;
  unaff_ESI[0x1f] = 0;
  uVar2 = DAT_00aaa690;
  unaff_ESI[0x20] = DAT_00aaa690;
  unaff_ESI[0x21] = uVar2;
  unaff_ESI[0x22] = uVar2;
  uVar2 = DAT_00aaa6fc;
  unaff_ESI[0x26] = 0;
  unaff_ESI[0x27] = 0;
  unaff_ESI[0x28] = 0;
  unaff_ESI[0x2f] = 0;
  unaff_ESI[0x30] = 0;
  unaff_ESI[0x31] = 0;
  unaff_ESI[0x32] = 0;
  fVar3 = g_flLevelUpUiBase_Inferred;
  unaff_ESI[0x23] = uVar2;
  unaff_ESI[0x24] = uVar2;
  unaff_ESI[0x25] = uVar2;
  uVar2 = DAT_00a0f70c;
  unaff_ESI[0x33] = fVar3;
  uVar4 = DAT_00aaa688;
  unaff_ESI[0x29] = uVar2;
  unaff_ESI[0x2a] = uVar2;
  unaff_ESI[0x2b] = uVar2;
  uVar2 = DAT_00a0f720;
  unaff_ESI[0x34] = uVar4;
  uVar4 = DAT_00a110d8;
  unaff_ESI[0x2c] = uVar2;
  unaff_ESI[0x2d] = uVar2;
  unaff_ESI[0x2e] = uVar2;
  unaff_ESI[0x35] = uVar4;
  unaff_ESI[0x36] = fVar1;
  FUN_008f59e0();
  return;
}
```
