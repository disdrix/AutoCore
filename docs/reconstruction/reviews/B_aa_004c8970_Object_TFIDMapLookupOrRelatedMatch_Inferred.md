# Review B (skeptical / adversarial): `aa_004c8970` Object_TFIDMapLookupOrRelatedMatch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c8970` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-T) |
| **Counterpart** | `reviews/A_aa_004c8970_Object_TFIDMapLookupOrRelatedMatch_Inferred.md` |
| **Scratch** | `docs/reconstruction/tmp/a_004c8970.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Pure bool predicate always 0/1 | **Falsified** — map hit returns `*(node+0x20)` (payload may be any non-zero) |
| 2 | Stack only 3 args (decompiler) | **Falsified** — `RET 0x10` = 16 B TFID; caller pushes 4 dwords from owner `+0x228` |
| 3 | `FUN_004cb4b0` free function on TFID only | **Falsified** — ECX = `self+0x154` map object |
| 4 | Same as `TFID_EqualsObjectId` | **Falsified** — map lookup + related gate; Equals only on miss subpath |
| 5 | Many callers | **Falsified** — sole code xref engage `005ccff0` |
| 6 | Product plate name sealed | **Overstated** — structural `_Inferred` only |
| 7 | cdecl | **Falsified** — thiscall `RET 0x10` |
| 8 | Map head at +0x154 | **Falsified** — map object +0x154; head/sentinel +0x158 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall RET 0x10 | **High** | ABI break |
| Map @ +0x154 / head +0x158 | **High** | Wrong container |
| Hit → +0x20 payload | **High** | Wrong return |
| Miss related @ MI+0xA4 | **High** | Gate false negative |
| Product English | **Open** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
thiscall Object_TFIDMapLookupOrRelatedMatch_Inferred(self, tfid[4 dwords])
  node = lower_bound(self+0x154, &tfidLo)
  if end or key < node.key → miss
  miss: related@MI+0xA4 match → 1; else vtbl+0x214 + TFID_Equals → 1/0
  hit:  return *(node+0x20)
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Map-this and RET 0x10 residuals closed by `read_memory`.

---

## 4. Surviving contract for AutoCore

```
// Engage gate (not pure Equals):
// - this = creature/object owning TFID map at +0x154
// - pass owner TFID 16 B by value (4 stack dwords); RET 0x10
// - non-zero means "mapped or related match" → skip LinkedDeath retarget
// - do not treat hit payload as bool-only; preserve node+0x20 value
// - do not merge with TFID_EqualsObjectId leaf
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/map/caller sealed; product English residual → **accept-with-gaps**.
