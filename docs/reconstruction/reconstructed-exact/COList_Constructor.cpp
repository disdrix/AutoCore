// =============================================================================
// COList_Constructor
// -----------------------------------------------------------------------------
// Stable ID: aa_004bbfb0
// Address:   0x004bbfb0–0x004bc17f  (464 B / 0x1D0, autoassault.exe base 0x400000)
// System:    client / COList (cloned-object list host)
// Generated: 2026-07-29 W27-L dual A/B (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + entry/exit/vtbl bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_004bbfb0
// =============================================================================
//
// PURPOSE:
//   Construct a COList host (sizeof 0x58). Installs vtbl PTR_FUN_009cb448,
//   clamps capacity args, optionally builds two CNDHash-like tables via
//   FUN_004bcf90, always builds a third table via FUN_004bce90(5), and
//   allocates three 0x2C single-CS list objects (final vtbl PTR_FUN_009cb378).
//
// ABI:
//   __thiscall; ECX=this; stack (int capA, int capB); ret 8; returns this*.
//   Entry: 6A FF 68 42 17 9A 00 … C7 06 48 B4 9C 00
//   Exit:  83 C4 10 C2 08 00
//
// CALLER:
//   Client_InitInstance FUN_0094a6a0 @ 0x0094a7eb:
//     operator_new(0x58); FUN_004bbfb0(5,10); DAT_00b04830 = this; client+0xD34.
//
// TWINS:
//   FUN_004bbc70  — COList_Destructor (body)
//   FUN_004bd1b0  — COList_ScalarDeletingDestructor (vtbl[0])
// =============================================================================

#include <cstdint>
#include <windows.h>

extern "C" void* operator_new(uint32_t size);
extern "C" uint32_t* __thiscall FUN_004bcf90(uint32_t* self, uint8_t bit_size);
extern "C" uint32_t* __thiscall FUN_004bce90(uint32_t* self, uint8_t bit_size);

extern void* PTR_FUN_009cb448;
extern void* PTR_FUN_009cb334;
extern void* PTR_FUN_009cb378;

// Partial COList host layout (ctor-written fields).
struct COList {
  void* vtbl;                 // +0x00 PTR_FUN_009cb448
  void* hashA;                // +0x04  FUN_004bcf90 / null
  void* hashB;                // +0x08  FUN_004bcf90 / null
  uint8_t hasHashA;           // +0x0C
  uint8_t hasHashB;           // +0x0D
  uint8_t flag_0e;            // +0x0E
  uint8_t pad_0f;             // +0x0F
  int32_t capA;               // +0x10
  int32_t capB;               // +0x14
  void* tableC;               // +0x18  FUN_004bce90(5)
  void* list0;                // +0x1C  0x2C CS-list
  void* list1;                // +0x20
  void* list2;                // +0x24
  // +0x28..+0x57 buffer triples / reserved (zeroed in groups)
  uint32_t rest[(0x58 - 0x28) / 4];
};

static uint32_t* construct_hash_bcf90(int bit_size)
{
  void* mem = operator_new(0x34);
  if (mem == nullptr) {
    return nullptr;
  }
  return FUN_004bcf90(static_cast<uint32_t*>(mem), static_cast<uint8_t>(bit_size));
}

static uint32_t* construct_hash_bce90(int bit_size)
{
  void* mem = operator_new(0x34);
  if (mem == nullptr) {
    return nullptr;
  }
  return FUN_004bce90(static_cast<uint32_t*>(mem), static_cast<uint8_t>(bit_size));
}

// 0x2C object: interim vtbl 009cb334 → zero fields → ICS(+4) → final vtbl 009cb378.
static uint32_t* construct_cs_list_0x2c()
{
  uint32_t* obj = static_cast<uint32_t*>(operator_new(0x2C));
  if (obj == nullptr) {
    return nullptr;
  }
  obj[0] = reinterpret_cast<uint32_t>(&PTR_FUN_009cb334);
  obj[8] = 0;
  obj[7] = 0;
  obj[9] = 0;
  *reinterpret_cast<uint8_t*>(obj + 10) = 0;
  InitializeCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(obj + 1));
  obj[0] = reinterpret_cast<uint32_t>(&PTR_FUN_009cb378);
  return obj;
}

// Machine: undefined4* __thiscall FUN_004bbfb0(undefined4* this, int capA, int capB)
extern "C" COList* __thiscall COList_Constructor(COList* self, int capA, int capB)
{
  // SEH frame omitted (LAB_009a1742); construction-state tracking matches image.

  self->vtbl = &PTR_FUN_009cb448;

  // Zero buffer-triple bases written by the image (dword indices 0xB/C/D, 0xF/10/11, 0x13/14/15).
  uint32_t* dwords = reinterpret_cast<uint32_t*>(self);
  dwords[0x0B] = 0;
  dwords[0x0C] = 0;
  dwords[0x0D] = 0;
  dwords[0x0F] = 0;
  dwords[0x10] = 0;
  dwords[0x11] = 0;
  dwords[0x13] = 0;
  dwords[0x14] = 0;
  dwords[0x15] = 0;

  if (capA < 0) {
    capA = 0;
  }
  if (capB < 0) {
    capB = 0;
  }

  self->capA = capA;
  self->capB = capB;
  self->hasHashA = static_cast<uint8_t>(capA != 0);
  self->hasHashB = static_cast<uint8_t>(capB != 0);

  if (capA != 0) {
    self->hashA = construct_hash_bcf90(capA);
  } else {
    self->hashA = nullptr;
  }

  if (self->hasHashB == 0) {
    self->hashB = nullptr;
  } else {
    self->hashB = construct_hash_bcf90(capB);
  }

  self->tableC = construct_hash_bce90(5);

  self->list0 = construct_cs_list_0x2c();
  self->list1 = construct_cs_list_0x2c();
  self->list2 = construct_cs_list_0x2c();

  self->flag_0e = 0;
  return self;
}

extern "C" COList* __thiscall FUN_004bbfb0(COList* param_1, int param_2, int param_3)
{
  return COList_Constructor(param_1, param_2, param_3);
}
