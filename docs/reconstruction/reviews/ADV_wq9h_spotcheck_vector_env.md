# Independent adversarial spot-check — WQ9H vector InsertN/PushBack + FrameTick env + Escort factory

| Field | Value |
|---|---|
| **Date** | `2026-08-05` |
| **Role** | Independent adversarial verifier (**not** dual author WQ9H-A / WQ9H-C / WQ9H-E / WQ9H-G) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | `WAVE_2026-08-04_wq009_depth5_partition_map.md` → **WQ9H-A** unit `00408050` only; **WQ9H-C** unit `00406220` only; **WQ9H-G** unit `00942e20` only; **WQ9H-E** unit `0060c860` only |
| **Units** | (1) `0x00408050` `StdVector_InsertN_Elem0x28_Inferred`; (2) `0x00406220` `StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred`; (3) `0x00942e20` `Client_FrameTick_EnvDayCycleAndSystems_Inferred`; (4) `0x0060c860` `CVOGHBMissionEscort_ReactionFactory_Inferred` |
| **Tools** | Dual reports A/B + raw/annotated/clean + function records + chain cross-check (InsertOne `00406de0`, ConstructN residual, Escort ctor dual, sky-blend dual) |
| **Live Ghidra this session** | Not required for seal audit — claims re-checked against dual-published raw decompile + re-verify body/ABI hex plates + clean CF rewrite |
| **Forbidden** | `disassemble_bytes`; parent ledger edits; dual rewrite; Launcher |
| **Image** | `autoassault.exe` base `0x400000` |
| **Terminal** | **false** |
| **Overall verdict** | **PASS-WITH-FINDINGS** |

---

## Inspected evidence

### Dual / report surfaces

| Path |
|---|
| `docs/agents/task-dual-ab-004085e0-00408050-wq9ha-report.md` (unit `00408050` only) |
| `docs/agents/task-dual-ab-00406220-004062a0-wq9hc-report.md` (unit `00406220` only) |
| `docs/agents/task-dual-ab-00942e20-00807550-wq9hg-report.md` (unit `00942e20` only) |
| `docs/agents/task-dual-ab-004195d0-0060c860-wq9he-report.md` (unit `0060c860` only) |
| `docs/reconstruction/reviews/A_aa_00408050_StdVector_InsertN_Elem0x28_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_00408050_StdVector_InsertN_Elem0x28_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_00406220_StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_00406220_StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_00942e20_Client_FrameTick_EnvDayCycleAndSystems_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_00942e20_Client_FrameTick_EnvDayCycleAndSystems_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_0060c860_CVOGHBMissionEscort_ReactionFactory_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_0060c860_CVOGHBMissionEscort_ReactionFactory_Inferred.md` |

### Artifacts (four units)

| Kind | `00408050` | `00406220` | `00942e20` | `0060c860` |
|---|---|---|---|---|
| Raw (+ re-verify) | `raw/aa_00408050_FUN_00408050.md` | `raw/aa_00406220_FUN_00406220.md` | `raw/aa_00942e20_FUN_00942e20.md` | `raw/aa_0060c860_FUN_0060c860.md` |
| Annotated | `…FUN_00408050.annotated.md` | `…FUN_00406220.annotated.md` | `…FUN_00942e20.annotated.md` | `…FUN_0060c860.annotated.md` |
| Clean named | `StdVector_InsertN_Elem0x28_Inferred.cpp` | `StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred.cpp` | `Client_FrameTick_EnvDayCycleAndSystems_Inferred.cpp` | `CVOGHBMissionEscort_ReactionFactory_Inferred.cpp` |
| Clean twin | `FUN_00408050.cpp` | `FUN_00406220.cpp` | `FUN_00942e20.cpp` | `FUN_0060c860.cpp` |
| Function named | `aa_00408050_StdVector_…` | `aa_00406220_StdVector_…` | `aa_00942e20_Client_FrameTick_…` | `aa_0060c860_CVOGHBMissionEscort_…` |

### Support / chain evidence (not OWN duals of this ADV set)

| Artifact | Use |
|---|---|
| Dual WQ9G-H `00406de0` InsertOne | Sole external caller of InsertN `00408050`; slow path of PushBack `00406220` |
| Dual WQ9G-H `00406e50` Ufill 0x28 | Grow/in-place fill callee of InsertN |
| Dual WQ9G-F `004912c0` sky blend | FrameTick child at `0x00942e75` (ECX=env) |
| Dual WQ9G-E `006507c0` Escort ctor | Factory spawn target after `operator_new(0x78)` |
| Dual WQ9H-A unit `004085e0` | **Out of scope** (not in unit list) |
| Dual WQ9H-C unit `004062a0` | **Out of scope** (elem-0xC twin; not in unit list) |
| Dual WQ9H-G unit `00807550` | **Out of scope** (ghost TFID assign; not in unit list) |
| Dual WQ9H-E unit `004195d0` | **Out of scope** (CNDHash recreate; not in unit list) |

### Evidence cross-check matrix

| Check | Result |
|---|---|
| Raw decompile ≡ dual A CF tables | **Yes** (all four) |
| Dual re-verify body ends + entry/exit hex recorded | **Yes** (all four) |
| Clean named owns correct VA (no plate collision) | **Yes** (all four; twins forward or re-express same CF) |
| Body-size arithmetic | **Yes** (see unit sections; Escort uses **inclusive** end — documented) |
| Vector chain: PushBack slow → InsertOne → InsertN 0x28 | **Yes** — dual reports + raw callees |
| FrameTick sky-blend call site not conflated with child VA | **Yes** — dual B rejects name-as-`004912c0`; disasm plate seals ECX |
| Escort factory ≠ ctor; size 0x78 + dualed Escort RTTI path | **Yes** |
| Twin non-merge (InsertN 0x28 ≠ 0xC/dword; PushBack 0x28 ≠ 0xC; Escort ≠ Outpost) | **Holds** |
| Terminal honesty | **false** on all duals / cleans / this ADV |
| Runtime Confirmed | **Not claimed** |

---

## Unit 1 — `0x00408050` StdVector_InsertN_Elem0x28_Inferred

### Body / ABI seal (independent)

```text
0x004082ed − 0x00408050 = 0x29D = 669 B exclusive
```

| Claim | Independent result |
|---|---|
| Range `0x00408050`–`0x004082ed` exclusive (**669 B** / `0x29D`); pad `CC`; next InsertN12 `0x004082f0` | **Confirmed** (size math + re-verify plate) |
| **ECX** = vec* (`mov ebx,ecx`); **EDX** = value*; stack where + count | **Confirmed** (raw `__fastcall` param_1/param_2 + parent InsertOne call shape) |
| **`ret 0x8`** (`C2 08 00`) | **Confirmed** (re-verify exit plate) |
| Stride **0x28** (10-dword snap; magic `0x66666667`; max `0x06666666`) | **Confirmed** (raw loop `iVar4=10`; `/0x28`; max check) |
| Growth **1.5×** then size+count floor; three-way relocate on grow | **Confirmed** (`cap + (cap>>1)`; Ufill `00406e50`; uninit_copy prefix/suffix) |
| In-place near-end vs mid + shared assign-fill | **Confirmed** (raw `tail < count` split; `0040a520` / `00409b20` / `00409b00`) |
| Sole caller InsertOne `00406de0` @ `0x00406e30` (count forced 1) | **Confirmed** (dual xref + re-verify) |
| `operator_delete` “noreturn” is decomp artifact | **Confirmed** — triad rebind after free is load-bearing in raw |
| Name `_Inferred` / product POD English open | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
// ECX=vec, EDX=value*, stack where, count; ret 8
void InsertN_Elem0x28(Vec *this, const Pod28 *value, Pod28 *where, uint count)
{
  Pod28 tmp[/*10 dwords*/];
  memcpy(tmp, value, 0x28);                 // snap so value may alias buffer
  uint cap  = begin ? (capEnd-begin)/0x28 : 0;
  if (count == 0) return;
  uint size = begin ? (end-begin)/0x28 : 0;
  if (0x06666666 - size < count) FUN_00418130();  // length_error
  if (cap < size + count) {
    // 1.5x then floor to size+count; new; prefix copy; Ufill; suffix; delete; triad
    ...
    return;
  }
  // in-place: if (end-where)/0x28 < count → open hole + Ufill
  // else mid relocate + FUN_00409b20; then shared FUN_00409b00 plant
}
```

### Clean fidelity

| Item | Result |
|---|---|
| Named clean VA / size plate | **Owns `0x00408050`** (no misbind) |
| CF rewrite (snap / max / 1.5× grow / in-place split / ret 8) | **Match** at structural level |
| Helper formal packing | **Soft gap** — grow/in-place call `FUN_00406e50(/*dest*/ nullptr, …)` and some mid-insert args are **simplified placeholders**, not full register/stack packing from raw. Dual A/B already mark helper packing **High**, not Confirmed runtime. |
| Scaffold twin | Thin forwarder to named clean — **OK** (note: twin file re-declares the FUN symbol; hygiene only) |

### Dual A/B quality

| Path | Verdict | ADV |
|---|---|---|
| A fidelity | accept-with-gaps | **Agree** — CF/ABI/stride/growth High–Confirmed; product open |
| B adversarial | accept-with-gaps | **Agree** — erase / dword / 0xC thiscall-3arg / always-grow / 2× / plain-ret attacks correctly falsified |

### Unit verdict

**PASS** — keep **`accept-with-gaps`**. Non-blocking clean helper-packing softness → overall findings only.

---

## Unit 2 — `0x00406220` StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred

### Body / ABI seal (independent)

```text
0x00406298 − 0x00406220 = 0x78 = 120 B exclusive
```

| Claim | Independent result |
|---|---|
| Range `0x00406220`–`0x00406298` exclusive (**120 B** / `0x78`); pad `CC` to twin `004062a0` | **Confirmed** |
| **EAX** = vector* (+4 begin, +8 end, +0xC capEnd); **ECX** = `const T*` value | **Confirmed** (raw `in_EAX` + `param_1`; re-verify + callers set EAX/ECX) |
| Bare **`ret 0`** (`C3` both exits) | **Confirmed** |
| Fast: size < capacity (`/0x28`, magic `0x66666667`) → ConstructN `00409d40(end,1)` → `end += 0x28` | **Confirmed** (raw ≡ clean) |
| Slow: insert-one rebind `00406de0` at `where=end`; out scratch discarded | **Confirmed** |
| Not thiscall; not tree/buynode; not stride 0xC twin | **Confirmed** (dual B attacks hold) |
| Callers (2): `FUN_00933480` / `FUN_00976900` | **Confirmed** (dual re-verify xrefs) |
| Name `_Inferred` | **Correct hygiene** |

### Recovered CF (independent)

```c
// customcc; EAX=vec*, ECX=value*; ret 0
void PushBack_Elem0x28(void *vec, const void *value)
{
  int begin = *(int *)((char *)vec + 4);
  if (begin != 0) {
    unsigned size = (*(int *)((char *)vec + 8) - begin) / 0x28;
    unsigned cap  = (*(int *)((char *)vec + 0xc) - begin) / 0x28;
    if (size < cap) {
      int end = *(int *)((char *)vec + 8);
      FUN_00409d40((void *)end, 1);   // value packing via phantom stack pack in binary
      *(int *)((char *)vec + 8) = end + 0x28;
      return;
    }
  }
  void *out = (void *)value; // scratch only
  FUN_00406de0(vec, &out, *(void **)((char *)vec + 8), value);
}
```

### Clean fidelity

| Item | Result |
|---|---|
| Named clean VA / size plate | **Owns `0x00406220`** |
| CF rewrite | **Match** — capacity gate, fast ConstructN, slow InsertOne, ret 0 |
| ConstructN value packing | Plate documents phantom pushes + `add esp,0x10`; clean call is 2-arg surface — **acceptable** with residual note (ConstructN undualed WQ9H-B) |
| Scaffold twin | Same CF rewrite — **OK** |

### Dual A/B quality

| Path | Verdict | ADV |
|---|---|---|
| A fidelity | accept-with-gaps | **Agree** |
| B adversarial | accept-with-gaps | **Agree** — tree merge / stride merge / always-grow / by-value / EDI-entry attacks falsified |

### Chain cross-check

```text
00406220 PushBack 0x28
  ├─ fast → 00409d40 ConstructN 0x28   [residual]
  └─ slow → 00406de0 InsertOne (dualed)
              └─ 00408050 InsertN 0x28  [Unit 1]
```

PushBack slow → InsertOne → InsertN chain is **coherent** across dual reports.

### Unit verdict

**PASS** — keep **`accept-with-gaps`**.

---

## Unit 3 — `0x00942e20` Client_FrameTick_EnvDayCycleAndSystems_Inferred

### Body / ABI seal (independent)

```text
0x009430f0 − 0x00942e20 = 0x2D0 = 720 B exclusive
```

| Claim | Independent result |
|---|---|
| Range `0x00942e20`–`0x009430f0` exclusive (**720 B** / `0x2D0`); frame `SUB ESP,0x114`; bare **`RET`** (`C3`) | **Confirmed** (re-verify entry/epilogue plates) |
| **EDI** = client/session host (register this); no stack args | **Confirmed** (raw `unaff_EDI`; entry `MOV EAX,EDI`) |
| Return **1** on gate fail / **0** success | **Confirmed** (`FUN_0092e510` early return 1; epilogue `XOR EAX,EAX`) |
| dt = min(`*(float*)(DAT_00d09874+0x30)`, **0.2f** `DAT_00a0f70c`) | **Confirmed** (raw + float plate `CD CC 4C 3E`) |
| If `[EDI+0xe04] != 0`: ECX = `*([EDI+0xe04]+0xe894)`; push dt; **`CALL 004912c0`** | **Confirmed** (re-verify disasm plate; raw decompile **hides** ECX setup — dual correctly elevated via disasm, not decomp alone) |
| Sole caller `FUN_0094b520` @ `0x0094b865` | **Confirmed** (xref_count=1) |
| Not the sky-blend leaf (`004912c0`); not skill/combat tick | **Confirmed** (dual B naming attacks) |
| Fog scale **0.01f** / `fFogHeight` **1.0f**; one-shot load-time string | **Confirmed** (raw strings + constants) |
| Name `_Inferred` / product host English open | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
// EDI = host; bare RET; return 0/1
uint FrameTick_EnvDayCycleAndSystems(void)
{
  if (FUN_0092e510() == 0) return 1;          // EAX=EDI implied
  float dt = *(float *)(DAT_00d09874 + 0x30);
  if (dt > DAT_00a0f70c /*0.2f*/) dt = DAT_00a0f70c;
  if (*(int *)(EDI + 0xe04) != 0)
    Env_DayCycle_ApplySkyBlendAndLight(/*ECX=*/env_at_+0xe894, dt);
  // system ticks, optional fog material, list drain, primary vtbl+0x344(dt)
  // one-shot "%%%%… All load time (%f)\n" when DAT_00d1f06c==0
  return 0;
}
```

### Clean fidelity

| Item | Result |
|---|---|
| Named clean VA / size plate | **Owns `0x00942e20`** |
| Gate / dt clamp / sky-blend ECX path / fog / load-time | **Match** raw + dual seal (clean **restores** ECX that decomp dropped) |
| List-drain loop | **Soft gap** — clean has placeholder `node = /* stack cursor after 004040a0 */ node;` for cursor reload; raw shows proper sentinel/node walk. Structural role sealed; clean is **not** a complete mechanical rewrite of the drain cursor. |
| Scaffold twin | `#include` of named clean — **OK** |

### Dual A/B quality

| Path | Verdict | ADV |
|---|---|---|
| A fidelity | accept-with-gaps | **Agree** — EDI/RET/dt/sky-blend call Confirmed |
| B adversarial | accept-with-gaps | **Agree** — ECX-this / ret4 / this-VA-as-sky-blend / multi-caller / always-apply attacks falsified |

### Unit verdict

**PASS** — keep **`accept-with-gaps`**. List-cursor clean softness is a finding, not a dual CF reject.

---

## Unit 4 — `0x0060c860` CVOGHBMissionEscort_ReactionFactory_Inferred

### Body / ABI seal (independent)

```text
Inclusive: 0x0060c991 − 0x0060c860 + 1 = 0x132 = 306 B
```

| Claim | Independent result |
|---|---|
| Body **306 B** / `0x132`; pad `CC` after `ret 8` | **Confirmed** (dual uses **inclusive** end `0x0060c991` — arithmetic holds; differ from exclusive convention of Units 1–3 only in notation) |
| **`__thiscall`**: ECX = reqHost; stack ownerCtx, scoreFloats*; **`ret 8`** | **Confirmed** (raw thiscall; exit `C2 08 00`) |
| Return **bool AL** (fail `xor al,al` / success `mov al,1`) | **Confirmed** — decompiler `return uVar3 & 0xffffff00` is a **merge artifact** (dual B correctly rejects as machine return) |
| Gate: owner enable `@+0x7e` + key `req+0x40 == obj+0xfc` | **Confirmed** (raw) |
| ResolveSkillTargets → optional CastSkill (fail → delete → false) → score `g_flOne` | **Confirmed** |
| Spawn if `(g_flZero < req+0x1c \|\| req+0x18) && targets[0x53] != -1` | **Confirmed** — dword index `0x53` ≡ byte `+0x14c` |
| `operator_new(0x78)` → `FUN_006507c0` Escort ctor → Enqueue `@+0xe4ec` → Start | **Confirmed** |
| Not the Escort ctor; not Outpost; delete continues | **Confirmed** (dual B attacks) |
| Xrefs via stubs `0060cab2` / `0060cac0` (Ghidra named-caller list empty) | **Accepted** as documented |
| Name `_Inferred` method English open; class via dualed ctor RTTI | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
// thiscall ECX=reqHost; [esp+4]=ownerCtx; [esp+8]=scoreFloats*; ret 8 → bool AL
bool ReactionFactory(void *req, void *ownerCtx, float *scores)
{
  void *ownerObj = /* *( *(ownerCtx+4)+4 + 0xa8 + ownerCtx ) */;
  if (!*(char *)(ownerObj + 0x7e) || *(int *)(req+0x40) != *(int *)(ownerObj+0xfc))
    return false;
  void **targets = ResolveSkillTargets(*(void **)(req+0x10), packed);
  if (!targets) return false;
  if (*(char *)(req+0x20)) {
    if (CastSkillOnTarget(...)) { operator_delete(targets); return false; }
  }
  scores[1 + *(uint8_t *)(req+8)] = g_flOne;
  if ((g_flZero < *(float *)(req+0x1c) || *(char *)(req+0x18))
      && targets[0x53] != -1) {
    void *mem = operator_new(0x78);
    void *action = mem ? CVOGHBMissionEscort_ctor(mem, ownerCtx, req) : 0;
    CVOGHBList_Enqueue(*(void **)(ownerObj + 0xe4ec), action);
    CVOGHBBase_Start(action);
  }
  operator_delete(targets);
  return true;
}
```

### Clean fidelity

| Item | Result |
|---|---|
| Named clean VA / size plate | **Owns `0x0060c860`** |
| CF rewrite | **Match** — gates, optional cast, score, conditional spawn, bool return (not decomp mask) |
| Scaffold twin | `#include` of named clean — **OK** |

### Dual A/B quality

| Path | Verdict | ADV |
|---|---|---|
| A fidelity | accept-with-gaps | **Agree** — factory role High; size Confirmed; product method open |
| B adversarial | accept-with-gaps | **Agree** — ctor-identity / Outpost / always-spawn / noreturn-delete / void-return attacks falsified |

### Unit verdict

**PASS** — keep **`accept-with-gaps`**.

---

## Findings (non-blocking)

| # | Severity | Finding | Impact |
|---|---|---|---|
| F1 | Low | **InsertN named clean** simplifies Ufill / mid-insert **helper formal packing** (`nullptr` dest placeholders). Dual already labels packing High not Confirmed. | Ports must not treat clean call sites as ABI-authoritative for helpers; use dual B ABI trap + raw. |
| F2 | Low | **FrameTick named clean** list-drain **node/cursor reload** is comment-stubbed vs raw sentinel walk. | Role of drain is sealed; bit-faithful list rewrite still residual. |
| F3 | Info | Body-end **notation** differs: Units 1–3 exclusive; Unit 4 Escort **inclusive** (`…–0x0060c991`). Arithmetic is consistent either way. | Prefer exclusive ends in future dual plates for uniformity. |
| F4 | Info | ConstructN `00409d40` remains **undualed** under PushBack fast path (WQ9H-B residual). InsertN mid-insert leaves partly undualed. | Expected open gaps; not dual overclaim. |
| F5 | Info | Product English open on all four (`_Inferred`); FrameTick host class / Escort method English / 0x28 POD type open. | Correct Terminal **false**. |

No CF reject. No dual A↔B contradiction on sealed ABI/role. No clean plate VA collision (unlike prior ADV free/dtor clone hazard). No Terminal overclaim.

---

## Overall verdict

| Unit | Dual seal | ADV unit verdict |
|---|---|---|
| `0x00408050` InsertN 0x28 | accept-with-gaps | **PASS** |
| `0x00406220` PushBack 0x28 | accept-with-gaps | **PASS** |
| `0x00942e20` FrameTick env | accept-with-gaps | **PASS** |
| `0x0060c860` Escort reaction factory | accept-with-gaps | **PASS** |

### **PASS-WITH-FINDINGS**

Dual OWN seals for the four units hold under independent adversarial read of dual A/B + raw re-verify + cleans. Structural CF, ABI, strides, growth policy, frame env parentage, and Escort factory path are sealed at High/Confirmed as claimed. Findings F1–F2 are clean-fidelity soft spots already bounded by dual residual language; they do **not** justify FAIL or dual rewrite.

**Terminal:** **false** (no runtime Confirmed; no Launcher this session).

---

## What ADV did **not** do

- No `disassemble_bytes`
- No parent ledger / WORK_QUEUE / RESUME / VERIFICATION_MATRIX / NAMING_REGISTRY / COVERAGE_LEDGER edits
- No dual A/B or clean rewrites
- No Launcher / live runtime
- No dual of out-of-scope pair mates (`004085e0`, `004062a0`, `00807550`, `004195d0`)

---

## Output

- This report: `docs/reconstruction/reviews/ADV_wq9h_spotcheck_vector_env.md`
- Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
