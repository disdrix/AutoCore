// =============================================================================
// FUN_009142f0
// -----------------------------------------------------------------------------
// Stable ID: aa_009142f0
// Address:   0x009142f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009142f0 @ 0x009142f0
// Stable ID: aa_009142f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_009142f0, fcos, fsin.
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

void __fastcall FUN_009142f0(int param_1)



{

  int in_EAX;

  float10 fVar1;

  

  *(int *)(in_EAX + 0xcc4) = param_1;

  *(uint8_t *)(in_EAX + 0xa82) = 0;

  if (param_1 == 0) {

    fVar1 = (float10)fsin((float10)*(float *)(in_EAX + 0x538));

    *(float *)(in_EAX + 0x5ac) = (float)fVar1;

    fVar1 = (float10)fcos((float10)*(float *)(in_EAX + 0x538));

    *(float *)(in_EAX + 0x5b4) = (float)-fVar1;

  }

  return;

}
