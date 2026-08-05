// =============================================================================
// FUN_005858b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005858b0
// Address:   0x005858b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005858b0 @ 0x005858b0
// Stable ID: aa_005858b0
// Embedded strings (evidence for future rename):
//   - "MatColorPrimary"
//   - "MatColorSecondary"
//   - "MatColorTertiary"
//   - "TintTexture"
//   - "DiffuseTexture"
//   - "black.dds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×11, while×4, do×3, goto×2, return×1, for×1.
//  - Notable callees: FUN_009700f0×3, FUN_0096f3e0×2, FUN_00970140×2, FUN_00989e00×2, FUN_005858b0, FUN_007b6770, FUN_007b6a20, FUN_0096ef70.
//  - Strings: "MatColorPrimary"; "MatColorSecondary"; "MatColorTertiary"; "TintTexture".
//  - Return sites: 1.

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

void FUN_005858b0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int param_4,uint32_t /* width from decompiler */ param_5,

                 char param_6)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  char *pcVar4;

  int iVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ local_134;

  int local_12c;

  uint8_t local_128 [4];

  uint8_t local_124 [3];

  char cStack_121;

  char local_120 [2];

  uint32_t /* width from decompiler */ auStack_11e [66];

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  local_c = 0xffffffff;

  puStack_10 = &LAB_009a54e6;

  local_14 = ExceptionList;

  iVar5 = 0;

  ExceptionList = &local_14;

  do {

    while( true ) {

      if (*(int *)(param_1 + 0xc0) == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = *(int *)(param_1 + 0xc4) - *(int *)(param_1 + 0xc0) >> 2;

      }

      if (iVar2 <= iVar5) {

        ExceptionList = local_14;

        return;

      }

      FUN_0096fdf0();

      FUN_009700f0("MatColorPrimary",param_2);

      FUN_009700f0("MatColorSecondary",param_3);

      if (param_6 != '\0') {

        FUN_009700f0("MatColorTertiary",param_5);

      }

      if (param_4 == 0) break;

      FUN_00970140("TintTexture",param_4);

      iVar5 = iVar5 + 1;

    }

    local_12c = 0;

    FUN_0096f6e0("DiffuseTexture",&local_12c);

    if (local_12c != 0) {

      local_120[0] = '\0';

      local_120[1] = '\0';

      puVar3 = auStack_11e;

      for (iVar2 = 0x40; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar3 = 0;

        puVar3 = puVar3 + 1;

      }

      *(uint16_t *)puVar3 = 0;

      if (*(int *)(local_12c + 0x4c) == 0) {

        puVar3 = &DAT_00d1ed24;

      }

      else {

        puVar3 = (uint32_t /* width from decompiler */ *)(*(int *)(local_12c + 0x4c) + 4);

      }

      pcVar4 = (char *)*puVar3;

      if ((char *)*puVar3 == (char *)0x0) {

        pcVar4 = PTR_DAT_00afa2bc;

      }

      iVar2 = -2 - (int)pcVar4;

      do {

        cVar1 = *pcVar4;

        pcVar4[(int)auStack_11e + iVar2] = cVar1;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      pcVar4 = strrchr(local_120,0x2e);

      if (pcVar4 != (char *)0x0) {

        *pcVar4 = '\0';

      }

      pcVar4 = &cStack_121;

      do {

        pcVar6 = pcVar4;

        pcVar4 = pcVar6 + 1;

      } while (pcVar6[1] != '\0');

      *(uint32_t /* width from decompiler */ *)(pcVar6 + 1) = s__tint_dds_009cd060._0_4_;

      *(uint32_t /* width from decompiler */ *)(pcVar6 + 5) = s__tint_dds_009cd060._4_4_;

      *(uint16_t *)(pcVar6 + 9) = s__tint_dds_009cd060._8_2_;

      FUN_0096ef70();

      pcVar4 = local_120;

      local_c = 0;

      FUN_007b6a20(pcVar4);

      cVar1 = FUN_007b6770(pcVar4);

      if (cVar1 == '\0') {

LAB_00585a66:

        FUN_00989e00(local_124,"black.dds");

        iVar2 = FUN_0096f3e0(local_124,0);

        if (-1 < iVar2) goto LAB_00585a92;

      }

      else {

        FUN_00989e00(local_128,local_120);

        iVar2 = FUN_0096f3e0(local_128,0);

        if (iVar2 < 0) goto LAB_00585a66;

LAB_00585a92:

        FUN_00970140("TintTexture",local_134);

      }

      local_c = 0xffffffff;

      FUN_0096efd0();

    }

    iVar5 = iVar5 + 1;

  } while( true );

}
