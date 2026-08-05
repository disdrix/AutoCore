// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Invalid_Packet_00784490
// -----------------------------------------------------------------------------
// Stable ID: aa_00784490
// Callee of Named_CalleeOf_Named_Invalid_Packet (+1 other named callers)
// Address:   0x00784490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Invalid_Packet: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_Invalid_Packet (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: htons×2, FUN_00784490, htonl.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Invalid_Packet (+1 other named callers)
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

void Named_CalleeOf_Named_CalleeOf_Named_Invalid_Packet_00784490(void)



{

  short sVar1;

  uint32_t /* width from decompiler */ uVar2;

  u_short uVar3;

  u_long uVar4;

  uint32_t /* width from decompiler */ *unaff_EBX;

  uint32_t /* width from decompiler */ *unaff_ESI;

  short *unaff_EDI;

  

  sVar1 = *unaff_EDI;

  if ((sVar1 == 0) || (sVar1 == 1)) {

    *unaff_ESI = 0;

    unaff_ESI[1] = 0;

    unaff_ESI[2] = 0;

    unaff_ESI[3] = 0;

    *(uint16_t *)unaff_ESI = 2;

    uVar3 = htons(unaff_EDI[1]);

    *(u_short *)((int)unaff_ESI + 2) = uVar3;

    uVar4 = htonl(*(u_long *)(unaff_EDI + 2));

    unaff_ESI[1] = uVar4;

    *unaff_EBX = 0x10;

  }

  else if (sVar1 == 2) {

    *unaff_ESI = 0;

    unaff_ESI[1] = 0;

    unaff_ESI[2] = 0;

    *(uint16_t *)(unaff_ESI + 3) = 0;

    *(uint16_t *)unaff_ESI = 6;

    uVar3 = htons(unaff_EDI[1]);

    *(u_short *)(unaff_ESI + 3) = uVar3;

    uVar2 = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 2);

    *(char *)((int)unaff_ESI + 2) = (char)((uint)uVar2 >> 0x18);

    *(char *)((int)unaff_ESI + 5) = (char)uVar2;

    *(char *)((int)unaff_ESI + 3) = (char)((uint)uVar2 >> 0x10);

    *(char *)(unaff_ESI + 1) = (char)((uint)uVar2 >> 8);

    uVar2 = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 4);

    *(char *)((int)unaff_ESI + 6) = (char)((uint)uVar2 >> 0x18);

    *(char *)((int)unaff_ESI + 7) = (char)((uint)uVar2 >> 0x10);

    *(char *)((int)unaff_ESI + 9) = (char)uVar2;

    *(char *)(unaff_ESI + 2) = (char)((uint)uVar2 >> 8);

    sVar1 = unaff_EDI[6];

    *(char *)((int)unaff_ESI + 10) = (char)((ushort)sVar1 >> 8);

    *(char *)((int)unaff_ESI + 0xb) = (char)sVar1;

    *unaff_EBX = 0xe;

    return;

  }

  return;

}
