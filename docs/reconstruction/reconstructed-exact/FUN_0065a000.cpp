// =============================================================================
// FUN_0065a000
// -----------------------------------------------------------------------------
// Stable ID: aa_0065a000
// Address:   0x0065a000  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0065a000 @ 0x0065a000
// Stable ID: aa_0065a000
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×5, do×2, while×2, return×2.
//  - Notable callees: FUN_00659c40, FUN_0065a000.
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

void FUN_0065a000(int param_1,uint32_t /* width from decompiler */ param_2,int *param_3,int param_4)



{

  uint in_EAX;

  uint uVar1;

  int local_c;

  uint local_8;

  uint local_4;

  

  local_c = param_1;

  do {

    uVar1 = 0;

    if (0 < (int)in_EAX) {

      do {

        if (*(char *)(uVar1 + param_1) == '<') break;

        uVar1 = uVar1 + 1;

      } while ((int)uVar1 < (int)in_EAX);

    }

    local_8 = uVar1;

    local_4 = uVar1 | 0x80000000;

    FUN_00659c40(*(uint32_t /* width from decompiler */ *)(param_4 + 4),&local_c);

    if (-1 < (int)(uVar1 | 0x80000000)) {

      (**(code **)(*DAT_00b05060 + 0x14))(param_1,uVar1 & 0x7fffffff,0x12);

    }

    if (uVar1 != in_EAX) {

      (**(code **)(*param_3 + 0x18))();

      (**(code **)(*param_3 + 0xc))(uVar1);

      return;

    }

    (**(code **)(*param_3 + 0x14))(param_2);

    in_EAX = (**(code **)(*param_3 + 8))(param_1,param_2);

    if (in_EAX == 0) {

      return;

    }

  } while( true );

}
