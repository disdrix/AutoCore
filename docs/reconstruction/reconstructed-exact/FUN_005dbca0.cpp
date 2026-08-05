// =============================================================================
// FUN_005dbca0
// -----------------------------------------------------------------------------
// Stable ID: aa_005dbca0
// Address:   0x005dbca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005dbca0 @ 0x005dbca0
// Stable ID: aa_005dbca0
// Embedded strings (evidence for future rename):
//   - "MatDiffuse"
//   - "MatEmissive"
//   - "MatAmbient"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_009700f0×3, FUN_005dbca0, FUN_0096f660.
//  - Strings: "MatDiffuse"; "MatEmissive"; "MatAmbient".
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

uint32_t /* width from decompiler */ __thiscall FUN_005dbca0(int param_1,uint param_2)



{

  float local_10;

  float local_c;

  float local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_8 = DAT_00aaa7a8;

  *(uint *)(param_1 + 400) = param_2;

  local_10 = (float)(param_2 >> 0x10 & 0xff) * local_8;

  local_c = (float)(param_2 >> 8 & 0xff) * local_8;

  local_8 = (float)(param_2 & 0xff) * local_8;

  local_4 = DAT_00a0f298;

  if (*(int *)(param_1 + 0x48) != 0) {

    FUN_009700f0("MatDiffuse",&local_10);

    FUN_009700f0("MatEmissive",&local_10);

    FUN_009700f0("MatAmbient",&local_10);

    FUN_0096f660();

  }

  return 1;

}
