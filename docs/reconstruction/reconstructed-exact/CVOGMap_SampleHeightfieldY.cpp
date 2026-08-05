// =============================================================================
// CVOGMap_SampleHeightfieldY
// -----------------------------------------------------------------------------
// Stable ID: aa_004cd220
// Address:   0x004cd220  (autoassault.exe, image base 0x400000)
// System:    world-terrain
// Generated: 2026-07-23 scaffold; refined 2026-07-29 OWN-ONLY dual A/B
// Exactness: Behavior-preserving rewrite of decompiler + body CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   CVOGMap pure heightfield Y sample at world (x, z).
//   If map+0xe4e0 (heightfield*) is null → return 0.0f (g_flZero).
//   Else tail-call FUN_005a58c0 with this = heightfield and the same (x, z).
//   NOT CastTerrainHeight (no collision ray / filter / lerp).
//
// ABI (body + callers; decompiler tail-call may hide stack args):
//   __thiscall: ECX = CVOGMap*; stack float x, float z; RET 8; ST0 = Y.
//
// Notable callers:
//   Client_Input_DriveControlTick (~0x009236d2) — camera look ground Y
//   CVOGCreature_FindTerrainHeight — initial HF sample
//   Vehicle_ActivateEnterWorld — many other map/AI/UI sites
//
// Dual: reviews/A_aa_004cd220_CVOGMap_SampleHeightfieldY.md
//       reviews/B_aa_004cd220_CVOGMap_SampleHeightfieldY.md

// Forward: heightfield bilinear sample (this = HF object at map+0xe4e0).
// Product name open; dual not in this unit's OWN scope.
extern "C" long double __thiscall FUN_005a58c0(void* heightfield, float x, float z);

// g_flZero @ 0x00a0f518 — image bytes 00 00 00 00
extern "C" float g_flZero;

/*
 * Body (authoritative):
 *   004cd220  mov  ecx, [ecx+0xe4e0]
 *   004cd226  test ecx, ecx
 *   004cd228  jz   short return_zero
 *   004cd22a  jmp  FUN_005a58c0          ; ECX = hf; (x,z) on stack
 *   004cd22f  fld  dword ptr [g_flZero]
 *   004cd235  ret  8
 */

long double __thiscall CVOGMap_SampleHeightfieldY(void* map, float worldX, float worldZ)
{
  void* heightfield = *(void**)((char*)map + 0xe4e0);

  if (heightfield != 0) {
    // Tail-equivalent: return FUN_005a58c0(heightfield, worldX, worldZ);
    return FUN_005a58c0(heightfield, worldX, worldZ);
  }

  return (long double)g_flZero;
}

// Scaffold alias retained for xref continuity.
long double __thiscall FUN_004cd220(void* map, float worldX, float worldZ)
{
  return CVOGMap_SampleHeightfieldY(map, worldX, worldZ);
}
