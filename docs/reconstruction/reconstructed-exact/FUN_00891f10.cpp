// =============================================================================
// FUN_00891f10
// -----------------------------------------------------------------------------
// Stable ID: aa_00891f10
// Address:   0x00891f10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00891f10 @ 0x00891f10
// Stable ID: aa_00891f10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_008904a0, FUN_00891480, FUN_00891f10, GetTickCount, ROUND.
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

void FUN_00891f10(int param_1,int param_2,int param_3,float param_4,int param_5,int param_6,

                 uint32_t /* width from decompiler */ param_7,int param_8)



{

  bool bVar1;

  char cVar2;

  int *in_EAX;

  DWORD DVar3;

  uint32_t /* width from decompiler */ unaff_retaddr;

  

  bVar1 = false;

  cVar2 = (**(code **)(*in_EAX + 0x3d8))();

  if ((cVar2 != '\0') && (in_EAX[0x16b] != 2)) {

    bVar1 = true;

  }

  in_EAX[0x16c] = param_1;

  in_EAX[0x16d] = param_2;

  in_EAX[0x16b] = 2;

  FUN_008904a0();

  in_EAX[0x169] = param_8;

  in_EAX[0x150] = param_3;

  in_EAX[0x14f] = (int)param_4;

  DVar3 = GetTickCount();

  in_EAX[0x168] = DVar3 - (int)ROUND(param_4 * (float)in_EAX[0x150] * DAT_00a0f520);

  in_EAX[0x14d] = param_5;

  in_EAX[0x14e] = param_6;

  if ((int *)in_EAX[0x14c] != (int *)0x0) {

    (**(code **)(*(int *)in_EAX[0x14c] + 0x15c))(1,in_EAX + 0x14d);

    (**(code **)(*(int *)in_EAX[0x14c] + 0x15c))(0,in_EAX + 0x14e);

    (**(code **)(*(int *)in_EAX[0x14c] + 0x3b0))(unaff_retaddr);

    (**(code **)(*(int *)in_EAX[0x14c] + 0x3ac))(0x3f800000);

    if ((float)in_EAX[0x150] == g_flZero) {

      (**(code **)(*(int *)in_EAX[0x14c] + 0x3b4))(0);

    }

    else {

      (**(code **)(*(int *)in_EAX[0x14c] + 0x3b4))(g_flOne / (float)in_EAX[0x150]);

    }

    (**(code **)(*(int *)in_EAX[0x14c] + 0x34c))();

  }

  if (bVar1) {

    FUN_00891480(in_EAX);

  }

  return;

}
