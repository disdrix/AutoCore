// =============================================================================
// Named_Failed_load_XML_file_failed_code
// -----------------------------------------------------------------------------
// Stable ID: aa_007b6e8d
// Address:   0x007b6e8d  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_Failed_load_XML_file_failed_code @ 0x007b6e8d
// Stable ID: aa_007b6e8d
// Embedded strings (evidence for future rename):
//   - "Failed to load XML file %s, failed with code %d"
//   - "%S(%i)(%s): pos %i, XML parse error: %S"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_007a4480×2, SysFreeString×2, Named_Failed_load_XML_file_failed_code, S.
//  - Strings: "Failed to load XML file %s, failed with code %d"; "%S(%i)(%s): pos %i, XML parse error: %S".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Failed to load XML file %s, failed with code %d"
 * Domain alias of FUN_007b6e8d (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

bool Named_Failed_load_XML_file_failed_code(void)



{

  int iVar1;

  int *piVar2;

  int unaff_EBP;

  int unaff_ESI;

  

  *(uint32_t /* width from decompiler */ *)(unaff_EBP + -4) = 0;

  if (unaff_ESI < 0) {

    FUN_007a4480(1,"Failed to load XML file %s, failed with code %d",

                 *(uint32_t /* width from decompiler */ *)(unaff_EBP + 0xc));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_EBP + -4) = 0xffffffff;

  if (*(short *)(unaff_EBP + -0x28) != -1) {

    iVar1 = **(int **)(unaff_EBP + 8);

    *(uint32_t /* width from decompiler */ *)(unaff_EBP + -0x14) = 0;

    (**(code **)(iVar1 + 0xf0))(*(int **)(unaff_EBP + 8),unaff_EBP + -0x14);

    piVar2 = *(int **)(unaff_EBP + -0x14);

    if (piVar2 != (int *)0x0) {

      *(uint32_t /* width from decompiler */ *)(unaff_EBP + 8) = 0;

      (**(code **)(*piVar2 + 0x20))(piVar2,unaff_EBP + 8);

      *(uint32_t /* width from decompiler */ *)(unaff_EBP + -0x20) = 0;

      (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x24))

                (*(int **)(unaff_EBP + -0x14),unaff_EBP + -0x20);

      *(uint32_t /* width from decompiler */ *)(unaff_EBP + -0x1c) = 0;

      (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x2c))

                (*(int **)(unaff_EBP + -0x14),unaff_EBP + -0x1c);

      *(uint32_t /* width from decompiler */ *)(unaff_EBP + -0x18) = 0;

      (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x30))

                (*(int **)(unaff_EBP + -0x14),unaff_EBP + -0x18);

      FUN_007a4480(1,"%S(%i)(%s): pos %i, XML parse error: %S",*(uint32_t /* width from decompiler */ *)(unaff_EBP + 8),

                   *(uint32_t /* width from decompiler */ *)(unaff_EBP + -0x1c),*(uint32_t /* width from decompiler */ *)(unaff_EBP + 0xc),

                   *(uint32_t /* width from decompiler */ *)(unaff_EBP + -0x18),*(uint32_t /* width from decompiler */ *)(unaff_EBP + -0x20));

      SysFreeString(*(BSTR *)(unaff_EBP + 8));

      SysFreeString(*(BSTR *)(unaff_EBP + -0x20));

      (**(code **)(**(int **)(unaff_EBP + -0x14) + 8))(*(int **)(unaff_EBP + -0x14));

    }

    ExceptionList = *(void **)(unaff_EBP + -0xc);

    return false;

  }

  ExceptionList = *(void **)(unaff_EBP + -0xc);

  return -1 < unaff_ESI;

}
