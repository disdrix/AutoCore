# Review B (skeptical / adversarial): `aa_007b8910` Com_BstrPropertyEquals_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b8910` |
| **VA** | `0x007b8910` |
| **Canonical name** | `Com_BstrPropertyEquals_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007b8910_Com_BstrPropertyEquals_Inferred.md` |
| **System** | COM / ADO field compare (DB load filters) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Case-sensitive CRT wcscmp only | VarBstrCmp with 0x400 | **Falsified** |
| 2 | Does not free input BSTR | SysFreeString both paths | **Falsified** |
| 3 | Returns HRESULT | bool/char widened | **Falsified** |
| 4 | Skill table exclusive | VehicleDb_LoadCloneBase also calls | **Falsified** |

---

## 2. Live ≡ raw

Live `batch_decompile` @ `0x007b8910` (autoassault.exe, 2026-07-29) matches `raw/aa_007b8910_FUN_007b8910.md` control flow and callees.

---

## 3. Surviving contract

```
// bool equals = VarBstrCmp(propBstr, rhs, 0x400, 0)==1; always free rhs + Release obj.
```

**Verdict:** **accept-with-gaps.** Adversarial pass does not overturn structural CF; naming remains `_Inferred` where product symbols absent.
