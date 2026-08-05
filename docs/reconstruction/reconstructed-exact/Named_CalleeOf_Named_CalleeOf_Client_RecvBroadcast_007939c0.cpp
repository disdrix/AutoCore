// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast_007939c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007939c0
// Callee of Named_CalleeOf_Client_RecvBroadcast
// Address:   0x007939c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvBroadcast: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×2, while×2.
//  - Notable callees: FUN_007939c0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvBroadcast
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

int Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast_007939c0(char *param_1)



{

  char *pcVar1;

  int iVar2;

  char cVar3;

  char *pcVar4;

  char *pcVar5;

  char *unaff_EDI;

  

  if ((unaff_EDI != (char *)0x0) && (param_1 != (char *)0x0)) {

    cVar3 = *unaff_EDI;

    iVar2 = 0;

    if (cVar3 != '\0') {

      pcVar5 = unaff_EDI;

      do {

        pcVar4 = param_1;

        if (cVar3 == *param_1) {

          do {

            pcVar1 = pcVar4 + 1;

            pcVar5 = pcVar5 + 1;

            if (*pcVar1 == '\0') {

              return iVar2;

            }

            pcVar4 = pcVar4 + 1;

          } while (*pcVar5 == *pcVar1);

        }

        iVar2 = iVar2 + 1;

        cVar3 = unaff_EDI[iVar2];

        pcVar5 = unaff_EDI + iVar2;

      } while (cVar3 != '\0');

    }

    return -1;

  }

  return -1;

}
