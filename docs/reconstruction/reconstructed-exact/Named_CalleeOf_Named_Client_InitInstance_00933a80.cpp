// =============================================================================
// Named_CalleeOf_Named_Client_InitInstance_00933a80
// -----------------------------------------------------------------------------
// Stable ID: aa_00933a80
// Callee of Named_Client_InitInstance
// Address:   0x00933a80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Client_InitInstance: callee helper. Evidence string: "Unable to find any logs in log directory <%s>, with <%s>, skipping test.\n". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Unable to find any logs in log directory <%s>, with <%s>, skipping test.\n"
//   - "Unable to purge log file <%s> in log directory <%s>"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_007a4480×2, _snprintf×2, DeleteFileA, FUN_00933a80, findfirst, findnext, time.
//  - Strings: "%s/%s"; "Unable to purge log file <%s> in log directory <%s>".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_Client_InitInstance
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_Client_InitInstance_00933a80(void)



{

  int iVar1;

  BOOL BVar2;

  int iVar3;

  time_t tVar4;

  uint8_t local_320 [12];

  int local_314;

  uint8_t local_30c [260];

  char local_208 [520];

  

  _snprintf(local_208,0x208,"%s/%s");

  iVar1 = findfirst(local_208,local_320);

  if (iVar1 < 0) {

    FUN_007a4480(0,"Unable to find any logs in log directory <%s>, with <%s>, skipping test.\n");

    return 0;

  }

  tVar4 = time((time_t *)0x0);

  do {

    if (0x3f480 < (int)tVar4 - local_314) {

      _snprintf(local_208,0x208,"%s/%s");

      BVar2 = DeleteFileA(local_208);

      if (BVar2 == 0) {

        FUN_007a4480(0,"Unable to purge log file <%s> in log directory <%s>",local_30c);

      }

    }

    iVar3 = findnext(iVar1,local_320);

  } while (iVar3 == 0);

  return 1;

}
