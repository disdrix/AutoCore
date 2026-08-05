# Raw capture: CVOGTerrain_LoadTintMap

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ab100` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004ab100` |
| **Canonical name** | `CVOGTerrain_LoadTintMap` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x004ab174) */
/* CVOGTerrain::LoadTintMap. Loads <map>_tint.tga into the per-cell RGBA vertex-color buffer
   (+0x3a4); defaults to 0xff7f7f7f mid-gray when missing. The terrain shaders multiply diffuse by
   2*vertColor, so 0x7f = neutral. */

undefined4 __fastcall CVOGTerrain_LoadTintMap(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  float fVar12;
  char local_190 [127];
  char cStack_111;
  char local_110 [2];
  undefined4 local_10e [66];
  
  local_110[0] = '\0';
  local_110[1] = '\0';
  puVar5 = local_10e;
  for (iVar6 = 0x40; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)puVar5 = 0;
  pcVar4 = local_190;
  uVar3 = (*(code *)PTR_FUN_00af8c9c)();
  FUN_00403450(param_1 + 0x124,uVar3);
  iVar6 = -2 - (int)pcVar4;
  do {
    cVar1 = *pcVar4;
    pcVar4[(int)local_10e + iVar6] = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  pcVar4 = strrchr(local_110,0x2e);
  if (pcVar4 != (char *)0x0) {
    *pcVar4 = '\0';
    pcVar4 = &cStack_111;
    do {
      pcVar10 = pcVar4;
      pcVar4 = pcVar10 + 1;
    } while (pcVar10[1] != '\0');
    *(undefined4 *)(pcVar10 + 1) = s__tint_tga_009cb140._0_4_;
    *(undefined4 *)(pcVar10 + 5) = s__tint_tga_009cb140._4_4_;
    *(undefined2 *)(pcVar10 + 9) = s__tint_tga_009cb140._8_2_;
  }
  pcVar4 = local_110;
  FUN_007b6a20(pcVar4);
  iVar6 = FUN_007b7250(pcVar4);
  puVar5 = operator_new__(*(int *)(param_1 + 0x14) * *(int *)(param_1 + 0x10) * 4);
  *(undefined4 **)(param_1 + 0x3a4) = puVar5;
  for (uVar7 = *(int *)(param_1 + 0x14) * *(int *)(param_1 + 0x10) & 0x3fffffff; uVar7 != 0;
      uVar7 = uVar7 - 1) {
    *puVar5 = 0xffffffff;
    puVar5 = puVar5 + 1;
  }
  for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
    *(undefined1 *)puVar5 = 0xff;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  if (iVar6 == 0) {
    iVar6 = 0;
    if (0 < *(int *)(param_1 + 0x14) * *(int *)(param_1 + 0x10)) {
      do {
        *(undefined4 *)(*(int *)(param_1 + 0x3a4) + iVar6 * 4) = 0xff7f7f7f;
        iVar6 = iVar6 + 1;
      } while (iVar6 < *(int *)(param_1 + 0x14) * *(int *)(param_1 + 0x10));
    }
    return 1;
  }
  iVar6 = FUN_00788e40();
  iVar8 = FUN_00788e30();
  if ((0 < iVar6) && (0 < iVar8)) {
    iVar9 = 0;
    if (0 < iVar6) {
      do {
        iVar11 = 0;
        if (0 < iVar8) {
          do {
            fVar12 = (float)iVar11;
            iVar2 = *(int *)(param_1 + 0x14);
            uVar7 = FUN_007890b0(iVar11,iVar9);
            iVar11 = iVar11 + 1;
            *(uint *)(*(int *)(param_1 + 0x3a4) + ((int)fVar12 * iVar2 + (int)(float)iVar9) * 4) =
                 uVar7 | 0xff000000;
          } while (iVar11 < iVar8);
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar6);
    }
    pcVar4 = local_110;
    FUN_007b6a20(pcVar4);
    FUN_007b70b0(pcVar4);
    return 1;
  }
  return 0;
}
```
