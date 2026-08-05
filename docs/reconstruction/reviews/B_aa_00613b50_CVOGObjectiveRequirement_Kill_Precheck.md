# Review B (skeptical / adversarial): `CVOGObjectiveRequirement_Kill_Precheck` @ `0x00613b50`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00613b50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (residual deepen; prior `2026-07-23`) |
| **Counterpart** | `reviews/A_aa_00613b50_CVOGObjectiveRequirement_Kill_Precheck.md` |
| **Verdict** | **accept-with-gaps** on filter+mutate+Eval contrast; **reject** thin 2026-07-23 dual-use / `+0.0` claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Precheck only gates; never mutates progress | **Falsified** — three store paths (`ADDSS` arg5 ×2 sites; XP `CVTSI2SS`+`ADDSS`) |
| 2 | Always adds +1.0 | **Falsified** — adds **arg5 float** (or XP vcall int→float); no `1.0f` immediate in default path |
| 3 | Decomp default `+ 0.0` is real (no-op credit) | **Falsified** — asm is `ADDSS XMM0, dword ptr [ESP+0x24]` @ `0x00613c6b` / `0x00613dca` |
| 4 | `param_3` is both state pointer and float addend | **Falsified** — **arg2→EBP=state**, **arg5=[ESP+0x24]=addend** (distinct stack slots) |
| 5 | Already-complete kills still count | **Falsified** — vcall Eval (`[vtbl+8]`) early-outs with AL≠0 |
| 6 | `unaff_EBP` is a real recovered local for faction | **Falsified** — decompiler noise; faction load is from **arg1** (`[ESP+0x14]` after frame) |
| 7 | Eval might also increment the slot | **Falsified** — Eval is 10-insn pure compare; zero stores (sibling dual sealed) |
| 8 | FailMission always runs after any successful credit | **Falsified** — vehicle path returns 1 at `0x00613c79` **before** FailMission tail |
| 9 | param_4/arg3 is unused padding | **Falsified** — nonzero rejects all |
| 10 | Cap check uses float@req+0x18 | **Falsified polarity detail** — `CVTSI2SS` from **int** @req+0x18 (same as Eval) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CF skeleton (gates / branches / three mutates / FailMission) | **High** | Wrong kill credit rules |
| Stack ABI (7 args, RET 0x1c, state vs addend split) | **High** | Corrupt progress or mis-call from ports |
| Eval pure-read contrast / same slot formula | **High** | Double-count or missing UI complete |
| Vehicle/faction product English (+0x531/+0x532) | **Probable** | Reject valid kills / credit wrong side |
| arg5 always 1.0f from all callers | **Tentative** | Wrong multi-kill credit math |
| arg6 unused globally (not just this body) | **Medium** | ABI mismatch with other precheck siblings |

---

## 3. Surviving contract for AutoCore

```
// thiscall; 7 stack args; RET 0x1c
Kill_Precheck(req, ctxEntity, state, typeCode, cbidOrFloat, addend, _unused, victim) -> u8:
  if typeCode != 0: return 0
  if Kill_Eval(req, ctxEntity, state): return 0   // pure read of state+4+slot*4

  slot = *(u8*)(req + 8)

  if vehicle_flag(req+0x10):
    // faction/level/bitmask filters on victim (+ ctxEntity faction inequality)
    *(float*)(state + 4 + slot*4) += addend
    return 1                                    // no FailMission

  // direct or type-0xe filters; reject if (float)req.required_i32 <= slot
  if xp_flag(req+0x13) && victim:
    *(float*)(state + 4 + slot*4) += (float)victim.vcall(0x244)
  else:
    *(float*)(state + 4 + slot*4) += addend

  if fail_flag(req+0x1c):
    FailMission(...); return 0
  return 1
```

```
// contrast — pure reader
Kill_Eval(req, /*unused*/, state) -> u8:
  return (*(float*)(state+4+slot*4) >= (float)*(i32*)(req+0x18)) ? 1 : 0
```

---

## 4. Open questions (honest residual)

1. Live kill of mission target → capture arg5 and pre/post slot float.
2. Map req offsets to server ObjectiveRequirementKill field names.
3. Whether any caller ever passes addend ≠ 1.0f.
4. arg6 purpose in the wider precheck dispatcher.

**Verdict:** **accept-with-gaps** — prior thin dual upgraded; decomp aliasing myths rejected; Eval contrast sealed.
