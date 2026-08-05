// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_008bd070
// -----------------------------------------------------------------------------
// Stable ID: aa_008bd070
// Callee of Named_CalleeOf_Client_RefreshOpenMissionUiWindows
// Address:   0x008bd070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RefreshOpenMissionUiWindows: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×2, while×1, return×1.
//  - Notable callees: block×26, FUN_004073a0, FUN_00410420, FUN_008bd070.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RefreshOpenMissionUiWindows
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x008bd130) */

/* WARNING: Removing unreachable block (ram,0x008bd13f) */

/* WARNING: Removing unreachable block (ram,0x008bd155) */

/* WARNING: Removing unreachable block (ram,0x008bd147) */

/* WARNING: Removing unreachable block (ram,0x008bd15b) */

/* WARNING: Removing unreachable block (ram,0x008bd167) */

/* WARNING: Removing unreachable block (ram,0x008bd16d) */

/* WARNING: Removing unreachable block (ram,0x008bd18c) */

/* WARNING: Removing unreachable block (ram,0x008bd190) */

/* WARNING: Removing unreachable block (ram,0x008bd192) */

/* WARNING: Removing unreachable block (ram,0x008bd180) */

/* WARNING: Removing unreachable block (ram,0x008bd184) */

/* WARNING: Removing unreachable block (ram,0x008bd186) */

/* WARNING: Removing unreachable block (ram,0x008bd196) */

/* WARNING: Removing unreachable block (ram,0x008bd18a) */

/* WARNING: Removing unreachable block (ram,0x008bd19c) */

/* WARNING: Removing unreachable block (ram,0x008bd1a5) */

/* WARNING: Removing unreachable block (ram,0x008bd1ac) */

/* WARNING: Removing unreachable block (ram,0x008bd1bb) */

/* WARNING: Removing unreachable block (ram,0x008bd1d3) */

/* WARNING: Removing unreachable block (ram,0x008bd1b7) */

/* WARNING: Removing unreachable block (ram,0x008bd1e0) */

/* WARNING: Removing unreachable block (ram,0x008bd1ee) */

/* WARNING: Removing unreachable block (ram,0x008bd0e8) */

/* WARNING: Removing unreachable block (ram,0x008bd224) */

/* WARNING: Removing unreachable block (ram,0x008bd0d4) */



void __fastcall Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_008bd070(int param_1)



{

  int iVar1;

  int iVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ad282;

  local_c = ExceptionList;

  iVar2 = 0;

  local_4 = 0;

  ExceptionList = &local_c;

  while( true ) {

    if (*(int *)(param_1 + 0x550) == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = *(int *)(param_1 + 0x554) - *(int *)(param_1 + 0x550) >> 2;

    }

    if (iVar1 <= iVar2) break;

    FUN_004073a0(0,1,*(int *)(param_1 + 0x550) + iVar2 * 4);

    iVar2 = iVar2 + 1;

  }

  FUN_00410420(0,0);

  ExceptionList = local_c;

  return;

}
