// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_00416160×2, FUN_0096b000, GetBoneTransform, UpdateWorldState, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\physics\\phySkeleton.cpp".
//  - Return sites: 3.

// =============================================================================
// Named_phySkeleton_0096b000
// -----------------------------------------------------------------------------
// Stable ID: aa_0096b000
// Address:   0x0096b000  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "phySkeleton"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Named_phySkeleton_0096b000(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  int unaff_EDI;

  

  if (param_2[1] == 0) {

    if (unaff_EDI == -1) {

      FUN_00416160(*param_2);

      return 0;

    }

    if (param_2[3] == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (int)(param_2[4] - param_2[3]) >> 2;

    }

    if (unaff_EDI < iVar1) {

      FUN_00416160(*(int *)(param_2[3] + unaff_EDI * 4) + 0x30);

      return 0;

    }

  }

  else {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\physics\\phySkeleton.cpp",0x25d,3,

                   "GetBoneTransform() called on dirty skeleton. Call UpdateWorldState() first.");

  }

  return 0xffffffff;

}
