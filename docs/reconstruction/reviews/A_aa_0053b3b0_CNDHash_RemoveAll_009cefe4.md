# Review A (reconstruction fidelity): `aa_0053b3b0` CNDHash_RemoveAll_009cefe4

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b3b0` |
| **VA** | `0x0053b3b0` |
| **Canonical name** | `CNDHash_RemoveAll` (node vtbl stamp `PTR_FUN_009cefe4`; non-owning) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_0053b3b0_CNDHash_RemoveAll_009cefe4.md` |
| **System** | container / CNDHash family |
| **Live tools** | batch decompile; twin family + remove `00537f30` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**RemoveAll twin** — CF identical to sealed RemoveAll family:

- Lock warn-only; inclusive mask walk; freelist all nodes; zero list/count
- **Does not** free values

**Only delta:** node vtbl stamp **`PTR_FUN_009cefe4`** — same family as remove `FUN_00537f30` / insert `FUN_0053c660` (mission state-blob).

Direct xrefs empty (vtbl/indirect).

---

## 2. Confidence

| Claim | Level |
|---|---|
| CF ≡ RemoveAll family | **Confirmed** |
| Vtbl `009cefe4` pairs with remove `00537f30` | **High** |
| Non-owning | **Confirmed** |

---

## 3. Recovered CF

```c
// same RemoveAll loop; stamp vtbl = PTR_FUN_009cefe4
```

**Verdict:** **accept-with-gaps.**
