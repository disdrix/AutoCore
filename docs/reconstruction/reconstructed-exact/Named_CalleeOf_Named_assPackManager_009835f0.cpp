// =============================================================================
// Named_CalleeOf_Named_assPackManager_009835f0
// -----------------------------------------------------------------------------
// Stable ID: aa_009835f0
// Callee of Named_assPackManager
// Address:   0x009835f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assPackManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0044e8c0, FUN_00719630, FUN_009835f0, FUN_00989b60.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_assPackManager
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

int Named_CalleeOf_Named_assPackManager_009835f0(void)



{

  char cVar1;

  int in_EAX;

  int iVar2;

  int *local_10c;

  int local_108;

  char local_104 [260];

  

  FUN_00719630();

  local_10c = DAT_00d1eac0;

  if (local_104[0] != '\0') {

    local_10c = (int *)0x0;

    cVar1 = FUN_00989b60(local_104,&local_10c);

    if (cVar1 == '\0') {

      local_10c = (int *)0x0;

    }

    else {

      local_10c = (int *)*local_10c;

    }

  }

  iVar2 = 0;

  if (local_10c != (int *)0x0) {

    FUN_0044e8c0(&local_108);

    if (local_108 == *(int *)(in_EAX + 8)) {

      return 0;

    }

    iVar2 = local_108 + 0xc;

  }

  return iVar2;

}
