// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_008b3050
// -----------------------------------------------------------------------------
// Stable ID: aa_008b3050
// Callee of Named_CalleeOf_Client_RefreshOpenMissionUiWindows
// Address:   0x008b3050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RefreshOpenMissionUiWindows: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: do×1, if×1, while×1, return×1.
//  - Notable callees: FUN_008b3050.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RefreshOpenMissionUiWindows
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

void Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_008b3050(void)



{

  int in_EAX;

  int iVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  uVar2 = 0;

  puVar3 = (uint32_t /* width from decompiler */ *)(in_EAX + 0x6d8);

  do {

    iVar1 = CVOGReaction_ResolveObjectTarget

                      (1,*(uint32_t /* width from decompiler */ *)(DAT_00d1b6d8 + 0x5a0 + (uVar2 & 0xff) * 8),

                       *(uint32_t /* width from decompiler */ *)(DAT_00d1b6d8 + 0x5a4 + (uVar2 & 0xff) * 8));

    if (iVar1 != 0) {

      (**(code **)(*(int *)*puVar3 + 0xd4))(1);

      (**(code **)(*(int *)*puVar3 + 0x34c))();

    }

    uVar2 = uVar2 + 1;

    puVar3 = puVar3 + 1;

  } while ((int)uVar2 < 8);

  return;

}
