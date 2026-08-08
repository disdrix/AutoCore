# Independent adversarial spot-check — WQ9D skill HB units `0x0061f940` + `0x0061b6f0`

| Field | Value |
|---|---|
| **Date** | `2026-08-04` |
| **Role** | Independent adversarial verifier (**not** WQ9D-B / WQ9D-C dual author) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | WQ9D-B + WQ9D-C important skill HB units (WQ-009 depth residual) |
| **Units** | `0x0061f940` `CVOGHBSkill_Virus_Ctor`; `0x0061b6f0` `CVOGHBSkill_SharedOnHeartBeat_Inferred` |
| **Tools** | Dual/report + A/B + clean/raw/annotated + function records; sibling ADV `ADV_wq009_spotcheck_0040aff0_0061fdf0.md` (Virus OnHB already sealed pulse + child ctor wiring); Ghidra MCP schemas present (`decompile_function`, `read_memory`, callers/xrefs) |
| **Forbidden** | `disassemble_bytes`; parent ledger edits; dual rewrite; Launcher |
| **Image** | `autoassault.exe` base `0x400000` |
| **Terminal** | **false** |

---

## Inspected evidence

### Dual / report surfaces

| Path |
|---|
| `docs/agents/task-dual-ab-0051b5d0-0061f940-wq9db-report.md` (Virus half) |
| `docs/agents/task-dual-ab-0061b6f0-004192a0-wq9dc-report.md` (SharedOnHB half) |
| `docs/reconstruction/reviews/A_aa_0061f940_CVOGHBSkill_Virus_Ctor.md` |
| `docs/reconstruction/reviews/B_aa_0061f940_CVOGHBSkill_Virus_Ctor.md` |
| `docs/reconstruction/reviews/A_aa_0061b6f0_CVOGHBSkill_SharedOnHeartBeat_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_0061b6f0_CVOGHBSkill_SharedOnHeartBeat_Inferred.md` |

### Artifacts (both units)

| Kind | `aa_0061f940` | `aa_0061b6f0` |
|---|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0061f940_FUN_0061f940.md` | `docs/reconstruction/raw/aa_0061b6f0_FUN_0061b6f0.md` |
| Annotated | `…/aa_0061f940_FUN_0061f940.annotated.md` | `…/aa_0061b6f0_FUN_0061b6f0.annotated.md` |
| Clean named | `…/CVOGHBSkill_Virus_Ctor.cpp` | `…/CVOGHBSkill_SharedOnHeartBeat_Inferred.cpp` |
| Clean scaffold | `…/FUN_0061f940.cpp` | `…/FUN_0061b6f0.cpp` |
| Function named | `…/aa_0061f940_CVOGHBSkill_Virus_Ctor.md` | `…/aa_0061b6f0_CVOGHBSkill_SharedOnHeartBeat_Inferred.md` |

### Cross-unit / prior ADV seals used

| Check | Result |
|---|---|
| Sibling ADV Virus OnHB (`0x0061fdf0`) | **Confirmed** RTTI `.?AVCVOGHBSkill_Virus@@`; vtbl `PTR_FUN_009d14bc`; **[+0x08]=`0x005082c0` TryFire**; **[+0x0c]=`0x0061fdf0` OnHB**; pulse **`FUN_0061b6f0` first**; child **`operator_new(0x6e0)` + `FUN_0061f940`** + Enqueue/Start; budget fields **`+0x6d0`/`+0x6d4`** |
| Dual raw Virus ctor live re-verify 2026-08-04 | Body **89 B** / `ret 0x20`; bytes `c706 bc149d00` (vtbl); `8986 d0060000` / `d4060000` (budget/period); sole CALL from OnHB @ `0x0062008d` |
| Dual raw SharedOnHB live re-verify 2026-08-04 | Body **613 B** exclusive end `0x0061b955`; epilogue `add esp,0x18` + **`C2 04 00`**; `DAT_00af4bd0`=**0x10**; **2** CODE callers + **9** DATA vtbl slots; RTTI sample Chain / InverseChain / Aggregate |

---

## Unit A — `0x0061f940` CVOGHBSkill_Virus_Ctor

### Body / ABI / identity seal (independent)

| Claim | Independent result |
|---|---|
| Body `0x0061f940`–`0x0061f998` inclusive (**89 B** / `0x59`) + `CC` pad after `ret 0x20` | **Confirmed** — dual raw re-verify range + size math (`0x998−0x940+1=0x59`) |
| `__thiscall` ECX=this; **8 stack args**; **`ret 0x20`**; EAX=`this` | **Confirmed** — decompile signature + `ret 0x20` = 8×4; clean matches |
| Linear ctor (no branches) | **Confirmed** — raw/clean linear CF |
| `FUN_00618180(p2..p7, 0, 1.0f / 0x3f800000)` intermediate base | **Confirmed** — raw + clean + scaffold twin |
| `this[0x1b4]` / **`+0x6d0`** = remainBudget (param_8) | **Confirmed** — dual byte note `8986 d0060000`; OnHB consumer decrements same |
| `*this = PTR_FUN_009d14bc` Virus vtbl | **Confirmed** — `c706 bc149d00`; sibling ADV vtbl read |
| `this[0x1b5]` / **`+0x6d4`** = remainPeriod then `CVOGHBBase_SetPeriodAndCounter(this, period, true)` | **Confirmed** — raw order: store then SetPeriod |
| RTTI **`.?AVCVOGHBSkill_Virus@@`** (type_info `0x00af2b08`) | **Confirmed** — dual + sibling ADV string @ `0x00af2b10` |
| Vtbl **[+0x0c] = `0x0061fdf0`** OnHeartBeat; **[+0x08] = TryFire `0x005082c0`** | **Confirmed** — dual raw vtbl table + sibling ADV dword @ `009d14c8` |
| Object size **`0x6e0`** | **High** — sole CALL path `operator_new(0x6e0)` in OnHB (sibling dual/ADV) |
| Sole **UNCONDITIONAL_CALL** from Virus OnHB child-spawn | **High** — dual callers table; DATA vtbl uses elsewhere acknowledged as non-CALL |
| Clean named ≡ sealed CF | **Confirmed** — base → budget → vtbl → period → SetPeriod → return this |
| Product design English beyond RTTI | **Open** — dual correctly residual |
| Runtime / bit-exact | **Open** — Terminal false honest |

### Adversarial attacks (Virus_Ctor)

| # | Attack | Result |
|---|---|---|
| 1 | This is OnHeartBeat / pulse body | **Fails** — linear ctor; pulse is `0x0061fdf0` / shared `0x0061b6f0` |
| 2 | Generic non-Virus HB factory | **Fails** — RTTI Virus + exclusive vtbl `009d14bc` + sole CALL from Virus OnHB |
| 3 | `param_8`/`param_9` are floats | **Fails** — dword stores; SetPeriod takes int period |
| 4 | Budget/period at wrong offsets | **Fails** — `+0x6d0`/`+0x6d4` sealed; OnHB uses same |
| 5 | `cdecl` / no stack cleanup | **Fails** — `ret 0x20` |
| 6 | Base trailing float is period seed | **Fails** — base gets `0` + `1.0f`; period is param_9 after vtbl |
| 7 | Multiple direct CALL factories | **Fails as CALL** — sole UNCONDITIONAL_CALL from OnHB |
| 8 | Confuse with SharedOnHB pulse | **Fails** — different VA/ABI; ctor installs vtbl SharedOnHB is multi-class method/subroutine |
| 9 | Product “Virus” design English Confirmed | **Fails** — dual correctly Open beyond RTTI name |
| 10 | Runtime Confirmed without Launcher | **Fails** — dual honest Terminal false |

### Soft niggle (not sealed-claim failure)

- Base-ctor arg English / `arg7` / skill blob remain residual (not OWN) — dual already gaps.
- DATA xrefs on Virus lifecycle helpers exist beyond sole CALL factory — dual notes them; CALL uniqueness claim still holds.

### Unit A dual quality

**PASS** — keep **`accept`**.

Sealed identity/CF/ABI/vtbl/budget-period all re-consistent with dual A/B, clean, raw re-verify, and sibling Virus OnHB ADV.

---

## Unit B — `0x0061b6f0` CVOGHBSkill_SharedOnHeartBeat_Inferred

### Body / ABI / role seal (independent)

| Claim | Independent result |
|---|---|
| Body `0x0061b6f0`–`0x0061b955` exclusive (**613 B** / `0x265`) | **Confirmed** — dual meta; size `0x955−0x6f0=0x265` |
| `__thiscall` ECX=HB*; stack `uint32_t *pOutStatus`; **`ret 4`** | **Confirmed** — epilogue `C2 04 00`; clean/raw signature |
| Prologue local frame `sub esp,0x18` | **Confirmed** — dual re-verify + epilogue `add esp,0x18` |
| `FUN_005787a0` → local status first | **Confirmed** — raw/clean stage 1 |
| `this[+0x6c8]++` pulse counter (`[0x1b2]`) | **Confirmed** — raw `param_1[0x1b2]++` |
| Outer gate: `status != DAT_00af4bd0 (0x10)` ∧ `flag@+0x20==0` ∧ (`state@+0x0c > 1` ∨ `==-1000`) | **Confirmed** — raw/clean identical |
| Effect cascade order (damage short → heat → flag8 stop → HP → shield → short/floater → multi-arg → impulse → `vtbl+0x50`) | **Confirmed** — raw ≡ clean ≡ dual cascade table |
| `DAT_00af4bd0` = **0x10**; adjacent `"Health"` @ `0x00af4bd8` English open | **Confirmed** value; English residual fair |
| Intensity scale `this[+0x6c4]` (`[0x1b1]`) multiplies effect scales | **Confirmed** — raw/clean |
| CODE callers: `FUN_0061ba80`, `CVOGHBSkill_Virus_OnHeartBeat` (`0x0061fdf0`) | **Confirmed** — dual + sibling ADV pulse first in Virus OnHB |
| DATA vtbl installs: **9** slots at **+0x08** | **Confirmed** — dual raw list of 9 vtbl addresses |
| RTTI sample hosts: Chain / InverseChain / Aggregate | **Confirmed** — dual RTTI sample (full 9-host census residual) |
| Not cast entry / RequestCast | **Confirmed** — post-cast HB tick shape |
| Clean named ≡ sealed CF | **Confirmed** — cascade order + out status; flag8 dual MI arms preserved |
| Nested leaves / field English / runtime | **Open** — dual correctly residual |

### Adversarial attacks (SharedOnHB)

| # | Attack | Result |
|---|---|---|
| 1 | Virus-only helper, not multi-class method | **Fails** — 9 DATA vtbl installs + RTTI sample; Virus is a **caller** that overrides OnHB and calls this |
| 2 | Always applies every effect | **Fails** — per-effect gates + outer status/flag/state gate |
| 3 | Hard-stop is silent no-op | **Fails** — `this.vtbl+0x18(1,1)` on flag8 miss |
| 4 | Leaf / no callees | **Fails** — large worker (`005787a0`, resolve, heat/HP/shield/impulse cluster, flag8, TFID copy) |
| 5 | Cast entry / RequestCast manager | **Fails** — post-cast HB pulse; no cast-validate callees |
| 6 | Same vtbl slot as Virus OnHB for all classes | **Nuanced / fails as stated** — for Virus, OnHB is **`vtbl+0x0c`** (`0061fdf0`); SharedOnHB sits at **`vtbl+0x08`** for sampled multi-class hosts and is **called** by Virus OnHB. Path B “same relative slot as Virus OnHB … +0x08” is **incorrect for Virus** (see findings) |
| 7 | Status `0x10` product-English “Health skill id” Confirmed | **Fails** — dword sealed; string adjacency only; dual English Open correct |
| 8 | Product plate name Confirmed (no `_Inferred`) | **Fails** — multi-class shared; dual correctly Inferred |
| 9 | Runtime / stacking Confirmed | **Fails** — Terminal false honest |
| 10 | Clean invents cascade order | **Fails** — clean ≡ 2026-07-23 raw ≡ dual re-verify |

### Soft niggles / findings (not sealed CF rejects)

1. **Path B vtbl-slot wording error (finding):** Review B claims Virus OnHB `0061fdf0` is at “sibling vtbl+0x08”. Independent seal (dual Virus raw + sibling ADV) places Virus OnHB at **`vtbl+0x0c`**, with **`+0x08 = TryFire `0x005082c0`**. SharedOnHB’s multi-class install at **+0x08** remains correct; the OnHB-vs-TryFire residual is **not** closed by claiming Virus places OnHB at the same slot. Dual report language (“weakened by Virus vtbl alignment”) slightly oversells that alignment but still keeps **accept-with-gaps** and Inferred name — **no dual rewrite required**.
2. **Clean comment “bit1” vs dual “bit2”** for `*(byte*)(+0x648) & 2`: mask **& 2** is correct; English bit-index wording only.
3. **Flag8 MI arm duplication** may be decompiler sticky (dual Probable) — both arms call same `vtbl+0x18(1,1)`; clean preserves both; residual fair.
4. Full 9-host RTTI census and dual of `FUN_005787a0`/effect leaves remain residual (not OWN).

### Unit B dual quality

**PASS-WITH-FINDINGS** — keep **`accept-with-gaps`**.

Sealed CF/ABI/cascade/multi-class DATA role/Virus CALL composition hold. Finding is Path B slot-alignment overclaim only; name residual and nested dual gaps remain correctly open.

---

## Cross-unit dual report quality

| Check | Result |
|---|---|
| WQ9D-B Virus half: A/B/report **accept** | **Agree** — identity/CF/ABI sealed |
| WQ9D-C SharedOnHB half: A/B/report **accept-with-gaps** | **Agree** — CF sealed; English/nested residual fair |
| Terminal false honesty | **Yes** — no runtime Confirmed |
| OWN scope discipline | **Yes** — each dual owns its pair; parent ledgers not edited |
| Tool discipline in duals | **Yes** — decompile + `read_memory` + xrefs; **no** `disassemble_bytes` claimed |
| Cross-wiring Virus ↔ Shared | **Consistent** — OnHB calls Shared pulse then specialized multi-spread; ctor installs Virus vtbl used by OnHB DATA |
| Clean sources meaningful | **Yes** — named CF, not raw iVar paste-only |
| AutoCore port notes | **Accurate** — Virus factory must use Virus ctor/vtbl + budget/period; shared pulse is default multi-class OnHB body + specialized compose |

### Independent overall verdict

| Unit | Dual verdict | ADV verdict |
|---|---|---|
| `aa_0061f940` CVOGHBSkill_Virus_Ctor | **accept** | **PASS — keep accept** |
| `aa_0061b6f0` CVOGHBSkill_SharedOnHeartBeat_Inferred | **accept-with-gaps** | **PASS-WITH-FINDINGS — keep accept-with-gaps** |

**Overall: PASS-WITH-FINDINGS**

No sealed-claim CF falsification. Finding: Path B SharedOnHB “Virus OnHB at vtbl+0x08” is wrong (**actual Virus OnHB slot +0x0c**); multi-class SharedOnHB at +0x08 + Virus subroutine call still support Inferred SharedOnHeartBeat role. Residual gaps dual already lists (product English, nested leaves, full RTTI census, flag8 sticky, runtime/bit-exact) remain fair.

**Parent ledgers:** not touched (per charter). **Dual A/B:** not rewritten.

**Terminal:** **false**

---

## Process

- Independent ADV verifier; **not** WQ9D-B / WQ9D-C author.
- Evidence: dual reports (Virus half WQ9D-B, SharedOnHB half WQ9D-C), A/B reviews, clean/raw/annotated/function records, sibling ADV `ADV_wq009_spotcheck_0040aff0_0061fdf0.md` for Virus OnHB↔ctor↔pulse wiring.
- **No** `disassemble_bytes`. **No** parent ledger edits. **No** dual rewrite. **No** Launcher.
- Output: `docs/reconstruction/reviews/ADV_wq9d_spotcheck_0061f940_0061b6f0.md` (this file).

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
