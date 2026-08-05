# Review A (reconstruction fidelity): `aa_005e6c40` CVOGRoadNode_ParseWidthFromTexName

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e6c40` |
| **VA** | `0x005e6c40` |
| **Canonical name** | `CVOGRoadNode_ParseWidthFromTexName` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005e6c40_CVOGRoadNode_ParseWidthFromTexName.md` |
| **System tag** | `map-roads` |
| **Verdict** | **accept** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/CVOGRoadNode_ParseWidthFromTexName.cpp` |
| Raw | `docs/reconstruction/raw/aa_005e6c40_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Parse road width from texture/profile name: copy name, strrchr '_', atof trailing number (e.g. road_2laneasphalt_20 → 20.0). Store float at this+0x164. Min clamp DAT_00a0f2a0; on missing '_' log 'Road has invalid texture name...' and default DAT_00a110d8 (10.0).

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| strrchr '_' then atof tail | High | Body + plate |
| Write float width to this+0x164 | High | Store |
| Default DAT_00a110d8 when no underscore | High | Branch |
| Min clamp DAT_00a0f2a0 | High | Plate |
| Log strings for invalid name | High | Strings |
| Example road_2laneasphalt_20 → 20 | High | Plate |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Copy → strrchr → atof/clamp or default+log | Yes |

---

## 4. Gaps

1. Exact float value of DAT_00a0f2a0 min.
2. Whether +0x164 ever holds pointer before parse (decomp dual write).

**Verdict:** **accept**
