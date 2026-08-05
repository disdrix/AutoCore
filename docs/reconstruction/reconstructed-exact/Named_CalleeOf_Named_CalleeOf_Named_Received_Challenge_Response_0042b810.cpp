// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Received_Challenge_Response_0042b810
// -----------------------------------------------------------------------------
// Stable ID: aa_0042b810
// Callee of Named_CalleeOf_Named_Received_Challenge_Response_8x
// Address:   0x0042b810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Received_Challenge_Response_8x: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×3, for×2, return×1.
//  - Notable callees: BitStream_readBits×2, FUN_0042b810, malloc, realloc.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Received_Challenge_Response_8x
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

void Named_CalleeOf_Named_CalleeOf_Named_Received_Challenge_Response_0042b810(void)



{

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  uint uVar3;

  uint uVar4;

  uint _NewSize;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint local_4;

  

  local_4 = 0;

  BitStream_readBits(10,&local_4);

  _NewSize = local_4 & 0x3ff;

  if (*(char *)(in_EAX + 0x14) == '\0') {

    puVar1 = malloc(*(size_t *)(in_EAX + 0x10));

    uVar4 = *(uint *)(in_EAX + 0x10);

    puVar5 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0xc);

    puVar6 = puVar1;

    for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *puVar6 = *puVar5;

      puVar5 = puVar5 + 1;

      puVar6 = puVar6 + 1;

    }

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *(uint8_t *)puVar6 = *(uint8_t *)puVar5;

      puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

      puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

    }

    *(uint32_t /* width from decompiler */ **)(in_EAX + 0xc) = puVar1;

    *(uint8_t *)(in_EAX + 0x14) = 1;

  }

  if (*(uint *)(in_EAX + 0x10) < _NewSize) {

    if (*(char *)(in_EAX + 0x14) != '\0') {

      *(uint *)(in_EAX + 0x10) = _NewSize;

      pvVar2 = realloc(*(void **)(in_EAX + 0xc),_NewSize);

      *(void **)(in_EAX + 0xc) = pvVar2;

    }

  }

  else {

    *(uint *)(in_EAX + 0x10) = _NewSize;

  }

  BitStream_readBits(_NewSize * 8,*(uint32_t /* width from decompiler */ *)(in_EAX + 0xc));

  return;

}
