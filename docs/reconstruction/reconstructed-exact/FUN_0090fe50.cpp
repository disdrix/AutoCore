// =============================================================================
// FUN_0090fe50
// -----------------------------------------------------------------------------
// Stable ID: aa_0090fe50
// Address:   0x0090fe50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0090fe50 @ 0x0090fe50
// Stable ID: aa_0090fe50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0096d550×2, FUN_007562d0, FUN_0090fe50, __RTDynamicCast.
//  - Return sites: 1.

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

void FUN_0090fe50(void)



{

  int iVar1;

  int *unaff_EBX;

  

  if (DAT_00d09a68 != 0) {

    if (unaff_EBX[0x288] != 0) {

      FUN_0096d550(unaff_EBX[0x288]);

      FUN_0096d550(unaff_EBX[0x289]);

    }

    (**(code **)(*DAT_00d09a60 + 8))();

    (**(code **)(*unaff_EBX + 0x1a8))();

    FUN_007562d0();

    DAT_00d09a68 = 0;

    iVar1 = __RTDynamicCast(unaff_EBX[0x28a],0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                            &CVOGGraphicsBase::RTTI_Type_Descriptor,0);

    if (iVar1 != 0) {

      *(uint32_t /* width from decompiler */ *)(iVar1 + 8) = 0;

    }

  }

  return;

}
