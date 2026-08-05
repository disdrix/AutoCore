// =============================================================================
// FUN_00518c20  (leave-FUN — product name withheld 2026-07-29)
// -----------------------------------------------------------------------------
// Stable ID: aa_00518c20
// Address:   0x00518c20  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 from raw capture; dual A/B leave-FUN 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE: Lazy-get map-like header at this+0x68 (0xC shell + FUN_0058d9c0 head).
// Twin of Skill_GetCategoryCooldownMap (slot +0x6c). Used by active-cast Lookup/Clear
// and LocalCastValidate size gate. No string/RTTI → retain FUN_00518c20.
// Dual: reviews/A_aa_00518c20_FUN_00518c20.md, B_aa_00518c20_FUN_00518c20.md
//
// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: operator_new, FUN_0058d9c0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 * - leave-FUN: do not promote Skill_GetActiveCastBindingMap without string/RTTI.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall FUN_00518c20(int param_1)



{

  void *pvVar1;

  int iVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a35fd;

  local_c = ExceptionList;

  if (*(int *)(param_1 + 0x68) == 0) {

    ExceptionList = &local_c;

    pvVar1 = operator_new(0xc);

    local_4 = 0;

    if (pvVar1 == (void *)0x0) {

      pvVar1 = (void *)0x0;

    }

    else {

      iVar2 = FUN_0058d9c0();

      *(int *)((int)pvVar1 + 4) = iVar2;

      *(uint8_t *)(iVar2 + 0x29) = 1;

      *(int *)(*(int *)((int)pvVar1 + 4) + 4) = *(int *)((int)pvVar1 + 4);

      *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)((int)pvVar1 + 4) = *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 4);

      *(int *)(*(int *)((int)pvVar1 + 4) + 8) = *(int *)((int)pvVar1 + 4);

      *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 8) = 0;

    }

    *(void **)(param_1 + 0x68) = pvVar1;

  }

  ExceptionList = local_c;

  return *(uint32_t /* width from decompiler */ *)(param_1 + 0x68);

}
