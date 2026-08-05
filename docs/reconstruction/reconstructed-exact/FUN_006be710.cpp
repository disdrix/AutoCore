// =============================================================================
// FUN_006be710
// -----------------------------------------------------------------------------
// Stable ID: aa_006be710
// Address:   0x006be710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006be710 @ 0x006be710
// Stable ID: aa_006be710
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×8, goto×4, do×3, while×3, return×1.
//  - Notable callees: FUN_005b3370, FUN_006be710.
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

uint8_t * FUN_006be710(uint8_t *param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *local_20c;

  uint local_208;

  uint local_204;

  uint32_t /* width from decompiler */ local_200 [128];

  

  iVar1 = *(int *)(param_2 + 4);

  local_20c = local_200;

  uVar5 = 0x80000080;

  local_204 = 0x80000080;

  local_200[0] = param_3;

  local_208 = 1;

  do {

    iVar2 = local_20c[local_208 - 1];

    local_208 = local_208 - 1;

    iVar3 = iVar2;

    do {

      iVar3 = iVar1 + (uint)*(ushort *)(iVar3 + 4) * 8;

      uVar4 = (uint)*(ushort *)(iVar3 + 6);

      if (uVar4 == 1) {

LAB_006be78b:

        if (uVar4 != param_4) {

          *param_1 = 0;

          goto LAB_006be81a;

        }

LAB_006be798:

        *(uint16_t *)(iVar3 + 6) = (uint16_t)param_4;

        uVar5 = local_204;

      }

      else {

        if (uVar4 != 2) {

          if (uVar4 == 3) goto LAB_006be78b;

          goto LAB_006be798;

        }

        if (param_4 != 3) goto LAB_006be798;

      }

      iVar6 = iVar2;

    } while (iVar3 != iVar2);

    do {

      uVar4 = (uint)*(ushort *)(iVar1 + 2 + (uint)*(ushort *)(iVar6 + 4) * 8);

      iVar6 = iVar1 + (uint)*(ushort *)(iVar6 + 4) * 8;

      if (*(short *)(iVar1 + 6 + uVar4 * 8) == 0) {

        if (local_208 == (uVar5 & 0x7fffffff)) {

          FUN_005b3370(&local_20c,4);

        }

        local_20c[local_208] = iVar1 + uVar4 * 8;

        local_208 = local_208 + 1;

        uVar5 = local_204;

      }

    } while (iVar6 != iVar2);

  } while (local_208 != 0);

  *param_1 = 1;

LAB_006be81a:

  if (-1 < (int)uVar5) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_20c,uVar5 << 2,0x12);

  }

  return param_1;

}
