// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00914890, NDSpecialFX_LoadFromScriptName.
//  - Strings: "skill_n_fixme_power-dump".
//  - Return sites: 1.

// =============================================================================
// Skill_skill_n_fixme_power_dump
// -----------------------------------------------------------------------------
// Stable ID: aa_00914890
// Address:   0x00914890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "skill_n_fixme_power-dump"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Skill_skill_n_fixme_power_dump(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ local_18 [2];

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if (DAT_00d1b6d8 != 0) {

    local_18[0] = 0x20c1;

    puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0x164 + DAT_00d1b6d8);

    local_10 = *puVar1;

    local_c = puVar1[1];

    local_8 = puVar1[2];

    local_4 = puVar1[3];

    if (g_pSectorNetConnection_INFERRED != (void *)0x0) {

      (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 0x18))(0xffffffff,local_18,0x18,0);

    }

    pvVar2 = NDSpecialFX_LoadFromScriptName("skill_n_fixme_power-dump",2,0);

    if (pvVar2 != (void *)0x0) {

      (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 4) + 4) + 4 +

                           *(int *)(DAT_00d1b6d8 + 0x250)) + 0xf8))(pvVar2,1,0);

    }

  }

  return;

}
