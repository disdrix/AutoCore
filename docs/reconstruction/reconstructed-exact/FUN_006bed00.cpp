// =============================================================================
// FUN_006bed00
// -----------------------------------------------------------------------------
// Stable ID: aa_006bed00
// Address:   0x006bed00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006bed00 @ 0x006bed00
// Stable ID: aa_006bed00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×1, for×1, while×1.
//  - Notable callees: FUN_005b3300×2, FUN_006be870×2, CONCAT31, FUN_006bed00.
//  - Return sites: 2.

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

void FUN_006bed00(int param_1,int param_2,int *param_3,int *param_4)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  uint extraout_ECX;

  int *piVar5;

  int *piVar6;

  int local_14;

  int local_10;

  char local_8 [4];

  char local_4 [4];

  

  local_10 = 0;

  if (0 < param_3[1]) {

    local_14 = 0;

    do {

      param_4[1] = 0;

      piVar5 = (int *)(*param_3 + local_14);

      if ((param_4[2] & 0x7fffffffU) == 0) {

        FUN_005b3300(param_4,1,0x10);

      }

      piVar2 = (int *)*param_4;

      param_4[1] = 1;

      *piVar2 = *piVar5;

      piVar2[1] = piVar5[1];

      for (piVar2 = (int *)piVar5[2]; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[2]) {

        if (((*piVar2 == *piVar5) && (piVar2[1] == piVar5[1])) && (piVar2[3] == piVar5[3])) {

          FUN_006be870(local_8,param_1,*(uint32_t /* width from decompiler */ *)(param_2 + 4),

                       CONCAT31((int3)((uint)piVar2[1] >> 8),1),param_4);

          FUN_006be870(local_4,param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 4),extraout_ECX & 0xffffff00,

                       param_4);

          if ((local_8[0] != '\0') && (local_4[0] != '\0')) {

            return;

          }

        }

        iVar3 = param_4[1];

        iVar1 = iVar3 + 1;

        if ((int)(param_4[2] & 0x7fffffffU) < iVar1) {

          iVar4 = (param_4[2] & 0x7fffffffU) * 2;

          if (iVar4 <= iVar1) {

            iVar4 = iVar1;

          }

          FUN_005b3300(param_4,iVar4,0x10);

        }

        param_4[1] = iVar1;

        piVar6 = (int *)(iVar3 * 0x10 + *param_4);

        *piVar6 = *piVar2;

        piVar6[1] = piVar2[1];

      }

      local_10 = local_10 + 1;

      local_14 = local_14 + 0x14;

    } while (local_10 < param_3[1]);

  }

  param_4[1] = 0;

  return;

}
