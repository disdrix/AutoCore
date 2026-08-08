# Independent adversarial spot-check — WQ9F freelist + buynode twins

| Field | Value |
|---|---|
| **Date** | `2026-08-04` |
| **Role** | Independent adversarial verifier (**not** dual author WQ9F-A / WQ9F-B) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | `WAVE_2026-08-04_wq009_depth3_partition_map.md` → **WQ9F-A** (freelist + no-SEH buynode), **WQ9F-B** (SEH buynode only for this ADV) |
| **Units** | (1) `0x004cb680` `SkillCNDHash_ReleaseChainsToFreelist_Inferred`; (2) `0x005a2de0` `StdTree_Buynode_Isnil29_Val24_Inferred`; (3) `0x00407e30` `StdTree_Buynode_Val24_Isnil29_Inferred` |
| **Tools** | Dual reports + A/B + raw/annotated/clean + function records + parent destroy raw + insert caller raws + ctor helper raw + Val12 buynode contrast raw + prior WQ9E ADV residual notes |
| **Live Ghidra this session** | MCP HTTP `127.0.0.1:8089` **not reachable** (localhost SSRF block). Claims re-checked against sealed raw decompile + dual 2026-08-04 re-verify byte seals + parent/insert caller raws |
| **Forbidden** | `disassemble_bytes`; parent ledger edits; dual rewrite; Launcher |
| **Image** | `autoassault.exe` base `0x400000` |
| **Terminal** | **false** |

---

## Inspected evidence

### Dual / report surfaces

| Path |
|---|
| `docs/agents/task-dual-ab-004cb680-005a2de0-wq9fa-report.md` |
| `docs/agents/task-dual-ab-00407e30-004c8610-wq9fb-report.md` (unit `00407e30` only for this ADV) |
| `docs/reconstruction/reviews/A_aa_004cb680_SkillCNDHash_ReleaseChainsToFreelist_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_004cb680_SkillCNDHash_ReleaseChainsToFreelist_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_005a2de0_StdTree_Buynode_Isnil29_Val24_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_005a2de0_StdTree_Buynode_Isnil29_Val24_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_00407e30_StdTree_Buynode_Val24_Isnil29_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_00407e30_StdTree_Buynode_Val24_Isnil29_Inferred.md` |

### Artifacts (three units)

| Kind | `004cb680` | `005a2de0` | `00407e30` |
|---|---|---|---|
| Raw (+ re-verify) | `raw/aa_004cb680_FUN_004cb680.md` | `raw/aa_005a2de0_FUN_005a2de0.md` | `raw/aa_00407e30_FUN_00407e30.md` |
| Annotated | `…FUN_004cb680.annotated.md` | `…FUN_005a2de0.annotated.md` | `…FUN_00407e30.annotated.md` |
| Clean named | `SkillCNDHash_ReleaseChainsToFreelist_Inferred.cpp` | `StdTree_Buynode_Isnil29_Val24_Inferred.cpp` | `StdTree_Buynode_Val24_Isnil29_Inferred.cpp` |
| Function named | `aa_004cb680_SkillCNDHash_…` | `aa_005a2de0_StdTree_Buynode_Isnil29_…` | `aa_00407e30_StdTree_Buynode_Val24_…` |

### Support / contrast evidence (not OWN duals)

| Artifact | Use |
|---|---|
| `raw/aa_004cba60_FUN_004cba60.md` + prior ADV_wq9e hash_presence | Sole freelist caller; zeros `+0x0c` then calls `004cb680` then free slab/table |
| `raw/aa_004cbb60_FUN_004cbb60.md` | Insert consumer of `005a2de0` — `(head, where, head, value, 0)` → uses EAX as node* |
| `raw/aa_00406c40_FUN_00406c40.md` | Insert consumer of `00407e30` — same arg shape, color=0 |
| `raw/aa_004098d0_FUN_004098d0.md` | SEH-buynode ctor: L/P/R + 6 dwords @+0x10 + color@+0x28 + isnil0@+0x29 |
| `raw/aa_005ae220_FUN_005ae220.md` | Val12 buynode contrast — `new(0x1c)`, value@+0x0c, isnil@+0x19, still `ret 0x14` |
| `ADV_wq9e_spotcheck_hash_presence.md` | Prior residual: freelist `004cb680` left open under destroy |
| `ADV_wq9e_spotcheck_ui_erase.md` | Prior residual: insert `004cbb60` uses buynode `005a2de0` |

### Evidence cross-check matrix

| Check | Result |
|---|---|
| Raw 2026-07-23 decompile ≡ dual A CF tables | **Yes** (all three) |
| Dual re-verify 2026-08-04 claims live ≡ raw | Stated **identical**; body ends + entry/exit hex recorded |
| Clean named ≡ raw CF | **Yes** (all three; SEH frame omitted honestly on `00407e30`) |
| Body-size arithmetic (inclusive/exclusive per dual) | **Yes** (see unit sections) |
| Parent destroy calls freelist before table free | **Yes** — `004cba60` raw: zero `+0xc` → `FUN_004cb680` → free/`delete[]` |
| Insert `004cbb60` uses `FUN_005a2de0` return as node* | **Yes** — `piVar4 = (int *)FUN_005a2de0(...)` then size++/link |
| Insert `00406c40` uses `FUN_00407e30` return as node* | **Yes** — `piVar3 = (int *)FUN_00407e30(...)` then size++/link |
| Ctor `004098d0` layout ≡ inlined `005a2de0` layout | **Yes** — same L/P/R / Val24 / color / isnil0 |
| Val12 contrast size/offsets | **Yes** — `0x1c` / isnil@+0x19 vs `0x30` / isnil@+0x29 |
| Twin non-merge (`00407e30` SEH+ctor vs `005a2de0` inlined) | **Holds** — distinct VAs, callers, body shapes |
| Prior WQ9E residual freelist open | **Closed** by WQ9F-A dual |

---

## Unit 1 — `0x004cb680` SkillCNDHash_ReleaseChainsToFreelist_Inferred

### Body / ABI seal (independent)

```text
0x004cb6e1 − 0x004cb680 + 1 = 0x62 = 98 B
```

| Claim | Independent result |
|---|---|
| Range `0x004cb680`–`0x004cb6e1` inclusive (**98 B** / `0x62`); terminal `5F 5E 5D 5B C3` + `CC` pad | **Confirmed** (size math + dual re-verify end/entry hex) |
| **`__thiscall`**; entry `53 55 56 8B D9` (`push ebx/ebp/esi; mov ebx,ecx`) | **Confirmed** |
| **Bare `ret`** (`C3`); void; no stack args | **Confirmed** |
| Bucket loop `0..mask(@+0x08)` **inclusive** (`uVar4 <= *(hash+8)`) | **Confirmed** (raw `while` condition) |
| Chain head = `table[i]` bucket then `bucket[+4]` | **Confirmed** |
| Next via `node[+0xc]`; payload `@+0x08` → conditional `operator_delete` | **Confirmed** |
| Temp stamp `PTR_FUN_009cb968` then freelist overwrite of `*node` | **Confirmed** (stamp then `*node = freelist; freelist = node`) |
| Freelist head `@ hash+0x20` | **Confirmed** |
| Clear bucket head after drain; does **not** free table/slab or zero `+0x0c`/`+0x08` | **Confirmed** — parent destroy owns those |
| Sole caller `004cba60` @ `004cba6a` | **Accepted** (dual re-verify + parent destroy raw call) |
| Decomp false-noreturn on `operator_delete` | **Confirmed artifact** — raw continues freelist push after call |
| Name `_Inferred` / product English open | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
void __fastcall FUN_004cb680(int param_1) // thiscall ECX=hash
{
  uint uVar4 = 0;
  do {
    undefined4 *puVar3 =
      *(undefined4 **)(*(int *)(*(int *)(param_1 + 0x10) + uVar4 * 4) + 4);
    while (puVar3 != 0) {
      undefined4 *puVar2 = (undefined4 *)puVar3[3];   // next +0xc
      *puVar3 = &PTR_FUN_009cb968;                    // temp stamp
      if ((void *)puVar3[2] != 0) {
        /* decomp false-noreturn */ operator_delete((void *)puVar3[2]);
      }
      puVar3[2] = 0;
      *puVar3 = *(undefined4 *)(param_1 + 0x20);      // freelist push
      *(undefined4 **)(param_1 + 0x20) = puVar3;
      puVar3 = puVar2;
    }
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x10) + uVar4 * 4) + 4) = 0;
    uVar4 = uVar4 + 1;
  } while (uVar4 <= *(uint *)(param_1 + 8));          // mask inclusive
  return; // bare ret
}
```

Clean `SkillCNDHash_ReleaseChainsToFreelist_Inferred.cpp` matches CF (mask-inclusive; payload delete; freelist `@+0x20`; stamp-then-overwrite; no table free).

### Adversarial attacks (freelist)

| # | Attack | Result |
|---|---|---|
| 1 | Custom EAX ABI (inventory freelist style) | **Fails** — entry `mov ebx,ecx`; bare `ret` |
| 2 | Frees table / slab itself | **Fails** — only chains + freelist; parent `004cba60` frees |
| 3 | `operator_delete` noreturn kills rest of body | **Fails** — freelist push + loop continue after call |
| 4 | Loop is `i < mask` (excludes last bucket) | **Fails** — `<= mask` inclusive |
| 5 | Stamp `009cb968` remains on freelist nodes | **Fails** — immediately overwritten by freelist next |
| 6 | Zeros live count / mask | **Fails** — no writes to `+0x0c` / `+0x08` |
| 7 | Multiple direct callers | **Fails** — sole destroy nested helper |
| 8 | Full hash dtor / recreate role | **Fails** — nested under destroy only |
| 9 | Product class English sealed | **Fails** — `_Inferred` |
| 10 | Bit-exact / runtime Confirmed | **Fails** — open; no Launcher |

### Soft niggles (not sealed-claim failures)

1. Freelist **pop / host teardown** consumer still open (dual gap) — role of *this* unit remains High from destroy nesting + freelist push shape.
2. Product node class behind `009cb968` open — naming only.

### Unit 1 dual quality

**PASS** — keep **`accept-with-gaps`**.

---

## Unit 2 — `0x005a2de0` StdTree_Buynode_Isnil29_Val24_Inferred

### Body / ABI seal (independent)

```text
0x005a2e3a − 0x005a2de0 + 1 = 0x5B = 91 B
```

| Claim | Independent result |
|---|---|
| Range `0x005a2de0`–`0x005a2e3a` inclusive (**91 B** / `0x5B`); terminal **`C2 14 00`** + `CC` | **Confirmed** (size math + dual exit bytes) |
| **`__stdcall`**; 5 stack args; **RET 0x14** | **Confirmed** |
| **EAX = node\*** (null on OOM); decomp `void` is wrong | **Confirmed** — insert casts return to `int*` and uses as new node |
| `operator_new(0x30)` | **Confirmed** (raw + entry `6A 30`) |
| L/P/R; **6 dwords** value @ **+0x10**; color @ **+0x28**; isnil=0 @ **+0x29** | **Confirmed** — raw `puVar1[4..9]`; `(puVar1+10)` color; `+0x29` |
| Does **not** write `+0x0c` | **Confirmed** (value starts at dword index 4) |
| Callers: `004cbb60`, `0058da40`, `005a3310` (3) | **Accepted** (dual re-verify; primary insert raw confirmed) |
| Insert family passes **color=0** | **Confirmed** — `FUN_005a2de0(..., param_5, 0)` in `004cbb60` |
| Not Val12 buynode `005ae220` | **Confirmed** — contrast raw `new(0x1c)`, isnil@+0x19 |
| Distinct from SEH twin `00407e30` | **Confirmed** — inlined ctor, no SEH, different insert consumer |
| Name `_Inferred` / product English open | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
// decomp says void — wrong; EAX = node*
void FUN_005a2de0(left, parent, right, value6*, color)
{
  undefined4 *puVar1 = operator_new(0x30);
  if (puVar1 != 0) {
    *puVar1 = left; puVar1[1] = parent; puVar1[2] = right;
    puVar1[4] = value6[0]; ... puVar1[9] = value6[5];  // +0x10 .. +0x24
    *(undefined1 *)(puVar1 + 10) = color;               // +0x28
    *(undefined1 *)((int)puVar1 + 0x29) = 0;            // isnil
  }
  return; // ret 0x14 (bytes)
}
```

Clean `StdTree_Buynode_Isnil29_Val24_Inferred.cpp` matches CF/layout/ABI (stdcall ret 0x14; 0x30; Val24; isnil0).

### Adversarial attacks (no-SEH buynode)

| # | Attack | Result |
|---|---|---|
| 1 | True `void` return | **Fails** — insert uses EAX as node*; null OOM path returns 0 |
| 2 | `thiscall` / ECX map | **Fails** — pure stack; `ret 0x14` |
| 3 | Val12 twin merge (`005ae220`) | **Fails** — size 0x30≠0x1c; isnil@+0x29≠+0x19; 6≠3 dwords |
| 4 | Same symbol as SEH twin `00407e30` | **Fails** — distinct VA; SEH+ctor helper vs inlined |
| 5 | Skill-gather product leaf (scaffold name) | **Fails** — generic insert shells; no product string/RTTI here |
| 6 | Value at `+0x0c` (Val12 layout) | **Fails** — value @+0x10 |
| 7 | Throws on OOM / always non-null | **Fails** — null skip init |
| 8 | Sets isnil=1 (nil sentinel) | **Fails** — hard isnil=0 |
| 9 | Sole caller `004cbb60` | **Partial only** — **3** callers; still same buynode role |
| 10 | Product demangle sealed | **Fails** — `_Inferred` |
| 11 | Runtime Confirmed | **Fails** — no Launcher |

### Soft niggles

1. Clean plate uses `operator_new` without an `extern` declaration — plate hygiene only; CF still correct.
2. Extra insert shells `0058da40` / `005a3310` not dualled (not OWN) — same buynode shape via xrefs.
3. Twin **name order** vs `00407e30` (`Isnil29_Val24` vs `Val24_Isnil29`) is intentional disambiguation; do not collapse names in parent merge.

### Unit 2 dual quality

**PASS** — keep **`accept-with-gaps`**.

---

## Unit 3 — `0x00407e30` StdTree_Buynode_Val24_Isnil29_Inferred

### Body / ABI seal (independent)

```text
0x00407eb4 − 0x00407e30 = 0x84 = 132 B  (exclusive end)
```

| Claim | Independent result |
|---|---|
| Range `0x00407e30`–`0x00407eb4` exclusive (**132 B** / `0x84`); last insn **`RET 0x14`** @ `0x00407eb1`; pad follows | **Confirmed** (size math + dual epilogue `8B E5 5D C2 14 00`) |
| **`__stdcall`**; 5 stack args; EAX = node* \| null | **Confirmed** (raw returns `pvVar1`; insert uses cast) |
| SEH frame (`LAB_009bc6e1` / ExceptionList) | **Confirmed** (raw prologue locals) |
| `operator_new(0x30)` then ctor `FUN_004098d0` on success | **Confirmed** |
| Ctor layout: L/P/R + 6 dwords @+0x10 + color@+0x28 + isnil0@+0x29 | **Confirmed** via `aa_004098d0` raw ≡ inlined twin |
| Sole caller insert `00406c40` @ `00406cad` with color=0 | **Confirmed** (insert raw call site) |
| Distinct from no-SEH twin `005a2de0` | **Confirmed** — SEH + external ctor; different insert consumer |
| Not Val12 buynode | **Confirmed** — size/layout via ctor |
| Name `_Inferred` | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
void * FUN_00407e30(left, parent, right, value, color)
{
  // SEH: ExceptionList = &frame; filter LAB_009bc6e1
  void *pvVar1 = operator_new(0x30);
  if (pvVar1 != 0) {
    // thiscall on node (Ghidra may omit ECX=pvVar1 in call print)
    FUN_004098d0(/*this=node*/, left, parent, right, value, color);
  }
  ExceptionList = saved;
  return pvVar1; // ret 0x14
}
```

Ctor `FUN_004098d0` (support raw):

```c
void __thiscall FUN_004098d0(node, left, parent, right, value6*, color)
{
  *node = left; node[1] = parent; node[2] = right;
  node[4..9] = value6[0..5];          // +0x10 Val24
  *(byte*)(node+10) = color;          // +0x28
  *(byte*)((int)node + 0x29) = 0;     // isnil
}
```

Clean `StdTree_Buynode_Val24_Isnil29_Inferred.cpp` matches CF (new 0x30; null skip; ctor; stdcall ret 0x14). SEH omitted in plate with explicit note — honest, not a CF claim failure.

### Adversarial attacks (SEH buynode)

| # | Attack | Result |
|---|---|---|
| 1 | thiscall ECX=map | **Fails** — pure stack; RET 0x14 |
| 2 | void return / no pointer | **Fails** — returns `pvVar1`; insert uses it |
| 3 | Value is 1 dword key only | **Fails** — ctor copies 6 dwords |
| 4 | isnil set from color arg | **Fails** — hard isnil=0 @+0x29 |
| 5 | Merge with `005a2de0` same body | **Fails** — SEH+ctor vs inlined; different callers |
| 6 | Val12 / placement-new freelist buy | **Fails** — CRT `new(0x30)` |
| 7 | Product English proven | **Fails** — `_Inferred` |
| 8 | Ctor dual complete | **Fails** — residual undualed (not OWN) |
| 9 | Runtime Confirmed | **Fails** — open |

### Soft niggles

1. Ctor helper `FUN_004098d0` remains undualed — layout already sealed by raw decompile identity with inlined twin.
2. Clean omits SEH — documented; retail has ExceptionList frame.
3. Twin name order vs unit 2 — keep both; peer-list in registry rather than merge.

### Unit 3 dual quality

**PASS** — keep **`accept-with-gaps`**.

---

## Cross-unit dual report quality

| Check | `004cb680` | `005a2de0` | `00407e30` |
|---|---|---|---|
| Dual report verdicts match A/B | **Yes** — both **accept-with-gaps** | **Yes** | **Yes** |
| Terminal false honesty | **Yes** | **Yes** | **Yes** |
| OWN scope discipline | WQ9F-A pair | WQ9F-A pair | WQ9F-B (with aggro unit not ADV'd here) |
| Tool discipline (no `disassemble_bytes`) | **Yes** | **Yes** | **Yes** (uses `disassemble_function` + `read_memory` only) |
| Decompiler artifact honesty | false-noreturn delete; `__fastcall` print for thiscall | void vs EAX | SEH; ctor thiscall print |
| Odd behavior preserved | stamp-then-freelist overwrite | OOM null no throw | SEH around new/ctor |
| Clean sources meaningful + own VA | **Yes** | **Yes** | **Yes** |
| Peer non-merge hygiene | ≠ inventory freelist; ≠ parent destroy | ≠ Val12; ≠ SEH twin | ≠ Val12; ≠ no-SEH twin |
| AutoCore port notes | drain-to-freelist before free | stdcall ret 0x14 / 0x30 | shared Val24 isnil29; do not merge twins |

### Twin relationship (port guard)

```text
Insert 0x00406c40  ──buynode──► 0x00407e30  (SEH + FUN_004098d0)   name: …_Val24_Isnil29_…
Insert 0x004cbb60  ──buynode──► 0x005a2de0  (inlined, no SEH)      name: …_Isnil29_Val24_…
Val12  insert family ──buynode──► 0x005ae220  (0x1c / isnil@+0x19)  DO NOT MERGE

Destroy 0x004cba60 ──freelist──► 0x004cb680  (mask-inclusive chain drain → +0x20)
```

Same **layout contract** (0x30 / Val24 / color@+0x28 / isnil@+0x29) across both Val24 buynodes; **different bodies and caller families** — port as shared layout template only, not one VA.

### Independent overall verdict

| Unit | Dual verdict | ADV verdict |
|---|---|---|
| `aa_004cb680` SkillCNDHash_ReleaseChainsToFreelist_Inferred | accept-with-gaps | **PASS — keep accept-with-gaps** |
| `aa_005a2de0` StdTree_Buynode_Isnil29_Val24_Inferred | accept-with-gaps | **PASS — keep accept-with-gaps** |
| `aa_00407e30` StdTree_Buynode_Val24_Isnil29_Inferred | accept-with-gaps | **PASS — keep accept-with-gaps** |

### Overall ADV

**PASS**

Sealed freelist CF/ABI and both Val24 isnil29 buynode contracts hold under independent adversarial re-check. Prior WQ9E residual that left `004cb680` / `005a2de0` open is correctly closed by WQ9F duals. No sealed-claim failure; gaps (product English, freelist pop dual, ctor dual, runtime) remain appropriately open. Terminal **false**.

### Residual risks (not dual failures)

| Risk | Severity | Notes |
|---|---|---|
| Live Ghidra unreachable this ADV session | Process | Mitigated by dual 2026-08-04 re-verify byte seals + raws + caller raws |
| Freelist pop / host teardown undualed | Residual | Does not undermine release-to-freelist role |
| `FUN_004098d0` undualed | Residual | Layout sealed by raw identity with inlined twin |
| Insert clean-name collision for `004cbb60` vs `00406c40` (prior WQ9E ADV) | Peer hygiene | **Does not** affect these three OWN clean plates (each has unique named path) |
| Twin name order inversion | Naming | Keep both; registry peer-list; do not merge VAs |

---

## Process

- Independent ADV only; **not** dual author for WQ9F-A / WQ9F-B.
- No parent ledger edits; no dual rewrite; no Launcher.
- No `disassemble_bytes`.
- Live Ghidra HTTP blocked; evidence from sealed dual re-verify + raw/annotated/clean + parent/insert/ctor/Val12 support raws.
- **Terminal false.**

### Output

| Kind | Path |
|---|---|
| This report | `docs/reconstruction/reviews/ADV_wq9f_spotcheck_freelist_buynode.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
