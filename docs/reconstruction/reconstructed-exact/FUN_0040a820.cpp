// =============================================================================
// FUN_0040a820
// -----------------------------------------------------------------------------
// Stable ID: aa_0040a820
// Address:   0x0040a820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040a820 @ 0x0040a820
// Stable ID: aa_0040a820
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_0040a820, FUN_0040a8f0.
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

void FUN_0040a820(int param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  iVar1 = param_2 - param_1 >> 4;

  iVar2 = iVar1 - (param_2 - param_1 >> 0x1f) >> 1;

  if (0 < iVar2) {

    puVar3 = (uint32_t /* width from decompiler */ *)(iVar2 * 0x10 + param_1);

    do {

      iVar2 = iVar2 + -1;

      FUN_0040a8f0(param_1,iVar1,puVar3[-4],puVar3[-3],puVar3[-2],puVar3[-1],param_3);

      puVar3 = puVar3 + -4;

    } while (0 < iVar2);

  }

  return;

}
