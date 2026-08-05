// =============================================================================
// FUN_009071b0
// -----------------------------------------------------------------------------
// Stable ID: aa_009071b0
// Address:   0x009071b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009071b0 @ 0x009071b0
// Stable ID: aa_009071b0
// Embedded strings (evidence for future rename):
//   - "%I64d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: sprintf×4, __alldiv×3, __allmul×3, CONCAT44, FUN_009071b0.
//  - Strings: "%I64d".
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

void FUN_009071b0(int param_1,int param_2)



{

  char cVar1;

  int *in_EAX;

  uint32_t /* width from decompiler */ unaff_EBX;

  uint32_t /* width from decompiler */ unaff_EBP;

  uint32_t /* width from decompiler */ unaff_ESI;

  longlong lVar2;

  uint64_t uVar3;

  longlong lVar4;

  uint64_t uStack_108;

  char acStack_100 [256];

  

  cVar1 = (**(code **)(*in_EAX + 0x3d8))();

  if (cVar1 != '\0') {

    if ((param_2 < 1) && ((param_2 < 0 || (param_1 == 0)))) {

      param_1 = 1;

      param_2 = 0;

    }

    uStack_108 = __alldiv(param_1,param_2,1000000000,0);

    sprintf(acStack_100,"%I64d",(int)uStack_108,(int)((ulonglong)uStack_108 >> 0x20));

    (**(code **)(*(int *)in_EAX[0x193] + 0x3ac))(acStack_100);

    (**(code **)(*(int *)in_EAX[0x193] + 0x34c))();

    lVar2 = __allmul(unaff_EBX,(uint32_t /* width from decompiler */)uStack_108,0xc4653600,0xffffffff);

    lVar2 = lVar2 + CONCAT44(param_2,param_1);

    uVar3 = __alldiv(lVar2,1000000,0);

    uStack_108._0_4_ = (uint32_t /* width from decompiler */)((ulonglong)uVar3 >> 0x20);

    sprintf((char *)((int)&uStack_108 + 4),"%I64d",(int)uVar3,(uint32_t /* width from decompiler */)uStack_108);

    (**(code **)(*(int *)in_EAX[0x192] + 0x3ac))((int)&uStack_108 + 4);

    (**(code **)(*(int *)in_EAX[0x192] + 0x34c))();

    lVar4 = __allmul(unaff_EBP,(int)uVar3,0xfff0bdc0,0xffffffff);

    lVar2 = lVar2 + lVar4;

    uVar3 = __alldiv(lVar2,1000,0);

    sprintf((char *)&uStack_108,"%I64d",(int)uVar3,(int)((ulonglong)uVar3 >> 0x20));

    (**(code **)(*(int *)in_EAX[0x191] + 0x3ac))(&uStack_108);

    (**(code **)(*(int *)in_EAX[0x191] + 0x34c))();

    lVar4 = __allmul(unaff_ESI,(int)uVar3,1000,0);

    lVar2 = lVar2 - lVar4;

    sprintf(&stack0xfffffef4,"%I64d",(int)lVar2,(int)((ulonglong)lVar2 >> 0x20));

    (**(code **)(*(int *)in_EAX[400] + 0x3ac))(&stack0xfffffef4);

    (**(code **)(*(int *)in_EAX[400] + 0x34c))();

  }

  return;

}
