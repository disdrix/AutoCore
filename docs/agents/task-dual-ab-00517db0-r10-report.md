# Dual A/B report — R10-032 OWN-ONLY (`0x00517db0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-032**  
**Scope:** VA `0x00517db0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (incl. parent BuyNode `0x00418700`, sibling PushBack `0x00402d10`, Incsize `0x00404840`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R10 residual dual — undualed callee of dualed HP manager `0x00418700` (BuyNode); partition missions-progression (shared STL leaf).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00517db0` StdList_PushBack_DwordFromEcx_Inferred | **accept-with-gaps** — CF/ABI/RET4/push_back/BuyNode+Incsize/ECX-value sealed; product `T` + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mission-only / vector / front / uninit-local / ECX=list-merge / bare-RET claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00517db0` — sealed facts

1. **Body:** `0x00517db0`–`0x00517de9` inclusive (**58 B** / `0x3A`); pad `CC` from `0x00517dea`. Last insn `RET 4` (`C2 04 00`).
2. **ABI (bytes win over Ghidra `void` / uninit local):**  
   - **ECX** = dword **value** to store at `node+8` (typically caller's adjusted `this`).  
   - **Stack arg0** = `list*` (`_Myhead` @ +4, `_Mysize` @ +8).  
   - void; **`RET 4`**.  
   - **Not** thiscall-with-list-in-ECX (that is `0x00402d10`).
3. **Semantics:** MSVC-shaped **`std::list` push_back**:
   - `head = list->_Myhead`
   - Spill ECX → `node = FUN_00418700(head, head->_Prev, &slot)` (0xC BuyNode)
   - `FUN_00404840(list, 1)` — `_Incsize`; may throw `"list<T> too long"`
   - `head->_Prev = node`; `node->_Prev->_Next = node`
4. **Classification:** worker.
5. **Callees:** `FUN_00418700` (`StdList_BuyNode_Dword_Seh`), `FUN_00404840` (`StdList_Incsize_Thiscall`).
6. **Callers / xrefs:** **5** code parents + **18** DATA vtable-style slots:
   - `FUN_004c30d0` @ `0x004c30e9`
   - `FUN_004f46c0` @ `0x004f46d9`
   - `FUN_00562fa0` @ `0x00562fb9`
   - `FUN_00587680` @ `0x00587699`
   - `FUN_00569ba0` @ `0x00569bb0` (this-adjust + tail **JMP**)
7. **Name:** `StdList_PushBack_DwordFromEcx_Inferred` (Ghidra `FUN_00517db0`; **_Inferred** — product `T` open).
8. **Decompile ≡ raw CF**; ABI sealed via `read_memory` (ECX spill + stack list + RET 4).
9. **Hex seal (body through RET 4):**

```text
51538b5c240c568b730457894c240c8b4e048d44240c5051568bcbe83009f0ff6a018bcb8bf8e865caeeff897e048b5704893a5f5e5b59c20400
```

10. **Twins / siblings (not owned this dual):**
    - `StdList_PushBack_Dword_Inferred` `0x00402d10` — ECX=list, stack=`const T*`
    - `StdList_PushFront_DwordFromEax_Inferred` `0x004027f0` — EAX=`const T*`, stack=list; front
    - Parent BuyNode `0x00418700` / Incsize `0x00404840` dualed separately

### Gaps

- Product C++ `T` / list typedef English.  
- Full DATA vtable ownership map.  
- Null-`operator_new` path (BuyNode may return 0).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00517db0_StdList_PushBack_DwordFromEcx_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00517db0_StdList_PushBack_DwordFromEcx_Inferred.md` | **accept-with-gaps** |

---

## Artifacts written / refreshed

| Kind | Path |
|------|------|
| Raw (+ R10-032 append) | `docs/reconstruction/raw/aa_00517db0_FUN_00517db0.md` |
| Annotated | `docs/reconstruction/raw/aa_00517db0_FUN_00517db0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/StdList_PushBack_DwordFromEcx_Inferred.cpp` |
| Clean FUN alias | `docs/reconstruction/reconstructed-exact/FUN_00517db0.cpp` |
| Function record FUN | `docs/reconstruction/functions/aa_00517db0_FUN_00517db0.md` |
| Function record named | `docs/reconstruction/functions/aa_00517db0_StdList_PushBack_DwordFromEcx_Inferred.md` |
| Review A | `docs/reconstruction/reviews/A_aa_00517db0_StdList_PushBack_DwordFromEcx_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00517db0_StdList_PushBack_DwordFromEcx_Inferred.md` |
| This report | `docs/agents/task-dual-ab-00517db0-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00517db0` | Port as **std::list push_back** with **ECX = value dword**, **stack = list***, **RET 4**. Typical use: virtual `Register(list*)` that does `list.push_back(this)`. Do **not** merge ABI with `0x00402d10` (list in ECX). Preserve BuyNode + Incsize throw path. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x00418700` | `StdList_BuyNode_Dword_Seh` |
| `0x00404840` | `StdList_Incsize_Thiscall` |
| `0x00402d10` | `StdList_PushBack_Dword_Inferred` (sibling ABI) |
| `0x004027f0` | `StdList_PushFront_DwordFromEax_Inferred` |

---

## Process

- OWN VA only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- ABI sealed carefully: decompiler uninit local = ECX spill.  
- No invented product plates; `_Inferred` name only.  
- Terminal **false**.
