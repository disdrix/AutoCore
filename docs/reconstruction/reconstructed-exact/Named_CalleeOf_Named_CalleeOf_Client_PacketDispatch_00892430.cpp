// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_00892430
// -----------------------------------------------------------------------------
// Stable ID: aa_00892430
// Callee of Named_CalleeOf_Client_PacketDispatch
// Address:   0x00892430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, while×1.
//  - Notable callees: FUN_004113b0×2, LeaveCriticalSection×2, FUN_004294f0, FUN_008923a0, FUN_00892430.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_PacketDispatch
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

int Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_00892430(int param_1,int param_2,int param_3,char param_4)



{

  int iVar1;

  int local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0;

  FUN_004294f0();

  iVar1 = FUN_004113b0(param_1 + 0x50c,&local_8);

  while (iVar1 == 0) {

    if (((local_8 != 0) && (*(int *)(local_8 + 0x5b0) == param_2)) &&

       (*(int *)(local_8 + 0x5b4) == param_3)) {

      if (*(char *)(param_1 + 0x534) != '\0') {

        *(uint8_t *)(param_1 + 0x534) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x510));

      }

      return local_8;

    }

    iVar1 = FUN_004113b0(param_1 + 0x50c,&local_8);

  }

  if (*(char *)(param_1 + 0x534) != '\0') {

    *(uint8_t *)(param_1 + 0x534) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x510));

  }

  if (param_4 != '\0') {

    iVar1 = FUN_008923a0();

    return iVar1;

  }

  return 0;

}
