# Review B (skeptical / adversarial): `aa_00578ce0` Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00578ce0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00578ce0_Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred.md` |
| **Agent** | WQ9D-F OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** on behavior/OnEnd role; product name remains Inferred |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is OnHeartBeat / fire tail | **Falsified** — DATA at vtbl **+0x10**; Stop tails +0x10; FireTail is sibling body at different VA |
| 2 | Ends with real `call FUN_005081f0` | **Falsified** — epilogue `E9` tail-jmp; decomp noise |
| 3 | Flag `0x10` increments owner counter | **Falsified** — `80 40 26 FF` dec; FireTail is the ++ side |
| 4 | Flag `0x02` inserts cast binding | **Falsified** — callee is `Skill_ClearCastBindingAndMaybeRestartCd` |
| 5 | `FUN_0051f880` always sets flag 1 | **Falsified** — this path pushes **0**; FireTail pushes 1 |
| 6 | No owner notification | **Falsified** — `vtbl+0x238` with mode 1 + skillId + rank + target |
| 7 | Resolve is free function without host ECX | **Falsified** — bytes load `*(this+0x688)+0xe4e8` into ECX |
| 8 | Product name is retail symbol | **Unproven** — `_Inferred` required |
| 9 | Runtime Confirmed without Launcher | **Rejected** — Terminal false |
| 10 | Only one caller | **Falsified** — multiple CODE wrappers + many DATA vtbl slots |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| OnEnd vtbl+0x10 | **Confirmed** | Wrong lifecycle wiring |
| Cast clear vs insert polarity | **Confirmed** | Double-insert / never-clear cast map |
| owner+0x26 dec | **Confirmed** | Counter desync vs FireTail |
| Tail empty base | **Confirmed** | False SEH/frame assumptions |
| Product English | Inferred | Cosmetic rename only |
| `vtbl+0x238` semantics | High (arity) / open (English) | Port may misname notify |

---

## 3. Cross-check

```
Stop 005081d0:   if !dormant: dormant=1; jmp [vtbl+0x10]  → this unit on skill HB vtbls
FireTail 578b30: flag0x10 ++; flag0x02 insert; f880(1)
This     578ce0: flag0x10 --; flag0x02 clear;  f880(0); clear +0x6b0; notify owner
Empty    5081f0: ret only — tail target
ClearCast 51a700: listed caller FUN_00578ce0 with HB+0x620 / +0x678 TFID
```

**Attack on “mode 1 means destroy object”:** only arity/order sealed from pushes (`1`, skillId, rank, `0`, target, `0,0,0`); product verb open — do not overclaim.

**Attack on “vector clear is optional”:** `FUN_00578ac0` always called after resolve; body has no skip gate before it.

---

## 4. Surviving contract for AutoCore

```
// Skill HB OnEnd shared body:
// 1) client end hook (PTR_FUN_00af31e0)
// 2) resolve target from HB TFID via world+0xe4e8 host
// 3) destroy HB pointer vector @ +0x6b0
// 4) if owner: vtbl+0x238(1, skillId, rank, 0, target, 0,0,0);
//              if flags&0x10: owner+0x26--
// 5) if target: maybe ClearCastBinding (flags&0x02); maybe set +0x6b8=0 (+0x140)
// 6) return (empty base OnEnd)
```

Port notes:
- Pair with FireTail polarity for `0x02` / `0x10` / `FUN_0051f880`.
- Do not skip vector teardown.
- Keep distinct from `CVOGHBBase_EndOrDestroy` (`vtbl+0x18` / `0x005083f0`).

---

## 5. Gaps

1. Product English / MSVC demangle.
2. Owner notify verb.
3. Nested cast-owner type.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**.
