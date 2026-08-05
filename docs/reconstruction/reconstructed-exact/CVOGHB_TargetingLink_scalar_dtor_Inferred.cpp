// =============================================================================
// CVOGHB_TargetingLink_scalar_dtor_Inferred  (was FUN_00512070)
// -----------------------------------------------------------------------------
// Stable ID: aa_00512070
// Address:   0x00512070 – 0x0051208d  (autoassault.exe, image base 0x400000)
// System:    heartbeat / combat-target (targeting-link HB)
// Generated: 2026-07-29 W19-G OWN dual A/B seal
//            three-rep: raw 2026-07-23 ≡ live decompile ≡ read_memory
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte-sealed ABI.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Class:     CVOGHB_TargetingLink family (Inferred; vtbl PTR_FUN_009cdfb0)
// Vtbl:      slot 0 @ DATA 0x009cdfb0
// =============================================================================

// PURPOSE
// MSVC scalar-deleting destructor for base targeting-link heartbeat:
//   1) FUN_00512060 — complete dtor (restore vtbl 009cdfb0 + FUN_00508390 detach)
//   2) if (flags & 1): operator_delete(this)
//   3) return this
// Virtual dispatch only (no CODE xrefs). Derived twin: 0x0051b870
// (CVOGHBPlayerTargetingLink_scalar_dtor) uses same complete-dtor body.

#include <cstdint>

extern void __fastcall FUN_00512060(void* thisHb /* ECX */);
extern void operator_delete(void* p);

void* __thiscall CVOGHB_TargetingLink_scalar_dtor_Inferred(
    void* thisHb /* ECX */,
    uint8_t flags /* stack+4 */)
{
  // push esi; mov esi, ecx
  FUN_00512060(thisHb);

  if ((flags & 1) != 0) {
    // push esi; call operator_delete; add esp, 4
    operator_delete(thisHb);
  }

  // mov eax, esi; pop esi; ret 4
  return thisHb;
}

// Ghidra alias
extern "C" void* __thiscall FUN_00512070(void* param_1, uint8_t param_2)
{
  return CVOGHB_TargetingLink_scalar_dtor_Inferred(param_1, param_2);
}
