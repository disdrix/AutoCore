// =============================================================================
// FUN_0092db30
// -----------------------------------------------------------------------------
// Stable ID: aa_0092db30
// Address:   0x0092db30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092db30 @ 0x0092db30
// Stable ID: aa_0092db30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: strtok×2, CONCAT22, FUN_007f6080, FUN_0092db30.
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

void FUN_0092db30(uint *param_1)



{

  uint *puVar1;

  char *in_EAX;

  char *pcVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ *unaff_EBX;

  

  puVar1 = param_1;

  if (((in_EAX != (char *)0x0) && (param_1 != (uint *)0x0)) && (unaff_EBX != (uint32_t /* width from decompiler */ *)0x0)) {

    param_1 = (uint *)CONCAT22(param_1._2_2_,0x2b);

    pcVar2 = strtok(in_EAX,(char *)&param_1);

    *puVar1 = 0;

    *unaff_EBX = 0;

    while (pcVar2 != (char *)0x0) {

      uVar3 = FUN_007f6080();

      uVar3 = uVar3 & 0xffff;

      if ((uVar3 != 1) && (uVar3 != 0x1c)) {

        if (uVar3 == 0x2a) {

          *unaff_EBX = 0x2a;

        }

        else {

          *puVar1 = uVar3;

        }

        pcVar2 = strtok((char *)0x0,(char *)&param_1);

      }

    }

  }

  return;

}
