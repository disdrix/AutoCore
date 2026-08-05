# Function record: Snd_UpdateSounds_UpdateSoundRegions

| Field | Value |
|---|---|
| **Stable ID** | `aa_00727440` |
| **Canonical name** | `Snd_UpdateSounds_UpdateSoundRegions` |
| **Prior scaffold** | `FUN_00727440` |
| **Address** | `0x00727440`–`0x00727b45` exclusive (**1797** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client audio / CSoundManager |
| **Completion status** | **Dual A/B sealed** 2026-07-29 (W25-Q) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

| Name | Role |
|------|------|
| `FUN_00727440` | Ghidra / scaffold |
| `UpdateSounds::updateSoundRegions` | plate / profiler string |

## Purpose

Client **audio manager tick** for sound-region updates: gated dt accumulation, critical-section protected listener push, nested hard-kill/regions (`FUN_007252d0`), per-slot volume/spatialize/fade, optional re-arm, then leave CS.

## Signature (sealed)

```c
// stdcall: ret 0xC
void Snd_UpdateSounds_UpdateSoundRegions(int mgr /*CSoundManager**/, uint flag, float dt);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00727440_FUN_00727440.md` (+ 2026-07-29 live)
- Annotated: `docs/reconstruction/raw/aa_00727440_FUN_00727440.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Snd_UpdateSounds_UpdateSoundRegions.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00727440.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00727440_Snd_UpdateSounds_UpdateSoundRegions.md`
- Review B: `docs/reconstruction/reviews/B_aa_00727440_Snd_UpdateSounds_UpdateSoundRegions.md`
- Scaffold record: `docs/reconstruction/functions/aa_00727440_FUN_00727440.md`

## Callers / callees

| Direction | Target | Notes |
|-----------|--------|-------|
| Caller | `FUN_00938380` | sole UNCONDITIONAL_CALL |
| Nested dual | `FUN_007252d0` / `aa_007252d0` | hard-kill + regions |
| Profile | `FUN_00786a00` / `FUN_00786990` | enter/leave around plate string |
| Win32 | `EnterCriticalSection`, `LeaveCriticalSection`, `GetTickCount` | |
| Other | `FUN_007272f0`, `FUN_00724d70`, `FUN_00723290`, channel/volume helpers | see review |

## Confidence

| Claim | Level |
|---|---|
| CF gate + CS + slot walks | **High / Sealed** |
| stdcall ret 0xC / 3 args | **High / Sealed** |
| Plate string identity | **High** (`read_memory`) |
| Threshold 0.0005 double | **High** (`read_memory`) |
| Nested regions via 007252d0 | **High** |
| Full semantics of every nested helper | **Med / open** (not owned) |
| Product PDB exact spelling | **Probable** (plate-backed) |
