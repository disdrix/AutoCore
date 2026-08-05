// =============================================================================
// Named_CalleeOf_Client_PacketDispatch_0080d480
// -----------------------------------------------------------------------------
// Stable ID: aa_0080d480
// Callee of Client_PacketDispatch
// Address:   0x0080d480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PacketDispatch: packet/network helper. Evidence string: "Sorry! That object is not available in this zone.". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Sorry! That object is not available in this zone."
//   - "Sorry! That object is invalid."
//   - "Sorry! That object is no longer available for viewing."
//   - "[System]"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, goto×1, for×1, do×1, while×1.
//  - Notable callees: FUN_007a6de0×3, FUN_007a69d0, FUN_0080d480, FUN_008f8200, FUN_00996ff0, sprintf.
//  - Strings: "Sorry! That object is not available in this zone."; "Sorry! That object is invalid."; "Sorry! That object is no longer available for viewing."; "[System]".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Client_PacketDispatch
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

void Named_CalleeOf_Client_PacketDispatch_0080d480(void)



{

  char cVar1;

  int iVar2;

  bool bVar3;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar4;

  char *pcVar5;

  int unaff_EDI;

  char local_100 [256];

  

  if (*(int *)(in_EAX + 0xe98) == 0) {

    return;

  }

  if (*(int *)(*(int *)(in_EAX + 0xe98) + 0x250) == 0) {

    return;

  }

  FUN_007a69d0();

  iVar2 = *(int *)(unaff_EDI + 0x10);

  bVar3 = false;

  local_100[0] = '\0';

  if (iVar2 == 1) {

    uVar4 = FUN_007a6de0("Sorry! That object is not available in this zone.",0xffffffff);

  }

  else if (iVar2 == 2) {

    uVar4 = FUN_007a6de0("Sorry! That object is invalid.",0xffffffff);

  }

  else {

    if (iVar2 != 3) goto LAB_0080d518;

    uVar4 = FUN_007a6de0("Sorry! That object is no longer available for viewing.",0xffffffff);

  }

  sprintf(local_100,"%s",uVar4);

  bVar3 = true;

LAB_0080d518:

  pcVar5 = local_100;

  do {

    cVar1 = *pcVar5;

    pcVar5 = pcVar5 + 1;

  } while (cVar1 != '\0');

  if (pcVar5 != local_100 + 1) {

    FUN_008f8200(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x109c),6,"[System]",local_100,0);

  }

  if (bVar3) {

    FUN_00996ff0(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 8),*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xc));

  }

  return;

}
