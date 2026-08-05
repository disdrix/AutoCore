// =============================================================================
// FUN_00659f60
// -----------------------------------------------------------------------------
// Stable ID: aa_00659f60
// Address:   0x00659f60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00659f60 @ 0x00659f60
// Stable ID: aa_00659f60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×5, do×2, while×2, return×2.
//  - Notable callees: FUN_00659c40, FUN_00659f60.
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

void FUN_00659f60(uint param_1,uint32_t /* width from decompiler */ param_2,int *param_3,int param_4)



{

  int unaff_EBX;

  uint uVar1;

  

  do {

    uVar1 = 0;

    if (0 < (int)param_1) {

      do {

        if (*(char *)(uVar1 + unaff_EBX) == '>') break;

        uVar1 = uVar1 + 1;

      } while ((int)uVar1 < (int)param_1);

    }

    if ((param_4 != 0) &&

       (FUN_00659c40(*(uint32_t /* width from decompiler */ *)(param_4 + 4),&stack0xfffffff4), -1 < (int)(uVar1 | 0x80000000))

       ) {

      (**(code **)(*DAT_00b05060 + 0x14))();

    }

    if (uVar1 != param_1) {

      (**(code **)(*param_3 + 0x18))();

      (**(code **)(*param_3 + 0xc))(uVar1 + 1);

      return;

    }

    (**(code **)(*param_3 + 0x14))(param_2);

    param_1 = (**(code **)(*param_3 + 8))();

    if (param_1 == 0) {

      return;

    }

  } while( true );

}
