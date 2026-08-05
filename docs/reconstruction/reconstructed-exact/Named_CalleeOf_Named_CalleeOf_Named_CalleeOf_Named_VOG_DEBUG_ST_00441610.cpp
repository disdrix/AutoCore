// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00441610
// -----------------------------------------------------------------------------
// Stable ID: aa_00441610
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x00441610  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00441610.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00441610(void)



{

  uint uVar1;

  uint uVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint *unaff_EDI;

  

  puVar4 = *(uint32_t /* width from decompiler */ **)(in_EAX + 4);

  if (*(char *)((int)puVar4[1] + 0x3d) == '\0') {

    uVar1 = *unaff_EDI;

    puVar3 = puVar4;

    puVar5 = (uint32_t /* width from decompiler */ *)puVar4[1];

    do {

      puVar4 = puVar5;

      uVar2 = puVar4[3];

      if ((*(uint *)(uVar2 + 8) < *(uint *)(uVar1 + 8)) ||

         ((*(uint *)(uVar2 + 8) == *(uint *)(uVar1 + 8) &&

          ((uVar2 < uVar1 ||

           ((uVar2 == uVar1 &&

            (((uint)puVar4[5] < unaff_EDI[2] ||

             ((puVar4[5] == unaff_EDI[2] && ((int)puVar4[6] < (int)unaff_EDI[3])))))))))))) {

        puVar5 = (uint32_t /* width from decompiler */ *)puVar4[2];

        puVar4 = puVar3;

      }

      else {

        puVar5 = (uint32_t /* width from decompiler */ *)*puVar4;

      }

      puVar3 = puVar4;

    } while (*(char *)((int)puVar5 + 0x3d) == '\0');

  }

  return puVar4;

}
