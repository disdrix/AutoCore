# Review B (skeptical / adversarial): `aa_005d6c60` Client_LocalDiscoveryTick

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d6c60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005d6c60_Client_LocalDiscoveryTick.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Client bits are authoritative persistence | **Falsified by plate** — server UnlockRegion / create path |
| 2 | Always explores every tick | **Overstated** — multiple gates (`+0x7e`, vehicle, `+0x4f1`, already-explored) |
| 3 | OnHeartBeat path still explores | **Falsified** — early return after creature HB |
| 4 | Delay always 5s wall-clock | **Partial** — sets 5000 then RescheduleAfterFire; HB timing infra |
| 5 | Sample uses full XYZ | **Overstated** — SampleExploredAreaId takes X and Z (`*pf`, `pf[2]`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Local explore mark | High | Fog never updates |
| Server authority note | High | Design wrong persistence |
| Gate polarity family | Probable | Explore while wrong mode |
| FUN_005cc630 | Tentative | Always/never HB divert |

---

## 3. Cross-check against raw

Clean is scaffold of raw. Cross-link RecvUnlockRegion: server can create empty unlock then apply bits; this tick only sets bits when area newly sampled.

---

## 4. Surviving contract for AutoCore

```
LocalDiscoveryTick(hb, ctx) every ~5s:
  if mode(FUN_005cc630): OnHeartBeat; return
  if local-sim gates pass:
    area = SampleExploredAreaId(terrain, x, z)
    if !IsAreaExplored(char, continent, area): SetAreaExploredBit(...,1)
  this.delay = 5000; RescheduleAfterFire
Persistence: server UnlockRegion / character create — do not trust client-only.
```

---

## 5. Open questions

1. Does client ever send discovery C2S each bit set?
2. FUN_005cc630 product name.
3. Relation to RelockContinentObject.
4. Multi-continent sampling edge cases.

**Verdict:** Local fog sampler sealed; authority boundary emphasized.
