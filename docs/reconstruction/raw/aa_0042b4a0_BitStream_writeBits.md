# Raw capture: BitStream_writeBits

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b4a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0042b4a0` |
| **Canonical name** | `BitStream_writeBits` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall BitStream_writeBits(int param_1,byte *param_2,byte *param_3)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  sbyte sVar7;
  uint uVar8;
  byte bVar9;
  uint uVar10;
  byte *pbVar11;
  uint uVar12;
  bool bVar13;
  uint local_4;
  
  uVar10 = (uint)param_2;
  if (param_2 == (byte *)0x0) {
    return 1;
  }
  if (*(uint *)(param_1 + 0x30) < (uint)(*(int *)(param_1 + 0x18) + (int)param_2)) {
    cVar2 = FUN_0042b450();
    if (cVar2 == '\0') {
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x30);
      return 0;
    }
  }
  uVar6 = *(uint *)(param_1 + 0x18);
  uVar12 = uVar6 & 7;
  pbVar11 = (byte *)((uVar6 >> 3) + *(int *)(param_1 + 0xc));
  uVar8 = 8 - uVar12;
  bVar13 = param_2 <= uVar8;
  param_2 = param_3;
  sVar7 = (sbyte)uVar12;
  if (bVar13) {
    bVar3 = ('\x01' << ((byte)uVar10 & 0x1f)) - 1;
    *pbVar11 = (*param_3 & bVar3) << sVar7 | ~(bVar3 << sVar7) & *pbVar11;
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + uVar10;
    return 1;
  }
  iVar5 = uVar6 + uVar10;
  if (uVar12 == 0) {
    *(int *)(param_1 + 0x18) = iVar5;
    if (7 < uVar10) {
      uVar6 = uVar10 >> 3;
      do {
        *pbVar11 = *param_3;
        pbVar11 = pbVar11 + 1;
        param_3 = param_3 + 1;
        uVar10 = uVar10 - 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    if (uVar10 != 0) {
      bVar3 = ('\x01' << ((byte)uVar10 & 0x1f)) - 1;
      *pbVar11 = ~bVar3 & *pbVar11 | *param_3 & bVar3;
      return 1;
    }
  }
  else {
    bVar3 = (byte)uVar8;
    bVar9 = (byte)(0xff >> (bVar3 & 0x1f)) & *pbVar11;
    *(int *)(param_1 + 0x18) = iVar5;
    if (7 < uVar10) {
      local_4 = uVar10 >> 3;
      do {
        bVar4 = *param_2;
        param_2 = param_2 + 1;
        *pbVar11 = bVar4 << sVar7 | bVar9;
        pbVar11 = pbVar11 + 1;
        bVar9 = bVar4 >> (bVar3 & 0x1f);
        uVar10 = uVar10 - 8;
        local_4 = local_4 - 1;
      } while (local_4 != 0);
    }
    bVar4 = (byte)(0xff >> (7 - ((char)iVar5 - 1U & 7) & 0x1f));
    if (uVar10 == 0) {
      *pbVar11 = ~bVar4 & *pbVar11 | bVar4 & bVar9;
      return 1;
    }
    if (uVar10 <= uVar8) {
      *pbVar11 = (*param_2 << sVar7 | bVar9) & bVar4 | ~bVar4 & *pbVar11;
      return 1;
    }
    bVar1 = *param_2;
    *pbVar11 = bVar1 << sVar7 | bVar9;
    pbVar11[1] = bVar1 >> (bVar3 & 0x1f) & bVar4 | ~bVar4 & pbVar11[1];
  }
  return 1;
}
```
