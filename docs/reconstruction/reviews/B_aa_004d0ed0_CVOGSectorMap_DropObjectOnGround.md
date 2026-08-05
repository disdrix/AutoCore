# Review B (skeptical / adversarial): `aa_004d0ed0` CVOGSectorMap_DropObjectOnGround

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d0ed0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004d0ed0_CVOGSectorMap_DropObjectOnGround.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Inventory bag insert | No bag walk; writes world pose + HB | **Falsified** as bag insert |
| 2 | Always starts HB | Gated on `param_5 != 0` | **Falsified** as always-on |
| 3 | Scatters Y | Only X/Z randomized | **Falsified** for Y scatter |
| 4 | Uses `pos[1]` as Y | Reads `pos[0],pos[2],pos[3]`; Y from heightfield | **Survives** — Y rebuilt |
| 5 | Radius scale is 1/65536 | Formula uses **2/65536** then subtract radius | **Falsified** naive unit scale |
| 6 | `DAT_00a0f298` is 1.0 | Memory = `0x3f000000` → **0.5f** | **Falsified** as 1.0 |

---

## 2. Live ≡ raw

Plate string, SEH frame, dual RNG draws, height branch, four float stores, optional new/enqueue/start — match clean scaffold and live decompile.

---

## 3. Surviving contract

```
DropObjectOnGround(map, obj, pos4, radius, hbFlag):
  reject null obj
  (x,z) = scatter(pos.x, pos.z, radius) if radius>0
  y = sampleY(x,z)? + 0.5 : 0.5
  obj.pos = (x,y,z,w); finalize; maybe HB
```

**Verdict:** **accept-with-gaps**.
