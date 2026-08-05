# Review B (skeptical / adversarial): `aa_00604e10` MedalDef_ZeroOwnedStrings_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00604e10` |
| **VA** | `0x00604e10` |
| **Canonical name** | `MedalDef_ZeroOwnedStrings_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00604e10_MedalDef_ZeroOwnedStrings_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Full MedalDef ctor (zeros all) | Only +4..+0x10; id/tail not written | **Falsified** full-zero |
| 2 | Frees previous string heap | No free/delete — pure stores of 0 | **Falsified** free |
| 3 | Sets vtbl | No write to `*this` | **Falsified** vtbl ctor |
| 4 | Stack args | Bare `RET`; ECX only | **Falsified** stack ABI |
| 5 | Is the fill-from-row path | Fill is `FUN_00605090` | **Falsified** role merge |
| 6 | Multiple callers | Sole xref from `FUN_00519660` | **Agree** |

---

## 2. Live ≡ raw

```
00604e10  MOV EAX,ECX
          XOR ECX,ECX
          MOV [EAX+4/8/c/10], ECX
00604e20  RET
```

Matches raw decompile exactly. Parent uses return in EDI as `this` for fill+insert.

---

## 3. Surviving contract

```
// after operator_new(0x1c):
//   ZeroOwnedStrings(def) → def->str[0..3] = null
// id and +0x14/+0x18 still uninitialized until InitFromRow
```

**Verdict:** **accept-with-gaps.**
