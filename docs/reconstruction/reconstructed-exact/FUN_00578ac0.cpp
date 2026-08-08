// =============================================================================
// FUN_00578ac0  (scaffold twin of Skill_HB_ClearPtrVectorAt6b0_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00578ac0
// Address:   0x00578ac0 – 0x00578b28 inclusive (0x69 B)
// Module:    autoassault.exe (image base 0x400000)
// System:    skills-abilities
// Generated: 2026-08-05 MEGA-014 (assembly-corrected; Ghidra symbol retained)
// Exactness: Behavior-preserving. Prefer named clean source for ports.
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_004b99c0(void* elem /* ECX */);
extern "C" void __cdecl operator_delete(void* p);

// Ghidra symbol retained for xref continuity. Meaningful name:
//   Skill_HB_ClearPtrVectorAt6b0_Inferred
void __fastcall FUN_00578ac0(void* param_1 /* ECX = skill HB this */)
{
  auto* base = reinterpret_cast<std::uint8_t*>(param_1);

  auto** puVar2 = *reinterpret_cast<void***>(base + 0x6b0);
  auto** end    = *reinterpret_cast<void***>(base + 0x6b4);

  if (puVar2 != end) {
    do {
      void* pvVar1 = *puVar2;
      if (pvVar1 != nullptr) {
        FUN_004b99c0(pvVar1);
        operator_delete(pvVar1);
      }
      puVar2 = puVar2 + 1;
    } while (puVar2 != *reinterpret_cast<void***>(base + 0x6b4));
  }

  void* buf = *reinterpret_cast<void**>(base + 0x6b0);
  if (buf != nullptr)
    operator_delete(buf);

  *reinterpret_cast<std::uint32_t*>(base + 0x6b0) = 0;
  *reinterpret_cast<std::uint32_t*>(base + 0x6b4) = 0;
  *reinterpret_cast<std::uint32_t*>(base + 0x6b8) = 0;
}
