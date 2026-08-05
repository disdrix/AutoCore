// =============================================================================
// FUN_0067c330
// -----------------------------------------------------------------------------
// Stable ID: aa_0067c330
// Address:   0x0067c330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067c330 @ 0x0067c330
// Stable ID: aa_0067c330
// Embedded strings (evidence for future rename):
//   - "Remote\'s newest-received timestamp (%hu) is more recent than current timestamp (%hu)"
//   - "C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: timestamp×2, FUN_0067c330, FUN_0076cec0, vog_LogMessage.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_0067c330(int param_1,uint32_t /* width from decompiler */ param_2,ushort param_3)



{

  ushort uVar1;

  float fVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  int iVar6;

  

  *(uint16_t *)(param_1 + 0x29ca) = (uint16_t)param_2;

  uVar1 = *(ushort *)(param_1 + 0x29c8);

  if ((uVar1 < param_3) || ((0xd0fc < uVar1 && (param_3 < 0x2ee1)))) {

    if ((param_3 < 0xd0fd) || (12000 < uVar1)) {

      uVar4 = FUN_0076cec0(&param_2,

                           "Remote\'s newest-received timestamp (%hu) is more recent than current timestamp (%hu)"

                           ,param_3,uVar1);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"

                     ,0x38e,3,uVar4);

      return;

    }

    uVar3 = ((uint)uVar1 - (uint)param_3) + 0x10000;

  }

  else {

    uVar3 = (uint)uVar1 - (uint)param_3;

  }

  uVar5 = *(int *)(param_1 + 0x29ec) * 7 + uVar3 >> 3;

  *(uint *)(param_1 + 0x29ec) = uVar5;

  if (uVar3 < uVar5) {

    iVar6 = uVar5 - uVar3;

  }

  else {

    iVar6 = uVar3 - uVar5;

  }

  uVar3 = (uint)(iVar6 + *(int *)(param_1 + 0x29f0) * 3) >> 2;

  *(uint *)(param_1 + 0x29f0) = uVar3;

  uVar5 = uVar5 + uVar3 * 4;

  if (uVar5 < 200) {

    uVar5 = 200;

  }

  fVar2 = (float)(int)uVar5;

  if ((int)uVar5 < 0) {

    fVar2 = fVar2 + _DAT_00aaa5dc;

  }

  *(double *)(param_1 + 0x29f8) = (double)(fVar2 * DAT_00a0f718);

  return;

}
