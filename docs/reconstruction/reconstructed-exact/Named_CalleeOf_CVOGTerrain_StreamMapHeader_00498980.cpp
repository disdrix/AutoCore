// =============================================================================
// Named_CalleeOf_CVOGTerrain_StreamMapHeader_00498980
// -----------------------------------------------------------------------------
// Stable ID: aa_00498980
// Callee of CVOGTerrain_StreamMapHeader
// Address:   0x00498980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGTerrain_StreamMapHeader: map/sector helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×5, if×4.
//  - Notable callees: FUN_00498980, FUN_00793710, FUN_00793830, FUN_0079cd10, FUN_0079cd30.
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of CVOGTerrain_StreamMapHeader
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

bool __thiscall Named_CalleeOf_CVOGTerrain_StreamMapHeader_00498980(int *param_1,uint32_t /* width from decompiler */ param_2,uint8_t *param_3)



{

  int iVar1;

  uint8_t local_c [12];

  

  if (*(char *)((int)param_1 + 5) != '\0') {

    if ((char)param_1[2] == '\0') {

      (**(code **)(*param_1 + 4))(param_3,1);

      return true;

    }

    FUN_0079cd10(param_2,local_c,0xc);

    iVar1 = FUN_00793830(local_c);

    *param_3 = iVar1 != 0;

    return true;

  }

  if (*(char *)((int)param_1 + 6) == '\0') {

    return false;

  }

  if ((char)param_1[2] == '\0') {

    (**(code **)(*param_1 + 8))(param_3,1);

    return true;

  }

  FUN_00793710(local_c,*param_3,0xc);

  iVar1 = FUN_0079cd30(param_2,local_c);

  return iVar1 != 0;

}
