// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_008e3940
// -----------------------------------------------------------------------------
// Stable ID: aa_008e3940
// Callee of Named_CalleeOf_Client_RefreshOpenMissionUiWindows
// Address:   0x008e3940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RefreshOpenMissionUiWindows: mission/objective helper. Evidence string: "You are not near a crafting station!". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "You are not near a crafting station!"
//   - "You need to be near a Fabrication Plant!"
//   - "You need to be near a Control Shop!"
//   - "You need to be near a Reactor!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×5, return×4.
//  - Notable callees: sprintf×4, FUN_0052b040, FUN_008e3940.
//  - Strings: "You are not near a crafting station!"; "You need to be near a Fabrication Plant!"; "You need to be near a Control Shop!"; "You need to be near a Reactor!".
//  - Return sites: 4.

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

void Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_008e3940(void)



{

  char cVar1;

  int in_EAX;

  char *unaff_ESI;

  uint8_t local_1fc [496];

  int local_c;

  int local_8;

  int local_4;

  

  if ((unaff_ESI != (char *)0x0) && (in_EAX != 0)) {

    cVar1 = FUN_0052b040(*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(in_EAX + 0xa8) + 0x3c) + 0x4ac),local_1fc

                        );

    if (cVar1 == '\0') {

      sprintf(unaff_ESI,"You are not near a crafting station!");

      return;

    }

    if (local_c != 0) {

      sprintf(unaff_ESI,"You need to be near a Fabrication Plant!");

      return;

    }

    if (local_4 != 0) {

      sprintf(unaff_ESI,"You need to be near a Control Shop!");

      return;

    }

    if (local_8 != 0) {

      sprintf(unaff_ESI,"You need to be near a Reactor!");

    }

  }

  return;

}
