// =============================================================================
// FUN_004339b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004339b0
// Address:   0x004339b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004339b0 @ 0x004339b0
// Stable ID: aa_004339b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_004339b0.
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

void __fastcall FUN_004339b0(uint32_t /* width from decompiler */ param_1,int param_2)



{

  uint uVar1;

  uint in_EAX;

  uint8_t *puVar2;

  uint8_t *puVar3;

  int unaff_EDI;

  

  if (((param_2 != 0) && (*(int *)(unaff_EDI + 4) != 0)) &&

     (uVar1 = *(uint *)(unaff_EDI + 0x28), uVar1 != 0)) {

    if (uVar1 <= in_EAX) {

      in_EAX = uVar1;

    }

    if (in_EAX != 0) {

      puVar2 = (uint8_t *)(param_2 + 2);

      puVar3 = (uint8_t *)(*(int *)(unaff_EDI + 4) + 0x29);

      do {

        puVar3[1] = puVar2[-2];

        *puVar3 = puVar2[-1];

        puVar3[-1] = *puVar2;

        puVar2 = puVar2 + 3;

        puVar3 = puVar3 + 4;

        in_EAX = in_EAX - 1;

      } while (in_EAX != 0);

    }

    *(uint8_t *)(unaff_EDI + 0x1a1) = 0;

  }

  return;

}
