// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_008cc5a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008cc5a0
// Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
// Address:   0x008cc5a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×16, return×2.
//  - Notable callees: FUN_008aab00, FUN_008cc5a0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
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

void Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_008cc5a0(void)



{

  char cVar1;

  int *unaff_ESI;

  char *unaff_EDI;

  

  if (unaff_ESI[0x195] != 0) {

    (**(code **)(*(int *)unaff_ESI[0x195] + 0x268))();

    FUN_008aab00(unaff_ESI[0x195]);

    (**(code **)(*(int *)unaff_ESI[0x195] + 0x34c))();

  }

  cVar1 = (**(code **)(*unaff_ESI + 0x3d8))();

  if (cVar1 != '\0') {

    cVar1 = (**(code **)(*unaff_ESI + 0xd0))();

    if (cVar1 != '\0') {

      if ((unaff_EDI == (char *)0x0) || (*unaff_EDI == '\0')) {

        if (unaff_ESI[400] != 0) {

          (**(code **)(*(int *)unaff_ESI[400] + 4))(0);

        }

        if (unaff_ESI[0x191] != 0) {

          (**(code **)(*(int *)unaff_ESI[0x191] + 4))(0);

        }

        if (unaff_ESI[0x192] != 0) {

          (**(code **)(*(int *)unaff_ESI[0x192] + 4))(0);

        }

        if (unaff_ESI[0x193] != 0) {

          (**(code **)(*(int *)unaff_ESI[0x193] + 4))(0);

        }

        if (unaff_ESI[0x194] != 0) {

          (**(code **)(*(int *)unaff_ESI[0x194] + 4))(0);

        }

        if (unaff_ESI[0x195] != 0) {

          (**(code **)(*(int *)unaff_ESI[0x195] + 4))(0);

        }

      }

      else {

        if (unaff_ESI[400] != 0) {

          (**(code **)(*(int *)unaff_ESI[400] + 0xfc))(1,0x3f000000);

        }

        if (unaff_ESI[0x191] != 0) {

          (**(code **)(*(int *)unaff_ESI[0x191] + 0xfc))(1,0x3f000000);

        }

        if (unaff_ESI[0x192] != 0) {

          (**(code **)(*(int *)unaff_ESI[0x192] + 0xfc))(1,0x3f000000);

        }

        if (unaff_ESI[0x193] != 0) {

          (**(code **)(*(int *)unaff_ESI[0x193] + 0xfc))(1,0x3f000000);

        }

        if (unaff_ESI[0x194] != 0) {

          (**(code **)(*(int *)unaff_ESI[0x194] + 0xfc))(1,0x3f000000);

        }

        if (unaff_ESI[0x195] != 0) {

          (**(code **)(*(int *)unaff_ESI[0x195] + 0xfc))(1,0x3f000000);

          return;

        }

      }

    }

  }

  return;

}
