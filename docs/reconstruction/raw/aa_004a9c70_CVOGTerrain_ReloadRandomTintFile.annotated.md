# Annotated low-level: CVOGTerrain_ReloadRandomTintFile

| Field | Value |
|---|---|
| Stable ID | `aa_004a9c70` |
| VA | `0x004a9c70` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004a9c70`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* CVOGTerrain::ReloadRandomTintFile [VOGTerrain.cpp]. Loads a <map>_verttint.png (must be 8px tall)
   into an 8-row random per-vertex TINT palette (this+0x3a8, 8 rows x width, width at +0x3c8).
   Writes the alpha byte (texel>>0x18) scaled. This is vertex colour tint, NOT terrain height. */

undefined4 __fastcall CVOGTerrain_ReloadRandomTintFile(int param_1)

{
  undefined1 uVar1;
  char cVar2;
  char *pcVar3;
  uint uVar4;
  undefined4 uVar5;
  void *pvVar6;
  undefined4 *puVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  uint *puVar11;
  int iVar12;
  char *pcVar13;
  int iVar14;
  int iVar15;
  ushort in_FPUControlWord;
  undefined4 *local_22c;
  int local_228;
  int local_224;
  uint local_220;
  undefined4 local_21c;
  char local_218 [2];
  undefined4 auStack_216 [65];
  char local_110 [2];
  undefined4 local_10e [66];
  
  local_110[0] = '\0';
  local_110[1] = '\0';
  pcVar3 = local_110 + 2;
  for (iVar9 = 0x40; iVar9 != 0; iVar9 = iVar9 + -1) {
    pcVar3[0] = '\0';
    pcVar3[1] = '\0';
    pcVar3[2] = '\0';
    pcVar3[3] = '\0';
    pcVar3 = pcVar3 + 4;
  }
  uVar1 = *(undefined1 *)(param_1 + 0x1c);
  pcVar3[0] = '\0';
  pcVar3[1] = '\0';
  local_224 = param_1;
  FUN_004a8fd0(uVar1,local_110);
  local_218[0] = '\0';
  local_218[1] = '\0';
  puVar7 = auStack_216;
  for (iVar9 = 0x40; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined2 *)puVar7 = 0;
  pcVar3 = local_110;
  do {
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  uVar4 = (int)pcVar3 - (int)local_110;
  pcVar3 = (char *)((int)&local_21c + 3);
  do {
    pcVar13 = pcVar3 + 1;
    pcVar3 = pcVar3 + 1;
  } while (*pcVar13 != '\0');
  pcVar13 = local_110;
  for (uVar10 = uVar4 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
    *(undefined4 *)pcVar3 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar3 = pcVar3 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar3 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar3 = pcVar3 + 1;
  }
  pcVar3 = strrchr(local_218,0x2e);
  if (pcVar3 != (char *)0x0) {
    *pcVar3 = '\0';
    pcVar3 = (char *)((int)&local_21c + 3);
    do {
      pcVar13 = pcVar3;
      pcVar3 = pcVar13 + 1;
    } while (pcVar13[1] != '\0');
    *(undefined4 *)(pcVar13 + 1) = s__verttint_png_009cb00c._0_4_;
    *(undefined4 *)(pcVar13 + 5) = s__verttint_png_009cb00c._4_4_;
    *(undefined4 *)(pcVar13 + 9) = s__verttint_png_009cb00c._8_4_;
    *(undefined2 *)(pcVar13 + 0xd) = s__verttint_png_009cb00c._12_2_;
  }
  pcVar3 = local_218;
  FUN_007b6a20(pcVar3);
  iVar9 = FUN_007b7250(pcVar3);
  if (iVar9 != 0) {
    iVar9 = FUN_00788e40();
    if (iVar9 != 8) {
      uVar5 = FUN_0076cec0(&local_228,
                           "ReloadRandomTintFile() - Height(in pixels) of %s wasn\'t %d... that\'s bad!"
                           ,local_218,8);
      vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGTerrain.cpp",0xae2,2,uVar5);
      return 0;
    }
    iVar9 = FUN_00788e30();
    if (iVar9 != 0) {
      uVar5 = FUN_00788e30();
      *(undefined4 *)(param_1 + 0x3c8) = uVar5;
      puVar7 = (undefined4 *)(param_1 + 0x3a8);
      iVar9 = 8;
      do {
        if ((void *)*puVar7 != (void *)0x0) {
          operator_delete__((void *)*puVar7);
        }
        *puVar7 = 0;
        pvVar6 = operator_new__(*(int *)(param_1 + 0x3c8) * 4);
        *puVar7 = pvVar6;
        puVar7 = puVar7 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      iVar9 = *(int *)(local_224 + 0x3c8);
      local_22c = (undefined4 *)(local_224 + 0x3c4);
      iVar12 = 7;
      do {
        iVar14 = 0;
        do {
          if (((iVar12 < 0) || (7 < iVar12)) ||
             (puVar7 = (undefined4 *)*local_22c, puVar7 == (undefined4 *)0x0)) {
            puVar7 = &DAT_00af06dc;
          }
          else if ((-1 < iVar14) && (iVar14 < iVar9)) {
            puVar7 = puVar7 + iVar14;
          }
          uVar5 = FUN_007890b0(iVar14,iVar12);
          *puVar7 = uVar5;
          iVar9 = *(int *)(local_224 + 0x3c8);
          iVar14 = iVar14 + 1;
        } while (iVar14 < iVar9);
        local_22c = local_22c + -1;
        iVar12 = iVar12 + -1;
      } while (-1 < iVar12);
      iVar9 = 0;
      local_22c = (undefined4 *)(local_224 + 0x3a8);
      do {
        iVar12 = *(int *)(local_224 + 0x3c8);
        iVar15 = 0;
        iVar14 = 0;
        if (0 < iVar12) {
          do {
            if (((iVar9 < 0) || (7 < iVar9)) ||
               (puVar7 = (undefined4 *)*local_22c, puVar7 == (undefined4 *)0x0)) {
              puVar7 = &DAT_00af06dc;
            }
            else if ((-1 < iVar14) && (iVar14 < iVar12)) {
              puVar7 = puVar7 + iVar14;
            }
            iVar14 = iVar14 + 1;
            iVar15 = iVar15 + (uint)*(byte *)((int)puVar7 + 3);
          } while (iVar14 < iVar12);
        }
        iVar14 = 0;
        if (0 < iVar12) {
          local_21c = (float)iVar15;
          do {
            if (((iVar9 < 0) || (7 < iVar9)) || (puVar8 = (uint *)*local_22c, puVar8 == (uint *)0x0)
               ) {
              puVar8 = &DAT_00af06dc;
            }
            else if ((-1 < iVar14) && (iVar14 < *(int *)(local_224 + 0x3c8))) {
              puVar8 = puVar8 + iVar14;
            }
            local_220 = (uint)in_FPUControlWord;
            local_228 = (int)ROUND(((float)(*puVar8 >> 0x18) / local_21c) * DAT_00aaa6f8);
            if (((iVar9 < 0) || (7 < iVar9)) ||
               (puVar11 = (uint *)*local_22c, puVar11 == (uint *)0x0)) {
              puVar11 = &DAT_00af06dc;
            }
            else if ((-1 < iVar14) && (iVar14 < *(int *)(local_224 + 0x3c8))) {
              puVar11 = puVar11 + iVar14;
            }
            iVar14 = iVar14 + 1;
            *puVar11 = local_228 << 0x18 | *puVar8 & 0xffffff;
          } while (iVar14 < *(int *)(local_224 + 0x3c8));
        }
        local_22c = local_22c + 1;
        iVar9 = iVar9 + 1;
      } while (iVar9 < 8);
      pcVar3 = local_218;
      FUN_007b6a20(pcVar3);
      FUN_007b70b0(pcVar3);
      return 1;
    }
    uVar5 = FUN_0076cec0(&local_228,
                         "ReloadRandomTintFile() - Width(in pixels) of %s was <= 0... that\'s bad!",
                         local_218);
    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGTerrain.cpp",0xae7,2,uVar5);
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
