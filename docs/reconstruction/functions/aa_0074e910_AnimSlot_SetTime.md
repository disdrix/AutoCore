# Function record: AnimSlot_SetTime

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074e910` |
| **Canonical name** | `AnimSlot_SetTime` |
| **Ghidra name** | `FUN_0074e910` |
| **Address** | `0x0074e910` |
| **Body range** | `0x0074e910`–`0x0074e9c2` (179 B; exclusive end `0x0074e9c3`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client visual / animation slot |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes + ABI sealed; product spelling residual |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0074e910_AnimSlot_SetTime.md`, `reviews/B_aa_0074e910_AnimSlot_SetTime.md` |
| **Last reviewed** | `2026-07-29` (W21-J) |

## Alias

- `FUN_0074e910` (Ghidra)
- `AnimClip_SetPlayhead` / `AnimSlot_Seek` (plausible product variants — **not sealed**)

## Purpose

**Set anim-slot playhead time and end/duration reference**, then recompute derived remaining at `+0x34`, clear `+0x50`/`+0x68`, mirror final time to `+0x6c`. Clamp or fmod-wrap based on mode byte `+0x4c`.

## Signature

```c
void __thiscall AnimSlot_SetTime(void* slot /* ECX */, float time, float endOrDuration);
// ret 8 — two float stack args
```

## Algorithm

1. `+0x44 = time`; `+0x40 = endOrDuration`.
2. If `+0x4c == 0`: clamp time to `[0, +0x48]`.
3. Else: `time = fmod(time, +0x48)`; if negative add `+0x48`.
4. `+0x34 = endOrDuration - time / (+0x3c)`.
5. `+0x50 = 0`; `+0x68 = 0`; `+0x6c = time`.

## Field map

| Off | Role |
|---|---|
| `+0x34` | derived remaining-ish: `param_3 - time/rate` |
| `+0x3c` | rate (ctor default `1.0`) |
| `+0x40` | end/duration ref (`param_3`) |
| `+0x44` | playhead (in/out) |
| `+0x48` | clip length (clamp max / fmod modulus) |
| `+0x4c` | mode: 0=clamp, nonzero=wrap |
| `+0x50` | forced 0 |
| `+0x68` | forced 0 |
| `+0x6c` | final time copy |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0074e910_FUN_0074e910.md`
- Annotated: `docs/reconstruction/raw/aa_0074e910_FUN_0074e910.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/AnimSlot_SetTime.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0074e910.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0074e910-0059d890-w21j-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `_CIfmod` (wrap path only); loads `g_flZero` @ `0x00a0f518` |
| **Callers** | 16 UNCONDITIONAL_CALL — includes `Object_LoadOrReplaceAnimSlot`, `AnimHost_SelectBlendSlot`, `FUN_004912c0`, `FUN_004930b0`, `FUN_004c50c0`/`5200`/`5350`, `FUN_00504d40`, `FUN_005232d0`, `FUN_0056a920`, `FUN_005866d0`, `FUN_005942d0`, `FUN_0073b7f0`, `FUN_009106d0`, +2 mid-body sites |

## Confidence

| Claim | Level |
|---|---|
| Body span / `ret 8` | **High** |
| thiscall + 2 float args | **High** |
| Clamp vs fmod mode at `+0x4c` | **High** |
| `+0x34 = param_3 - time/rate` | **High** |
| Zero `+0x50` / `+0x68`; copy `+0x6c` | **High** |
| Anim-slot `0x78` object context | **High** (ctor/load duals) |
| Product/PDB symbol spelling | Open |
| Runtime / bit-exact | Open |

## Related

- `FUN_0074ed90` — anim slot ctor (`0x78`; defaults wrap mode)
- `aa_005828b0` Object_LoadOrReplaceAnimSlot
- `aa_005816a0` AnimHost_SelectBlendSlot
