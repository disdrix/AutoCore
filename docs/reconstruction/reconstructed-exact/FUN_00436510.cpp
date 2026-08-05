// =============================================================================
// FUN_00436510
// -----------------------------------------------------------------------------
// Stable ID: aa_00436510
// Address:   0x00436510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00436510 @ 0x00436510
// Stable ID: aa_00436510
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00436510, FUN_004367a0, FUN_004367f0, FUN_00436970.
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

uint FUN_00436510(int param_1,uint param_2,uint param_3)



{

  uint uVar1;

  uint *in_EAX;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  

  uVar6 = ((int)(param_2 - in_EAX[2]) >> 2) * 0x20 + param_1;

  if (param_3 != 0) {

    uVar2 = *in_EAX;

    if (-uVar2 - 1 < param_3) {

      uVar2 = FUN_004367a0();

    }

    FUN_004367f0(uVar2 + 0x1f + param_3 >> 5,0);

    uVar2 = *in_EAX;

    if (uVar2 == 0) {

      *in_EAX = param_3;

      return uVar6;

    }

    uVar1 = in_EAX[2];

    uVar4 = 0;

    param_2 = uVar1;

    if (uVar2 != 0) {

      param_2 = uVar1 + (uVar2 >> 5) * 4;

      uVar4 = uVar2 & 0x1f;

    }

    uVar2 = uVar2 + param_3;

    uVar3 = 0;

    *in_EAX = uVar2;

    uVar5 = uVar1;

    if (uVar2 != 0) {

      uVar5 = uVar1 + (uVar2 >> 5) * 4;

      uVar3 = uVar2 & 0x1f;

    }

    FUN_00436970(uVar6 & 0x1f,uVar1 + (uVar6 >> 5) * 4,uVar4,param_2,uVar3,uVar5);

  }

  return uVar6;

}
