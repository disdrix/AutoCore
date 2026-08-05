# Review B refresh: soft-steer / analog (skeptical) — UF-006 BIND residual

| Field | Value |
|---|---|
| **Stable ID** | `aa_009223b0` |
| **Counterpart** | A soft/analog refresh |
| **Verdict** | **accept-with-gaps** (body High; **UF-006 label polarity still open**) |
| **This residual pass** | 2026-07-29 — ActionMap **label polarity only**; body ±0.5/±1.0 **not re-opened**; camera duals **not rewritten** |

## Challenges (prior + this residual)

| Challenge | Outcome |
|---|---|
| Soft polarity bug in body? | **Preserve as observed** — retail push bits sealed; flipping = inventing a port patch |
| SoftL/SoftR plate names product-true? | **Attacked** — display-name order + stride arithmetic **swap** plate SoftL↔SoftR vs UI strings |
| Name↔DAT arithmetic seals UF-006? | **No** — elevates alternate label story to **Probable**, not sealed High |
| Analog device identity | Open — only `DAT_00d1b618` sample path sealed (out of slice) |
| Full function dual 2026-07-23 | This refresh **adds** soft/analog + bind-label evidence only |

Do **not** claim soft labels sealed without either formal ActionMap object layout or runtime hold.

---

## UF-006 BIND residual — adversarial label analysis

### Body (sealed — attack fails if claiming rewrite)

| DAT | Immediate | f32 | Image / decomp |
|-----|-----------|----:|----------------|
| `DAT_00d1bc8e` | `0x3f800000` | +1.0 | hard path |
| `DAT_00d1bcc2` | `0xbf800000` | −1.0 | hard path |
| `DAT_00d1bd2a` | `0xbf000000` | −0.5 | push @ `0x00922c48` |
| `DAT_00d1bcf6` | `0x3f000000` | +0.5 | push @ `0x00922cf8` |

**Attack result:** magnitudes and priority order **not broken**. Residual is **naming**, not hex.

### String evidence (High — not sufficient alone)

| VA | Bytes (`read_memory`) | C string |
|----|----------------------|----------|
| `0x00a853d8` | `53 74 65 65 72 20 4c 65 66 74 20 53 6f 66 74 00` | `Steer Left Soft` |
| `0x00a853c4` | `53 74 65 65 72 20 52 69 67 68 74 20 53 6f 66 74 00` | `Steer Right Soft` |
| `0x00a853f4` | … | `Steer Left` |
| `0x00a853e8` | … | `Steer Right` |

Stores: `Client_InitActionDisplayNames` ActionMap `+0x34d` / `+0x381` (soft), `+0x2e5` / `+0x319` (hard). **High** that UI can show those labels. **Does not** alone prove which held `DAT_*` that slot’s key sets.

### Stride arithmetic attack surface (Probable, not High)

Claim under test: `held = DAT_00d1bc26 + (name_off − 0x27d)` with Accel baseline.

| Support | Attack |
|---------|--------|
| Drive slots spaced `0x34` in both name offs and known held DATs | Strong pattern match |
| Hard L/R/Brake inferred DATs match plate | Consistent |
| Soft inferred DATs land on the two soft body loads | Consistent addresses |
| Activate name `+0x4b9` → `d1be62` under same rule (interact map) | Extra cross-system consistency |
| OnKeyDown plate says held at entry `+4` from `DAT_00d1bbee` | **Not re-sealed** as identity of Accel held `d1bc26` in this residual |
| No live CE hold of “Steer Left Soft” → DAT | **Missing** for High |

**Verdict on link:** **Probable**. Promoting to High without object-base or runtime would be overclaim.

### If arithmetic accepted (Story B) — polarity “bug” dissolves into plate swap

| UI display (string) | Inferred DAT | Body f32 | vs hard |
|---------------------|--------------|---------:|---------|
| Steer Left Soft | `d1bcf6` | +0.5 | same sign as Hard L (+1) |
| Steer Right Soft | `d1bd2a` | −0.5 | same sign as Hard R (−1) |

WI-MOV plate **SoftL = `d1bd2a`**, **SoftR = `d1bcf6`** is then **inverted relative to UI strings**. Residual becomes: **plate SoftL/SoftR labels misaligned with InitActionDisplayNames**, not “retail soft band is intentionally opposite.”

### If arithmetic rejected (Story A) — original invert stands

Under plate SoftL/SoftR as physical names: soft signs **oppose** hard L/R. That was the original UF-006 / CX-001 framing.

### What remains Probable / open (must not invent fix)

| Residual | Level | Forbidden “fix” |
|----------|-------|-------------------|
| Product UI L/R soft ↔ which DAT | **Probable** (Story B favored by arithmetic; not sealed) | Renaming clean DATs SoftL/SoftR as sealed truth |
| Soft physical = hard physical under player | **Open** | Flipping ±0.5 immediates in clean or ports |
| Formal ActionMap name field vs held byte layout | **Open / Probable** | Treating PollBoundActions baseline as High for this unit alone |
| Runtime bind hold | **Open** | Claiming complete without CE/Launcher |

**Skeptical summary:** New string + arithmetic evidence **narrows** UF-006 from “maybe body wrong” to “label map Probable; body High.” It does **not** seal the unit. Prefer documenting dual stories over picking a rename.

## Sealed vs open (this residual slice)

| Slice | Status |
|-------|--------|
| Soft/hard body CF & immediates | **Sealed High** |
| Display bind name strings | **Sealed High** (image + InitActionDisplayNames) |
| Display ↔ DAT via stride | **Probable** |
| UF-006 product label polarity | **Open residual** |
| Camera duals | **Out of ownership** (not touched) |
| Full DriveControlTick complete | **Open** (UF-003 remainder, runtime, callers) |
