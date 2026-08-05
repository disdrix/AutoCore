// =============================================================================
// FUN_009871c0
// -----------------------------------------------------------------------------
// Stable ID: aa_009871c0
// Address:   0x009871c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009871c0 @ 0x009871c0
// Stable ID: aa_009871c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_00457e40×3, FUN_0044c370, FUN_00986e90, FUN_009871c0.
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

int * FUN_009871c0(uint32_t /* width from decompiler */ param_1)



{

  uint32_t /* width from decompiler */ in_EAX;

  int *piVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  piVar1 = (int *)FUN_00986e90(in_EAX);

  if (piVar1 == (int *)0x0) {

    return (int *)0x0;

  }

  iVar2 = (**(code **)(*piVar1 + 0x18))(param_1);

  if (iVar2 == -2) {

    piVar3 = (int *)FUN_0044c370(piVar1[2],piVar1[3]);

    (**(code **)*piVar1)(1);

    piVar1 = (int *)0x0;

    if (piVar3 != (int *)0x0) {

      piVar1 = (int *)FUN_00457e40();

      piVar4 = (int *)FUN_00457e40();

      *piVar4 = *piVar1 + 1;

      return piVar3;

    }

  }

  else {

    puVar5 = (uint32_t /* width from decompiler */ *)FUN_00457e40();

    *puVar5 = 1;

  }

  return piVar1;

}
