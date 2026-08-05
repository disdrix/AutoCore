# Raw capture: NDAssetImage_FlipHorizontal

| Field | Value |
|---|---|
| **Stable ID** | `aa_0098acc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0098acc0`–`0x0098ae77` |
| **Canonical name** | `NDAssetImage_FlipHorizontal` |
| **Prior scaffold** | `FUN_0098acc0` |
| **System** | client assets / `NDAssetImage` |
| **Capture timestamp** | `2026-07-29` (W20-L dual seal; body ≡ 2026-07-23 raw) |
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` |
| **Integrity** | Named raw; authoritative CF matches scaffold raw |

---

## Raw pseudocode (authoritative decompile)

```c
/* Horizontal flip of NDAssetImage for TGA image-descriptor bit4 (right-origin).
   Sibling of NDAssetImage_FlipVertical (bit5 top-origin, 32bpp gate at LoadTGA).
   this in EDI; return AL = 0 fail / 1 success. */

undefined4 NDAssetImage_FlipHorizontal(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined1 *puVar9;
  int unaff_EDI;
  int local_10;
  
  if (*(int *)(unaff_EDI + 4) == 0) {
    return 0;
  }
  puVar2 = operator_new(0x1b8);
  if (puVar2 == (undefined4 *)0x0) {
    return 0;
  }
  *puVar2 = &PTR_FUN_00a9bcac;
  FUN_004320d0();
  FUN_00432260(unaff_EDI,0,0,1);
  sVar1 = *(short *)(unaff_EDI + 0x16);
  iVar4 = ((uint)(sVar1 == 0x18) * 2 + 1) * (*(int *)(unaff_EDI + 0xc) + -1);
  iVar8 = puVar2[0xd];
  puVar5 = (undefined1 *)(*(int *)(unaff_EDI + 0x34) + iVar4);
  if (sVar1 == 8) {
    local_10 = 0;
    if (0 < *(int *)(unaff_EDI + 0x10)) {
      do {
        iVar6 = 0;
        puVar3 = puVar5;
        if (-1 < iVar4) {
          do {
            *(undefined1 *)(iVar6 + iVar8) = *puVar3;
            iVar6 = iVar6 + 1;
            puVar3 = puVar3 + -1;
          } while (iVar6 <= iVar4);
        }
        puVar5 = puVar5 + *(int *)(unaff_EDI + 0x30);
        iVar8 = iVar8 + *(int *)(unaff_EDI + 0x30);
        local_10 = local_10 + 1;
      } while (local_10 < *(int *)(unaff_EDI + 0x10));
    }
  }
  else if (sVar1 == 0x18) {
    local_10 = 0;
    if (0 < *(int *)(unaff_EDI + 0x10)) {
      do {
        if (-1 < iVar4) {
          puVar3 = (undefined1 *)(iVar8 + 1);
          puVar9 = puVar5 + 2;
          uVar7 = (iVar4 + 3U) / 3;
          do {
            puVar3[-1] = puVar9[-2];
            *puVar3 = puVar9[-1];
            puVar3[1] = *puVar9;
            puVar3 = puVar3 + 3;
            puVar9 = puVar9 + -3;
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
        puVar5 = puVar5 + *(int *)(unaff_EDI + 0x30);
        iVar8 = iVar8 + *(int *)(unaff_EDI + 0x30);
        local_10 = local_10 + 1;
      } while (local_10 < *(int *)(unaff_EDI + 0x10));
    }
  }
  else {
    iVar8 = 0;
    if (0 < *(int *)(unaff_EDI + 0x10)) {
      do {
        iVar6 = 0;
        if (-1 < iVar4) {
          do {
            FUN_00433530();
            FUN_004337d0(iVar8);
            iVar6 = iVar6 + 1;
          } while (iVar6 <= iVar4);
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < *(int *)(unaff_EDI + 0x10));
    }
  }
  FUN_00433390();
  FUN_00432580(unaff_EDI);
  (**(code **)*puVar2)(1);
  return 1;
}
```
