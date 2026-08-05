// =============================================================================
// FUN_004362c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004362c0
// Address:   0x004362c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004362c0 @ 0x004362c0
// Stable ID: aa_004362c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_004362c0, FUN_00436410, FUN_004364b0.
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

void __thiscall FUN_004362c0(uint *param_1,uint32_t /* width from decompiler */ param_2)



{

  uint uVar1;

  uint in_EAX;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  

  uVar1 = *param_1;

  if (uVar1 < in_EAX) {

    uVar4 = param_1[2];

    uVar2 = 0;

    if (uVar1 != 0) {

      uVar4 = uVar4 + (uVar1 >> 5) * 4;

      uVar2 = uVar1 & 0x1f;

    }

    FUN_004364b0(uVar2,uVar4,param_2);

    return;

  }

  if (in_EAX < uVar1) {

    uVar2 = param_1[2];

    uVar3 = 0;

    uVar4 = uVar2;

    if (uVar1 != 0) {

      uVar4 = uVar2 + (uVar1 >> 5) * 4;

      uVar3 = uVar1 & 0x1f;

    }

    FUN_00436410(in_EAX & 0x1f,uVar2 + (in_EAX >> 5) * 4,uVar3,uVar4);

  }

  return;

}
