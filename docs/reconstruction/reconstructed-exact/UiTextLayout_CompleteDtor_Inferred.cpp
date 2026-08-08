// =============================================================================
// UiTextLayout_CompleteDtor_Inferred  (aa_00797d70)
// -----------------------------------------------------------------------------
// Address:   0x00797d70  (autoassault.exe, image base 0x400000)
// Body:      0x00797d70–0x00797e17 inclusive (168 B / 0xA8)
// Wave:      WQ9L-F OWN-ONLY dual 2026-08-05
// System:    UI owned text-layout block / complete destructor
// Exactness: Behavior-preserving rewrite from decompile + disassemble_function
//            + read_memory. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Complete destructor for a heap-owned text-layout object used by
//   CNDUIWindow at +0x28C (and many text-edit paths). Merges float metrics,
//   finalizes layout (FUN_00797530(1)), frees buffer vector @+0x94, tears
//   0x80-stride run vector @+0x80, destroys wstring @+0x0C.
//   Does NOT free the host block — callers pair with operator_delete.
//
// ABI:
//   __stdcall 1 arg (layout*). SEH LAB_009add5a. RET 4 (C2 04 00). void.
//
// PEERS:
//   CNDUIWindow_CompleteDtor free path: FUN_00797d70(p); operator_delete(p);
//   Layout finalize: FUN_00797530
//   Run-vector teardown: FUN_004271c0
// =============================================================================

#include <cstdint>

extern "C" void __cdecl FUN_00797530(char finalize_flag); // EBX=this convention
extern "C" void __cdecl FUN_004271c0(void);               // EBX=vector shell*
extern "C" void __cdecl operator_delete(void* p);
extern "C" void __thiscall basic_string_wchar_dtor(void* self);

// Complete dtor only — does not free self.
extern "C" void __stdcall UiTextLayout_CompleteDtor_Inferred(uint8_t* obj)
{
  // SEH: LAB_009add5a; ESI=obj; EH state = 2

  float* base = reinterpret_cast<float*>(obj + 0xA4);
  float* delta = reinterpret_cast<float*>(obj + 0xA8);
  *base = *base + *delta;
  *delta = 0.0f;

  // FUN_00797530 reads this via EBX; pass object in EBX at call site.
  // Reconstruct as: EBX=obj; FUN_00797530(1);
  // (helper uses unaff_EBX = layout*)
  {
    // Call with EBX = obj is machine ABI; portable sketch:
    //   mov ebx, obj; push 1; call FUN_00797530
    FUN_00797530(1);
  }

  void** vec94 = reinterpret_cast<void**>(obj + 0x94);
  if (vec94[0] != nullptr) {
    operator_delete(vec94[0]);
  }
  vec94[0] = nullptr;
  vec94[1] = nullptr;
  vec94[2] = nullptr;

  // EH state = 0
  // FUN_004271c0 uses EBX = obj+0x80 (vector of 0x80-stride elems)
  {
    // mov ebx, obj+0x80; call FUN_004271c0
    FUN_004271c0();
  }

  // EH = -1
  basic_string_wchar_dtor(obj + 0x0C);

  // SEH restore; RET 4
}

// Ghidra twin name
extern "C" void __stdcall FUN_00797d70(uint8_t* obj)
{
  UiTextLayout_CompleteDtor_Inferred(obj);
}
