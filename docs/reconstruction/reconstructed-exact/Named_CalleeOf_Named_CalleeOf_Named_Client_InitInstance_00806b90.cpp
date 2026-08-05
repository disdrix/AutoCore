// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_00806b90
// -----------------------------------------------------------------------------
// Stable ID: aa_00806b90
// Callee of Named_CalleeOf_Named_Client_InitInstance
// Address:   0x00806b90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×13, goto×5, return×2.
//  - Notable callees: GetTickCount×4, FUN_00806170×2, FUN_008066f0, FUN_00806b90.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Client_InitInstance
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

void Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_00806b90(char param_1,char param_2)



{

  int iVar1;

  int in_EAX;

  DWORD DVar2;

  char cVar3;

  int unaff_ESI;

  char unaff_retaddr;

  

  if (*(char *)(unaff_ESI + 0xd1d) == '\0') {

    return;

  }

  if (in_EAX != 0) {

    *(int *)(unaff_ESI + 0xd18) = in_EAX;

  }

  cVar3 = *(char *)(unaff_ESI + 0xd1c);

  if (cVar3 == '\0') {

LAB_00806bd6:

    if (DAT_00d1b6d8 != 0) {

      param_2 = '\x01';

      goto LAB_00806be3;

    }

LAB_00806bde:

    if (param_2 != '\x05') goto LAB_00806be3;

  }

  else {

    if (DAT_00d1b6d8 != 0) {

      if (cVar3 == '\0') goto LAB_00806bd6;

      goto LAB_00806bde;

    }

    param_2 = '\0';

LAB_00806be3:

    if (param_2 != cVar3) {

      if ((*(char *)(unaff_ESI + 0xd1e) == '\x05') && (in_EAX != 0)) {

        *(char *)(unaff_ESI + 0xd1e) = cVar3;

      }

      *(char *)(unaff_ESI + 0xd1c) = param_2;

      FUN_00806170();

      cVar3 = '\x01';

      goto LAB_00806c4a;

    }

  }

  cVar3 = param_1;

  if ((*(char *)(unaff_ESI + 0xd1e) != '\x05') &&

     (DVar2 = GetTickCount(), *(uint *)(unaff_ESI + 0xd18) < DVar2 - *(int *)(unaff_ESI + 0xd14))) {

    *(uint8_t *)(unaff_ESI + 0xd1c) = *(uint8_t *)(unaff_ESI + 0xd1e);

    *(uint8_t *)(unaff_ESI + 0xd1e) = 5;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xd18) = 0;

    FUN_00806170();

    cVar3 = '\x01';

  }

LAB_00806c4a:

  if (param_1 != '\0') {

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xcd4) = 0xff;

  }

  iVar1 = *(int *)(unaff_ESI + 0xc48);

  DVar2 = GetTickCount();

  (**(code **)(iVar1 + 0x70))(DVar2);

  if ((cVar3 != '\0') || (DVar2 = GetTickCount(), 1000 < DVar2 - *(int *)(unaff_ESI + 0xd14))) {

    DVar2 = GetTickCount();

    *(DWORD *)(unaff_ESI + 0xd14) = DVar2;

    FUN_008066f0();

    (**(code **)(*(int *)(unaff_ESI + 0xc48) + 0x6c))();

  }

  if (unaff_retaddr != '\0') {

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xcd4) = 0x80;

  }

  return;

}
