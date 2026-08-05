// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Ski_00421f80
// -----------------------------------------------------------------------------
// Stable ID: aa_00421f80
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Skill_DbLoadSkills
// Address:   0x00421f80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Skill_DbLoadSkills: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: while×1, for×1, return×1.
//  - Notable callees: FUN_00421f80.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Skill_DbLoadSkills
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Ski_00421f80(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  while (in_EAX != param_2) {

    puVar1 = in_EAX + 0x24d;

    puVar3 = unaff_EBX;

    puVar4 = in_EAX;

    for (iVar2 = 0x24d; in_EAX = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar4 = *puVar3;

      puVar3 = puVar3 + 1;

      puVar4 = puVar4 + 1;

    }

  }

  return;

}
