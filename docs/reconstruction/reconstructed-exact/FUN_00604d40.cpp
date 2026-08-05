// =============================================================================
// FUN_00604d40  (superseded alias → CVOGHB_TargetingLink_ctor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00604d40
// Address:   0x00604d40  (autoassault.exe, image base 0x400000)
// System:    heartbeat / combat-target (targeting-link HB)
// Generated: 2026-07-29 dual A/B refresh (was 2026-07-23 scaffold)
// Canonical clean: CVOGHB_TargetingLink_ctor_Inferred.cpp
// Dual A/B:  reviews/A_aa_00604d40_CVOGHB_TargetingLink_ctor_Inferred.md
// =============================================================================

// PURPOSE: Shared targeting-link HB ctor — see CVOGHB_TargetingLink_ctor_Inferred.
// Scaffold name Named_CalleeOf_*DriveControlTick* rejected (only 2 xrefs:
// Object_SetSelectedTarget + FUN_00512090 PlayerTargetingLink wrapper).

extern "C" void __thiscall CVOGHBBase_ctor(void* thisHb);
extern "C" void __thiscall CVOGHBBase_AttachOwnerObject(void* thisHb, void* pOwner);
extern "C" void __thiscall CVOGHBBase_Start(void* thisHb);
extern "C" void* PTR_FUN_009cdfb0[];

void* __thiscall FUN_00604d40(void* thisHb, void* pOwner)
{
  CVOGHBBase_ctor(thisHb);
  *(void***)thisHb = PTR_FUN_009cdfb0;
  CVOGHBBase_AttachOwnerObject(thisHb, pOwner);
  *(int*)((char*)thisHb + 0x1C) = 2;       // nTypeTag
  *(int*)((char*)thisHb + 0x0C) = -1000;   // nPeriodSentinel
  *(int*)((char*)thisHb + 0x08) = 1000;    // nPeriodMs
  CVOGHBBase_Start(thisHb);
  return thisHb;
}
