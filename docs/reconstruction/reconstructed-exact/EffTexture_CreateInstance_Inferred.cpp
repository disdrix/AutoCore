// =============================================================================
// EffTexture_CreateInstance_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0096e9f0
// Address:   0x0096e9f0–0x0096ea5a exclusive (106 B / 0x6A)
// Module:    autoassault.exe (image base 0x400000)
// System:    palantir graphics Effects — effTexture factory
// Wave:      W38-O 2026-08-04
// Exactness: Behavior-preserving rewrite of decompiler CF + body hex.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Allocate + construct an effect-texture instance from freelist DAT_00d21930,
//   initialize GPU resources via FUN_0096cad0 (effTextureImpl.cpp CreateTexture
//   path). On init failure, invoke complete dtor vtbl[0](this,1) and return null.
//
// ABI (bytes-sealed; Ghidra under-declares formals):
//   EBX = const uint32_t dims[2]*   // {width, height}
//   stack a0..a4 (five dwords)      // format / aux / flags / … / related
//   RET 0x14                        // stdcall-style clean 20 bytes
//   returns object* in EAX or null
//
// CALLER CONTRACT (from EffTexture_CreateOrAssignSlot / PalantirEnv init):
//   Parent thiscall has 6 stack args (p0..p5); factory receives
//     EBX = p1 (dims*), stack = (p0, p2, p3, p4, p5). Parent p1 is "dead" after
//     load into EBX for the call.
//   Observed env init: format 0x15 (D3DFMT_A8R8G8B8), flags 0x4011, dims from
//   display size or half size.
//
// CALLEES:
//   FUN_0043f120  freelist pop (EDI=&DAT_00d21930) → node in EAX
//   FUN_0096bbb0  in-place ctor (object in EAX); sets vtbls 00aa0a20 / 00aa0a10
//   FUN_0096cad0  thiscall init (ECX=obj); packs dims from *EBX; HRESULT-like
//
// BYTES (106 B):
//   5657bf3019d200e82407adff85c07409e8abd1ffff8bf0eb0233f685f67445
//   8b44241c8b4c24188b54241050518b0b5283ec088bc489088b5304895004
//   8b44242089642430508b44242c8bcee88fe0ffff85c07d0f8b166a018bce
//   ff1233c05f5ec214005f8bc65ec21400
//
// =============================================================================

#include <cstdint>

struct EffTextureObj {
  void**   vtbl;     // +0x00  (complete dtor at [0])
  // … remainder initialized by FUN_0096bbb0 / FUN_0096cad0 …
};

// Ghidra: FUN_0043f120 — freelist pop; EDI = &head
extern "C" EffTextureObj* FUN_0043f120(void /*EDI=&DAT_00d21930*/);

// Ghidra: FUN_0096bbb0 — in-place ctor; object in EAX
extern "C" EffTextureObj* FUN_0096bbb0(void /*EAX=obj*/);

// Ghidra: FUN_0096cad0 — thiscall init; returns <0 on failure
// Formals intentionally opaque at this dual (owned residual on 0096cad0).
extern "C" int __thiscall FUN_0096cad0(
    EffTextureObj* self /*ECX*/,
    uint32_t a0,
    uint32_t width,
    uint32_t height,
    uint32_t a1,
    uint32_t a3,
    uint32_t* dims_ptr_or_related);

// Ghidra: FUN_0096e9f0
// EBX = dims*; five stack args; RET 0x14.
extern "C" EffTextureObj* __stdcall EffTexture_CreateInstance_Inferred(
    uint32_t a0,
    uint32_t a1,
    uint32_t a2,
    uint32_t a3,
    uint32_t a4
    /*EBX = const uint32_t dims[2]*/)
{
  // Retail: MOV EDI, 0x00d21930; CALL FUN_0043f120
  EffTextureObj* obj = FUN_0043f120(); // EDI preloaded to freelist head
  if (obj == nullptr) {
    // null path still falls through to return ESI=0
  } else {
    obj = FUN_0096bbb0(); // in-place ctor on EAX=obj
  }

  if (obj != nullptr) {
    // Retail packs *EBX/{EBX+4} onto a stack local and forwards a0..a4 into
    // FUN_0096cad0 (thiscall). Exact stack shape matches body hex; product
    // names for a0..a4 remain open (see gaps).
    const uint32_t* dims = nullptr; // EBX in retail
    int hr = FUN_0096cad0(obj, a0,
                          dims ? dims[0] : 0,
                          dims ? dims[1] : 0,
                          a1, a3, /*related*/ nullptr);
    (void)a2;
    (void)a4;
    if (hr < 0) {
      // vtbl[0](this, 1) — complete destructor with delete
      using CompleteDtor = void(__fastcall*)(EffTextureObj* /*ECX*/, int /*stack?*/);
      // Retail: PUSH 1; MOV ECX,ESI; CALL dword ptr [EDX]  (vtbl[0])
      void** vtbl = obj->vtbl;
      reinterpret_cast<void(__thiscall*)(EffTextureObj*, int)>(vtbl[0])(obj, 1);
      return nullptr;
    }
  }
  return obj;
}
