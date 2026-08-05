# Review B (skeptical / adversarial): `aa_0048f370` PalantirEnv_RebuildDefaultLights_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048f370` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-R) |
| **Counterpart** | `reviews/A_aa_0048f370_PalantirEnv_RebuildDefaultLights_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is env **ctor** / phase InitPhases itself | **Falsified** — void bare RET; no water/distort/NDRiver; called *by* InitPhases |
| 2 | Free function / no this | **Falsified** — `8B F1`; all 3 callers set ECX to env |
| 3 | One-shot create only (leaks on re-entry) | **Falsified** — prelude `FUN_0048eb10` destroys `+0x104/+0x108` first |
| 4 | Lights live at `+0xC4` (owned phase slot) | **Falsified** — lights at `+0x108/+0x104`; `+0xC4` only optional notify |
| 5 | Scaffold login-callback callee name is product | **Reject** — structural auto name; evidence is light strings + env slots |
| 6 | First light type string is proven `"Directional"` | **Overstated** — first `FUN_0096e430` has **no** stack string in bytes; type inferred from Direction/Color params only |
| 7 | Return value meaningful | **Falsified** — void; no EAX init |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Env method / rebuild lights | **High** | Mis-owned port |
| ABI bare RET / thiscall | **High** | Stack imbalance |
| Slot map +0x108 / +0x104 / size 0x94 | **High** | Wrong layout |
| Dir seed floats | **High** | Wrong lighting default |
| First light type English | **Medium** | Naming only |
| Product demangle | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against InitPhases (W31-P)

```
// InitPhases prelude (sealed W31-P):
FUN_00756320(env, flag);
FUN_0048f370(env);   // this unit — lights
FUN_0048ed00(env);   // peer — textures
// then water/distort/owned phases...
// Note: +0xC4 owned phase is created AFTER this call on first boot,
// so FUN_005b3520 path is typically cold on first InitPhases.
```

---

## 4. Surviving contract for AutoCore

```
// Port as env method, rebuild-safe:
PalantirEnv_RebuildDefaultLights(env);
// Must: tear +0x104/+0x108 first; alloc 0x94 light hosts
// Must: dir @ +0x108 (Direction/Color); hemi @ +0x104 (Hemispheric/ColorTop/ColorBottom)
// Must NOT: treat as InitPhases or free function
// Keep FUN_0048eb10 / light ctor as separate units
```

---

## 5. Verdict

Adversarial pass confirms A on method role, ABI, rebuild policy, and slot map. Rejects login-callback scaffold name and ctor conflation. First-light type string residual + product demangle → **accept-with-gaps**.
