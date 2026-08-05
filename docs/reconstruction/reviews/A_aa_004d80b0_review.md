# Review A (reconstruction fidelity): `aa_004d80b0` CVOGCombat_CalculateAndAwardKillXP

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d80b0` |
| **VA** | `0x004d80b0` |
| **Canonical name** | `CVOGCombat_CalculateAndAwardKillXP` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004d80b0_CVOGCombat_CalculateAndAwardKillXP.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCombat_CalculateAndAwardKillXP.cpp` |
| Prior art | `docs/XP.md` § Final kill amount |
| Memory | `read_memory` @ `0x00B037F8`, `0x009CBF80`, `0x00A0F730` |

---

## 2. Signature

| Element | Raw | Clean | Match |
|---|---|---|---|
| Convention | `__cdecl` 6 params | Same | **Yes** |
| Levels + mult + character + convoy count + unused | Present | Present; unused unnamed | **Yes** |
| Return | void | void | **Yes** |

---

## 3. Control flow vs raw

| Stage | Raw | Clean | Match |
|---|---|---|---|
| Prep-clamp `victim-player > 3` → `victim = player+3` | Present | Present | **Yes** |
| Dead second clause after clamp | Present | Present (commented) | **Yes** |
| `Experience_LevelDiffBaseXp(..., true)` | Present | Present | **Yes** |
| Convoy blend when count > 0 | Present | Present | **Yes** |
| `ceil(base * globalScalar * mult)` | Present | Present | **Yes** |
| Spree stacks `max(0, +0x738-1)` + 5% | Present | Present | **Yes** |
| `AddExperience(..., KillPath)` | Present | Present | **Yes** |
| Local `+0x7e` + vtable `+0x19c` + floater | Present | Present | **Yes** |

---

## 4. State mutations

| Target | Mutation |
|---|---|
| Character via `AddExperience` | Total XP / levels (KillPath) |
| Spree byte `+0x738` | **Read only** here (updated inside AddExperience KillPath) |
| Combat floater queue | Enqueue when local |

---

## 5. Constants cross-check

| Symbol | Image | XP.md |
|---|---|---|
| `g_flGlobalKillXpScalar` | `0x00B037F8` = **0** | Matches “BSS 0” |
| `g_flKillSpreeBonusPerStack` | `0x009CBF80` = **0.05f** | Matches |
| `g_flMultiKillCountBlend` | `0x00A0F730` = **0.1f** | Matches |

---

## 6. Gaps

1. `pLocalPlayerCtx_INFERRED` for `+0x7e` is still unaffiliated register in decompiler — floater gate host not fully typed.
2. Floater enqueue args simplified vs full blob in sibling units.
3. `ROUND` vs exact x87 mode not proven.

**Verdict:** Clean tracks raw formula and award path. **accept-with-gaps.**
