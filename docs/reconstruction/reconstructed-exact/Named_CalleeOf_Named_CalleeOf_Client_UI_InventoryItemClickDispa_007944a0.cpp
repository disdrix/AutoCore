// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_UI_InventoryItemClickDispa_007944a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007944a0
// Callee of Named_CalleeOf_Client_UI_InventoryItemClickDispatch
// Address:   0x007944a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_UI_InventoryItemClickDispatch: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×5, while×2, return×2, do×1.
//  - Notable callees: FUN_00423f40×2, FUN_004294f0, FUN_007944a0, LeaveCriticalSection.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_UI_InventoryItemClickDispatch
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

char * Named_CalleeOf_Named_CalleeOf_Client_UI_InventoryItemClickDispa_007944a0(void)



{

  char *pcVar1;

  char cVar2;

  int in_EAX;

  int iVar3;

  char *pcVar4;

  char *pcVar5;

  int *local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if (*(int *)(in_EAX + 0x20c) != 0) {

    pcVar5 = (char *)0x0;

    local_4 = 0;

    local_8 = (int *)0x0;

    FUN_004294f0();

    iVar3 = FUN_00423f40(&local_8);

    while (iVar3 == 0) {

      if (local_8 != (int *)0x0) {

        iVar3 = *local_8;

        if (((iVar3 == 1) && (pcVar4 = (char *)local_8[1], pcVar4 != (char *)0x0)) &&

           (*pcVar4 != '\0')) {

          pcVar1 = pcVar4 + 1;

          do {

            cVar2 = *pcVar4;

            pcVar4 = pcVar4 + 1;

          } while (cVar2 != '\0');

          pcVar5 = pcVar4 + ((int)pcVar5 - (int)pcVar1);

        }

        else if ((iVar3 == 0xb) || (iVar3 == 0xc)) {

          pcVar5 = pcVar5 + 1;

        }

      }

      iVar3 = FUN_00423f40(&local_8);

    }

    if (*(char *)(in_EAX + 0x210) != '\0') {

      *(uint8_t *)(in_EAX + 0x210) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x1ec));

    }

    return pcVar5;

  }

  return (char *)0x0;

}
