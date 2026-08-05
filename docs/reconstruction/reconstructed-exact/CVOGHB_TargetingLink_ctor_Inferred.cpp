// =============================================================================
// CVOGHB_TargetingLink_ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00604d40
// Address:   0x00604d40–0x00604dab  (autoassault.exe, image base 0x400000)
// System:    heartbeat / combat-target (targeting-link HB)
// Generated: 2026-07-29 dual A/B (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler + machine CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual A/B:  reviews/A_aa_00604d40_CVOGHB_TargetingLink_ctor_Inferred.md
//            reviews/B_aa_00604d40_CVOGHB_TargetingLink_ctor_Inferred.md
// =============================================================================
//
// PURPOSE
//   Shared ctor for targeting-link heartbeat objects (size 0x28):
//     CVOGHBBase_ctor → vtbl 0x009cdfb0 → AttachOwner(owner)
//     → nTypeTag=2 → nPeriodSentinel=-1000 → nPeriodMs=1000 → Start
//   Target-side (Object_SetSelectedTarget) keeps vtbl 009cdfb0.
//   Self-side wrapper FUN_00512090 calls this then sets vtbl 009cdfd4
//   (CVOGHBPlayerTargetingLink family). No alloc / Enqueue / partner link here.
//
// ABI (machine-sealed)
//   __thiscall; ECX = thisHb; stack = pOwner; RET 4; returns thisHb in EAX.
//
// SEALED CONSTANTS
//   PTR_FUN_009cdfb0, type tag 2, period ms 1000, period sentinel -1000.
// =============================================================================

// Layout offsets (CVOGHBBase — sealed on aa_00508200 dual):
//   +0x00 pVTable
//   +0x08 nPeriodMs          (TryFire pulse)
//   +0x0C nPeriodSentinel    (SetPeriod / Reschedule)
//   +0x18 pOwnerObject
//   +0x1C nTypeTag           (Ghidra: nUnusedOrFlags)
//   +0x21 fDormant

extern "C" void __thiscall CVOGHBBase_ctor(void* thisHb);
extern "C" void __thiscall CVOGHBBase_AttachOwnerObject(void* thisHb, void* pOwner);
extern "C" void __thiscall CVOGHBBase_Start(void* thisHb);

// Family vtbl for targeting-link base (not PlayerTargetingLink RTTI).
extern "C" void* PTR_FUN_009cdfb0[];

void* /*CVOGHBBase**/ __thiscall CVOGHB_TargetingLink_ctor_Inferred(
    void* thisHb,
    void* pOwner)
{
  // SEH frame present in retail (LAB_009a8018); omitted in clean plate body.

  CVOGHBBase_ctor(thisHb);

  *(void***)thisHb = PTR_FUN_009cdfb0;                 // +0x00

  CVOGHBBase_AttachOwnerObject(thisHb, pOwner);        // +0x18 + list mgr

  *(int*)((char*)thisHb + 0x1C) = 2;                   // nTypeTag
  *(int*)((char*)thisHb + 0x0C) = -1000;               // nPeriodSentinel
  *(int*)((char*)thisHb + 0x08) = 1000;                // nPeriodMs (1 s)

  CVOGHBBase_Start(thisHb);                            // clear dormant + OnStart

  return thisHb;
}
