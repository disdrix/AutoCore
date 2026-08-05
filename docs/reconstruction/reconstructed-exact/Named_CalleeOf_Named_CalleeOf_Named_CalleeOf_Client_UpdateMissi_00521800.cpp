// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_UpdateMissi_00521800
// -----------------------------------------------------------------------------
// Stable ID: aa_00521800
// Callee of Named_CalleeOf_Named_CalleeOf_Client_UpdateMissionJournal
// Address:   0x00521800  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_UpdateMissionJournal: mission/objective helper. Evidence string: "Unknown". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Human"
//   - "Unknown"
//   - "Biomek"
//   - "Mutant"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_007a69d0×4, FUN_007a6de0×4, FUN_00521800.
//  - Strings: "Human"; "Unknown"; "Biomek"; "Mutant".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_UpdateMissionJournal
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_UpdateMissi_00521800(int param_1)



{

  char cVar1;

  char *pcVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  cVar1 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c)

                   + 0x532);

  if (cVar1 == '\0') {

    uVar3 = 0xffffffff;

    pcVar2 = "Human";

    FUN_007a69d0("Human",0xffffffff);

    FUN_007a6de0(pcVar2,uVar3);

    return;

  }

  if (cVar1 != '\x01') {

    if (cVar1 != '\x02') {

      uVar3 = 0xffffffff;

      pcVar2 = "Unknown";

      FUN_007a69d0("Unknown",0xffffffff);

      FUN_007a6de0(pcVar2,uVar3);

      return;

    }

    uVar3 = 0xffffffff;

    pcVar2 = "Biomek";

    FUN_007a69d0("Biomek",0xffffffff);

    FUN_007a6de0(pcVar2,uVar3);

    return;

  }

  uVar3 = 0xffffffff;

  pcVar2 = "Mutant";

  FUN_007a69d0("Mutant",0xffffffff);

  FUN_007a6de0(pcVar2,uVar3);

  return;

}
