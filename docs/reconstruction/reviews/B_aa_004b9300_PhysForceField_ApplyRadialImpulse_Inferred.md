# Review B (skeptical / adversarial): `aa_004b9300` PhysForceField_ApplyRadialImpulse_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b9300` |
| **VA** | `0x004b9300` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra) |
| **Counterpart** | `reviews/A_aa_004b9300_PhysForceField_ApplyRadialImpulse_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Mission complete audio helper | scaffold name | **Falsified** — physics area query + impulse; 0 audio strings/callees |
| 2 | Always applies radial push | flag + null gates | **Falsified** — early out if no world, no target, or flag bit 5 clear |
| 3 | Falloff always linear | `params[10]` branches | **Falsified** — linear / quadratic / constant |
| 4 | GetObjectsInArea default AABB | args `mode=2, filter=1` | **Falsified** — mode **2** (sphere-ish per `004ea350` dual) |
| 5 | Direction always world-axis params | `params[+0x24]` | **Partial** — may re-express dir in target local frame via quat |
| 6 | Sole path is area impulse | `this+0x28` | **Partial** — secondary TFID queue for types 1/0x10/0x11 even after primary |
| 7 | `params[10]` is true float | float compares | **Attacked** — values are integer 1/2 re-interpreted as float (1.4013e-45 / 2.8026e-45) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Not audio / mission table | **High** | Wrong system ownership |
| Radial impulse math | **High** | Wrong knockback feel |
| Falloff enum int-in-float | **High** | Port as real float fails always |
| Mode-2 area query | **High** | Wrong broadphase set |
| Product English name | **Tentative** | Naming only |
| Secondary path full semantics | **Probable** | Missing delayed force |

---

## 3. Cross-check against raw / live

```
if !world: return
if params:
  resolve target; require flag bit5
  center = target world pos (if phys host ready)
  optional orient-rotate baseDir
  scale baseDir *= blend
  hits = GetObjectsInArea(world, center, radius, mode=2, filter=1)
  foreach hit: falloff * mixedDir; optional /mass; apply impulse
  queue summary record; free list
if type in {1,0x10,0x11}: resolve TFID; queue secondary force pod
```

Live ≡ raw ≡ clean. Epsilon `@009cb2b4` = `0x34000000` float.

---

## 4. Surviving contract for AutoCore

```
// Force action tick / fire:
PhysForceField_ApplyRadialImpulse(action, targetOrNull)
// Knockback only if action.world && (action.params || secondary type) && target flag
// FalloffMode: 1 linear, 2 quadratic, else flat strength
```

Server note: client phys impulse — do not invent sector-authoritative knockback from this VA alone.

---

## 5. Attack scenarios that must not pass review

1. **Keep scaffold “mission audio” name** — pollutes naming registry.
2. **Port falloff as float distance curve without int modes** — both 1 and 2 branches dead.
3. **Use AABB mode 0 for this caller** — different hit set than retail.
4. **Skip flag bit 5** — applies to objects retail ignores.

---

## 6. Open questions

1. Class of `this` (reaction? timed force? special FX phys?).
2. Who calls `004b9af0` / `00518590` and with which types.
3. Whether secondary path is “sticky” force follow or one-shot reattach.

**Verdict:** **accept-with-gaps**
