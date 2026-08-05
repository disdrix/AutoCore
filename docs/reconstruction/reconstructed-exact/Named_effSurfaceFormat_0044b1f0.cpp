// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×14, return×9, goto×9, switch×2.
//  - Notable callees: FUN_0044b1f0, FUN_0076cec0, vog_LogMessage.
//  - Strings: "Unknown Texture format : format:%u width:%u height:%u"; "..\\palantir/graphics/Effects/effSurfaceFormat.h".
//  - Return sites: 9.

// =============================================================================
// Named_effSurfaceFormat_0044b1f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0044b1f0
// Address:   0x0044b1f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "effSurfaceFormat"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __fastcall Named_effSurfaceFormat_0044b1f0(int param_1)



{

  int in_EAX;

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  int unaff_ESI;

  bool bVar4;

  int local_10;

  int local_c;

  int local_8;

  int local_4;

  

  piVar3 = &local_10;

  if (param_1 < 0x50) {

    if (param_1 == 0x4f) {

switchD_0044b20d_caseD_14:

      return in_EAX * unaff_ESI * 3;

    }

    switch(param_1) {

    case 0x14:

    case 0x4b:

    case 0x4d:

      goto switchD_0044b20d_caseD_14;

    case 0x15:

    case 0x16:

    case 0x23:

    case 0x3f:

    case 0x40:

    case 0x47:

      goto switchD_0044b20d_caseD_15;

    case 0x17:

    case 0x18:

    case 0x19:

    case 0x1a:

    case 0x33:

    case 0x3c:

    case 0x49:

switchD_0044b20d_caseD_17:

      return in_EAX * unaff_ESI * 2;

    case 0x1c:

    case 0x32:

      return in_EAX * unaff_ESI;

    case 0x24:

switchD_0044b20d_caseD_24:

      return in_EAX * unaff_ESI * 8;

    }

  }

  else {

    if (param_1 < 0x75) {

      if (param_1 == 0x74) {

        return in_EAX * unaff_ESI * 0x10;

      }

      switch(param_1) {

      case 0x50:

      case 0x6f:

        goto switchD_0044b20d_caseD_17;

      default:

        goto switchD_0044b20d_caseD_1b;

      case 0x6e:

      case 0x71:

      case 0x73:

        goto switchD_0044b20d_caseD_24;

      case 0x70:

      case 0x72:

        goto switchD_0044b20d_caseD_15;

      }

    }

    if (param_1 < 0x33545845) {

      if (param_1 == 0x33545844) goto LAB_0044b326;

      if (param_1 == 0x75) goto switchD_0044b20d_caseD_17;

      if (param_1 == 0x31545844) {

        local_c = (int)(in_EAX + (in_EAX >> 0x1f & 3U)) >> 2;

        local_4 = (int)(unaff_ESI + (unaff_ESI >> 0x1f & 3U)) >> 2;

        local_10 = 1;

        local_8 = 1;

        if (0 < local_c) {

          piVar3 = &local_c;

        }

        piVar1 = &local_8;

        if (0 < local_4) {

          piVar1 = &local_4;

        }

        return *piVar1 * *piVar3 * 8;

      }

      bVar4 = param_1 == 0x32545844;

    }

    else {

      if (param_1 == 0x34545844) goto LAB_0044b326;

      bVar4 = param_1 == 0x35545844;

    }

    if (bVar4) {

LAB_0044b326:

      local_8 = (int)(in_EAX + (in_EAX >> 0x1f & 3U)) >> 2;

      local_10 = (int)(unaff_ESI + (unaff_ESI >> 0x1f & 3U)) >> 2;

      local_4 = 1;

      local_c = 1;

      piVar3 = &local_4;

      if (0 < local_8) {

        piVar3 = &local_8;

      }

      piVar1 = &local_c;

      if (0 < local_10) {

        piVar1 = &local_10;

      }

      return *piVar1 * *piVar3 * 0x10;

    }

  }

switchD_0044b20d_caseD_1b:

  uVar2 = FUN_0076cec0(&local_4,"Unknown Texture format : format:%u width:%u height:%u",param_1);

  vog_LogMessage("..\\palantir/graphics/Effects/effSurfaceFormat.h",0x1f2,3,uVar2);

  return 0;

switchD_0044b20d_caseD_15:

  return in_EAX * unaff_ESI * 4;

}
