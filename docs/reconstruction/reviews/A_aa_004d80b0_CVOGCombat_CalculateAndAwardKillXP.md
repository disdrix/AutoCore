# Review A (reconstruction fidelity): `aa_004d80b0` CVOGCombat_CalculateAndAwardKillXP

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d80b0` |
| **VA** | `0x004d80b0` |
| **Canonical name** | `CVOGCombat_CalculateAndAwardKillXP` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004d80b0_CVOGCombat_CalculateAndAwardKillXP.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Final kill XP: prep-clamp victim level (max player+3), `Experience_LevelDiffBaseXp` (grey), optional convoy blend (count>0, 0.1 constant), raw=ceil(base×**g_flGlobalKillXpScalar**×participation), spree stacks max(0,spree−1)×5%, then `AddExperience(..., KillPath)` + optional type-3 floater if local.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004d80b0_CVOGCombat_CalculateAndAwardKillXP.md` |
| Annotated | `docs/reconstruction/raw/aa_004d80b0_CVOGCombat_CalculateAndAwardKillXP.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCombat_CalculateAndAwardKillXP.cpp` |
| Function record | `docs/reconstruction/functions/aa_004d80b0_CVOGCombat_CalculateAndAwardKillXP.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Victim clamp to player+3 when delta>3` | **High** | Prep before LevelDiffBase |
| `LevelDiffBaseXp(..., grey=true)` | **High** | Callee |
| `Convoy blend when count>0 uses 0.1f @ 0x00A0F730` | **High** | ceil((base+trunc(count*0.1*base))/count) |
| `Global scalar @ 0x00B037F8 is BSS 0 → local raw often 0` | **High** | Image note; product still coded |
| `Spree stacks from char+0x738; +5% per stack @ 0x009CBF80` | **High** | stacks=max(0,byte-1) |
| `Award via AddExperience KillPath` | **High** | isKillPath=1 |
| `Local floater type 3 when award ok + +0x7e` | **Probable** | pLocalPlayerCtx residual |
| `nUnused formal unused in body` | **High** | Signature residue |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Clamp + base + convoy + scalar | **Yes** |
| Spree + AddExperience + floater | **Yes** |
| No invented non-zero default scalar | **Yes** |

---

## 5. Gaps / open

1. Whether server patches global scalar or only client image is zero.
2. Local player context for +0x7e residual.
3. Experience_LevelDiffBaseXp table full seal.
4. Runtime kill capture (expect 0 client-side if scalar stays 0).

**Verdict:** **accept-with-gaps**
