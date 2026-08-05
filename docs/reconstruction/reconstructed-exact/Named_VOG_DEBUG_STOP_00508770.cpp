// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, for×1.
//  - Notable callees: FUN_007a4480×2, EnterCriticalSection, FUN_00508770, FUN_0076dae0, FUN_0076db40.
//  - Strings: "VOG_DEBUG_STOP"; "List Error!  TraversalLock Call Stack:\n%s\n".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_00508770
// -----------------------------------------------------------------------------
// Stable ID: aa_00508770
// Address:   0x00508770  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void __fastcall Named_VOG_DEBUG_STOP_00508770(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint16_t *puVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint16_t local_1008;

  uint32_t /* width from decompiler */ local_1006 [1022];

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0x508780;

  if (*(char *)(param_1 + 0x28) != '\0') {

    FUN_007a4480(0,"VOG_DEBUG_STOP");

    local_1008 = 0;

    puVar2 = local_1006;

    for (iVar1 = 0x3ff; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    uVar7 = 0;

    *(uint16_t *)puVar2 = 0;

    uVar6 = 0xfff;

    puVar5 = &local_1008;

    uVar4 = 0x14;

    uVar3 = 0;

    FUN_0076dae0(0,0x14,puVar5,0xfff,0);

    FUN_0076db40(uVar3,uVar4,puVar5,uVar6,uVar7);

    FUN_007a4480(1,"List Error!  TraversalLock Call Stack:\n%s\n",&local_1008);

    return;

  }

  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));

  *(uint8_t *)(param_1 + 0x28) = 1;

  return;

}
