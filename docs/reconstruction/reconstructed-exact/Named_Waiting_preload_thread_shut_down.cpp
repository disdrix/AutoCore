// =============================================================================
// Named_Waiting_preload_thread_shut_down
// -----------------------------------------------------------------------------
// Stable ID: aa_00970a90
// Address:   0x00970a90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_Waiting_preload_thread_shut_down @ 0x00970a90
// Stable ID: aa_00970a90
// Embedded strings (evidence for future rename):
//   - "Waiting for preload thread to shut down (%d)...\n"
//   - "Preload Thread wont exit! terminating it.!\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1, for×1.
//  - Notable callees: FUN_0076c130×2, WaitForSingleObject×2, Named_Waiting_preload_thread_shut_down, InterlockedDecrement, SetEvent, TerminateThread, down.
//  - Strings: "Waiting for preload thread to shut down (%d)...\n"; "Preload Thread wont exit! terminating it.!\n".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Waiting for preload thread to shut down (%d)...
"
 * Domain alias of FUN_00970a90 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_Waiting_preload_thread_shut_down(void)



{

  int iVar1;

  DWORD DVar2;

  int iVar3;

  int unaff_EDI;

  

  iVar1 = *(int *)(unaff_EDI + 0xc);

  iVar3 = 0;

  InterlockedDecrement((LONG *)(iVar1 + 0xc));

  SetEvent(*(HANDLE *)(iVar1 + 4));

  DVar2 = WaitForSingleObject(*(HANDLE *)(unaff_EDI + 8),100);

  if (DVar2 == 0x102) {

    while (iVar3 < 0x14) {

      FUN_0076c130("Waiting for preload thread to shut down (%d)...\n",iVar3);

      iVar3 = iVar3 + 1;

      DVar2 = WaitForSingleObject(*(HANDLE *)(unaff_EDI + 8),100);

      if (DVar2 != 0x102) {

        return 1;

      }

    }

    FUN_0076c130("Preload Thread wont exit! terminating it.!\n");

    TerminateThread(*(HANDLE *)(unaff_EDI + 8),0);

  }

  return 1;

}
