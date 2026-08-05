// =============================================================================
// Class_00aa05cc_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0074d750
// Address:   0x0074d750–0x0074d7ad  (94 B / 0x5E; autoassault.exe base 0x400000)
// System:    class host with dual NestedHash bags (vtbl PTR_FUN_00aa05cc)
// Generated: 2026-07-23 scaffold as FUN_0074d750; dual A/B seal 2026-07-29 (W35-C)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   ECX thiscall ctor for a 0x5C host: install vtbl PTR_FUN_00aa05cc, zero
//   head fields, placement-construct NestedHashBag at +0x0c and NestedHash
//   (sentinel 0x14) at +0x34. Callers always allocate with operator_new(0x5c).
//
// ABI:
//   ECX = this; no stack formals; bare RET; returns this in EAX.
//   Nested bag ctors are stack-self* / RET 4 (W34-D / W34-E).
//
// REJECT: scaffold Named_CalleeOf_* product aliases.
//

#include <cstdint>

// Sealed duals (W34)
extern "C" void* NestedHashBag_Ctor_Inferred(void* self /* stack; RET 4 */);
extern "C" void* NestedHash_Ctor_Sentinel0x14_Inferred(void* self /* stack; RET 4 */);

// Retail vtbl symbol (Ghidra)
extern "C" void* PTR_FUN_00aa05cc[];

// Nested bag spans are 0x28 each (head unwritten by bag ctors; sentinel@+8, size@+c,
// 9-bucket shell@+10, flags@+20/+24). See W34-D / W34-E.
struct NestedHashBag0x28 {
  uint32_t head00;      // +0x00 unwritten by bag ctor
  uint32_t head04;      // +0x04 unwritten by bag ctor
  void* sentinel;       // +0x08
  uint32_t size;        // +0x0c
  uint8_t shell[0x10];  // +0x10 PtrVecShell
  uint32_t flag20;      // +0x20
  uint32_t flag24;      // +0x24
};

using NestedHash0x28 = NestedHashBag0x28; // same shell layout; different sentinel factory

struct Class_00aa05cc {
  void** vtbl;                 // +0x00
  uint32_t field04;            // +0x04
  uint32_t field08;            // +0x08
  NestedHashBag0x28 bag0c;    // +0x0c .. +0x33
  NestedHash0x28 bag34;        // +0x34 .. +0x5b
}; // sizeof == 0x5C

static_assert(sizeof(Class_00aa05cc) == 0x5C, "host size must match operator_new(0x5c)");

extern "C" Class_00aa05cc* __fastcall Class_00aa05cc_Ctor_Inferred(Class_00aa05cc* self)
{
  // SEH LAB_009acbbf omitted (frame only)
  self->vtbl = reinterpret_cast<void**>(&PTR_FUN_00aa05cc);
  self->field04 = 0;
  self->field08 = 0; // retail: XORPS + MOVSS store (4 B zero)
  NestedHashBag_Ctor_Inferred(&self->bag0c);
  NestedHash_Ctor_Sentinel0x14_Inferred(&self->bag34);
  return self;
}

// Ghidra twin symbol
extern "C" Class_00aa05cc* __fastcall FUN_0074d750(Class_00aa05cc* self)
{
  return Class_00aa05cc_Ctor_Inferred(self);
}
