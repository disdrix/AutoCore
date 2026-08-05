// =============================================================================
// FUN_00690460
// -----------------------------------------------------------------------------
// Stable ID: aa_00690460
// Address:   0x00690460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00690460 @ 0x00690460
// Stable ID: aa_00690460
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×5, while×2, do×1, return×1.
//  - Notable callees: FUN_0068c5d0, FUN_00690460.
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

void __thiscall FUN_00690460(int *param_1,uint32_t /* width from decompiler */ param_2,short param_3,int param_4)



{

  int iVar1;

  short sVar2;

  int iVar3;

  void *pvVar4;

  int iVar5;

  uint uVar6;

  uint local_8;

  

  if ((*param_1 != 0) && (local_8 = 0, param_1[0xb] != 0)) {

    do {

      iVar3 = 0;

      if (*(int *)(param_4 + 4) != 0) {

        iVar3 = (*(int *)(param_4 + 8) - *(int *)(param_4 + 4)) / 0x38;

      }

      pvVar4 = operator_new__((iVar3 * 2 & 0xffffU) << 1);

      uVar6 = 0;

      while( true ) {

        iVar1 = *(int *)(param_4 + 4);

        if (iVar1 == 0) {

          iVar5 = 0;

        }

        else {

          iVar5 = (*(int *)(param_4 + 8) - iVar1) / 0x38;

        }

        if ((uint)(iVar5 * 2) <= uVar6) break;

        if (iVar1 == 0) {

          sVar2 = 0;

        }

        else {

          sVar2 = (short)((*(int *)(param_4 + 8) - iVar1) / 0x38);

        }

        *(short *)((int)pvVar4 + uVar6 * 2) = param_3 + sVar2 * (short)local_8 * 2 + (short)uVar6;

        uVar6 = uVar6 + 1;

      }

      FUN_0068c5d0(param_2,pvVar4,iVar3 * 2);

      *(short *)(*param_1 + 0x1e) = *(short *)(*param_1 + 0x1e) + 1;

      local_8 = local_8 + 1;

    } while (local_8 < (uint)param_1[0xb]);

  }

  return;

}
