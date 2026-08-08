# Dual A/B report — R10-028 OWN-ONLY (`0x004bc950`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-028**  
**Scope:** VA `0x004bc950` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (read-only family evidence only).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r10_residual_partition_map.md` → **R10-028**.  
**System:** inventory-transfer / client::list.  
**Parent dual (context only):** `0x005725a0`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004bc950` List_DestroyAll | **accept** — ECX host / CS@+4 / TraversalLock gate / drain head@+0x1c / zero three heads / product DestroyAll plate sealed |

Path A (fidelity): **accept**.  
Path B (adversarial): stdcall / RemoveAll-merge / ObjectCsList-VA-merge / single-head / lock-safe / invent-name claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004bc950` — sealed facts

1. **Body:** `0x004bc950`–`0x004bca4a` inclusive (**251 B** / `0xFB`); terminal **`C3`**.
2. **ABI:** **ECX = list host** (`8B F1`); void; bare **`RET`**. Decompiler `__fastcall` matches.
3. **Semantics:** CS-guarded list **DestroyAll**:
   - SEH frame (`LAB_009a16d0`); `__chkstk` **0x1004**.
   - `EnterCriticalSection(host+4)`.
   - If `host[+0x28] ≠ 0`: LeaveCS; throw **`0x80070005`** (`E_ACCESSDENIED`).
   - Drain `host[+0x1c]`: `head = node[+8]`; scalar-deleting dtor `(*vtbl)(node, 1)` — **no** `node[+4]=0`.
   - Zero `host[+0x24]`, `[+0x20]`, `[+0x1c]`; LeaveCS.
4. **Product plate (SEH path, not main CF):** `"List Error!  DestroyAll Call Stack:\n%s\n"` @ `0x00a33af0` + `VOG_DEBUG_STOP` @ `0x00a15844`.
5. **Callers (4 / 9 sites):** `FUN_004bcab0`×1, `FUN_004bcbc0`×2, `FUN_005737c0`×2, `FUN_00572730`×4.
6. **Callees:** `EnterCriticalSection`, `LeaveCriticalSection`, `_CxxThrowException`, `__chkstk`; indirect node vtbl[0].
7. **Family:** dualed `List_RemoveAll` `0x004bc580` (mid-life clear; zeros `node[+4]`), `List_TraversalLock` `0x004294f0`, `List_IterateNext` `0x004022a0`. CF twin `ObjectCsList_DestroyAll_Inferred` `0x00424060` — **do not merge VAs**.
8. **Name:** `List_DestroyAll` (Ghidra `FUN_004bc950`). Product method plate **High** — no `_Inferred` required.
9. **Decompile ≡ raw CF** (2026-07-23 body unchanged); re-verify append-only (no wipe).

### Gaps

- Product C++ class English for list host / node payload.  
- Exact roles of `+0x20` / `+0x24` beyond co-cleared heads.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004bc950_List_DestroyAll.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004bc950_List_DestroyAll.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004bc950_FUN_004bc950.md` |
| Annotated | `docs/reconstruction/raw/aa_004bc950_FUN_004bc950.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/List_DestroyAll.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004bc950.cpp` |
| Function | `docs/reconstruction/functions/aa_004bc950_FUN_004bc950.md` |
| Function named | `docs/reconstruction/functions/aa_004bc950_List_DestroyAll.md` |
| This report | `docs/agents/task-dual-ab-004bc950-r10-report.md` |

---

## Contrast (family evidence only; not dualled)

```text
List_RemoveAll  (0x004bc580)  [dualed W37-U]
  - product: "List Error!  RemoveAll Call Stack"
  - zeros node[+4] before scalar dtor
  - mid-life clear callers (grid reset, reaction remove)

List_DestroyAll (0x004bc950)  [OWN R10-028]
  - product: "List Error!  DestroyAll Call Stack"
  - no node[+4] clear
  - host dtor / stack-local teardown callers

ObjectCsList_DestroyAll_Inferred (0x00424060)  [dualed WQ9L]
  - CF clone of DestroyAll; separate VA/SEH; do not merge
```

Partition parent `0x005725a0` names the inventory-manager call graph, not this leaf's product role.
