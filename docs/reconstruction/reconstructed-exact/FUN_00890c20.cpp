// =============================================================================
// FUN_00890c20
// -----------------------------------------------------------------------------
// Stable ID: aa_00890c20
// Address:   0x00890c20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00890c20 @ 0x00890c20
// Stable ID: aa_00890c20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_004113b0×2, FUN_004294f0, FUN_00792490, FUN_00890c20, LeaveCriticalSection.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_00890c20(int *param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int *piStack_c;

  uint32_t /* width from decompiler */ local_8 [2];

  

  if (DAT_00d1790c == '\0') {

    puVar2 = (uint32_t /* width from decompiler */ *)(**(code **)(*param_1 + 0x120))(local_8,1,0);

    _DAT_00d178fc = *puVar2;

    _DAT_00d17900 = puVar2[1];

  }

  local_8[0] = 0;

  FUN_004294f0();

  iVar3 = FUN_004113b0(param_1 + 0x143,&piStack_c);

  piVar1 = piStack_c;

  while (iVar3 == 0) {

    piStack_c = piVar1;

    if (piVar1 != (int *)0x0) {

      (**(code **)(*piVar1 + 0x440))();

      (**(code **)(*param_1 + 0xb0))(piVar1);

    }

    iVar3 = FUN_004113b0(param_1 + 0x143,&piStack_c);

    piVar1 = piStack_c;

  }

  if ((char)param_1[0x14d] != '\0') {

    *(uint8_t *)(param_1 + 0x14d) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x144));

  }

  (**(code **)(*param_1 + 0x3ac))();

  FUN_00792490();

  return;

}
