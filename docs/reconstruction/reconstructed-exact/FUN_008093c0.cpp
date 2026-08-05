// =============================================================================
// FUN_008093c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008093c0
// Address:   0x008093c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008093c0 @ 0x008093c0
// Stable ID: aa_008093c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CVOGMap_SetVariable, FUN_004bb160, FUN_008093c0, Object_ResolveFromTFID, TFID_NotEquals.
//  - Return sites: 2.

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

void FUN_008093c0(void)



{

  int in_EAX;

  int iVar1;

  int *piVar2;

  void *pvVar3;

  int unaff_EBX;

  

  if (*(char *)(in_EAX + 4) == '\0') {

    if ((((*(char *)(in_EAX + 0x20) == '\0') || (*(int *)(unaff_EBX + 0xe98) == 0)) ||

        (iVar1 = TFID_NotEquals((void *)(in_EAX + 0x10),

                                (void *)(*(int *)(*(int *)(*(int *)(unaff_EBX + 0xe98) + 4) + 4) +

                                         0x164 + *(int *)(unaff_EBX + 0xe98))), (char)iVar1 == '\0')

        ) && (piVar2 = (int *)FUN_004bb160(0,*(uint32_t /* width from decompiler */ *)(in_EAX + 8),

                                           *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc)), piVar2 != (int *)0x0)) {

      pvVar3 = Object_ResolveFromTFID((TFID_16 *)(in_EAX + 0x10));

      (**(code **)(*piVar2 + 0x2c0))(pvVar3);

    }

    return;

  }

  CVOGMap_SetVariable(*(uint32_t /* width from decompiler */ *)(in_EAX + 8),*(uint32_t /* width from decompiler */ *)(in_EAX + 0xc),0);

  return;

}
