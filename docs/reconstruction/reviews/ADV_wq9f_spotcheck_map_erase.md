# Independent adversarial spot-check — WQ9F map erase cluster

| Field | Value |
|---|---|
| **Date** | `2026-08-04` |
| **Role** | Independent adversarial verifier (**not** dual author for WQ9F-C / WQ9F-F / WQ9F-G) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | `WAVE_2026-08-04_wq009_depth3_partition_map.md` → sample of **WQ9F-C**, **WQ9F-F**, **WQ9F-G** (map erase path) |
| **Units** | (1) `0x004cbaa0` `StdTree_EraseRange_Isnil29_Inferred` |
| | (2) `0x0051c880` `Map_EraseNode_Isnil1d_Inferred` |
| | (3) `0x0051be50` `Map_FreeSubtree_Isnil15` |
| | (4) `0x0051ce00` `Map_EraseNode_Isnil15` |
| **Tools** | Dual reports + A/B + raw/annotated/clean + function records; dual-appended `read_memory` / epilogue hex; peer dualed range cleans (`Map_EraseRange_Isnil1d` / `Map_EraseRange_Isnil15`); body-size arithmetic; callee-family cross-check. **No** `disassemble_bytes` |
| **Live Ghidra this session** | Not required for seal — dual re-verify 2026-08-04 documents live ≡ raw CF + epilogue bytes; independent re-check uses those sealed surfaces + raw decompile plates |
| **Forbidden** | `disassemble_bytes`; parent ledger edits; dual rewrite; Launcher |
| **Image** | `autoassault.exe` base `0x400000` |
| **Terminal** | **false** (no runtime Confirmed) |

---

## Inspected evidence

### Dual / report surfaces

| Path |
|---|
| `docs/agents/task-dual-ab-004c8780-004cbaa0-wq9fc-report.md` |
| `docs/agents/task-dual-ab-0051c880-0051be50-wq9ff-report.md` |
| `docs/agents/task-dual-ab-0051ce00-0051e120-wq9fg-report.md` |
| `docs/reconstruction/reviews/A_aa_004cbaa0_StdTree_EraseRange_Isnil29_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_004cbaa0_StdTree_EraseRange_Isnil29_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_0051c880_Map_EraseNode_Isnil1d_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_0051c880_Map_EraseNode_Isnil1d_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_0051be50_Map_FreeSubtree_Isnil15.md` |
| `docs/reconstruction/reviews/B_aa_0051be50_Map_FreeSubtree_Isnil15.md` |
| `docs/reconstruction/reviews/A_aa_0051ce00_Map_EraseNode_Isnil15.md` |
| `docs/reconstruction/reviews/B_aa_0051ce00_Map_EraseNode_Isnil15.md` |

### Artifacts (four VAs)

| Kind | `aa_004cbaa0` | `aa_0051c880` | `aa_0051be50` | `aa_0051ce00` |
|---|---|---|---|---|
| Raw (+ re-verify) | `raw/aa_004cbaa0_FUN_004cbaa0.md` | `raw/aa_0051c880_FUN_0051c880.md` | `raw/aa_0051be50_FUN_0051be50.md` | `raw/aa_0051ce00_FUN_0051ce00.md` |
| Annotated | `…FUN_004cbaa0.annotated.md` | `…FUN_0051c880.annotated.md` | `…FUN_0051be50.annotated.md` | `…FUN_0051ce00.annotated.md` |
| Clean named | `StdTree_EraseRange_Isnil29_Inferred.cpp` | `Map_EraseNode_Isnil1d_Inferred.cpp` | `Map_FreeSubtree_Isnil15.cpp` | `Map_EraseNode_Isnil15.cpp` |
| Clean twin | `FUN_004cbaa0.cpp` | `FUN_0051c880.cpp` | `FUN_0051be50.cpp` | `FUN_0051ce00.cpp` |
| Function named | `aa_004cbaa0_StdTree_…` | `aa_0051c880_Map_…` | `aa_0051be50_Map_…` | `aa_0051ce00_Map_…` |

### Peer / chain evidence (not OWN duals of this ADV)

| Artifact | Use |
|---|---|
| Dualed `Map_EraseRange_Isnil1d_Inferred` clean (`0x0051d700`) | Confirms sole-caller chain → `FUN_0051c880` partial; free `0051be10` (isnil1d) |
| Dualed `Map_EraseRange_Isnil15` clean (`0x0051d7c0`) | Confirms free `0051be50` full-clear + erase `0051ce00` partial |
| Dualed `StdTree_EraseAndRebalance_Isnil29` (`0x004cb740`) | Partial callee of `004cbaa0`; isnil@+0x29 peer |
| Dualed `Map_EraseNode` / `_B` (isnil@+0x29) | Non-merge contrast for isnil1d / isnil15 erases |
| Prior ADV `ADV_wq9e_spotcheck_ui_erase.md` | Family hazards: false-noreturn delete; epilogue size--/`*out`/ret 8 |

### Evidence cross-check matrix

| Check | Result |
|---|---|
| Raw 2026-07-23 decompile ≡ dual A CF tables | **Yes** (all four) |
| Dual re-verify 2026-08-04: live ≡ raw CF + bytes epilogue | Stated **identical** with entry/exit hex / isnil immediates |
| Clean named path owns claimed VA (no collision) | **Yes** (headers match each VA / size) |
| Body-size arithmetic | **Yes** (see unit sections) |
| isnil family discriminators non-merge | **Yes** (+0x29 / +0x1d / +0x15) |
| Free/erase callee pairs distinct across families | **Yes** |
| Peer range cleans wire these callees correctly | **Yes** |
| Terminal false honesty | **Yes** (all duals + this ADV) |

---

## Unit A — `0x004cbaa0` StdTree_EraseRange_Isnil29_Inferred (WQ9F-C)

### Body / ABI / CF seal (independent)

```text
0x004cbb54 − 0x004cbaa0 = 0xB4 = 180 B exclusive
```

| Claim | Independent result |
|---|---|
| Body `0x004cbaa0`–`0x004cbb54` exclusive (**180 B**); pad `CC` | **Confirmed** — size math + dual re-verify end |
| **`__thiscall`** ECX=map shell; stack `outIt`, `first`, `last`; **RET 0x0C** both exits | **Confirmed** — raw void thiscall + dual epilogue hex `C2 0C 00` (`5F 5E 89 10 5B C2 0C 00` full; partial `…89 30…C2 0C 00`) |
| Full clear: `first == head->left && last == head` → `FUN_004cb550(root)`; head L/P/R reset; size=0; `*outIt=begin` | **Confirmed** — raw decompile lines 33–40 |
| Partial: while first≠last: successor isnil@+0x29; `FUN_004cb740` single erase; first=succ; `*outIt=first` | **Confirmed** — raw while + `FUN_004cb740(&param_3,piVar3)` |
| isnil@**+0x29** successor walk | **Confirmed** — raw `*(char*)(…+0x29)` |
| Free/erase pair: free `004cb550` / erase `004cb740` — **not** Map_EraseRange pair | **Confirmed** — raw callees; dual B falsifies merge with `0051c7c0`/`0051d880` |
| 6 UNCONDITIONAL_CALL xrefs (multi-caller worker) | **High** — dual sealed; not contested by raw CF |
| Product demangle / free-subtree full algebra of `004cb550` | **Open** — dual residual fair; `_Inferred` correct |
| Runtime / bit-exact | **Open** — Terminal false |

### Live decompile (raw plate summary)

```c
void __thiscall FUN_004cbaa0(int map, undefined4 *outIt, int *first, int *last)
{
  int *head = *(int **)(map + 4);
  if (first == (int *)*head && last == head) {
    FUN_004cb550(head[1]);           // free root (parent)
    // reset head L/P/R to head; size=0; *outIt = begin
    return;                          // ret 0xc
  }
  while (first != last) {
    // successor walk uses isnil @ +0x29
    FUN_004cb740(&first, first);     // ECX = map (bytes)
    first = succ;
  }
  *outIt = first;
  return;                            // ret 0xc
}
```

Clean `StdTree_EraseRange_Isnil29_Inferred.cpp` matches this CF with named successor helper and explicit map ECX on erase.

### Adversarial attacks (range isnil29)

| # | Attack | Result |
|---|---|---|
| 1 | Same binary as `Map_EraseRange` `0x0051c7c0` | **Fails** — free `004cb550` vs `0051bbc0`; erase `004cb740` vs `Map_EraseNode` |
| 2 | Same as `Map_EraseRange_B` | **Fails** — free `0051be90` on B |
| 3 | isnil@+0x15 / +0x1d family | **Fails** — successor immediates **+0x29** |
| 4 | Single-node only (no range) | **Fails** — full-clear + loop |
| 5 | RET 8 (single-erase ABI) | **Fails** — both exits **ret 0x0C** |
| 6 | Erase without map ECX | **Fails** — dual bytes `MOV ECX,EDI` before `CALL 004cb740` |
| 7 | Product/PDB English sealed | **Fails** — `_Inferred` required |
| 8 | Runtime Confirmed | **Fails** |

### Soft niggles

1. Free-subtree `FUN_004cb550` algebra residual (family-wide decomp left-walk hazard) — correctly open.
2. Clean inlines successor rather than naming a shared successor VA — equivalent CF; fine for range plate.

### Unit A dual quality

**PASS** — keep **`accept-with-gaps`**.

---

## Unit B — `0x0051c880` Map_EraseNode_Isnil1d_Inferred (WQ9F-F)

### Body / ABI / CF seal (independent)

```text
0x0051cb36 − 0x0051c880 = 0x2B6 = 694 B exclusive
```

| Claim | Independent result |
|---|---|
| Body exclusive end `0x0051cb36` (**694 B**); next `Map_EraseNode` @ `0x0051cb40`; `CC` pad | **Confirmed** — dual re-verify; Ghidra end `0x0051cb06` incomplete (false noreturn) correctly superseded |
| **`__thiscall`** ECX=map; stack `(pOutIt, pNode)`; **`ret 8`** (`C2 08 00` @ `0x0051cb33`) | **Confirmed** — dual epilogue + signature form |
| isnil@**+0x1d** → `"invalid map/set<T> iterator"` | **Confirmed** — raw `*(char*)(param_3+0x1d)` + throw string |
| color@**+0x1c** (black fixup) | **Confirmed** — raw `(char)param_3[7]` / `+0x1c` immediates on children |
| Successor `FUN_0051b690`; min `0051b670`; max `00421b90`; rotates `00420130`/`00420180` | **Confirmed** — raw callees |
| `operator_delete` falls through → size-- if >0 → `*pOutIt=succ` | **High** — dual bytes seal; raw plate ends at delete with false-noreturn (family hazard) |
| Sole static caller `Map_EraseRange_Isnil1d_Inferred` (`0x0051d700`) | **High** — dual xrefs; peer range clean calls `FUN_0051c880` |
| Distinct from isnil@+0x29 `Map_EraseNode` / `_B` | **Confirmed** — different isnil/color + rotate VAs |
| Product English / full RB line-proof | **Open** — dual residual fair |
| Runtime / bit-exact | **Open** |

### Color / isnil math (independent)

| Field | Offset evidence |
|---|---|
| isnil | raw `param_3 + 0x1d` |
| color | raw `param_3[7]` as `int*` → `7*4 = 0x1c`; child color `+0x1c` in fixup |

### Adversarial attacks (erase isnil1d)

| # | Attack | Result |
|---|---|---|
| 1 | Function ends at `operator_delete` (decomp complete) | **Fails** — epilogue size-- / `*out` / `ret 8` (bytes) |
| 2 | isnil@+0x29 like `Map_EraseNode` | **Fails** — gate **+0x1d** |
| 3 | Same VA / merge with `Map_EraseNode` @ `0x0051cb40` | **Fails** — adjacent but distinct; different layout |
| 4 | Identity with range erase `0051d700` | **Fails** — single-node callee |
| 5 | isnil15 callees (`00673070` / `004e22d0`…) | **Fails** — uses `0051b690` / `00420130` family |
| 6 | No size field update | **Fails** — post-delete `map+8` size-- |
| 7 | Product name sealed without `_Inferred` | **Fails** — dual correctly `_Inferred` |
| 8 | Runtime Confirmed | **Fails** |

### Soft niggles

1. **Clean is surface-level:** `Map_EraseNode_Isnil1d_Inferred.cpp` seals ABI/gate/epilogue and stubs full unlink/RB with `(void)map` + comment “full case tree in raw.” Same honesty pattern as prior isnil29 erase ADV. Raw remains authoritative for tight RB edges — **not** a sealed-claim failure (dual already gaps full rotation algebra).
2. Ghidra “unreachable” two-child blocks in raw header — dual correctly treats as live (family pattern).

### Unit B dual quality

**PASS** — keep **`accept-with-gaps`**.

---

## Unit C — `0x0051be50` Map_FreeSubtree_Isnil15 (WQ9F-F)

### Body / ABI / CF seal (independent)

```text
0x0051be85 − 0x0051be50 = 0x35 = 53 B exclusive
```

| Claim | Independent result |
|---|---|
| Body 53 B; **`ret 4`** (`C2 04 00`); `CC` pad | **Confirmed** — dual re-verify + size math |
| Stack `node*`; ECX threaded unused | **Confirmed** — dual ABI notes; free has no map this |
| isnil@**+0x15** early-out | **Confirmed** — raw `*(char*)(param_1+0x15)` |
| Byte-correct algebra: free right@+8; left=`*node`; delete; node=left until isnil | **Confirmed** — annotated/clean restore left walk decomp dropped |
| Decompiler plate incomplete (false-noreturn on delete) | **Confirmed** — raw only shows right recurse + delete |
| Sole external caller `Map_EraseRange_Isnil15` full-clear (`head->parent`) | **High** — dual xrefs; peer range clean `FUN_0051be50(head->parent)` |
| Twin CF `StdMap_FreeSubtree_Isnil15_Inferred` @ `0x004ba770` — do not alias | **Confirmed** — different VA/callers (dual B) |
| Distinct from isnil29 free `0051bbc0` / `0051be90` and isnil1d free `0051be10` | **Confirmed** — isnil immediate + callers |
| Value dtor / map type English | **Open** — delete-only surface |
| Runtime / bit-exact | **Open** |

### Live decompile vs byte-correct clean

```c
// Decomp plate (incomplete):
void FUN_0051be50(void *node) {
  if (*(char *)((int)node + 0x15) == '\0') {
    FUN_0051be50(*(void **)((int)node + 8));
    operator_delete(node); // false noreturn — drops left walk
  }
}

// Clean / annotated (byte-correct):
// free(right); left=*node; delete(node); node=left; until isnil@+0x15
```

### Adversarial attacks (free isnil15)

| # | Attack | Result |
|---|---|---|
| 1 | Only frees right child (trust decomp) | **Fails** — bytes restore left-walk loop |
| 2 | Same as isnil1d free `0051be10` | **Fails** — isnil **+0x15** vs **+0x1d** |
| 3 | Same symbol as `004ba770` | **Fails** — different VA / skill-neighborhood callers |
| 4 | This is erase-range / erase-node | **Fails** — no map this; node* + delete only |
| 5 | isnil@+0x29 free clone | **Fails** — offset **+0x15** |
| 6 | Dead / unused | **Fails** — Map_EraseRange_Isnil15 full clear |
| 7 | RET 8 / thiscall map | **Fails** — **ret 4** stack node* |
| 8 | Runtime Confirmed | **Fails** |

### Soft niggles

1. Why a second isnil15 free clone exists vs `004ba770` — residual (compilation unit / map type); not CF error.
2. Clean does not name left/right struct fields beyond pointer arithmetic — matches dual structural plate style.

### Unit C dual quality

**PASS** — keep **`accept-with-gaps`**.

---

## Unit D — `0x0051ce00` Map_EraseNode_Isnil15 (WQ9F-G)

### Body / ABI / CF seal (independent)

```text
0x0051d0b5 − 0x0051ce00 + 1 = 0x2B6 = 694 B inclusive
exclusive end 0x0051d0b6
```

| Claim | Independent result |
|---|---|
| Body **694 B** same size class as isnil1d erase; pad `CC` | **Confirmed** — size math + dual re-verify |
| **`__thiscall`** ECX=map; stack `(outIt, node)`; **RET 8** | **Confirmed** — dual + annotated; family epilogue pattern |
| isnil@**+0x15** → `"invalid map/set<T> iterator"` @ `0x00a152f0` | **Confirmed** — raw `param_3 + 0x15` + same throw string as isnil1d |
| color@**+0x14** | **Confirmed** — raw `(char)param_3[5]` → `5*4=0x14`; child `+0x14` |
| Successor `FUN_00673070`; Min `004e12a0`; Max `00421b70`; Lrot `004e22d0`; Rrot `006753b0` | **Confirmed** — raw callees (distinct from isnil1d set) |
| Post-delete size-- / `*outIt` / ret 8 after false-noreturn delete | **High** — dual bytes seal |
| Two-child transplant live (decomp “unreachable” @ `0x0051cf20+`) | **High** — dual/disasm notes; same hazard class as isnil1d raw header |
| Callers (3): `Map_EraseRange_Isnil15`, `FUN_0051d940`, `FUN_0052c930` | **High** — dual xrefs; peer range clean wires `FUN_0051ce00` |
| Distinct from `Map_EraseNode_IntKey` `0x005d1df0` (also isnil15) | **Confirmed** — different VA/callees (dual B) |
| Distinct from isnil@+0x29 `Map_EraseNode` / `_B` | **Confirmed** |
| Product English / nested min-max-rot duals | **Open** |
| Runtime / bit-exact | **Open** |

### Family contrast (independent)

| Family | isnil | color | Erase VA | Example rotates |
|---|---|---|---|---|
| isnil29 | +0x29 | +0x28 | `Map_EraseNode` / `_B` / `004cb740` | isnil29 rotates |
| isnil1d | +0x1d | +0x1c | **`0051c880`** | `00420130` / `00420180` |
| isnil15 | +0x15 | +0x14 | **`0051ce00`** | `004e22d0` / `006753b0` |

### Adversarial attacks (erase isnil15)

| # | Attack | Result |
|---|---|---|
| 1 | Decomp complete at delete | **Fails** — size-- / outIt / ret 8 fall-through |
| 2 | isnil@+0x29 layout | **Fails** — **+0x15 / +0x14** |
| 3 | Merge with `Map_EraseNode` / `_B` | **Fails** — wrong family |
| 4 | Identity with `Map_EraseNode_IntKey` | **Fails** — different VA + callees |
| 5 | Identity with isnil1d erase `0051c880` | **Fails** — different isnil + callees |
| 6 | Skill-domain exclusive product erase | **Fails** — multi-caller STL helper + throw string |
| 7 | RET 4 (free-subtree ABI) | **Fails** — **ret 8** |
| 8 | “Unreachable” two-child blocks dead | **Fails** — dual treats as live image code |
| 9 | Product demangle sealed | **Fails** as product claim — structural name OK |
| 10 | Runtime Confirmed | **Fails** |

### Soft niggles

1. Clean surface stubs RB like unit B; throw path uses `return` placeholder — honesty OK; raw authoritative for full cases.
2. Name lacks `_Inferred` while isnil1d has it — dual intentional (pairs dualed `Map_EraseRange_Isnil15` / family of `Map_EraseNode`); product English still open. Acceptable structural naming.
3. Twin `FUN_0051ce00.cpp` `#include`s named clean (ODR hazard if both TUs compiled) — scaffold hygiene only; not CF.

### Unit D dual quality

**PASS** — keep **`accept-with-gaps`**.

---

## Cross-unit dual report quality

| Check | WQ9F-C (`004cbaa0`) | WQ9F-F (`0051c880` + `0051be50`) | WQ9F-G (`0051ce00`) |
|---|---|---|---|
| Dual report verdicts match A/B | **Yes** — accept-with-gaps | **Yes** — both accept-with-gaps | **Yes** — accept-with-gaps |
| Terminal false honesty | **Yes** | **Yes** | **Yes** |
| OWN scope discipline | **Yes** (with scrub sibling) | **Yes** | **Yes** (with tidy sibling) |
| Tool discipline (no `disassemble_bytes`) | **Yes** | **Yes** | **Yes** (uses `disassemble_function` for two-child — allowed; not `disassemble_bytes`) |
| Decompiler artifact honesty | RET 0x0C + free residual | false noreturn delete; free left-walk | false noreturn + “unreachable” two-child |
| Clean owns correct VA | **Yes** full range CF | **Yes** (erase surface; free full) | **Yes** (surface) |
| Peer non-merge hygiene | ≠ Map_EraseRange* | ≠ Map_EraseNode / free twins | ≠ IntKey / isnil29 / isnil1d |
| AutoCore port notes | Accurate free/erase pair | Accurate isnil1d / free isnil15 | Accurate isnil15 erase + RET 8 |

### Independent overall verdict

| Unit | Dual verdict | ADV verdict |
|---|---|---|
| `aa_004cbaa0` StdTree_EraseRange_Isnil29_Inferred | accept-with-gaps | **PASS — keep accept-with-gaps** |
| `aa_0051c880` Map_EraseNode_Isnil1d_Inferred | accept-with-gaps | **PASS — keep accept-with-gaps** |
| `aa_0051be50` Map_FreeSubtree_Isnil15 | accept-with-gaps | **PASS — keep accept-with-gaps** |
| `aa_0051ce00` Map_EraseNode_Isnil15 | accept-with-gaps | **PASS — keep accept-with-gaps** |

### Spot-check rollup

**Overall WQ9F map-erase ADV: PASS.**

- All four duals hold under independent adversarial review.
- Sealed claims (ABI, isnil/color families, free/erase pairing, false-noreturn epilogues, peer non-merge) match raw + dual re-verify + peer range cleans.
- Clean plates bind to the correct VAs (no WQ9E-style shared-name collision).
- Residual gaps (product English, free-subtree residual for `004cb550`, full RB case algebra on erase cleans, runtime) are correctly owned; Terminal remains **false**.

**Soft niggles only** (do not demote duals):

1. Single-node erase cleans (`0051c880`, `0051ce00`) are intentional surface contracts — port must prefer raw for full RB edge cases.
2. Free-subtree left-walk always requires bytes over decomp in this family.

**No dual rewrite performed by this ADV** (per charter). No parent ledger edits.

---

## Process

- Independent ADV verifier; **not** WQ9F-C / WQ9F-F / WQ9F-G dual author.
- Evidence: dual reports, A/B, raw/annotated/clean/function records; peer dualed range cleans; body-size and layout arithmetic.
- **No** `disassemble_bytes`. **No** parent ledger edits. **No** dual file edits. **No** Launcher.
- Output: `docs/reconstruction/reviews/ADV_wq9f_spotcheck_map_erase.md` (this file).

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
