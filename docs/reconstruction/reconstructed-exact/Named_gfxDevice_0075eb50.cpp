// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0075eb50, StretchRect, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp"; "StretchRect() failed copying backbuffer".
//  - Return sites: 2.

// =============================================================================
// Named_gfxDevice_0075eb50
// -----------------------------------------------------------------------------
// Stable ID: aa_0075eb50
// Address:   0x0075eb50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxDevice"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_gfxDevice_0075eb50(int *param_1)



{

  uint32_t /* width from decompiler */ *in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_8 = in_EAX[0xae];

  local_4 = in_EAX[0xaf];

  local_10 = 0;

  local_c = 0;

  iVar1 = (**(code **)(*(int *)*in_EAX + 0x88))

                    ((int *)*in_EAX,in_EAX[2],0,*(uint32_t /* width from decompiler */ *)(*param_1 + 0x14),&local_10,0);

  if (iVar1 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp",0x1c6,3,

                   "StretchRect() failed copying backbuffer");

    return 0xffffffff;

  }

  return 0;

}
