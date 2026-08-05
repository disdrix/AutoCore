# Review B (skeptical / adversarial): `aa_0054b2c0` SkillDefMap_EnsureInitialized

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054b2c0` |
| **VA** | `0x0054b2c0` |
| **Canonical name** | `SkillDefMap_EnsureInitialized` (INFERRED) |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0054b2c0_SkillDefMap_EnsureInitialized.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is `VOG_DEBUG_STOP` implementation | String is **failure log** only (`FUN_007a4480`) | **Falsified** as purpose |
| 2 | Per-skill cast helper | Global once-flag + map clear/load | **Falsified** |
| 3 | Always loads skill rows | Mode `DAT_00b04694 != 0` tears down vector path instead | **Falsified** single-path load claim |
| 4 | `DAT_00b04724` stays 0 until success | Set to **1 at entry** before load completes | **Attack succeeds on “only on success”** — flag is eager |
| 5 | Alias “Named_VOG_DEBUG_STOP” is product API | String-evidence scaffold only | **Agree rename** for dual |
| 6 | Safe to call freely mid-cast | Clears entire map + rebuilds / frees | **Risk confirmed** — once-init / reload only |
| 7 | Parent plate “init if not set” is wrong | Callers gate on `DAT_00b04724==0` | **Attack fails** — lazy call pattern sealed |
| 8 | Noreturn delete paths always abort process | Decompiler warning only | **Open** — do not seal as always fatal |
| 9 | Full skill element schema owned here | Install delegated to `0054a290` | **Agree** ownership boundary |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Once flag `DAT_00b04724` | **Confirmed** | Double-init storms / skip-init |
| Eager flag set before load finish | **Confirmed** | Partial init if load fails mid-body |
| Map head clear protocol | **Confirmed** | Corrupt tree if half-applied |
| Stride `0x934` | **Confirmed** | Skip/overlap records |
| Mode dual-path | **Confirmed** | Port only load path → wrong teardown |
| Load format / `007e34b0` | **Open** | Wrong data source |
| Mode flag product meaning | **Open** | Wrong branch in AutoCore |

---

## 3. Cross-check against raw / live

```
raw ≡ live decompile 2026-07-29.
callers: CVOGReaction_ResolveSkillTargets, FUN_0054b480, Skill_EvaluateRankedElements
globals: DAT_00b04724/34/38/3c, DAT_00b04694, DAT_00b0435c/60/64
string: VOG_DEBUG_STOP on iVar2 < 0 after FUN_007e34b0
epilogue: add esp, 0x30; ret
```

### Eager-flag trap

Do **not** assume failed load leaves `DAT_00b04724==0` for retry. Body sets **1** immediately after SEH setup. Retry policy is product-open.

### Mode trap

Porting only the `0x934` loop without `DAT_00b04694` branch is incomplete.

### Ownership trap

Row materialization lives in **`FUN_0054a290`** (elements string, map insert via `00418890` / `0054ea60`). This unit **orchestrates**, not fully defines skill rows.

---

## 4. Surviving contract for AutoCore

```
void EnsureSkillDefMapInitialized() {
  // callers only when g_skillDefMapInited == 0
  g_skillDefMapInited = 1;           // DAT_00b04724 — eager
  SubInitA(); SubInitB();            // 0054a1a0 / 0054a640
  if (!g_skillDefModeAlt) {          // DAT_00b04694
    ClearMap(g_skillDefEnd);         // DAT_00b04738 self-links; size 0
    if (LoadTable(buf) < 0) Log("VOG_DEBUG_STOP");
    else for each record stride 0x934:
      InstallSkillRow(rec);          // 0054a290
      free(*(void**)(rec+0x930));
  } else {
    FreeAltVector(DAT_00b0435c..);   // product-open
  }
}
```

---

## 5. Open questions

1. `DAT_00b04694` product semantics.
2. Source path for `FUN_007e34b0`.
3. Fail/retry policy after eager flag.
4. Runtime verification.

**Verdict:** **accept-with-gaps**
