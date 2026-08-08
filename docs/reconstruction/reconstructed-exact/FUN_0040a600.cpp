// =============================================================================
// FUN_0040a600  (scaffold twin of SkillSet_Vector_UninitializedCopy_0x18_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040a600
// Address:   0x0040a600–0x0040a664 inclusive (101 B)
// System:    skills-abilities / STL SkillSet vector
// Generated: 2026-08-05 MEGA-055 — twin kept; prefer named clean plate
// Named:     reconstructed-exact/SkillSet_Vector_UninitializedCopy_0x18_Inferred.cpp
// Retired:   Named_CalleeOf_Skill_Uses_SkillSet_GetEntryCount_0040a600.cpp
// Exactness: Behavior-preserving; not modernization. Bit-for-bit: DEFERRED.
// =============================================================================

#include <cstdint>

// Callee FUN_00412b10: EAX=dest, ECX=src; copy 6 dwords if dest != null.
extern "C" void FUN_00412b10(void);

// Decompiler shape (Ghidra); real ABI is ECX=end + cdecl stack first/dest (see named plate).
extern "C" int __cdecl FUN_0040a600(int src_end_as_ecx_register_arg,
                                    int src_first,
                                    int dest)
{
  // SEH: PUSH -1; PUSH LAB_009bd090; FS:[0] link — omitted
  void* local_10;
  uint8_t* puStack_c;
  uint32_t local_8;

  (void)local_10;
  (void)puStack_c;
  (void)local_8;

  // Register ECX carries src_end on entry (Ghidra param_1).
  int src_end = src_end_as_ecx_register_arg;
  int cur = src_first;
  int out = dest;

  for (; cur != src_end; cur += 0x18) {
    // bytes: MOV ECX,ESI; MOV EAX,EDI; CALL FUN_00412b10
    FUN_00412b10();
    out += 0x18;
  }
  return out;
}
