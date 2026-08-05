# Review B (skeptical / adversarial): `aa_0041aef0` SkillRowVec_EmplaceBack_Stride934_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041aef0` |
| **VA** | `0x0041aef0` |
| **Canonical name** | `SkillRowVec_EmplaceBack_Stride934_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0041aef0_SkillRowVec_EmplaceBack_Stride934_Inferred.md` |
| **System** | skills-abilities / DB load (Skill_DbLoadSkillsCharacters nested) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Is skill cast / combat logic | No combat strings; pure buffer math | **Falsified** |
| 2 | Stride 0x100 / generic POD | Immediate 0x934 + 0x24d dword copy | **Falsified** |
| 3 | Always reallocates | Fast path bumps end without FUN_0041c920 | **Falsified** |
| 4 | Multiple unrelated owners | Only 007e34b0 xrefs | **Falsified multi-owner** |
| 5 | Bit-exact MSVC vector ABI | Shape match only; no RTTI | **Survives as inferred** |

---

## 2. Live ≡ raw

Live `batch_decompile` @ `0x0041aef0` (autoassault.exe, 2026-07-29) matches `raw/aa_0041aef0_FUN_0041aef0.md` control flow and callees.

---

## 3. Surviving contract

```
// Vec934: +4 begin, +8 end, +0xc capEnd; elem size 0x934
// Emplace one element at end or grow via FUN_0041c920.
```

**Verdict:** **accept-with-gaps.** Adversarial pass does not overturn structural CF; naming remains `_Inferred` where product symbols absent.
