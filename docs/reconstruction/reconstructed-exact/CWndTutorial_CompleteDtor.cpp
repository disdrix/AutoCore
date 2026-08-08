// =============================================================================
// CWndTutorial_CompleteDtor  (aa_0097a8a0)
// -----------------------------------------------------------------------------
// Address:   0x0097a8a0 – 0x0097a8da inclusive (59 B / 0x3B)
//            autoassault.exe, image base 0x400000
// Wave:      WQ9J-C OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite from live decompile + full-body
//            read_memory + disassemble_function + RTTI COL.
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       ECX=this; SEH; ADD ESP,0x10; RET; does not free this
// RTTI:      .?AVCWndTutorial@@  (type_info @ 0x00affaa4)
// =============================================================================

#include <cstdint>

// Deep UI-window base complete (not dualed here). Large teardown of owned
// child widgets / lists at high host offsets.
extern "C" void __fastcall FUN_00792c20(void* self); // 0x00792c20

// Retail vtbl symbol (Ghidra) — CWndTutorial primary vtbl.
extern "C" void* PTR_FUN_00a6f61c;

// ECX = this. SEH. ADD ESP,0x10; RET. Complete dtor — does not free this.
extern "C" void __fastcall CWndTutorial_CompleteDtor(void* self)
{
  // SEH: push -1; push LAB_009b4587; link ExceptionList (omitted as runtime frame)
  *reinterpret_cast<void**>(self) = &PTR_FUN_00a6f61c;
  // EH state = 0xFFFFFFFF
  FUN_00792c20(self);
  // restore ExceptionList; ADD ESP,0x10; RET
}

// Scaffold / Ghidra alias
extern "C" void __fastcall FUN_0097a8a0(void* self)
{
  CWndTutorial_CompleteDtor(self);
}
