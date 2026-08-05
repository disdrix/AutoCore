# Review B (skeptical / adversarial): `aa_00492dd0` PalantirEnv_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00492dd0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-P) |
| **Counterpart** | `reviews/A_aa_00492dd0_PalantirEnv_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is a free function / not a ctor | **Falsified** — returns this; installs vtbl; SEH ctor ladder; factory `new` then call |
| 2 | Zero or one stack formal | **Falsified** — `RET 8`; params at Stack[0x4]/[0x8]; factory `push parent; push 0` |
| 3 | Same as phase init `FUN_0048fc90` | **Falsified** — peer method; this unit never touches water/distort/NDRiver |
| 4 | Object size unknown / not 0x198 | **Falsified** — sole caller `operator_new(0x198)`; highest stores ≤ `+0x194` |
| 5 | Multiple callers | **Falsified** — analyze_function_complete: sole `FUN_004cda90` |
| 6 | Product class fully named | **Overstated** — `_Inferred` only; PalantirEnv is structural from factory slot |
| 7 | Scaffold long Palantir-desk name is product | **Reject** — auto parent-seed chain, not demangle |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Complete ctor role | **High** | Mis-owned port |
| ABI RET 8 / return this | **High** | Stack imbalance |
| Factory store `+0xE894` / size 0x198 | **High** | Layout corruption |
| Parent @ `+0xB8` | **High** | Wrong backlink |
| `FUN_0096ef70` subobject bases | **Medium** | Subobject layout skew |
| Product demangle | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against factory (W30-F)

```
// Client_InitPalantirViewBundle @ 0x004cdb70 region:
//   operator_new(0x198);
//   push parent (esi); push 0; mov ecx, eax; call FUN_00492dd0
//   parent+0xE894 = result
// later: env+0xC0 = view; FUN_0048fc90(env, 1)
```

Confirms this VA is **ctor only**; phases are separate and require post-wire `+0xC0`.

---

## 4. Surviving contract for AutoCore

```
// Port as complete ctor (placement-new style):
env = PalantirEnv_Ctor(raw_0x198, /*arg0*/0, parent);
// Must: vtbl, parent@+0xB8, arg0@+0xBC, RB@+0x190, child@+0x100
// Must NOT: assume view@+0xC0 already set (factory wires after return)
// Must NOT: call water/distort here
// Keep FUN_0044e100 / FUN_00497920 as separate units
```

---

## 5. Verdict

Adversarial pass confirms A on ctor role, ABI, size, and factory split from phase init. Product name residual → **accept-with-gaps**.
