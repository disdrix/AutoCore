# Independent adversarial spot-check — WQ9R-B dual `0x0040aff0` + `0x0061fdf0`

| Field | Value |
|---|---|
| **Date** | `2026-08-04` |
| **Role** | Independent adversarial verifier (**not** WQ9R-B dual author) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | WQ9R-B OWN pair (WQ-009 residual skills-abilities / identity) |
| **Units** | `0x0040aff0` `Object_CopyTfid16At228_Inferred`; `0x0061fdf0` `CVOGHBSkill_Virus_OnHeartBeat` |
| **Tools** | Ghidra MCP `batch_decompile`, `read_memory`, `get_function_by_address`, `get_function_xrefs`, `get_function_callees`; dual report + A/B + clean/raw artifact read-through |
| **Forbidden** | `disassemble_bytes`; parent ledger edits; dual rewrite; Launcher |
| **Image** | `autoassault.exe` base `0x400000` |

---

## Inspected evidence

### Dual / report surfaces

| Path |
|---|
| `docs/agents/task-dual-ab-0040aff0-0061fdf0-wq9rb-report.md` |
| `docs/reconstruction/reviews/A_aa_0040aff0_Object_CopyTfid16At228_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_0040aff0_Object_CopyTfid16At228_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_0061fdf0_CVOGHBSkill_Virus_OnHeartBeat.md` |
| `docs/reconstruction/reviews/B_aa_0061fdf0_CVOGHBSkill_Virus_OnHeartBeat.md` |

### Artifacts (both units)

| Kind | `aa_0040aff0` | `aa_0061fdf0` |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_0040aff0_FUN_0040aff0.md` | `docs/reconstruction/raw/aa_0061fdf0_FUN_0061fdf0.md` |
| Annotated | `…/aa_0040aff0_FUN_0040aff0.annotated.md` | `…/aa_0061fdf0_FUN_0061fdf0.annotated.md` |
| Clean named | `…/Object_CopyTfid16At228_Inferred.cpp` | `…/CVOGHBSkill_Virus_OnHeartBeat.cpp` |
| Clean scaffold | `…/FUN_0040aff0.cpp` | `…/FUN_0061fdf0.cpp` |
| Function named | `…/aa_0040aff0_Object_CopyTfid16At228_Inferred.md` | `…/aa_0061fdf0_CVOGHBSkill_Virus_OnHeartBeat.md` |

### Live Ghidra spot-checks (this session)

| Check | Result |
|---|---|
| `batch_decompile(0x0040aff0,0x0061fdf0)` | Live CF **≡** dual report + raw skeleton |
| `read_memory` @ `0x0040aff0` (48 B) | `8B442404 81C128020000 … C20400 CC…` — out load, `+0x228`, four dword stores, **`ret 4`** |
| `read_memory` @ `0x0061fdf0` (prologue) | SEH frame + `call FUN_0061b6f0` / `FUN_00578270` shape |
| `read_memory` @ `0x00620180` (epilogue) | `5B 8B E5 5D C2 04 00` — **`ret 4`** |
| `read_memory` @ gather site `0x0061ff70` | Pushes include **`6a 01`** (mode **1**) and **`83 CB FF` / `53`** (filterA **-1**) before `Skill_GatherTargetsInArea` |
| `read_memory` `DAT_00a0f524` | `00 00 48 42` → **50.0f** |
| `read_memory` `DAT_009e2df0` (16 B) | `FF×8` + `00×8` null TFID sentinel |
| `read_memory` vtbl `0x009d14bc` (16 B) | `[+0x08]=0x005082c0` TryFire; **`[+0x0c]=0x0061fdf0`** |
| `read_memory` type_info `0x00af2b08` | name string **`.?AVCVOGHBSkill_Virus@@`** |
| `read_memory` COL `0x00aae0b8` | pTypeDescriptor → `0x00af2b08` |
| `get_function_by_address` | `0040aff0`–`0040b016`; `0061fdf0`–`00620186` |
| `get_function_xrefs(0x0040aff0)` | **23** `UNCONDITIONAL_CALL` (filter ×3, FindTarget, net/combat, etc.) |
| `get_function_xrefs(0x0061fdf0)` | **DATA only** `@ 0x009d14c8` |
| `get_function_callees(0x0061fdf0)` | Pulse, resolve, gather, RNG, RTTI, new, Virus ctor, Enqueue, Start, TFID_NotEquals — matches dual |

---

## Unit A — `0x0040aff0` Object_CopyTfid16At228_Inferred

### Body / ABI seal (independent)

| Claim | Independent result |
|---|---|
| Body range Ghidra `0040aff0`–`0040b016` | **Confirmed** (`get_function_by_address`) |
| `__thiscall`, one stack arg, **`ret 4`** | **Confirmed** — terminal `C2 04 00` |
| Source offset **`this+0x228`** | **Confirmed** — `81 C1 28 02 00 00` |
| **16 B** out-copy (four dwords → `+0x22c/+0x230/+0x234`) | **Confirmed** — four load/store pairs |
| Leaf (no CALL) | **Confirmed** — no callees in body |
| No store to `this` | **Confirmed** — only loads from source, stores to out |
| EAX = out | **Confirmed** — `mov eax,[esp+4]` preserved through body |
| **23** call sites | **Confirmed** — xrefs list matches dual inventory shape |
| Role = TFID_16 extract (not pointer-return getter) | **High** — out buffer stores + callers feed TFID equals/not-equals / resolve |

### Adversarial attacks (TFID copy)

| # | Attack | Result |
|---|---|---|
| 1 | Function returns pointer into object (GetWorldPositionPtr style) | **Fails** — four stores to stack `*out` |
| 2 | Source is float3 position @ +0x228 | **Fails** — width 16 B; identity callers |
| 3 | `cdecl` / no stack cleanup | **Fails** — `ret 4` |
| 4 | Mutates object TFID | **Fails** — read-only source |
| 5 | AI FindTarget-only helper | **Fails** — 23 sites across filter/combat/net |
| 6 | Offset is +0x214 (mode-table residual wording) | **Fails** — live bytes seal **0x228** |
| 7 | Product/PDB name Confirmed | **Fails** — dual correctly keeps `_Inferred` |
| 8 | Runtime / bit-exact Confirmed | **Fails** — dual honest Open |

### Soft niggle (not sealed-claim failure)

1. **Body length wording:** dual/raw say “38 B exclusive” ending at `0x0040b016`. Live bytes are **39 B** to exclusive end `0x0040b017` (last instruction `ret 4` occupies `0040b014`–`0040b016` inclusive). Ghidra body end `0040b016` is **inclusive last byte**. CF/ABI claims unaffected.
2. **Review B hand-addressing** for `pop esi` / `ret 4` (`0040b011`/`0040b012`) is off by two bytes vs live layout (`0040b013`/`0040b014`). Byte sequence in raw is correct.

### Unit A dual quality

**PASS** — keep **`accept`**.

---

## Unit B — `0x0061fdf0` CVOGHBSkill_Virus_OnHeartBeat

### Body / ABI / identity seal (independent)

| Claim | Independent result |
|---|---|
| Body `0061fdf0`–`00620186`; **`ret 4`** | **Confirmed** — meta + epilogue `C2 04 00` |
| RTTI **`.?AVCVOGHBSkill_Virus@@`** | **Confirmed** — type string @ `0x00af2b10` |
| COL `0x00aae0b8` → type_info `0x00af2b08` | **Confirmed** |
| Vtbl `PTR_FUN_009d14bc`; slot **+0x0c** = this | **Confirmed** — dword @ `009d14c8` = `f0 fd 61 00` |
| Slot **+0x08** = `0x005082c0` (`CVOGHBBase_TryFire`) | **Confirmed** |
| DATA-only xref (virtual) | **Confirmed** — single DATA @ `009d14c8` |
| Pulse `FUN_0061b6f0` then primary resolve `FUN_00578270` | **Confirmed** — decompile + callees |
| Primary gate `vtbl+0x198()==0` else `vtbl+0x18(1,1)` / `*out=0` | **Confirmed** |
| World flag `*(char*)(world+0x7e)` and `this+0x10` | **Confirmed** (`world = this[0x1a2]` = `+0x688`) |
| RNG `(u16 % 100) > 0x19` (~75%) | **Confirmed** |
| Owner RTTI Creature(+0x250) OR Physics | **Confirmed** — dual `__RTDynamicCast` |
| Host RTTI fail → `*out=0` **without** `vtbl+0x18` | **Confirmed** — distinct from primary-target fail arm |
| Origin `FUN_00404c90` / null TFID seed | **Confirmed** — sentinel bytes |
| Gather **mode=1**, **filterA=-1** | **Confirmed** — decompile + gather-site pushes |
| maxTargets `*(u8*)(this+0x102)` else **4** | **Confirmed** |
| radius `this+0x5c` else **`DAT_00a0f524` = 50.0f** | **Confirmed** — float bytes |
| Budget dec `this+0x6d0` / `+0x6d4` (`[0x1b4]`/`[0x1b5]`) | **Confirmed** |
| Child `operator_new(0x6e0)` + `FUN_0061f940` + Enqueue(`world+0xe4ec`) + Start | **Confirmed** |
| Success `*out = pulseStatus` | **Confirmed** |
| Decompiler sticky `Object_ResolveFromTFID(outList[0])` vs loop `pA++` | **Acknowledged** — clean correctly uses advancing `pA`; dual lists residual |

### Adversarial attacks (Virus HB)

| # | Attack | Result |
|---|---|---|
| 1 | Free function / cast-entry manager | **Fails** — vtbl DATA only + RTTI Virus |
| 2 | Gather mode defaults to **4** | **Fails** — mode push **1**; **4** is maxTargets default |
| 3 | Always spreads every tick | **Fails** — RNG + flags + budget gates |
| 4 | Hostile gather (mode 2) | **Fails** — literal mode **1** (ally residual table) |
| 5 | Creates generic non-Virus HB only | **Fails** — Virus ctor `FUN_0061f940` / same class factory |
| 6 | Direct CALL fan-in | **Fails as CALL** — DATA-only; virtual dispatch |
| 7 | 100% fire when gates pass | **Fails** — `(u%100)>0x19` ≈ 75% |
| 8 | Product skill design English Confirmed | **Fails** — dual correctly Open beyond RTTI name |
| 9 | Runtime / stacking Confirmed | **Fails** — dual honest Open |
| 10 | Primary-invalid and host-RTTI-fail share same hard-stop | **Nuanced** — both `*out=0`, but only primary path calls **`vtbl+0x18(1,1)`**; dual CF stages already separate them |

### Soft niggle (not sealed-claim failure)

1. Clean reconstructs resolve as `Object_ResolveFromTFID(pA)` (correct intent); live decompiler still prints sticky `aTStack_ca0` on the resolve call while `pA` advances and pad writes use `pA` fields — dual residual is accurate; not a sealed-claim overclaim.
2. Nested helpers (`FUN_0061b6f0`, `FUN_0061f940`, `FUN_0051b720`) remain residual / other partitions — correctly out of OWN dual.
3. Field English for `+0x7e` / `+0x102` / budget dwords remains Tentative/Open — dual does not over-promote.

### Unit B dual quality

**PASS** — keep **`accept-with-gaps`**.

---

## Cross-unit / report seal

| Report claim | ADV result |
|---|---|
| Path A: `0040aff0` **accept**; `0061fdf0` **accept-with-gaps** | **Agree** |
| Path B: no CF rejects; mode-vs-maxTargets confusion closed | **Agree** — live gather-site seals mode **1** / default max **4** |
| `0040aff0` leaf TFID out-copy @ +0x228 / ret 4 | **Confirmed** |
| `0061fdf0` Virus OnHeartBeat ally multi-spread | **Confirmed** identity + CF |
| Default radius **50**, max targets **4**, ~**75%** RNG | **Confirmed** constants/math |
| Null TFID sentinel `DAT_009e2df0` | **Confirmed** |
| Live decompile ≡ dual raw CF | **Confirmed** this session |
| Never claim runtime Confirmed | **Agree** |
| Parent ledgers not owned by dual | **Respected** (ADV also no parent edits) |

### Clean ≡ raw CF

| Unit | Match |
|---|---|
| `Object_CopyTfid16At228_Inferred.cpp` | **Yes** — four dwords from `+0x228`, ret-out |
| `CVOGHBSkill_Virus_OnHeartBeat.cpp` | **Yes** — pulse → gates → gather mode 1 → spawn loop → status; fail arms separated |

---

## Verdict

| Unit | Dual verdict | ADV verdict |
|------|--------------|-------------|
| `aa_0040aff0` Object_CopyTfid16At228_Inferred | **accept** | **PASS — keep accept** |
| `aa_0061fdf0` CVOGHBSkill_Virus_OnHeartBeat | **accept-with-gaps** | **PASS — keep accept-with-gaps** |

No sealed-claim falsification. Soft niggles only (body-length exclusive wording / Review B pop-ret addresses / decompiler sticky resolve arg). Residual gaps dual already lists (product English, nested duals, field English, runtime/bit-exact, resolve-iterator static risk) remain fair.

**Parent ledgers:** not touched (per charter).

---

## Deliverable

- `docs/reconstruction/reviews/ADV_wq009_spotcheck_0040aff0_0061fdf0.md` (this file)
