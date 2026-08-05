# Review A (reconstruction fidelity): `aa_008c92b0` Auth_Client_RequireAccountName

| Field | Value |
|---|---|
| **Stable ID** | `aa_008c92b0` |
| **VA** | `0x008c92b0` |
| **Canonical name** | `Auth_Client_RequireAccountName` |
| **System** | auth-login |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008c92b0_Auth_Client_RequireAccountName.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_008c92b0_*.md` (or FUN_ twin) |
| Clean | `docs/reconstruction/reconstructed-exact/Auth_Client_RequireAccountName.cpp` |
| String / plate evidence | From clean header + body |

---

## 2. Purpose (from unit)

Login-form gate: if account-name widget at unaff_ESI+0x590 is non-null and vtbl+0x1dc text is non-empty, return 1 (ok). Else show toast 'You need to specify your Account Name!' via FUN_007a69d0/FUN_007a6de0/FUN_007fdfb0(&DAT_00d1a840,...) and return 0. Blocks login proceed when empty.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| String 'You need to specify your Account Name!' | **High** | Literal |
| Return 1 only when text non-empty | **High** | early return 1 |
| Else toast path then return 0 | **High** | fallthrough |
| Widget pointer at +0x590 | **High** | null check before vtbl |
| Text via vtbl+0x1dc (called twice) | **High** | decomp pattern |
| unaff_ESI is login dialog / form this | **Medium** | register; not formal param |
| Control flow preserved clean ≡ raw scaffold | **High** | No modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| if widget → get text → empty? fail toast : return 1; always 0 on miss | **Yes** |
| No network send in this unit | **Yes** |

---

## 5. Gaps

1. unaff_ESI formalization open (thiscall vs lost reg).
2. DAT_00d1a840 toast host identity open.
3. Double vtbl+0x1dc call may be decomp artifact vs two getters.

**Verdict:** **accept-with-gaps**
