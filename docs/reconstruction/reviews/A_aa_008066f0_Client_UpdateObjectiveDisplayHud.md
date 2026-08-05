# Review A (reconstruction fidelity): `aa_008066f0` Client_UpdateObjectiveDisplayHud

| Field | Value |
|---|---|
| **Stable ID** | `aa_008066f0` |
| **VA** | `0x008066f0` |
| **Canonical name** | `Client_UpdateObjectiveDisplayHud` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008066f0_Client_UpdateObjectiveDisplayHud.md` |
| **System tag** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_UpdateObjectiveDisplayHud.cpp` |
| Raw | `docs/reconstruction/raw/aa_008066f0_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Refresh objective/level/money HUD strings. switch on mode byte this+0xd1c; case 1 builds 'Level' label via FUN_007a6de0, XP bar fraction from character thresholds (Experience_GetCumulativeThreshold), money/objective format strings ('%s - %s %d', 'Money', '%s: %s'). Client presentation only.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| switch(this+0xd1c) mode | High | Body |
| case 1 Level string path | High | FUN_007a6de0 Level |
| XP bar uses cumulative thresholds | High | Callees |
| Money / objective format strings | High | Strings |
| Uses local character DAT_00d1b6d8 context | Medium | Body |
| No mission state mutation | High | UI only |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| SEH → switch mode → set label widgets | Yes |

---

## 4. Gaps

1. All switch cases beyond case 1.
2. Widget object offsets +0x70/+0xbb0/+0x350 semantics.

**Verdict:** **accept-with-gaps**
