// =============================================================================
// Named_CalleeOf_Drive_Invalid_Vehicle_Name_008fd160
// -----------------------------------------------------------------------------
// Stable ID: aa_008fd160
// Callee of Drive_Invalid_Vehicle_Name
// Address:   0x008fd160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_Invalid_Vehicle_Name: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004fcb50, FUN_008fd160.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Drive_Invalid_Vehicle_Name
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

uint Named_CalleeOf_Drive_Invalid_Vehicle_Name_008fd160(void)



{

  uint in_EAX;

  uint uVar1;

  int unaff_ESI;

  

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x514) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x528) = 0;

  if ((DAT_00d1b6d8 != 0) && (*(int *)(DAT_00d1b6d8 + 0x250) != 0)) {

    if ((*(int *)(unaff_ESI + 0x730) != 0) && (*(int *)(*(int *)(unaff_ESI + 0x730) + 0x508) != 0))

    {

      uVar1 = FUN_004fcb50();

      *(uint *)(unaff_ESI + 0x514) = uVar1 & 0xff;

    }

    uVar1 = (uint)*(byte *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x288);

    *(uint *)(unaff_ESI + 0x52c) = uVar1;

    *(uint *)(unaff_ESI + 0x528) = uVar1;

    return (uint)*(byte *)(unaff_ESI + 0x514);

  }

  return in_EAX & 0xffffff00;

}
