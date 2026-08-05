// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: Skill_GetCategoryCooldownMap×2, FUN_005ae2b0.
//  - Return sites: 1.

// =============================================================================
// Skill_GetCategoryCooldownMap
// -----------------------------------------------------------------------------
// Stable ID: aa_00518d70
// Address:   0x00518d70  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* Skill_GetCategoryCooldownMap(pMapOwner)

   

   Parameters:

     pMapOwner - object holding map pointer at +0x6c (lazy-alloc red-black map)

   

   Returns: map* at +0x6c

   VERIFIED lazy std::map-style construction. */



void * __fastcall Skill_GetCategoryCooldownMap(void *pMapOwner)



{

  void *pvVar1;

  int iVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a3612;

  local_c = ExceptionList;

  if (*(int *)((int)pMapOwner + 0x6c) == 0) {

    ExceptionList = &local_c;

    pvVar1 = operator_new(0xc);

    local_4 = 0;

    if (pvVar1 == (void *)0x0) {

      pvVar1 = (void *)0x0;

    }

    else {

      iVar2 = FUN_005ae2b0();

      *(int *)((int)pvVar1 + 4) = iVar2;

      *(uint8_t *)(iVar2 + 0x19) = 1;

      *(int *)(*(int *)((int)pvVar1 + 4) + 4) = *(int *)((int)pvVar1 + 4);

      *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)((int)pvVar1 + 4) = *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 4);

      *(int *)(*(int *)((int)pvVar1 + 4) + 8) = *(int *)((int)pvVar1 + 4);

      *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 8) = 0;

    }

    *(void **)((int)pMapOwner + 0x6c) = pvVar1;

  }

  ExceptionList = local_c;

  return *(void **)((int)pMapOwner + 0x6c);

}
