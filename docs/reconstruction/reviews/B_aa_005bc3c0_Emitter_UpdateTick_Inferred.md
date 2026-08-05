# Review B (skeptical / adversarial): `Emitter_UpdateTick_Inferred` / `FUN_005bc3c0` @ `0x005bc3c0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bc3c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W28-I) |
| **Counterpart** | `reviews/A_aa_005bc3c0_Emitter_UpdateTick_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is only interval spawn (`FUN_005bc120`) | **Falsified** — 6438 B parent; spawn is late child when list empty |
| 2 | Always keeps emitter | **Falsified** — early path returns **0** (HostTick removes) |
| 3 | Plain RET / 0 stack cleanup | **Falsified** — `ret 0x0C` (3 stack args) |
| 4 | Multiple HostTick-class callers | **Falsified** — single xref `FUN_004b8ed0` |
| 5 | `g_flLevelUpUiBase_Inferred` is UI scalar | **Falsified in this use** — bytes **2.0f** quat factor (known misnomer) |
| 6 | Clean staged model is bit-exact port | **Partially overstated** — raw decompile is authority for full math; staged clean seals ABI/stages |
| 7 | Product name retail | **Overstated** — `_Inferred` |
| 8 | Runtime verified | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Keep polarity 0/1 | **High** | HostTick leaks or drops emitters |
| ret 0x0C ABI | **High** | Stack corruption |
| Interval child call site | **High** | Spawn never/always fires |
| Pose-branch completeness | **Medium** | Wrong world basis for some attach modes |
| Product English | **Medium** | Docs only |
| Runtime | **Open** | Matrix |

---

## 3. Cross-check against raw + bytes

```
tick++; global_counter++
optional object-death snapshot
if stop_flag: clear; return 1
countdown -= dt; if countdown > 0: return 1
if early_kill: return 0
… pose refresh / motion …
if interval_mode && *list==0: Emitter_SpawnOnIntervalTick
clear first_frame; return 1
```

Entry SEH + align. Exit `8B E5 5D C2 0C 00`. HostTick: push camera, field_2c, dt; `mov ecx,payload`; call; `test al,al; jz remove`.

---

## 4. Surviving contract for AutoCore

```
// ECX = emitter payload from FX list +0x1E0
// stack (float* dt, int host+0x2c, int camera/world); ret 0x0C
// return 0 → HostTick unlinks + FUN_005be310; 1 → SlotListTick
// MUST preserve countdown early-out and early-kill return 0
// Interval spawn is child 0x005bc120 — do not fold into this unit alone
// Quat factor is 2.0f (not a UI base)
```

Do not port staged clean alone for bit-exact pose math — use raw decompile.

---

## 5. Verdict

Adversarial pass **confirms** A with residual gaps on full pose-expression port and product English → **accept-with-gaps**.
