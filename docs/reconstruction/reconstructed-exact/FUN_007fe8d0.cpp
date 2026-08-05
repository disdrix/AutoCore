// =============================================================================
// FUN_007fe8d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fe8d0
// Address:   0x007fe8d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fe8d0 @ 0x007fe8d0
// Stable ID: aa_007fe8d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: CNDHash_LookupByKey, FUN_0040c5c0, FUN_007fb640, FUN_007fe8d0, __RTDynamicCast, strncpy.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_007fe8d0(void)



{

  int *piVar1;

  int in_EAX;

  void *pvVar2;

  int iVar3;

  char acStack_98 [128];

  uint32_t /* width from decompiler */ uStack_18;

  float fStack_14;

  float fStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  uint32_t /* width from decompiler */ uStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  if (*(uint *)(in_EAX + 0x3c20) != 0) {

    pvVar2 = CNDHash_LookupByKey(*(void **)(*(int *)(in_EAX + 0xe98) + 0x548),

                                 *(uint *)(in_EAX + 0x3c20));

    if (pvVar2 != (void *)0x0) {

      if (*(int *)((int)pvVar2 + 0x158) == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)((int)pvVar2 + 0x15c) - *(int *)((int)pvVar2 + 0x158) >> 2;

      }

      if (*(int *)(in_EAX + 0x3c24) < iVar3) {

        piVar1 = *(int **)(*(int *)((int)pvVar2 + 0x158) + *(int *)(in_EAX + 0x3c24) * 4);

        iVar3 = (**(code **)(*piVar1 + 0x50))();

        if (iVar3 == 0xc) {

          iVar3 = __RTDynamicCast(piVar1,0,&CVOGObjectiveRequirement::RTTI_Type_Descriptor,

                                  &CVOGObjectiveRequirement_UseItem::RTTI_Type_Descriptor,0);

          if (iVar3 != 0) {

            uStack_18 = 0xffffffff;

            acStack_98[0] = '\0';

            strncpy(acStack_98,*(char **)(iVar3 + 0x40),0x7f);

            uStack_8 = 0xffffffff;

            uStack_4 = 0xffffffff;

            fStack_14 = g_flLevelUpUiBase_Inferred;

            uStack_c = 2;

            fStack_10 = g_flMultiKillCountBlend;

            uStack_18 = 0xffff0000;

            FUN_0040c5c0(acStack_98);

            FUN_007fb640();

            return 1;

          }

        }

        return 0;

      }

    }

  }

  return 0;

}
