# Review A (reconstruction fidelity): `aa_0080ae70` Client_AwardKillExperience

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080ae70` |
| **VA** | `0x0080ae70` |
| **Canonical name** | `Client_AwardKillExperience` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0080ae70_Client_AwardKillExperience.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_AwardKillExperience.cpp` |
| Callee | `CVOGReaction_AddExperience` |
| Prior art | `docs/XP.md` GiveXP 0x205F |

---

## 2. Signature & CF

| Stage | Raw | Clean | Match |
|---|---|---|---|
| `__cdecl` formal packet* | Present | Present (often unused) | **Yes** |
| Register EDI+0xe98 local char | Present | Present | **Yes** |
| ESI+4 amount / ESI+8 hint | Present | Present | **Yes** |
| Null char → VOG_DEBUG_STOP | Present | Present | **Yes** |
| `AddExperience(..., PacketOrNonKill)` | Present | Present | **Yes** |
| Hint != -1 → write `+0x738` + `GetTickCount`→`+0x734` | Present | Present | **Yes** |
| Vehicle `+0x250` → floater type 3 | Present | Present | **Yes** |

---

## 3. State mutations

| Target | Mutation |
|---|---|
| Character XP | Via AddExperience non-kill |
| `+0x738` / `+0x734` | Level hint path only |
| Floater queue | Optional |

---

## 4. Gaps

1. Custom dispatch register contract still INFERRED (how EDI/ESI set).
2. Floater blob DAT constants not semantic-named.
3. Historical filename/function name says “Kill” but path is all GiveXP.

**Verdict:** Handler CF faithful. **accept-with-gaps.**
