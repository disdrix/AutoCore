// =============================================================================
// Item_SetBroken  (FUN_00513de0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00513de0
// Address:   0x00513de0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE: Set ItemFlag_Broken (item+0x17c bit 19 / mask 0x80000) to desired 0/1.
// Stable ID: aa_00513de0
//
// On change: FUN_00512670 marks dirty bit 0x20000 on self and +0xac chain.
// After write: if Broken is set, tail-jumps vtable+0x90 with stack arg 0.
//
// Dual: docs/reconstruction/reviews/A|B_aa_00513de0_Item_SetBroken.md
//
// Related (not this unit):
//   - Dirty helper:     FUN_00512670 @ 0x00512670  (| 0x20000)
//   - Sibling bit20 set: FUN_00513e30 @ 0x00513e30  (mask 0x100000)
//   - Stack eligibility: Item_IsStackEligible @ 0x00513e70 (reads bit19)

// READABILITY:
//  - Body size: ~16 non-empty decompiler lines; ~0x4d bytes asm.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00512670; indirect vtbl+0x90 (tail).
//  - ABI: thiscall ECX=item, 1 stack arg, ret 4.

/*
 * Behavioral notes:
 * - Live Ghidra decompile + read_memory 2026-07-29 ≡ raw 2026-07-23.
 * - Compare uses full low byte of desired vs extracted bit {0,1}.
 * - Write keeps only bit0 of desired (<<19 then & 0x80000).
 * - Runtime / differential verification: OPEN.
 */

#include <cstdint>

// Forward: item+0x17c |= 0x20000; walk *(item+0xac) same OR
extern "C" void __fastcall FUN_00512670(int item);

// item: CVOG cloned inventory object (ECX / this)
// desiredBroken: 0 clear, non-zero typically 1 set (low byte)
void __thiscall Item_SetBroken(int *item, std::uint32_t desiredBroken)
{
  // Ghidra: FUN_00513de0
  int *self = item;
  const std::uint32_t desired_byte = desiredBroken & 0xff;

  if ((((std::uint32_t)self[0x5f] >> 0x13) & 1u) != desired_byte) {
    FUN_00512670((int)self);
    // bytes keep ECX; decompiler extraout_ECX is artifact
    self = item;
  }

  // flags ^= (((desired_byte << 19) ^ flags) & 0x80000)
  self[0x5f] = (int)((std::uint32_t)self[0x5f] ^
                     (((desired_byte << 0x13) ^ (std::uint32_t)self[0x5f]) & 0x80000u));

  // post-write: byte at +0x17e bit3 == dword bit19
  if ((*(std::uint8_t *)((int)self + 0x17e) & 8) != 0) {
    // tail: stack arg forced 0; jmp [vtbl+0x90]
    (**(void (**)(void))(*self + 0x90))();
    return;
  }
  return;
}

// Compatibility alias (scaffold name)
void __thiscall FUN_00513de0(int *param_1, std::uint32_t param_2)
{
  Item_SetBroken(param_1, param_2);
}
