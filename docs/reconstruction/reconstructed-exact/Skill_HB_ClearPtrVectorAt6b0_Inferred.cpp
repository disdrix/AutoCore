// =============================================================================
// Skill_HB_ClearPtrVectorAt6b0_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00578ac0
// Address:   0x00578ac0 – 0x00578b28 inclusive (0x69 B / 105)
// Module:    autoassault.exe (image base 0x400000)
// System:    skills-abilities / skill HB OnEnd teardown helper
// Generated: 2026-08-05 MEGA-014 dual (decompile + disassemble_function +
//            read_memory + callers/xrefs + call-site context)
// Exactness: Behavior-preserving rewrite. Assembly corrects decompiler
//            noreturn / missing zero-stores after buffer free.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   Destroy the skill-HB-owned pointer vector at this+0x6b0..+0x6b8:
//     for each non-null element → NDSpecialFX_TeardownCore then operator_delete;
//     free the array buffer if non-null; always zero begin/end/capacity.
//   Sole retail caller: Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred
//   (FUN_00578ce0) immediately after target resolve.
//
// ABI:
//   __thiscall; ECX = skill HB this; no stack args; plain RET.
//
// Dual: reviews/A|B_aa_00578ac0_Skill_HB_ClearPtrVectorAt6b0_Inferred.md
// =============================================================================

#include <cstdint>

// Dualed: docs/reconstruction/reviews/A_aa_004b99c0_NDSpecialFX_TeardownCore_Inferred.md
extern "C" void __fastcall NDSpecialFX_TeardownCore_Inferred(void* fx /* ECX */);

// CRT IAT @ 0x00489822 → [0x009c6694]; cdecl; returns (ADD ESP,4 at call sites).
extern "C" void __cdecl operator_delete(void* p);

// Layout (skill HB subclass — absolute offsets):
//   +0x6b0  void** begin   (T* array)
//   +0x6b4  void** end
//   +0x6b8  void** capacity_end
// Element type: owned NDSpecialFX* (teardown via dualed 0x004b99c0).

void __fastcall Skill_HB_ClearPtrVectorAt6b0_Inferred(void* hb /* ECX */)
{
  auto* base = reinterpret_cast<std::uint8_t*>(hb);

  auto** it  = *reinterpret_cast<void***>(base + 0x6b0);
  auto** end = *reinterpret_cast<void***>(base + 0x6b4);

  for (; it != end; ++it) {
    void* p = *it;
    if (p != nullptr) {
      NDSpecialFX_TeardownCore_Inferred(p);
      operator_delete(p);
    }
  }

  void* buf = *reinterpret_cast<void**>(base + 0x6b0);
  if (buf != nullptr)
    operator_delete(buf);

  // Always — decompiler drops this path after non-null buffer free.
  *reinterpret_cast<void**>(base + 0x6b0) = nullptr;
  *reinterpret_cast<void**>(base + 0x6b4) = nullptr;
  *reinterpret_cast<void**>(base + 0x6b8) = nullptr;
}
