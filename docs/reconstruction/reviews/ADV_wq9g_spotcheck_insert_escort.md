# Independent adversarial spot-check — WQ9G insert chain + escort ctor

| Field | Value |
|---|---|
| **Date** | `2026-08-04` |
| **Role** | Independent adversarial verifier (**not** dual author WQ9G-B / WQ9G-C / WQ9G-E) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | `WAVE_2026-08-04_wq009_depth4_partition_map.md` → **WQ9G-B** (`004cb4f0`/`00401480`), **WQ9G-C** unit `004cc400` only, **WQ9G-E** unit `006507c0` only |
| **Units** | (1) `0x004cb4f0` `StdTree_Predecessor_Isnil29_Inferred`; (2) `0x00401480` `StdPairKey_Less_HiSignedLoUnsigned_Inferred`; (3) `0x004cc400` `StdMap_OperatorIndex_Tfid_Isnil29_Inferred`; (4) `0x006507c0` `CVOGHBMissionEscort_ctor` |
| **Tools** | Dual reports A/B + raw/annotated/clean + function records + insert-hint parent raw (`004cc220`) for chain cross-check |
| **Live Ghidra this session** | Not required for seal audit — claims re-checked against dual-published raw decompile + re-verify body hex / `disassemble_function` plates + clean CF rewrite |
| **Forbidden** | `disassemble_bytes`; parent ledger edits; dual rewrite; Launcher |
| **Image** | `autoassault.exe` base `0x400000` |
| **Terminal** | **false** |

---

## Inspected evidence

### Dual / report surfaces

| Path |
|---|
| `docs/agents/task-dual-ab-004cb4f0-00401480-wq9gb-report.md` |
| `docs/agents/task-dual-ab-004cc400-004c9380-wq9gc-report.md` (unit `004cc400` only) |
| `docs/agents/task-dual-ab-006507c0-0051f940-wq9ge-report.md` (unit `006507c0` only) |
| `docs/reconstruction/reviews/A_aa_004cb4f0_StdTree_Predecessor_Isnil29_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_004cb4f0_StdTree_Predecessor_Isnil29_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_00401480_StdPairKey_Less_HiSignedLoUnsigned_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_00401480_StdPairKey_Less_HiSignedLoUnsigned_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_004cc400_StdMap_OperatorIndex_Tfid_Isnil29_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_004cc400_StdMap_OperatorIndex_Tfid_Isnil29_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_006507c0_CVOGHBMissionEscort_ctor.md` |
| `docs/reconstruction/reviews/B_aa_006507c0_CVOGHBMissionEscort_ctor.md` |

### Artifacts (four units)

| Kind | `004cb4f0` | `00401480` | `004cc400` | `006507c0` |
|---|---|---|---|---|
| Raw (+ re-verify) | `raw/aa_004cb4f0_FUN_004cb4f0.md` | `raw/aa_00401480_FUN_00401480.md` | `raw/aa_004cc400_FUN_004cc400.md` | `raw/aa_006507c0_FUN_006507c0.md` |
| Annotated | `…FUN_004cb4f0.annotated.md` | `…FUN_00401480.annotated.md` | `…FUN_004cc400.annotated.md` | `…FUN_006507c0.annotated.md` |
| Clean named | `StdTree_Predecessor_Isnil29_Inferred.cpp` | `StdPairKey_Less_HiSignedLoUnsigned_Inferred.cpp` | `StdMap_OperatorIndex_Tfid_Isnil29_Inferred.cpp` | `CVOGHBMissionEscort_ctor.cpp` |
| Clean twin | `FUN_004cb4f0.cpp` | `FUN_00401480.cpp` | `FUN_004cc400.cpp` | `FUN_006507c0.cpp` |
| Function named | `aa_004cb4f0_StdTree_…` | `aa_00401480_StdPairKey_…` | `aa_004cc400_StdMap_…` | `aa_006507c0_CVOGHBMissionEscort_ctor` |

### Support / chain evidence (not OWN duals of this ADV set)

| Artifact | Use |
|---|---|
| `raw/aa_004cc220_FUN_004cc220.md` (+ annotated) | Insert-hint parent: calls `00401480` (key less) + `004cb4f0` (prev); sole external caller `004cc400` @ `0x004cc457` |
| Dual WQ9G-C unit `004c9380` | **Out of scope** for this ADV (not in unit list) |
| Dual WQ9G-E unit `0051f940` | **Out of scope** for this ADV (not in unit list) |

### Evidence cross-check matrix

| Check | Result |
|---|---|
| Raw decompile ≡ dual A CF tables | **Yes** (all four) |
| Dual re-verify body ends + entry/exit hex recorded | **Yes** (all four) |
| Clean named ≡ raw CF | **Yes** (all four; named cleans own their VAs — no WQ9E-style plate collision) |
| Body-size arithmetic (exclusive ends) | **Yes** (see unit sections) |
| Insert-hint `004cc220` uses `00401480` + `004cb4f0` | **Yes** — parent raw |
| Op[] `004cc400` is sole external caller of insert-hint | **Yes** — parent raw sole-caller seal + op[] miss path `CALL 0x004cc220` |
| Pair-key less algebra matches op[] equality gate / hint order | **Yes** — hi signed primary, lo unsigned secondary |
| Escort RTTI / vtable / `ret 8` / period overwrite | **Yes** — raw hex + RTTI plate |
| Twin non-merge (isnil29 pred ≠ isnil15; pair less ≠ int SETL; Escort ≠ Outpost) | **Holds** |
| Terminal honesty | **false** on all duals / cleans |

---

## Unit 1 — `0x004cb4f0` StdTree_Predecessor_Isnil29_Inferred

### Body / ABI seal (independent)

```text
0x004cb540 − 0x004cb4f0 = 0x50 = 80 B exclusive
```

| Claim | Independent result |
|---|---|
| Range `0x004cb4f0`–`0x004cb540` exclusive (**80 B** / `0x50`); pad `CC` before `004cb550` | **Confirmed** (size math + raw hex plate) |
| **ECX = Node\*\*** — entry `8B 01` (`mov eax,[ecx]`) | **Confirmed** |
| Bare **`C3`**; void; leaf (no callees) | **Confirmed** (three exit arms; no `E8` in body hex) |
| isnil @ **+0x29** (`80 78 29 00` / `80 7A 29 00`) | **Confirmed** |
| left@+0 / parent@+4 / right@+8 | **Confirmed** (loads +0/+4/+8 only for links) |
| Three-arm predecessor: header→right; else left-subtree rightmost; else climb while left-child | **Confirmed** (raw ≡ clean) |
| Not successor (no right-subtree min walk) | **Confirmed** |
| Not isnil15 / EDX-it peers | **Confirmed** — all isnil cmps use `29`; ABI is ECX |
| Name `_Inferred` / product demangle open | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
void __fastcall FUN_004cb4f0(int *it /*ECX*/)
{
  int *cur = (int *)*it;
  if (*(char *)((int)cur + 0x29) != 0) {  // header/end
    *it = cur[2];                         // → right
    return;
  }
  int left = *cur;
  if (*(char *)(left + 0x29) == 0) {       // left not nil → rightmost
    int p = left, r = *(int *)(left + 8);
    while (*(char *)(r + 0x29) == 0) { p = r; r = *(int *)(r + 8); }
    *it = p;
    return;
  }
  // climb while current is left child of parent
  int *parent = (int *)cur[1];
  if (*(char *)((int)parent + 0x29) == 0) {
    do {
      if (*it != *parent) break;          // *it != parent->left
      *it = (int)parent;
      parent = (int *)parent[1];
    } while (*(char *)((int)parent + 0x29) == 0);
    if (*(char *)((int)parent + 0x29) == 0)
      *it = (int)parent;
  }
}
```

### Clean fidelity

| Item | Result |
|---|---|
| Named clean VA / size plate | **Owns `0x004cb4f0`** (no misbind) |
| CF rewrite | **Match** — three arms; isnil29; ECX |
| Scaffold twin | Thin forwarder to named clean — **OK** |

### Dual A/B quality

| Path | Verdict | ADV |
|---|---|---|
| A fidelity | accept-with-gaps | **Agree** — CF/ABI High; product open |
| B adversarial | accept-with-gaps | **Agree** — successor / isnil15 / EDX / RET-N attacks correctly falsified |

### Unit verdict

**PASS** — keep **`accept-with-gaps`**.

---

## Unit 2 — `0x00401480` StdPairKey_Less_HiSignedLoUnsigned_Inferred

### Body / ABI seal (independent)

```text
0x004014a5 − 0x00401480 = 0x25 = 37 B exclusive
```

Body hex (raw re-verify, 37 B) re-parsed independently:

```text
mov eax,[esp+4]      ; a*
mov edx,[eax+4]      ; a.hi
mov ecx,[esp+8]      ; b*
cmp edx,[ecx+4]      ; signed hi
jg  → return 0
jl  → return 1
mov eax,[eax]        ; a.lo
cmp eax,[ecx]        ; lo
jae → return 0       ; UNSIGNED (JAE)
mov eax,1 / ret 8
xor eax,eax / ret 8
```

| Claim | Independent result |
|---|---|
| Range exclusive **37 B** / `0x25`; pad `CC` | **Confirmed** |
| Two stack `uint32_t*`; **`C2 08 00` RET 8**; EAX 0\|1; leaf | **Confirmed** |
| **hi @+4 signed** primary (`JG`/`JL`) | **Confirmed** |
| **lo @+0 unsigned** secondary (`JAE`) | **Confirmed** |
| Algebra `(a.hi < b.hi) \|\| (a.hi == b.hi && a.lo < b.lo)` | **Confirmed** (raw decompile + bytes) |
| Not both-signed / both-unsigned / lo-primary / thiscall | **Confirmed** (B attacks stand) |
| Name `_Inferred` | **Correct hygiene** |

### Clean fidelity

| Item | Result |
|---|---|
| Named clean | **Owns VA**; early-out rewrite equivalent to dual-branch raw |
| Signedness | **Preserved** — `int32_t` hi, unsigned lo compare |
| Scaffold twin | Forwarder — **OK** |

### Dual A/B quality

| Path | Verdict | ADV |
|---|---|---|
| A | accept-with-gaps | **Agree** |
| B | accept-with-gaps | **Agree** — mixed signedness sealed by opcode class, not decompiler alone |

### Unit verdict

**PASS** — keep **`accept-with-gaps`**.

---

## Unit 3 — `0x004cc400` StdMap_OperatorIndex_Tfid_Isnil29_Inferred

### Body / ABI seal (independent)

```text
0x004cc469 − 0x004cc400 = 0x69 = 105 B exclusive
```

Raw includes full `disassemble_function` plate (not `disassemble_bytes`) through:

```text
CALL 0x004cb4b0          ; lower_bound TFID
CMP EAX,[EDI+4]          ; vs head
… JG hit / JL miss …
CMP EDX,[EAX+0x10]
JNC hit                  ; lo unsigned ≥ → hit (equality gate half)
… stage key16 + mapped=0 …
CALL 0x004cc220          ; insert-hint
MOV EAX,[EAX]
ADD EAX,0x20             ; mapped*
RET 4                    ; C2 04 00
```

| Claim | Independent result |
|---|---|
| Body **105 B** exclusive; terminal **`C2 04 00`**; pad `CC` | **Confirmed** (size + terminal hex `c2 04 00 cc…`) |
| `__thiscall`; ECX = map shell (`head@+4`); one stack key ptr; **RET 4** | **Confirmed** |
| lower_bound `0x004cb4b0` then hit = not-end ∧ ¬(key < node) | **Confirmed** |
| Eq order: hi **signed** @ node+0x14 / key[1]; lo **unsigned** @ node+0x10 / key[0] | **Confirmed** (JG/JL + JNC) |
| Miss: stage 4 key dwords + **mapped=0**; insert-hint; return `*pair` | **Confirmed** |
| Return **node+0x20** mapped* (`ADD EAX,0x20`) | **Confirmed** |
| Sole external caller of dualed insert-hint `0x004cc220` | **Confirmed** via parent raw sole-caller seal + this miss path |
| Not always-insert / not int-key op[] / not insert-or-find pair return | **Confirmed** (B attacks) |
| Name `_Inferred` | **Correct hygiene** |

### Clean fidelity

| Item | Result |
|---|---|
| Named clean owns `0x004cc400` | **Yes** — VA plate in header |
| CF | **Match** — `TfidKeyLess` + insert on end\|\|less; return `&mapped` |
| Scaffold twin | Near-literal raw rewrite — **OK** (VA-bound) |
| Prior WQ9E insert clean collision risk | **Absent** for this unit |

### Dual A/B quality

| Path | Verdict | ADV |
|---|---|---|
| A | accept-with-gaps | **Agree** — CF/ABI/RET4/sole-hint-caller High |
| B | accept-with-gaps | **Agree** — wrong-role attacks closed; English residual open |

### Soft niggle (not verdict-moving)

- Dual lists xref site `0x005dd869` without naming its enclosing function; does not weaken the 5-call / CF seals.

### Unit verdict

**PASS** — keep **`accept-with-gaps`**.

---

## Unit 4 — `0x006507c0` CVOGHBMissionEscort_ctor

### Body / ABI seal (independent)

```text
0x006508c8 − 0x006507c0 = 0x108 = 264 B exclusive
```

| Claim | Independent result |
|---|---|
| Body **264 B** exclusive; pad `CC` after **`ret 8`** | **Confirmed** (size + exit hex `83 c4 10 c2 08 00`) |
| `__thiscall`; ECX=this; stack `ownerCtx`, `reqHost`; returns **this** | **Confirmed** (raw + `mov eax,esi` path in hex plate) |
| Class **`CVOGHBMissionEscort`** via RTTI TD `.?AVCVOGHBMissionEscort@@` | **Confirmed** (dual RTTI plate; Outpost litter correctly rejected by B) |
| Vtable install `*this = PTR_FUN_009e52c4` (`c7 06 c4 52 9e 00`) | **Confirmed** |
| OnHB @ vtable +0x0C = dualed `0x006508d0` | **Accepted** (vtable slot claim; peer dual exists) |
| Default TFID pad `{−1,−1,0,0}` @ +0x38 from `DAT_009e52b0..bc` | **Confirmed** |
| Tag `0x0b` @ +0x1C; period force **1000** @ +0x08 after `SetPeriodAndCounter(-1000,true)` | **Confirmed** (imm `0xb` + push `-1000`/`true` then `c74608 e8030000`) |
| Factory alloc size **0x78** is caller-side (`FUN_0060c860`) | **Accepted** (documented correctly as not ctor body) |
| Second call site `0x00613e62` gap owned | **Correct residual** |
| Name **no** `_Inferred` (RTTI Confirmed) | **Correct hygiene** |

### Field seed cross-check (raw dword indices → offsets)

| Store | Offset | Source (raw) | Clean |
|---|---|---|---|
| nested world/slot | +0x24 | ownerCtx chain +0xa8 | **Match** |
| cached TFID[4] | +0x38..+0x44 | DAT pad | **Match** |
| pReqHost | +0x6C | param_3 | **Match** |
| targetMatchRef | +0x2C | req+0x44 post `FUN_0060c3c0` | **Match** |
| match mode byte | +0x30 | req+0x48 | **Match** |
| missionKey | +0x28 | `*(req+4)+0x10` | **Match** |
| max range | +0x48 | req+0x1c | **Match** |
| complete-zone pack | +0x50..+0x68 | req +0x28/+0x2c/+0x38/+0x30/+0x34/+0x3c | **Offset match**; English labels Probable (dual gap) |
| tag / period / tick | +0x1C / +0x08 / +0x70 | imm / 1000 / `g_dwClientTickMs` | **Match** |

### Clean fidelity

| Item | Result |
|---|---|
| Named clean owns `0x006507c0` | **Yes** |
| CF order | **Match** base→vtable→seed→resolve→SetPeriod→Attach→period/tick→return this |
| Decompiler pitfalls owned | **Yes** — `ret 8`; period overwrite; Outpost non-bind |
| Scaffold twin | `#include` of named clean — **OK** for alias |

### Dual A/B quality

| Path | Verdict | ADV |
|---|---|---|
| A | accept-with-gaps | **Agree** — RTTI/ctor CF High; reqHost English residual |
| B | accept-with-gaps | **Agree** — Outpost / void / ret4 / non-ctor / period-stays-−1000 falsified |

### Unit verdict

**PASS** — keep **`accept-with-gaps`**.

---

## Cross-unit insert chain consistency

```text
StdMap_OperatorIndex_Tfid_Isnil29 (0x004cc400)
  ├─ lower_bound TFID (0x004cb4b0)          [prior dual]
  └─ miss → StdTree_InsertHint_Isnil29 (0x004cc220)   [prior dual; sole caller = 004cc400]
              ├─ StdPairKey_Less_HiSignedLoUnsigned (0x00401480)  ← this ADV
              └─ StdTree_Predecessor_Isnil29 (0x004cb4f0)         ← this ADV
```

| Check | Result |
|---|---|
| Hint parent raw names both leaves | **Yes** |
| Pair order at leaf ≡ op[] equality gate | **Yes** (hi signed / lo unsigned) |
| Pred isnil29 family matches map nodes used by hint/op[] | **Yes** (+0x29) |
| Escort ctor is orthogonal mission HB residual (not tree) | **Yes** — correctly co-spotted as separate WQ9G-E unit |

No chain contradiction that would force a dual rewrite or verdict downgrade.

---

## Confirmations

1. All four dual verdicts (**accept-with-gaps**) are independently supportable from raw CF + byte plates + clean rewrite.
2. Insert-chain leaves (`004cb4f0`, `00401480`) and operator[] shell (`004cc400`) form a coherent isnil29 / TFID-pair port surface.
3. Escort ctor identity is RTTI-sealed; period/vtable/TFID-pad oddities preserved.
4. Clean plates are **VA-disambiguated** (no shared-filename collision of the WQ9E insert kind).
5. Terminal remains **false** everywhere (no runtime Confirmed claim overreach).
6. Dual process hygiene: no `disassemble_bytes`; OWN scopes respected; `_Inferred` only where product English open; Escort correctly un-suffixed.

---

## Gaps (remain open — dual already owns)

1. Product / MSVC demangle for tree value_type and pair-key English (TFID vs custom).
2. Full inventory of maps sharing `004cb4f0` / `00401480` beyond sealed callers.
3. Full 16 B TFID storage vs 8 B ordered-pair compare product English (`004cc400`).
4. Escort reqHost field dictionary product English; enclosing FUN for site `0x00613e62`.
5. Runtime golden / bit-exact / differential for all four.

---

## Pass / fail

| Unit | Dual verdict | ADV verdict |
|---|---|---|
| `0x004cb4f0` StdTree_Predecessor_Isnil29_Inferred | **accept-with-gaps** | **PASS** — retain **accept-with-gaps** |
| `0x00401480` StdPairKey_Less_HiSignedLoUnsigned_Inferred | **accept-with-gaps** | **PASS** — retain **accept-with-gaps** |
| `0x004cc400` StdMap_OperatorIndex_Tfid_Isnil29_Inferred | **accept-with-gaps** | **PASS** — retain **accept-with-gaps** |
| `0x006507c0` CVOGHBMissionEscort_ctor | **accept-with-gaps** | **PASS** — retain **accept-with-gaps** |

### Spot-check rollup

**PASS** — WQ9G insert-chain residuals (`004cb4f0`, `00401480`, `004cc400`) and escort ctor (`006507c0`) dual seals hold under independent multi-source verification (raw + dual re-verify hex/disasm plates + A/B consistency + named clean CF match + insert-hint parent chain). No sealed-claim failure requiring dual rewrite or verdict downgrade. Soft niggles limited to pre-owned English residuals and an unenclosed xref site label on `004cc400`.

**Terminal remains `false`.**

---

## Process notes

- Independent ADV verifier; **not** dual author of WQ9G-B / WQ9G-C / WQ9G-E.
- Scope limited to the four listed VAs; no edits to parent ledgers, dual reports, or A/B reviews.
- No `disassemble_bytes`; no Launcher.
- Evidence basis: dual-published raw/annotated/clean + dual A/B + agent reports + `aa_004cc220` parent raw for chain glue.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
