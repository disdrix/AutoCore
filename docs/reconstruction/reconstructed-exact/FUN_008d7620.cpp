// =============================================================================
// FUN_008d7620
// -----------------------------------------------------------------------------
// Stable ID: aa_008d7620
// Address:   0x008d7620  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d7620 @ 0x008d7620
// Stable ID: aa_008d7620
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004c0380, FUN_008d7620.
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

void FUN_008d7620(uint32_t /* width from decompiler */ param_1)



{

  int in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_20 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x50c);

  local_1c = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x510);

  local_18 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x514);

  local_14 = 0;

  local_30 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x518);

  local_2c = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x51c);

  local_28 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x520);

  local_24 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x524);

  uVar6 = 0;

  uVar5 = 0;

  uVar4 = 1;

  puVar3 = &local_30;

  puVar2 = &local_20;

  uVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x544) + 4) + 4) + 4 +

                               *(int *)(in_EAX + 0x544)) + 0x1cc))(puVar2,puVar3,1,0,0,param_1);

  FUN_004c0380(uVar1,puVar2,puVar3,uVar4,uVar5,uVar6,param_1);

  return;

}
