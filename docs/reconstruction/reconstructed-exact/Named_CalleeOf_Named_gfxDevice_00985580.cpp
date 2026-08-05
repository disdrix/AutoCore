// =============================================================================
// Named_CalleeOf_Named_gfxDevice_00985580
// -----------------------------------------------------------------------------
// Stable ID: aa_00985580
// Callee of Named_gfxDevice
// Address:   0x00985580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: while×3, if×3, for×1, return×1.
//  - Notable callees: FUN_00743c50, FUN_00985580.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxDevice
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

void Named_CalleeOf_Named_gfxDevice_00985580(void)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int in_EAX;

  int iVar7;

  

  puVar2 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0x14);

  puVar3 = (uint32_t /* width from decompiler */ *)*puVar2;

  while (puVar3 != puVar2) {

    if ((*(byte *)(puVar3 + 3) & 0x28) == 0) {

      iVar4 = puVar3[6];

      for (iVar7 = puVar3[5]; iVar7 != iVar4; iVar7 = iVar7 + 0x20) {

        FUN_00743c50();

      }

    }

    if (*(char *)((int)puVar3 + 0x21) == '\0') {

      puVar5 = (uint32_t /* width from decompiler */ *)puVar3[2];

      if (*(char *)((int)puVar5 + 0x21) == '\0') {

        cVar1 = *(char *)((int)*puVar5 + 0x21);

        puVar3 = puVar5;

        puVar5 = (uint32_t /* width from decompiler */ *)*puVar5;

        while (cVar1 == '\0') {

          cVar1 = *(char *)((int)*puVar5 + 0x21);

          puVar3 = puVar5;

          puVar5 = (uint32_t /* width from decompiler */ *)*puVar5;

        }

      }

      else {

        cVar1 = *(char *)((int)puVar3[1] + 0x21);

        puVar6 = (uint32_t /* width from decompiler */ *)puVar3[1];

        puVar5 = puVar3;

        while ((puVar3 = puVar6, cVar1 == '\0' && (puVar5 == (uint32_t /* width from decompiler */ *)puVar3[2]))) {

          cVar1 = *(char *)((int)puVar3[1] + 0x21);

          puVar6 = (uint32_t /* width from decompiler */ *)puVar3[1];

          puVar5 = puVar3;

        }

      }

    }

  }

  return;

}
