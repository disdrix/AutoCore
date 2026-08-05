# Review B (skeptical / adversarial): `aa_005e1150` LootCatalog_RollFilteredCandidateId_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e1150` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005e1150_LootCatalog_RollFilteredCandidateId_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Identical to `005e1030` | Different fill (`005e0cd0` vs `005e07d0`) + filter loop | **Falsified** merge |
| 2 | Always strips invalid prefix | Only when `param_6 != 0` **and** `004ce940()!=0` | **Survives** as gated |
| 3 | Exclusion list required | `param_5==0` skips exclude; may still pick | **Survives** as optional |
| 4 | `operator_delete` process-kills | SEH artifact | **Survives** as noise |
| 5 | Is GenerateLootItem itself | Only rolls an id; materialize is caller | **Falsified** |
| 6 | Uses same fill as unfiltered path | `005e07d0` vs `005e0cd0` different table math | **Falsified** |

---

## 2. Live ≡ raw

Live matches raw `aa_005e1150`: SEH, `005e0cd0`, null check, exclude/invalid compact loop, RNG pick, dual delete tails.

---

## 3. Surviving contract

```
// catalog + band/quality formals → FUN_005e0cd0 → candidate dword vector
// if null → -1
// for each id:
//   drop if in exclude_vec[begin,end)
//   drop if filter_invalid && gate(004ce940) && prefix lookup miss/-1
// if remaining: random-pick one; free; return id
// else free; fail
```

**Gaps kept:** formal names; clean pick return; `004ce940` product meaning.

**Verdict:** **accept-with-gaps**.
