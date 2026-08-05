# Review B (skeptical / adversarial): `aa_0051f550` BuildRaceClassSuffix_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051f550` |
| **VA** | `0x0051f550` |
| **Canonical name** | `BuildRaceClassSuffix_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0051f550_BuildRaceClassSuffix_Inferred.md` |
| **System** | UI path suffix |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Full path builder including directory | Only appends short `_x` tokens to empty buffer | **Falsified** full path |
| 2 | Race enum unbounded | Only 0/1/2 append; else race skipped | **Agree** bounded |
| 3 | Class always appended | switch 0..3 only; `-1` from garage skips | **Agree** |
| 4 | Returns heap string | Returns static `DAT_00b04600` | **Falsified** heap |
| 5 | Thread-safe | Single global buffer | **Falsified** TLS |
| 6 | Drive-physics helper | Garage/icon consumers only in sealed xrefs | **Falsified** drive role (prior alias noise) |

---

## 2. Live ≡ raw

```
Live ≡ raw + read_memory tokens:
  clear b04600
  race∈{0,1,2} → append _h/_m/_b
  class switch → append _c/_e/_o/_r
  return &b04600
```

---

## 3. Surviving contract

```
// char* BuildRaceClassSuffix(race, class)
// Static buffer DAT_00b04600; tokens from 0x009ceee0 table.
```

**Verdict:** **accept-with-gaps.**
