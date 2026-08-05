// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00411c60
// -----------------------------------------------------------------------------
// Stable ID: aa_00411c60
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa
// Address:   0x00411c60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, return×1, goto×1, while×1.
//  - Notable callees: FUN_004113b0×2, FUN_00411c60, FUN_004294f0, LeaveCriticalSection.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa
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

uint8_t Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00411c60(void)



{

  int in_EAX;

  int iVar1;

  uint8_t uVar2;

  int unaff_EDI;

  int local_8;

  uint32_t /* width from decompiler */ local_4;

  

  uVar2 = 0;

  local_4 = 0;

  FUN_004294f0();

  iVar1 = FUN_004113b0(in_EAX,&local_8);

  do {

    if (iVar1 != 0) {

LAB_00411cad:

      if (*(char *)(in_EAX + 0x28) != '\0') {

        *(uint8_t *)(in_EAX + 0x28) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 4));

      }

      return uVar2;

    }

    if (local_8 == unaff_EDI) {

      uVar2 = 1;

      goto LAB_00411cad;

    }

    iVar1 = FUN_004113b0(in_EAX,&local_8);

  } while( true );

}
