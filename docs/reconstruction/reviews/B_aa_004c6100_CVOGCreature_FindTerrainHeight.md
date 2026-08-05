# Review B (skeptical / adversarial): `aa_004c6100` CVOGCreature_FindTerrainHeight

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c6100` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004c6100_CVOGCreature_FindTerrainHeight.md` |
| **Verdict** | **accept-with-gaps** on CF; castRay packing residual |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always uses only CastTerrainHeight | **Falsified — castRay when body** |
| 2 | No foot offset | **Falsified — +0x120** |
| 3 | Ignores local filter | **Falsified — bLocal → filter** |
| 4 | Finished castRay ABI | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dual path body vs map cast | High | Hover/sink NPCs |
| Foot +0x120 | High | Buried feet |
| bLocal filter | High | Self-hit rays |
| castRay packing | Tentative | Wrong hit Y |

---

## 3. Cross-check against raw

```
bLocal=focused==this; y=HF(x,z)+bias;
if elevated: body? castRay : CastTerrainHeight(bLocal);
return y+foot.
Clean ≡ raw CF; ray out residual.
```

---

## 4. Surviving contract for AutoCore

```
FindTerrainHeight:
  AI/movement snap; foot offset required
  prefers physics ray when phantom/body present else map cast
  AutoCore IsNPC may rely on server Y + foot instead of calling this
  pair CastTerrainHeight + castRay verified plates
```

---

## 5. Open questions

1. Finish aa_00580ed0 dual if missing.
2. Name FUN_004cd220.
3. Live NPC hover cases.

**Verdict:** **accept-with-gaps** on CF; castRay packing residual
