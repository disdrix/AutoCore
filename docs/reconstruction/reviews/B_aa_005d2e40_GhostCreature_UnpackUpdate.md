# Review B (skeptical / adversarial): `aa_005d2e40` GhostCreature_UnpackUpdate

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d2e40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005d2e40_GhostCreature_UnpackUpdate.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Terrain-snaps feet on unpack | Falsified — as-is position |
| 2 | Is VehicleNet_UnpackGhostVehicle | Falsified — creature path |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| No foot correction contract | High | Floating/sinking creatures |
| Initial vs delta split | High | Missing skills on spawn |

---

## 3. Cross-check against raw

```
UnpackUpdate(creatureGhost, stream, isInitial):
  position raw; optional initial enhancement/skills/level.
Clean ≡ raw CF large residual.
```

---

## 4. Surviving contract for AutoCore

```
Creature ghost unpack; contrast vehicle unpack for owner forms.
```

---

## 5. Open questions

1. Cross-link owner TFID forms in vehicle unpack.

**Verdict:** accept-with-gaps
