# Review A (reconstruction fidelity): `aa_008223e0` Auth_Setup_of_CNDAuthClient_failed

| Field | Value |
|---|---|
| **Stable ID** | `aa_008223e0` |
| **VA** | `0x008223e0` |
| **Canonical name** | `Auth_Setup_of_CNDAuthClient_failed` |
| **System** | auth |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008223e0_Auth_Setup_of_CNDAuthClient_failed.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_008223e0_*.md` (or FUN_ twin) |
| Clean | `docs/reconstruction/reconstructed-exact/Auth_Setup_of_CNDAuthClient_failed.cpp` |
| String / plate evidence | From clean header + body |

---

## 2. Purpose (from unit)

CNDAuthClient-like object initializer (string-driven name from failure path only): set vtbl chain PTR_FUN_00aa7420 then PTR_FUN_00a76344; zero fields; byte flags; FUN_00417210(0,0,0,0,0); param_1[0x13]=6; if FUN_007299e0()<0 then OutputDebugStringA('Setup of CNDAuthClient failed!') + FUN_007a4480(0,'VOG_DEBUG_STOP'). Returns param_1. Constructor/init with hard-fail branch — not a pure error dialog.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Failure string Setup of CNDAuthClient failed! | **High** | OutputDebugStringA |
| VOG_DEBUG_STOP on failure | **High** | FUN_007a4480 |
| vtbl installs + field zeroing before probe | **High** | body order |
| FUN_007299e0() < 0 triggers fail path | **High** | if |
| param_1[0x13] = 6 (mode/state?) | **High** | store |
| FUN_00417210 five zero args | **Medium** | callee open |
| Name overstates — whole function is setup, not only fail | **High** | skeptical plate |
| Control flow preserved clean ≡ raw scaffold | **High** | No modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| EH → vtbl/fields init → FUN_00417210 → more zeros → probe → optional fail → return this | **Yes** |
| Success path returns param_1 without debug string | **Yes** |

---

## 5. Gaps

1. FUN_007299e0 is actual CNDAuthClient setup? open.
2. FUN_00417210 purpose open (named callee-of in function records).
3. Full object layout beyond observed stores open.
4. Address-suffixed twin same VA.

**Verdict:** **accept-with-gaps**
