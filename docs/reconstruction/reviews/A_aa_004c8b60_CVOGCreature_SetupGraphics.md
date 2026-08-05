# Review A (reconstruction fidelity): `aa_004c8b60` CVOGCreature_SetupGraphics

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c8b60` |
| **VA** | `0x004c8b60` |
| **Canonical name** | `CVOGCreature_SetupGraphics` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004c8b60_CVOGCreature_SetupGraphics.md` |
| **System** | `npc-ai` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Creature graphics/physics placement setup: for template type **0x12** with flag bit4 clear, **subtract rlFlyingHeight** from Y before placement (pairs with CreateCreature add). NPC name setup and further graphics init follow.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c8b60_CVOGCreature_SetupGraphics.md` |
| Annotated | `docs/reconstruction/raw/aa_004c8b60_CVOGCreature_SetupGraphics.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCreature_SetupGraphics.cpp` |
| Function record | `docs/reconstruction/functions/aa_004c8b60_CVOGCreature_SetupGraphics.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Type 0x12 && !(flags>>4&1) → Y -= flying height @ template+0x4d4` | **High** | Plate + body |
| `FUN_005d4d70(param_2) placement helper` | **High** | Early call |
| `Graphics object +0x13a = 1 when +8 non-null` | **High** | Flag set |
| `IsNPC name setup path present` | **Probable** | Plate; mid-body string work |
| `Large residual FUN_* / SEH` | **High** | Scaffold body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Flying-height Y adjust | **Yes** |
| Placement + flag | **Yes** |
| Trailing graphics setup preserved | **Yes** |

---

## 5. Gaps / open

1. Full remaining body after name setup (mesh/phys).
2. Flag bit4 meaning sealed name.
3. Pair exactness with CreateCreature +height.
4. Runtime spawn height capture.

**Verdict:** **accept-with-gaps**
