# Review B (skeptical / adversarial): `aa_0048fc90` PalantirEnv_InitPhases_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048fc90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-P) |
| **Counterpart** | `reviews/A_aa_0048fc90_PalantirEnv_InitPhases_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the env **ctor** | **Falsified** — factory already ran `FUN_00492dd0`; this is post-wire method; returns 0 not this |
| 2 | This == parent factory / runs on client parent | **Falsified** — ECX from `[parent+0xE894]`; uses env `+0xB8/+0xC0` |
| 3 | Name = Drive_NDRiver_fx only | **Overstated/reject** — NDRiver is tail; water+distort+three owned phases dominate body |
| 4 | Water/distort recreated every call | **Falsified** — gated on global null; process singletons |
| 5 | Owned phases use view like water | **Falsified** — water/distort take `+0xC0` view; owned three take `+0xB8` parent |
| 6 | Bare RET / no stack formal | **Falsified** — `RET 4`; factory `push 1` |
| 7 | Product phase English fully known | **Overstated** — strings seal water/distort labels only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Env method / phase bootstrap | **High** | Mis-owned port |
| ABI RET 4 / return 0 | **High** | Stack imbalance |
| Singleton vs owned split | **High** | Double-init / wrong lifetime |
| View vs parent ctor args | **High** | Wrong dependency |
| Flag product meaning | **Medium** | Wrong enable path |
| Product demangle | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against factory (W30-F) + ctor peer

```
// Must run AFTER:
//   env = ctor(new(0x198), 0, parent)
//   view+4 = env; env+0xC0 = view
// Then:
//   FUN_0048fc90(env, 1)
// Water ctor needs view@+0xC0 — factory order is mandatory.
```

---

## 4. Surviving contract for AutoCore

```
// Port as env method, not free-standing NDRiver loader:
ok0 = PalantirEnv_InitPhases(env, /*flag*/1); // returns 0
// Must: require env+0xC0 view wired; env+0xB8 parent set by ctor
// Must: water/distort once globally; three owned every call
// Must NOT: treat as env ctor or parent method
// Keep phase ctors as separate units
```

---

## 5. Verdict

Adversarial pass confirms A on method role, ABI, singleton policy, and arg split. Rejects Drive_NDRiver_fx as full name. Product residual → **accept-with-gaps**.
