// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_anmTrackMaster_inl_0045c280
// -----------------------------------------------------------------------------
// Stable ID: aa_0045c280
// Callee of Named_CalleeOf_Named_anmTrackMaster_inl
// Address:   0x0045c280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_anmTrackMaster_inl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×1, while×1, goto×1.
//  - Notable callees: FUN_0044c560, FUN_0045c280, FUN_004608a0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_anmTrackMaster_inl
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

void Named_CalleeOf_Named_CalleeOf_Named_anmTrackMaster_inl_0045c280(void)



{

  bool bVar1;

  uint *in_EAX;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *unaff_ESI;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ *local_4;

  

  puVar3 = *(uint32_t /* width from decompiler */ **)(unaff_EBX + 4);

  bVar1 = true;

  local_8 = 1;

  if (*(char *)((int)puVar3[1] + 0x21) == '\0') {

    puVar2 = (uint32_t /* width from decompiler */ *)puVar3[1];

    do {

      puVar3 = puVar2;

      if (((uint)puVar3[5] < in_EAX[1]) ||

         (((uint)puVar3[5] <= in_EAX[1] && ((uint)puVar3[4] <= *in_EAX)))) {

        puVar2 = (uint32_t /* width from decompiler */ *)puVar3[2];

        bVar1 = false;

        local_8 = 0;

      }

      else {

        puVar2 = (uint32_t /* width from decompiler */ *)*puVar3;

        bVar1 = true;

        local_8 = 1;

      }

    } while (*(char *)((int)puVar2 + 0x21) == '\0');

  }

  local_4 = puVar3;

  if (bVar1) {

    if (puVar3 == (uint32_t /* width from decompiler */ *)**(int **)(unaff_EBX + 4)) {

      local_8 = 1;

      goto LAB_0045c305;

    }

    FUN_004608a0();

  }

  if ((in_EAX[1] < (uint)local_4[5]) ||

     ((in_EAX[1] <= (uint)local_4[5] && (*in_EAX <= (uint)local_4[4])))) {

    *unaff_ESI = local_4;

    *(uint8_t *)(unaff_ESI + 1) = 0;

    return;

  }

LAB_0045c305:

  puVar3 = (uint32_t /* width from decompiler */ *)FUN_0044c560(&local_4,local_8,puVar3,in_EAX);

  *unaff_ESI = *puVar3;

  *(uint8_t *)(unaff_ESI + 1) = 1;

  return;

}
