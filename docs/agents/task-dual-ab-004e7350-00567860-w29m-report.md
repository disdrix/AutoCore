# Dual A/B report — W29-M OWN-ONLY (`0x004e7350`, `0x00567860`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W29-M  
**Scope:** OWN ONLY VAs `0x004e7350`, `0x00567860`. Dual A/B + artifacts.  
**Partition:** wave29 (W29-M). Related: W28-P `004e5120`; W27-R `00567450`.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / xrefs / callers / callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_004e7350` StdMap_Dtor_Val12 | **accept-with-gaps** — Val12 map dtor; erase-range + free head + null; **`C3`**; Ghidra end stale; decomp false-noreturn residual |
| `aa_00567860` StdMap_InsertAlways_Val12_IntKey | **accept-with-gaps** — signed int always-insert; **`ret 8`**; always `inserted=1`; **not** insert-or-find; sole insert via `00567450` |

---

## `aa_004e7350` — StdMap_Dtor_Val12

### Sealed facts

1. **Body:** `0x004e7350`–`0x004e737e` exclusive (**46** B / `0x2E`). Final **`C3`** (`ret`); pad `CC`. Ghidra listed end `0x004e736f` **stale**.

2. **ABI:** `__thiscall`; ECX=map (`head@+4`, `size@+8`); no stack args; clean **0** B.

3. **Algorithm:**
   ```
   EraseRange(map, &tmp, *head /*begin*/, head /*end*/)  // FUN_004e5120
   operator_delete(head)
   head = 0; size = 0
   ```

4. **Callees:** `FUN_004e5120` (StdMap_EraseRange_Val12, W28-P); `operator_delete`.

5. **Callers (1 / 2 xrefs):** `FUN_004d64d0` @ `0x004d6970`, `0x004d697b` (two map shells in large object dtor).

6. **Node family:** Val12 via erase-range (isnil@+0x19). Peer isnil@+0x15 erase — **do not merge**.

7. **Name:** structural `StdMap_Dtor_Val12`. Legacy VOG_DEBUG seed is **narrow**.

### Gaps

1. Product/MSVC demangle for the two map instantiations.  
2. Runtime OOM / empty-tree edge via erase-range (owned by W28-P).  
3. Bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_004e7350_StdMap_Dtor_Val12.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_004e7350_StdMap_Dtor_Val12.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004e7350_StdMap_Dtor_Val12.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004e7350_StdMap_Dtor_Val12.md` |
| Function record | `docs/reconstruction/functions/aa_004e7350_StdMap_Dtor_Val12.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_004e7350_FUN_004e7350.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_Dtor_Val12.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004e7350.cpp` |
| Raw | `docs/reconstruction/raw/aa_004e7350_FUN_004e7350.md` |
| Annotated | `docs/reconstruction/raw/aa_004e7350_FUN_004e7350.annotated.md` |

---

## `aa_00567860` — StdMap_InsertAlways_Val12_IntKey

### Sealed facts

1. **Body:** `0x00567860`–`0x005678c0` exclusive (**96** B / `0x60`). Epilogue **`C2 08 00`** (`ret 8`); pad `CC`.

2. **ABI:** `__thiscall` ECX=map; stack `(outPair*, value*)`; clean **8** B.

3. **Algorithm:**
   ```
   walk tree by signed int key (value[0] vs node+0x0c); isnil@+0x19
   equal keys go right
   ALWAYS InsertAndRebalance (FUN_00567450) → out{it, inserted=1}
   ```

4. **Callees:** `FUN_00567450` (Map_TreeInsertAndRebalance_Val12, W27-R → buynode `005ae220`).

5. **Callers (1 / 2 xrefs):** `FUN_00565950` @ `0x0056641a`, `0x00566452`.

6. **Node:** Val12 / 0x1c — key@+0x0c, color@+0x18, isnil@+0x19.

7. **Name:** structural `StdMap_InsertAlways_Val12_IntKey`. Prior notes calling this insert-or-find are **wrong** — **do not merge** with `0053a1a0` / `00573810`.

### Gaps

1. Product English / demangle for map type.  
2. Whether callers ever insert duplicate keys (multimap-like).  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00567860_StdMap_InsertAlways_Val12_IntKey.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00567860_StdMap_InsertAlways_Val12_IntKey.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00567860_StdMap_InsertAlways_Val12_IntKey.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00567860_StdMap_InsertAlways_Val12_IntKey.md` |
| Function record | `docs/reconstruction/functions/aa_00567860_StdMap_InsertAlways_Val12_IntKey.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_00567860_FUN_00567860.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_InsertAlways_Val12_IntKey.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00567860.cpp` |
| Raw | `docs/reconstruction/raw/aa_00567860_FUN_00567860.md` |
| Annotated | `docs/reconstruction/raw/aa_00567860_FUN_00567860.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### StdMap_Dtor_Val12 (`0x004e7350`)

- Port as **full Val12 map destructor**: erase-range then free header, not “clear size only.”
- Preserve post-`operator_delete` **null head + size** (decomp omits them).
- Chain erase through **`FUN_004e5120`** (isnil@+0x19), not isnil@+0x15 twin.
- Two instances in parent object dtor — generic map shell, not product-named.

### StdMap_InsertAlways_Val12_IntKey (`0x00567860`)

- Port as **always-insert**, **not** insert-or-find / insert-or-assign.
- Out pair always `{node, true}`; **`ret 8`**.
- Key compare is **signed int** at value dword0 / node +0x0c.
- Insert path is **`FUN_00567450`** → stack buy `005ae220` — not ESI buy `0046c6c0`.
- Do **not** substitute `0053a1a0` (int insert-or-find) or `00573810` (uint insert-or-find).

---

## Notes

- No Launcher. No parent ledger / partition map / COVERAGE_LEDGER edits.
- Did not write dual artifacts for non-owned helpers (`004e5120` dualed W28-P; `00567450` dualed W27-R; `005ae220` dualed W24-I; callers out of ownership).
- Scaffold raw bodies preserved; W29-M re-verify **appended** only.
- Corrected W27-R claim that uniqueness lives in `00567860` — it does **not**.
