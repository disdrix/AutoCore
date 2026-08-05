// =============================================================================
// Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_0080a6b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0080a6b0
// Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
// Address:   0x0080a6b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper. Evidence string: "Your clan has been disbanded". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Your clan has been disbanded"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×1, for×1, return×1.
//  - Notable callees: FUN_004c2680, FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0, FUN_0080a6b0, FUN_0094c6d0.
//  - Strings: "Your clan has been disbanded".
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

void Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_0080a6b0(void)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  

  FUN_007a69d0();

  if (*(int *)(unaff_ESI + 0x31f0) != 0) {

    FUN_004c2680();

    puVar3 = *(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x31f0);

    for (iVar2 = 0x82; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar3 = 0;

      puVar3 = puVar3 + 1;

    }

    **(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x31f0) = 0xffffffff;

  }

  FUN_0094c6d0();

  uVar6 = 0;

  uVar5 = 1;

  uVar4 = 0xffffffff;

  uVar1 = FUN_007a6de0("Your clan has been disbanded",0xffffffff);

  FUN_007fdfb0(unaff_ESI,uVar1,uVar4,uVar5,uVar6);

  return;

}
