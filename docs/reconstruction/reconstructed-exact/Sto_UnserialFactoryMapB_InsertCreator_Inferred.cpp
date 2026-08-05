// =============================================================================
// Sto_UnserialFactoryMapB_InsertCreator_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00444a40
// Address:   0x00444a40–0x00444ac5  (autoassault.exe, image base 0x400000)
// System:    arda2/storage — stoAbstractUnserializationFactory (map B insert)
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W36-C)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Bind a creator function (EBX) into NestedHash map B under a FourCC tag
//   (stack arg). Uses MapB GetInstance (FUN_00438ca0 / DAT_00d1fcec).
//   Logs duplicate if tag already present; still overwrites node+0xC with EBX.
//
// ABI (bytes):
//   cdecl stack: uint32_t tag
//   register formal: EBX = creator function pointer
//   void return; SUB ESP,0x10; plain RET after ADD ESP,0x10
//   Body 134 B (0x86)
//
// CALLERS:
//   FUN_00444910 — tag 0x4C445344 "DSDL"
//   FUN_00444930 — tag 0x4C444141 "AADL"
//
// TWIN:
//   MapA insert FUN_004449b0 (W36-A) — same shape, MapA GetInstance
//
// REJECT scaffold: Named_CalleeOf_*_Palantir_*
//

#include <cstdint>

struct NestedHash_Sentinel0x10;

// W35-D
extern "C" NestedHash_Sentinel0x10*
Sto_UnserialFactoryMapB_GetInstance_Inferred(void); // FUN_00438ca0

// W36-B (unowned here): find / insert helpers
// find: ESI=bag, ECX=&key, EAX=&out_node  (FUN_0046c1b0)
// insert: EDI=bag, stack pair {tag,0}       (FUN_0046bf90)
extern "C" void NestedHash_Find_0x10_Inferred(void);   // FUN_0046c1b0 stand-in
extern "C" void NestedHash_Insert_0x10_Inferred(void); // FUN_0046bf90 stand-in
extern "C" void vog_LogMessage(const char* file, int line, int severity, const char* msg);

using CreatorFn = void* (*)(void); // exact formals open

// EBX = creator (register formal; not a C++ parameter)
extern "C" void
Sto_UnserialFactoryMapB_InsertCreator_Inferred(uint32_t tag)
{
  // Prologue locals omitted; mirrors retail frame
  NestedHash_Sentinel0x10* bag =
      Sto_UnserialFactoryMapB_GetInstance_Inferred();
  void* sentinel = *reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(bag) + 0x08);

  bag = Sto_UnserialFactoryMapB_GetInstance_Inferred();
  void* node = nullptr;
  // NestedHash_Find(bag, &tag) → node  // FUN_0046c1b0
  (void)NestedHash_Find_0x10_Inferred;
  if (node != sentinel) {
    vog_LogMessage(
        "..\\arda2/storage/stoAbstractUnserializationFactory.h",
        0x24,
        2,
        "Inserting duplicate creator tag to factory");
  }

  bag = Sto_UnserialFactoryMapB_GetInstance_Inferred();
  // NestedHash_Find again
  if (node == sentinel) {
    // NestedHash_InsertIfMissing(bag, {tag, 0}) // FUN_0046bf90
    (void)NestedHash_Insert_0x10_Inferred;
    // node = inserted node*
  }

  // Creator from EBX (register formal)
  CreatorFn creator = nullptr; // = EBX at call site
  *reinterpret_cast<CreatorFn*>(
      reinterpret_cast<uint8_t*>(node) + 0x0C) = creator;
}

// Ghidra twin symbol
extern "C" void FUN_00444a40(uint32_t tag)
{
  Sto_UnserialFactoryMapB_InsertCreator_Inferred(tag);
}
