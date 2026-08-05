// =============================================================================
// FUN_004294f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004294f0
// Address:   0x004294f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004294f0 @ 0x004294f0
// Stable ID: aa_004294f0
// Embedded strings (evidence for future rename):
//   - "VOG_DEBUG_STOP"
//   - "List Error!  TraversalLock Call Stack:\n%s\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, for×1.
//  - Notable callees: FUN_007a4480×2, EnterCriticalSection, FUN_004294f0, FUN_0076d8b0, FUN_0076d9d0, FUN_0076dae0.
//  - Strings: "VOG_DEBUG_STOP"; "List Error!  TraversalLock Call Stack:\n%s\n".
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void __fastcall FUN_004294f0(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint8_t local_1058 [80];

  uint16_t local_1008;

  uint32_t /* width from decompiler */ local_1006 [1022];

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0x429500;

  if (*(char *)(param_1 + 0x28) != '\0') {

    FUN_007a4480(0,"VOG_DEBUG_STOP");

    local_1008 = 0;

    puVar4 = local_1006;

    for (iVar3 = 0x3ff; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    *(uint16_t *)puVar4 = 0;

    uVar1 = FUN_0076dae0();

    if (DAT_00d0dfb0 != 0) {

      uVar2 = FUN_0076d9d0(uVar1,1,local_1058,0x14);

      FUN_0076d8b0(uVar1,uVar2,local_1058,&local_1008,0xfff);

    }

    FUN_007a4480(1,"List Error!  TraversalLock Call Stack:\n%s\n",&local_1008);

    return;

  }

  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));

  *(uint8_t *)(param_1 + 0x28) = 1;

  return;

}
