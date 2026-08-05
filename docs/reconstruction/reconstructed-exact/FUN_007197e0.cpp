// =============================================================================
// FUN_007197e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007197e0
// Address:   0x007197e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007197e0 @ 0x007197e0
// Stable ID: aa_007197e0
// Embedded strings (evidence for future rename):
//   - "    Deleted: position: <%8d> size: %8d\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: for×2, return×1.
//  - Notable callees: FUN_007197e0, printf.
//  - Strings: "    Deleted: position: <%8d> size: %8d\n".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int FUN_007197e0(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  int in_EAX;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ local_1c [7];

  

  puVar1 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0x38);

  iVar4 = 0;

  for (puVar3 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0x34); puVar3 != puVar1; puVar3 = puVar3 + 7) {

    puVar5 = puVar3;

    puVar6 = local_1c;

    for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar6 = *puVar5;

      puVar5 = puVar5 + 1;

      puVar6 = puVar6 + 1;

    }

    printf("    Deleted: position: <%8d> size: %8d\n",local_1c[0],local_1c[1]);

    iVar4 = iVar4 + puVar3[1];

  }

  return iVar4;

}
