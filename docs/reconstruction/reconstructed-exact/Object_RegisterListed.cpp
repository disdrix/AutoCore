// =============================================================================
// Object_RegisterListed
// -----------------------------------------------------------------------------
// Stable ID: aa_004bc180
// Address:   0x004bc180  (autoassault.exe, image base 0x400000)
// Body:      0x004bc180 – 0x004bc41c
// System:    world object listing / mission notify hooks
// Dual:      W19-E 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   Register Object into a ListingContext (manager). Validates COID, enforces
//   manager mode flags, rejects duplicates ("already listed"), ensures a
//   CNDHash bucket by type/key, allocates listing handles via FUN_004bc680,
//   and optionally fires CVOGReaction_FailMissionNotify for special types /
//   flag paths.
//
//   String "VOG_DEBUG_STOP" is ONLY the log tag on the invalid-COID throw path.
//   Parent-seed name Mission_VOG_DEBUG_STOP is incomplete.
//
// ABI (machine):
//   int32_t __thiscall Object_RegisterListed(ListingContext* this, Object* obj);
//   ECX = this, stack arg0 = obj, epilogue ret 4.
//   Returns 0 on success or already-listed; throws HRESULT on hard errors.
// =============================================================================

#include <cstdint>

// External callees (Ghidra names retained where product English open)
extern "C" void FUN_007a4480(int level, const char* fmt, ...);
extern "C" void _CxxThrowException(void* pExceptionObject, void* pThrowInfo);
extern "C" int FUN_004e77d0(int coid_lo, int coid_hi, void* obj, int flag);
extern "C" void* CNDHash_LookupByKey(void* hash, unsigned key);
extern "C" void* operator_new(unsigned size);
extern "C" int FUN_004bcb40(); // bucket node ctor (thiscall residual)
extern "C" void FUN_004bd1d0(int typeKey, int node, int z);
extern "C" int FUN_004bc680(void* obj, int* outHandle);
extern "C" void CVOGReaction_FailMissionNotify(void* pObjPtr);
extern "C" char FUN_005130e0(int arg);
extern void* ExceptionList;
extern void* DAT_00acc430; // ThrowInfo for HRESULT

// ListingContext / Object layouts used by this unit only (partial)
// Object: +0xa8 meta*, +0xd0/+0xd4/+0xd8/+0xdc handles, +0x160/+0x164 COID,
//         +0x168 mode, +0x17c flags; vtbl +0x208, +0x1d4
// ListingContext: +0xc/+0xd mode flags, +0x18 CNDHash*

std::uint32_t __thiscall Object_RegisterListed(int param_1 /*ListingContext**/, int* param_2 /*Object*/)
{
  int* piVar1 = param_2;
  int iVar3 = param_2[0x59]; // COID hi @ +0x164
  // SEH frame omitted (LAB_009a174c)

  // Invalid COID → log tag + E_INVALIDARG
  if ((iVar3 < 1) && ((iVar3 < 0) || (param_2[0x58] == 0))) {
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    {
      std::uint32_t hr = 0x80070057u;
      _CxxThrowException(&hr, &DAT_00acc430);
    }
  }

  // Mode gate: object+0x168 selects manager +0xd vs +0xc
  if ((char)param_2[0x5a] == '\0') {
    if (*(char*)(param_1 + 0xd) == '\0') {
      std::uint32_t hr = 0x80070057u;
      _CxxThrowException(&hr, &DAT_00acc430);
    }
  } else if (*(char*)(param_1 + 0xc) == '\0') {
    std::uint32_t hr = 0x80070057u;
    _CxxThrowException(&hr, &DAT_00acc430);
  }

  // Already listed → soft fail
  iVar3 = FUN_004e77d0(param_2[0x58], iVar3, param_2, 0);
  if (iVar3 != 0) {
    FUN_007a4480(1, "object %I64d (%d) is already listed",
                 piVar1[0x58], piVar1[0x59],
                 *(std::uint32_t*)(piVar1[0x2a] + 0x34));
    return 0;
  }

  // Bucket key: force 0x30 if vtbl+0x208 nonzero, else type at meta+0x38
  iVar3 = (**(int(**)())(*piVar1 + 0x208))();
  unsigned key;
  if (iVar3 == 0) {
    key = *(unsigned*)(piVar1[0x2a] + 0x38);
  } else {
    key = 0x30u;
  }

  void* pvVar4 = CNDHash_LookupByKey(*(void**)(param_1 + 0x18), key);
  if (pvVar4 == nullptr) {
    pvVar4 = operator_new(0x2c);
    if ((pvVar4 == nullptr) || (iVar3 = FUN_004bcb40(), iVar3 == 0)) {
      std::uint32_t hr = 0x8007000Eu; // E_OUTOFMEMORY
      _CxxThrowException(&hr, &DAT_00acc430);
    }
    FUN_004bd1d0(*(std::uint32_t*)(piVar1[0x2a] + 0x38), iVar3, 0);
  }

  int handle = 0;
  FUN_004bc680(piVar1, &handle);
  piVar1[0x37] = handle; // +0xdc primary

  int type = *(int*)(piVar1[0x2a] + 0x38);
  if ((type == 0x12) ||
      ((type == 0xe &&
        (iVar3 = (**(int(**)())(*piVar1 + 0x1d4))(), iVar3 != 0)) &&
       (iVar3 = (**(int(**)())(*piVar1 + 0x1d4))(),
        *(char*)(iVar3 + 0x2ac) == '\0'))) {
    int hr = FUN_004bc680(piVar1, &handle);
    if (hr < 0) {
      _CxxThrowException(&hr, &DAT_00acc430);
    }
    piVar1[0x34] = handle; // +0xd0
    CVOGReaction_FailMissionNotify(&param_2);
  } else if (type != 0x14) {
    goto after_type_notify;
  } else {
    CVOGReaction_FailMissionNotify(&param_2);
  }

after_type_notify:
  if (FUN_005130e0(1) != '\0') {
    int hr = FUN_004bc680(piVar1, &handle);
    if (hr < 0) {
      _CxxThrowException(&hr, &DAT_00acc430);
    }
    piVar1[0x35] = handle; // +0xd4
  }

  if ((((unsigned)piVar1[0x5f] >> 5) & 1) != 0) { // +0x17c bit 5
    int hr = FUN_004bc680(piVar1, &handle);
    if (hr < 0) {
      _CxxThrowException(&hr, &DAT_00acc430);
    }
    piVar1[0x36] = handle; // +0xd8
    CVOGReaction_FailMissionNotify(&param_2);
  }

  return 0;
}
