# Dual A/B report — W24-S OWN `aa_0074ee40` + `aa_0040b020`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W24-S  
**Scope:** VAs `0x0074ee40`, `0x0040b020` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` (disasm off) + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0074ee40` AnimSlot_BindResourceFromPath | **accept-with-gaps** — bind CF + ABI ret4 + +0x70/+0x74 + fail=-1 sealed; nested helpers / product English residual |
| `aa_0040b020` ThreadSafeObjectList_PopFront | **accept** — pop-front CF + dual CS + node 0xC layout + Interlocked count sealed |

---

## VA `0x0074ee40` — sealed facts

1. **Body:** `0x0074ee40`–`0x0074eea9` (105 B exclusive end; `RET 4` both paths).
2. **ABI:** **ECX**=AnimSlot* (0x78); stack `pathKey`; return `0`/`1` or `0xFFFFFFFF`.
3. **Semantics:** ND cache lookup → store resource **`+0x70`** → vtbl+4 ready → acquire inner **`+0x74`** → channel extract → weight init → return ready bool.
4. **Globals:** cache root `DAT_00d1f050`; type singleton via `FUN_00449070` → `&DAT_00d1f7cc`.
5. **Fail domain:** any null/extract-fail → **`-1`**; parent loaders use **`result >= 0`**.
6. **Callers (9 named):** includes `Object_LoadOrReplaceAnimSlot` (`0x005828b0`, W18-C), `FUN_00581e20`, `FUN_005866d0`, …
7. **Name:** `AnimSlot_BindResourceFromPath` (Ghidra `FUN_0074ee40`; **Inferred**).
8. **Decompile ≡ 2026-07-23 raw ≡ bytes** for CF.

### Gaps

- Product English for ND resource / multi-host (anim vs graphics child) typing.  
- Nested helper duals (`00449070`, cache, acquire, `00963950`, `0074eaa0`).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0074ee40_AnimSlot_BindResourceFromPath.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0074ee40_AnimSlot_BindResourceFromPath.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0074ee40_FUN_0074ee40.md` |
| Annotated | `docs/reconstruction/raw/aa_0074ee40_FUN_0074ee40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AnimSlot_BindResourceFromPath.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0074ee40.cpp` |
| Function | `docs/reconstruction/functions/aa_0074ee40_FUN_0074ee40.md` |
| Function named | `docs/reconstruction/functions/aa_0074ee40_AnimSlot_BindResourceFromPath.md` |
| Scratch | `docs/reconstruction/tmp/a_0074ee40.md` |

---

## VA `0x0040b020` — sealed facts

1. **Body:** `0x0040b020`–`0x0040b136` (278 B; SEH; `RET`).
2. **ABI:** **ECX**=list*; no stack formals; return payload* or 0.
3. **Semantics:** Thread-safe **pop front** — dual CS, destroy node, return payload, InterlockedDecrement count.
4. **List layout:** head`+4`, tail`+8`, count`+0xC`, CS inner`+0x10`, CS outer`+0x28`.
5. **Node layout:** vtbl`+0`, payload`+4`, next`+8` (size **0xC** from push twin).
6. **Inner CS:** only when **`count < 2`**.
7. **Twins:** push `FUN_004024d0`; dtor drain `FUN_004bcbf0`.
8. **Callers (7+):** `FUN_0058c850` (skill multi-target iterate), `FUN_004bcbf0`, mission/combat sites; 22 xrefs.
9. **Name:** `ThreadSafeObjectList_PopFront` (Ghidra `FUN_0040b020`; **Inferred**).
10. **Decompile ≡ 2026-07-23 raw ≡ bytes** for CF.

### Gaps

- Product/PDB symbol (Inferred name only).  
- Nested-CS threshold English vs push’s outer `count < 4` policy.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040b020_ThreadSafeObjectList_PopFront.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0040b020_ThreadSafeObjectList_PopFront.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0040b020_FUN_0040b020.md` |
| Annotated | `docs/reconstruction/raw/aa_0040b020_FUN_0040b020.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ThreadSafeObjectList_PopFront.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040b020.cpp` |
| Function | `docs/reconstruction/functions/aa_0040b020_FUN_0040b020.md` |
| Function named | `docs/reconstruction/functions/aa_0040b020_ThreadSafeObjectList_PopFront.md` |
| Scratch | `docs/reconstruction/tmp/a_0040b020.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0074ee40` | Anim/ND slot bind — preserve fail=`-1`, success 0/1 ready flag, stores at +0x70/+0x74, and parent `>= 0` gate; do not skip channel extract / weight init order. |
| `0040b020` | Thread-safe object list pop — preserve dual CS (+0x28 always, +0x10 when count&lt;2), Interlocked count, node dtor flag 1, empty→null without lock; pair with push `004024d0` / dtor `004bcbf0`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete (no disasm dump) + read_memory.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- This report: `docs/agents/task-dual-ab-0074ee40-0040b020-w24s-report.md`

Absolute roots: `C:\Users\josh\Documents\GitHub\AutoCore\` + paths above.
