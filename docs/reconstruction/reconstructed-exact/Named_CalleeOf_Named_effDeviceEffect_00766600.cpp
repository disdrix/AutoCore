// =============================================================================
// Named_CalleeOf_Named_effDeviceEffect_00766600
// -----------------------------------------------------------------------------
// Stable ID: aa_00766600
// Callee of Named_effDeviceEffect
// Address:   0x00766600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_effDeviceEffect: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00766600, WriteFile.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_effDeviceEffect
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

int __thiscall Named_CalleeOf_Named_effDeviceEffect_00766600(int param_1,LPCVOID param_2,DWORD param_3)



{

  BOOL BVar1;

  DWORD local_4;

  

  local_4 = 0;

  BVar1 = WriteFile(*(HANDLE *)(param_1 + 8),param_2,param_3,&local_4,(LPOVERLAPPED)0x0);

  return (BVar1 != 0) - 1;

}
