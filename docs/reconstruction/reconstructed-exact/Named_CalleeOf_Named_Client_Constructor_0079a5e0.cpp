// =============================================================================
// Named_CalleeOf_Named_Client_Constructor_0079a5e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0079a5e0
// Callee of Named_Client_Constructor
// Address:   0x0079a5e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Client_Constructor: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, if×1, for×1, return×1.
//  - Notable callees: CONCAT44, FUN_0079a5e0, QueryPerformanceCounter.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Client_Constructor
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

void Named_CalleeOf_Named_Client_Constructor_0079a5e0(void)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int unaff_ESI;

  LARGE_INTEGER local_8;

  

  uVar1 = DAT_00aaa66c;

  iVar5 = 0;

  iVar3 = 0;

  puVar2 = (uint32_t /* width from decompiler */ *)(unaff_ESI + 0x68);

  do {

    puVar2[-0xe] = 0;

    *puVar2 = 0;

    puVar2[0xe] = 0;

    puVar2[0x1c] = 0;

    puVar2[0x2a] = uVar1;

    *(uint8_t *)(unaff_ESI + 0x20 + iVar3) = 0;

    iVar3 = iVar3 + 1;

    puVar2 = puVar2 + 1;

  } while (iVar3 < 0xe);

  iVar3 = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10) = 0;

  if (0 < *(int *)(unaff_ESI + 0x1c)) {

    do {

      puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x18) + iVar5);

      for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {

        *puVar2 = 0;

        puVar2 = puVar2 + 1;

      }

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0x24 + *(int *)(unaff_ESI + 0x18)) = 9999999;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0x28 + *(int *)(unaff_ESI + 0x18)) = 9999999;

      iVar3 = iVar3 + 1;

      iVar5 = iVar5 + 0x2c;

    } while (iVar3 < *(int *)(unaff_ESI + 0x1c));

  }

  QueryPerformanceCounter(&local_8);

  *(float *)(unaff_ESI + 0x238) =

       (float)CONCAT44((local_8.s.HighPart - *(int *)(unaff_ESI + 0x234)) -

                       (uint)(local_8.s.LowPart < *(uint *)(unaff_ESI + 0x230)),

                       local_8.s.LowPart - *(uint *)(unaff_ESI + 0x230)) *

       *(float *)(unaff_ESI + 0x14);

  return;

}
