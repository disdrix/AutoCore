# Raw capture: FUN_0056add0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056add0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0056add0` |
| **Canonical name** | `FUN_0056add0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined1 __fastcall FUN_0056add0(int param_1)

{
  short sVar1;
  undefined1 uVar2;
  short sVar3;
  short sVar4;
  
  sVar3 = 0;
  if (0 < *(short *)(param_1 + 0x130)) {
    sVar3 = *(short *)(param_1 + 0x130);
  }
  sVar1 = *(short *)(param_1 + 0x132);
  sVar4 = sVar3;
  if (sVar3 < sVar1) {
    sVar4 = sVar1;
  }
  uVar2 = sVar3 < sVar1;
  if (sVar4 < *(short *)(param_1 + 0x134)) {
    uVar2 = 2;
    sVar4 = *(short *)(param_1 + 0x134);
  }
  if (sVar4 < *(short *)(param_1 + 0x136)) {
    uVar2 = 3;
    sVar4 = *(short *)(param_1 + 0x136);
  }
  if (sVar4 < *(short *)(param_1 + 0x138)) {
    uVar2 = 4;
    sVar4 = *(short *)(param_1 + 0x138);
  }
  if (sVar4 < *(short *)(param_1 + 0x13a)) {
    uVar2 = 5;
  }
  return uVar2;
}
```
