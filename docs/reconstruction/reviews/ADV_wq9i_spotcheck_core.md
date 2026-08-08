# Independent adversarial spot-check — WQ9I core (freelist teardown / isnil21 insert+map / host recreate BL2)

| Field | Value |
|---|---|
| **Date** | `2026-08-05` |
| **Role** | Independent adversarial verifier (**not** dual author WQ9I-A / WQ9I-B / WQ9I-C / WQ9I-D) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | `WAVE_2026-08-04_wq009_depth6_partition_map.md` → **WQ9I** core residual units |
| **Units** | (1) `0x00416e80` FreelistSlabVector_Teardown; (2) `0x00407200` StdTree_InsertAndRebalance_Isnil21; (3) `0x00407060` StdMap_InsertOrFind_PairKey_Isnil21; (4) `0x007fe640` Host_CNDHash_TraverseTeardownThenRecreate_BL2 |
| **Tools** | Dual A/B + agent reports + raw/annotated/clean + function records + parent/peer cleans (`CNDHash_Dtor_00a2c2b0`, `CNDHash_Recreate_00a2c2e4`, `FUN_00406560`) + prior ADV `ADV_wq9h_spotcheck_cndhash.md` + independent body-size / hex decode |
| **Live Ghidra this session** | Not re-dispatched from this ADV tool surface. Claims re-checked against sealed raw decompile + dual 2026-08-04/05 re-verify byte seals + continuous body hex (00407060) + clean CF. **No** `disassemble_bytes`. |
| **Forbidden** | `disassemble_bytes`; parent ledger edits; dual A/B rewrite; Launcher |
| **Image** | `autoassault.exe` base `0x400000` |
| **Terminal** | **false** |

---

## Inspected evidence

### Dual / report surfaces

| Path |
|---|
| `docs/agents/task-dual-ab-00416e80-00409db0-wq9ia-report.md` (OWN freelist half) |
| `docs/agents/task-dual-ab-00409f30-00407200-wq9ib-report.md` (OWN insert half) |
| `docs/agents/task-dual-ab-00407060-004099b0-wq9ic-report.md` (OWN InsertOrFind half) |
| `docs/agents/task-dual-ab-0040a6e0-007fe640-wq9id-report.md` (OWN host recreate half) |
| `docs/reconstruction/reviews/A_aa_00416e80_FreelistSlabVector_Teardown_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_00416e80_FreelistSlabVector_Teardown_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_00407200_StdTree_InsertAndRebalance_Isnil21_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_00407200_StdTree_InsertAndRebalance_Isnil21_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_00407060_StdMap_InsertOrFind_PairKey_Isnil21_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_00407060_StdMap_InsertOrFind_PairKey_Isnil21_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_007fe640_Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_007fe640_Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred.md` |

### Artifacts (four units)

| Kind | `00416e80` | `00407200` | `00407060` | `007fe640` |
|---|---|---|---|---|
| Raw (+ re-verify) | `raw/aa_00416e80_FUN_00416e80.md` | `raw/aa_00407200_FUN_00407200.md` | `raw/aa_00407060_FUN_00407060.md` | `raw/aa_007fe640_FUN_007fe640.md` |
| Annotated | `…FUN_00416e80.annotated.md` | `…FUN_00407200.annotated.md` | `…FUN_00407060.annotated.md` | `…FUN_007fe640.annotated.md` |
| Clean named | `FreelistSlabVector_Teardown_Inferred.cpp` | `StdTree_InsertAndRebalance_Isnil21_Inferred.cpp` | `StdMap_InsertOrFind_PairKey_Isnil21_Inferred.cpp` | `Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred.cpp` |
| Scaffold twin | `FUN_00416e80.cpp` | `FUN_00407200.cpp` | `FUN_00407060.cpp` | `FUN_007fe640.cpp` |
| Function named | `aa_00416e80_FreelistSlabVector_…` | `aa_00407200_StdTree_Insert…` | `aa_00407060_StdMap_Insert…` | `aa_007fe640_Host_CNDHash_…` |

### Support / contrast evidence (not OWN duals)

| Artifact | Use |
|---|---|
| `CNDHash_Dtor_00a2c2b0.cpp` / `raw/aa_00406420_*` | Parent: `PUSH this+0x20` → freelist teardown |
| `CNDHash_Recreate_00a2c2e4.cpp` / WQ9H-E dual | Nested recreate EAX/BL; sole host caller residual closed by `007fe640` |
| `FUN_00406560.cpp` InsertHint isnil21 | Sole caller of InsertOrFind; multi-site caller of always-insert |
| Peer isnil29 insert `00406c40` / pair `004cbee0` | CF-shape twins; **must not merge VAs** |
| Twin freelist thiscall `0x0059c8a0` | Same CF, different ABI (bare ret vs ret4) |
| Prior `ADV_wq9h_spotcheck_cndhash.md` | Host field `+0x3084` + recreate family seals |
| Reject plate `Named_VOG_DEBUG_STOP_007fe640.cpp` | Assert-string scaffold correctly demoted |

### Evidence cross-check matrix

| Check | Result |
|---|---|
| Raw decompile ≡ dual A CF tables | **Yes** (all four) |
| Dual re-verify claims live ≡ raw + entry/exit hex | Stated **identical**; body ends recorded |
| Clean named ≡ raw CF (plus documented decomp overrides) | **Yes** (all four; freelist always-zero + host BL=2 are byte overrides) |
| Body-size arithmetic (inclusive/exclusive per dual) | **Yes** (see unit sections) |
| Clean plate VA binding unique (no isnil29-style collision) | **Yes** — each named clean cites one OWN VA; scaffolds redirect |
| Parent dtor → freelist `+0x20` | **Yes** — dtor clean + freelist dual callers |
| InsertOrFind → always-insert `00407200` | **Yes** — raw calls ×2; both dualed this batch |
| Host → recreate `004195d0` with BL=2 | **Yes** — recreate plate + host epilogue bytes |
| Terminal / runtime Confirmed | **Not claimed** (policy; terminal false) |

---

## Unit 1 — `0x00416e80` FreelistSlabVector_Teardown_Inferred

### Body / ABI seal (independent)

```text
0x00416ef6 − 0x00416e80 + 1 = 0x77 = 119 B  (inclusive end)
```

| Claim | Independent result |
|---|---|
| Range `0x00416e80`–`0x00416ef6` inclusive (**119 B** / `0x77`); pad `CC` | **Confirmed** (size math + dual re-verify) |
| **stdcall** stack freelist*; **`ret 4`** (`C2 04 00`) | **Confirmed** — raw re-verify epilogue; dual B falsifies thiscall |
| Loop `[begin,end)` @ +0x08/+0x0c; `_aligned_free(*it)`; stride 4 | **Confirmed** (raw + annotated) |
| `operator_delete(begin)` when non-null **returns** | **Confirmed** — bytes fall-through; decomp false-noreturn overridden |
| **Always** zero +0x08 / +0x0c / +0x10 | **Confirmed** — both paths; dual B falsifies null-only zero |
| Does **not** walk freelist head @ +0x00 | **Confirmed** — only triad at +8 |
| Callers push freelist base (`hash+0x20`); twin `0059c8a0` thiscall bare ret | **Confirmed** (parent dtor clean + dual) |
| Product English open → `_Inferred` | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
// stdcall; ret 4 — stack freelist*
void FUN_00416e80(int param_1 /* freelist* */)
{
  // SEH LAB_009bc71b
  void **it = *(void ***)(param_1 + 8);
  void **end = *(void ***)(param_1 + 0xc);
  while (it != end) {
    _aligned_free(*it);
    ++it; // +4
  }
  // decomp shows exclusive zero on null-begin then noreturn delete — BYTES OVERRIDE:
  if (*(void **)(param_1 + 8) != 0)
    operator_delete(*(void **)(param_1 + 8)); // RETURNS
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  // ret 4
}
```

Clean `FreelistSlabVector_Teardown_Inferred.cpp` matches sealed CF (always triad zero after optional delete).

### Adversarial attacks (Freelist teardown)

| # | Attack | Result |
|---|---|---|
| 1 | Thiscall ECX=hash like twin `0059c8a0` | **Fails** — stack arg; `ret 4` |
| 2 | `operator_delete` never returns (decomp) | **Fails** — fall-through to zeros |
| 3 | Zero only on null-begin path | **Fails** — always zero triad |
| 4 | Walks freelist head chain @ +0 | **Fails** — only +8 triad |
| 5 | Element stride 0xC / 0x28 (vector T) | **Fails** — `add esi,4` pointer array |
| 6 | Same as DestroyBucketTable | **Fails** — distinct VA; only aligned_free + buffer delete |
| 7 | Merge VA with twin `0059c8a0` | **Fails** — same CF, different ABI |
| 8 | Product `std::vector<void*>` sealed | **Fails** — `_Inferred` |
| 9 | Runtime / bit-exact Confirmed | **Fails** — open |

### Soft niggles (not sealed-claim failures)

1. Clean lacks explicit `__stdcall` attribute — ABI sealed in plate comment / dual.
2. SEH frame omitted from clean body (documented).
3. Sibling undualed scaffolds (`FUN_00413850` etc.) use decomp `param_1+8` dword-index — not OWN; freelist OWN clean is correct.

### Unit 1 dual quality

**PASS** — keep **`accept-with-gaps`**.

---

## Unit 2 — `0x00407200` StdTree_InsertAndRebalance_Isnil21_Inferred

### Body / ABI seal (independent)

```text
0x00407395 − 0x00407200 + 1 = 0x196 = 406 B  (inclusive end)
```

| Claim | Independent result |
|---|---|
| Range `0x00407200`–`0x00407395` inclusive (**406 B** / `0x196`); pad `CC` | **Confirmed** |
| **`__thiscall`** ECX=map; stack `out* / addLeft / where* / value*`; **`RET 0x10`** | **Confirmed** — raw entry `MOV EDI,ECX`; epilogue `C2 10 00` |
| Size gate `size ≥ 0xFFFFFFE` → `"map/set<T> too long"` | **Confirmed** — decomp `0xffffffd < size`; dual `CMP [EDI+8],0xFFFFFFFE` / `JB` |
| Buynode `00408990` Val16 / red / isnil0 / node 0x28 | **Confirmed** — dualed WQ9H-J; args (head, where, head, value, 0) |
| Link empty / left / right + extremum | **Confirmed** (raw ≡ clean) |
| RB while parent red; L `0050e9f0` / R `005a27f0`; root black @+0x20 | **Confirmed** |
| Always-insert (no key compare in body) | **Confirmed** |
| Callers: InsertHint `00406560` + InsertOrFind `00407060` | **Confirmed** (function record 9 xrefs; dual) |
| Not isnil29 always-insert `00406c40` | **Confirmed** — different max / buynode / color@+0x28 |
| Product demangle open → `_Inferred` | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
void __thiscall FUN_00407200(int map, Node** out, char addLeft, Node* where, void* value)
{
  // SEH LAB_009bc919
  if (0xffffffd < *(uint *)(map + 8)) {
    // length_error("map/set<T> too long") — noreturn
  }
  Node* n = FUN_00408990(head, where, head, value, /*red*/ 0);
  *(map + 8) += 1;
  // link empty / right / left + extremum
  // RB fixup while parent color @+0x20 == 0; rotates 0050e9f0 / 005a27f0
  head->parent->color = 1; // root black
  *out = n;
  // RET 0x10
}
```

Clean `StdTree_InsertAndRebalance_Isnil21_Inferred.cpp` matches CF; throw path plate-simplified to early `return` (documented non-returning throw residual).

### Adversarial attacks (Always-insert)

| # | Attack | Result |
|---|---|---|
| 1 | This is InsertHint (key compare + fallback) | **Fails** — no compare / no InsertOrFind call |
| 2 | This is unique InsertOrFind alone | **Fails** — always inserts; parent owns uniqueness |
| 3 | isnil@+0x29 / node 0x30 family | **Fails** — buynode 0x28; color@+0x20 |
| 4 | Same VA as isnil29 always-insert | **Fails** — peer `00406c40` |
| 5 | Freelist / CNDHash insert | **Fails** — STL throw string + RB tree |
| 6 | `RET 0x0C` like InsertHint | **Fails** — **`RET 0x10`** |
| 7 | Max size `0x0AAAAAA8` (isnil29) | **Fails** — gate `0xFFFFFFFE` |
| 8 | cdecl / no this | **Fails** — `MOV EDI,ECX` |
| 9 | Product English sealed | **Fails** — `_Inferred` |
| 10 | Runtime Confirmed | **Fails** — open |

### Soft niggles

1. Clean throw path is non-throwing `return` plate (dual owns length_error CF).
2. Rotates `0050e9f0` / `005a27f0` undualed (roles sealed).
3. Function-record wording still tags InsertOrFind as “residual” — dual of `00407060` now exists (stale label only).

### Unit 2 dual quality

**PASS** — keep **`accept-with-gaps`**.

---

## Unit 3 — `0x00407060` StdMap_InsertOrFind_PairKey_Isnil21_Inferred

### Body / ABI seal (independent)

```text
0x00407133 − 0x00407060 = 0xD3 = 211 B  (exclusive end)
```

| Claim | Independent result |
|---|---|
| Range `0x00407060`–`0x00407133` exclusive (**211 B** / `0xD3`); pad `CC` | **Confirmed** |
| **`__thiscall`** ECX=map; stack `InsertPair* out`, `ValPair* value`; **`RET 0x8`** ×3 | **Confirmed** — prologue + hex `C2 08 00` ×3 |
| isnil `@+0x21` (`80 78 21 00`) | **Confirmed** — continuous body hex |
| Hi signed primary `@node+0x14` / `@value+4` (`3B 50 14` + `7F`/`7C`) | **Confirmed** |
| Lo unsigned secondary `@node+0x10` / `@value+0` (`3B 58 10` + **`JAE`**) | **Confirmed** |
| Insert worker `E8` → `00407200` ×2 | **Confirmed** — hex relocs land on `0x00407200` |
| Pred `E8` → `005adff0` ×1 | **Confirmed** — hex reloc lands on `0x005adff0` |
| Equal hit: `inserted=0`, no mapped rewrite | **Confirmed** (raw + clean) |
| Sole caller dualed InsertHint `00406560` | **Accepted** (dual 1-xref + InsertHint clean fallthrough) |
| Peer isnil29 pair shell `004cbee0` — do not merge | **Confirmed** |
| Product pair English open → `_Inferred` | **Correct hygiene** |

### Independent hex decode (body continuous hex from dual re-verify)

```text
prologue: 51 55 8B 6C 24 10 56 57 8B F9     ; local + EBP=value; EDI=map
isnil:    80 78 21 00                       ; CMP byte [EAX+0x21],0
hi:       3B 50 14 … 7F / 7C                ; signed vs node+0x14
lo:       3B 58 10 73 …                     ; unsigned JAE vs node+0x10
insert1:  E8 32 01 00 00  → 0x00407200
pred:     E8 0A 6F 1A 00  → 0x005adff0
insert2:  E8 F1 00 00 00  → 0x00407200
exits:    C2 08 00 ×3
```

### Live / raw decompile (independent summary)

```c
void __thiscall FUN_00407060(int map, undefined4 *out, uint *value)
{
  Node *head = *(Node **)(map + 4);
  Node *where = head;
  bool goLeft = true;
  char addLeft = 1;
  Node *node = head->parent;
  if (node->isnil == 0) {
    // lower_bound: go right when node <= key (hi signed, lo unsigned)
  }
  if (goLeft) {
    if (where == head->left) { // **head
      // FUN_00407200(..., addLeft=1, ...); out.inserted = 1; RET 8
    }
    FUN_005adff0(&hint); // predecessor
  }
  if (hint < key) { // strict
    // FUN_00407200(..., addLeft, ...); out.inserted = 1; RET 8
  }
  out->inserted = 0;
  out->it = hint;
  // RET 8
}
```

Clean `StdMap_InsertOrFind_PairKey_Isnil21_Inferred.cpp` matches compare order and insert/equal paths.

### Adversarial attacks (InsertOrFind)

| # | Attack | Result |
|---|---|---|
| 1 | Merge with isnil29 pair `004cbee0` | **Fails** — isnil@+0x21; insert `00407200` |
| 2 | Single dword int-key (`004cbe20`) | **Fails** — hi/lo pair walk |
| 3 | Both dwords signed | **Fails** — lo uses **unsigned** `JAE` |
| 4 | Both dwords unsigned | **Fails** — hi uses **signed** `JG`/`JL` |
| 5 | Always-insert only | **Fails** — equal path `inserted=0` |
| 6 | Hit rewrites value | **Fails** — stores it + flag only |
| 7 | `RET 0x0C` / 4 stack args | **Fails** — **`RET 0x8`**, two stack args |
| 8 | isnil@+0x29 Val24 family | **Fails** — `80 78 21 00` |
| 9 | Multi-caller shared leaf | **Narrow** — **1** xref (InsertHint only) |
| 10 | Product TFID/operator[] sealed | **Fails** — `_Inferred` |
| 11 | Runtime Confirmed | **Fails** — open |

### Soft niggles

1. Dual A listed insert worker dual as gap (WQ9I-B) — **closed** by Unit 2 dual in this ADV batch; residual label stale only.
2. Pred `005adff0` undualed (role sealed).
3. Decompiler reuses `param_3` as walk cursor — machine keeps value in EBP (annotated correctly).

### Unit 3 dual quality

**PASS** — keep **`accept-with-gaps`**.

---

## Unit 4 — `0x007fe640` Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred

### Body / ABI seal (independent)

```text
0x007fe710 − 0x007fe640 = 0xD1 = 209 B  (exclusive end)
```

| Claim | Independent result |
|---|---|
| Range `0x007fe640`–`0x007fe710` exclusive (**209 B** / `0xD1`); pad `CC` | **Confirmed** |
| **stdcall** stack owner*; **`RET 4`** | **Confirmed** — entry `MOV EBP,[ESP+8]`; epilogue `C2 04 00` |
| Hash @ **`owner+0x3084`** | **Confirmed** — entry `MOV ESI,[EBP+0x3084]`; hex `8B B5 84 30 00 00` |
| Null hash early-out | **Confirmed** (raw) |
| Soft TraversalLock assert then force lock `@+0x1d = 1` | **Confirmed** — continues after log |
| Ordered walk head `@+0x14`, next `@+0x20`, payload `@+0xc` | **Confirmed** |
| Per-object vtbl `+0x3d8` / `+0x440`; secondary `obj+0x2b0` → vtbl `+0xb0` | **Confirmed** — raw `piVar3[0xac]` ≡ +0x2b0 |
| Unlock then recreate | **Confirmed** |
| Recreate handoff: **EAX=hash**, **BL=2** (imm `B3 02`) | **Confirmed** — dual re-verify bytes; decomp omits formals |
| Nested `CNDHash_Recreate_00a2c2e4` (`0x004195d0`, WQ9H-E dualed) | **Confirmed** |
| Callers ×2: `009348bc`, `009349d4` | **Accepted** (dual xrefs) |
| Reject `Named_VOG_DEBUG_STOP_*` identity | **Confirmed** — assert strings only |
| Product host English open → `_Inferred` | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
void FUN_007fe640(int owner)
{
  int hash = *(int *)(owner + 0x3084);
  int cursor = 0;
  if (hash == 0) return;
  if (*(char *)(hash + 0x1d) != 0) {
    FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  *(undefined1 *)(hash + 0x1d) = 1;
  while (true) {
    hash = *(int *)(owner + 0x3084);
    // soft unlock check / TraverseToNext strings
    cursor = (cursor == 0) ? *(int *)(hash + 0x14) : *(int *)(cursor + 0x20);
    int *obj = (cursor == 0) ? 0 : *(int **)(cursor + 0xc);
    if (obj == 0) break;
    if ((**(code **)(*obj + 0x3d8))() != 0)
      (**(code **)(*obj + 0x440))();
    if (obj[0xac] != 0) // +0x2b0
      (**(code **)(*(int *)obj[0xac] + 0xb0))(obj);
  }
  *(undefined1 *)(*(int *)(owner + 0x3084) + 0x1d) = 0;
  // BYTES: EAX = hash; BL = 2; CALL 004195d0
  FUN_004195d0();
  // RET 4
}
```

Clean `Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred.cpp` matches CF + recreate seed.

### Adversarial attacks (Host traverse/recreate)

| # | Attack | Result |
|---|---|---|
| 1 | Hard-abort / throw on lock errors | **Fails** — logs then continues |
| 2 | Skill thiscall recreate + stack log2 / RET 4 on nested | **Fails** — EAX/BL bare-ret family on nested recreate |
| 3 | BL log2 not 2 / from host field | **Fails** — imm `MOV BL,2` |
| 4 | Decomp no formals → no recreate ABI | **Fails** — bytes seal EAX/BL |
| 5 | Hash field not +0x3084 | **Fails** — entry + epilogue loads |
| 6 | Identity is `Named_VOG_DEBUG_STOP_*` | **Fails** — assert string only |
| 7 | thiscall on owner (ECX=this) | **Fails** — stack owner; `RET 4` |
| 8 | Runtime Confirmed | **Fails** — open |

### Soft niggles

1. Clean lacks explicit `__stdcall` attribute (plate documents RET 4).
2. Product English for host class / vtbl methods open (correctly residual).
3. Callers `FUN_00934880` / `FUN_009349b0` undualed (not OWN).

### Unit 4 dual quality

**PASS** — keep **`accept-with-gaps`**.

---

## Cross-unit consistency

| Topic | Independent |
|---|---|
| Freelist under CNDHash dtor | **Confirmed** — dtor pushes `this+0x20` → Unit 1 |
| InsertOrFind → always-insert | **Confirmed** — Unit 3 calls Unit 2 ×2; both dualed this batch |
| InsertHint → both map helpers | **Confirmed** — `FUN_00406560` clean wires insert + InsertOrFind |
| isnil21 family layout | **Confirmed** — color@+0x20, isnil@+0x21, node 0x28, Val16; shared by Units 2–3 |
| Pair-key order | **Confirmed** — hi signed primary, lo unsigned secondary; peer leaf `00401480` |
| Host field +0x3084 chain | **Confirmed** — ctor/recreate family (WQ9H ADV) + Unit 4 sole BL=2 recreate parent |
| Freelist twin ABI non-merge | **Confirmed** — `00416e80` ret4 vs `0059c8a0` thiscall |
| isnil29 non-merge | **Confirmed** — insert peer `00406c40`, pair peer `004cbee0` |
| Clean plate VA uniqueness | **Confirmed** — no WQ9E-style shared-name collision on these four |
| Naming hygiene | All four `_Inferred`; VOG_DEBUG_STOP scaffold rejected |

```text
CNDHash_Dtor_00a2c2b0 (0x00406420)
  └─ FreelistSlabVector_Teardown_Inferred (0x00416e80)  [OWN WQ9I-A]

StdTree_InsertHint_Isnil21 (0x00406560)
  ├─ StdTree_InsertAndRebalance_Isnil21 (0x00407200)  [OWN WQ9I-B]
  └─ StdMap_InsertOrFind_PairKey_Isnil21 (0x00407060) [OWN WQ9I-C]
        └─ StdTree_InsertAndRebalance_Isnil21 (0x00407200)

Host rebuild/teardown (00934880 / 009349b0)
  └─ Host_CNDHash_TraverseTeardownThenRecreate_BL2 (0x007fe640) [OWN WQ9I-D]
        └─ CNDHash_Recreate_00a2c2e4 (0x004195d0)  [WQ9H-E]
```

---

## Confirmations

1. WQ9I dual A/B + agent reports for all four OWN VAs are **faithful** to raw decompile and dual re-verify byte seals.
2. Freelist: stdcall ret4, aligned_free loop, delete-returns, always triad zero — **confirmed**; thiscall twin correctly separated.
3. Always-insert isnil21: thiscall RET 0x10, size gate, buynode 00408990, RB color@+0x20, no key compare — **confirmed**.
4. InsertOrFind pair isnil21: RET 8, hi signed / lo unsigned, equal-no-rewrite, sole InsertHint caller — **confirmed** via continuous hex.
5. Host traverse/teardown/recreate: owner stack, +0x3084, unlock-then-recreate, EAX/BL=2 — **confirmed**.
6. Dual B attacks correctly reject ABI merges, family merges, decomp noreturn traps, and product-English overclaim.
7. Clean named sources match sealed CF; scaffold twins keep Ghidra symbols; reject plate for VOG_DEBUG_STOP stands.
8. Mutual dual residuals (InsertOrFind ↔ insert worker) are **closed within this ADV set**; remaining gaps are product English, undualed rotates/pred/callers, runtime.
9. **terminal = false** — no runtime / bit-exact / differential claimed.

---

## Gaps (remain open — dual already owns)

| Gap | Unit | Blocks accept? |
|---|---|---|
| Product / PDB English (freelist type, map value_type, pair type, host class) | All | No (`accept-with-gaps`) |
| Full dual of rotates `0050e9f0` / `005a27f0` | Insert | No |
| Full dual of pred `005adff0` | InsertOrFind | No |
| Wrapper `00416c30` + sibling hash dtors | Freelist callers | No |
| Host callers `00934880` / `009349b0` | Host | No |
| Exact English for vtbl +0x3d8 / +0x440 / +0xb0 | Host | No |
| Runtime / bit-exact / differential | All | No (policy; terminal false) |

---

## Pass / fail

| Unit | Dual verdict | ADV result |
|---|---|---|
| `aa_00416e80` FreelistSlabVector_Teardown_Inferred | **accept-with-gaps** | **PASS** — retain **accept-with-gaps** |
| `aa_00407200` StdTree_InsertAndRebalance_Isnil21_Inferred | **accept-with-gaps** | **PASS** — retain **accept-with-gaps** |
| `aa_00407060` StdMap_InsertOrFind_PairKey_Isnil21_Inferred | **accept-with-gaps** | **PASS** — retain **accept-with-gaps** |
| `aa_007fe640` Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred | **accept-with-gaps** | **PASS** — retain **accept-with-gaps** |

### Overall

**PASS** — WQ9I core dual seals hold under independent multi-source verification (raw + dual byte seals / continuous hex + clean CF + parent/peer wiring + prior WQ9H ADV). No sealed-claim failure requiring dual rewrite, clean VA rebinding, or verdict downgrade.

Soft niggles only: missing `__stdcall` attributes on freelist/host cleans; insert clean throw plate simplification; stale “residual” labels between Units 2–3 after mutual dual completion.

**terminal = false**

---

## Process notes

- Independent ADV verifier; **not** WQ9I-A / WQ9I-B / WQ9I-C / WQ9I-D author.
- **No** parent ledger / WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY / COVERAGE_LEDGER edits.
- **No** dual A/B rewrite; **no** Launcher.
- Live Ghidra MCP not callable from this ADV session tool surface; verification uses sealed raw, dual re-verify byte claims, continuous body hex for `00407060`, clean CF, parent/peer cleans, and prior ADV_wq9h host/recreate family seals.
- **No** `disassemble_bytes`.
- Output: `docs/reconstruction/reviews/ADV_wq9i_spotcheck_core.md` (this file).
