// =============================================================================
// FUN_006f8b10
// -----------------------------------------------------------------------------
// Stable ID: aa_006f8b10
// Address:   0x006f8b10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f8b10 @ 0x006f8b10
// Stable ID: aa_006f8b10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: ABS×3, FUN_006f8b10.
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

void __thiscall FUN_006f8b10(int param_1,uint8_t *param_2,float *param_3)



{

  if ((byte)((ABS(param_3[2]) < *(float *)(param_1 + 0x48)) << 1 |

             (ABS(param_3[1]) < *(float *)(param_1 + 0x44)) << 2 |

            (ABS(*param_3) < *(float *)(param_1 + 0x40)) * -8 & 0xeU) == 0xe) {

    param_3[0xd] = param_3[*(ushort *)(param_3 + 0xe)] * param_3[0xc] -

                   *(float *)(param_1 + 0x20 + (uint)*(ushort *)(param_3 + 0xe) * 4);

    *param_2 = 1;

    return;

  }

  *param_2 = 0;

  return;

}
