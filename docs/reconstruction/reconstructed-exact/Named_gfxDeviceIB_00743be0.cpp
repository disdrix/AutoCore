// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00743be0, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceIB.cpp".
//  - Return sites: 2.

// =============================================================================
// Named_gfxDeviceIB_00743be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00743be0
// Address:   0x00743be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxDeviceIB"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_gfxDeviceIB_00743be0(int *param_1,int param_2,int param_3,uint param_4)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ unaff_EDI;

  

  piVar1 = (int *)*param_1;

  if (piVar1 != (int *)0x0) {

    if (((*(byte *)(param_1 + 2) & 2) == 0) || ((param_4 & 0x10) == 0)) {

      iVar2 = (**(code **)(*piVar1 + 0x2c))

                        (piVar1,param_1[4] * param_2,param_1[4] * param_3,&param_4,param_4);

      if (-1 < iVar2) {

        param_1[3] = param_1[3] + 1;

        return unaff_EDI;

      }

    }

    else {

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceIB.cpp",0xaa,1,

                     "Call to gfxDeviceIB::Lock, with Read-only flag set when Index Buffer is Write-only! Doomed to failure..."

                    );

    }

  }

  return 0;

}
