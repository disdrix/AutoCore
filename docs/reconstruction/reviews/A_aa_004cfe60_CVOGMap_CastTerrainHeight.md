# Review A (reconstruction fidelity): `aa_004cfe60` CVOGMap_CastTerrainHeight

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cfe60` |
| **VA** | `0x004cfe60` |
| **Canonical name** | `CVOGMap_CastTerrainHeight` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004cfe60_CVOGMap_CastTerrainHeight.md` |
| **System** | `world-terrain` |
| **Verdict** | **accept** |

---

## 1. Purpose

Map terrain **down-cast height** query (`this` = CVOGMap*). Null heightfield at **map+0xe4e0** → return **0.0**. Sample HF Y via `FUN_005a58c0(x,z)`; build vertical ray start `(x,yStart,z)` → end `(x, hfY+0.01, z)` with filter **`(-(flag!=0)&0xD)+5`** (5 or 18); cast via `FUN_0055e530` on map ctx **+0xe4a4**. Hit → lerp Y by fraction; miss → pure HF Y. Used by spawn / FindTerrainHeight / air-stab re-ground. **Not** wheel `TtPhantom::castRay`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004cfe60_CVOGMap_CastTerrainHeight.md` |
| Annotated | `docs/reconstruction/raw/aa_004cfe60_CVOGMap_CastTerrainHeight.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGMap_CastTerrainHeight.cpp` |
| Function record | `docs/reconstruction/functions/aa_004cfe60_CVOGMap_CastTerrainHeight.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `map+0xe4e0 null → 0.0` | **High** | Verified plate |
| `FUN_005a58c0 HF sample (x,z)` | **High** | Call |
| `endY = hfY + DAT_00a0f718 (0.01)` | **High** | read_memory verified |
| `filter = (-(flag!=0)&0xD)+5` | **High** | 5 or 18 |
| `FUN_0055e530 collision cast` | **High** | ctx +0xe4a4 |
| `Hit: lerp yStart↔endY by fraction` | **High** | return |
| `Miss: return hfY (not yStart)` | **High** | Critical |
| `RET 0x10 four stack args` | **High** | thiscall map |
| `Not wheel collide path` | **High** | physics verified contrast |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Null HF + sample + ray + hit/miss | **Yes** |
| Matches verified fn_004cfe60 plate | **Yes** |

---

## 5. Gaps / open

1. Name FUN_005a58c0 / FUN_0055e530 fully.
2. Exact ray/result stack layout vs castRay sibling.
3. Runtime bit-exact vs heightfield assets.

**Verdict:** **accept**
