// =============================================================================
// FUN_00871600
// -----------------------------------------------------------------------------
// Stable ID: aa_00871600
// Address:   0x00871600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00871600 @ 0x00871600
// Stable ID: aa_00871600
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, while×1, return×1.
//  - Notable callees: FUN_004113b0×2, FUN_004294f0, FUN_007fbd30, FUN_00870070, FUN_00871150, FUN_00871600, LeaveCriticalSection.
//  - Return sites: 1.

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

void __fastcall FUN_00871600(int *param_1)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 != '\0') {

    uStack_4 = 0;

    uStack_8 = 0;

    FUN_004294f0();

    iVar2 = FUN_004113b0(param_1 + 0x18a,&uStack_8);

    while (iVar2 == 0) {

      FUN_00871150(uStack_8);

      iVar2 = FUN_004113b0(param_1 + 0x18a,&uStack_8);

    }

    if ((char)param_1[0x194] != '\0') {

      *(uint8_t *)(param_1 + 0x194) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18b));

    }

    FUN_00870070();

    FUN_007fbd30();

  }

  return;

}
