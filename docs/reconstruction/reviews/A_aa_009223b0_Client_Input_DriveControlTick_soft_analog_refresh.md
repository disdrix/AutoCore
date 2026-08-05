# Review A refresh: DriveControlTick soft-steer / analog (2026-07-29)

| Field | Value |
|---|---|
| **Stable ID** | `aa_009223b0` |
| **Counterpart** | B soft/analog refresh |
| **Verdict** | **accept-with-gaps** (soft CF High; UF-006 **bind label polarity residual open**) |
| **This residual pass** | 2026-07-29 — **ActionMap label polarity only** (no body re-open; no camera dual rewrite) |

## Soft-steer body (SECTION 7) — sealed High (do not re-open)

| Priority | ActionMap DAT (body load) | SetSteerInput immediate | f32 | Plate label (WI-MOV-001) |
|----------|---------------------------|-------------------------|-----|--------------------------|
| 1 hard-R | `DAT_00d1bcc2` | `0xbf800000` | −1.0 | Hard R |
| 2 hard-L | `DAT_00d1bc8e` | `0x3f800000` | +1.0 | Hard L |
| 3 soft (plate SoftL) | `DAT_00d1bd2a` | `0xbf000000` | **−0.5** | SoftL |
| 4 soft (plate SoftR) | `DAT_00d1bcf6` | `0x3f000000` | **+0.5** | SoftR |
| 5 clear | none + no analog | `0` | 0 | — |

All axis writes gated `vehicle+0x101==0`. Clean ≡ raw for order and immediates (**High**). Image push sites: soft −0.5 @ `0x00922c48`, soft +0.5 @ `0x00922cf8`.

## Analog (SECTION 3) — out of this residual scope

`DAT_00d1b618` present+active samples channels → may call SetLongitudinal/SetSteer or camera offsets. CF documented; bind calibration **runtime open**. Not re-opened here.

---

## UF-006 residual — ActionMap label polarity only (BIND)

### What is sealed vs open

| Item | Status | Notes |
|------|--------|-------|
| Soft/hard body magnitudes ±0.5 / ±1.0 | **Sealed High** | Decompile + image push; **do not re-open / flip** |
| Exclusive priority hard-R → hard-L → soft(`d1bd2a`) → soft(`d1bcf6`) → clear | **Sealed High** | Body CF |
| Display string literals exist | **Sealed High** | Image `read_memory` 2026-07-29 (below) |
| Display names written into ActionMap slots | **Sealed High** | `Client_InitActionDisplayNames` `0x007f7570` stores |
| Display name ↔ held DAT identity | **Probable** | Stride arithmetic from Accel baseline (below) — not runtime hold |
| Plate SoftL/SoftR vs product UI L/R | **Open residual** | Two competing label stories; **no invented fix** |
| Physical soft = hard direction under player key | **Open** | Needs runtime bind hold (Launcher/CE) |

### Bind-name evidence (strings / data)

| Evidence | VA / field | Content | Confidence |
|----------|------------|---------|------------|
| String image | `0x00a853f4` (`s_Steer_Left_00a853f4`) | `"Steer Left"` | **High** (`read_memory`) |
| String image | `0x00a853e8` (`s_Steer_Right_00a853e8`) | `"Steer Right"` | **High** |
| String image | `0x00a853d8` (`s_Steer_Left_Soft_00a853d8`) | `"Steer Left Soft"` | **High** |
| String image | `0x00a853c4` (`s_Steer_Right_Soft_00a853c4`) | `"Steer Right Soft"` | **High** |
| Display store | ActionMap `+0x2e5` | copies Steer Left | **High** (clean InitActionDisplayNames SECTION 3) |
| Display store | ActionMap `+0x319` | copies Steer Right | **High** |
| Display store | ActionMap `+0x34d` | copies **Steer Left Soft** | **High** |
| Display store | ActionMap `+0x381` | copies **Steer Right Soft** | **High** |
| Slot stride | `0x34` between drive name fields | Accel…Brake consecutive | **High** |

### Name-offset → held-DAT arithmetic (Probable link)

Baseline used elsewhere (PollBoundActions / plate): **Accelerate** display `ActionMap+0x27d` ↔ held `DAT_00d1bc26`.  
Rule under test: `held_DAT = 0x00d1bc26 + (name_off − 0x27d)` (same stride as ActionMap slots).

| Display name (InitActionDisplayNames) | Name off | Δ off | Inferred held DAT | Body SetSteer / thr | Matches plate hard/brake? |
|---------------------------------------|---------:|------:|-------------------|---------------------|---------------------------|
| Accelerate | `+0x27d` | 0 | `DAT_00d1bc26` | thr −1 | Yes (baseline) |
| Reverse | `+0x2b1` | `0x34` | `DAT_00d1bc5a` | thr +1 | Yes |
| Steer Left | `+0x2e5` | `0x68` | `DAT_00d1bc8e` | steer **+1.0** | Yes (Hard L) |
| Steer Right | `+0x319` | `0x9c` | `DAT_00d1bcc2` | steer **−1.0** | Yes (Hard R) |
| **Steer Left Soft** | `+0x34d` | `0xd0` | **`DAT_00d1bcf6`** | steer **+0.5** | **≠ plate SoftR name** |
| **Steer Right Soft** | `+0x381` | `0x104` | **`DAT_00d1bd2a`** | steer **−0.5** | **≠ plate SoftL name** |
| Brake | `+0x3b5` | `0x138` | `DAT_00d1bd5e` | HB 1 | Yes |

Cross-check (non-drive): Activate name `+0x4b9` → `DAT_00d1be62` under same rule (documented in PollBoundActions interact map) — same Δ identity.

### Two label stories (document both; invent neither)

**Story A — WI-MOV plate SoftL/SoftR (historical dual tables):**

| Plate label | DAT | Body f32 | Sign vs hard counterpart if SoftL=HardL |
|-------------|-----|---------:|----------------------------------------|
| SoftL | `d1bd2a` | −0.5 | **Opposes** Hard L (+1) |
| SoftR | `d1bcf6` | +0.5 | **Opposes** Hard R (−1) |

→ Soft band **sign-inverted** vs hard **if** plate SoftL/SoftR mean physical left/right.

**Story B — UI display-name order via stride arithmetic (this residual):**

| UI string | Inferred DAT | Body f32 | Sign vs hard Steer Left/Right |
|-----------|--------------|---------:|-------------------------------|
| Steer Left Soft | `d1bcf6` | **+0.5** | **Same sign** as Hard L (+1) |
| Steer Right Soft | `d1bd2a` | **−0.5** | **Same sign** as Hard R (−1) |

→ Soft band **aligns** with hard polarity; residual becomes **plate SoftL/SoftR labels swapped vs product strings**, not a body-value bug.

### Still Probable (explicit — do not invent fix)

1. **Name→DAT identity** remains **Probable**, not High: arithmetic + Accel baseline + hard/brake consistency is strong, but this residual did **not** re-prove ActionMap object base (name field and held byte are fields of one live object) via OnKeyDown field-layout seal or CE hold.
2. **Which story is product truth** remains open until (a) formal slot layout seal, or (b) runtime: hold key bound to UI “Steer Left Soft” → observe which DAT and resulting `entity+0x618`.
3. **Do not invent fix:** no clean/body flip of ±0.5; no silent rename of plate SoftL/SoftR in SECTION 7 immediates; no port “correction.” Document residual only (CX-001 / UF-006).

### Verdict on this residual slice

- **Body soft-steer:** sealed High (prior).
- **Bind label polarity (UF-006):** **still open** — evidence improved (strings High; name↔DAT Probable with display-order story B), but not sealed.
- Unit: **accept-with-gaps** unchanged for full DriveControlTick.
