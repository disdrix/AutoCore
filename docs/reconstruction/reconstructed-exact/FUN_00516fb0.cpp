// =============================================================================
// FUN_00516fb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00516fb0
// Address:   0x00516fb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00516fb0 @ 0x00516fb0
// Stable ID: aa_00516fb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×4, while×3, do×2, for×1, return×1.
//  - Notable callees: FUN_004b6f00×3, FUN_004022a0×2, FUN_004294f0, FUN_00516fb0, LeaveCriticalSection, __RTDynamicCast.
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

void __thiscall FUN_00516fb0(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ local_8;

  int local_4;

  

  uVar1 = param_2;

  iVar2 = *(int *)(param_1 + 0x124);

  if (iVar2 != *(int *)(param_1 + 0x128)) {

    do {

      FUN_004b6f00(uVar1);

      iVar2 = iVar2 + 4;

    } while (iVar2 != *(int *)(param_1 + 0x128));

  }

  iVar2 = *(int *)(param_1 + 0x138);

  if (iVar2 != *(int *)(param_1 + 0x13c)) {

    do {

      FUN_004b6f00(uVar1);

      iVar2 = iVar2 + 4;

    } while (iVar2 != *(int *)(param_1 + 0x13c));

  }

  local_8 = 0;

  param_2 = 0;

  FUN_004294f0();

  iVar2 = FUN_004022a0(&local_8,&param_2);

  while (iVar2 == 0) {

    if ((((*(int *)(param_2 + 0x1c) == 1) &&

         (iVar2 = __RTDynamicCast(param_2,0,&CVOGHBBase::RTTI_Type_Descriptor,

                                  &CVOGHBSkillBase::RTTI_Type_Descriptor,0), iVar2 != 0)) &&

        (*(int *)(iVar2 + 0x6b0) != 0)) &&

       (local_4 = *(int *)(iVar2 + 0x6b4) - *(int *)(iVar2 + 0x6b0) >> 2, local_4 != 0)) {

      for (uVar3 = 0;

          (*(int *)(iVar2 + 0x6b0) != 0 &&

          (uVar3 < (uint)(*(int *)(iVar2 + 0x6b4) - *(int *)(iVar2 + 0x6b0) >> 2)));

          uVar3 = uVar3 + 1) {

        FUN_004b6f00(uVar1);

      }

    }

    iVar2 = FUN_004022a0(&local_8,&param_2);

  }

  iVar2 = *(int *)(param_1 + 0xb0);

  if (*(char *)(iVar2 + 0x28) != '\0') {

    *(uint8_t *)(iVar2 + 0x28) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 4));

  }

  return;

}
