# Annotated low-level: BitStream_readBits

| Field | Value |
|---|---|
| Stable ID | `aa_0042b670` |
| VA | `0x0042b670` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0042b670`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall BitStream_readBits(int param_1,uint param_2,byte *param_3)

{
  byte *pbVar1;
  uint uVar2;
  byte bVar3;
  byte *pbVar4;
  byte bVar5;
  uint uVar6;
  byte bVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  
  if (param_2 != 0) {
    uVar2 = *(uint *)(param_1 + 0x18);
    if (*(uint *)(param_1 + 0x2c) < uVar2 + param_2) {
      *(undefined1 *)(param_1 + 0x1c) = 1;
      return 0;
    }
    uVar6 = uVar2 & 7;
    pbVar4 = (byte *)((uVar2 >> 3) + *(int *)(param_1 + 0xc));
    uVar8 = param_2 + 7 >> 3;
    if (uVar6 == 0) {
      for (; uVar8 != 0; uVar8 = uVar8 - 1) {
        *param_3 = *pbVar4;
        param_3 = param_3 + 1;
        pbVar4 = pbVar4 + 1;
      }
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + param_2;
      return 1;
    }
    bVar7 = *pbVar4 >> (sbyte)uVar6;
    *(uint *)(param_1 + 0x18) = uVar2 + param_2;
    bVar5 = (byte)(8 - uVar6);
    pbVar10 = param_3;
    if (7 < param_2) {
      pbVar9 = param_3;
      param_3 = (byte *)(param_2 >> 3);
      bVar3 = bVar7;
      do {
        pbVar1 = pbVar4 + 1;
        pbVar4 = pbVar4 + 1;
        bVar7 = *pbVar1 >> (sbyte)uVar6;
        pbVar10 = pbVar9 + 1;
        param_2 = param_2 - 8;
        param_3 = (byte *)((int)param_3 - 1);
        *pbVar9 = *pbVar1 << (bVar5 & 0x1f) | bVar3;
        pbVar9 = pbVar10;
        bVar3 = bVar7;
      } while (param_3 != (byte *)0x0);
    }
    if (param_2 != 0) {
      if (param_2 <= 8 - uVar6) {
        *pbVar10 = bVar7;
        return 1;
      }
      *pbVar10 = pbVar4[1] << (bVar5 & 0x1f) | bVar7;
    }
  }
  return 1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
