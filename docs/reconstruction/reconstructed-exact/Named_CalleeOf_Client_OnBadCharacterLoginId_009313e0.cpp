// =============================================================================
// Named_CalleeOf_Client_OnBadCharacterLoginId_009313e0
// -----------------------------------------------------------------------------
// Stable ID: aa_009313e0
// Callee of Client_OnBadCharacterLoginId (+1 other named callers)
// Address:   0x009313e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_OnBadCharacterLoginId: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_OnBadCharacterLoginId (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0092f360, FUN_009313e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_OnBadCharacterLoginId (+1 other named callers)
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

void Named_CalleeOf_Client_OnBadCharacterLoginId_009313e0(void)



{

  char cVar1;

  int unaff_ESI;

  uint32_t /* width from decompiler */ local_18 [2];

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  

  FUN_0092f360();

  local_10 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x508);

  local_c = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x50c);

  local_18[0] = 0x8001;

  local_8 = 0xffffffff;

  if (*(int *)(unaff_ESI + 0xc7c) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0xc7c) + 8))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0xc7c) + 0x18))(0xffffffff,local_18,0x18,0);

    }

  }

  return;

}
