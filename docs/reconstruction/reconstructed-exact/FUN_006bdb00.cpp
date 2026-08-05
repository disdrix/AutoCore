// =============================================================================
// FUN_006bdb00
// -----------------------------------------------------------------------------
// Stable ID: aa_006bdb00
// Address:   0x006bdb00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006bdb00 @ 0x006bdb00
// Stable ID: aa_006bdb00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, while×2, return×1.
//  - Notable callees: FUN_005b3300, FUN_005b3370, FUN_006bdb00.
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

void FUN_006bdb00(int param_1,uint32_t /* width from decompiler */ param_2,int param_3,int *param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  

  iVar4 = *(int *)(param_1 + 8);

  if ((int)(param_4[2] & 0x7fffffffU) < iVar4) {

    iVar5 = (param_4[2] & 0x7fffffffU) * 2;

    if (iVar5 <= iVar4) {

      iVar5 = iVar4;

    }

    FUN_005b3300(param_4,iVar5,2);

  }

  param_4[1] = iVar4;

  iVar4 = *(int *)(param_3 + 8);

  iVar5 = 0;

  if (0 < *(int *)(param_1 + 8)) {

    do {

      puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 4) + iVar5 * 8);

      if ((*(short *)((int)puVar1 + 6) == 1) || (*(short *)((int)puVar1 + 6) == 2)) {

        *(uint16_t *)(*param_4 + iVar5 * 2) = *(uint16_t *)(param_3 + 8);

        if (*(uint *)(param_3 + 8) == (*(uint *)(param_3 + 0xc) & 0x7fffffff)) {

          FUN_005b3370((int *)(param_3 + 4),8);

        }

        iVar2 = *(int *)(param_3 + 8);

        iVar3 = *(int *)(param_3 + 4);

        *(uint32_t /* width from decompiler */ *)(iVar3 + iVar2 * 8) = *puVar1;

        *(uint32_t /* width from decompiler */ *)(iVar3 + 4 + iVar2 * 8) = puVar1[1];

        *(int *)(param_3 + 8) = *(int *)(param_3 + 8) + 1;

      }

      else {

        *(uint16_t *)(*param_4 + iVar5 * 2) = 0xffff;

      }

      iVar5 = iVar5 + 1;

    } while (iVar5 < *(int *)(param_1 + 8));

  }

  if (iVar4 < *(int *)(param_3 + 8)) {

    do {

      iVar5 = *(int *)(param_3 + 4) + iVar4 * 8;

      *(uint16_t *)(iVar5 + 2) = *(uint16_t *)(*param_4 + (uint)*(ushort *)(iVar5 + 2) * 2);

      *(uint16_t *)(iVar5 + 4) = *(uint16_t *)(*param_4 + (uint)*(ushort *)(iVar5 + 4) * 2);

      iVar4 = iVar4 + 1;

    } while (iVar4 < *(int *)(param_3 + 8));

  }

  return;

}
