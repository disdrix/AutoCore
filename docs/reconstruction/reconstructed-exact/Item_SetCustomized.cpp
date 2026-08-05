// =============================================================================
// Item_SetCustomized  (FUN_00513e30)
// -----------------------------------------------------------------------------
// Stable ID: aa_00513e30
// Address:   0x00513e30  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 W19-H
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE: Set ItemFlag_Customized (item+0x17c bit 20 / mask 0x100000) to desired 0/1.
// Stable ID: aa_00513e30
//
// On change: FUN_00512670 marks dirty bit 0x20000 on self and +0xac chain.
// After write: returns (no vtbl tail — unlike Item_SetBroken).
//
// Dual: docs/reconstruction/reviews/A|B_aa_00513e30_Item_SetCustomized.md
//
// Related (not this unit):
//   - Dirty helper:      FUN_00512670 @ 0x00512670  (| 0x20000)
//   - Sibling Broken set: Item_SetBroken @ 0x00513de0  (mask 0x80000 + vtbl+0x90)
//   - Trade reject:       Client_UI_InventoryDropToGrid reads bit20
//   - Permanent customize Yes: Client_UiModalDispatch case 0x4e58 calls this(1)

// READABILITY:
//  - Body size: ~11 non-empty decompiler lines; ~0x34 bytes asm.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00512670.
//  - ABI: thiscall ECX=item, 1 stack arg, ret 4.

/*
 * Behavioral notes:
 * - Live Ghidra decompile + read_memory 2026-07-29 ≡ raw 2026-07-23.
 * - Compare uses full low byte of desired vs extracted bit {0,1}.
 * - Write keeps only bit0 of desired (<<20 then & 0x100000).
 * - Product label Customized: peer string + permanent-customize path (Probable/High).
 * - Runtime / differential verification: OPEN.
 */

#include <cstdint>

// Forward: item+0x17c |= 0x20000; walk *(item+0xac) same OR
extern "C" void __fastcall FUN_00512670(int item);

// item: CVOG cloned inventory object (ECX / this)
// desiredCustomized: 0 clear, non-zero typically 1 set (low byte)
void __thiscall Item_SetCustomized(int *item, std::uint32_t desiredCustomized)
{
  // Ghidra: FUN_00513e30
  int *self = item;
  const std::uint32_t desired_byte = desiredCustomized & 0xff;

  if ((((std::uint32_t)self[0x5f] >> 0x14) & 1u) != desired_byte) {
    FUN_00512670((int)self);
    // bytes keep ECX; decompiler extraout_ECX is artifact
    self = item;
  }

  // flags ^= (((desired_byte << 20) ^ flags) & 0x100000)
  self[0x5f] = (int)((std::uint32_t)self[0x5f] ^
                     (((desired_byte << 0x14) ^ (std::uint32_t)self[0x5f]) & 0x100000u));
  return;
}

// Compatibility alias (scaffold name)
void __thiscall FUN_00513e30(int *param_1, std::uint32_t param_2)
{
  Item_SetCustomized(param_1, param_2);
}
