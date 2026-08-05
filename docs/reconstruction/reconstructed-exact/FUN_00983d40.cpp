// =============================================================================
// FUN_00983d40
// -----------------------------------------------------------------------------
// Stable ID: aa_00983d40
// Address:   0x00983d40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00983d40 @ 0x00983d40
// Stable ID: aa_00983d40
// Embedded strings (evidence for future rename):
//   - "Opening %s from disk from pack file."
//   - "C:\\vog\\1_code\\palantir\\palantir\\assets\\assPackManager.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_0076cec0, FUN_00983680, FUN_00983b60, FUN_00983d40, vog_LogMessage.
//  - Strings: "Opening %s from disk from pack file."; "C:\\vog\\1_code\\palantir\\palantir\\assets\\assPackManager.cpp".
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

/* WARNING: Type propagation algorithm not settling */



int FUN_00983d40(void)



{

  int iVar1;

  undefined *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *unaff_EDI;

  int local_8 [2];

  

  local_8[1] = 0;

  local_8[0] = 0;

  iVar1 = FUN_00983680(local_8 + 1,local_8,0);

  if (iVar1 == 0) {

    return 0;

  }

  if (local_8[0] == 0) {

    puVar2 = (undefined *)*unaff_EDI;

    if ((undefined *)*unaff_EDI == (undefined *)0x0) {

      puVar2 = PTR_DAT_00afa2bc;

    }

    uVar3 = FUN_0076cec0(&stack0x00000004,"Opening %s from disk from pack file.",puVar2);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assPackManager.cpp",0xb3,1,uVar3);

    return iVar1;

  }

  iVar1 = FUN_00983b60(0,local_8[0]);

  return iVar1;

}
