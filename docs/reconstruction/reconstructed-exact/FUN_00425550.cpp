// =============================================================================
// FUN_00425550
// -----------------------------------------------------------------------------
// Stable ID: aa_00425550
// Address:   0x00425550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00425550 @ 0x00425550
// Stable ID: aa_00425550
// Embedded strings (evidence for future rename):
//   - "LogNetConnection"
//   - "NetConnection %s: START %s"
//   - "NetConnection %s: END %s - %d bits"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_00783aa0×2, FUN_00783b60×2, FUN_007845c0×2, FUN_00425550, FUN_00425890, FUN_00425f50, FUN_0042bc80, FUN_00783850.
//  - Strings: "LogNetConnection"; "NetConnection %s: START %s"; "NetConnection %s: END %s - %d bits".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00425550(int *param_1,int param_2)



{

  uint uVar1;

  int in_EAX;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  

  FUN_00425890(param_1,param_2);

  if (param_2 == 0) {

    iVar2 = (**(code **)(*param_1 + 0x44))();

    param_1[0x47] = param_1[0x47] + 1;

    if (param_1[0x48] == 0) {

      param_1[0x48] = iVar2;

    }

    else {

      *(int *)(param_1[0x49] + 0x10) = iVar2;

    }

    param_1[0x49] = iVar2;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x10) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 4) = *(uint32_t /* width from decompiler */ *)(param_1[0x6a] + 0x78);

    FUN_00425f50();

    uVar1 = _DAT_00d208c4 & 1;

    iVar2 = *(int *)(in_EAX + 0x18);

    *(int *)(in_EAX + 0x34) = param_1[0x73];

    if (uVar1 == 0) {

      _DAT_00d208c4 = _DAT_00d208c4 | 1;

      DAT_00d208c0 = FUN_00783b60("LogNetConnection");

    }

    if (*(char *)(DAT_00d208c0 + 4) != '\0') {

      DAT_00d179a0 = DAT_00d208c0;

      iVar3 = (**(code **)*param_1)();

      uVar4 = FUN_007845c0(*(uint32_t /* width from decompiler */ *)(iVar3 + 0x20));

      FUN_00783aa0("NetConnection %s: START %s",uVar4);

      DAT_00d179a0 = 0;

    }

    (**(code **)(*param_1 + 0x38))();

    if ((_DAT_00d208c4 & 2) == 0) {

      _DAT_00d208c4 = _DAT_00d208c4 | 2;

      DAT_00d208bc = FUN_00783b60("LogNetConnection");

    }

    if (*(char *)(DAT_00d208bc + 4) != '\0') {

      iVar3 = *(int *)(in_EAX + 0x18);

      DAT_00d179a0 = DAT_00d208bc;

      iVar5 = (**(code **)*param_1)();

      uVar4 = FUN_007845c0(*(uint32_t /* width from decompiler */ *)(iVar5 + 0x20),iVar3 - iVar2);

      FUN_00783aa0("NetConnection %s: END %s - %d bits",uVar4);

      DAT_00d179a0 = 0;

    }

  }

  if (param_1[0x6d] != 0) {

    FUN_00783850(param_1[0x25],param_1[0x23],param_2,0);

    FUN_0042bc80(5,param_1[0x6d]);

  }

  return;

}
