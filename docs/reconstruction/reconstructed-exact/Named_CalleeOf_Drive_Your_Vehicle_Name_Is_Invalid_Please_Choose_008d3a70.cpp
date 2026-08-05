// =============================================================================
// Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_008d3a70
// -----------------------------------------------------------------------------
// Stable ID: aa_008d3a70
// Callee of Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_Anoth
// Address:   0x008d3a70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, goto×1.
//  - Notable callees: FUN_008cf510×2, FUN_008cf3b0, FUN_008cf7f0, FUN_008d3090, FUN_008d3a70.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_Anoth
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

void Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_008d3a70(void)



{

  int iVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar2;

  

  if (DAT_00d1b77c == 0) {

    return;

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x568) = 0;

  *(uint8_t *)(in_EAX + 0x5bc) = 1;

  iVar1 = DAT_00d1b77c;

  *(uint32_t /* width from decompiler */ *)(DAT_00d1b77c + 0x600) = *(uint32_t /* width from decompiler */ *)(DAT_00d1b77c + 0x5f4);

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x604) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x5f8);

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x608) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x5fc);

  iVar1 = DAT_00d1b77c;

  *(uint32_t /* width from decompiler */ *)(DAT_00d1b77c + 0x5d0) = *(uint32_t /* width from decompiler */ *)(DAT_00d1b77c + 0x5b8);

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x5d4) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x5bc);

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x5d8) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x5c0);

  FUN_008cf7f0(0);

  iVar1 = *(int *)(in_EAX + 0x568);

  if (-1 < iVar1) {

    if (iVar1 < 2) {

      FUN_008cf510(1);

      uVar2 = 0;

    }

    else {

      if (iVar1 != 2) goto LAB_008d3b0d;

      FUN_008cf510(0);

      uVar2 = 1;

    }

    FUN_008cf3b0(uVar2);

  }

LAB_008d3b0d:

  *(uint8_t *)(*(int *)(in_EAX + 0x568) + 0x5c0 + in_EAX) = 1;

  FUN_008d3090();

  *(uint8_t *)(in_EAX + 0x5c0) = 1;

  return;

}
