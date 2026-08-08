# Dual A/B report — R13-024 OWN `aa_004e4e10`

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual R13-024  
**Scope:** VA `0x004e4e10` only. Dual A/B + artifacts (trio + function + A/B).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger / other VAs.  
**Ghidra:** `decompile_function` / `analyze_function_complete` + `read_memory` + callers/xrefs + callee `batch_decompile`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-024**.  
**System:** skills-abilities.  
**Parent dual:** `0x004e3e70` (StdTree_EraseAndRebalance_Isnil21).  
**Dual start:** 2686.  
**Terminal:** **false**.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004e4e10` StdTree_EraseRange_Isnil21_Inferred | **accept-with-gaps** — ABI/CF/isnil/callers/free+erase pair sealed (180 B); product English + free-subtree residual open |

---

## VA `0x004e4e10` — sealed facts

1. **Body:** `0x004e4e10`–`0x004e4ec4` exclusive (**180 B** / `0xB4`); pad `CC`×12 then next @ `0x004e4ed0`.
2. **ABI:** **`__thiscall`** (ECX = map); stack `Node** outIt`, `Node* first`, `Node* last`; both exits **`RET 0x0C`** (`C2 0C 00` @ `0x004e4e57` and `0x004e4ec1`); void return after out-it write.
3. **Role:** MSVC-style **range erase** `[first, last)` for **isnil@+0x21** family:
   - **Full clear** when `first == head->left && last == head`: `FUN_004e2e00(root)`; head L/P/R → head; `size = 0`; `*outIt = begin`
   - **Partial:** while `first != last`: successor (isnil@+0x21), then single erase parent dual `FUN_004e3e70(map, &first, first)`, advance
   - final `*outIt = first`
4. **Layout:** node **0x28**; isnil@**+0x21**; color@**+0x20** (used inside erase only); Val16 @+0x10 (not destroyed here); head@map+4; size@map+8.
5. **Does not:** perform RB rebalance itself; free whole tree without head reset; use Val12 isnil@+0x19 offsets; use twin free `004e2e40`.
6. **Callers (1):** `FUN_004e7320` @ `0x004e7332` — map clear then `operator_delete(head)`.
7. **Callees:** `FUN_004e2e00` (full free), `FUN_004e3e70` (single erase+rebalance isnil21).
8. **Name:** `StdTree_EraseRange_Isnil21_Inferred` (Ghidra `FUN_004e4e10`). **Reject** Named_CalleeOf_VOG_DEBUG_STOP scaffold.
9. **Family:** parent erase dual `StdTree_EraseAndRebalance_Isnil21_Inferred` @ `0x004e3e70`; peer twin range `FUN_004e52a0` (free `004e2e40`); Val12 range `004e5120`; Isnil29 range `004cbaa0` (same 180 B shape, different offsets).
10. **Decompile ≡ raw CF** for full-clear / successor / erase loop; ABI from `read_memory`.  
    Entry hex (64 B): `538b5c2410568b742410578bf98b47043b3075363bd875328b400450e8cfdfffff8b47048940048b4704c747080000000089008b47048940088b4f048b118b44`  
    Epilogue tails: `5f5e89105bc20c00` (full) / `8b4424105f89305e5bc20c00` (partial).
11. **Closes** R13-024 residual dual for this VA (static); product demangle + free-subtree residual still open.

### Gaps

- Product / PDB English for owning `map<K,V>` of sole caller `FUN_004e7320`.  
- Complete free-subtree algebra of `FUN_004e2e00` (left-recurse residual; false-noreturn).  
- Twin free path `004e52a0`/`004e2e40` difference (value dtor vs POD).  
- Runtime / differential / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004e4e10_StdTree_EraseRange_Isnil21_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004e4e10_StdTree_EraseRange_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ R13-024 append) | `docs/reconstruction/raw/aa_004e4e10_FUN_004e4e10.md` |
| Annotated | `docs/reconstruction/raw/aa_004e4e10_FUN_004e4e10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseRange_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004e4e10.cpp` |
| Function | `docs/reconstruction/functions/aa_004e4e10_FUN_004e4e10.md` |
| Function named | `docs/reconstruction/functions/aa_004e4e10_StdTree_EraseRange_Isnil21_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004e4e10` | Port as **range erase** for **isnil@+0x21** maps: full clear free via **`004e2e00`** + head reset + size0; partial loop successor then parent dual single erase **`004e3e70`**; write `*outIt`; **RET 0x0C**. **Do not** use Val12 offsets (+0x18/+0x19) or Val12 erase `004e4130`. **Do not** merge with twin free `004e2e40` (`004e52a0`). **Do not** treat as single-node erase (that is parent `004e3e70`). Pair with erase dual `004e3e70` for same layout. |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x004e3e70` | single-node erase+rebalance isnil21 — **parent dual** (partition) |
| `0x004e2e00` | full free-subtree isnil21 (residual algebra) |
| `0x004e7320` | sole caller — map clear + delete head |
| `0x004e52a0` | peer range twin (erase same; free `004e2e40`) |
| `0x004e5120` | Val12 range erase (different family) |
| `0x004cbaa0` | Isnil29 range erase (same 180 B shape) |
| `0x004e12c0` | nextnode / successor isnil21 (used inside erase, not this shell) |

---

## Process

- OWN VA only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + callee decompile. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Inferred name with `_Inferred` suffix; never Runtime Confirmed.  
- Rejected Named_CalleeOf_* scaffold as product identity.  
- Trio evidence: raw + annotated + clean (named) + function records.
