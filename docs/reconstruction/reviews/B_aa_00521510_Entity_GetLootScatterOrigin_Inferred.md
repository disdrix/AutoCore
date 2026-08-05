# Review B (skeptical / adversarial): `aa_00521510` Entity_GetLootScatterOrigin_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521510` |
| **VA** | `0x00521510` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00521510_Entity_GetLootScatterOrigin_Inferred.md` |
| **System** | missions-progression / combat death loot placement |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Always calls convoy helper | Only when `+0xcb0 != 0` | **Falsified** |
| 2 | Returns float position XYZ | Packs two dwords; no float ops | **Falsified** as XYZ float |
| 3 | -1 from helper is success | -1 triggers **fallback** pack | **Falsified** as success |
| 4 | `+0xcb0` is HP or health | OnDeath uses same flag for convoy XP split | **Survives as convoy/multi flag** (**Probable**) |
| 5 | Sole caller OnDeath | 4+ static callers | **Falsified** |
| 6 | Offsets absolute from object start | Added to component base from `*(this+4)+4` | **Survives as relative** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Branch + fallback CF | **High** | Wrong scatter parent |
| Packed u32 pair return | **High** | Truncation bugs |
| Convoy flag +0xcb0 | **High** as branch; **Probable** name | |
| Field meaning 0x164/0x168 | **Tentative** | Wrong net identity |
| 00575870 contract | **Open** | Convoy loot mis-parent |

---

## 3. Cross-check

Live ≡ raw/clean. Parent credit path: `uVar16 = FUN_00521510(&fStack_40); FUN_004d2750(amount, &fStack_40, 0x41200000, 1, uVar16);`. Item path stores return at `piVar11[2]+0x170`.

---

## 4. Surviving contract

```
uint64 GetLootScatterOrigin(Entity* e, void* ctx) {
  if (e->convoyFlag_cb0 == 0)
    return Pack(e->field164, e->field168); // via component base
  uint64 v = ResolveConvoyOrigin(e, ctx);  // FUN_00575870
  if (v == (uint64)-1)
    return Pack(e->field164, e->field168);
  return v;
}
// Do not assume float3. Do not skip fallback on -1.
```

---

## 5. What would overturn

1. Evidence packed value is not identity/origin (e.g. pure RNG seed).
2. `+0xcb0` means something other than multi-body/convoy in layout docs.
3. Helper never returns -1 (dead branch).

**Verdict:** **accept-with-gaps.**
