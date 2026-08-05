# Review B (skeptical / adversarial): `aa_004a16d0` FxMaster_LoadEventVariant_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a16d0` |
| **VA** | `0x004a16d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra) |
| **Counterpart** | `reviews/A_aa_004a16d0_FxMaster_LoadEventVariant_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Free-form string FX play | name formatting | **Falsified** — int map key + `"%s_FOR_EVENT_%d"`; consumers pass small event codes |
| 2 | Same as `NDSpecialFX_LoadFromScriptName` | both call `004a0b90` | **Distinct** — LoadFromScriptName opens XML from disk; this clones from in-memory catalog template |
| 3 | `this` is the 0x240 FX object | thiscall | **Falsified** — `*this` is map; 8-byte catalog host from `004a1620` |
| 4 | Always writes `+0x230` | slot param | **Falsified** — only when `0 ≤ slot < 5`; `004ec010` passes `-1` |
| 5 | Level-up exclusive | scaffold name | **Falsified** — weapon fire / equip / load callers dominate |
| 6 | Product name known | format string only | **Holds as false** — `_Inferred` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Event-id → named variant | **High** | Wrong combat FX |
| Template `+0xD5` name | **High** | Bad snprintf base |
| Catalog host ≠ FX instance | **High** | Type confusion |
| Return EAX = FX\* | **Probable** | Silent null mishandle |
| Slot field `+0x230` English | **Tentative** | Cosmetic channel |

---

## 3. Cross-check against raw / live

```
map = *catalogHost
it = lower_bound(map, eventId)
if it == end: return
tmpl = it.value@+0x10
name = snprintf("%s_FOR_EVENT_%d", tmpl+0xD5, eventId)
fx = FUN_004a0b90(tmpl, name, mode, -1, 0)
if fx && 0<=slot<5: fx[+0x230]=slot
```

Live ≡ raw ≡ clean. Chain: `004eb3b0` ensure catalog → this → `004a0b90` instance.

---

## 4. Surviving contract for AutoCore

```
// Typical weapon event:
Object_EnsureFxMasterFromDef_Inferred(obj);
FxMaster_LoadEventVariant_Inferred(obj->fxMaster@+0x88, eventId, 1, -1);
// Miss if map lacks eventId or master null
```

---

## 5. Open questions

1. Confirm EAX return with call-site mov.
2. Who owns / activates the returned FX (attach host, `004b8dc0`, etc.).
3. Map population keys from LoadMasterFromXML.

**Verdict:** **accept-with-gaps**
