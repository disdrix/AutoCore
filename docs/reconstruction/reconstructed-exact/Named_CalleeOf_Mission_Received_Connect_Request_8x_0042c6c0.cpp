// =============================================================================
// Named_CalleeOf_Mission_Received_Connect_Request_8x_0042c6c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0042c6c0
// Callee of Mission_Received_Connect_Request_8x (+1 other named callers)
// Address:   0x0042c6c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Received_Connect_Request_8x: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Mission_Received_Connect_Request_8x (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, while×1.
//  - Notable callees: FUN_0042c6c0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Mission_Received_Connect_Request_8x (+1 other named callers)
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

uint32_t /* width from decompiler */ Named_CalleeOf_Mission_Received_Connect_Request_8x_0042c6c0(void)



{

  int iVar1;

  int iVar2;

  int in_EAX;

  uint uVar3;

  short *unaff_ESI;

  

  uVar3 = (((*(uint *)(unaff_ESI + 4) << 8 ^ (uint)(ushort)unaff_ESI[1]) * 8 ^

           *(uint *)(unaff_ESI + 6)) << 5 ^ *(uint *)(unaff_ESI + 4) >> 0x10 ^

          *(uint *)(unaff_ESI + 2)) % *(uint *)(in_EAX + 0x18);

  iVar1 = *(int *)(in_EAX + 0x20);

  iVar2 = *(int *)(iVar1 + uVar3 * 4);

  while( true ) {

    if (iVar2 == 0) {

      return 0;

    }

    if ((((*unaff_ESI == *(short *)(iVar2 + 0xf8)) && (unaff_ESI[1] == *(ushort *)(iVar2 + 0xfa)))

        && (*(int *)(unaff_ESI + 2) == *(int *)(iVar2 + 0xfc))) &&

       (((*(int *)(unaff_ESI + 4) == *(int *)(iVar2 + 0x100) &&

         (*(int *)(unaff_ESI + 6) == *(int *)(iVar2 + 0x104))) &&

        (*(int *)(unaff_ESI + 8) == *(int *)(iVar2 + 0x108))))) break;

    uVar3 = uVar3 + 1;

    if (*(uint *)(in_EAX + 0x18) <= uVar3) {

      uVar3 = 0;

    }

    iVar2 = *(int *)(iVar1 + uVar3 * 4);

  }

  return *(uint32_t /* width from decompiler */ *)(iVar1 + uVar3 * 4);

}
