// =============================================================================
// VehicleCrew_ContainsMember_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005749d0
// Address:   0x005749d0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities (crew roster; gather mode 0xb / filter residual)
// Generated: 2026-08-04 WQ9R-A dual (live Ghidra decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (no Launcher / not run).
// =============================================================================
//
// PURPOSE:
//   Return true if candidate object's COID lo/hi pair appears in this host's
//   4-slot crew table at +0x198 (stride 0x10). Used by skill gather/filter
//   mode 0xb ("same vehicle / plant crew") when vehicle+0xCB0 is the crew host,
//   and by Client_RecvDestroyObject / crew insert guard paths.
//
// ABI: __thiscall; ECX=crew host*; stack candidate*; RET 4; AL = 0/1.
// Body: 0x005749d0–0x00574a2e exclusive (94 B); leaf.
//
// Odd behavior preserved:
//   - Ghidra uint3/CONCAT31 noise dropped; real return is AL bool.
//   - Slot index advanced as byte (unsigned char) then compared > 3.
//
// Dual: reviews/A|B_aa_005749d0_VehicleCrew_ContainsMember_Inferred.md

#include <cstdint>

// Crew host (partial — only fields used by this unit):
//   +0x198  slot[4] of 0x10 bytes; dwords [0]/[1] = COID lo/hi
// Twin writer FUN_005755b0 also stores object* and bumps count at +0x1D8.

// __thiscall
extern "C" std::uint8_t __thiscall VehicleCrew_ContainsMember_Inferred(
    void* self,
    void* candidate)
{
  if (candidate == nullptr) {
    return 0;
  }

  int offBase = *reinterpret_cast<int*>(*reinterpret_cast<int*>(static_cast<char*>(candidate) + 4) + 4);
  int coidLo = *reinterpret_cast<int*>(offBase + 0x164 + reinterpret_cast<int>(candidate));
  int coidHi = *reinterpret_cast<int*>(offBase + 0x168 + reinterpret_cast<int>(candidate));

  unsigned slot = 0;
  for (;;) {
    int byteOff = static_cast<int>(slot * 0x10);
    if (coidLo == *reinterpret_cast<int*>(static_cast<char*>(self) + 0x198 + byteOff) &&
        coidHi == *reinterpret_cast<int*>(static_cast<char*>(self) + 0x19c + byteOff)) {
      return 1;
    }
    unsigned char next = static_cast<unsigned char>(static_cast<unsigned char>(slot) + 1);
    slot = next;
    if (next > 3) {
      return 0;
    }
  }
}

// Legacy symbol alias.
extern "C" std::uint8_t __thiscall FUN_005749d0(void* self, void* candidate)
{
  return VehicleCrew_ContainsMember_Inferred(self, candidate);
}
