# Independent adversarial spot-check — WQ9H CNDHash (freelist / ctor / dtor / recreate)

| Field | Value |
|---|---|
| **Date** | `2026-08-05` |
| **Role** | Independent adversarial verifier (**not** dual author WQ9H-A / WQ9H-D / WQ9H-E) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | `WAVE_2026-08-04_wq009_depth5_partition_map.md` → **WQ9H-A** (`004085e0`), **WQ9H-D** (`004063a0`/`00406420`), **WQ9H-E** (`004195d0`) |
| **Units** | (1) `0x004085e0` freelist; (2) `0x004063a0` ctor; (3) `0x00406420` dtor; (4) `0x004195d0` recreate |
| **Tools** | Dual reports + A/B + raw/annotated/clean + function records + parent alloc/destroy raws + inventory/skill contrast raws + independent body-size / field-map arithmetic |
| **Live Ghidra this session** | Not re-dispatched from this ADV tool surface (prior WQ9 duals claim live ≡ raw; no `disassemble_bytes`). Claims re-checked against sealed raw decompile + dual 2026-08-04 re-verify byte seals + clean CF |
| **Forbidden** | `disassemble_bytes`; parent ledger edits; dual rewrite; Launcher |
| **Image** | `autoassault.exe` base `0x400000` |
| **Terminal** | **false** |

---

## Inspected evidence

### Dual / report surfaces

| Path |
|---|
| `docs/agents/task-dual-ab-004085e0-00408050-wq9ha-report.md` (OWN freelist half) |
| `docs/agents/task-dual-ab-004063a0-00406420-wq9hd-report.md` |
| `docs/agents/task-dual-ab-004195d0-0060c860-wq9he-report.md` (OWN recreate half) |
| `docs/reconstruction/reviews/A_aa_004085e0_CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_004085e0_CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_004063a0_CNDHash_Ctor_00a2c2b0.md` |
| `docs/reconstruction/reviews/B_aa_004063a0_CNDHash_Ctor_00a2c2b0.md` |
| `docs/reconstruction/reviews/A_aa_00406420_CNDHash_Dtor_00a2c2b0.md` |
| `docs/reconstruction/reviews/B_aa_00406420_CNDHash_Dtor_00a2c2b0.md` |
| `docs/reconstruction/reviews/A_aa_004195d0_CNDHash_Recreate_00a2c2e4.md` |
| `docs/reconstruction/reviews/B_aa_004195d0_CNDHash_Recreate_00a2c2e4.md` |

### Artifacts (four units)

| Kind | `004085e0` | `004063a0` | `00406420` | `004195d0` |
|---|---|---|---|---|
| Raw (+ re-verify) | `raw/aa_004085e0_FUN_004085e0.md` | `raw/aa_004063a0_FUN_004063a0.md` | `raw/aa_00406420_FUN_00406420.md` | `raw/aa_004195d0_FUN_004195d0.md` |
| Clean named | `CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred.cpp` | `CNDHash_Ctor_00a2c2b0.cpp` | `CNDHash_Dtor_00a2c2b0.cpp` | `CNDHash_Recreate_00a2c2e4.cpp` |
| Function named | `aa_004085e0_CNDHash_…` | `aa_004063a0_CNDHash_Ctor…` | `aa_00406420_CNDHash_Dtor…` | `aa_004195d0_CNDHash_Recreate…` |

### Support / contrast evidence (not OWN duals)

| Artifact | Use |
|---|---|
| `raw/aa_00406fc0_FUN_00406fc0.md` | Parent destroy: `mov ebx,eax` → freelist; zeros live `@+0x0c`; free slab/`delete[]` table |
| `raw/aa_00406f20_FUN_00406f20.md` | Nested alloc: ESI ABI; stamp `00a2c2e4`; COUNT→MASK at `+8` |
| `raw/aa_004138d0_FUN_004138d0.md` | Inventory recreate — same **EAX/BL** CF shape; different helper VAs |
| `raw/aa_00413ea0_FUN_00413ea0.md` | Inventory freelist — **EBX** + node[+3]/[+4] layout peer; payload **virtual dtor** contrast |
| `raw/aa_004cb680_FUN_004cb680.md` | Skill freelist — **thiscall** + different node offsets (payload[+2]/next[+3]) |
| Skill recreate/ctor raws (`004cbdc0` / `0051dd60`) | thiscall+`ret 4` / skill vtbl family contrast |

### Evidence cross-check matrix

| Check | Result |
|---|---|
| Raw 2026-07-23 decompile ≡ dual A CF tables | **Yes** (all four) |
| Dual re-verify 2026-08-04 claims live ≡ raw | Stated **identical**; body ends + entry/exit hex recorded |
| Clean named ≡ raw CF | **Yes** (all four) |
| Body-size arithmetic (exclusive freelist / inclusive others) | **Yes** (see unit sections) |
| Parent destroy → freelist EBX handoff | **Yes** — `00406fc0` entry `53 8B D8` (`push ebx; mov ebx,eax`); freelist uses `unaff_EBX` |
| Ctor/recreate host field `+0x3084` chain | **Yes** — ctor sole create stores host+0x3084; recreate sole caller loads same |
| Alloc mask post-condition (after ctor/recreate) | **Yes** — `00406f20` does `*(+8)--` after sentinel fill |
| Inventory recreate ABI peer | **Yes** — `004138d0` EAX/BL bare ret; helpers `00413e20`/`00413d80` not host |
| Skill freelist ABI/layout contrast | **Yes** — thiscall + payload/next offsets differ |
| Terminal / runtime Confirmed | **Not claimed** (policy; terminal false) |

---

## Unit 1 — `0x004085e0` CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred

### Body / ABI seal (independent)

```text
0x00408635 − 0x004085e0 = 0x55 = 85 B  (exclusive end; last insn C3 @ 0x00408634)
```

| Claim | Independent result |
|---|---|
| Range `0x004085e0`–`0x00408635` exclusive (**85 B** / `0x55`); pad `CC` | **Confirmed** (size math + dual re-verify end) |
| **customcc**; **EBX = CNDHash\***; no stack; void; bare `ret` | **Confirmed** — raw `unaff_EBX`; parent `mov ebx,eax`; entry load `[ebx+0x10]` |
| Walk buckets `0..mask` **inclusive** (`mask@+0x08`) | **Confirmed** — `while (uVar4 <= *(uint*)(ebx+8))` |
| Chain head = `*(table[i] + 4)`; next = `node[4]` (+0x10); payload = `node[3]` (+0x0C) | **Confirmed** (raw) |
| Stamp `PTR_FUN_00a2c2bc`; `operator_delete` payload only; freelist-push `@+0x20` overwriting slot0; clear heads | **Confirmed** |
| Does **not** free table / zero live count / rewrite mask | **Confirmed** — those belong to parent `00406fc0` |
| Sole caller: DestroyBucketTable `00406fc0` | **Accepted** (parent raw call + dual 1-xref) |
| Name `_Inferred` / product English open | **Correct hygiene** |
| Not tree++ neighbor `00408590` | **Confirmed** — different CF (isnil walk vs freelist) |

### Live / raw decompile (independent summary)

```c
void FUN_004085e0(void) // EBX = hash*
{
  uint bucket = 0;
  do {
    undefined4 *node = *(undefined4 **)(*(int *)(*(int *)(unaff_EBX + 0x10) + bucket * 4) + 4);
    while (node != 0) {
      undefined4 *next = (undefined4 *)node[4];
      *node = &PTR_FUN_00a2c2bc;
      if ((void *)node[3] != 0) operator_delete((void *)node[3]); // decomp "noreturn" is false
      node[3] = 0;
      *node = *(undefined4 *)(unaff_EBX + 0x20);      // freelist next
      *(undefined4 **)(unaff_EBX + 0x20) = node;       // freelist head
      node = next;
    }
    *(undefined4 *)(*(int *)(*(int *)(unaff_EBX + 0x10) + bucket * 4) + 4) = 0;
    bucket++;
  } while (bucket <= *(uint *)(unaff_EBX + 8));
}
```

Clean `CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred.cpp` matches CF (inclusive mask, payload-only delete, freelist push, no table free).

### Adversarial attacks (Freelist)

| # | Attack | Result |
|---|---|---|
| 1 | This is destroy-bucket-table (`00406fc0`) | **Fails** — no live zero, no `free`/`delete[]` of table |
| 2 | Skill thiscall freelist (`004cb680`) | **Fails** — EBX formal; skill uses ECX + different node offsets |
| 3 | Tree free-subtree / map erase | **Fails** — hash table + freelist head `@+0x20` |
| 4 | Frees nodes with `operator_delete` | **Fails** — only payload; node recycled |
| 5 | `operator_delete` aborts freelist push | **Fails** — raw continues after delete (decomp warning only) |
| 6 | Exclusive bucket loop `0..mask-1` | **Fails** — `<= mask` inclusive |
| 7 | VA-neighbor tree++ identity (`00408590`) | **Fails** — different system |
| 8 | Product English sealed | **Fails** — `_Inferred` |
| 9 | Runtime / bit-exact Confirmed | **Fails** — open |

### Soft niggles (not sealed-claim failures)

1. Clean types table entries as `CndHashNode*` — machine sentinels are stamp-`00a2c2e4` slabs (0xc); chain head still `@sentinel+4` (CF correct).
2. Payload typed dtor vs scalar `operator_delete` left open (inventory freelist uses virtual dtor path — different stamp family).

### Unit 1 dual quality

**PASS** — keep **`accept-with-gaps`**.

---

## Unit 2 — `0x004063a0` CNDHash_Ctor_00a2c2b0

### Body / ABI seal (independent)

```text
0x0040641c − 0x004063a0 + 1 = 0x7D = 125 B
```

| Claim | Independent result |
|---|---|
| Range `0x004063a0`–`0x0040641c` inclusive (**125 B** / `0x7D`); `CC` pad then dtor | **Confirmed** |
| **CL = log2**; **stack = CNDHash\***; **EAX = this**; **`ret 4`** | **Confirmed** — raw returns `param_2`; dual entry `MOV ESI,[ESP+…]`; `SHL EAX,CL`; exit `C2 04 00` |
| **Not** standard thiscall (this not in ECX) | **Confirmed** — Ghidra `__thiscall(byte, this*)` is role-swap fiction |
| vtbl **`PTR_FUN_00a2c2b0`**; `*(+8) = 1 << log2` provisional COUNT | **Confirmed** (raw) |
| Zero `+4,+0xc,+0x10,+0x14,+0x18,+0x20,+0x28,+0x2c,+0x30`; `+0x1c`=log2; `+0x1d`=0; **`+0x24` unwritten** | **Confirmed** — raw writes `param_2[8]` then skips `[9]` to `[10]` |
| Nested `CNDHash_AllocBucketTable_00a2c2e4` with **ESI=this** | **Confirmed** (raw call; alloc raw ESI formal) |
| Sole caller: `FUN_0093e7e0` — `new(0x34)`, **CL=2**, store host **`+0x3084`** | **Accepted** (dual caller site + size 0x34) |
| Stamp-suffix name; product English open | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
undefined4 * FUN_004063a0(byte log2 /*CL*/, undefined4 *self /*stack*/)
{
  *self = &PTR_FUN_00a2c2b0;
  self[2] = 1 << (log2 & 0x1f); // +8 COUNT
  self[1]=self[3]=self[4]=self[5]=self[6]=0;
  *(byte *)(self + 7) = log2;                 // +0x1c
  *(undefined1 *)((int)self + 0x1d) = 0;      // lock
  self[8] = 0;                                // +0x20
  // self[9] / +0x24 intentionally not written
  self[10]=self[0xb]=self[0xc]=0;
  FUN_00406f20(); // ESI=self → stamp 00a2c2e4; COUNT→MASK
  return self;    // ret 4
}
```

Clean matches field map, +0x24 gap, CL/stack ABI, ESI alloc handoff.

### Adversarial attacks (Ctor)

| # | Attack | Result |
|---|---|---|
| 1 | Skill thiscall ctor (`0051dd60`: ECX=this, stack log2) | **Fails** — inverted CL/stack; different vtbl |
| 2 | Ghidra thiscall role-correct | **Fails** — machine CL=log2 / stack this |
| 3 | Zeroes entire 0x34 / writes +0x24 | **Fails** — +0x24 gap preserved |
| 4 | Nested alloc is thiscall on ECX | **Fails** — ESI custom (WQ9G-J) |
| 5 | Multiple production create sites / variable log2 | **Fails as sole-xref claim** — one CALL, hard-coded CL=2 |
| 6 | Product English sealed | **Fails** — stamp suffix only |
| 7 | Runtime Confirmed | **Fails** — open |

### Soft niggles

1. Full dual of sole host init caller `FUN_0093e7e0` remains residual (not OWN).
2. Nested OOM/throw path lives in alloc (log2 gate / throw) — intentional residual.

### Unit 2 dual quality

**PASS** — keep **`accept-with-gaps`**.

---

## Unit 3 — `0x00406420` CNDHash_Dtor_00a2c2b0

### Body / ABI seal (independent)

```text
0x0040649a − 0x00406420 + 1 = 0x7B = 123 B
```

| Claim | Independent result |
|---|---|
| Range `0x00406420`–`0x0040649a` inclusive (**123 B** / `0x7B`); bare `ret`; pad `CC` | **Confirmed** |
| **`__thiscall`**; **ECX = CNDHash\***; void; bare `ret` | **Confirmed** — raw `param_1`; dual entry `MOV ESI,ECX` |
| Re-stamp vtbl `00a2c2b0` | **Confirmed** (raw) |
| Lock `@+0x1d`: log `HashError:Destructor…` + `VOG_DEBUG_STOP` then **continue** | **Confirmed** — no throw / no early return in raw |
| Destroy via **EAX** `00406fc0` then freelist subobject `FUN_00416e80(this+0x20)` | **Confirmed** — raw `FUN_00406fc0()` then `FUN_00416e80(param_1+8)`; dword index `+8` → **byte +0x20** |
| Sole caller: scalar deleting `FUN_00406520` (vtbl[`00a2c2b0`][0]) | **Accepted** (dual) |
| Stamp-suffix name; scaffold `Named_VOG_DEBUG_STOP_*` rejected | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
void __fastcall FUN_00406420(undefined4 *self /*ECX*/)
{
  *self = &PTR_FUN_00a2c2b0;
  if (*(char *)((int)self + 0x1d) != '\0') {
    FUN_007a4480(0, "HashError:Destructor, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    // fall through
  }
  FUN_00406fc0();           // EAX=self → zero live; freelist chains; free table
  FUN_00416e80(self + 8);   // dword+8 = this+0x20 freelist storage teardown
}
```

Clean matches soft lock, destroy-then-freelist order, +0x20 LEA modeling.

### Adversarial attacks (Dtor)

| # | Attack | Result |
|---|---|---|
| 1 | Lock throws or skips destroy | **Fails** — log only; continues |
| 2 | VOG_DEBUG_STOP-as-identity (scaffold) | **Fails** — full dtor CF |
| 3 | Same ABI as ctor (CL/stack `ret 4`) | **Fails** — thiscall / bare ret |
| 4 | Nested destroy is ECX thiscall | **Fails** — EAX ABI (`00406fc0`) |
| 5 | Freelist at byte offset +0x08 (literal `param_1+8`) | **Fails** — dword index → **+0x20** |
| 6 | Merge with Skill complete dtor `0051de80` | **Fails** — different VA/stamp/helpers |
| 7 | Product English sealed | **Fails** — stamp suffix only |
| 8 | Runtime Confirmed | **Fails** — open |

### Soft niggles

1. Nested freelist storage dtor `FUN_00416e80` undualed — dual correctly residualizes; destroy/freelist **order** still High.
2. Exact freelist subobject shape (single head ptr vs multi-dword slab vector) still open beyond “teardown at +0x20”.

### Unit 3 dual quality

**PASS** — keep **`accept-with-gaps`**.

---

## Unit 4 — `0x004195d0` CNDHash_Recreate_00a2c2e4

### Body / ABI seal (independent)

```text
0x00419618 − 0x004195d0 + 1 = 0x49 = 73 B
```

| Claim | Independent result |
|---|---|
| Range `0x004195d0`–`0x00419618` inclusive (**73 B** / `0x49`); bare `ret`; pad `CC` | **Confirmed** |
| **EAX = CNDHash\***; **BL = log2**; no stack; void; bare `ret` | **Confirmed** — raw `in_EAX` / `unaff_BL`; entry `56 8B F0` |
| Lock soft-continue with `HashError:Recreate…` + `VOG_DEBUG_STOP` | **Confirmed** (raw if then fall-through) |
| Order: destroy `00406fc0` → seed log2/`1<<log2`/`+0x14`/`+0x18` → alloc `00406f20` | **Confirmed** |
| Sole caller: `FUN_007fe640` — unlock `@+0x1d`, EAX=`*(owner+0x3084)`, **BL=2** | **Accepted** (dual; host field matches ctor store) |
| Distinct from skill thiscall recreate `004cbdc0` | **Confirmed** — skill uses ECX + stack log2 + `ret 4` |
| CF peer of inventory `004138d0` with different helpers | **Confirmed** — inventory calls `00413e20`/`00413d80` |
| Stamp-suffix name | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
void FUN_004195d0(void) // EAX=hash*, BL=log2
{
  if (*(char *)(in_EAX + 0x1d) != '\0') {
    FUN_007a4480(0, "HashError:Recreate, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  FUN_00406fc0(); // EAX ABI
  *(byte *)(in_EAX + 0x1c) = unaff_BL;
  *(int *)(in_EAX + 8) = 1 << (unaff_BL & 0x1f);
  *(undefined4 *)(in_EAX + 0x18) = 0;
  *(undefined4 *)(in_EAX + 0x14) = 0;
  FUN_00406f20(); // ESI ABI; mask post-cond
}
```

Clean matches lock-continue, seed stores, dual helper ABIs.

### Post-condition (independent via nested alloc)

After successful Recreate with valid log2 ∈ [1,16]:

```text
*(hash+8)  = (1 << log2) - 1   // COUNT seeded then MASK via 00406f20
*(hash+0x1c) = log2
ordered +0x14/+0x18 cleared before alloc
```

### Adversarial attacks (Recreate)

| # | Attack | Result |
|---|---|---|
| 1 | Lock hard-abort / early return / throw | **Fails** — soft log only |
| 2 | Skill thiscall + stack log2 + `ret 4` | **Fails** — EAX/BL bare ret |
| 3 | Same helper VAs as inventory `004138d0` | **Fails** — host uses `00406fc0`/`00406f20` |
| 4 | Stack arg for log2 | **Fails** — BL only; caller imm 2 |
| 5 | Product English sealed without stamp | **Fails** — stamp suffix |
| 6 | Runtime Confirmed | **Fails** — open |

### Soft niggles

1. Full dual of caller `FUN_007fe640` residual (not OWN).
2. Recreate does not clear freelist head / lock itself (caller unlocks); dual correctly does not invent extra clears.

### Unit 4 dual quality

**PASS** — keep **`accept-with-gaps`**.

---

## Family chain (independent)

```text
FUN_0093e7e0  (host init; new(0x34); log2=2 → host+0x3084)
  └─ CNDHash_Ctor_00a2c2b0 (0x004063a0)                         [WQ9H-D]
        └─ CNDHash_AllocBucketTable_00a2c2e4 (0x00406f20)       [WQ9G-J]

vtbl[00a2c2b0][0] = FUN_00406520  (scalar deleting)
  └─ CNDHash_Dtor_00a2c2b0 (0x00406420)                         [WQ9H-D]
        ├─ CNDHash_DestroyBucketTable_00a2c2e4 (0x00406fc0)     [WQ9G-J]
        │     └─ CNDHash_ReleaseBucketChainsToFreelist… (0x004085e0) [WQ9H-A]
        └─ FUN_00416e80 (this+0x20) freelist storage dtor       [residual]

FUN_007fe640  (post-traverse unlock on hash @ owner+0x3084)
  └─ CNDHash_Recreate_00a2c2e4 (0x004195d0)                     [WQ9H-E]
        ├─ DestroyBucketTable_00a2c2e4 (0x00406fc0)
        │     └─ freelist 0x004085e0
        └─ AllocBucketTable_00a2c2e4 (0x00406f20)
```

### Port ABI map (must not type-merge)

| Unit | Host ABI | Skill peer | Inventory peer |
|---|---|---|---|
| Freelist | **EBX**, bare ret | thiscall `004cb680` (different node layout) | EBX `00413ea0` (virt-dtor payload) |
| Ctor | **CL+stack, ret 4** | thiscall+stack log2 `0051dd60` | (family-dependent) |
| Dtor | **thiscall**, bare ret | thiscall complete `0051de80` | (family-dependent) |
| Recreate | **EAX+BL**, bare ret | thiscall+`ret 4` `004cbdc0` | **EAX+BL** `004138d0` (different helpers) |

Host object size **0x34**; vtbl **`00a2c2b0`**; sentinel stamp **`00a2c2e4`**; node stamp **`00a2c2bc`**.

---

## Confirmations

1. WQ9H-A freelist dual A/B + agent report seals are **faithful** to raw: EBX ABI, inclusive mask walk, payload-only delete, freelist push `@+0x20`, sole destroy parent.
2. WQ9H-D ctor dual seals are **faithful**: inverted CL/stack ABI, field map including **+0x24 skip**, vtbl imm, ESI alloc handoff, sole create site size 0x34 / log2=2.
3. WQ9H-D dtor dual seals are **faithful**: thiscall, non-fatal lock assert, EAX destroy, freelist teardown at **+0x20** (not byte +8), scalar-deleting caller.
4. WQ9H-E recreate dual seals are **faithful**: EAX/BL ABI, lock soft-continue, destroy→seed→alloc order, stamp-family helpers, host `+0x3084` chain with ctor.
5. Dual B correctly rejects: destroy-merge, skill thiscall merges, hard lock abort, freelist-at-byte-+8, tree-neighbor merge, scaffold VOG identity, inventory helper type-identity without ABI note.
6. Clean named sources match raw semantics; stamp / `_Inferred` hygiene correct; **terminal false**.

---

## Gaps (remain open — dual already owns)

| Gap | Unit | Blocks accept? |
|---|---|---|
| Product / PDB English for host class behind vtbl `00a2c2b0` / stamps `00a2c2e4`/`00a2c2bc` | All | No |
| Typed payload dtor vs scalar `operator_delete` | Freelist | No |
| Full dual of freelist storage dtor `FUN_00416e80` | Dtor | No |
| Full dual of scalar deleting wrapper `FUN_00406520` | Dtor | No |
| Full dual of host create `FUN_0093e7e0` / recreate caller `FUN_007fe640` | Ctor / Recreate | No |
| Runtime / bit-exact / differential | All | No (policy; terminal false) |

---

## Pass / fail

| Unit | Dual verdict | ADV result |
|---|---|---|
| `0x004085e0` CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred | **accept-with-gaps** | **PASS** — retain **accept-with-gaps** |
| `0x004063a0` CNDHash_Ctor_00a2c2b0 | **accept-with-gaps** | **PASS** — retain **accept-with-gaps** |
| `0x00406420` CNDHash_Dtor_00a2c2b0 | **accept-with-gaps** | **PASS** — retain **accept-with-gaps** |
| `0x004195d0` CNDHash_Recreate_00a2c2e4 | **accept-with-gaps** | **PASS** — retain **accept-with-gaps** |

### Overall

**PASS** — WQ9H CNDHash freelist/ctor/dtor/recreate dual seals hold under independent multi-source verification (raw + dual re-verify byte seals + clean CF match + parent alloc/destroy chain + inventory/skill ABI-layout contrast + body/field arithmetic). No sealed-claim failure requiring dual rewrite or verdict downgrade.

Soft residuals only: undualed nested freelist storage dtor + host create/recreate callers; product English; payload delete typing; runtime open.

**terminal = false**

---

## Process notes

- Independent ADV verifier; **not** WQ9H-A / WQ9H-D / WQ9H-E dual author.
- **No** parent ledger / WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY edits.
- **No** dual A/B rewrite; **no** Launcher.
- **No** `disassemble_bytes`.
- Verification uses sealed raw, dual 2026-08-04 re-verify claims, clean sources, parent WQ9G-J alloc/destroy raws, inventory/skill contrast raws, and independent size/field/ABI arithmetic.
- Output: `docs/reconstruction/reviews/ADV_wq9h_spotcheck_cndhash.md` (this file).
