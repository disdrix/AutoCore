# Annotated low-level: FUN_0047efa0

| Field | Value |
|---|---|
| Stable ID | `aa_0047efa0` |
| VA | `0x0047efa0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0047efa0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0047efa0(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int in_EAX;
  byte bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  
  uVar4 = 0;
  if (*(int *)(in_EAX + 0x1698) != 0) {
    do {
      uVar7 = (uint)*(ushort *)(*(int *)(in_EAX + 0x169c) + uVar4 * 2);
      uVar8 = (uint)*(byte *)(uVar4 + *(int *)(in_EAX + 0x1690));
      uVar4 = uVar4 + 1;
      iVar5 = *(int *)(in_EAX + 0x16b4);
      bVar3 = (byte)iVar5;
      if (uVar7 == 0) {
        uVar7 = (uint)*(ushort *)(param_1 + 2 + uVar8 * 4);
        if ((int)(0x10 - uVar7) < iVar5) {
          uVar1 = *(ushort *)(param_1 + uVar8 * 4);
          *(ushort *)(in_EAX + 0x16b0) = *(ushort *)(in_EAX + 0x16b0) | uVar1 << (bVar3 & 0x1f);
          *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
               *(undefined1 *)(in_EAX + 0x16b0);
          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
          *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
               *(undefined1 *)(in_EAX + 0x16b1);
          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
          iVar5 = *(int *)(in_EAX + 0x16b4) + -0x10 + uVar7;
          *(ushort *)(in_EAX + 0x16b0) = uVar1 >> (0x10U - (char)*(int *)(in_EAX + 0x16b4) & 0x1f);
        }
        else {
          *(ushort *)(in_EAX + 0x16b0) =
               *(ushort *)(in_EAX + 0x16b0) | *(short *)(param_1 + uVar8 * 4) << (bVar3 & 0x1f);
          iVar5 = iVar5 + uVar7;
        }
LAB_0047f2dc:
        *(int *)(in_EAX + 0x16b4) = iVar5;
      }
      else {
        uVar6 = (uint)(byte)(&DAT_00a278d0)[uVar8];
        uVar10 = (uint)*(ushort *)(param_1 + 0x406 + uVar6 * 4);
        if ((int)(0x10 - uVar10) < iVar5) {
          uVar1 = *(ushort *)(param_1 + 0x404 + uVar6 * 4);
          *(ushort *)(in_EAX + 0x16b0) = *(ushort *)(in_EAX + 0x16b0) | uVar1 << (bVar3 & 0x1f);
          *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
               *(undefined1 *)(in_EAX + 0x16b0);
          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
          *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
               *(undefined1 *)(in_EAX + 0x16b1);
          iVar5 = *(int *)(in_EAX + 0x16b4);
          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
          *(uint *)(in_EAX + 0x16b4) = iVar5 + -0x10 + uVar10;
          *(ushort *)(in_EAX + 0x16b0) = uVar1 >> (0x10U - (char)iVar5 & 0x1f);
        }
        else {
          *(ushort *)(in_EAX + 0x16b0) =
               *(ushort *)(in_EAX + 0x16b0) |
               *(short *)(param_1 + 0x404 + uVar6 * 4) << (bVar3 & 0x1f);
          *(uint *)(in_EAX + 0x16b4) = iVar5 + uVar10;
        }
        iVar5 = *(int *)(&DAT_00a27088 + uVar6 * 4);
        if (iVar5 != 0) {
          iVar9 = uVar8 - *(int *)(&DAT_00a279d0 + uVar6 * 4);
          iVar2 = *(int *)(in_EAX + 0x16b4);
          if (0x10 - iVar5 < iVar2) {
            *(ushort *)(in_EAX + 0x16b0) =
                 *(ushort *)(in_EAX + 0x16b0) | (ushort)(iVar9 << ((byte)iVar2 & 0x1f));
            *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
                 *(undefined1 *)(in_EAX + 0x16b0);
            *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
            *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
                 *(undefined1 *)(in_EAX + 0x16b1);
            *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
            iVar2 = *(int *)(in_EAX + 0x16b4) + -0x10;
            *(ushort *)(in_EAX + 0x16b0) =
                 (ushort)iVar9 >> (0x10U - (char)*(int *)(in_EAX + 0x16b4) & 0x1f);
          }
          else {
            *(ushort *)(in_EAX + 0x16b0) =
                 *(ushort *)(in_EAX + 0x16b0) | (ushort)(iVar9 << ((byte)iVar2 & 0x1f));
          }
          *(int *)(in_EAX + 0x16b4) = iVar2 + iVar5;
        }
        uVar8 = uVar7 - 1;
        if (uVar8 < 0x100) {
          bVar3 = (&DAT_00a276cf)[uVar7];
        }
        else {
          bVar3 = (&DAT_00a277d0)[uVar8 >> 7];
        }
        uVar6 = (uint)bVar3;
        uVar7 = (uint)*(ushort *)(param_2 + 2 + uVar6 * 4);
        iVar5 = *(int *)(in_EAX + 0x16b4);
        if ((int)(0x10 - uVar7) < iVar5) {
          uVar1 = *(ushort *)(param_2 + uVar6 * 4);
          *(ushort *)(in_EAX + 0x16b0) =
               *(ushort *)(in_EAX + 0x16b0) | uVar1 << ((byte)iVar5 & 0x1f);
          *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
               *(undefined1 *)(in_EAX + 0x16b0);
          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
          *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
               *(undefined1 *)(in_EAX + 0x16b1);
          iVar5 = *(int *)(in_EAX + 0x16b4);
          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
          *(uint *)(in_EAX + 0x16b4) = iVar5 + -0x10 + uVar7;
          *(ushort *)(in_EAX + 0x16b0) = uVar1 >> (0x10U - (char)iVar5 & 0x1f);
        }
        else {
          *(ushort *)(in_EAX + 0x16b0) =
               *(ushort *)(in_EAX + 0x16b0) |
               *(short *)(param_2 + uVar6 * 4) << ((byte)iVar5 & 0x1f);
          *(uint *)(in_EAX + 0x16b4) = iVar5 + uVar7;
        }
        iVar5 = *(int *)(&DAT_00a27100 + uVar6 * 4);
        if (iVar5 != 0) {
          iVar2 = *(int *)(in_EAX + 0x16b4);
          iVar9 = uVar8 - *(int *)(&DAT_00a27a48 + uVar6 * 4);
          if (0x10 - iVar5 < iVar2) {
            *(ushort *)(in_EAX + 0x16b0) =
                 *(ushort *)(in_EAX + 0x16b0) | (ushort)(iVar9 << ((byte)iVar2 & 0x1f));
            *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
                 *(undefined1 *)(in_EAX + 0x16b0);
            *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
            *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
                 *(undefined1 *)(in_EAX + 0x16b1);
            *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
            iVar5 = *(int *)(in_EAX + 0x16b4) + -0x10 + iVar5;
            *(ushort *)(in_EAX + 0x16b0) =
                 (ushort)iVar9 >> (0x10U - (char)*(int *)(in_EAX + 0x16b4) & 0x1f);
          }
          else {
            *(ushort *)(in_EAX + 0x16b0) =
                 *(ushort *)(in_EAX + 0x16b0) | (ushort)(iVar9 << ((byte)iVar2 & 0x1f));
            iVar5 = iVar2 + iVar5;
          }
          goto LAB_0047f2dc;
        }
      }
    } while (uVar4 < *(uint *)(in_EAX + 0x1698));
  }
  uVar4 = (uint)*(ushort *)(param_1 + 0x402);
  iVar5 = *(int *)(in_EAX + 0x16b4);
  if (iVar5 <= (int)(0x10 - uVar4)) {
    *(ushort *)(in_EAX + 0x16b0) =
         *(ushort *)(in_EAX + 0x16b0) | *(short *)(param_1 + 0x400) << ((byte)iVar5 & 0x1f);
    *(uint *)(in_EAX + 0x16b4) = iVar5 + uVar4;
    *(uint *)(in_EAX + 0x16ac) = (uint)*(ushort *)(param_1 + 0x402);
    return;
  }
  uVar1 = *(ushort *)(param_1 + 0x400);
  *(ushort *)(in_EAX + 0x16b0) = *(ushort *)(in_EAX + 0x16b0) | uVar1 << ((byte)iVar5 & 0x1f);
  *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) = *(undefined1 *)(in_EAX + 0x16b0)
  ;
  *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
  *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) = *(undefined1 *)(in_EAX + 0x16b1)
  ;
  iVar5 = *(int *)(in_EAX + 0x16b4);
  *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
  *(uint *)(in_EAX + 0x16b4) = iVar5 + -0x10 + uVar4;
  *(ushort *)(in_EAX + 0x16b0) = uVar1 >> (0x10U - (char)iVar5 & 0x1f);
  *(uint *)(in_EAX + 0x16ac) = (uint)*(ushort *)(param_1 + 0x402);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
