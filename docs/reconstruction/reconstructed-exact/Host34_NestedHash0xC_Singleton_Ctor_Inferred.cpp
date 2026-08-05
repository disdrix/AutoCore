// =============================================================================
// Host34_NestedHash0xC_Singleton_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0096eec0
// Address:   0x0096eec0 – 0x0096ef6a exclusive (170 B / 0xAA)
// Module:    autoassault.exe (image base 0x400000)
// Wave:      W35-S OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + byte-sealed map path.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Placement constructor for a 0x34-byte host that embeds NestedHash (sentinel
//   node 0x0C) at offset 0, publishes self to DAT_00d1f04c, once-inits a static
//   NDResource-style type-token object (DAT_00d1f7e4 / PTR_FUN_00a9ef54 + atexit),
//   and registers handler LAB_0096ed30 into the map at *DAT_00d1f050 + 0x58.
//
// ABI: stack(self*); RET 4; returns self in EAX. Not ECX-thiscall.
// SEH: LAB_009b1316
// Nested: NestedHash_Ctor_Sentinel0xC_Inferred (FUN_0043fdf0, W34-F)
//
// Reject scaffold name Named_CalleeOf_* (parent-seed chain only).
// =============================================================================

#include <cstdint>

// External sealed / unowned symbols (names structural where inferred).
extern "C" void* NestedHash_Ctor_Sentinel0xC_Inferred(void* self /*stack; RET 4*/);
extern "C" uint32_t* FUN_0043bd40(/* ECX=tree*, EAX=&key */);  // unowned map find/insert
extern "C" int _atexit(void (*fn)());
extern "C" void LAB_009c3370();   // static dtor thunk for DAT_00d1f7e4
extern "C" void LAB_0096ed30();   // registered handler (code site; not a Ghidra function)

extern "C" void* DAT_00d1f04c;           // singleton host*
extern "C" void* DAT_00d1f050;           // NDResourceCache* (global)
extern "C" uint32_t DAT_00d1f7e8;        // once-init guard bits
extern "C" void* DAT_00d1f7e4;           // static type-token object
extern "C" void* PTR_FUN_00a9ef54;       // vtbl for static type-token

struct Host34_NestedHash0xC {
  uint8_t  nested_hash[0x28];  // NestedHash_Sentinel0xC shell
  uint8_t  flag28;
  uint8_t  pad29[3];
  uint32_t field2c;
  uint32_t field30;
};
static_assert(sizeof(Host34_NestedHash0xC) == 0x34, "host size");

// stack(self*); RET 4
extern "C" Host34_NestedHash0xC* Host34_NestedHash0xC_Singleton_Ctor_Inferred(
    Host34_NestedHash0xC* self)
{
  DAT_00d1f04c = self;

  NestedHash_Ctor_Sentinel0xC_Inferred(self);

  self->flag28 = 1;
  self->field2c = 0;
  self->field30 = 0;

  if ((DAT_00d1f7e8 & 1u) == 0) {
    DAT_00d1f7e8 |= 1u;
    DAT_00d1f7e4 = &PTR_FUN_00a9ef54;
    _atexit(&LAB_009c3370);
  }

  // Bytes: EBP = *DAT_00d1f050; ECX = EBP+0x58; key dword on stack = 0x00d1f7e4
  uint32_t key = 0x00d1f7e4u;
  // FUN_0043bd40 is __fastcall-ish: ECX=tree, EAX=&key (see live decompile of 0043bd40)
  uint32_t* slot = FUN_0043bd40(/* tree = *(NDResourceCache*)+0x58, key=&key */);
  (void)key;
  slot[0] = reinterpret_cast<uint32_t>(&LAB_0096ed30);
  slot[1] = 0;

  return self;
}

// Ghidra twin name
extern "C" Host34_NestedHash0xC* FUN_0096eec0(Host34_NestedHash0xC* self)
{
  return Host34_NestedHash0xC_Singleton_Ctor_Inferred(self);
}
