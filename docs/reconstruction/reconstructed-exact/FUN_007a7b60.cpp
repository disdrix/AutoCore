// =============================================================================
// FUN_007a7b60
// -----------------------------------------------------------------------------
// Stable ID: aa_007a7b60
// Address:   0x007a7b60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a7b60 @ 0x007a7b60
// Stable ID: aa_007a7b60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: return×2, switch×1, if×1.
//  - Notable callees: FUN_007a7b60.
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

void __thiscall

FUN_007a7b60(int *param_1,char param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int unaff_retaddr;

  uint8_t local_10 [12];

  uint32_t /* width from decompiler */ *puStack_4;

  

  uVar4 = 0;

  uVar3 = 0;

  (**(code **)(*param_1 + 0x140))(local_10,param_5);

  switch(unaff_retaddr) {

  case 0:

  case 3:

  case 6:

    break;

  case 1:

  case 4:

  case 7:

    break;

  case 2:

  case 5:

  case 8:

    break;

  default:

    if (param_2 != '\0') {

      puVar1 = (uint32_t /* width from decompiler */ *)(**(code **)(*param_1 + 0x120))(local_10,param_3,param_4);

      uVar4 = *puVar1;

      iVar2 = (**(code **)(*param_1 + 0x120))(&stack0xffffffe4,puStack_4,param_4);

      uVar3 = *(uint32_t /* width from decompiler */ *)(iVar2 + 4);

    }

    *puStack_4 = uVar4;

    puStack_4[1] = uVar3;

    return;

  }

                    /* WARNING: Could not recover jumptable at 0x007a7c00. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(&UNK_007a7cc0 + (uint)(byte)(&UNK_007a7ccc)[unaff_retaddr] * 4))();

  return;

}
