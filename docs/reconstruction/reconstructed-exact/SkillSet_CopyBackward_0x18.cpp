// =============================================================================
// SkillSet_CopyBackward_0x18
// -----------------------------------------------------------------------------
// Stable ID: aa_00409ed0
// Address:   0x00409ed0–0x00409f0a inclusive (59 B / 0x3B; autoassault.exe base 0x400000)
// System:    skills-abilities / SkillSet vector (NPCSkillSetEntry stride 0x18)
// Generated: 2026-08-05 MEGA-054 OWN dual A/B seal
// Exactness: Behavior-preserving rewrite of live bytes + call-site ABI.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Supersedes: FUN_00409ed0.cpp scaffold;
//             Named_CalleeOf_Skill_Uses_SkillSet_GetEntryCount_00409ed0.cpp
// Dual: reviews/A|B_aa_00409ed0_SkillSet_CopyBackward_0x18.md
// Forward twin: SkillSet_UninitializedCopy_0x18 @ 0x00442b00 (dualed)
// Callers: FUN_00412730, FUN_00440f80, FUN_00442760, FUN_00454f30, FUN_0046bba0
// =============================================================================
//
// PURPOSE:
//   std::copy_backward-style reverse walk over a half-open [src_begin, src_end)
//   of 0x18-byte POD SkillSet entries into [dest_begin, dest_end).
//   Returns dest_begin (EAX after reverse walk). Empty range returns dest_end.
//
// ABI: EAX=dest_end, ECX=src_end, EDX=src_begin; RET 0 (no stack args).
// Bytes: 3B D1 74 36 53 56 57 83 E9 18 83 E8 18 3B CA ... 75 D0 5F 5E 5B C3
// Diff vs forward twin 00442b00: SUB not ADD; no null-dest skip.
// =============================================================================

#include <cstdint>

// 0x18-byte SkillSet entry — six dwords; field English open (copied wholesale).
struct NPCSkillSetEntry {
  std::uint32_t w0;
  std::uint32_t w1;
  std::uint32_t w2;
  std::uint32_t w3;
  std::uint32_t w4;
  std::uint32_t w5;
};

// Register triple is part of the sealed ABI (not portable C++ thiscall/cdecl).
// Clean plate documents the contract; implementation mirrors control flow.

extern "C" NPCSkillSetEntry *SkillSet_CopyBackward_0x18(
    NPCSkillSetEntry *dest_end_eax,
    NPCSkillSetEntry *src_end_ecx,
    NPCSkillSetEntry *src_begin_edx)
{
  if (src_begin_edx == src_end_ecx) {
    return dest_end_eax; // empty: dest_begin == dest_end
  }

  do {
    --src_end_ecx;
    --dest_end_eax;
    dest_end_eax->w0 = src_end_ecx->w0;
    dest_end_eax->w1 = src_end_ecx->w1;
    dest_end_eax->w2 = src_end_ecx->w2;
    dest_end_eax->w3 = src_end_ecx->w3;
    dest_end_eax->w4 = src_end_ecx->w4;
    dest_end_eax->w5 = src_end_ecx->w5;
  } while (src_end_ecx != src_begin_edx);

  return dest_end_eax; // dest_begin
}
