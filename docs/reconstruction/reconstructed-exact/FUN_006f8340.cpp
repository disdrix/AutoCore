// =============================================================================
// FUN_006f8340
// -----------------------------------------------------------------------------
// Stable ID: aa_006f8340
// Address:   0x006f8340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f8340 @ 0x006f8340
// Stable ID: aa_006f8340
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006f8340.
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

void __fastcall FUN_006f8340(float *param_1,int param_2,short *param_3,short *param_4)



{

  float fVar1;

  float fVar2;

  bool bVar3;

  bool bVar4;

  bool bVar5;

  float *in_EAX;

  int unaff_ESI;

  float local_30 [4];

  float local_20 [7];

  

  local_30[0] = *param_1;

  local_30[1] = param_1[1];

  local_30[2] = param_1[2];

  local_20[0] = *in_EAX;

  fVar1 = in_EAX[1];

  fVar2 = in_EAX[2];

  local_30[param_2] = 1.0;

  local_20[1] = fVar1;

  local_20[2] = fVar2;

  local_20[unaff_ESI] = 1.0;

  bVar3 = local_20[0] < g_flZero;

  bVar4 = local_20[1] < g_flZero;

  bVar5 = local_20[2] < g_flZero;

  *param_3 = (((ushort)(local_30[2] < g_flZero) << 1 | (ushort)(local_30[1] < g_flZero) << 2 |

              (ushort)(local_30[0] < g_flZero) * -8 & 0xe) + 0x400) * 0x10 + (short)param_2;

  *param_4 = ((byte)(bVar5 << 1 | bVar4 << 2 | bVar3 * -8) & 0xe ^ 0xe) * 0x10 + (short)unaff_ESI;

  return;

}
