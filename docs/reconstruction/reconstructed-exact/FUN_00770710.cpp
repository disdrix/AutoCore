// =============================================================================
// FUN_00770710
// -----------------------------------------------------------------------------
// Stable ID: aa_00770710
// Address:   0x00770710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00770710 @ 0x00770710
// Stable ID: aa_00770710
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×5, return×5, do×1, while×1.
//  - Notable callees: FUN_00770710.
//  - Return sites: 5.

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

uint32_t /* width from decompiler */ __fastcall FUN_00770710(uint32_t /* width from decompiler */ param_1,int *param_2)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  int *in_EAX;

  uint *puVar4;

  int iVar5;

  int iVar6;

  

  iVar1 = *in_EAX;

  if (*param_2 < iVar1) {

    return 1;

  }

  if (iVar1 < *param_2) {

    return 0xffffffff;

  }

  iVar6 = 0;

  puVar4 = (uint *)(in_EAX[3] + -4 + iVar1 * 4);

  if (0 < iVar1) {

    iVar5 = (param_2[3] + -4 + iVar1 * 4) - (int)puVar4;

    do {

      uVar2 = *(uint *)(iVar5 + (int)puVar4);

      uVar3 = *puVar4;

      if (uVar3 >= uVar2 && uVar3 != uVar2) {

        return 1;

      }

      if (uVar3 < uVar2) {

        return 0xffffffff;

      }

      iVar6 = iVar6 + 1;

      puVar4 = puVar4 + -1;

    } while (iVar6 < iVar1);

  }

  return 0;

}
