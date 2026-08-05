// =============================================================================
// FUN_00805460
// -----------------------------------------------------------------------------
// Stable ID: aa_00805460
// Address:   0x00805460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00805460 @ 0x00805460
// Stable ID: aa_00805460
// Embedded strings (evidence for future rename):
//   - "CLCDManager::Initialize(): failed to initialize graphics component.\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CLCDManager::Initialize, FUN_007a4480, FUN_00805460, FUN_00805900.
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

int __fastcall FUN_00805460(int *param_1)



{

  int iVar1;

  

  (**(code **)(*param_1 + 0xc))(0,0);

  (**(code **)(*param_1 + 0x18))(0xa0,0x2b);

  (**(code **)(*param_1 + 0x28))();

  (**(code **)(*param_1 + 0x24))();

  iVar1 = FUN_00805900();

  if (iVar1 < 0) {

    FUN_007a4480(0xffffffff,&DAT_00a2c2a4,

                 "CLCDManager::Initialize(): failed to initialize graphics component.\n");

    (**(code **)(*param_1 + 8))();

    return iVar1;

  }

  return 0;

}
