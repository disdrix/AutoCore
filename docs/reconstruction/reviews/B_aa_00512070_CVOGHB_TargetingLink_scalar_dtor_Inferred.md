# Review B (skeptical / independent): `aa_00512070` CVOGHB_TargetingLink_scalar_dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512070` |
| **VA** | `0x00512070` |
| **Canonical name** | `CVOGHB_TargetingLink_scalar_dtor_Inferred` |
| **Review date** | `2026-07-29` (W19-G OWN dual) |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_00512070_CVOGHB_TargetingLink_scalar_dtor_Inferred.md` |
| **System** | `heartbeat` / targeting-link |
| **Verdict** | **accept-with-gaps** — agree with A; keep `_Inferred` |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_00512070` only | Acceptable leave-FUN scaffold; under-describes sealed role |
| `CVOGHBPlayerTargetingLink_scalar_dtor` | **Reject** — that is derived twin `0x0051b870` / vtbl `009cdfd4` |
| `CVOGHBBase_scalar_dtor` | **Reject** — base CVOGHBBase uses different vtbl family; this is targeting-link slot 0 |
| `CVOGHB_TargetingLink_dtor` without scalar | **Ambiguous** — complete dtor is `FUN_00512060`; this is deleting wrapper |
| `CVOGHB_TargetingLink_scalar_dtor` without `_Inferred` | **Reject** — no RTTI product string sealed for base family on this VA |
| `CVOGHB_TargetingLink_scalar_dtor_Inferred` | **Accept** — role Confirmed + family name from ctor dual |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Function is complete dtor only (no delete) | **Fails** — `test flags&1` + conditional `operator_delete` |
| Complete dtor is inlined here | **Fails** — near call to `FUN_00512060`; that body does vtbl+detach |
| Vtbl slot is derived PlayerTargetingLink | **Fails** — DATA xref is `009cdfb0` not `009cdfd4`; dword0 of base vtbl = this VA |
| `ret 4` means two stack args | **Fails** — single `flags` dword cleaned (MSVC thiscall dtor) |
| Name without `_Inferred` via "obvious class" | **Fails** — base family ctor itself is `_Inferred`; no type string here |

---

## 3. Cross-check vs derived twin `0x0051b870`

| Aspect | Base `00512070` | Derived `0051b870` |
|---|---|---|
| CF shape | identical scalar deleting | identical |
| Complete dtor | `FUN_00512060` direct | thunk/`FUN_00512060` |
| Vtbl | `009cdfb0`[0] | `009cdfd4`[0] |
| Class evidence | ctor dual Inferred | RTTI / purge path Confirmed PlayerTargetingLink |

---

## 4. Agreement with Review A

- Scalar-deleting dtor CF Confirmed: **agree**
- Vtbl slot 0 base family: **agree**
- Keep `_Inferred`: **agree**
- Gaps (mangled, RTTI string, array dtor, runtime): **agree open**

---

## 5. Residual risks

- Agents may confuse this with derived `0051b870` — document vtbl address in every artifact (done).
- Do not rename `FUN_00512060` from this dual (not owned); leave complete-dtor naming residual.

**Verdict:** **accept-with-gaps**
