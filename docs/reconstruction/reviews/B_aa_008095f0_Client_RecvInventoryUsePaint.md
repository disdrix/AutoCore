# Review B (skeptical / adversarial): `aa_008095f0` Client_RecvInventoryUsePaint

| Field | Value |
|---|---|
| **Stable ID** | `aa_008095f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_008095f0_Client_RecvInventoryUsePaint.md` |
| **Verdict** | **needs-more-evidence** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Name proves inventory-use paint only | **Working** — body is vehicle paint apply; inventory coupling external |
| 2 | Path 0/1 are the only paint channels | **CF holds for switch**; other packet values ignored |
| 3 | Clean body vcall complete | **Incomplete** — width notes / stubs |
| 4 | Opcode sealed | **Fail** — not in body |

---

## 2. Surviving contract

```
obj = ResolveTFID(pkt+0x10); require vehicle type 0x0E + body
if path@+0x21==0: paintA(color) else if ==1: paintB(color)
if obj==local vehicle: local refresh
terminal refresh
```

**Verdict:** Specialty paint CF only; not core transfer path.
