// =============================================================================
// CMenuChatlog_CompleteDtor  (aa_008327f0)
// -----------------------------------------------------------------------------
// Address:   0x008327f0 – 0x0083282a inclusive (59 B / 0x3B)
//            autoassault.exe, image base 0x400000
// Wave:      WQ9J-C OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite from live decompile + full-body
//            read_memory + disassemble_function + RTTI COL.
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       ECX=this; SEH; ADD ESP,0x10; RET; does not free this
// RTTI:      .?AVCMenuChatlog@@  (type_info @ 0x00affb04)
// =============================================================================

#include <cstdint>

// Intermediate base complete (not dualed here). Installs PTR_FUN_00a72f6c,
// runs FUN_0082ce20, then chains FUN_00792c20 (deep UI base).
extern "C" void __fastcall FUN_0082d540(void* self); // 0x0082d540

// Retail vtbl symbol (Ghidra) — CMenuChatlog primary vtbl.
extern "C" void* PTR_FUN_00a70524;

// ECX = this. SEH. ADD ESP,0x10; RET. Complete dtor — does not free this.
extern "C" void __fastcall CMenuChatlog_CompleteDtor(void* self)
{
  // SEH: push -1; push LAB_009b453f; link ExceptionList (omitted as runtime frame)
  *reinterpret_cast<void**>(self) = &PTR_FUN_00a70524;
  // EH state = 0xFFFFFFFF
  FUN_0082d540(self);
  // restore ExceptionList; ADD ESP,0x10; RET
}

// Scaffold / Ghidra alias
extern "C" void __fastcall FUN_008327f0(void* self)
{
  CMenuChatlog_CompleteDtor(self);
}
