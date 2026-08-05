// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0087d690
// -----------------------------------------------------------------------------
// Stable ID: aa_0087d690
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
// Address:   0x0087d690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli: callee helper. Evidence string: "Gravel". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Gravel"
//   - "Pavement"
//   - "Grass"
//   - "Unknown"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~85 non-empty decompiler lines.
//  - Control keywords: return×8, do×7, while×7, if×1, switch×1.
//  - Notable callees: FUN_007a6de0×7, FUN_007a69d0, FUN_0087d690.
//  - Strings: "Gravel"; "Pavement"; "Grass"; "Unknown".
//  - Return sites: 8.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
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

char * Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0087d690(void)



{

  char cVar1;

  char *pcVar2;

  char *pcVar3;

  uint32_t /* width from decompiler */ unaff_ESI;

  char *unaff_EDI;

  

  if (unaff_EDI != (char *)0x0) {

    FUN_007a69d0();

    switch(unaff_ESI) {

    case 0:

      pcVar2 = (char *)FUN_007a6de0("Gravel",0xffffffff);

      pcVar3 = unaff_EDI;

      do {

        cVar1 = *pcVar2;

        *pcVar3 = cVar1;

        pcVar2 = pcVar2 + 1;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      return unaff_EDI;

    case 1:

      pcVar2 = (char *)FUN_007a6de0(&DAT_00a5874c,0xffffffff);

      pcVar3 = unaff_EDI;

      do {

        cVar1 = *pcVar2;

        *pcVar3 = cVar1;

        pcVar2 = pcVar2 + 1;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      return unaff_EDI;

    case 2:

      pcVar2 = (char *)FUN_007a6de0(&DAT_00a58750,0xffffffff);

      pcVar3 = unaff_EDI;

      do {

        cVar1 = *pcVar2;

        *pcVar3 = cVar1;

        pcVar2 = pcVar2 + 1;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      return unaff_EDI;

    case 3:

      pcVar2 = (char *)FUN_007a6de0("Pavement",0xffffffff);

      pcVar3 = unaff_EDI;

      break;

    case 4:

      pcVar2 = (char *)FUN_007a6de0("Grass",0xffffffff);

      pcVar3 = unaff_EDI;

      do {

        cVar1 = *pcVar2;

        *pcVar3 = cVar1;

        pcVar2 = pcVar2 + 1;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      return unaff_EDI;

    case 5:

      pcVar2 = (char *)FUN_007a6de0(&DAT_00a58744,0xffffffff);

      pcVar3 = unaff_EDI;

      do {

        cVar1 = *pcVar2;

        *pcVar3 = cVar1;

        pcVar2 = pcVar2 + 1;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      return unaff_EDI;

    default:

      pcVar2 = (char *)FUN_007a6de0("Unknown",0xffffffff);

      pcVar3 = unaff_EDI;

      do {

        cVar1 = *pcVar2;

        *pcVar3 = cVar1;

        pcVar2 = pcVar2 + 1;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      return unaff_EDI;

    }

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    return unaff_EDI;

  }

  return (char *)0x0;

}
