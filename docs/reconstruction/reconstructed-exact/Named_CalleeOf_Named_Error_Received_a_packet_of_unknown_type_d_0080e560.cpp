// =============================================================================
// Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_0080e560
// -----------------------------------------------------------------------------
// Stable ID: aa_0080e560
// Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
// Address:   0x0080e560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0080e560, FUN_008f8200.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
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

void Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_0080e560(void)



{

  int in_EAX;

  int iVar1;

  

  if ((((((*(char *)(in_EAX + 8) == -1) || (DAT_00d1b6d8 == 0)) ||

        ((uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac +

                                          DAT_00d1b6d8) + 0x3c) + 0x532) ==

         (int)*(char *)(in_EAX + 8))) &&

       ((*(char *)(in_EAX + 9) != '\0' || ((~(byte)(DAT_00af921c >> 4) & 1) == 0)))) &&

      ((*(char *)(in_EAX + 9) != '\x01' ||

       (((~(byte)(DAT_00af921c >> 5) & 1) == 0 &&

        ((DAT_00d1b6d8 == 0 ||

         (((*(short *)(in_EAX + 4) == 0 ||

           (iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +

                                         DAT_00d1b6d8) + 0x27c))(),

           (int)(uint)*(ushort *)(in_EAX + 4) <= iVar1)) &&

          ((*(short *)(in_EAX + 6) == 0 ||

           (iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +

                                         DAT_00d1b6d8) + 0x27c))(),

           iVar1 <= (int)(uint)*(ushort *)(in_EAX + 6))))))))))))) && (DAT_00d1b8dc != 0)) {

    FUN_008f8200(DAT_00d1b8dc,1,&DAT_00a156cc,in_EAX + 0x10,0);

  }

  return;

}
