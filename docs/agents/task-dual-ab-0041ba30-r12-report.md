# Dual A/B report — R12-011 OWN-ONLY (`0x0041ba30`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-011**  
**Scope:** VA `0x0041ba30` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including peer Val16 always-insert `00407200`, buynode `0041d860`, parent `0041a570`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` + `read_memory` + `get_assembly_context` + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-011**.  
**System:** skills-abilities.  
**Parent dual:** `0x005a27f0` StdTree_Rrotate_Isnil21_Inferred (R11-007).  
**Dual start:** 2646.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0041ba30` StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred | **accept-with-gaps** — always-insert CF/ABI/RET0x10/isnil21/char-key/node0x24 sealed; product + buynode/parent dual residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): InsertHint-merge / InsertOrFind-as-sole-role / Val16-`00407200`-merge / isnil29-merge / freelist / wrong RET / wrong max / cdecl / skill-product-name / Runtime Confirmed all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0041ba30` — sealed facts

1. **Body:** `0x0041ba30`–`0x0041bbc5` inclusive (**406 B** / `0x196`); pad `CC`.
2. **ABI:** **`__thiscall`** ECX=map; stack `Node** out`, `char addLeft`, `Node* where`, `const void* value`; **`ret 0x10`** (`C2 10 00`). EAX returns `out` after `*out = node`.
3. **Semantics:** MSVC-style **always-insert + RB rebalance** for **char-key isnil@+0x21**:
   - Size gate: `size ≥ 0x0CCCCCCB` → `"map/set<T> too long"` / length_error / throw.
   - Buynode residual `FUN_0041d860` `(head, where, head, value*, color=0)` → `operator_new(0x24)`.
   - `size++`; link empty / left / right + extremum update.
   - While parent color red: uncle recolor or Lrotate `0050e9f0` / Rrotate `005a27f0`.
   - Root black @+0x20; `*out = node`.
4. **Layout:** node **0x24**; color@**+0x20**; isnil@**+0x21**; char key @**+0x0C** (from buynode + parent compare).
5. **Callees:** `0041d860` buynode (undualed); `0050e9f0` L (dualed); `005a27f0` R (dualed parent); length_error path.
6. **Callers (1):** residual `FUN_0041a570` (2 sites `0041a5c9`, `0041a600`).
7. **Xrefs:** 2 UNCONDITIONAL_CALL.
8. **Name:** `StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred` (Ghidra `FUN_0041ba30`). Product demangle open → `_Inferred`. Reject scaffold CVOG/Named_CalleeOf chain as product name.
9. **Twins (CF):** peer Val16 always-insert isnil21 `00407200` (different buynode/max); rotates L `0050e9f0` / R `005a27f0`; peer family isnil29 `00406c40`.
10. **Decompile ≡ raw CF**; RET + thiscall + size imm `0x0CCCCCCB` + color@+0x20 sealed via `read_memory`; parent call sites `MOV ECX,EDI` seal thiscall.

### Gaps

- Product / MSVC demangle for value_type / map instantiation.  
- Full dual of buynode `0041d860` and parent `0041a570` (roles sealed).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0041ba30_StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0041ba30_StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0041ba30_FUN_0041ba30.md` |
| Annotated | `docs/reconstruction/raw/aa_0041ba30_FUN_0041ba30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0041ba30.cpp` |
| Function | `docs/reconstruction/functions/aa_0041ba30_FUN_0041ba30.md` |
| Function named | `docs/reconstruction/functions/aa_0041ba30_StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_0041a570  char-key InsertOrFind / placement parent  [undualed]
  └─ StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred (0x0041ba30)  [OWN R12-011]
       ├─ FUN_0041d860          buynode node0x24 / isnil21  [undualed]
       ├─ StdTree_Lrotate_Isnil21_Inferred (0x0050e9f0)   [R10-030 dualed]
       └─ StdTree_Rrotate_Isnil21_Inferred (0x005a27f0)   [R11-007 dualed] ← parent dual

Peer (other instantiation, dualed elsewhere):
  00407200 StdTree_InsertAndRebalance_Isnil21_Inferred  (Val16 / node0x28 / max 0xFFFFFFE)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0041ba30-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0041ba30` | Port as **shared StdTree always-insert + rebalance** for **char-key isnil@+0x21 / color@+0x20 / node 0x24**. **thiscall** ECX=map; stack `(out, addLeft, where, value)`; **ret 0x10**. Size gate **`0x0CCCCCCB`**. Pair with Lrotate `0050e9f0`, Rrotate `005a27f0`, buynode `0041d860`, parent `0041a570`. |
| Pair with | Dualed isnil21 rotates; residual char-key parent/buynode. |
| Naming caution | **Not** Val16 always-insert `00407200`. **Not** InsertHint/InsertOrFind. **Not** isnil29 family. **Not** skill/CVOGReaction-specific product API. |

---

## Parent merge handoff (not done here)

Parent dual R11-007 listed this insert as a residual caller of Rrotate `005a27f0` — now dualed R12-011. Registry / matrix / system ledger updates are parent-merge responsibility (forbidden for this OWN agent).
