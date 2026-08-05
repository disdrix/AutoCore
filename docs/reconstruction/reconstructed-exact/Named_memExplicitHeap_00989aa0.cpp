// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, goto×1.
//  - Notable callees: FUN_0076cec0, FUN_00989a60, FUN_00989aa0, vog_LogMessage.
//  - Strings: "Explicit Heap Growing"; "C:\\vog\\1_code\\palantir\\arda2\\memory\\memExplicitHeap.cpp".
//  - Return sites: 2.

// =============================================================================
// Named_memExplicitHeap_00989aa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00989aa0
// Address:   0x00989aa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "memExplicitHeap"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint Named_memExplicitHeap_00989aa0(void)



{

  int *piVar1;

  int *in_EAX;

  uint uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_ESI;

  uint8_t local_4 [4];

  

  uVar2 = *in_EAX + in_EAX[2] & ~in_EAX[2];

  piVar1 = in_EAX + 1;

  *piVar1 = *piVar1 + ((*in_EAX - uVar2) - unaff_ESI);

  if (-1 < *piVar1) {

LAB_00989aec:

    *in_EAX = uVar2 + unaff_ESI;

    return uVar2;

  }

  if ((char)in_EAX[3] != '\0') {

    uVar3 = FUN_0076cec0(local_4,"Explicit Heap Growing");

    vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\memory\\memExplicitHeap.cpp",0x60,1,uVar3);

    uVar2 = FUN_00989a60();

    if (uVar2 != 0) {

      in_EAX[1] = in_EAX[1] - unaff_ESI;

      goto LAB_00989aec;

    }

  }

  return 0;

}
