// =============================================================================
// Named_CalleeOf_Client_ChatMacroQuickPhrases_0082ad70
// -----------------------------------------------------------------------------
// Stable ID: aa_0082ad70
// Callee of Client_ChatMacroQuickPhrases
// Address:   0x0082ad70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_ChatMacroQuickPhrases: social/chat helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, return×2.
//  - Notable callees: FUN_0082ad70.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_ChatMacroQuickPhrases
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

void Named_CalleeOf_Client_ChatMacroQuickPhrases_0082ad70(void)



{

  char cVar1;

  char *pcVar2;

  int *unaff_EBX;

  int unaff_ESI;

  char *unaff_EDI;

  

  if ((-1 < unaff_ESI) && (unaff_ESI < 5)) {

    if ((void *)unaff_EBX[unaff_ESI + 0x141] != (void *)0x0) {

      operator_delete__((void *)unaff_EBX[unaff_ESI + 0x141]);

    }

    unaff_EBX[unaff_ESI + 0x141] = 0;

    if (unaff_EDI != (char *)0x0) {

      pcVar2 = unaff_EDI;

      do {

        cVar1 = *pcVar2;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

      pcVar2 = operator_new__((uint)(pcVar2 + (1 - (int)(unaff_EDI + 1))));

      unaff_EBX[unaff_ESI + 0x141] = (int)pcVar2;

      do {

        cVar1 = *unaff_EDI;

        *pcVar2 = cVar1;

        unaff_EDI = unaff_EDI + 1;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

    }

    (**(code **)(*unaff_EBX + 0x444))();

                    /* WARNING: Could not recover jumptable at 0x0082addf. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*unaff_EBX + 0x34c))();

    return;

  }

  return;

}
