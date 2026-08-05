// =============================================================================
// Named_CalleeOf_Client_RecvInventoryEquip_00571010
// -----------------------------------------------------------------------------
// Stable ID: aa_00571010
// Callee of Client_RecvInventoryEquip (+7 other named callers)
// Address:   0x00571010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvInventoryEquip: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_RecvInventoryEquip (+7 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, while×1.
//  - Notable callees: FUN_004022a0×2, LeaveCriticalSection×2, FUN_004294f0, FUN_00571010.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_RecvInventoryEquip (+7 other named callers)
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

int __thiscall Named_CalleeOf_Client_RecvInventoryEquip_00571010(int param_1,int param_2,int param_3)



{

  int iVar1;

  int local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0;

  FUN_004294f0();

  iVar1 = FUN_004022a0(&local_4,&local_8);

  while( true ) {

    if (iVar1 != 0) {

      if (*(char *)(param_1 + 0x54) != '\0') {

        *(uint8_t *)(param_1 + 0x54) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));

      }

      return 0;

    }

    if (((local_8 != 0) && (*(int *)(local_8 + 0x160) == param_2)) &&

       (*(int *)(local_8 + 0x164) == param_3)) break;

    iVar1 = FUN_004022a0(&local_4,&local_8);

  }

  if (*(char *)(param_1 + 0x54) != '\0') {

    *(uint8_t *)(param_1 + 0x54) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));

  }

  return local_8;

}
