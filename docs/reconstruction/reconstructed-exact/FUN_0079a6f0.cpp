// =============================================================================
// FUN_0079a6f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0079a6f0
// Address:   0x0079a6f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079a6f0 @ 0x0079a6f0
// Stable ID: aa_0079a6f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0079a5e0, FUN_0079a6f0, QueryPerformanceCounter, QueryPerformanceFrequency.
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

int __fastcall FUN_0079a6f0(int param_1,uint8_t param_2)



{

  int in_EAX;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x23c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

  (((LARGE_INTEGER *)(param_1 + 0x230))->s).LowPart = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x234) = 0;

  *(uint8_t *)(param_1 + 8) = param_2;

  *(int *)(param_1 + 0xc) = in_EAX;

  if (in_EAX < 1) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 1;

  }

  FUN_0079a5e0();

  QueryPerformanceFrequency((LARGE_INTEGER *)(param_1 + 0x228));

  *(float *)(param_1 + 0x14) = g_flOne / (float)(longlong)*(LARGE_INTEGER *)(param_1 + 0x228);

  QueryPerformanceCounter((LARGE_INTEGER *)(param_1 + 0x230));

  return param_1;

}
