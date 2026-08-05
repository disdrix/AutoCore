# Review B (skeptical / adversarial): `aa_0092a200` Object_MatchesFilterDescriptor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092a200` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0092a200_Object_MatchesFilterDescriptor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | `__thiscall` on object | Uses EAX filter + EBX object; no ECX this | **Falsified** as thiscall |
| 2 | Only vehicle-create filter | 7 callers incl. inventory + client tick | **Falsified** as vehicle-only |
| 3 | OR across all tables always | Type pass can **return 0** mid-match (subtype/level fail) | **Sealed** — fail-closed inside type hit |
| 4 | Level band always applied | `-1` open on min and/or max | **Falsified** as always-band |
| 5 | TFID path is AND with tables | Independent final pass; returns 1 alone | **Sealed** as alternate accept |
| 6 | Sets filter+4 itself | Callers write `+4=1` after success | **Falsified** — pure predicate |
| 7 | `unaff_EBX` is noise | Live `test ebx` + callers load EBX | **Sealed** as real ABI |

---

## 2. Confidence table

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX filter / EBX object / AL bool | **High** | Wrong port ABI |
| Five sequential accept paths | **High** | Miss eligibility |
| Fail inside type-hit on subtype/level | **High** | False accepts |
| Parallel map at `+0xd8` | **High** | Wrong category |
| Product table English | **Open** | Doc only |
| Runtime | **Open** | |

---

## 3. Surviving contract

```c
// custom: EAX=filter, EBX=object
bool Object_MatchesFilterDescriptor(FilterDesc* filter /*EAX*/, Object* obj /*EBX*/);
```

- Pure predicate; no side effects on filter (callers latch `filter+4`).
- Accept if any completed pass succeeds; type pass is strict after id hit.

---

## 4. Verdict

**accept-with-gaps** — adversarial seals dual-register ABI and fail-closed type branch.
