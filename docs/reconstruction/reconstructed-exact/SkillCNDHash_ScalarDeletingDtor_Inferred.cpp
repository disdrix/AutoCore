// =============================================================================
// SkillCNDHash_ScalarDeletingDtor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0051de60
// Address:   0x0051de60–0x0051de7d inclusive (30 B / 0x1E)
//            autoassault.exe, image base 0x400000
// Wave:      2026-08-04 WQ9F-H OWN dual A/B seal
// Exactness: Behavior-preserving rewrite from live decompile + full-body
//            read_memory + disassemble_function. Epilogue sealed vs Ghidra
//            false-noreturn on operator_delete.
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       __thiscall; ECX=this; stack flags; RET 4; returns this*.
// Vtbl:      PTR_FUN_009ce1b8[0] @ DATA 0x009ce1b8
// Peer:      SkillCNDHash_Ctor_Inferred @ 0x0051dd60 (same vtbl install)
// Complete:  FUN_0051de80 (not OWN; HashError:Destructor string)
// =============================================================================

#include <cstdint>

// Complete object dtor: installs vtbl, checks traversal lock @+0x1d, destroys
// bucket table + nested state. Not dualled in WQ9F-H.
extern "C" void __thiscall SkillCNDHash_CompleteDtor_Inferred(void* self); // 0x0051de80
extern "C" void __cdecl operator_delete(void* p);

// MSVC scalar-deleting destructor for skill-family CNDHash (vtbl[0]).
// Always runs complete dtor; free heap host iff (flags & 1); return this.
extern "C" void* __thiscall SkillCNDHash_ScalarDeletingDtor_Inferred(void* self,
                                                                    uint8_t flags)
{
  // ESI = self (bytes: 56 8B F1)
  SkillCNDHash_CompleteDtor_Inferred(self);

  if ((flags & 1u) != 0u) {
    operator_delete(self);
  }

  return self; // RET 4 (C2 04 00)
}

// Scaffold twin entry (Ghidra name).
extern "C" void* __thiscall FUN_0051de60(void* self, uint8_t flags)
{
  return SkillCNDHash_ScalarDeletingDtor_Inferred(self, flags);
}
