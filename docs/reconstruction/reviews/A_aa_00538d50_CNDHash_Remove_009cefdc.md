# Review A (reconstruction fidelity): `aa_00538d50` CNDHash_Remove_009cefdc

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538d50` |
| **VA** | `0x00538d50` |
| **Canonical name** | `CNDHash_Remove_009cefdc` (remove twin; vtbl `PTR_LAB_009cefdc`; no delete) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_00538d50_CNDHash_Remove_009cefdc.md` |
| **System** | container / CNDHash family |
| **Live tools** | batch + force decompile, callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Non-owning **CNDHash remove** (same CF as `0x00538b20` / `0x00538bd0`):

- Lock warn-only; `004e2ca0` bucket find+unlink; list unlink; freelist; miss E_FAIL.
- Vtbl `PTR_LAB_009cefdc`.
- **No** `operator_delete`.

Caller: `FUN_0052a240` (continent/object reaction sibling of Relock).

---

## 2. Confidence

| Claim | Level |
|---|---|
| CF A≡B ≡ raw | **Confirmed** |
| Non-owning | **Confirmed** |
| Vtbl `009cefdc` | **Confirmed** |

---

## 3. Recovered CF

Same as sealed `CNDHash_Remove` with vtbl `009cefdc`.
