# Review B (skeptical / adversarial): `aa_004c4dd0` Combat_ComputeBaseCritChance_FromHost

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4dd0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W23-K) |
| **Counterpart** | `reviews/A_aa_004c4dd0_Combat_ComputeBaseCritChance_FromHost.md` |
| **Scratch** | `tmp/a_004c4dd0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler `extraout_ST0` is raw level | **Overstated** — first `FMUL 0.001` already applied; closed form still `(score+level)*0.001*0.125+0.02` |
| 2 | Only one scale factor vs no-bind path | **Confirmed difference** — bind uses 0.125+0.02; no-bind uses 0.25+0.05 |
| 3 | This is the Combat skill (Fighting) formula | **Falsified** — UI places under Perception / Base Critical Hit Chance; prior auto-name wrong |
| 4 | Returns percent 0–100 | **Falsified** — fraction; UI multiplies by display scale (`DAT_00aaa7ac`) |
| 5 | FUN_004c41c0 is free-standing level | **Falsified** — perception-capped composite with gate; not owned fully |
| 6 | cdecl / stack args | **Falsified** — ECX host, no stack formals, ST0 out |
| 7 | Formula needs runtime | **Partial** — image constants sealed; live roll not run |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Closed-form chance | **High** | Wrong crit rates |
| Constants 0.001 / 0.125 / 0.02 | **High** | Same |
| ABI ECX + ST0 | **High** | Calling convention bug |
| UI Base Crit label | **High** | Mis-name only if wrong |
| Bind-path role vs no-bind | **High** | Wrong branch in port |
| Host type English | **Medium** | Naming only |
| Callee depth | **Open** | Residual |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
host=ECX
level = vcall(mi, +0x27c)
score = FUN_004c41c0(host)
return (score + level) * 0.001 * 0.125 + 0.02
```

Live decompile ≡ raw. FPU order matches algebraic closed form. Parent W22-A left this formula open — now sealed.

---

## 4. Surviving contract for AutoCore

```
// Bind-path base crit chance (fraction)
if (attacker.bind) chance = Combat_ComputeBaseCritChance_FromHost(bind);
else chance = level * 0.001f * 0.25f + 0.05f;
// then +attacker bonus -target resist; floor 0.05
// DO NOT use 0.25/0.05 scale on bind path
```

---

## 5. Verdict

Adversarial pass **confirms** A: formula/ABI/UI sealed; residual is host/callee English only → **accept**.
