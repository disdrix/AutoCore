// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0076cec0×2, vog_LogMessage×2, FUN_00985fe0.
//  - Strings: "Light Managers has %d still active."; "Light Managers has %d inactive.".
//  - Return sites: 1.

// =============================================================================
// Named_gfxLightManagerFactory_00985fe0
// -----------------------------------------------------------------------------
// Stable ID: aa_00985fe0
// Address:   0x00985fe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxLightManagerFactory"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_gfxLightManagerFactory_00985fe0(void)



{

  int in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int local_4;

  

  if ((*(int *)(in_EAX + 4) != 0) &&

     (iVar1 = *(int *)(in_EAX + 8) - *(int *)(in_EAX + 4) >> 2, iVar1 != 0)) {

    uVar2 = FUN_0076cec0(&local_4,"Light Managers has %d still active.",iVar1);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLightManagerFactory.cpp",0x90,

                   2,uVar2);

  }

  iVar1 = *(int *)(in_EAX + 0x14);

  if ((iVar1 != 0) && (local_4 = *(int *)(in_EAX + 0x18) - iVar1 >> 2, local_4 != 0)) {

    if (iVar1 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = *(int *)(in_EAX + 0x18) - iVar1 >> 2;

    }

    uVar2 = FUN_0076cec0(&local_4,"Light Managers has %d inactive.",iVar1);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLightManagerFactory.cpp",0x94,

                   2,uVar2);

  }

  return;

}
