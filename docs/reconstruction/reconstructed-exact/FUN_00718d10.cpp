// =============================================================================
// FUN_00718d10
// -----------------------------------------------------------------------------
// Stable ID: aa_00718d10
// Address:   0x00718d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00718d10 @ 0x00718d10
// Stable ID: aa_00718d10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, while×1.
//  - Notable callees: FUN_00767050×2, FUN_00767340×2, CONCAT22, FUN_00718d10.
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

void FUN_00718d10(uint32_t /* width from decompiler */ *param_1,short *param_2)



{

  short sVar1;

  uint in_EAX;

  short *psVar2;

  uint uVar3;

  short *psVar4;

  

  if (param_2 != (short *)0x0) {

    sVar1 = *param_2;

    psVar4 = param_2;

    while (sVar1 != 0) {

      psVar2 = (short *)CONCAT22((short)(in_EAX >> 0x10),*psVar4);

      if (param_1[7] == 0) {

        param_2 = psVar2;

        in_EAX = (**(code **)(*(int *)*param_1 + 0x18))(&param_2,2);

      }

      else {

        uVar3 = FUN_00767340(psVar2);

        param_1[1] = param_1[1] | uVar3;

        in_EAX = FUN_00767050();

      }

      param_1[1] = param_1[1] | in_EAX;

      psVar4 = psVar4 + 1;

      sVar1 = *psVar4;

    }

  }

  if (param_1[7] != 0) {

    uVar3 = FUN_00767340(0);

    param_1[1] = param_1[1] | uVar3;

    uVar3 = FUN_00767050();

    param_1[1] = param_1[1] | uVar3;

    return;

  }

  param_2 = (short *)0x0;

  uVar3 = (**(code **)(*(int *)*param_1 + 0x18))(&param_2,2);

  param_1[1] = param_1[1] | uVar3;

  return;

}
