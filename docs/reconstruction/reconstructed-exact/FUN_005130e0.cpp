// =============================================================================
// FUN_005130e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005130e0
// Address:   0x005130e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005130e0 @ 0x005130e0
// Stable ID: aa_005130e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: return×4, if×2, switch×1.
//  - Notable callees: FUN_005130e0, __RTDynamicCast.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

byte __thiscall FUN_005130e0(int param_1,char param_2)



{

  int iVar1;

  

  if ((param_2 == '\0') || (*(int *)(param_1 + 0xac) == 0)) {

    switch(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xa8) + 0x38)) {

    case 1:

      return *(byte *)(*(int *)(*(int *)(param_1 + 0xa8) + 0x3c) + 0x3f2) >> 7;

    case 4:

    case 6:

    case 8:

    case 10:

    case 0xc:

    case 0x10:

    case 0x1a:

    case 0x1c:

    case 0x32:

    case 0x34:

    case 0x42:

      return 1;

    case 0xe:

      iVar1 = __RTDynamicCast(param_1,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                              &CVOGVehicle::RTTI_Type_Descriptor,0);

      if ((iVar1 != 0) && (*(char *)(iVar1 + 0x2ac) != '\0')) {

        return 1;

      }

    }

  }

  return 0;

}
