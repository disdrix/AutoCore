# Review A (reconstruction fidelity): `aa_007280f0` AuthClient_OnLoginOk

| Field | Value |
|---|---|
| **Stable ID** | `aa_007280f0` |
| **VA** | `0x007280f0` |
| **Canonical name** | `AuthClient_OnLoginOk` |
| **System** | auth |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007280f0_AuthClient_OnLoginOk.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_007280f0_AuthClient_OnLoginOk.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_007280f0_FUN_007280f0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AuthClient_OnLoginOk.cpp` |
| String evidence | `LoginOk/AuthServer` |

---

## 2. Purpose (from unit)

Inbound LoginOk: thiscall; null this early -1; else callback with session fields.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| String "LoginOk" | **High** |  |
| Extra null check unlike simple fail handlers | **High** |  |
| Shared shell pattern | **High** |  |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Shared socket scratch shell on auth client param | **Yes** (clean ≡ raw scaffold) |
| Log "LoginOk"/"AuthServer" | **Yes** (clean ≡ raw scaffold) |
| if this/param_1==0 return -1 | **Yes** (clean ≡ raw scaffold) |
| callback on listener if set | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. Exact callback slot and full payload field list
2. Relationship to Client_RecvLoginOk +0x50/+0x54

**Verdict:** **accept-with-gaps**
