// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, for×1.
//  - Notable callees: FUN_00745ea0×2, FUN_0074fd90, FUN_0076cec0, NDResource_AcquireInnerObject, vog_LogMessage.
//  - Strings: "Setting asset handle for <%x> to an unrelated asset <%x>.".
//  - Return sites: 2.

// =============================================================================
// Named_effDeviceEffect_0074fd90
// -----------------------------------------------------------------------------
// Stable ID: aa_0074fd90
// Address:   0x0074fd90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "effDeviceEffect"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_effDeviceEffect_0074fd90(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *unaff_EDI;

  uint8_t local_4 [4];

  

  iVar1 = NDResource_AcquireInnerObject();

  if (iVar1 == unaff_ESI) {

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1cc) = *unaff_EDI;

    FUN_00745ea0();

    return;

  }

  uVar2 = FUN_0076cec0(local_4,"Setting asset handle for <%x> to an unrelated asset <%x>.");

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effDeviceEffect.cpp",0x77,

                 5,uVar2);

  FUN_00745ea0();

  return;

}
