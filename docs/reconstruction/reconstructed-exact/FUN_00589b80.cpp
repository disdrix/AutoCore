// =============================================================================
// FUN_00589b80
// -----------------------------------------------------------------------------
// Stable ID: aa_00589b80
// Address:   0x00589b80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00589b80 @ 0x00589b80
// Stable ID: aa_00589b80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: NAN×2, CONCAT21, FUN_00589b80.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint FUN_00589b80(float param_1,byte param_2)



{

  uint32_t /* width from decompiler */ in_EAX;

  uint uVar1;

  

  uVar1 = (uint)CONCAT21((short)((uint)in_EAX >> 0x10),

                         (param_1 == g_flZero) << 6 | (NAN(param_1) || NAN(g_flZero)) << 2 | 2U |

                         param_1 < g_flZero) << 8;

  if ((param_1 != g_flZero) && (uVar1 = (uint)param_2, param_1 < (float)uVar1 * _DAT_009d4d20)) {

    return 1;

  }

  return uVar1 & 0xffffff00;

}
