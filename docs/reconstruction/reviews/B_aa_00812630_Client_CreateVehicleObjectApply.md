# Review B (skeptical / adversarial): `Client_CreateVehicleObjectApply` @ `0x00812630`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00812630` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00812630_Client_CreateVehicleObjectApply.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Spawns without template lookup | **Falsified — GiveItemByCbid** |
| 2 | Always player-owned | **Falsified — +0xa1 gate** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CBID at packet+4 | High | Wrong → protocol/UI mismatch risk |
| GiveItemByCbid creates entity shell | High | Wrong → protocol/UI mismatch risk |
| Possession flag packet+0xa1 | High | Wrong → protocol/UI mismatch risk |
| Client context param_2 +0xe04 parent/world | Medium | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
CreateVehicleObjectApply(pkt, client):
  resolve CBID → object; construct/link into world; if local-possessed apply control hooks
```

---

## 4. Open questions

1. Full create-vehicle packet layout
2. vt slot semantic names
3. Non-vehicle create siblings not reviewed

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
