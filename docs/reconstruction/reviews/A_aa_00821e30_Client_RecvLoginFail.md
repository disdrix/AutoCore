# Review A (reconstruction fidelity): `aa_00821e30` Client_RecvLoginFail

| Field | Value |
|---|---|
| **Stable ID** | `aa_00821e30` |
| **VA** | `0x00821e30` |
| **Canonical name** | `Client_RecvLoginFail` |
| **System** | auth-login-ui |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00821e30_Client_RecvLoginFail.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00821e30_Client_RecvLoginFail.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_00821e30_Client_RecvLoginFail.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvLoginFail.cpp` |
| String evidence | `multiple login fail user strings` |

---

## 2. Purpose (from unit)

LoginFail UI: switch on fail code for message strings; reset UI controls; toast.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Multi-case fail code switch | **High** |  |
| Some codes Sleep(0x5dc) then retry FUN_00729940 | **High** | 1500ms |
| User-visible strings via toast | **High** |  |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| switch fail codes (cases include 7,0xd,0xe sleep/retry; default toast) | **Yes** (clean ≡ raw scaffold) |
| UI field reset via vt calls on login widgets | **Yes** (clean ≡ raw scaffold) |
| FUN_007fdfb0 toast helper | **Yes** (clean ≡ raw scaffold) |
| vt+0x34c finalize | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. Complete case→string map (large switch)
2. Exact widget indices 0x164/0x165

**Verdict:** **accept-with-gaps**
