// =============================================================================
// Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_0080a5b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0080a5b0
// Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
// Address:   0x0080a5b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper. Evidence string: "Received too many characters.". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Received too many characters."
//   - "allocatenewobjectfromcbid failed %d Get a programmer"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_007a4480×2, CVOGReaction_GiveItemByCbid, FUN_0080a5b0.
//  - Strings: "Received too many characters."; "allocatenewobjectfromcbid failed %d Get a programmer".
//  - Return sites: 3.

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

void Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_0080a5b0(void)



{

  int iVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_EBX;

  int unaff_ESI;

  

  if (0xb < *(int *)(unaff_ESI + 0x144)) {

    FUN_007a4480(1,"Received too many characters.");

    return;

  }

  piVar2 = (int *)CVOGReaction_GiveItemByCbid(*(int *)(unaff_EBX + 4));

  if (piVar2 == (int *)0x0) {

    FUN_007a4480(1,"allocatenewobjectfromcbid failed %d Get a programmer",

                 *(uint32_t /* width from decompiler */ *)(unaff_EBX + 4));

    return;

  }

  (**(code **)(*piVar2 + 8))(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 4),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xe04),0);

  uVar3 = (**(code **)(*piVar2 + 0x1dc))();

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xe9c + *(int *)(unaff_ESI + 0x144) * 4) = uVar3;

  iVar1 = *(int *)(unaff_ESI + 0xe9c + *(int *)(unaff_ESI + 0x144) * 4);

  (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0xc4))();

  iVar1 = *(int *)(unaff_ESI + 0xe9c + *(int *)(unaff_ESI + 0x144) * 4);

  (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x218))

            (*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xe04));

  *(int *)(unaff_ESI + 0x144) = *(int *)(unaff_ESI + 0x144) + 1;

  return;

}
