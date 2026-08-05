// =============================================================================
// FUN_006469c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006469c0
// Address:   0x006469c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006469c0 @ 0x006469c0
// Stable ID: aa_006469c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006469c0.
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

float10 FUN_006469c0(uint param_1)



{

  byte bVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  

  uVar3 = (param_1 >> 0x17 & 0xff) - 0x7f;

  iVar2 = 0x17 - uVar3;

  param_1 = param_1 & ~((int)((param_1 & 0x7fffffff) - 1) >> 0x1f);

  bVar1 = ~(byte)(iVar2 >> 0x1f);

  uVar4 = -0x800000 >> ((bVar1 & 0x17) - (bVar1 & (byte)iVar2) & 0x1f) | iVar2 >> 0x1f;

  return (float10)(float)((~((~uVar4 & param_1) - 1) & 0x800000 >> ((byte)uVar3 & 0x1f) &

                          (int)param_1 >> 0x1f) + param_1 & ~((int)uVar3 >> 0x1f) & uVar4 |

                         (int)(uVar3 & param_1) >> 0x1f & 0xbf800000U);

}
