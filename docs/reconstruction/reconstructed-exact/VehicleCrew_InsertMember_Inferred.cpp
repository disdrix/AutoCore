// =============================================================================
// VehicleCrew_InsertMember_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005755b0
// Address:   0x005755b0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities (crew roster writer; gather mode 0xb residual)
// Generated: 2026-08-04 WQ9D-D dual (live Ghidra decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (no Launcher / not run).
// =============================================================================
//
// PURPOSE:
//   Insert member into this host's 4-slot crew table at +0x198 (stride 0x10) when:
//     - (u8 count@+0x1D8 + i32@+0x1E4) <= 3
//     - VehicleCrew_ContainsMember(member) is false
//     - a free slot exists (COID lo/hi both 0xFFFFFFFF; free test is (lo & hi) == ~0u)
//   On success: write COID pair, store object*, set member+0xCB0 = host,
//   append COID to vector at host+0x1F4, increment count, return 1.
//   If capacity gate passed but no free slot: VOG_DEBUG_STOP then return 0.
//
// Twin reader: VehicleCrew_ContainsMember_Inferred @ 0x005749d0
// Twin clear:  FUN_00574a90 (WQ9D-G)
//
// ABI: __thiscall; ECX=crew host*; stack member*; RET 4; AL = 0/1.
// Body: 0x005755b0–0x00575694 exclusive (228 B).
//
// Odd behavior preserved:
//   - Free sentinel is (lo & hi) == 0xFFFFFFFF (both FFs), not lo==0 && hi==0.
//   - Decompiler shows FUN_00520330(host); bytes use thiscall on *member*
//     with host as stack arg → member+0xCB0 = host.
//   - Zero direct CALL xrefs in Ghidra (orphan); CF still sealed from body.
//
// Dual: reviews/A|B_aa_005755b0_VehicleCrew_InsertMember_Inferred.md

#include <cstdint>

// Callees (not dualed here).
extern "C" std::uint8_t __thiscall VehicleCrew_ContainsMember_Inferred(
    void* self, void* candidate); // FUN_005749d0
extern "C" void __thiscall FUN_00520330(void* self, void* crew_host); // +0xCB0 store
extern "C" void __thiscall FUN_00418d70(void* vec, void* coid_pair); // append 8 B
extern "C" void FUN_007a4480(int a, const char* msg);

// Crew host (partial):
//   +0x198  slot[4] of 0x10: coidLo, coidHi, object*, ?
//   +0x1D8  u8 count
//   +0x1E4  i32 capacity bias
//   +0x1F4  vector of COID pairs

// __thiscall
extern "C" std::uint8_t __thiscall VehicleCrew_InsertMember_Inferred(
    void* self,
    void* member)
{
  auto* host = static_cast<std::uint8_t*>(self);
  auto* mem = static_cast<std::uint8_t*>(member);

  int capacity =
      static_cast<int>(host[0x1d8]) + *reinterpret_cast<int*>(host + 0x1e4);
  if (capacity > 3) {
    return 0;
  }

  if (VehicleCrew_ContainsMember_Inferred(self, member) != 0) {
    return 0;
  }

  for (int i = 0; i < 4; ++i) {
    auto* slot = reinterpret_cast<std::uint32_t*>(host + 0x198 + i * 0x10);
    if ((slot[0] & slot[1]) == 0xffffffffu) {
      int offBase =
          *reinterpret_cast<int*>(*reinterpret_cast<int*>(mem + 4) + 4);
      slot[0] = *reinterpret_cast<std::uint32_t*>(offBase + 0x164 +
                                                   reinterpret_cast<int>(mem));
      slot[1] = *reinterpret_cast<std::uint32_t*>(offBase + 0x168 +
                                                   reinterpret_cast<int>(mem));
      // object* at (i + 0x1A)*0x10 == +0x1A0 + i*0x10 == slot+8
      *reinterpret_cast<void**>(host + (i + 0x1a) * 0x10) = member;

      // Bytes: ECX=member, arg0=host → member+0xCB0 = host
      FUN_00520330(member, self);

      std::uint32_t coid[2];
      int off2 =
          *reinterpret_cast<int*>(*reinterpret_cast<int*>(mem + 4) + 4);
      coid[0] = *reinterpret_cast<std::uint32_t*>(off2 + 0x164 +
                                                   reinterpret_cast<int>(mem));
      coid[1] = *reinterpret_cast<std::uint32_t*>(off2 + 0x168 +
                                                   reinterpret_cast<int>(mem));
      // this = host+0x1F4
      FUN_00418d70(host + 0x1f4, coid);

      host[0x1d8] = static_cast<std::uint8_t>(host[0x1d8] + 1);
      return 1;
    }
  }

  FUN_007a4480(0, "VOG_DEBUG_STOP");
  return 0;
}

// Legacy symbol alias.
extern "C" std::uint8_t __thiscall FUN_005755b0(void* self, void* member)
{
  return VehicleCrew_InsertMember_Inferred(self, member);
}
