// =============================================================================
// Class_009c7948_CompleteDtor  (aa_0040d890)
// -----------------------------------------------------------------------------
// Address:   0x0040d890 – 0x0040d8ca inclusive (59 B / 0x3B)
//            autoassault.exe, image base 0x400000
// Wave:      W32-C OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite from live decompile + full-body
//            read_memory. Derived complete: install PTR_FUN_009c7948 then
//            chain base StdTreeHost_PtrVal_CompleteDtor (0x0040d820).
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       ECX=this; SEH; ADD ESP,0x10; RET; does not free this
// =============================================================================

#include <cstdint>

// Base complete (W31-A). ECX=this; SEH; clear + FUN_0040d7c0(this+4).
extern "C" void __fastcall StdTreeHost_PtrVal_CompleteDtor(void* self); // 0x0040d820

// Retail vtbl symbol (Ghidra).
extern "C" void* PTR_FUN_009c7948;

// ECX = this. SEH. ADD ESP,0x10; RET. Complete dtor — does not free this.
extern "C" void __fastcall Class_009c7948_CompleteDtor(void* self)
{
  // SEH: push -1; push LAB_009be2d8; link ExceptionList (omitted as runtime frame)
  *reinterpret_cast<void**>(self) = &PTR_FUN_009c7948;
  // EH state = 0xFFFFFFFF
  StdTreeHost_PtrVal_CompleteDtor(self);
  // restore ExceptionList; ADD ESP,0x10; RET
}

// Scaffold / Ghidra alias
extern "C" void __fastcall FUN_0040d890(void* self)
{
  Class_009c7948_CompleteDtor(self);
}
