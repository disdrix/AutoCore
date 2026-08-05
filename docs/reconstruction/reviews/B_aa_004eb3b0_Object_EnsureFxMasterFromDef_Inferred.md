# Review B (skeptical / adversarial): `aa_004eb3b0` Object_EnsureFxMasterFromDef_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004eb3b0` |
| **VA** | `0x004eb3b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra) |
| **Counterpart** | `reviews/A_aa_004eb3b0_Object_EnsureFxMasterFromDef_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always reloads XML | No cache | **Falsified** — early out when `+0x88 != 0` |
| 2 | Same as full `Clonebase_EnsureDefLoaded` | Similar name path | **Distinct** — only attaches FX master catalog; no critical section / def materialize / phy reload |
| 3 | `+0x88` is NDSpecialFX* (`0x240`) | FX-related | **Falsified as 0x240 object** — `operator_new(8)` + map ctor; FX instances come later via `004a16d0`/`004a0b90` |
| 4 | Free function | Many xrefs | **Falsified** — ECX `this` |
| 5 | Sentinel `def != -0x316` is magic type id | weird constant | **Explained** — prevents `def+0x316 == 0` null deref pattern |
| 6 | Product name known | scaffold | **Holds as false** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Lazy `+0x88` ensure | **High** | Double load / leak |
| Def name → LoadMasterFromXML | **High** | Wrong asset wire |
| Host size 8 | **High** | Over-free |
| Event-map readiness for `004a16d0` | **Probable** | Event FX silent miss |
| Owning C++ type name | **Tentative** | Folder only |

---

## 3. Cross-check against raw / live

```
if (obj[+0x88] || !def || def==-0x316) return-ish
if (name shorts at def+0x316/+0x318 empty) return
obj[+0x88] = new_catalog_or_null
if catalog: LoadMasterFromXML(catalog, name_from_def)
```

Live ≡ raw ≡ clean. Consumer `004ec010`: ensure → if `+0x88` then `004a16d0(eventId,1,-1)`.

---

## 4. Surviving contract for AutoCore

```
Object_EnsureFxMasterFromDef_Inferred(obj);
// Post: obj[+0x88] may still be 0 if no def name
// Post: if non-null, catalog ready for event variant load
```

---

## 5. Open questions

1. LoadMasterFromXML error → empty catalog vs null host.
2. Relationship to explicit `"%S_nfx.xml"` path in EnsureDefLoaded (parallel attach paths).

**Verdict:** **accept-with-gaps**
