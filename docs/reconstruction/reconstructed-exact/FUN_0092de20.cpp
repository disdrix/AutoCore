// =============================================================================
// FUN_0092de20
// -----------------------------------------------------------------------------
// Stable ID: aa_0092de20
// Address:   0x0092de20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092de20 @ 0x0092de20
// Stable ID: aa_0092de20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00793aa0, FUN_0092de20.
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

void __thiscall FUN_0092de20(int param_1,uint8_t param_2)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *in_EAX;

  int unaff_ESI;

  uint32_t /* width from decompiler */ local_a8 [8];

  uint32_t /* width from decompiler */ local_88;

  uint32_t /* width from decompiler */ local_84;

  uint8_t local_28;

  uint8_t local_27;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_18;

  uint8_t local_10 [16];

  

  if (in_EAX != (uint32_t /* width from decompiler */ *)0x0) {

    local_18 = *in_EAX;

    local_28 = param_2;

    local_27 = *(uint8_t *)((int)in_EAX + 0x26);

    local_20 = in_EAX[0xb];

    local_a8[0] = 0x9000;

    if (param_1 != 0) {

      FUN_00793aa0(local_10,param_1,9);

    }

    iVar1 = *(int *)(unaff_ESI + 0xe98);

    iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

    local_88 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + iVar1);

    local_84 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + iVar1);

    if (*(int *)(unaff_ESI + 0xc78) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0xc78) + 0x18))(0xffffffff,local_a8,0xa8,0);

    }

  }

  return;

}
