// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_008f6f60
// -----------------------------------------------------------------------------
// Stable ID: aa_008f6f60
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_OnBadCharac (+1 other named callers)
// Address:   0x008f6f60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_OnBadCharac: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_OnBadCharac (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_008f6f60.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_OnBadCharac (+1 other named callers)
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_008f6f60(void)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uStack_48;

  uint8_t *puStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint8_t *puStack_38;

  uint8_t local_20 [4];

  uint8_t auStack_1c [28];

  

  if ((*(int *)(unaff_ESI + 0x53c) != 0) && (*(int *)(unaff_ESI + 0x534) != 0)) {

    puStack_38 = local_20;

    uStack_3c = 0x8f6f92;

    (**(code **)(**(int **)(unaff_ESI + 0x53c) + 0x134))();

    piVar1 = *(int **)(unaff_ESI + 0x534);

    uStack_3c = 0;

    uStack_40 = 1;

    puStack_44 = auStack_1c;

    uStack_48 = 0x8f6fca;

    iVar2 = (**(code **)(*piVar1 + 0x120))();

    uStack_48 = 1;

    iVar3 = (**(code **)(*piVar1 + 0x140))(local_20);

    iVar2 = *(int *)(iVar2 + 4);

    iVar3 = *(int *)(iVar3 + 4);

    iVar5 = (int)(float)puStack_44;

    puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(unaff_ESI + 0x53c) + 0x140))(local_20,1);

    uStack_48 = *puVar4;

    puStack_44 = (uint8_t *)(iVar2 + iVar3 + iVar5);

    (**(code **)(**(int **)(unaff_ESI + 0x53c) + 300))(&uStack_48);

    (**(code **)(**(int **)(unaff_ESI + 0x53c) + 0x34c))();

  }

  return;

}
