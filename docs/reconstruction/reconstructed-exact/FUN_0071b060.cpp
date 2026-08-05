// =============================================================================
// FUN_0071b060
// -----------------------------------------------------------------------------
// Stable ID: aa_0071b060
// Address:   0x0071b060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071b060 @ 0x0071b060
// Stable ID: aa_0071b060
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_0071b060, FUN_0071d530.
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

void __fastcall FUN_0071b060(uint32_t /* width from decompiler */ param_1,uint *param_2)



{

  int in_EAX;

  uint uVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  

  uVar1 = *param_2 + 7 & 0xfffffff8;

  uVar4 = 0;

  iVar3 = 0;

  *param_2 = uVar1;

  iVar2 = (int)uVar1 >> 2;

  if (0 < iVar2) {

    do {

      uVar4 = uVar4 ^ *(uint *)(in_EAX + iVar3 * 4);

      iVar3 = iVar3 + 1;

    } while (iVar3 < iVar2);

  }

  *(uint *)(in_EAX + iVar3 * 4) = uVar4;

  *param_2 = *param_2 + 8;

  iVar2 = (int)*param_2 >> 3;

  if (0 < iVar2) {

    do {

      FUN_0071d530();

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

  }

  return;

}
