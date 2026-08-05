// =============================================================================
// FUN_008e8b50
// -----------------------------------------------------------------------------
// Stable ID: aa_008e8b50
// Address:   0x008e8b50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008e8b50 @ 0x008e8b50
// Stable ID: aa_008e8b50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: do×1, if×1, while×1, return×1.
//  - Notable callees: FUN_008e8b50.
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

void FUN_008e8b50(int param_1,int param_2,char param_3)



{

  int iVar1;

  int in_EAX;

  int *piVar2;

  int iVar3;

  

  piVar2 = (int *)(in_EAX + 0x52c);

  iVar3 = 4;

  do {

    iVar1 = *piVar2;

    if ((iVar1 != 0) &&

       (((*(int *)(iVar1 + 8) == param_1 && (*(int *)(iVar1 + 0xc) == param_2)) || (param_3 != '\0')

        ))) {

      iVar1 = *piVar2;

      *(uint32_t /* width from decompiler */ *)(iVar1 + 8) = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc) = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)*piVar2 = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(*piVar2 + 0x1c) = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(*piVar2 + 0x10) = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(*piVar2 + 0x18) = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(*piVar2 + 0x14) = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(*piVar2 + 0x24) = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(*piVar2 + 0x28) = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(*piVar2 + 0x2c) = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(*piVar2 + 0x30) = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(*piVar2 + 0x34) = 0;

      *(uint32_t /* width from decompiler */ *)(*piVar2 + 0x38) = 0;

      *(uint32_t /* width from decompiler */ *)(*piVar2 + 0x3c) = 0;

      *(uint32_t /* width from decompiler */ *)(*piVar2 + 0x40) = 0;

      *(uint32_t /* width from decompiler */ *)(*piVar2 + 0x44) = 0;

      *(uint32_t /* width from decompiler */ *)(*piVar2 + 0x48) = 0;

      *(uint8_t *)(*piVar2 + 0x4c) = 0;

      *(uint8_t *)(*piVar2 + 0x8c) = 0;

    }

    piVar2 = piVar2 + 1;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  return;

}
