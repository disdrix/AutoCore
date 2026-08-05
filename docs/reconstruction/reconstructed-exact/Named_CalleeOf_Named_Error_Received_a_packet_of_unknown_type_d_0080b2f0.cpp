// =============================================================================
// Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_0080b2f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0080b2f0
// Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
// Address:   0x0080b2f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_0080b2f0, FUN_008cc5a0.
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

void __fastcall Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_0080b2f0(int param_1)



{

  char cVar1;

  int iVar2;

  int in_EAX;

  char *pcVar3;

  char *pcVar4;

  

  if (*(int *)(in_EAX + 8) != 0) {

    *(int *)(in_EAX + 8) = in_EAX + 0xc;

  }

  if (*(void **)(param_1 + 0xf44) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0xf44));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf44) = 0;

  pcVar3 = *(char **)(in_EAX + 8);

  if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {

    pcVar4 = pcVar3 + 1;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar4 = operator_new__((uint)(pcVar3 + (1 - (int)pcVar4)));

    *(char **)(param_1 + 0xf44) = pcVar4;

    pcVar3 = *(char **)(in_EAX + 8);

    do {

      cVar1 = *pcVar3;

      *pcVar4 = cVar1;

      pcVar3 = pcVar3 + 1;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

  }

  iVar2 = *(int *)(param_1 + 0xf3c);

  if ((((iVar2 != 0) && (*(int **)(param_1 + 0xf40) != (int *)0x0)) &&

      (**(int **)(param_1 + 0xf40) == iVar2)) &&

     ((*(int *)(iVar2 + 0xa90) == 2 && (*(int *)(iVar2 + 0xa7c) != 0)))) {

    FUN_008cc5a0();

  }

  return;

}
