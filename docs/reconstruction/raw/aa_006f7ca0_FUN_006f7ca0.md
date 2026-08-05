# Raw capture: FUN_006f7ca0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006f7ca0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006f7ca0` |
| **Canonical name** | `FUN_006f7ca0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006f7ca0(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int in_EAX;
  uint uVar4;
  uint *unaff_EBX;
  int iVar5;
  
  uVar4 = in_EAX >> 4;
  bVar3 = ~(byte)(uVar4 >> 3) & 1;
  bVar1 = ~(byte)(uVar4 >> 2) & 1;
  bVar2 = ~(byte)(uVar4 >> 1) & 1;
  if (param_1 != 0) {
    iVar5 = 1 << (bVar1 + bVar2 * '\x02') * '\x02';
    if ((*unaff_EBX & iVar5 * 2) == 0) {
      *unaff_EBX = *unaff_EBX + iVar5;
    }
  }
  if (param_1 != 1) {
    iVar5 = 1 << ((bVar3 + 4 + bVar2 * '\x02') * '\x02' & 0x1f);
    if ((*unaff_EBX & iVar5 * 2) == 0) {
      *unaff_EBX = *unaff_EBX + iVar5;
    }
  }
  if (param_1 != 2) {
    iVar5 = 1 << ((bVar3 + 8 + bVar1 * '\x02') * '\x02' & 0x1f);
    if ((*unaff_EBX & iVar5 * 2) == 0) {
      *unaff_EBX = *unaff_EBX + iVar5;
    }
  }
  return;
}
```
