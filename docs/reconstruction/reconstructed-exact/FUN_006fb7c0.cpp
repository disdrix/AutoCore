// =============================================================================
// FUN_006fb7c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006fb7c0
// Address:   0x006fb7c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006fb7c0 @ 0x006fb7c0
// Stable ID: aa_006fb7c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: ABS×3, FUN_006fb7c0.
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

byte __fastcall FUN_006fb7c0(float *param_1)



{

  float *in_EAX;

  

  return (DAT_00bc5638 < ABS(param_1[2] - in_EAX[2])) << 1 |

         (DAT_00bc5634 < ABS(param_1[1] - in_EAX[1])) << 2 |

         (DAT_00bc5630 < ABS(*param_1 - *in_EAX)) * -8 & 0xeU;

}
