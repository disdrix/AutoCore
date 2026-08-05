// =============================================================================
// Mission_EnsureRegionMissions  (FUN_0053fff0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0053fff0
// Address:   0x0053fff0  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-23 scaffold; sealed 2026-07-29 wave3 (+0xf18 wrapper)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (static Ghidra seal only).
// Dual A/B:  reviews/A_aa_0053fff0_Mission_EnsureRegionMissions.md
//            reviews/B_aa_0053fff0_Mission_EnsureRegionMissions.md
// =============================================================================

// PURPOSE:
//   Lazy-ensure CVOGRegionMissions (VOGRegionMissions.cpp) at owner+0xf18 and
//   return that wrapper*. First call: operator_new(0x10) + FUN_0060b870 ctor
//   (four hashes + populate from WAD vector DAT_00b0434c or DB load path).
//   Callers that need mission-id lookup must use hash = *wrapper.
//
// SIGNATURE:
//   void* __fastcall Mission_EnsureRegionMissions(void* owner);  // ECX = owner
//
// WRAPPER @ +0xf18 (size 0x10):
//   +0x0  primary mission-id CNDHash*   (FUN_0053b0b0(8))
//   +0x4  objective-side CNDHash*       (FUN_0053b1b0(8))
//   +0x8  extended hash 0x38            (vtbl PTR_FUN_009df688)
//   +0xC  extended hash 0x38
//
// TYPICAL ECX: DAT_00b041fc; dialog path *(clientCtx+0xd30).
// SIBLING: FUN_0053ff80 = void ensure (same slot; optional FUN_0056e4e0).

// Declared but not defined here:
void* operator_new(unsigned int size);
void* __fastcall FUN_0060b870(void* self); // Mission_VOGRegionMissions ctor
extern void* ExceptionList;
extern unsigned char LAB_009a3f90[];

void* __fastcall Mission_EnsureRegionMissions(void* owner)
{
  void* pvVar1;
  void* uVar2;
  void* local_c;
  unsigned char* puStack_8;
  unsigned int local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a3f90[0];
  local_c = ExceptionList;
  if (*(int*)((char*)owner + 0xf18) == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x10);
    local_4 = 0;
    if (pvVar1 == 0) {
      uVar2 = 0;
    } else {
      uVar2 = FUN_0060b870(pvVar1);
    }
    *(void**)((char*)owner + 0xf18) = uVar2;
  }
  ExceptionList = local_c;
  return *(void**)((char*)owner + 0xf18);
}
