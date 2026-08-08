// =============================================================================
// SkillSet_Vector_UninitializedCopy_0x18_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0040a600
// Address:   0x0040a600–0x0040a664 inclusive (101 B / 0x65; autoassault.exe base 0x400000)
// System:    skills-abilities / STL SkillSet vector (NPCSkillSetEntry stride 0x18)
// Generated: 2026-08-05 MEGA-055 OWN dual A/B seal
// Exactness: Behavior-preserving rewrite of live bytes + call-site ABI.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Supersedes: FUN_0040a600.cpp scaffold;
//             Named_CalleeOf_Skill_Uses_SkillSet_GetEntryCount_0040a600.cpp (retired name).
// Dual: reviews/A|B_aa_0040a600_SkillSet_Vector_UninitializedCopy_0x18_Inferred.md
// Callers: FUN_00412730 (2 sites), FUN_00412a80 trampoline (1 site)
// Callee:  FUN_00412b10 (6-dword / 0x18 element copy; null-dest guard)
// Peers:   SkillSet_GetEntryCount (0x00402d80);
//          SkillSet_Vector_UninitializedFillN_0x18_Inferred (0x00406f00);
//          leaf twin SkillSet_UninitializedCopy_0x18 (0x00442b00) — different ABI/no SEH
// =============================================================================
//
// PURPOSE:
//   MSVC-style vector uninitialized_copy (_Ucopy) for 0x18-byte SkillSet entries.
//   Copy [src_first, src_end) into dest via per-element FUN_00412b10; return dest end.
//
// ABI (sealed — decompiler __thiscall is wrong):
//   cdecl RET (C3); callers ADD ESP, 0x10
//   ECX            = src_end (exclusive)
//   stack [ESP+4]  = src_first
//   stack [ESP+8]  = dest
//   stack +0xC/+0x10 pushed by all callers but unused by body (EH/vector residue)
//   EAX            = dest + n*0x18
// Bytes (epilogue): 8B C7 … 5F 5E 5B 8B E5 5D C3
// =============================================================================

#include <cstdint>

struct NPCSkillSetEntry {
  // 0x18 bytes — six dwords; field English open (copied wholesale by FUN_00412b10).
  unsigned char bytes[0x18];
};

// Leaf element construct/copy: if (dest) copy 6 dwords from src → dest. RET.
extern "C" void __fastcall SkillSetEntry_Copy6Dwords_Inferred(
    const NPCSkillSetEntry* src /*ECX*/,
    NPCSkillSetEntry* dest /*EAX*/);

// SEH frame (LAB_009bd090) omitted in clean plate; control flow preserved.

extern "C" NPCSkillSetEntry* SkillSet_Vector_UninitializedCopy_0x18_Inferred(
    NPCSkillSetEntry* src_end /*ECX*/,
    NPCSkillSetEntry* src_first /*stack*/,
    NPCSkillSetEntry* dest /*stack*/)
{
  // EH state = 0 while constructing
  for (; src_first != src_end; ++src_first) {
    SkillSetEntry_Copy6Dwords_Inferred(src_first, dest);
    ++dest; // +0x18
  }
  // EH state = -1; unlink FS:[0]
  return dest;
}
