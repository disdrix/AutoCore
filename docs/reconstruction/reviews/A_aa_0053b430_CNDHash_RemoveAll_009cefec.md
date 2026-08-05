# Review A (reconstruction fidelity): `aa_0053b430` CNDHash_RemoveAll_009cefec

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b430` |
| **VA** | `0x0053b430` |
| **Canonical name** | `CNDHash_RemoveAll` (node vtbl stamp `PTR_FUN_009cefec`; non-owning) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_0053b430_CNDHash_RemoveAll_009cefec.md` |
| **System** | container / CNDHash family |
| **Live tools** | `batch_decompile` + twin family; remove `00538000`; node dtor residual |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**RemoveAll twin** — CF identical to sealed RemoveAll family:

- Lock warn-only (`HashError:RemoveAll…`); inclusive mask walk; freelist all nodes; zero list/count; return 0
- **Does not** free values (zeros `@node+0x08` only)

**Only delta:** node vtbl stamp **`PTR_FUN_009cefec`** — same family as remove `FUN_00538000` / Destroy-via-remove `FUN_00538e50` / node residual xrefs (`00537550` review lists this VA among stamp writers).

Direct code xrefs empty (vtbl/indirect).

---

## 2. Confidence

| Claim | Level |
|---|---|
| CF ≡ RemoveAll family | **Confirmed** |
| Vtbl `009cefec` pairs with remove `00538000` | **High** |
| Non-owning | **Confirmed** |
| Inclusive `u <= mask` | **Confirmed** |

---

## 3. Recovered CF

```c
// same RemoveAll loop; stamp vtbl = PTR_FUN_009cefec
```

**Verdict:** **accept-with-gaps.**
