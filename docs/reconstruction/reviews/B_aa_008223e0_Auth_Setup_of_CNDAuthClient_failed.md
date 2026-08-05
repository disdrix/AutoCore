# Review B (skeptical / adversarial): `Auth_Setup_of_CNDAuthClient_failed` @ `0x008223e0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008223e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_008223e0_Auth_Setup_of_CNDAuthClient_failed.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on setup callees |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Function only runs on failure | **Falsified — always inits; fail branch optional** |
| 2 | Shows player-facing login dialog | **Falsified — OutputDebugStringA + VOG_DEBUG_STOP** |
| 3 | Implements AuthServer TCP | **Falsified — client object setup** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Init-then-probe structure | High | Miss success path |
| Failure strings | High | Wrong diagnostics |
| Field [0x13]=6 and byte flags | Medium | Wrong object state |
| FUN_007299e0 semantics | Tentative | May mis-attribute setup root |
| Clean is CF-preserving scaffold | High | Low for map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth/UI layout mistakes |

---

## 3. Cross-check against raw

```
SetupCNDAuthClient(this):
  vtbl = ...; zero fields; flags; FUN_00417210(0..)
  this[0x13] = 6
  if FUN_007299e0() < 0:
    OutputDebugStringA("Setup of CNDAuthClient failed!")
    FUN_007a4480(0, "VOG_DEBUG_STOP")
  return this
```

---

## 4. Surviving contract for AutoCore

```
Auth_Setup_of_CNDAuthClient_failed(param_1):
  client CNDAuthClient init with debug-stop on setup failure;
  rename is string-driven from fail path only.
```

---

## 5. Open questions

1. Rename candidate: CNDAuthClient_Init or similar after FUN_007299e0 sealed.
2. Link FUN_00417210 twin records (aa_00417210).

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on setup callees — safe as behavioral map for AutoCore client auth/login UX; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
