# Review B (skeptical / adversarial): `aa_00519280` MaterialList_SeedDefaultDiffuseAmbientEmissive_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00519280` |
| **VA** | `0x00519280` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY dual B — WQ9R-E) |
| **Counterpart** | `reviews/A_aa_00519280_MaterialList_SeedDefaultDiffuseAmbientEmissive_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is a skill-bank cast helper | WQ-009 residual label | **Falsified as cast** — pure Mat* effect param seed; no skill id / cast / validate |
| 2 | Only 2 formals | Ghidra sig | **Falsified** — callers pass color float4; `009700f0` reads stack+0x0C |
| 3 | Always overwrites existing bank | no gate in body | **Caller-gated** — `0051b2a0` only invokes when bank empty; body itself does not check emptiness |
| 4 | Default is white `{1,1,1,1}` | typical mat default | **Falsified** — `{0,0,0,1}` (black RGB, alpha 1) |
| 5 | `FUN_00608720` is skill resolve | name unknown | **Falsified** — copies N float4 dwords (`param_1[0..3]=param_3[0..3]`) |
| 6 | Ghidra void return is wrong | return_type_warning | **Holds void** — no meaningful EAX; pure side-effect |
| 7 | Product name known | scaffold | **Holds as false** — `_Inferred` from strings |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Triple Mat* string path | **Confirmed** | Wrong FX params |
| Float4 push stride 0x10 | **High** | Bank corruption |
| Caller float4 apply | **High** | Wrong tint |
| Skill-domain membership | **Low** | Mis-filed under skills residual (nested of object path, not cast) |
| `0051def0` head semantics | **Tentative** | Missed clear/resize |

---

## 3. Cross-check against raw / live

```
default = {0,0,0,1}
// optional vector resize (0051def0) — residual this
for each material index in src pointer count:
  bind+push MatDiffuse default
  bind+push MatAmbient default
  bind+push MatEmissive default
  apply caller float4 to all three Mat*
```

Live ≡ raw ≡ clean CF. Strings and `g_flOne` sealed by `read_memory`.

---

## 4. Surviving contract for AutoCore

```
// When host material color bank empty:
MaterialList_SeedDefaultDiffuseAmbientEmissive_Inferred(
    materialOwner,   // +0xC0/+0xC4 void* range
    &host->vecAt0x144, // begin @ +0x148
    r, g, b, a);
// Post: bank has 3 * materialCount float4 defaults (then effect shows caller color)
```

---

## 5. Open questions

1. `FUN_0051def0` this pointer / which vector cleared.
2. Per-index material pointer consumption (count-only vs load).
3. Relation to PalTool / `PalToolMaterialNoMap.fx` Mat* family (sibling duals).

**Verdict:** **accept-with-gaps**
