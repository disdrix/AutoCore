// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Sending_Chal_0042b2a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0042b2a0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_Sending_Challenge_Response
// Address:   0x0042b2a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_Sending_Challenge_Response: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_0042b2a0, free, malloc.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_Sending_Challenge_Response
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Sending_Chal_0042b2a0(void)



{

  uint uVar1;

  void *_Memory;

  uint in_EAX;

  void *pvVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint uVar4;

  uint *unaff_ESI;

  uint uVar5;

  

  if (unaff_ESI[1] < in_EAX) {

    uVar5 = in_EAX + (0x10 - (in_EAX & 0xf));

    pvVar2 = malloc(uVar5 * 4);

    uVar1 = *unaff_ESI;

    _Memory = (void *)unaff_ESI[2];

    uVar4 = 0;

    unaff_ESI[2] = (uint)pvVar2;

    if (uVar1 != 0) {

      do {

        puVar3 = (uint32_t /* width from decompiler */ *)(unaff_ESI[2] + uVar4 * 4);

        if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

          *puVar3 = *(uint32_t /* width from decompiler */ *)(uVar4 * 4 + (int)_Memory);

        }

        uVar4 = uVar4 + 1;

      } while (uVar4 < uVar1);

    }

    unaff_ESI[2] = (uint)_Memory;

    free(_Memory);

    unaff_ESI[2] = (uint)pvVar2;

    unaff_ESI[1] = uVar5;

  }

  return;

}
