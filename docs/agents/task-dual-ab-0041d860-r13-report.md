# Dual A/B report — R13-023 OWN-ONLY (`0x0041d860`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-023**  
**Scope:** VA `0x0041d860` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including peer Val16 buynode `00408990`, residual value ctor `0041c140`, placement parent `0041a570`, always-insert parent already dualed as evidence only).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` / `get_xrefs_to` + `read_memory` + `disassemble_function` + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-023**.  
**System:** skills-abilities.  
**Parent dual:** `0x0041ba30` StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred (R12-011).  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0041d860` StdTree_Buynode_CharKey_Isnil21_Inferred | **accept-with-gaps** — stdcall buynode CF/ABI/RET0x14/node0x24/char@+0x0C/color@+0x20/isnil0@+0x21/sole caller sealed; product + residual value ctor dual open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): freelist/CNDHash / Val16-`00408990`-merge / Val24-isnil29-merge / thiscall-map / skill-product-name / Runtime Confirmed all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0041d860` — sealed facts

1. **Body:** `0x0041d860`–`0x0041d8e5` inclusive (**134 B** / `0x86`); epilogue **`RET 0x14`** (`C2 14 00` @ `0x0041d8e3`); pad `CC` after body.
2. **ABI:** **`__stdcall`**; 5 stack args `(left, parent, right, value*, color)`; **EAX** = node\* \| null. Entry is **not** thiscall on the map (ECX used only for nested value ctor).
3. **Semantics:** MSVC-style **StdTree buynode** for **char-key isnil@+0x21**:
   - SEH frame (`LAB_009bd7d1`).
   - `operator_new(0x24)`.
   - If non-null: left/parent/right; **char key** @+0x0C from `*value`; thiscall residual `FUN_0041c140` on **node+0x10** from `value+4`; **color** @+0x20; **isnil=0** @+0x21.
4. **Layout:** node **0x24**; color@**+0x20**; isnil@**+0x21**; char key @**+0x0C**; residual value body @**+0x10** (elem stride 0x18 via residual ctor — product Open).
5. **Callees:** `operator_new(0x24)`; residual `FUN_0041c140` (undualed).
6. **Callers (1):** dualed `FUN_0041ba30` @ `0x0041ba9d` — args `(head, where, head, value*, color=0)`.
7. **Xrefs:** 1 UNCONDITIONAL_CALL.
8. **Name:** `StdTree_Buynode_CharKey_Isnil21_Inferred` (Ghidra `FUN_0041d860`). Product demangle open → `_Inferred`. Reject scaffold CVOG/Named_CalleeOf chain as product name.
9. **Twins (CF):** peer Val16 isnil21 buynode `00408990` (node 0x28 — **do not merge**); parent always-insert `0041ba30` (R12-011 dualed); family isnil21 rotates `0050e9f0` / `005a27f0`.
10. **Decompile ≡ raw CF**; RET + stdcall + size imm `0x24` + color/isnil stores sealed via `read_memory` / disasm; nested thiscall ECX sealed despite decompiler elision.

### Gaps

- Product / MSVC demangle for value_type / map instantiation.  
- Full dual of residual value ctor `0041c140` (and callees) — not OWN.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0041d860_StdTree_Buynode_CharKey_Isnil21_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0041d860_StdTree_Buynode_CharKey_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0041d860_FUN_0041d860.md` |
| Annotated | `docs/reconstruction/raw/aa_0041d860_FUN_0041d860.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Buynode_CharKey_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0041d860.cpp` |
| Function | `docs/reconstruction/functions/aa_0041d860_FUN_0041d860.md` |
| Function named | `docs/reconstruction/functions/aa_0041d860_StdTree_Buynode_CharKey_Isnil21_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_0041a570  char-key InsertOrFind / placement parent  [undualed]
  └─ StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred (0x0041ba30)  [dualed R12-011]
       ├─ StdTree_Buynode_CharKey_Isnil21_Inferred (0x0041d860)  [OWN R13-023]
       │    └─ FUN_0041c140   residual value construct @+0x10  [undualed]
       ├─ StdTree_Lrotate_Isnil21_Inferred (0x0050e9f0)   [R10-030 dualed]
       └─ StdTree_Rrotate_Isnil21_Inferred (0x005a27f0)   [R11-007 dualed]

Peer (other instantiation, dualed elsewhere):
  00408990 StdTree_Buynode_Val16_Isnil21_Inferred  (node 0x28 / Val16 — do not merge)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0041d860-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0041d860` | Port as **shared StdTree buynode** for **char-key isnil@+0x21 / color@+0x20 / node 0x24**. **`__stdcall`** `(left, parent, right, value*, color)`; **ret 0x14**; EAX=node*\|null. Pair with always-insert `0041ba30`, residual value ctor `0041c140`. |
| Pair with | Dualed char-key always-insert `0041ba30`; dualed isnil21 rotates; residual placement `0041a570`. |
| Naming caution | **Not** Val16 buynode `00408990`. **Not** Val24/isnil29 buynodes. **Not** freelist/CNDHash. **Not** skill/CVOGReaction-specific product API. |

---

## Parent merge handoff (not done here)

Parent dual R12-011 listed this buynode as residual callee of always-insert `0041ba30` — now dualed R13-023. Registry / matrix / system ledger updates are parent-merge responsibility (forbidden for this OWN agent).
