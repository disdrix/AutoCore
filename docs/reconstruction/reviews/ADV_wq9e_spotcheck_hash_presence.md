# Independent adversarial spot-check — WQ9E-A + WQ9E-B (hash destroy/alloc + presence store/score)

| Field | Value |
|---|---|
| **Date** | `2026-08-04` |
| **Role** | Independent adversarial verifier (**not** dual author WQ9E-A / WQ9E-B) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | `WAVE_2026-08-04_wq009_depth2_partition_map.md` → **WQ9E-A**, **WQ9E-B** |
| **Units** | (1) `0x004cba60` `SkillCNDHash_DestroyBucketTable_Inferred` + `0x004cb410` `SkillCNDHash_AllocBucketTable_Inferred`; (2) `0x0054fec0` `Skill_StoreEffectPresenceFlags_Inferred` + `0x00627ec0` `Skill_ComputeEffectScore_Inferred` |
| **Tools** | Dual reports + A/B + raw/annotated/clean + function records + inventory destroy contrast raw + parent WQ9D recreate/ctor ADV/raws + relative-call arithmetic |
| **Live Ghidra this session** | MCP HTTP `127.0.0.1:8089` **not reachable** (localhost SSRF block). Claims re-checked against sealed raw decompile + dual 2026-08-04 re-verify byte seals + parent WQ9D ADV (live decompile of recreate/ctor that call these helpers) |
| **Forbidden** | `disassemble_bytes`; parent ledger edits; dual rewrite; Launcher |
| **Image** | `autoassault.exe` base `0x400000` |
| **Terminal** | **false** |

---

## Inspected evidence

### Dual / report surfaces

| Path |
|---|
| `docs/agents/task-dual-ab-004cba60-004cb410-wq9ea-report.md` |
| `docs/agents/task-dual-ab-0054fec0-00627ec0-wq9eb-report.md` |
| `docs/reconstruction/reviews/A_aa_004cba60_SkillCNDHash_DestroyBucketTable_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_004cba60_SkillCNDHash_DestroyBucketTable_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_004cb410_SkillCNDHash_AllocBucketTable_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_004cb410_SkillCNDHash_AllocBucketTable_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_0054fec0_Skill_StoreEffectPresenceFlags_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_0054fec0_Skill_StoreEffectPresenceFlags_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_00627ec0_Skill_ComputeEffectScore_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_00627ec0_Skill_ComputeEffectScore_Inferred.md` |

### Artifacts (four units)

| Kind | `004cba60` | `004cb410` | `0054fec0` | `00627ec0` |
|---|---|---|---|---|
| Raw (+ re-verify) | `raw/aa_004cba60_FUN_004cba60.md` | `raw/aa_004cb410_FUN_004cb410.md` | `raw/aa_0054fec0_FUN_0054fec0.md` | `raw/aa_00627ec0_FUN_00627ec0.md` |
| Annotated | `…FUN_004cba60.annotated.md` | `…FUN_004cb410.annotated.md` | `…FUN_0054fec0.annotated.md` | `…FUN_00627ec0.annotated.md` |
| Clean named | `SkillCNDHash_DestroyBucketTable_Inferred.cpp` | `SkillCNDHash_AllocBucketTable_Inferred.cpp` | `Skill_StoreEffectPresenceFlags_Inferred.cpp` | `Skill_ComputeEffectScore_Inferred.cpp` |
| Function named | `aa_004cba60_SkillCNDHash_…` | `aa_004cb410_SkillCNDHash_…` | `aa_0054fec0_Skill_Store…` | `aa_00627ec0_Skill_Compute…` |

### Support / contrast evidence (not OWN duals)

| Artifact | Use |
|---|---|
| `raw/aa_004cbdc0_FUN_004cbdc0.md` + WQ9D-A ADV | Recreate: destroy then seed then alloc; ECX=hash |
| `raw/aa_0051dd60_FUN_0051dd60.md` | Ctor sole alloc caller |
| `raw/aa_00413e20_FUN_00413e20.md` | Inventory destroy twin — **EAX** ABI contrast |
| `ADV_wq9d_spotcheck_004cbdc0_0051dd60.md` | Prior independent seal of parent recreate/ctor |
| Presence leaf dual (WQ9D-E) | Callee of both store and score |

### Evidence cross-check matrix

| Check | Result |
|---|---|
| Raw 2026-07-23 decompile ≡ dual A CF tables | **Yes** (all four) |
| Dual re-verify 2026-08-04 claims live ≡ raw | Stated **identical**; body ends + entry/exit hex recorded |
| Clean named ≡ raw CF | **Yes** (all four) |
| Body-size arithmetic (inclusive/exclusive per dual) | **Yes** (see unit sections) |
| Store relative call target → `0x00627be0` | **Yes** (`E8 18 7D 0D 00` from `0x0054fec4` → next=`0x0054fec8` + `0x000d7d18` = `0x00627be0`) |
| Throw code signed/unsigned identity | **Yes** (`-0x7fffbffd` ≡ `0x80004003` = `E_POINTER`) |
| Inventory destroy ABI contrast | **Yes** — `in_EAX` vs skill `mov esi,ecx` |
| Score short-index → byte offsets in clean | **Yes** (e.g. `[0x30]→+0x60`, `+0x1a short* → +0x34 float`) |
| Parent WQ9D mask post-condition depends on alloc | **Holds** via OWN `004cb410` `*(+8) = N-1` |

---

## Unit 1a — `0x004cba60` SkillCNDHash_DestroyBucketTable_Inferred

### Body / ABI seal (independent)

```text
0x004cba93 − 0x004cba60 + 1 = 0x34 = 52 B
```

| Claim | Independent result |
|---|---|
| Range `0x004cba60`–`0x004cba93` inclusive (**52 B**); `CC` pad after bare `ret` | **Confirmed** (size math + dual re-verify end) |
| **`__thiscall`**; entry `56 8B F1` (`push esi; mov esi,ecx`) | **Confirmed** (dual re-verify; raw `param_1` this) |
| **Bare `ret`** (`5E C3`); void; no stack args | **Confirmed** |
| Zero **`+0x0c`** (live count), **not** mask `+0x08` | **Confirmed** (raw first store; dual B byte claim `c7460c…`) |
| Callee `FUN_004cb680` freelist release | **Confirmed** (raw call; residual nested) |
| If table `@+0x10`: `free(**table)` slab + `delete[]` table + null `+0x10` | **Confirmed** (raw exact free shape) |
| Callers: recreate `004cbdc0` @ `004cbde6`; dtor `0051de80` @ `0051dece` | **Accepted** (dual re-verify + parent recreate raw order) |
| Distinct from inventory `0x00413e20` (EAX) | **Confirmed** — inventory raw uses `in_EAX`; same free shape, different ABI |
| Name `_Inferred` / product English open | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
void __fastcall FUN_004cba60(int param_1) // thiscall ECX=hash
{
  *(undefined4 *)(param_1 + 0xc) = 0;
  FUN_004cb680();
  if (*(undefined4 **)(param_1 + 0x10) != (undefined4 *)0x0) {
    free((void *)**(undefined4 **)(param_1 + 0x10)); // slab base = bucket[0]
    operator_delete__(*(void **)(param_1 + 0x10));   // pointer array
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return; // bare ret
}
```

Clean `SkillCNDHash_DestroyBucketTable_Inferred.cpp` matches CF (zero `+0x0c`; freelist helper; dual free; leaves mask/`+0x20` alone).

### Adversarial attacks (Destroy)

| # | Attack | Result |
|---|---|---|
| 1 | Custom EAX ABI like inventory `00413e20` | **Fails** — entry `mov esi,ecx`; callers set ECX |
| 2 | Zeros mask / count at `+0x08` | **Fails** — only writes `+0x0c` |
| 3 | `free(table)` frees pointer array as slab | **Fails** — `free(**table)` then `delete[](table)` |
| 4 | Full object destructor | **Fails** — dtor continues after this (e.g. freelist host) |
| 5 | ECX is owner (`owner+0x70`) | **Fails** — recreate passes hash; dtor is on hash |
| 6 | Stack args / `ret 4` | **Fails** — bare `ret` |
| 7 | Product class name sealed | **Fails** — `_Inferred` |
| 8 | Nested freelist dual complete | **Fails** — `004cb680` residual open |
| 9 | Bit-exact / runtime Confirmed | **Fails** — open |

### Soft niggles (not sealed-claim failures)

1. **Nested freelist helper** `FUN_004cb680` remains undualed — dual correctly owns residual; destroy shape still High from free order + callers.
2. Parent WQ9D dual B once said destroy “zeros count” imprecisely; **this** dual correctly seals `+0x0c` not `+0x08` (parent recreate still correct because it immediately overwrites `+0x08`).

### Unit 1a dual quality

**PASS** — keep **`accept-with-gaps`**.

---

## Unit 1b — `0x004cb410` SkillCNDHash_AllocBucketTable_Inferred

### Body / ABI seal (independent)

```text
0x004cb4a0 − 0x004cb410 + 1 = 0x91 = 145 B
```

| Claim | Independent result |
|---|---|
| Range `0x004cb410`–`0x004cb4a0` inclusive (**145 B**) | **Confirmed** |
| **`__thiscall`**; entry `51 56 8B F1`; success bare ret `5F 5E 59 C3` | **Confirmed** (dual re-verify) |
| Log2 gate: `0 < *(char*)(+0x1c) < 0x11` i.e. **[1, 16]** | **Confirmed** (raw compound if; dual `cmp 1 / jl`, `cmp 0x10 / jg`) |
| Fail: `VOG_DEBUG_STOP` + `_CxxThrowException` code **`0x80004003`** | **Confirmed** — raw `-0x7fffbffd` ≡ `0x80004003`; `ThrowInfo` `DAT_00acc430` |
| `N = *(+8)`; `new[](N*4)` → `+0x10`; `malloc(N*0xc)` slab | **Confirmed** (raw) |
| Each sentinel stamp **`&PTR_LAB_009cb970`**, `[+4]=0`, `[+8]=0` | **Confirmed** (raw loop) |
| Post: `*(+8) = N - 1` (**COUNT → MASK**) | **Confirmed** (raw `*(…+8) = *(…+8) + -1`) |
| Callers: recreate `004cbe0c`; ctor `0051ddba` | **Confirmed** via parent recreate/ctor raws |
| Distinct from inventory/medal alloc VAs | **Confirmed** (different VA + stamp family) |
| Name `_Inferred` | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
void __fastcall FUN_004cb410(int param_1)
{
  if (('\0' < *(char *)(param_1 + 0x1c)) && (*(char *)(param_1 + 0x1c) < '\x11')) {
    // N = *(param_1+8); new[](N*4) → +0x10; malloc(N*0xc)
    // for i in 0..N-1: table[i]=slab+i*0xc; stamp 009cb970; zeros
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1; // MASK
    return;
  }
  FUN_007a4480(0, "VOG_DEBUG_STOP");
  local_4 = -0x7fffbffd; // 0x80004003
  _CxxThrowException(&local_4, (ThrowInfo *)&DAT_00acc430); // noreturn
}
```

Clean matches gate, dual alloc, stamp, mask post-condition, throw path.

### Adversarial attacks (Alloc)

| # | Attack | Result |
|---|---|---|
| 1 | Soft-fail / return error on bad log2 | **Fails** — log + noreturn throw |
| 2 | Domain includes 0 or 0..15 only | **Fails** — rejects 0; accepts 16 (`< 0x11`) |
| 3 | `+8` remains bucket **count** after success | **Fails** — decremented to **mask** |
| 4 | Single allocation for table+slab | **Fails** — `new[]` then `malloc` |
| 5 | Type-merge with inventory `00413d80` / medal allocs | **Fails** — stamp `009cb970` / distinct VA |
| 6 | ECX is owner / stack skill-id | **Fails** — thiscall on hash; log2 already at `+0x1c` |
| 7 | Stack arg / `ret 4` | **Fails** — bare ret |
| 8 | Product English sealed | **Fails** — `_Inferred` |
| 9 | OOM null-checked | **Fails as sealed claim** — no checks (preserve; open intentionality) |
| 10 | Bit-exact / runtime Confirmed | **Fails** — open |

### Soft niggles

1. **OOM path** — no null checks after `new[]`/`malloc`; dual correctly preserves and leaves intentionality open.
2. Clean uses `extern void *PTR_LAB_009cb970` + store `&…` (matches Ghidra form); retail imm is address **`0x009cb970`**.

### Unit 1b dual quality

**PASS** — keep **`accept-with-gaps`**.

---

## Unit 2a — `0x0054fec0` Skill_StoreEffectPresenceFlags_Inferred

### Body / ABI seal (independent)

```text
0x0054fef8 − 0x0054fec0 + 1 = 0x39 = 57 B
```

| Claim | Independent result |
|---|---|
| Range `0x0054fec0`–`0x0054fef8` inclusive (**57 B**); `CC` pad | **Confirmed** |
| Entry `56 8B F1 E8 18 7D 0D 00` → call **`0x00627be0`** | **Confirmed** by relative-call arithmetic |
| **`__fastcall`/`__thiscall`**; ECX = skill*; void; plain `ret` | **Confirmed** (raw + dual) |
| `mask = Skill_ComputeEffectPresenceFlags_Inferred(skill)` | **Confirmed** (raw single callee) |
| `+0x620==0` → `+0x624 = mask` plain | **Confirmed** |
| else `+0x624 = mask \| 4`; if `+0x148==0` then `+0x620 \|= 0x100000` | **Confirmed** |
| Does **not** Evaluate | **Confirmed** — no Evaluate call; body only 57 B |
| Static callers: **none** | **Accepted** (dual xrefs empty; dual B correctly does not overclaim reachability) |
| Twin store inlined in `Skill_ReevaluateForCurrentRank` (`0x00553390`) | **Accepted** as dual claim (CF identity of store tail; not OWN dual of Reevaluate) |
| Name `_Inferred` | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
void __fastcall FUN_0054fec0(int param_1)
{
  uint uVar1 = FUN_00627be0();
  if (*(uint *)(param_1 + 0x620) == 0) {
    *(uint *)(param_1 + 0x624) = uVar1;
  } else {
    *(uint *)(param_1 + 0x624) = uVar1 | 4;
    if (*(char *)(param_1 + 0x148) == '\0') {
      *(uint *)(param_1 + 0x620) = *(uint *)(param_1 + 0x620) | 0x100000;
      return;
    }
  }
  return;
}
```

Clean matches (early-return on zero-`+0x620` is behavior-equivalent fallthrough).

### Adversarial attacks (Store)

| # | Attack | Result |
|---|---|---|
| 1 | This unit **is** `Skill_ReevaluateForCurrentRank` | **Fails** — no Evaluate; different VA; 57 B |
| 2 | Body **computes** presence bits (is the leaf) | **Fails** — single call to `00627be0` |
| 3 | Always ORs `4` into `+0x624` | **Fails** — plain store when `+0x620==0` |
| 4 | Always sets `0x100000` on `+0x620` | **Fails** — requires `+0x620!=0` **and** `+0x148==0` |
| 5 | `or al,4` is partial-byte not dword `|4` | **Benign** — bit2 of EAX is full dword bit 2 |
| 6 | Active static callers exist | **Overstated if claimed** — dual correctly reports zero xrefs |
| 7 | Product English sealed | **Fails** — `_Inferred` |
| 8 | Bit-exact / runtime Confirmed | **Fails** — open |

### Soft niggles

1. **Zero static callers** — may be dead extract or dynamic-only; dual treats as gap, not CF reject. Port still useful as shared helper twin of Reevaluate store.
2. Bit `4` / `0x100000` / gate `+0x148` product English open (shared residual with Reevaluate).

### Unit 2a dual quality

**PASS** — keep **`accept-with-gaps`**.

---

## Unit 2b — `0x00627ec0` Skill_ComputeEffectScore_Inferred

### Body / ABI seal (independent)

```text
0x00628516 − 0x00627ec0 = 0x756 = 1878 B  (exclusive end per dual)
```

| Claim | Independent result |
|---|---|
| Body `0x00627ec0`–`0x00628516` exclusive (**1878 B** / `0x756`) | **Confirmed** (size math) |
| **`__fastcall`/`__thiscall`**; ECX = skill*; **EAX = (int)ceil(score)**; plain ret | **Confirmed** (raw return `(int)ROUND(ceil)`) |
| First act: call presence leaf `FUN_00627be0` | **Confirmed** (raw) |
| Gates banks on bits `1`, `0x100`, `0x40`, `8`, `2`, `0x800`, `0x10`, `0x1000` | **Confirmed** (raw if cascade) |
| Float pool values (dual `read_memory` seal) | **Accepted as dual-sealed** — 0.35 / 0.5 / 1.2 / 0.2 / 0.125 / 5.0 / 0.8 / 10000 / ~1/3 / 1.0 / 2.0 / 0.1 / 0.001 (live read not re-run this session) |
| Floor score ≥ **1.0**; return **ceil** int | **Confirmed** (raw) |
| Does **not** write `+0x624` | **Confirmed** — pure compute |
| Bits `0x800`/`0x1000` from base path (leaf ORs `skill+0xc`) | **Accepted** — score uses those flags; dual B correctly rejects “scan-only” origin |
| Callers: 11 UNCONDITIONAL_CALL dual-score pattern | **Accepted** (dual A list; pattern sealed @ hosts) |
| Name `_Inferred` | **Correct hygiene** |

### Offset map (short* decomp → clean bytes) — independent

| Raw `extraout_ECX` form | Byte offset | Clean |
|---|---|---|
| `[0x30]` / `[0x2a]` | `+0x60` / `+0x54` | pair bank 0x1 |
| `*(float*)(+0x1a)` / `(+0x14)` | `+0x34` / `+0x28` | scale after bank 0x1 |
| `byte*(+0x29) & 1` | `+0x52` | bit scale |
| `[0x48]` / `[0x3c]` | `+0x90` / `+0x78` | bank 0x100 |
| `*(int*)(+0xc)` | `+0x18` | duration-linked 0x40 + duration scale |
| `[0x36]`… | `+0x6c`… | signed bank 0x8 |
| `*(float*)(+0x1e)` | `+0x3c` | bank 0x2 |
| `*extraout_ECX` | `+0` | bank 0x800 |
| `byte*(+0x6d)` | `+0xda` | bank 0x10 |
| `*(float*)(+0x26)` | `+0x4c` | ungated bonus |
| `*(int*)(+8)` / `(+0xe)` | `+0x10` / `+0x1c` | duration / charge scales |

Clean `Skill_ComputeEffectScore_Inferred.cpp` matches these offsets and the gated bank structure, floor, and ceil.

### Adversarial attacks (Score)

| # | Attack | Result |
|---|---|---|
| 1 | Stores `skill+0x624` | **Fails** — no stores; pure float → ceil |
| 2 | Is the presence leaf itself | **Fails** — calls `00627be0`; large weighted body |
| 3 | Always scores all banks | **Fails** — each bank behind bit test |
| 4 | Bits `0x800`/`0x1000` come only from field scan | **Fails** — dual/leaf: OR from base `skill+0xc` |
| 5 | Return is float score | **Fails** — `(int)ceil` |
| 6 | Single-skill UI-only consumer | **Fails** — dual-score compare callers |
| 7 | Product metric English (threat/DPS) sealed | **Fails** — `_Inferred` |
| 8 | Global name `g_flLevelUpUiBase_Inferred` proves level-up UI role here | **Overstated name only** — value sealed **2.0f** as literal two |
| 9 | Bit-exact / float ulp Confirmed | **Fails** — open |

### Soft niggles

1. **Decompiler goto soup** on signed-short bank (`flags & 8`) — dual B marks Med confidence on branch shape vs compiler; clean mirrors raw, not a sealed CF invent.
2. **Full named dual of every caller host** open — dual correctly seals dual-score *pattern*, not every host product name.
3. Float pool **re-read** not available this ADV session; values accepted from dual 2026-08-04 `read_memory` seal + clean constants matching those seals.

### Unit 2b dual quality

**PASS** — keep **`accept-with-gaps`**.

---

## Cross-unit consistency

### WQ9E-A pair (destroy ↔ alloc)

| Topic | Independent |
|---|---|
| Pair relationship | **Confirmed** — recreate: destroy → seed log2/count → alloc; ctor: field init → alloc; dtor: destroy |
| Free/alloc free-shape match | **Confirmed** — alloc `new[]` + `malloc` slab; destroy `free(*table)` + `delete[]` |
| Mask lifecycle | Callers seed **count** `1<<log2` at `+8`; alloc converts to **mask**; destroy leaves `+8` untouched |
| Shared ABI | Both **thiscall ECX=hash**, bare ret (alloc throw on bad log2) |
| Inventory contrast | Shared *family* free/alloc shape; **skill** thiscall + stamp `009cb970` vs inventory EAX + other stamps |
| Parent WQ9D mask post-condition | **Holds** only because this OWN alloc dual is correct |

```text
Object_CreateOrRecreateSkillHash_Inferred (0x00518e30)
  ├─ existing +0x70 → SkillCNDHash_Recreate_Inferred (0x004cbdc0)   [WQ9D-A]
  │     ├─ SkillCNDHash_DestroyBucketTable_Inferred (0x004cba60)  [WQ9E-A]
  │     │     └─ FUN_004cb680 freelist release                     [residual]
  │     └─ SkillCNDHash_AllocBucketTable_Inferred (0x004cb410)    [WQ9E-A]
  └─ missing → new(0x34) + SkillCNDHash_Ctor_Inferred (0x0051dd60) [WQ9D-A]
        └─ SkillCNDHash_AllocBucketTable_Inferred (0x004cb410)    [WQ9E-A]
Skill hash dtor FUN_0051de80
  └─ SkillCNDHash_DestroyBucketTable_Inferred (0x004cba60)        [WQ9E-A]
```

### WQ9E-B pair (store ↔ score)

| Topic | Independent |
|---|---|
| Shared callee | Both call **`Skill_ComputeEffectPresenceFlags_Inferred` (`0x00627be0`)** |
| Orthogonal roles | Store writes `+0x624` (+ optional `+0x620`); score is pure float→ceil — **no merge** |
| Presence bit map | Score gates must stay locked to presence leaf bit definitions |
| Reevaluate relationship | Store helper is extract/twin of post-Evaluate store; score is separate HB-priority consumer |
| Port rule | Do not Evaluate inside store; do not write `+0x624` inside score |

```text
Skill_ComputeEffectPresenceFlags_Inferred (0x00627be0)  [WQ9D-E]
  ├─ Skill_StoreEffectPresenceFlags_Inferred (0x0054fec0)  [WQ9E-B] → +0x624
  │     twin store inlined in Skill_ReevaluateForCurrentRank (0x00553390)
  └─ Skill_ComputeEffectScore_Inferred (0x00627ec0)       [WQ9E-B] → ceil int
        └─ dual-score callers (HB/conflict compare)
```

---

## Confirmations

1. WQ9E-A dual A/B + agent report seals for destroy/alloc are **faithful** to raw decompile, free/alloc shape, log2 gate, mask post-condition, and parent recreate/ctor call chain.
2. WQ9E-B dual A/B + agent report seals for store/score are **faithful** to raw CF, relative-call identity of presence leaf, conditional `|4`/`|0x100000`, and presence-gated score structure + ceil floor.
3. Dual B correctly rejects: inventory EAX merge, free-table-as-slab, soft-fail-on-bad-log2, mask-as-count-after, Evaluate-merge, always-|4, store-vs-score merge, all-banks scoring.
4. Clean named sources match raw semantics; `_Inferred` hygiene correct; terminal false.
5. Parent WQ9D recreate mask post-condition is independently re-validated via OWN alloc raw.

---

## Gaps (remain open — dual already owns)

| Gap | Unit | Blocks accept? |
|---|---|---|
| Product / PDB class English for skill CNDHash / stamp `009cb970` | 1a/1b | No |
| Full dual of freelist helper `FUN_004cb680` | 1a | No |
| OOM intentionality (no null checks) | 1b | No |
| Why store VA has zero static callers | 2a | No |
| Bit `4` / `0x100000` / `+0x148` English | 2a | No |
| Product score metric English (threat/priority/DPS) | 2b | No |
| Exhaustive bank combat labels + full named callers | 2b | No |
| Runtime / bit-exact / float ulp differential | All | No (policy; terminal false) |

---

## Pass / fail

| Unit | Dual verdict | ADV result |
|---|---|---|
| `0x004cba60` SkillCNDHash_DestroyBucketTable_Inferred | **accept-with-gaps** | **PASS** — retain **accept-with-gaps** |
| `0x004cb410` SkillCNDHash_AllocBucketTable_Inferred | **accept-with-gaps** | **PASS** — retain **accept-with-gaps** |
| `0x0054fec0` Skill_StoreEffectPresenceFlags_Inferred | **accept-with-gaps** | **PASS** — retain **accept-with-gaps** |
| `0x00627ec0` Skill_ComputeEffectScore_Inferred | **accept-with-gaps** | **PASS** — retain **accept-with-gaps** |

### Overall

**PASS** — WQ9E-A and WQ9E-B dual seals hold under independent multi-source verification (raw + dual re-verify byte seals + clean CF match + parent WQ9D chain + inventory ABI contrast + relative-call arithmetic for presence leaf). No sealed-claim failure requiring dual rewrite or verdict downgrade.

Soft residuals only: undualed freelist helper; zero static callers on store extract; product English on stamps/bits/score metric; float pool not re-read live this session (accepted from dual seal).

**terminal = false**

---

## Process notes

- Independent ADV verifier; **not** WQ9E-A / WQ9E-B dual author.
- **No** parent ledger / WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY edits.
- **No** dual A/B rewrite; **no** Launcher.
- Live Ghidra MCP not callable from this ADV session tool surface (localhost SSRF); verification uses sealed raw, dual 2026-08-04 re-verify claims, clean sources, parent WQ9D ADV/raws, inventory contrast raw, and independent size/call/throw arithmetic.
- Output: `docs/reconstruction/reviews/ADV_wq9e_spotcheck_hash_presence.md` (this file).
