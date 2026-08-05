// =============================================================================
// Net_Nazgul_MsgInclude
// -----------------------------------------------------------------------------
// Stable ID: aa_0046e410
// Address:   0x0046e410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Domain alias Net_Nazgul_MsgInclude for FUN_0046e410 @ 0x0046e410
// Stable ID: aa_0046e410
// Embedded strings (evidence for future rename):
//   - "Unknown msg type: %d"
//   - "c:\\vog\\1_code\\palantir\\platform\\library\\include\\nazgul\\msg\\../../../src/nazgul/ms"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0041b440, FUN_0041b610, Net_Nazgul_MsgInclude, FUN_0076cec0, vog_LogMessage.
//  - Strings: "Unknown msg type: %d".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "c:\vog\1_code\palantir\platform\library\include\nazgul\msg\../../../src/nazgul/ms"
 * Domain alias of FUN_0046e410 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * __thiscall Net_Nazgul_MsgInclude(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  int unaff_EDI;

  

  FUN_0041b610();

  if (param_1 == *(int *)(in_EAX + 4)) {

    uVar1 = FUN_0076cec0(&param_2,"Unknown msg type: %d",param_2);

    vog_LogMessage("c:\\vog\\1_code\\palantir\\platform\\library\\include\\nazgul\\msg\\../../../src/nazgul/msg/msgRouter.h"

                   ,0x89,2,uVar1);

    return (int *)0x0;

  }

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_0041b440();

  piVar3 = (int *)(*(code *)*puVar2)();

  (**(code **)(*piVar3 + 8))(param_3);

  if (unaff_EDI != 0) {

    piVar3[2] = unaff_EDI;

  }

  return piVar3;

}
