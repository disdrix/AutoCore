// =============================================================================
// FUN_00811750
// -----------------------------------------------------------------------------
// Stable ID: aa_00811750
// Address:   0x00811750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00811750 @ 0x00811750
// Stable ID: aa_00811750
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_007fef20×2, FUN_007fc840, FUN_00811750, FUN_00870290, FUN_00870680, FUN_009423b0, __RTDynamicCast.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_00811750(void)



{

  int in_EAX;

  int iVar1;

  int unaff_EBX;

  

  if (*(int *)(in_EAX + 0xe98) == 0) {

    return 0;

  }

  iVar1 = __RTDynamicCast(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x10cc),0,&CVOGDialog::RTTI_Type_Descriptor,

                          &CDlgArenaResults::RTTI_Type_Descriptor,0);

  if (iVar1 == 0) {

    return 0;

  }

  if (*(char *)(unaff_EBX + 8) == '\x01') {

    FUN_009423b0(in_EAX,1,1);

    if ((DAT_00d1b778 != 0) && (*(int *)(in_EAX + 0xe98) != 0)) {

      (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) + 4 +

                           *(int *)(in_EAX + 0xe98)) + 0x188))(0x2000);

    }

  }

  FUN_007fc840();

  FUN_007fef20(0x27,1,1);

  FUN_007fef20(0x1b,1,0);

  FUN_00870290();

  FUN_00870680(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 4));

  return 1;

}
