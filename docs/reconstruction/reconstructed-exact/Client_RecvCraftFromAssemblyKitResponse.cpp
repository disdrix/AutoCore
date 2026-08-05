// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: return×3, switch×1.
//  - Notable callees: FUN_007a6de0×2, Client_RecvCraftFromAssemblyKitResponse, FUN_0040c5c0, FUN_007a69d0, FUN_007fdfb0, strncpy.
//  - Strings: "Item Created!"; "Failed Crafting: Object not a kit."; "Failed Crafting: Invalid ingredient list."; "Experimentation Failed.".
//  - Return sites: 3.

// =============================================================================
// Client_RecvCraftFromAssemblyKitResponse
// -----------------------------------------------------------------------------
// Stable ID: aa_0080b640
// Address:   0x0080b640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

void Client_RecvCraftFromAssemblyKitResponse(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ unaff_ESI;

  char *pcVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  size_t _Count;

  uint32_t /* width from decompiler */ uVar5;

  char local_98 [128];

  uint32_t /* width from decompiler */ local_18;

  float local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  FUN_007a69d0();

  switch(*(uint32_t /* width from decompiler */ *)(param_1 + 4)) {

  case 0:

    _Count = 0x80;

    local_18 = 0xffffffff;

    local_98[0] = '\0';

    pcVar2 = (char *)FUN_007a6de0("Item Created!",0xffffffff);

    strncpy(local_98,pcVar2,_Count);

    local_14 = g_flLevelUpUiBase_Inferred;

    local_c = 0;

    local_10 = DAT_00aaa68c;

    local_18 = 0xffeee3d8;

    local_8 = 0xffffffff;

    local_4 = 0xffffffff;

    FUN_0040c5c0(local_98);

    return;

  case 1:

    pcVar2 = "Failed Crafting: Object not a kit.";

    break;

  case 2:

    pcVar2 = "Failed Crafting: Invalid ingredient list.";

    break;

  case 3:

    pcVar2 = "Experimentation Failed.";

    break;

  case 4:

    pcVar2 = "Not enough skill to attempt this.";

    break;

  case 5:

    pcVar2 = "You are not near a valid crafting station.";

    break;

  default:

    return;

  }

  uVar5 = 0;

  uVar4 = 1;

  uVar3 = 0xffffffff;

  uVar1 = FUN_007a6de0(pcVar2,0xffffffff);

  FUN_007fdfb0(unaff_ESI,uVar1,uVar3,uVar4,uVar5);

  return;

}
