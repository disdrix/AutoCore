# Review B (skeptical / adversarial): `aa_00519200` Skill_StartCastAgainHeartbeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_00519200` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (residual strengthen; prior quality refresh same day) |
| **Counterpart** | `reviews/A_aa_00519200_Skill_StartCastAgainHeartbeat.md` |
| **Verdict** | **accept-with-gaps** |
| **Scratch** | `reviews/a_00519200.md` |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Server skill cooldown authority | Body only alloc/enqueue/Start local HB | **Falsified** — client/sim overlay |
| 2 | No HB list involvement | `Enqueue` + `Start` on `world+0xe4ec` | **Falsified** |
| 3 | Plate formals match body | `RET 0x8` + inverted names; decomp dropped ctor skill arg | **Falsified** — bytes win |
| 4 | Type-8 is tentative naming only | Ctor `C7 46 1C 08 00 00 00` | **Sealed High** as type **8** |
| 5 | Unit dedups / prevents stacking | Always `new(0x28)` — no lookup | **Falsified for this unit** |
| 6 | Charge delay is always skill+0x14 | Clear=**0**; Apply=packet+0x10; LocalRange=skill+**0x10** | **Caller-dependent** (High) |
| 7 | `this` is skill runtime | Callers pass **character/owner entity**; skill is stack0 | **Falsified** |
| 8 | Decomp ctor arity (2 stack) | Ctor `RET 0xC` + 3 pushes | **Falsified** — 3 stack args |
| 9 | Only 4–5 production callers | `get_function_xrefs` lists **6** | **Falsified** undercount — **6 sealed** |
| 10 | Null new aborts enqueue | `je` skips ctor only; Enqueue/Start always | **Falsified** — null HB passed |
| 11 | All entries gated by skill+0x61c | LocalRange miss has **no** `+0x61c` at call | **Falsified** as universal gate |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| World list `*(owner+0xa4)+0xe4ec` | **High** | Lost cast-again / wrong list |
| ABI `(owner, skill, chargeMs)` / `RET 0x8` | **High** | Wrong port call convention |
| Ctor `(hb, owner, skill, charge)` / `RET 0xC` | **High** | Wrong duration/owner wiring |
| Type-8 at HB+0x1c | **High** | Wrong HB class / teardown filters |
| Charge taxonomy (4 sources) | **High** | Early/late re-enable; miss-path CD wrong |
| No in-unit stacking guard | **High** | Double overlay if callers race |
| Null-alloc still Start | **High** | Potential null deref in callees |
| Duration formula | N/A here | Ctor-owned |
| Live stacking / server sync | **Open** | Overlay desync |

---

## 3. Cross-check against raw / bytes

```
// Prior decomp (incomplete ctor call):
ctor(mem, this, (int)pOwnerCtx);

// Bytes-sealed body:
push 0x28; call operator_new
je skip_ctor
  push charge; push skill; push owner; ecx=mem; call 0051e240  // ctor RET 0xC
esi = hb or 0
Enqueue(*( *(owner+0xa4) + 0xe4ec ), esi)
CVOGHBBase_Start(esi)
ret 8
```

Clean CF matches raw decomp control flow; **signature surface must follow bytes**, not Ghidra plate names. Pcode CALL node for ctor under-lists stack formals — same decomp bug as plate.

---

## 4. Surviving contract for AutoCore

```
StartCastAgainHeartbeat(ownerEntity, skillRuntime, chargeDelayMs):
  // client/sim optimistic CD / cast-again timer only — not server authority
  hb = new CVOGHBOKToCastAgain(owner, skill, chargeDelayMs)  // type 8; duration in ctor
  // if new fails: still enqueue+start null (retail body)
  world.HBList[+0xe4ec].Enqueue(hb)
  hb.Start()
  // pair OnStart/OnEnd + category map + ClearCastBinding / Recv failure teardown
```

Port notes:

* Power-plant modifier must be **1.0** identity in **ctor** path; do not invent a second CD HB from `lDelayTime`.
* Charge delay is **not** a single field: port must pass caller-correct ms (0 / +0x14 / packet+0x10 / skill+0x10).
* Do not assume `+0x61c` gates every entry (LocalRange miss does not).

---

## 5. Residual disposition

| Prior / residual gap | Disposition |
|----------------------|-------------|
| Plate formals vs body | **Sealed High** — bytes ABI; plate falsified |
| Type-8 identity | **Sealed High** — ctor `+0x1c = 8` |
| Stacking in this unit | **Sealed:** none (always alloc) |
| Caller set completeness | **Sealed High** — 6 xrefs |
| Charge sources | **Sealed High** — 4 classes |
| Null new path | **Sealed High** — still Enqueue/Start |
| LocalRange flag / live multi-HB | Open (caller / runtime) |
| Runtime / diff / bit-exact | Still open |

**Verdict:** **accept-with-gaps**
