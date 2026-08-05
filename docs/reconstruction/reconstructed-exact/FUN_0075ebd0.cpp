// =============================================================================
// FUN_0075ebd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0075ebd0
// Address:   0x0075ebd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075ebd0 @ 0x0075ebd0
// Stable ID: aa_0075ebd0
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp"
//   - "Clear() Failed"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: Clear, FUN_0043b800, FUN_0075ebd0, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp"; "Clear() Failed".
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

uint32_t /* width from decompiler */

FUN_0075ebd0(uint32_t /* width from decompiler */ *param_1,byte param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5)



{

  byte bVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = DAT_00d1f048;

  bVar1 = 0;

  if ((param_2 & 1) != 0) {

    iVar2 = FUN_0043b800();

    bVar1 = -(iVar2 != 0) & 2;

  }

  if ((param_2 & 4) != 0) {

    iVar3 = *(int *)(iVar3 + 8);

    if (iVar3 == 0x49) {

      iVar3 = 1;

    }

    else if (iVar3 == 0x4b) {

      iVar3 = 8;

    }

    else if (iVar3 == 0x4f) {

      iVar3 = 4;

    }

    else {

      iVar3 = 0;

    }

    bVar1 = bVar1 | -(iVar3 != 0) & 4U;

  }

  if ((param_2 & 2) != 0) {

    bVar1 = bVar1 | 1;

  }

  if (bVar1 != 0) {

    iVar3 = (**(code **)(*(int *)*param_1 + 0xac))

                      ((int *)*param_1,0,0,bVar1,*param_3,param_4,param_5);

    if (iVar3 < 0) {

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp",0x19d,3,

                     "Clear() Failed");

      return 0xffffffff;

    }

  }

  return 0;

}
