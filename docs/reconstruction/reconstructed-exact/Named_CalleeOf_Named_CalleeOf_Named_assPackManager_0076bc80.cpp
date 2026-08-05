// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_assPackManager_0076bc80
// -----------------------------------------------------------------------------
// Stable ID: aa_0076bc80
// Callee of Named_CalleeOf_Named_assPackManager
// Address:   0x0076bc80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_assPackManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×7, return×5, while×3, do×2, goto×1.
//  - Notable callees: strncat×2, FUN_0076adc0, FUN_0076bc00, FUN_0076bc80, isalpha, strchr.
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_assPackManager
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_assPackManager_0076bc80(uint32_t /* width from decompiler */ param_1)



{

  char cVar1;

  char cVar2;

  char *in_EAX;

  int iVar3;

  char *pcVar4;

  undefined *puVar5;

  char *_Source;

  char local_104 [260];

  

  if (*in_EAX == '\0') {

    return 1;

  }

  local_104[0] = '\0';

  iVar3 = isalpha((int)*in_EAX);

  _Source = in_EAX;

  if ((iVar3 != 0) && (in_EAX[1] == ':')) {

    _Source = in_EAX + 2;

    strncat(local_104,in_EAX,2);

    if (*_Source == '\0') {

      return 1;

    }

  }

  do {

    pcVar4 = strchr("/\\",(int)*_Source);

    if ((pcVar4 != (char *)0x0) && (_Source[1] == '\0')) {

      return 1;

    }

    cVar2 = _Source[1];

    pcVar4 = _Source;

    while (pcVar4 = pcVar4 + 1, cVar2 != '\0') {

      puVar5 = &DAT_00a24120;

      cVar1 = '/';

      do {

        if (cVar2 == cVar1) goto LAB_0076bd2f;

        cVar1 = puVar5[1];

        puVar5 = puVar5 + 1;

      } while (cVar1 != '\0');

      cVar2 = pcVar4[1];

    }

LAB_0076bd2f:

    strncat(local_104,_Source,(int)pcVar4 - (int)_Source);

    cVar2 = FUN_0076adc0(local_104);

    if ((cVar2 == '\0') && (cVar2 = FUN_0076bc00(local_104,param_1), cVar2 == '\0')) {

      return 0;

    }

    _Source = pcVar4;

    if (*pcVar4 == '\0') {

      return 1;

    }

  } while( true );

}
