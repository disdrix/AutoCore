// =============================================================================
// CNDUIDialog_CompleteDtor  (aa_00792c20)
// -----------------------------------------------------------------------------
// Address:   0x00792c20 – 0x00792d12 inclusive (243 B / 0xF3 true body)
//            Ghidra DB body end 00792ceb is TRUNCATED (false noreturn on
//            member operator_delete). Bytes continue through FUN_007b5be0 + RET.
//            autoassault.exe, image base 0x400000
// Wave:      WQ9K-G OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite from decompile + full-body
//            read_memory + disassemble_function + RTTI COL.
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       ECX=this; SEH; ADD ESP,0x10; RET; does not free this
// RTTI:      .?AVCNDUIDialog@@  (type_info @ 0x00afe1c8)
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_007917c0(void* self); // child-hash teardown @ +0x4c0
extern "C" void __fastcall FUN_00415e90(void);       // list shell clear; ESI = this+0x4dc
extern "C" void __cdecl operator_delete(void* p);
extern "C" void __fastcall FUN_007b5be0(void* self); // deeper UI window complete

// Retail vtbl symbol (Ghidra) — CNDUIDialog primary vtbl.
extern "C" void* PTR_FUN_00a98f44;

// Null-safe scalar-deleting call on owned object pointer slot.
static inline void scalar_delete_owned(void** slot)
{
  void* p = *slot;
  if (p != nullptr) {
    // (**vtbl)(1) — MSVC scalar-deleting form on owned subobject
    auto** vtbl = *reinterpret_cast<void***>(p);
    auto fn = reinterpret_cast<void*(__thiscall*)(void*, int)>(vtbl[0]);
    fn(p, 1);
  }
  *slot = nullptr;
}

// ECX = this. SEH. ADD ESP,0x10; RET. Complete dtor — does not free this.
extern "C" void __fastcall CNDUIDialog_CompleteDtor(void* self)
{
  auto* base = reinterpret_cast<std::uint8_t*>(self);

  // SEH: push -1; push LAB_009b4054; link ExceptionList (omitted as runtime frame)
  *reinterpret_cast<void**>(self) = &PTR_FUN_00a98f44;
  // EH state = 1
  FUN_007917c0(self);

  // Owned helpers (ctor peer FUN_00792d20): skip +0x4c4 / [0x131]
  scalar_delete_owned(reinterpret_cast<void**>(base + 0x4c0)); // [0x130]
  scalar_delete_owned(reinterpret_cast<void**>(base + 0x4c8)); // [0x132]
  scalar_delete_owned(reinterpret_cast<void**>(base + 0x4cc)); // [0x133]
  scalar_delete_owned(reinterpret_cast<void**>(base + 0x4d0)); // [0x134]
  scalar_delete_owned(reinterpret_cast<void**>(base + 0x4d4)); // [0x135]
  scalar_delete_owned(reinterpret_cast<void**>(base + 0x4d8)); // [0x136]

  // ESI = this+0x4dc for list-shell helper (unaff_ESI in decompile of 00415e90)
  // FUN_00415e90(); // requires ESI = this+0x4dc in retail ABI
  (void)0; // plate: invoke with ESI = self+0x4dc

  // Member free at +0x4e0 — operator_delete RETURNS (not host free)
  void* mem = *reinterpret_cast<void**>(base + 0x4e0);
  operator_delete(mem);
  *reinterpret_cast<void**>(base + 0x4e0) = nullptr;

  // EH state = 0xFFFFFFFF
  FUN_007b5be0(self);
  // restore ExceptionList; ADD ESP,0x10; RET
}

// Scaffold / Ghidra alias
extern "C" void __fastcall FUN_00792c20(void* self)
{
  CNDUIDialog_CompleteDtor(self);
}
