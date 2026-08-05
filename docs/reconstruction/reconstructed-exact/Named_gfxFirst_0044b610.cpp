// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_0044b610, GetTriangleVertexSteps, vog_LogMessage.
//  - Strings: "..\\palantir/graphics/gfxFirst.h"; "Invalid face type in GetTriangleVertexSteps()".
//  - Return sites: 4.

// =============================================================================
// Named_gfxFirst_0044b610
// -----------------------------------------------------------------------------
// Stable ID: aa_0044b610
// Address:   0x0044b610  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxFirst"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Named_gfxFirst_0044b610(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int in_EAX;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  if (in_EAX == 4) {

    *unaff_ESI = 3;

    *param_2 = 3;

    *param_1 = 3;

    return 0;

  }

  if (in_EAX != 5) {

    if (in_EAX != 6) {

      vog_LogMessage("..\\palantir/graphics/gfxFirst.h",0x5b,2,

                     "Invalid face type in GetTriangleVertexSteps()");

      return 0xffffffff;

    }

    *unaff_ESI = 0;

    *param_2 = 1;

    *param_1 = 1;

    return 0;

  }

  *unaff_ESI = 1;

  *param_2 = 1;

  *param_1 = 1;

  return 0;

}
