// =============================================================================
// FUN_0048f0b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0048f0b0
// Address:   0x0048f0b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048f0b0 @ 0x0048f0b0
// Stable ID: aa_0048f0b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0048f0b0, FUN_004bc180, FUN_004e8830.
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

void __thiscall FUN_0048f0b0(int param_1,int *param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  char cVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ unaff_EBX;

  uint32_t /* width from decompiler */ unaff_retaddr;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ uStack_c;

  uint32_t /* width from decompiler */ uStack_8;

  

  if (param_2 != (int *)0x0) {

    if (((uint)param_2[0x5f] >> 5 & 1) != 0) {

      puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*param_2 + 0x1c8))();

      (**(code **)*puVar3)(*(uint32_t /* width from decompiler */ *)(param_1 + 0xb8),param_3,param_4,0);

    }

    if (((uint)param_2[0x5f] >> 6 & 1) != 0) {

      FUN_004e8830(param_4,&local_10);

      uVar1 = *(uint32_t /* width from decompiler */ *)(param_3 + 8);

      (**(code **)(*param_2 + 0x218))(*(uint32_t /* width from decompiler */ *)(param_1 + 0xb8));

      puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*param_2 + 0x1cc))();

      cVar2 = (**(code **)*puVar3)

                        (uVar1,unaff_EBX,unaff_retaddr,param_3,uStack_14,local_10,uStack_c,uStack_8,

                         0);

      if (cVar2 != '\0') {

        (**(code **)(*param_2 + 0xb8))(param_2[0x2e]);

        piVar4 = (int *)(**(code **)(*param_2 + 0x1cc))();

        (**(code **)(*piVar4 + 0x20))();

      }

    }

    FUN_004bc180(param_2);

  }

  return;

}
