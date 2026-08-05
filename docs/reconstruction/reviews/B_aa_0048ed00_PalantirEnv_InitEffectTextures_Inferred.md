# Review B (skeptical / adversarial): `aa_0048ed00` PalantirEnv_InitEffectTextures_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048ed00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-R) |
| **Counterpart** | `reviews/A_aa_0048ed00_PalantirEnv_InitEffectTextures_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This loads NDRiver.fx / is Drive_NDRiver_fx | **Falsified** — no FX path; sole work is dual `FUN_0096f0e0`; NDRiver is **InitPhases** tail |
| 2 | Free function (Ghidra `void FUN(void)` signature) | **Falsified** — `8B F1`; InitPhases sets ECX=env |
| 3 | Decompile shows all formals of `FUN_0096f0e0` | **Partial gap** — decompiler drops thiscall ECX; bytes seal `+0xDC` / `+0xE0` |
| 4 | Creates lights | **Falsified** — peer `0048f370` owns lights; this is textures only |
| 5 | Half dims are floats | **Falsified** — integer `/2` of device width/height |
| 6 | Product texture purpose fully known | **Overstated** — create/bind proven; stage/usage English open |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Env method / dual texture create | **High** | Mis-owned port |
| ABI bare RET / thiscall | **High** | Stack imbalance |
| Slots +0xDC / +0xE0 + related +0xD4 | **High** | Wrong layout |
| format 0x15 = A8R8G8B8 | **High** | Wrong format |
| meaning of 0x4011 | **Medium** | Wrong pool/usage |
| Product slot English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against InitPhases (W31-P)

```
// Must run in InitPhases after lights rebuild:
FUN_0048f370(env);
FUN_0048ed00(env);  // this unit
// Nested ctor already placed object graph at +0xD4 (W31-P ctor peer).
// Related ptr env+0xD4 on first texture call is intentional, not optional noise.
```

---

## 4. Surviving contract for AutoCore

```
// Port as env method after default lights:
PalantirEnv_InitEffectTextures(env);
// Must: full-res texture → +0xDC (related +0xD4); half-res → +0xE0
// Must: format 0x15; pass device dims from *(DAT_00d1f058+0x2c)+0x80
// Must NOT: conflate with NDRiver.fx load or light rebuild
// Keep FUN_0096f0e0 as separate texture helper
```

---

## 5. Verdict

Adversarial pass confirms A on method role, ABI, dual-slot layout, and texture callee. Rejects NDRiver scaffold naming. Residual `0x4011` + product slot English → **accept-with-gaps**.
