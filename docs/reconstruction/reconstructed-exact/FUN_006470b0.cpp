// =============================================================================
// FUN_006470b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006470b0
// Address:   0x006470b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006470b0 @ 0x006470b0
// Stable ID: aa_006470b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×5, while×2, for×2, do×1, return×1, goto×1.
//  - Notable callees: FUN_006470b0.
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

void FUN_006470b0(byte *param_1,int param_2,int *param_3)



{

  char cVar1;

  int *piVar2;

  int iVar3;

  char *pcVar4;

  uint uVar5;

  uint uVar6;

  int iVar7;

  byte *pbVar8;

  byte *pbVar9;

  char local_20;

  uint16_t local_1f;

  byte local_1d;

  uint local_1c [4];

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  piVar2 = param_3;

  local_1c[1] = 2;

  local_4 = 2;

  iVar7 = 0;

  local_1c[0] = 0;

  local_1c[2] = 3;

  local_1c[3] = 0;

  local_c = 0;

  local_8 = 1;

  local_20 = '\0';

  param_2 = local_1c[param_2 % 3] + (param_2 / 3) * 4;

  local_1f = 0;

  local_1d = 0;

  pbVar9 = param_1;

  while ((0 < param_2 && (iVar3 = (**(code **)(*piVar2 + 8))(&param_1,1), iVar3 == 1))) {

    if ((&DAT_009e4668)[(uint)param_1 & 0x7f] != -1) {

      param_2 = param_2 + -1;

      (&local_20)[iVar7] = (&DAT_009e4668)[(uint)param_1 & 0xff];

      iVar7 = iVar7 + 1;

      if (iVar7 == 4) {

        *pbVar9 = (byte)local_1f >> 4 | local_20 * '\x04';

        pbVar9[1] = local_1f._1_1_ >> 2 | (byte)local_1f << 4;

        pbVar9[2] = local_1f._1_1_ << 6 | local_1d;

        iVar7 = 0;

        pbVar9 = pbVar9 + 3;

        local_1d = 0;

        local_1f = 0;

        local_20 = '\0';

      }

    }

  }

  pcVar4 = (char *)(**(code **)(*piVar2 + 4))(&param_2);

  cVar1 = *pcVar4;

  do {

    if (cVar1 == '\0') {

LAB_00647207:

      if ((iVar7 != 0) && (uVar6 = local_1c[iVar7 + 2], 0 < (int)uVar6)) {

        pbVar8 = (byte *)register0x00000010;

        for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

          *(uint32_t /* width from decompiler */ *)pbVar9 = *(uint32_t /* width from decompiler */ *)pbVar8;

          pbVar8 = pbVar8 + 4;

          pbVar9 = pbVar9 + 4;

        }

        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

          *pbVar9 = *pbVar8;

          pbVar8 = pbVar8 + 1;

          pbVar9 = pbVar9 + 1;

        }

      }

      return;

    }

    (**(code **)(*piVar2 + 0x14))(1);

    (**(code **)(*piVar2 + 8))(&local_4,1);

    if ((char)local_c != '=') {

      (**(code **)(*piVar2 + 0x18))();

      goto LAB_00647207;

    }

    pcVar4 = (char *)(**(code **)(*piVar2 + 4))(&local_8);

    cVar1 = *pcVar4;

  } while( true );

}
