// =============================================================================
// Named_CalleeOf_Client_PlayNamedInterfaceSound_00722b80
// -----------------------------------------------------------------------------
// Stable ID: aa_00722b80
// Callee of Client_PlayNamedInterfaceSound
// Address:   0x00722b80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PlayNamedInterfaceSound: presentation helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, do×1, while×1.
//  - Notable callees: CONCAT31, FUN_00722b80.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Client_PlayNamedInterfaceSound
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

uint Named_CalleeOf_Client_PlayNamedInterfaceSound_00722b80(uint param_1,uint param_2,int param_3)



{

  int *piVar1;

  uint in_EAX;

  int iVar2;

  uint *puVar3;

  

  if ((param_1 & param_2) == 0xffffffff) {

    return in_EAX & 0xffffff00;

  }

  piVar1 = (int *)(in_EAX + 0x210);

  iVar2 = 0;

  if (0 < *piVar1) {

    puVar3 = (uint *)(in_EAX + 0x31c);

    do {

      in_EAX = *puVar3;

      if ((((in_EAX != 0) && (*(int *)(in_EAX + 0x2c) == param_3)) &&

          (*(uint *)(in_EAX + 0x40) == param_1)) &&

         ((*(uint *)(in_EAX + 0x44) == param_2 &&

          ((*(char *)(in_EAX + 0x1c5) != '\0' || (*(char *)(in_EAX + 0x3a) != '\0')))))) {

        return CONCAT31((int3)(in_EAX >> 8),1);

      }

      iVar2 = iVar2 + 1;

      puVar3 = puVar3 + 1;

    } while (iVar2 < *piVar1);

  }

  return in_EAX & 0xffffff00;

}
