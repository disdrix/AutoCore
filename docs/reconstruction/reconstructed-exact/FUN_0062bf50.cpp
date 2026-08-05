// =============================================================================
// FUN_0062bf50
// -----------------------------------------------------------------------------
// Stable ID: aa_0062bf50
// Address:   0x0062bf50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062bf50 @ 0x0062bf50
// Stable ID: aa_0062bf50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: while×4, if×4, do×2, return×1.
//  - Notable callees: FUN_0062bf50×2.
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

void FUN_0062bf50(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  uint uVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  int iVar6;

  

  do {

    uVar1 = *(uint *)(param_1 + (param_2 + param_3 >> 1) * 8);

    iVar5 = param_3;

    iVar6 = param_2;

    do {

      uVar2 = *(uint *)(param_1 + iVar6 * 8);

      while (uVar2 < uVar1) {

        iVar6 = iVar6 + 1;

        uVar2 = *(uint *)(param_1 + iVar6 * 8);

      }

      uVar2 = *(uint *)(param_1 + iVar5 * 8);

      while (uVar1 < uVar2) {

        iVar5 = iVar5 + -1;

        uVar2 = *(uint *)(param_1 + iVar5 * 8);

      }

      if (iVar5 < iVar6) break;

      if (iVar5 != iVar6) {

        uVar3 = *(uint32_t /* width from decompiler */ *)(param_1 + 4 + iVar5 * 8);

        uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + iVar5 * 8);

        *(uint32_t /* width from decompiler */ *)(param_1 + iVar5 * 8) = *(uint32_t /* width from decompiler */ *)(param_1 + iVar6 * 8);

        *(uint32_t /* width from decompiler */ *)(param_1 + 4 + iVar5 * 8) = *(uint32_t /* width from decompiler */ *)(param_1 + 4 + iVar6 * 8);

        *(uint32_t /* width from decompiler */ *)(param_1 + iVar6 * 8) = uVar4;

        *(uint32_t /* width from decompiler */ *)(param_1 + 4 + iVar6 * 8) = uVar3;

      }

      iVar5 = iVar5 + -1;

      iVar6 = iVar6 + 1;

    } while (iVar6 <= iVar5);

    if (param_2 < iVar5) {

      FUN_0062bf50(param_1,param_2,iVar5,param_4);

    }

    param_2 = iVar6;

    if (param_3 <= iVar6) {

      return;

    }

  } while( true );

}
