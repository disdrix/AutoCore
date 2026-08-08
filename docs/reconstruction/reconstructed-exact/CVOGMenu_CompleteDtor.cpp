// =============================================================================
// CVOGMenu_CompleteDtor  (aa_0082d540)
// -----------------------------------------------------------------------------
// Address:   0x0082d540 – 0x0082d58e inclusive (79 B / 0x4F)
//            autoassault.exe, image base 0x400000
// Wave:      WQ9K-G OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite from live decompile + full-body
//            read_memory + disassemble_function + RTTI COL.
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       ECX=this; SEH; ADD ESP,0x10; RET; does not free this
// RTTI:      .?AVCVOGMenu@@  (type_info @ 0x00afe39c)
// =============================================================================

#include <cstdint>

// Menu-owned hash/map teardown at dword [0x14d] (not dualed here).
extern "C" void __fastcall FUN_0082ce20(void* self); // 0x0082ce20

// Shared UI base complete — CNDUIDialog (dualed WQ9K-G as aa_00792c20).
extern "C" void __fastcall FUN_00792c20(void* self); // 0x00792c20
// alias: CNDUIDialog_CompleteDtor

// Retail vtbl symbol (Ghidra) — CVOGMenu primary vtbl.
extern "C" void* PTR_FUN_00a72f6c;

// ECX = this. SEH. ADD ESP,0x10; RET. Complete dtor — does not free this.
extern "C" void __fastcall CVOGMenu_CompleteDtor(void* self)
{
  // SEH: push -1; push LAB_009b4443; link ExceptionList (omitted as runtime frame)
  *reinterpret_cast<void**>(self) = &PTR_FUN_00a72f6c;
  // EH state = 0
  FUN_0082ce20(self);
  // EH state = 0xFFFFFFFF
  FUN_00792c20(self); // CNDUIDialog_CompleteDtor
  // restore ExceptionList; ADD ESP,0x10; RET
}

// Scaffold / Ghidra alias
extern "C" void __fastcall FUN_0082d540(void* self)
{
  CVOGMenu_CompleteDtor(self);
}
