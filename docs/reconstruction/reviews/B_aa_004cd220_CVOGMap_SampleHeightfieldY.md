# Review B (skeptical / adversarial): `aa_004cd220` CVOGMap_SampleHeightfieldY

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cd220` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual A/B — live Ghidra; body + xrefs) |
| **Counterpart** | `reviews/A_aa_004cd220_CVOGMap_SampleHeightfieldY.md` |
| **System** | `world-terrain` (not exclusive to input-drive-control) |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on gate/ABI/HF-sample role; **reject** overclaims that this is cast-terrain, DriveControlTick-only, a full physics Y query, or a finished bit-exact port |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Decompiler signature `__fastcall (int only)` is complete ABI | **Falsified** — body `RET 8` + callers pass **two floats** `(x,z)` |
| 2 | Non-null path is CALL then return of a nested result | **Falsified** — **tail JMP** to `FUN_005a58c0`; ECX rewritten to HF |
| 3 | This unit is `CVOGMap_CastTerrainHeight` | **Falsified** — cast is `0x004cfe60`; this unit has **no** cast, filter, lerp, or `+0xe4a4` |
| 4 | DriveControlTick-only / camera-only helper | **Falsified** — 57 xrefs; named callers include `CVOGCreature_FindTerrainHeight`, `Vehicle_ActivateEnterWorld`, many FUN_* |
| 5 | Null HF returns a miss sentinel / NaN / last Y | **Falsified** — hard `g_flZero` = **0.0f** |
| 6 | Samples height at world **Y** or full XYZ | **Falsified** — stack is **X and Z** only (FindTerrainHeight `*pos`, `pos[2]`) |
| 7 | Scaffold name `FUN_004cd220` / "unknown system" is final | **Superseded** — map HF sample role sealed; name **Probable** `CVOGMap_SampleHeightfieldY` |
| 8 | Ready for bit-exact seal of full package | **Fail** — runtime/diff open; `FUN_005a58c0` product name open |
| 9 | Equal to inlined HF sample inside CastTerrainHeight | **Related but not equal** — cast inlines null check + `FUN_005a58c0` then ray; this is the **shared pure sample gate** used elsewhere |
| 10 | Writes camera/entity fields | **Falsified** — pure function; DCT consumer writes host after return |

---

## 2. Decisive dataflow (raw ≡ live ≡ body)

```
// thiscall ECX = map (CVOGMap*)
// stack: float x, float z
// RET 8; return ST0

hf = *(map + 0xe4e0)
if hf == 0:
  return 0.0f                    // g_flZero @ 0x00a0f518
else:
  // ECX := hf; jump FUN_005a58c0(x, z)  // tail; no epilogue in this unit
  return FUN_005a58c0_Y
```

Live re-decompile (2026-07-29) matches 2026-07-23 raw CF. ABI corrected from body bytes + call-site inventory.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Null HF → 0.0 | **High** | Wrong ground snap / camera Y when HF unloaded |
| Tail to HF sample with (x,z) | **High** | Wrong ECX / clobbered stack |
| RET 8 / two float args | **High** | Stack imbalance / wrong coords |
| Not cast / not wheel ray | **High** | Port to wrong collision path |
| Map layout `+0xe4e0` | **High** | Same sealed slot as castTerrain plate |
| Exact product method name | **Probable** | Rename churn only |
| `FUN_005a58c0` bilinear details | **High structure; product open** | Scale/grid wrong if ported from memory only |
| Runtime golden | **Open** | Residual parity |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `map+0xe4e0` as HF | Invented? | **No** — body load; matches `fn_004cfe60` |
| `g_flZero` address | Guess? | **No** — body `D9 05 18 F5 A0 00`; mem `00 00 00 00` |
| Tail target `0x005a58c0` | Wrong jmp? | **No** — `E9` rel32 resolves to `005a58c0` |
| RET 8 | Decompiler void? | **Body wins** over incomplete decompiler sig |
| Hidden cast inside | Tail only? | **No cast** in 24-byte body |
| DCT exclusive | Callers? | **No** — FindTerrainHeight + dozens more |

---

## 5. Surviving contract for AutoCore

```
// CVOGMap_SampleHeightfieldY (Probable name)
float SampleHeightfieldY(CVOGMap* map, float worldX, float worldZ):
  hf = map->heightfield   // +0xe4e0
  if hf == null:
    return 0.0f
  return Heightfield_SampleY(hf, worldX, worldZ)   // FUN_005a58c0

// Do NOT:
//  - substitute CastTerrainHeight (physics refine) unless caller needs it
//  - invent (x,y,z) three-arg form
//  - treat as player-input exclusive
// Pair with CVOGMap_CastTerrainHeight / creature FindTerrainHeight when ray refine required
```

**DriveControlTick:** uses return as ground Y for look-projection after thr/HB push — consumer math remains on `aa_009223b0`.

---

## 6. Open questions

1. Product / PDB symbol string for `0x004cd220`.
2. Dual / name for `FUN_005a58c0` (HF sample kernel).
3. Live null-HF frequency during sector load / transition.
4. Whether server-side terrain snap uses an equivalent pure HF sample.

**Verdict:** **accept-with-gaps**
