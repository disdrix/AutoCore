# Review B (skeptical / adversarial): `Client_RecvDestroyObject` @ `0x008149c0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008149c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_008149c0_Client_RecvDestroyObject.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always no-ops without connection | **Falsified — local vehicle TFID path** |
| 2 | Uses only object id u32 | **Falsified — 64-bit TFID pair** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| TFID pair at packet+8/+0xc | High | Wrong → protocol/UI mismatch risk |
| ResolveObjectTarget named | High | Wrong → protocol/UI mismatch risk |
| Local vehicle TFID compare path | High | Wrong → protocol/UI mismatch risk |
| in_EAX client context | Medium | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
RecvDestroyObject(pkt):
  resolve object by TFID; destroy; special-case if matches local driven vehicle ids
```

---

## 4. Open questions

1. Destroy cascade full callees
2. packet+0x10 type byte meaning
3. FUN_00802170 identity

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
