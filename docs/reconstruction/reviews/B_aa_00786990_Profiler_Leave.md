# Review B (skeptical / adversarial): `aa_00786990` Profiler_Leave

| Field | Value |
|---|---|
| **Stable ID** | `aa_00786990` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00786990_Profiler_Leave.md` |
| **Verdict** | **accept-with-gaps** on CF; scaffold “mission helper” reading **falsified** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function is mission-search business logic | Body only gates flag, QPC, parent pop; SearchAutoMissions is a **caller**, not domain | **Falsified** as mission logic |
| 2 | `param_1` / ECX is `CVOGCharacter*` | Sites always `MOV ECX,[0x00afa27c]` before call; character in Search is `EBP` | **Falsified** |
| 3 | Always mutates state | `CMP [this+0x175],0` / `JZ` return | **Falsified** unconditional mutate |
| 4 | `FUN_00780690` takes explicit formals | Assembly sets **ESI** = `[node+4]` then call; no stack args | **Falsified** decompiler-only “void()” without ESI note |
| 5 | Leave uses only last sample `timer+0x24` for hierarchical total | Leave reloads accum `@+8/+c` and divisor `@+10/+14` into `__alldiv`, **not** `+0x24` | **Falsified** last-sample-only |
| 6 | Always restores parent / always clears current | Parent null → **skip** slot write; current can remain | **Falsified** always-pop |
| 7 | `__fastcall` two register formals | Single ECX this; `RET` 0 | **Overstated** if read as two-arg fastcall |
| 8 | Thunk `0x00480160` is independent logic | `MOV ECX,[DAT]; JMP Leave` only | **Falsified** as separate body |
| 9 | Scaffold clean “profile / zone leave” without stack model | Paired enter `0x00786a00` name-push + leave parent-pop = **scope stack** | **Overstated** as generic “zone” without enter pair |
| 10 | `node+0x28` is the same field as timer max `@+0x28` | Timer max is on **timer block**; hierarchical total is on **node** | **Falsified** conflation if offsets not qualified |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Enable gate + ECX global | **High** | Wrong this in port → AV |
| Slot stride 0xC / current +8 | **High** | Corrupt wrong thread’s stack |
| ESI timer before accumulate | **High** | Silent wrong stats / crash |
| Hierarchical += scaled accum | **High** | Wrong aggregate metrics |
| Parent-null skip restore | **High** | Over-pop or sticky current |
| Mission path independence | **High** | Wasted port effort on profiler |
| Divisor unit / QPF identity | **Low–Med** | Wrong time scale if interpreting totals |
| Product type names | **Low** | Naming only |
| Full thread-create path in `FUN_007866e0` | **Med** (other unit) | First leave on new thread |

---

## 3. Cross-check against live decompile + assembly (2026-07-29)

Decompiler CF matches raw scaffold **and** full assembly (no hidden branches). Critical decompiler gaps closed by asm:

| Decompiler artifact | Asm seal |
|---|---|
| `unaff_ESI` in `FUN_00780690` | Leave sets `ESI = [node+4]` |
| Order: accumulate then `__alldiv` then `+0x28` | Instruction order at `0x007869b4`–`0x007869d1` |
| Second `FUN_007866e0` only on parent≠0 | `TEST EDI / JZ epilogue` |

**SearchAutoMissions framing (caller, not body):**

```
enter:  ECX=[DAT_00afa27c]; PUSH "CVOGCharacter::SearchAutoMissions"; CALL 0x00786a00
leave:  ECX=[DAT_00afa27c]; CALL 0x00786990   // early null-wrapper AND normal exit
```

String @ `0x009cff4c` confirmed via `read_memory`.

---

## 4. Surviving contract for AutoCore

```
// Do not port into mission-progression unless hosting a real profiler UI.
// Correct semantic: Profiler_Leave / scope pop on g_profiler.

if (g_profiler.enabled) {          // byte +0x175
  // stop current named scope; add scaled time to node hierarchical total;
  // pop parent into TLS slot current
}
// Mission auto-grant CF is independent of this side effect.
```

**Falsified port mistakes:**

- Treating Leave as part of GiveMission / Requirements.
- Passing character* as ECX.
- Clearing current even when parent is null.
- Using timer last-sample field instead of accum/div for `node+0x28`.

---

## 5. Open questions (residual only)

1. Exact product name / class of `DAT_00afa27c` manager.
2. Divisor initialization (QPF vs fixed scale).
3. Whether root scope parent is always non-null after first enter.
4. Relationship to alternate profiler pair `FUN_0076cf00` / `FUN_0076cef0` (physics strings) — **different VA family**.
5. Runtime capture of nested enter/leave depth under SearchAutoMissions.

**Verdict:** **accept-with-gaps** — CF sealed; domain is **profiler leave**, not SearchAutoMissions logic. Scaffold dual was missing; A/B now present.
