// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_SetAnnounce_0097ae30
// -----------------------------------------------------------------------------
// Stable ID: aa_0097ae30
// Callee of Named_CalleeOf_Named_CalleeOf_Client_SetAnnouncementLabelTextur
// Address:   0x0097ae30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_SetAnnouncementLabelTextur: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, do×1, while×1.
//  - Notable callees: FUN_004b99c0, FUN_0097ae30.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_SetAnnouncementLabelTextur
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_SetAnnounce_0097ae30(void)



{

  void *pvVar1;

  int in_EAX;

  uint *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  puVar3 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0x554);

  if (puVar3 != *(uint32_t /* width from decompiler */ **)(in_EAX + 0x558)) {

    do {

      pvVar1 = (void *)*puVar3;

      if (pvVar1 != (void *)0x0) {

        FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      puVar3 = puVar3 + 1;

    } while (puVar3 != *(uint32_t /* width from decompiler */ **)(in_EAX + 0x558));

  }

  if (*(void **)(in_EAX + 0x554) == (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x554) = 0;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x558) = 0;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x55c) = 0;

    if (*(int *)(in_EAX + 0x4fc) != 0) {

      *(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x4fc) + 0xa8) = 0;

      puVar2 = (uint *)(*(int *)(in_EAX + 0x4fc) + 0xbc);

      *puVar2 = *puVar2 & 0xfffffffe;

    }

    if (*(int *)(in_EAX + 0x500) != 0) {

      *(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x500) + 0xa8) = 0;

      puVar2 = (uint *)(*(int *)(in_EAX + 0x500) + 0xbc);

      *puVar2 = *puVar2 & 0xfffffffe;

    }

    if (*(int *)(in_EAX + 0x504) != 0) {

      *(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x504) + 0xa8) = 0;

      puVar2 = (uint *)(*(int *)(in_EAX + 0x504) + 0xbc);

      *puVar2 = *puVar2 & 0xfffffffe;

    }

    if (*(int *)(in_EAX + 0x508) != 0) {

      *(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x508) + 0xa8) = 0;

      puVar2 = (uint *)(*(int *)(in_EAX + 0x508) + 0xbc);

      *puVar2 = *puVar2 & 0xfffffffe;

    }

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(in_EAX + 0x554));

}
