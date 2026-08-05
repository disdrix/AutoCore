# Review B (skeptical / adversarial): `aa_004cda90` Client_InitPalantirViewBundle_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cda90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-F) |
| **Counterpart** | `reviews/A_aa_004cda90_Client_InitPalantirViewBundle_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is a ctor of the parent itself | **Falsified** — parent in ECX is pre-existing; only three child news; returns 1 not this |
| 2 | Multiple stack formals / stdcall | **Falsified** — bare `C3`; `8B F1` only; analyze locals show register this |
| 3 | Same as Class_009c7a1c_Ctor | **Falsified** — that is callee `FUN_00496f70`; this is the factory that news 0xC8 then calls it |
| 4 | GfxView size wrong / not graphics | **Falsified** — `new(0x150)` + ctor path `gfxView.cpp` / `PalViewBackground.fx` |
| 5 | Always requires desktop object | **Falsified** — `+0xE89C` branch is optional; caller may leave null → fail later on Palantir string path |
| 6 | Product English fully known | **Overstated** — structural `_Inferred` only; parent type open |
| 7 | `FUN_0048fc90` this = parent | **Falsified** — uses `+0xC0` link just written on env (`e894`); ECX is env host |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Three-slot factory role | **High** | Mis-owned port |
| ABI bare RET / return 1 | **High** | Stack imbalance |
| Alloc sizes + store offsets | **High** | Layout corruption |
| GfxView identity | **High** | Wrong subsystem port |
| Parent product type | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against Class_009c7a1c_Ctor (W29-G)

```
// FUN_004cda90 (this VA) sole factory arm for Class_009c7a1c:
//   operator_new(0xC8);
//   FUN_00496f70(parent);   // ret 4 ctor
//   parent+0xE898 = result;
```

Confirms W29-G claim that `00496f70` is **not** a factory — this VA is.

---

## 4. Surviving contract for AutoCore

```
// Port as parent method (ECX = large client/core):
ok = Client_InitPalantirViewBundle(parent); // returns 1
// Must: construct GfxView 0x150, env 0x198, Class_009c7a1c 0xC8
// Must: cross-wire view+4 ↔ env+0xC0 before env phase init
// Must: honor optional +0xE89C desktop wire
// Keep Class_009c7a1c_Ctor / GfxView ctor as separate units
```

---

## 5. Verdict

Adversarial pass confirms A on factory role, ABI, sizes, and callee split. Product name residual → **accept-with-gaps**.
