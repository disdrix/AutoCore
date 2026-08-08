# Independent adversarial spot-check — WQ9K tree buynode + isnil2d rotates + ShopVeh reindex

| Field | Value |
|---|---|
| **Date** | `2026-08-05` |
| **Role** | Independent adversarial verifier (**not** dual author WQ9K-C / WQ9K-H / WQ9K-I / WQ9K-J) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | `WAVE_2026-08-04_wq009_depth8_partition_map.md` → **WQ9K-C** `00404180`; **WQ9K-H** `0083ac90`; **WQ9K-I** `0044e010`; **WQ9K-J** `0042a840` |
| **Units** | (1) `0x00404180` `StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred`; (2) `0x0044e010` `StdTree_LeftRotate_Isnil2D_Inferred`; (3) `0x0042a840` `StdTree_Rrotate_Isnil2D_Inferred`; (4) `0x0083ac90` `ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred` |
| **Tools** | Dual A/B + agent reports + raw/annotated/clean + function records + peer contrast (isnil29 rotates, thiscall buynode twin, swap leaf) + independent body-size / hex plate re-count |
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
| `docs/agents/task-dual-ab-00404180-00405f20-wq9kc-report.md` (unit `00404180` only) |
| `docs/agents/task-dual-ab-0083ac90-00416830-wq9kh-report.md` (unit `0083ac90` only) |
| `docs/agents/task-dual-ab-004168c0-0044e010-wq9ki-report.md` (unit `0044e010` only) |
| `docs/agents/task-dual-ab-0042a840-0040a590-wq9kj-report.md` (unit `0042a840` only) |
| `docs/reconstruction/reviews/A_aa_00404180_StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_00404180_StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_0044e010_StdTree_LeftRotate_Isnil2D_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_0044e010_StdTree_LeftRotate_Isnil2D_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_0042a840_StdTree_Rrotate_Isnil2D_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_0042a840_StdTree_Rrotate_Isnil2D_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_0083ac90_ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_0083ac90_ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred.md` |

### Artifacts (four units)

| Kind | `00404180` | `0044e010` | `0042a840` | `0083ac90` |
|---|---|---|---|---|
| Raw (+ re-verify) | `raw/aa_00404180_FUN_00404180.md` | `raw/aa_0044e010_FUN_0044e010.md` | `raw/aa_0042a840_FUN_0042a840.md` | `raw/aa_0083ac90_FUN_0083ac90.md` |
| Annotated | `…FUN_00404180.annotated.md` | `…FUN_0044e010.annotated.md` | `…FUN_0042a840.annotated.md` | `…FUN_0083ac90.annotated.md` |
| Clean named | `StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred.cpp` | `StdTree_LeftRotate_Isnil2D_Inferred.cpp` | `StdTree_Rrotate_Isnil2D_Inferred.cpp` | `ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred.cpp` |
| Clean twin | `FUN_00404180.cpp` | `FUN_0044e010.cpp` | `FUN_0042a840.cpp` | `FUN_0083ac90.cpp` |
| Function named | `aa_00404180_StdTree_…` | `aa_0044e010_StdTree_…` | `aa_0042a840_StdTree_…` | `aa_0083ac90_ShopVehList_…` |

### Support / contrast evidence (not OWN duals of this ADV set)

| Artifact | Use |
|---|---|
| Dual WQ9F-B / ADV_wq9f buynode `00407e30` | Thiscall-ctor Val24/isnil29 twin of EAX-ctor buynode `00404180` — non-merge |
| Dual WQ9J-H node ctors `00409880` / `004098d0` | EAX-this vs thiscall construct leaves under buynode twins |
| Dual isnil29 rotates `004192a0` / `004192f0` | ABI invert trap (ECX=tree / stack=node) vs isnil2d ECX=node / stack=map |
| Dual WQ9J-D swap `00833160` | Sole callee of ShopVeh reindex swap path |
| Dual WQ9J-F StringKey erase `004094c0` | Shared consumer of both isnil2d rotates |
| Prior ADV `ADV_wq9f_spotcheck_freelist_buynode.md` | Family SEH/buynode / freelist-reject pattern |

### Evidence cross-check matrix

| Check | Result |
|---|---|
| Raw decompile ≡ dual A CF tables | **Yes** (all four; decomp traps overridden by bytes where noted) |
| Dual re-verify body ends + entry/exit hex recorded | **Yes** (buynode epilogue `C2 14 00`; both rotates full body hex; ShopVeh entry/exit plates) |
| Clean named owns correct VA (no plate collision) | **Yes** (all four; twins re-express same CF except ShopVeh scaffold select=0 note) |
| Body-size arithmetic | **Yes** (see unit sections; hex re-count for rotates) |
| Buynode ≠ freelist; ≠ thiscall twin `00407e30`; pairs EAX-ctor `00409880` | **Holds** |
| L-rotate promotes **right** child; R-rotate promotes **left** child | **Holds** (entry ops `MOV EAX,[ECX+8]` vs `MOV EAX,[ECX]`) |
| isnil@**+0x2D** on both rotates; **not** isnil29 `@+0x29` | **Holds** (`80 7A 2D 00`) |
| isnil2d rotate ABI = **ECX=node / stack=map / RET 4** (invert of isnil29) | **Holds** |
| ShopVeh EAX=select + stack host + RET 4; five-slot window; id base `0x9ca4` | **Holds** |
| Terminal honesty | **false** on all duals / cleans / this ADV |
| Runtime Confirmed | **Not claimed** |

---

## Unit 1 — `0x00404180` StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred

### Body / ABI seal (independent)

```text
0x00404202 − 0x00404180 = 0x82 = 130 B  (exclusive end)
```

| Claim | Independent result |
|---|---|
| Range `0x00404180`–`0x00404202` exclusive (**130 B** / `0x82`); terminal **`C2 14 00`** @ `0x004041ff` | **Confirmed** (dual re-verify + size math) |
| **`__stdcall`** 5 stack args; **EAX** = node* \| null; **not** thiscall | **Confirmed** (raw + dual B disasm plate) |
| `operator_new(0x30)` then conditional ctor | **Confirmed** |
| Ctor = dualed `StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred` (`0x00409880`): **EAX**=node, **ECX**=value*, **EDX**=left; stack parent/right/color; **RET 0xC** | **Confirmed** (dual re-verify register plate; decomp incomplete arg list correctly called out) |
| Layout via ctor: Val24 @+0x10; color@+0x28; isnil=0 @+0x29; node size 0x30 | **Confirmed** (WQ9J-H dual + this dual) |
| Sole caller insert `FUN_004069f0` @ `0x00406a56` (map/set too long; rebalance outside) | **Accepted** (1 UNCONDITIONAL_CALL; parent undualed) |
| Distinct from thiscall buynode twin `0x00407e30` (ctor `004098d0`) | **Holds** — dual B rejects merge |
| SEH present; freelist/CNDHash rejected | **Holds** |
| Name `_Inferred` / product open | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
// Decomp incomplete on ctor formals — bytes seal EAX/ECX/EDX + 3 stack.
void * FUN_00404180(/* left, parent, right, value*, color — stdcall 5 */)
{
  // SEH FS:[0] / LAB_009bc701
  void *pvVar1 = operator_new(0x30);
  if (pvVar1 != 0) {
    // retail: EAX=node; ECX=value*; EDX=left; PUSH color,right,parent
    FUN_00409880(/* decomp shows only param_2,param_3,param_5 */);
  }
  return pvVar1; // RET 0x14
}
```

### Clean fidelity

| Item | Result |
|---|---|
| Named clean VA / size plate | **Owns `0x00404180`** (130 B exclusive) |
| CF rewrite | **Match** — `new(0x30)` + null-skip + EAX-ctor + return node |
| ABI plate | Explicit stdcall RET 0x14; twin non-merge note |
| SEH omitted honestly | **OK** (commented) |
| Scaffold twin | Re-expresses same CF — **OK** |

### Dual A/B quality

| Path | Verdict | ADV |
|---|---|---|
| A fidelity | accept-with-gaps | **Agree** — CF/ABI/size High; product + insert dual open |
| B adversarial | accept-with-gaps | **Agree** — freelist / thiscall / merge / scaffold product names falsified |

### Unit verdict

**PASS** — seals hold; residual product English + undualed insert parent are dual-declared gaps, not ADV falsifications.

---

## Unit 2 — `0x0044e010` StdTree_LeftRotate_Isnil2D_Inferred

### Body / ABI seal (independent)

```text
0x0044e05b − 0x0044e010 + 1 = 0x4C = 76 B  (inclusive)
// independent hex plate re-count = 76 B (matches dual)
```

| Claim | Independent result |
|---|---|
| Range `0x0044e010`–`0x0044e05b` inclusive (**76 B** / `0x4C`); pad `CC` | **Confirmed** |
| Three exits all **`RET 4`** (`C2 04 00`) | **Confirmed** (hex plate) |
| **ECX** = node X; stack map*; void | **Confirmed** (call-site `MOV ECX,…; PUSH map; CALL`) |
| **Left rotate**: entry `8B 41 08` = `MOV EAX,[ECX+8]` → Y = X.right | **Confirmed** |
| Nil guard `80 7A 2D 00` → isnil@**+0x2D** on Y.left | **Confirmed** |
| Root / left-child / right-child rewire; Y.left = X; X.parent = Y | **Confirmed** (raw decompile ≡ classic MSVC left-rotate) |
| No color stores (callers use +0x2C around CALL) | **Confirmed** |
| Leaf (0 callees); **10** CALL xrefs / 4 parent funcs | **Accepted** (dual re-verify; shared with R-rotate consumers) |
| Not isnil29 L-rotate `004192a0` (ABI invert + isnil@+0x29) | **Holds** — dual B trap explicit |
| Not right-rotate | **Holds** — promotes right child |

### Live / raw decompile (independent summary)

```c
void __thiscall FUN_0044e010(int param_1 /*X=ECX*/, int param_2 /*map*/)
{
  int *Y = *(int **)(param_1 + 8);       // X.right
  *(int *)(param_1 + 8) = *Y;            // X.right = Y.left
  if (*(char *)(*Y + 0x2d) == 0)         // Y.left non-nil
    *(int *)(*Y + 4) = param_1;
  Y[1] = *(int *)(param_1 + 4);          // Y.parent = X.parent
  // root / left-child / right-child cases, each RET 4
  *Y = param_1;                          // Y.left = X
  *(int **)(param_1 + 4) = Y;            // X.parent = Y
}
```

### Clean fidelity

| Item | Result |
|---|---|
| Named clean VA / size plate | **Owns `0x0044e010`** (76 B) |
| CF rewrite | **Match** — classic left-rotate; `node_is_nil` via +0x2D |
| Map shell `myhead = *(map+4)`; root = head->parent | **Match** |
| Twin alias `FUN_0044e010` | Same CF — **OK** |

### Dual A/B quality

| Path | Verdict | ADV |
|---|---|---|
| A fidelity | accept-with-gaps | **Agree** |
| B adversarial | accept-with-gaps | **Agree** — right-rotate / isnil29 / no-RET4 / recolor / single-caller rejected |

### Unit verdict

**PASS** — CF/ABI/isnil sealed. Residual: product map English; naming style note (see findings).

---

## Unit 3 — `0x0042a840` StdTree_Rrotate_Isnil2D_Inferred

### Body / ABI seal (independent)

```text
0x0042a88f − 0x0042a840 + 1 = 0x50 = 80 B  (inclusive)
// independent hex plate re-count = 80 B (matches dual)
```

| Claim | Independent result |
|---|---|
| Range `0x0042a840`–`0x0042a88f` inclusive (**80 B** / `0x50`) | **Confirmed** |
| Three **`RET 4`** exits | **Confirmed** |
| **ECX** = node x; stack tree; void | **Confirmed** (`MOV EDX,[ESP+4]` loads tree) |
| **Right rotate**: entry `8B 01` = `MOV EAX,[ECX]` → y = x.left | **Confirmed** |
| Nil guard `80 7A 2D 00` on **y.right** (isnil@+0x2D) | **Confirmed** |
| y.right = x; x.parent = y on all exits | **Confirmed** |
| No recolor; leaf; shared callers with L-rotate (insert `00430b60`, erase `004094c0`, peers) | **Confirmed** / **Accepted** |
| ABI **invert** of isnil29 R-rotate `004192f0` (that family: ECX=tree / stack=node / isnil@+0x29) | **Holds** — dual B explicit |
| Not left-rotate | **Holds** |

### Live / raw decompile (independent summary)

```c
void __thiscall FUN_0042a840(int *x /*ECX*/, int tree /*stack*/)
{
  int y = *x;                            // x->left
  *x = *(int *)(y + 8);                  // x->left = y->right
  if (*(char *)(*(int *)(y + 8) + 0x2d) == 0)
    *(int **)(*(int *)(y + 8) + 4) = x;  // y->right->parent = x
  *(int *)(y + 4) = x[1];                // y->parent = x->parent
  // root / right-child / left-child cases; each: y->right=x; x->parent=y; RET 4
}
```

### Clean fidelity

| Item | Result |
|---|---|
| Named clean VA / size plate | **Owns `0x0042a840`** (80 B) |
| CF rewrite | **Match** (pointer-offset style mirrors decomp) |
| ABI trap comment vs isnil29 | **Present and correct** |
| Twin | Same CF — **OK** |

### Dual A/B quality

| Path | Verdict | ADV |
|---|---|---|
| A fidelity | **accept** | **Agree on CF** — product residual still open; grade slightly firmer than L-rotate peer's accept-with-gaps (see findings) |
| B adversarial | **accept** | **Agree** — left-rotate / ECX=tree / isnil29/49 merge / recolor / bare-ret rejected |

### Unit verdict

**PASS** — leaf rotate seals hold. Process note only on accept vs accept-with-gaps grading.

---

## Unit 4 — `0x0083ac90` ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred

### Body / ABI seal (independent)

```text
0x0083aeb4 − 0x0083ac90 + 1 = 0x225 = 549 B  (inclusive)
```

| Claim | Independent result |
|---|---|
| Range `0x0083ac90`–`0x0083aeb4` inclusive (**549 B** / `0x225`); pad `CC` | **Confirmed** |
| Entry `83 EC 08 85 C0 55 8B 6C 24 10` — `TEST EAX`; host from stack after `PUSH EBP` | **Confirmed** |
| Exit `… 83 C4 08 C2 04 00` — **`RET 4`** | **Confirmed** |
| **EAX** = select_index; stack **host***; void; **not** thiscall | **Confirmed** (raw `in_EAX`; dual B falsifies ECX=host) |
| Host `+0x4fc` count bound; `+0x500` select write; `+0x50c[5]` slots | **Confirmed** (raw) |
| Window list_i ∈ `[select-2, select+2]`; slot = list_i − select + 2; bounds vs 5 | **Confirmed** |
| Id base **`0x9ca4`**; clear id **`-1`** via vtbl+0x74; get via vtbl+0x78 | **Confirmed** |
| Sole CALL of dualed swap `00833160` @ `0x0083ad72` after ESI/EDI slot loads | **Confirmed** (dual + WQ9J-D chain) |
| Not full list rebuild; not free of host/slots; swap only on mismatch+donor | **Holds** — dual B rejects overclaims |
| Dead `CMP …,5` post-swap abf0 branch (j always &lt; 5) | **Accepted** as dual-noted odd behavior |
| Helpers `0083a860` / `0083a880` / `0083abf0` / `00833d50` undualed | **Open** (correctly Med residual) |
| Name `_Inferred` (shopveh English from graph, not RTTI here) | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
void FUN_0083ac90(undefined4 *host /*stack*/)
{
  int select = in_EAX;
  if (select < 0 || select > *(int *)((int)host + 0x4fc)) return;
  *(int *)((int)host + 0x500) = select;
  // for list_i = select-2 .. select+2:
  //   slot = list_i - select + 2; if in-range and slots[slot]:
  //     if GetId(slots[slot]) - 0x9ca4 == list_i: refresh (a860/abf0/a880)
  //     else: scan donor j; CALL 00833160; fix ids; a880
  //     SetId(slots[slot], list_i + 0x9ca4)
  // leading clear when select < 2; trailing when (count-select+2) < 5
  // RET 4
}
```

### Clean fidelity

| Item | Result |
|---|---|
| Named clean VA / size plate | **Owns `0x0083ac90`** (549 B) |
| CF rewrite (portable host+select formals) | **Match** window math, offsets, id base, swap, clears |
| Product ABI note (EAX select + stack host) | **Documented** on plate and FUN twin |
| Scaffold twin `FUN_0083ac90` hardcodes select `0` | **Hygiene defect** — not callable as product entry (see findings) |
| Helper formals (`abf0(slot,list_i,host)` vs decomp 1-arg) | **Open** — undualed; dual correctly Med |

### Dual A/B quality

| Path | Verdict | ADV |
|---|---|---|
| A fidelity | accept-with-gaps | **Agree** — ABI/window/id/swap High |
| B adversarial | accept-with-gaps | **Agree** — thiscall / stack-select / full-rebuild / always-swap / free overclaims rejected |

### Unit verdict

**PASS-WITH-FINDINGS** — core CF/ABI seals hold; scaffold twin select=0 + undualed helper arity are residual hygiene (helpers already dual-gapped).

---

## Cross-unit family checks

| Check | Result |
|---|---|
| isnil2d L/R rotate form a **pair**: same isnil@+0x2D, same ECX=node/stack map/RET4, mirrored promote child | **Yes** |
| Pair consumers shared (StringKey insert/erase + peers) | **Yes** |
| Pair **not** mergeable with isnil29 rotates (ABI invert + isnil offset) | **Yes** |
| Buynode is isnil**29**/Val24 family — **not** isnil2d rotate family; co-owned only by residual partition | **Yes** (dual WQ9K-C note) |
| ShopVeh is UI reindex worker — **not** tree STL; co-owned only by residual partition | **Yes** |
| All four duals Terminal **false**; no Runtime Confirmed | **Yes** |

---

## Findings

| # | Severity | Unit | Finding |
|---|---|---|---|
| F1 | **Low** (naming) | `0044e010` / `0042a840` | Registry names asymmetric: `StdTree_**LeftRotate**_Isnil2D_Inferred` vs peer `StdTree_**Rrotate**_Isnil2D_Inferred`, and vs isnil29 `StdTree_**Lrotate**_Isnil29`. CF seal unaffected; rename later for family consistency if desired. |
| F2 | **Low** (process) | `0042a840` | Dual A/B graded **accept** while product demangle still open and L-rotate peer is **accept-with-gaps** for the same residual class. Prefer accept-with-gaps for product-open leaves; **does not** undermine CF. |
| F3 | **Low** (process) | `0042a840` report | WQ9K-J still lists peer L-rotate `0044e010` as “residual dual” — same-wave WQ9K-I dual already sealed it. Stale gap language only. |
| F4 | **Low** (scaffold) | `0083ac90` | Clean twin `FUN_0083ac90` hardcodes `select=0` while product entry requires live **EAX**. Named clean is authoritative; twin is not a bit-faithful entry shim. |
| F5 | **Info** (already dual-gapped) | `0083ac90` | Undualed helpers (`0083a860`/`0083a880`/`0083abf0`/`00833d50`) and decomp vs clean arity on `abf0` remain open — dual Med residual; ADV does not elevate to FAIL. |
| F6 | **Info** (already dual-gapped) | `00404180` | Parent insert `004069f0` undualed; decomp incomplete ctor formals correctly overridden by bytes. |

No finding falsifies a dual High claim on CF, ABI, body size, isnil offset, rotate direction, or ShopVeh window math.

---

## Verdict summary

| Unit | Dual A/B | ADV unit | Notes |
|---|---|---|---|
| `0x00404180` buynode Val24 EAX-ctor | accept-with-gaps / accept-with-gaps | **PASS** | SEH + new(0x30) + EAX-ctor + RET 0x14 sealed |
| `0x0044e010` L-rotate isnil2d | accept-with-gaps / accept-with-gaps | **PASS** | 76 B; ECX=node; isnil@+0x2D; left-rotate CF |
| `0x0042a840` R-rotate isnil2d | accept / accept | **PASS** | 80 B; mirrored right-rotate; ABI invert trap vs isnil29 holds |
| `0x0083ac90` ShopVeh reindex | accept-with-gaps / accept-with-gaps | **PASS-WITH-FINDINGS** | EAX/host/RET4/window/id/swap sealed; scaffold twin + helpers residual |

### Overall: **PASS-WITH-FINDINGS**

Independent re-check of dual A/B, raw re-verify plates, and named cleans confirms all four units' control-flow and ABI seals. Findings are naming hygiene, accept-grade consistency, stale peer-residual wording, and scaffold twin incompleteness — not CF failures. **Terminal remains false.** No parent ledger edits; no dual rewrites.

---

## Artifacts written

- Output: `docs/reconstruction/reviews/ADV_wq9k_spotcheck_tree_shop.md` (this file).
)
