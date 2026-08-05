# Review B (skeptical / adversarial): `CVOGHBAICreatureBase_PathlessIdleRoam_Inferred` / `FUN_005cd220` @ `0x005cd220`

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cd220` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-S) |
| **Counterpart** | `reviews/A_aa_005cd220_CVOGHBAICreatureBase_PathlessIdleRoam_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This seeks / chases the player | **Falsified** — local random offset only; no player TFID/path |
| 2 | Same as `FUN_004cd220` terrain sample | **Falsified** — different VA (`0x005cd220` vs `0x004cd220`) |
| 3 | `g_flLevelUpUiBase_Inferred` is UI level-up | **Falsified here** — loads **2.0f** for math scale |
| 4 | `g_flVehicleHpTechCoeff` is vehicle HP | **Falsified here** — loads **3.0f**; used as radius floor-add |
| 5 | Always issues a move | **Falsified** — gates + 1/3 chance; often no-op |
| 6 | Return value drives OnHeartBeat | **Falsified** — call is void-shaped; return unused |
| 7 | Product name retail | **Overstated** — `_Inferred` |
| 8 | Runtime verified | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Cooldown + flag gates | **High** | roam spam / freeze |
| 1/3 probability | **High** | wrong roam rate |
| Offset ∈ ~[-r,r] | **High** | roam radius wrong |
| Not player-seek | **High** | bad Ambient AI feel |
| vtbl destinations | **Medium** | wrong move API |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes

```
if !owner+0x279: return
if !(interval < tick - stamp): return
busy = 1
u = rand_u16; if u%3: return
r = table+0x4d4; if r < 3: r += 3
off.xz = u16 * r * 2 * (~1/65536) - r; off.y = 0
quat = FUN_0053e0b0; pack vtbl+0x1a4; Math_QuatTransformPoint; AI vtbl+0x4c(dest,0)
ret
```

Entry `55 8b ec 83 e4 f0`. Exit `5d c3`. Globals verified by `read_memory`.

---

## 4. Surviving contract for AutoCore

```
// Pathless Ambient roam helper — NOT combat seek, NOT MapPath home
// MUST honor owner+0x279 and cooldown before any move
// MUST apply 1/3 random gate
// MUST use radius table+0x4d4 with floor-add 3.0 when r < 3
// MUST map ushort via (u16 * r * 2 * ~1/65536 - r) for XZ
// MUST NOT treat Ghidra float symbol names as product semantics
// Return value may be ignored
```

Port gap called out in `docs/NPC.md` row 2 (pathless idle roam) depends on this unit.

---

## 5. Verdict

Adversarial pass **confirms** A: pathless roam with gated random local destination → **accept-with-gaps**.
