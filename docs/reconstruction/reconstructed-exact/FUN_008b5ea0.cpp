// =============================================================================
// FUN_008b5ea0
// -----------------------------------------------------------------------------
// Stable ID: aa_008b5ea0
// Address:   0x008b5ea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008b5ea0 @ 0x008b5ea0
// Stable ID: aa_008b5ea0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: __allrem×4, sprintf×4, __alldiv×3, CVOGReaction_ResolveObjectTarget, FUN_008b5a40, FUN_008b5ea0.
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

void __fastcall FUN_008b5ea0(int *param_1)



{

  int *piVar1;

  char cVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar3;

  uint64_t uVar4;

  char acStack_34 [52];

  

  if ((in_EAX != 0) && (cVar2 = (**(code **)(*param_1 + 0x3d8))(), cVar2 != '\0')) {

    param_1[0x146] = *(int *)(in_EAX + 0x200);

    param_1[0x147] = *(int *)(in_EAX + 0x204);

    param_1[0x148] = *(int *)(in_EAX + 0x1e8);

    param_1[0x149] = *(int *)(in_EAX + 0x1ec);

    __allrem();

    sprintf(acStack_34,"%d");

    (**(code **)(*(int *)param_1[0x151] + 0x1d8))();

    uVar3 = __alldiv(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x1e8));

    __allrem(uVar3);

    sprintf(&stack0xffffffc0,"%d");

    (**(code **)(*(int *)param_1[0x152] + 0x1d8))();

    uVar4 = __alldiv(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x1e8),*(uint32_t /* width from decompiler */ *)(in_EAX + 0x1ec),1000000,0);

    uVar4 = __allrem(uVar4,1000,0);

    sprintf(&stack0xffffffb4,"%d",(int)uVar4,(int)((ulonglong)uVar4 >> 0x20));

    (**(code **)(*(int *)param_1[0x153] + 0x1d8))(&stack0xffffffb4,1,1);

    uVar4 = __alldiv(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x1e8),*(uint32_t /* width from decompiler */ *)(in_EAX + 0x1ec),1000000000,0);

    uVar4 = __allrem(uVar4,1000,0);

    sprintf(&stack0xffffffa8,"%d",(int)uVar4,(int)((ulonglong)uVar4 >> 0x20));

    (**(code **)(*(int *)param_1[0x154] + 0x1d8))(&stack0xffffffa8,1,1);

    (**(code **)(*(int *)param_1[0x158] + 0x1d8))(in_EAX + 0x1c2,1,0);

    (**(code **)(*(int *)param_1[0x159] + 0x1d8))();

    (**(code **)(*(int *)param_1[0x15a] + 0x1d8))(in_EAX + 0x32,1,0);

    if ((*(uint *)(in_EAX + 0x1f0) & *(uint *)(in_EAX + 500)) != 0xffffffff) {

      CVOGReaction_ResolveObjectTarget(1,*(uint *)(in_EAX + 0x1f0),*(uint *)(in_EAX + 500));

    }

    FUN_008b5a40();

    piVar1 = (int *)param_1[0x156];

    if (piVar1 != (int *)0x0) {

      if ((((param_1[0x144] & param_1[0x145]) == 0xffffffff) && (param_1[0x149] < 1)) &&

         ((param_1[0x149] < 0 || (param_1[0x148] == 0)))) {

        cVar2 = (**(code **)(*piVar1 + 0xd8))();

        if (cVar2 == '\x01') {

          (**(code **)(*(int *)param_1[0x156] + 0xd4))(0);

          (**(code **)(*(int *)param_1[0x156] + 0x34c))();

          (**(code **)(*param_1 + 0x34c))();

          return;

        }

      }

      else {

        cVar2 = (**(code **)(*piVar1 + 0xd8))();

        if (cVar2 == '\0') {

          (**(code **)(*(int *)param_1[0x156] + 0xd4))(1);

          (**(code **)(*(int *)param_1[0x156] + 0x34c))();

        }

      }

    }

    (**(code **)(*param_1 + 0x34c))();

  }

  return;

}
