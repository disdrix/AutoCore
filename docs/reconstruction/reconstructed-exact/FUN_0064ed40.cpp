// =============================================================================
// FUN_0064ed40
// -----------------------------------------------------------------------------
// Stable ID: aa_0064ed40
// Address:   0x0064ed40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0064ed40 @ 0x0064ed40
// Stable ID: aa_0064ed40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_005b3300×3, FUN_0064e840, FUN_0065e2d0, hkDefaultBrake_ctor.
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

uint32_t /* width from decompiler */ * __thiscall hkDefaultBrake_ctor(uint32_t /* width from decompiler */ *param_1,char *param_2)



{

  int iVar1;

  int iVar2;

  

  FUN_0065e2d0(param_2);

  *param_1 = &PTR_FUN_009e4cb8;

  param_1[10] = 0;

  param_1[0xb] = 0;

  param_1[0xc] = 0x80000000;

  param_1[0xd] = 0;

  param_1[0xe] = 0;

  param_1[0xf] = 0x80000000;

  param_1[0x10] = 0;

  param_1[0x11] = 0;

  param_1[0x12] = 0x80000000;

  iVar2 = (int)*param_2;

  if ((int)(param_1[0xc] & 0x7fffffff) < iVar2) {

    iVar1 = (param_1[0xc] & 0x7fffffff) * 2;

    if (iVar1 <= iVar2) {

      iVar1 = iVar2;

    }

    FUN_005b3300(param_1 + 10,iVar1,4);

  }

  param_1[0xb] = iVar2;

  iVar2 = (int)*param_2;

  if ((int)(param_1[0xf] & 0x7fffffff) < iVar2) {

    iVar1 = (param_1[0xf] & 0x7fffffff) * 2;

    if (iVar1 <= iVar2) {

      iVar1 = iVar2;

    }

    FUN_005b3300(param_1 + 0xd,iVar1,4);

  }

  param_1[0xe] = iVar2;

  iVar2 = (int)*param_2;

  if ((int)(param_1[0x12] & 0x7fffffff) < iVar2) {

    iVar1 = (param_1[0x12] & 0x7fffffff) * 2;

    if (iVar1 <= iVar2) {

      iVar1 = iVar2;

    }

    FUN_005b3300(param_1 + 0x10,iVar1,1);

  }

  param_1[0x11] = iVar2;

  FUN_0064e840(param_2);

  return param_1;

}
