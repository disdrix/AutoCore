// =============================================================================
// FUN_0043f5e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0043f5e0
// Address:   0x0043f5e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0043f5e0 @ 0x0043f5e0
// Stable ID: aa_0043f5e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, while×1.
//  - Notable callees: FUN_0043f5e0.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_0043f5e0(float *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  float *pfVar3;

  int unaff_EBX;

  uint uVar4;

  float fVar5;

  float in_XMM1_Da;

  

  iVar1 = *(int *)(unaff_EBX + 4);

  uVar2 = 0;

  uVar4 = 0;

  pfVar3 = (float *)(iVar1 + 4);

  while( true ) {

    if (iVar1 == 0) {

      return uVar2;

    }

    if ((uint)(*(int *)(unaff_EBX + 8) - iVar1 >> 4) <= uVar4) break;

    fVar5 = pfVar3[1] * param_1[2] + param_1[1] * *pfVar3 + pfVar3[-1] * *param_1 + pfVar3[2];

    if (fVar5 < 0.0 - in_XMM1_Da) {

      return 0xffffffff;

    }

    if (fVar5 < in_XMM1_Da) {

      uVar2 = 1;

    }

    uVar4 = uVar4 + 1;

    pfVar3 = pfVar3 + 4;

  }

  return uVar2;

}
