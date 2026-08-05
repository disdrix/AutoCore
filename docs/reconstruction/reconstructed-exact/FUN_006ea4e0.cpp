// =============================================================================
// FUN_006ea4e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006ea4e0
// Address:   0x006ea4e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ea4e0 @ 0x006ea4e0
// Stable ID: aa_006ea4e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: while×4, if×4, do×2, return×1.
//  - Notable callees: FUN_006ea4e0×2.
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

void FUN_006ea4e0(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  uint uVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int iVar5;

  

  do {

    uVar1 = *(uint *)(param_1 + (param_2 + param_3 >> 1) * 4);

    iVar4 = param_3;

    iVar5 = param_2;

    do {

      uVar2 = *(uint *)(param_1 + iVar5 * 4);

      while (uVar2 < uVar1) {

        iVar5 = iVar5 + 1;

        uVar2 = *(uint *)(param_1 + iVar5 * 4);

      }

      uVar2 = *(uint *)(param_1 + iVar4 * 4);

      while (uVar1 < uVar2) {

        iVar4 = iVar4 + -1;

        uVar2 = *(uint *)(param_1 + iVar4 * 4);

      }

      if (iVar4 < iVar5) break;

      if (iVar4 != iVar5) {

        uVar3 = *(uint32_t /* width from decompiler */ *)(param_1 + iVar4 * 4);

        *(uint32_t /* width from decompiler */ *)(param_1 + iVar4 * 4) = *(uint32_t /* width from decompiler */ *)(param_1 + iVar5 * 4);

        *(uint32_t /* width from decompiler */ *)(param_1 + iVar5 * 4) = uVar3;

      }

      iVar4 = iVar4 + -1;

      iVar5 = iVar5 + 1;

    } while (iVar5 <= iVar4);

    if (param_2 < iVar4) {

      FUN_006ea4e0(param_1,param_2,iVar4,param_4);

    }

    param_2 = iVar5;

    if (param_3 <= iVar5) {

      return;

    }

  } while( true );

}
