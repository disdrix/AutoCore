# Independent adversarial spot-check — WQ9I vector ConstructN/PodCopy + tree NodeCtor + list Incsize

| Field | Value |
|---|---|
| **Date** | `2026-08-05` |
| **Role** | Independent adversarial verifier (**not** dual author WQ9I-A / WQ9I-B / WQ9I-C / WQ9I-E) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | `WAVE_2026-08-04_wq009_depth6_partition_map.md` → **WQ9I-A** unit `00409db0`; **WQ9I-B** unit `00409f30`; **WQ9I-C** unit `004099b0`; **WQ9I-E** unit `00416010` |
| **Units** | (1) `0x00409db0` `StdVector_ConstructN_Elem12_Inferred`; (2) `0x00409f30` `StdVector_PodCopyElement_0x28_Inferred`; (3) `0x004099b0` `StdTree_NodeCtor_Val16_Isnil21_Inferred`; (4) `0x00416010` `StdList_Incsize_Max1fffffff` |
| **Tools** | Dual reports A/B + raw/annotated/clean + function records + parent chain raws (ConstructN0x28, buynode, list insert parent) |
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
| `docs/agents/task-dual-ab-00416e80-00409db0-wq9ia-report.md` (unit `00409db0` only) |
| `docs/agents/task-dual-ab-00409f30-00407200-wq9ib-report.md` (unit `00409f30` only) |
| `docs/agents/task-dual-ab-00407060-004099b0-wq9ic-report.md` (unit `004099b0` only) |
| `docs/agents/task-dual-ab-00416010-004160b0-wq9ie-report.md` (unit `00416010` only) |
| `docs/reconstruction/reviews/A_aa_00409db0_StdVector_ConstructN_Elem12_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_00409db0_StdVector_ConstructN_Elem12_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_00409f30_StdVector_PodCopyElement_0x28_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_00409f30_StdVector_PodCopyElement_0x28_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_004099b0_StdTree_NodeCtor_Val16_Isnil21_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_004099b0_StdTree_NodeCtor_Val16_Isnil21_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_00416010_StdList_Incsize_Max1fffffff.md` |
| `docs/reconstruction/reviews/B_aa_00416010_StdList_Incsize_Max1fffffff.md` |

### Artifacts (four units)

| Kind | `00409db0` | `00409f30` | `004099b0` | `00416010` |
|---|---|---|---|---|
| Raw (+ re-verify) | `raw/aa_00409db0_FUN_00409db0.md` | `raw/aa_00409f30_FUN_00409f30.md` | `raw/aa_004099b0_FUN_004099b0.md` | `raw/aa_00416010_FUN_00416010.md` |
| Annotated | `…FUN_00409db0.annotated.md` | `…FUN_00409f30.annotated.md` | `…FUN_004099b0.annotated.md` | `…FUN_00416010.annotated.md` |
| Clean named | `StdVector_ConstructN_Elem12_Inferred.cpp` | `StdVector_PodCopyElement_0x28_Inferred.cpp` | `StdTree_NodeCtor_Val16_Isnil21_Inferred.cpp` | `StdList_Incsize_Max1fffffff.cpp` |
| Clean twin | `FUN_00409db0.cpp` | `FUN_00409f30.cpp` | `FUN_004099b0.cpp` | `FUN_00416010.cpp` |
| Function named | `aa_00409db0_StdVector_…` | `aa_00409f30_StdVector_…` | `aa_004099b0_StdTree_…` | `aa_00416010_StdList_…` |

### Support / chain evidence (not OWN duals of this ADV set)

| Artifact | Use |
|---|---|
| Raw `aa_00409d40` ConstructN 0x28 | Parent of PodCopy `00409f30`; loop call + `add dest,0x28` |
| Dual WQ9G-I `00406ee0` Ufill Elem12 | Sole Ufill caller of ConstructN `00409db0` |
| Dual WQ9H-C `004062a0` PushBack Elem12 | Fast-path caller of ConstructN `00409db0` |
| Dual WQ9H-J `00408990` Buynode Val16/isnil21 | Sole caller of NodeCtor `004099b0` after `operator_new(0x28)` |
| Raw `aa_00415dd0` list insert parent | Calls Incsize `00416010` with count=1 after buy-node |
| Twin Incsize `0043fe60` (max `0x3fffffff`) | Contrast — dual B rejects merge |
| Prior ADV `ADV_wq9h_spotcheck_vector_env.md` | Vector family residual: ConstructN/PodCopy chain under InsertN/PushBack |

### Evidence cross-check matrix

| Check | Result |
|---|---|
| Raw decompile ≡ dual A CF tables | **Yes** (all four) |
| Dual re-verify body ends + entry/exit hex recorded | **Yes** (all four; PodCopy full 20 B plate; NodeCtor hex dump; Incsize max imm) |
| Clean named owns correct VA (no plate collision) | **Yes** (all four; twins re-express or forward) |
| Body-size arithmetic (inclusive/exclusive per dual) | **Yes** (see unit sections) |
| ConstructN12 → PodCopy leaf `00409f50` (3 dwords / EAX·ECX) **≠** PodCopy `00409f30` (10 dwords / EAX·EDX) | **Holds** — dual B trap explicit; ADV re-confirms |
| PodCopy `00409f30` under ConstructN0x28 `00409d40` only (not under ConstructN12) | **Yes** — parent raw loop calls `00409f30` |
| NodeCtor under buynode only; no alloc inside ctor | **Yes** — buynode raw `new(0x28)` then `FUN_004099b0` |
| Incsize max `0x1fffffff` distinct from `0x3fffffff` twin | **Yes** — raw gate + dual B |
| Terminal honesty | **false** on all duals / cleans / this ADV |
| Runtime Confirmed | **Not claimed** |

---

## Unit 1 — `0x00409db0` StdVector_ConstructN_Elem12_Inferred

### Body / ABI seal (independent)

```text
0x00409e12 − 0x00409db0 + 1 = 0x63 = 99 B  (inclusive end)
```

| Claim | Independent result |
|---|---|
| Range `0x00409db0`–`0x00409e12` inclusive (**99 B** / `0x63`); plain **`C3`** | **Confirmed** (size math + raw re-verify plate) |
| **ECX** = `const T*` value; stack dest + count; caller cleans 8 B | **Confirmed** (raw byte plate `mov ebx,ecx`; parents pass ECX) |
| Loop: `FUN_00409f50(EAX=dest, ECX=value)` × count; **dest += 0x0C** | **Confirmed** (bytes `add esi,0x0C`; decomp omits step — dual correctly overrides) |
| Callee = **3-dword** PodCopy (`00409f50`), **not** 10-dword `00409f30` | **Confirmed** (raw + annotated + dual B attack #11) |
| Callers (2): Ufill `00406ee0` @ `00406eec`; push_back fast `004062a0` @ `004062ef` | **Accepted** (dual re-verify + prior dualed parents) |
| Not InsertN / Ufill wrapper / ConstructN 0x28 | **Holds** — dual B rejects merge |
| Name `_Inferred` / product POD English open | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
// Decomp omits ECX value + dest step — sealed by bytes:
//   mov ebx,ecx; mov esi,[ebp+8]; mov edi,[ebp+0xC]
//   loop: mov ecx,ebx; mov eax,esi; call 00409f50; sub edi,1; add esi,0x0C
void FUN_00409db0(undefined4 param_1 /*dest*/, int param_2 /*count*/)
{
  // SEH LAB_009bc620
  for (; param_2 != 0; param_2--) {
    FUN_00409f50(); // machine: EAX=dest, ECX=value*; 3 dwords
  }
  return; // C3
}
```

### Clean fidelity

| Item | Result |
|---|---|
| Named clean VA / size plate | **Owns `0x00409db0`** (99 B / plain ret) |
| CF rewrite | **Match** — ECX value*, loop PodCopy, dest+=0x0C |
| Scaffold twin | Re-expresses same CF — **OK** (not a VA collision) |
| SEH | Omitted honestly from clean body |

### Dual A/B quality

| Path | Verdict | ADV |
|---|---|---|
| A fidelity | accept-with-gaps | **Agree** — construct-N role High; stride Confirmed |
| B adversarial | accept-with-gaps | **Agree** — InsertN/Ufill/0x28/dword/thiscall/stdcall attacks falsified |

### Unit verdict

**PASS** — keep **`accept-with-gaps`**. Residual: undualed leaf `00409f50` + product type (dual already open).

---

## Unit 2 — `0x00409f30` StdVector_PodCopyElement_0x28_Inferred

### Body / ABI seal (independent)

```text
0x00409f43 − 0x00409f30 + 1 = 0x14 = 20 B  (inclusive end)
```

| Claim | Independent result |
|---|---|
| Range `0x00409f30`–`0x00409f43` inclusive (**20 B** / `0x14`); pad `CC` | **Confirmed** |
| Full body bytes `57 8B F8 85 FF 74 0B 56 B9 0A 00 00 00 8B F2 F3 A5 5E 5F C3` | **Confirmed** (raw re-verify plate) |
| **EAX** = dest; **EDX** = src; bare **`C3`**; no stack args | **Confirmed** (machine + ConstructN parent call shape) |
| Null dest → skip; else **REP MOVSD** ECX=**10** → **0x28** bytes | **Confirmed** (`TEST EDI` / `JZ` / imm `0x0A` / `F3 A5`) |
| Callers (2): ConstructN 0x28 `00409d40` @ `00409d78`; range `0040a520` @ `0040a558` | **Confirmed** (parent raw loop + dual) |
| Leaf (no callees); not ConstructN loop; not 0xC twin | **Holds** — dual B rejects |
| Name `_Inferred` / product open | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
void __fastcall FUN_00409f30(undefined4 param_1 /*phantom*/, undefined4 *param_2 /*src=EDX*/)
{
  undefined4 *in_EAX; // dest
  if (in_EAX != 0) {
    for (int i = 10; i != 0; --i) { // machine: REP MOVSD ECX=10
      *in_EAX++ = *param_2++;
    }
  }
  return; // C3
}
```

### Clean fidelity

| Item | Result |
|---|---|
| Named clean VA / size plate | **Owns `0x00409f30`** (20 B) |
| CF rewrite | **Match** — null-dst no-op; `memcpy(dest,src,0x28)` ≡ 10 dwords |
| Scaffold twin | `#include` of named clean — **OK** |

### Dual A/B quality

| Path | Verdict | ADV |
|---|---|---|
| A fidelity | accept-with-gaps | **Agree** — leaf CF/ABI Confirmed |
| B adversarial | accept-with-gaps | **Agree** — thiscall / 0xC / ConstructN-loop / always-copy attacks falsified |

### Unit verdict

**PASS** — keep **`accept-with-gaps`**.

---

## Unit 3 — `0x004099b0` StdTree_NodeCtor_Val16_Isnil21_Inferred

### Body / ABI seal (independent)

```text
0x004099f3 − 0x004099b0 = 0x43 = 67 B  (exclusive end)
```

| Claim | Independent result |
|---|---|
| Range `0x004099b0`–`0x004099f3` exclusive (**67 B** / `0x43`); pad `CC` | **Confirmed** |
| **`__thiscall`** ECX=node*; stack L/P/R/value4*/color; **`RET 0x14`** (`C2 14 00`) | **Confirmed** (raw hex + epilogue) |
| Layout: L/P/R @+0/+4/+8; Val16 four dwords @+0x10..+0x1c; color@+0x20; **isnil=0** @+0x21 | **Confirmed** (raw decompile + store table) |
| **+0x0c untouched** | **Confirmed** (raw no write; dual B attack) |
| **EAX = this** (entry `MOV EAX,ECX`); decomp `void` is display false | **Confirmed** |
| Sole caller buynode `00408990` after `operator_new(0x28)` | **Confirmed** (buynode raw) |
| Not full buynode / Val24-isnil29 / head shell / freelist | **Holds** — dual B rejects |
| Name `_Inferred` / product value English open | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
void __thiscall FUN_004099b0(
    undefined4 *param_1 /*this*/,
    undefined4 left, undefined4 parent, undefined4 right,
    undefined4 *value4, undefined1 color)
{
  *param_1 = left;
  param_1[1] = parent;
  param_1[2] = right;
  // +0x0c not written
  param_1[4] = value4[0]; // +0x10
  param_1[5] = value4[1];
  param_1[6] = value4[2];
  param_1[7] = value4[3]; // +0x1c
  *(undefined1 *)(param_1 + 8) = color;           // +0x20
  *(undefined1 *)((int)param_1 + 0x21) = 0;       // isnil
  return; // RET 0x14; EAX=this
}
```

### Clean fidelity

| Item | Result |
|---|---|
| Named clean VA / size plate | **Owns `0x004099b0`** (67 B exclusive) |
| CF rewrite | **Match** — L/P/R + Val16 + color + isnil0; returns self |
| Scaffold twin | Forwards to named clean — **OK** |

### Dual A/B quality

| Path | Verdict | ADV |
|---|---|---|
| A fidelity | accept-with-gaps | **Agree** — layout/ABI High |
| B adversarial | accept-with-gaps | **Agree** — alloc-inside / isnil1 / Val24 / stdcall attacks falsified |

### Unit verdict

**PASS** — keep **`accept-with-gaps`**.

---

## Unit 4 — `0x00416010` StdList_Incsize_Max1fffffff

### Body / ABI seal (independent)

```text
0x0041607e − 0x00416010 + 1 = 0x6F = 111 B  (inclusive end)
```

| Claim | Independent result |
|---|---|
| Range `0x00416010`–`0x0041607e` inclusive (**111 B** / `0x6F`); plain **`C3`** | **Confirmed** |
| **ECX** = count; **EDX** = list*; no stack args; void | **Confirmed** (raw `__fastcall`; dual B rejects thiscall) |
| Gate: `(0x1fffffffU - *(list+8)) < count` → `"list<T> too long"` throw | **Confirmed** (raw + string @ `0x00a1581c`) |
| Else `*(list+8) += count` (`_Mysize`) | **Confirmed** |
| Max **`0x1fffffff`** ≠ twin `0043fe60` max `0x3fffffff` | **Confirmed** (dual B attack) |
| Not node alloc / link (buy-node is `00415ed0`) | **Confirmed** |
| Callers pass count=1 after buy-node | **Accepted** (dual re-verify + parent raw call site) |
| Product exception type open; Terminal false | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
void __fastcall FUN_00416010(uint param_1 /*ECX count*/, int param_2 /*EDX list*/)
{
  // SEH LAB_009bc919
  if (0x1fffffffU - *(int *)(param_2 + 8) < param_1) {
    // basic_string("list<T> too long");
    // FUN_00401a40(...);
    // _CxxThrowException(..., &DAT_00acc388); // noreturn
  }
  *(uint *)(param_2 + 8) = *(int *)(param_2 + 8) + param_1;
  return; // C3
}
```

### Clean fidelity

| Item | Result |
|---|---|
| Named clean VA / size plate | **Owns `0x00416010`** |
| CF rewrite | **Match** on size gate + `_Mysize += count` |
| Throw path | Clean uses `return` after comment for noreturn throw — **plate softener** (see F1) |
| Scaffold twin | Forwards to named clean — **OK** |

### Dual A/B quality

| Path | Verdict | ADV |
|---|---|---|
| A fidelity | accept-with-gaps | **Agree** — role/ABI/max/string High |
| B adversarial | accept-with-gaps | **Agree** — thiscall / soft-fail / unlimited / twin-merge attacks falsified |

### Unit verdict

**PASS** — keep **`accept-with-gaps`**. Clean throw softener is non-blocking (F1).

---

## Findings (non-blocking)

| # | Severity | Finding | Impact |
|---|---|---|---|
| F1 | Low | **Incsize named clean** softens noreturn throw path to a commented `return`. Dual B already falsifies soft-fail / bool-success claims; raw remains authoritative for throw. | Ports must not treat clean overflow path as recoverable; implement throw or abort matching retail. |
| F2 | Low (port) | **PodCopy ABI family trap:** ConstructN Elem12 uses leaf `00409f50` (**EAX dest / ECX src / 3 dwords**); PodCopy Elem0x28 `00409f30` is **EAX dest / EDX src / 10 dwords**. Dual B seals both, but a naive “all PodCopy are EAX/EDX” merge would corrupt construct-N for 0xC. | Keep leaves distinct in AutoCore ports; do not share one register ABI across 0xC and 0x28 families. |
| F3 | Info | PodCopy leaf `00409f50` remains **undualed** under ConstructN Elem12 (CF sealed as residual). Range worker `0040a520` undualed under PodCopy 0x28. | Expected open gaps; not dual overclaim. |
| F4 | Info | Body-end **notation** differs: Units 1/2/4 inclusive; Unit 3 exclusive. Arithmetic is consistent either way. | Prefer uniform exclusive ends in future dual plates. |
| F5 | Info | Product English open on ConstructN / PodCopy / NodeCtor (`_Inferred`); Incsize name sealed from plate string but exception type behind `DAT_00acc388` open. | Correct Terminal **false**. |

No CF reject. No dual A↔B contradiction on sealed ABI/role. No clean plate VA collision (unlike prior ADV free/dtor / insert-clone hazards). No Terminal overclaim.

---

## Overall verdict

| Unit | Dual seal | ADV unit verdict |
|---|---|---|
| `0x00409db0` ConstructN Elem12 | accept-with-gaps | **PASS** |
| `0x00409f30` PodCopy 0x28 | accept-with-gaps | **PASS** |
| `0x004099b0` NodeCtor Val16/isnil21 | accept-with-gaps | **PASS** |
| `0x00416010` StdList_Incsize Max1fffffff | accept-with-gaps | **PASS** |

### **PASS-WITH-FINDINGS**

Dual OWN seals for the four units hold under independent adversarial read of dual A/B + raw re-verify + cleans. Structural CF, ABI, strides (0xC vs 0x28), NodeCtor layout/RET, and list Incsize max/string are sealed at High/Confirmed as claimed. Findings F1–F2 are clean-fidelity / port-hygiene soft spots already bounded by dual residual language; they do **not** justify FAIL or dual rewrite.

**Terminal:** **false** (no runtime Confirmed; no Launcher this session).

---

## What ADV did **not** do

- No `disassemble_bytes`
- No parent ledger / WORK_QUEUE / RESUME / VERIFICATION_MATRIX / NAMING_REGISTRY / COVERAGE_LEDGER / ACTIVE_WORK / CHANGE_LOG edits
- No dual A/B or clean rewrites
- No Launcher / live runtime
- No dual of out-of-scope pair mates (`00416e80`, `00407200`, `00407060`, `004160b0`)

---

## Output

- This report: `docs/reconstruction/reviews/ADV_wq9i_spotcheck_vector_list.md`
- Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
