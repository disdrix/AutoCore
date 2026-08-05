// READABILITY (auto CF):
//  - Body size: ~93 non-empty decompiler lines.
//  - Control keywords: if×6, do×3, while×3, return×3, for×1.
//  - Notable callees: FUN_007b6a20×2, buffer×2, CONCAT11, CVOGTerrain_LoadMapImage, CVOGTerrain_LoadTintMap, CVOGTerrain_ReloadRandomTintFile, FUN_00403450, FUN_004a8960.
//  - Return sites: 3.

// =============================================================================
// CVOGTerrain_LoadMapImage
// -----------------------------------------------------------------------------
// Stable ID: aa_004aba80
// Address:   0x004aba80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x004abaea) */

/* CVOGTerrain::LoadMapImage. Loads <map>.tga (32bpp BGRA). Per cell: height16 buffer (+0x3e0, u16)

   = (alphaPlane<<8) | B - terrain height is 16-BIT, world Y = height16 * HeightScale/256 (B is

   the low byte, not noise); tile buffer (+0x3dc, u8) = G (low 3 bits = tile layer index). Then

   LoadTintMap + ReloadRandomTintFile. */



uint32_t /* width from decompiler */ __thiscall CVOGTerrain_LoadMapImage(int *param_1,char param_2)



{

  char cVar1;

  uint8_t uVar2;

  uint8_t uVar3;

  byte bVar4;

  uint32_t /* width from decompiler */ uVar5;

  char *pcVar6;

  int iVar7;

  void *pvVar8;

  int iVar9;

  byte *pbVar10;

  uint32_t /* width from decompiler */ *puVar11;

  int iVar12;

  int iStack_198;

  char local_184 [128];

  char local_104 [2];

  uint32_t /* width from decompiler */ local_102 [64];

  

  local_104[0] = '\0';

  local_104[1] = '\0';

  puVar11 = local_102;

  for (iVar9 = 0x40; iVar9 != 0; iVar9 = iVar9 + -1) {

    *puVar11 = 0;

    puVar11 = puVar11 + 1;

  }

  *(uint16_t *)puVar11 = 0;

  pcVar6 = local_184;

  uVar5 = (*(code *)PTR_FUN_00af8c9c)();

  FUN_00403450(param_1 + 0x49,uVar5);

  iVar9 = -2 - (int)pcVar6;

  do {

    cVar1 = *pcVar6;

    pcVar6[(int)local_102 + iVar9] = cVar1;

    pcVar6 = pcVar6 + 1;

  } while (cVar1 != '\0');

  pcVar6 = local_104;

  FUN_007b6a20(pcVar6);

  iVar9 = FUN_007b7250(pcVar6);

  if (iVar9 == 0) {

    return 1;

  }

  iVar7 = FUN_00788e40();

  param_1[5] = iVar7;

  iVar7 = FUN_00788e30();

  param_1[4] = iVar7;

  pvVar8 = operator_new__(param_1[5] * iVar7);

  param_1[0xf7] = (int)pvVar8;

  pvVar8 = operator_new__(param_1[4] * param_1[5] * 2);

  param_1[0xf8] = (int)pvVar8;

  if (*param_1 < 0x13) {

    iVar9 = FUN_004a8960(iVar9);

    if (iVar9 != 0) {

      return 1;

    }

  }

  else {

    iStack_198 = 0;

    if (0 < param_1[5]) {

      do {

        iVar9 = 0;

        if (0 < param_1[4]) {

          do {

            iVar7 = param_1[4];

            iVar12 = param_1[5] * iVar9 + iStack_198;

            uVar2 = FUN_00788ee0(iVar9,iStack_198);

            uVar3 = FUN_00788f60(iVar9,iStack_198);

            *(ushort *)(param_1[0xf8] + (iVar7 * iStack_198 + iVar9) * 2) = CONCAT11(uVar2,uVar3);

            bVar4 = FUN_00788fd0(iVar9,iStack_198);

            pbVar10 = (byte *)(param_1[0xf7] + iVar12);

            *pbVar10 = *pbVar10 ^ (*(byte *)(param_1[0xf7] + iVar12) ^ bVar4) & 7;

            iVar9 = iVar9 + 1;

            *(byte *)(iVar12 + param_1[0xf7]) =

                 (*(byte *)(iVar12 + param_1[0xf7]) ^ bVar4) & 7 ^ bVar4;

          } while (iVar9 < param_1[4]);

        }

        iStack_198 = iStack_198 + 1;

      } while (iStack_198 < param_1[5]);

    }

  }

  if (param_2 != '\0') {

    CVOGTerrain_LoadTintMap();

    CVOGTerrain_ReloadRandomTintFile();

  }

  pcVar6 = local_104;

  FUN_007b6a20(pcVar6);

  FUN_007b70b0(pcVar6);

  return 0;

}
