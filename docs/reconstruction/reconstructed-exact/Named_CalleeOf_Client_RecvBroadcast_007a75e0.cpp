// =============================================================================
// Named_CalleeOf_Client_RecvBroadcast_007a75e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007a75e0
// Callee of Client_RecvBroadcast
// Address:   0x007a75e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvBroadcast: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, while×2, do×1, return×1.
//  - Notable callees: FUN_007a75e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_RecvBroadcast
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

void __fastcall Named_CalleeOf_Client_RecvBroadcast_007a75e0(uint32_t /* width from decompiler */ param_1,char *param_2)



{

  int iVar1;

  char cVar2;

  int iVar3;

  int unaff_EDI;

  

  if ((param_2 != (char *)0x0) && (unaff_EDI != 0)) {

    iVar1 = 0;

    iVar3 = 0;

    cVar2 = *param_2;

    while (cVar2 != '\0') {

      if ((param_2[iVar1] == '[') && (cVar2 = '[', param_2[iVar1 + 1] == '$')) {

        do {

          if (cVar2 == '\0') break;

          cVar2 = param_2[iVar1 + 1];

          iVar1 = iVar1 + 1;

        } while (cVar2 != ']');

        if (param_2[iVar1] == '\0') break;

      }

      else {

        *(char *)(iVar3 + unaff_EDI) = param_2[iVar1];

        iVar3 = iVar3 + 1;

      }

      iVar1 = iVar1 + 1;

      cVar2 = param_2[iVar1];

    }

    *(uint8_t *)(iVar3 + unaff_EDI) = 0;

  }

  return;

}
