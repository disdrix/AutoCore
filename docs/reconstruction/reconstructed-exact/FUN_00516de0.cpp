// =============================================================================
// FUN_00516de0
// -----------------------------------------------------------------------------
// Stable ID: aa_00516de0
// Address:   0x00516de0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00516de0 @ 0x00516de0
// Stable ID: aa_00516de0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×7, while×3, do×2, return×2, for×1.
//  - Notable callees: FUN_004b8ed0×3, FUN_004022a0×2, memmove×2, FUN_004294f0, FUN_004b99c0, FUN_00516de0, LeaveCriticalSection, __RTDynamicCast.
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

void __thiscall FUN_00516de0(int param_1,int param_2)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ *_Src;

  void *_Src_00;

  uint uVar4;

  uint32_t /* width from decompiler */ *_Dst;

  void *pvVar5;

  uint32_t /* width from decompiler */ local_8;

  int local_4;

  

  _Dst = *(uint32_t /* width from decompiler */ **)(param_1 + 0x124);

  if (_Dst != *(uint32_t /* width from decompiler */ **)(param_1 + 0x128)) {

    _Src = _Dst + 1;

    do {

      pvVar5 = (void *)*_Dst;

      cVar1 = FUN_004b8ed0(param_2);

      if (cVar1 == '\0') {

        _Dst = _Dst + 1;

        _Src = _Src + 1;

      }

      else {

        memmove(_Dst,_Src,(*(int *)(param_1 + 0x128) - (int)_Src >> 2) * 4);

        *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x128) + -4;

        if (pvVar5 != (void *)0x0) {

          FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar5);

        }

      }

    } while (_Dst != *(uint32_t /* width from decompiler */ **)(param_1 + 0x128));

  }

  pvVar5 = *(void **)(param_1 + 0x138);

  uVar3 = param_2;

  if (pvVar5 != *(void **)(param_1 + 0x13c)) {

    _Src_00 = (void *)((int)pvVar5 + 4);

    do {

      uVar3 = param_2;

      cVar1 = FUN_004b8ed0(param_2);

      if (cVar1 == '\0') {

        pvVar5 = (void *)((int)pvVar5 + 4);

        _Src_00 = (void *)((int)_Src_00 + 4);

      }

      else {

        memmove(pvVar5,_Src_00,(*(int *)(param_1 + 0x13c) - (int)_Src_00 >> 2) * 4);

        *(int *)(param_1 + 0x13c) = *(int *)(param_1 + 0x13c) + -4;

      }

    } while (pvVar5 != *(void **)(param_1 + 0x13c));

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

      for (uVar4 = 0;

          (*(int *)(iVar2 + 0x6b0) != 0 &&

          (uVar4 < (uint)(*(int *)(iVar2 + 0x6b4) - *(int *)(iVar2 + 0x6b0) >> 2)));

          uVar4 = uVar4 + 1) {

        FUN_004b8ed0(uVar3);

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
