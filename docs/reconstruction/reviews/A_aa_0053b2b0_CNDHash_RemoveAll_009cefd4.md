# Review A (reconstruction fidelity): `aa_0053b2b0` CNDHash_RemoveAll_009cefd4

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b2b0` |
| **VA** | `0x0053b2b0` |
| **Canonical name** | `CNDHash_RemoveAll` (node vtbl stamp `PTR_FUN_009cefd4`; non-owning) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_0053b2b0_CNDHash_RemoveAll_009cefd4.md` |
| **System** | container / CNDHash family |
| **Live tools** | batch decompile; twin family |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**RemoveAll twin** — CF identical to `0x0053b130` / `0x0053b230`:

- Lock warn-only
- Inclusive `u <= mask` bucket walk
- Non-owning: clear value, freelist-push nodes, zero list + count

**Only delta:** node vtbl stamp **`PTR_FUN_009cefd4`** (continent-unlock insert family at `CNDHash_Insert` `0x0053c560` / remove `0x00538c80`).

Direct xrefs empty.

---

## 2. Confidence

| Claim | Level |
|---|---|
| CF ≡ RemoveAll family | **Confirmed** |
| Vtbl `009cefd4` | **Confirmed** |
| Non-owning | **Confirmed** |

---

## 3. Recovered CF

```c
// same RemoveAll loop; stamp vtbl = PTR_FUN_009cefd4
```

**Verdict:** **accept-with-gaps.**
