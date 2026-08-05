# Dual A/B report — W30-L OWN-ONLY (`0x005e15a0`, `0x005e18d0`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W30-L  
**Scope:** OWN ONLY VAs `0x005e15a0`, `0x005e18d0`. Dual A/B + artifacts.  
**Partition:** wave30  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / xrefs / callers / callees / complete analysis). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_005e15a0` StdTree_EraseAndRebalance_Val12 | **accept-with-gaps** — Val12 erase CF/ABI/`ret 8`/size--/isnil throw sealed; product demangle open |
| `aa_005e18d0` StdMap_InsertOrFindByIntKey_Val12 | **accept-with-gaps** — signed int-key insert-or-find CF/ABI/`ret 8`/out-pair sealed; product demangle open |

---

## `aa_005e15a0` — StdTree_EraseAndRebalance_Val12

### Sealed facts

1. **Body (true):** `0x005e15a0`–`0x005e1856` exclusive (**694** B / `0x2B6`). Final **`C2 08 00`** (`ret 8`); pad `CC`. Ghidra lists end `0x005e1826` (**false** — `operator_delete` noreturn truncate).

2. **ABI:** **`__thiscall`**; ECX = map (`head` @ `+4`, `size` @ `+8`); stack `(outIt*, node*)`; void; **`ret 8`**.

3. **Algorithm (bytes authority on epilogue):**
   ```
   if node->isnil: throw "invalid map/set<T> iterator"
   FUN_005ae0b0()                     // successor prep
   splice replacement; fix root / leftmost / rightmost
   if erased black: RB fixup (Lrotate 00573170 / Rrotate 00418c10)
   operator_delete(node)
   if size>0: size--                  // decomp miss
   *outIt = successor; ret 8
   ```

4. **Throw:** `"invalid map/set<T> iterator"` @ `0x00a152f0` / `DAT_00acc34c`.

5. **Node:** Val12 / 0x1c — left@0 parent@4 right@8 value@0x0c **color@0x18 isnil@0x19**.

6. **Callees:** `FUN_005ae0b0`, `FUN_005adfa0` (min), `FUN_00418bf0` (max), `FUN_00573170`, `FUN_00418c10`, `operator_delete`, throw chain.

7. **Callers (1):** `FUN_005e1990` @ `0x005e1a2f` (range erase wrapper).

8. **Name:** structural `StdTree_EraseAndRebalance_Val12`. Peer family: `004e4130` / `00573250` / `005399f0` / `005ae990` — **do not merge VAs**.

9. **Decompile:** live ≡ raw CF; **epilogue size-- + ret 8 sealed by bytes**.

### Gaps

1. Product/MSVC demangle for map of `FUN_005e1990`.  
2. Ghidra “unreachable” transplant blocks (medium).  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005e15a0_StdTree_EraseAndRebalance_Val12.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005e15a0_StdTree_EraseAndRebalance_Val12.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005e15a0_StdTree_EraseAndRebalance_Val12.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005e15a0_StdTree_EraseAndRebalance_Val12.md` |
| Function record | `docs/reconstruction/functions/aa_005e15a0_StdTree_EraseAndRebalance_Val12.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_005e15a0_FUN_005e15a0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Val12_005e15a0.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005e15a0.cpp` |
| Raw | `docs/reconstruction/raw/aa_005e15a0_FUN_005e15a0.md` |
| Annotated | `docs/reconstruction/raw/aa_005e15a0_FUN_005e15a0.annotated.md` |

---

## `aa_005e18d0` — StdMap_InsertOrFindByIntKey_Val12

### Sealed facts

1. **Body:** `0x005e18d0`–`0x005e1988` exclusive (**184** B / `0xB8`). Exits end **`C2 08 00`** (`ret 8`); pad `CC`.

2. **ABI:** **`__thiscall`** ECX=map; stack `(InsertPair* out, Val12* value)`; void; clean **8** B.

3. **Algorithm:**
   ```
   walk tree by SIGNED int key (value[0] vs node+0x0c); isnil@+0x19
   if goLeft && parent==leftmost: InsertAndRebalance(005e13b0,…,1) → out{it,1}
   else if goLeft: Predecessor(005ae050)
   if parent.key < key: InsertAndRebalance(…,addLeft) → out{it,1}
   else: out{parent,0}  // equal — no value rewrite
   ```

4. **Key compare (bytes):** walk `setl` (`0F 9C`); equal gate `jge` (`7D`) — **signed**, not uint peer `00573810`.

5. **Callees:** `FUN_005e13b0` (always-insert+rebalance; max `0x15555553`; buynode `005ae220`; `ret 0x10`); `FUN_005ae050` (StdTree_Dec_Val12).

6. **Callers (1):** `FUN_005e0610` @ `0x005e06db` (mission/reaction consumer; also `CVOGReaction_FailMissionNotify`).

7. **Node:** Val12 / 0x1c — key@+0x0c, color@+0x18, isnil@+0x19.

8. **Name:** structural `StdMap_InsertOrFindByIntKey_Val12`. Legacy Mission Named_CalleeOf_* is **narrow**. Peer CF: `0x0053a1a0` (W28-P; insert helper `00539210`).

9. **Decompile:** live ≡ raw CF; ret 8 + signed compares sealed by bytes.

### Gaps

1. Product English / demangle for map of `FUN_005e0610`.  
2. Full dual of always-insert `FUN_005e13b0` (not OWN).  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005e18d0_StdMap_InsertOrFindByIntKey_Val12.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005e18d0_StdMap_InsertOrFindByIntKey_Val12.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005e18d0_StdMap_InsertOrFindByIntKey_Val12.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005e18d0_StdMap_InsertOrFindByIntKey_Val12.md` |
| Function record | `docs/reconstruction/functions/aa_005e18d0_StdMap_InsertOrFindByIntKey_Val12.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_005e18d0_FUN_005e18d0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFindByIntKey_Val12_005e18d0.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005e18d0.cpp` |
| Raw | `docs/reconstruction/raw/aa_005e18d0_FUN_005e18d0.md` |
| Annotated | `docs/reconstruction/raw/aa_005e18d0_FUN_005e18d0.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### StdTree_EraseAndRebalance_Val12 (`0x005e15a0`)

- Port as Val12 map/set **single-node erase** with isnil@+0x19, color@+0x18, size--, and Val12 L/R rotate pair — do **not** reuse isnil@+0x15 erase offsets/rotates.
- Preserve **thiscall + ret 8**; Ghidra end is **not** authority — continue past `operator_delete` for size-- / `*outIt`.
- Share algorithm with peer erase clones; keep this VA as its own instantiation (sole consumer `FUN_005e1990`).

### StdMap_InsertOrFindByIntKey_Val12 (`0x005e18d0`)

- Port as **generic Val12 unique insert-or-find**, not mission-specific logic (mission is caller `FUN_005e0610`).
- Preserve **signed** int key compare; do not substitute unsigned inventory peer `00573810`.
- Equal key: **no** value rewrite (`inserted=0` only).
- Always-insert via local helper `FUN_005e13b0` → stack buynode `005ae220` (not ESI twin `0046c6c0`).

### Family context (owned elsewhere)

| Helper | VA | Role |
|--------|-----|------|
| StdTree_Inc_Val12 | `0x005ae0b0` | W28-N — successor |
| StdTree_Dec_Val12 | `0x005ae050` | W29-E — predecessor |
| StdTree_Lrotate_Val12 | `0x00573170` | W26-Q |
| StdTree_Rrotate_Val12 | `0x00418c10` | W26-Q |
| StdTree_Buynode_Val12 | `0x005ae220` | W24-I — via insert helper |
| StdTree_Erase peer | `0x004e4130` / `0x00573250` | W27-Q / W27-S |
| InsertOrFind peer | `0x0053a1a0` | W28-P (int key) |
| FUN_005e13b0 | `0x005e13b0` | always-insert for this map (not OWN) |
| FUN_005e1990 | `0x005e1990` | range erase consumer (not OWN) |

---

## Notes

- Tools used: `decompile_function`, `analyze_function_complete`, `read_memory`, `get_function_by_address`, `get_xrefs_to`, `get_function_callers`, `get_function_callees`. **No** `disassemble_bytes`. **No** Launcher. **No** parent ledger edits.
- Partition ownership: W30-L only for these two VAs.
- Scaffold raw decompile bodies preserved; re-verify **appended** only.
- **Critical:** for erase, bytes supersede decompiler on epilogue (size-- / ret 8 / out-it). For insert-or-find, bytes seal signed key compares and `ret 8`.
