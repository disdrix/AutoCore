# Dual A/B report — R10-006 OWN-ONLY (`0x00404840`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-006**  
**Scope:** VA `0x00404840` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (incl. parent BuyNode `0x00418700`, twin `0x0043fe60`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs/callees + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R10 residual dual — undualed callee of dualed HP manager `0x00418700` (BuyNode); partition missions-progression (shared STL leaf).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00404840` StdList_Incsize_Thiscall | **accept** — CF/ABI/RET4/max/`_Mysize`/string/throw path sealed; product exception English + runtime open |

Path A (fidelity): **accept**.  
Path B (adversarial): fastcall-twin-merge / Max1fffffff-merge / mission-only / node-alloc / soft-fail / bare-RET / vector-string claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00404840` — sealed facts

1. **Body:** `0x00404840`–`0x004048AE` inclusive (**111 B** / `0x6F`); pad `CC` from `0x004048AF`.
2. **ABI:** **ECX** = list*; stack `uint32_t count`; void; **`RET 4`** (`C2 04 00`).
3. **Semantics:** MSVC-shaped **`std::list::_Incsize`**:
   - if `0x3fffffffU - list->_Mysize < count` → throw `"list<T> too long"` @ `0x00a1581c` via `FUN_00401a40` + `_CxxThrowException` / ThrowInfo `DAT_00acc388`
   - else `list->_Mysize += count` at `list+8`
4. **Layout:** `_Mysize` @ list+8 (head typically +4; not touched here).
5. **Callees:** `basic_string` ctor, `FUN_00401a40`, `_CxxThrowException`.
6. **Callers / xrefs:** **32** call sites; sample parents:
   - `FUN_00402d10` StdList_PushBack_Dword @ `0x00402d2f` (`PUSH 1` / `MOV ECX,ESI`)
   - `FUN_004040f0` insert-one @ `0x00404110`
   - `FUN_00517db0` @ `0x00517dd6`
   - `FUN_0052b350` @ `0x0052b376`
   - Plus inventory/character/UI paths (`CVOGReaction_RemoveInventoryItem`, `CVOGCharacter_SerializeCreatePacket`, …)
7. **Name:** `StdList_Incsize_Thiscall` (Ghidra `FUN_00404840`). Retires `Named_CalleeOf_Client_DebugListMissionsStatus_00404840`.
8. **Decompile ≡ raw CF**; ABI sealed via `read_memory` + caller `get_assembly_context`.
9. **Hex seal (body through ret 4):**

```text
64a1000000008b5424046aff6819c99b0050648925000000008b410883ec4456beffffff3f2bf03bf25e7333681c58a1008d4c2404ff15f8629c00c744244c000000008d0424508d4c2420e8b0d1ffff6888c3ac008d4c242051e8c1f4290003c28941088b4c244464890d0000000083c450c20400
```

10. **Twins (not owned this dual):**
    - `StdList_Incsize` `0x0043fe60` — same max **`0x3fffffff`**, **fastcall** ECX=count / EDX=list* / bare `RET` (sealed W23-E **accept**)
    - `StdList_Incsize_Max1fffffff` `0x00416010` — max **`0x1fffffff`**, fastcall (sealed WQ9I-E)

### Gaps

- Product exception type English (ThrowInfo only).  
- Runtime / bit-exact / differential.  
- Parent BuyNode dual residual already sealed separately (`0x00418700`).

---

## Artifacts written / refreshed

| Kind | Path |
|------|------|
| Raw (+ R10-006 append) | `docs/reconstruction/raw/aa_00404840_FUN_00404840.md` |
| Annotated | `docs/reconstruction/raw/aa_00404840_FUN_00404840.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/StdList_Incsize_Thiscall.cpp` |
| Clean FUN alias | `docs/reconstruction/reconstructed-exact/FUN_00404840.cpp` |
| Function record FUN | `docs/reconstruction/functions/aa_00404840_FUN_00404840.md` |
| Function record named | `docs/reconstruction/functions/aa_00404840_StdList_Incsize_Thiscall.md` |
| Review A | `docs/reconstruction/reviews/A_aa_00404840_StdList_Incsize_Thiscall.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00404840_StdList_Incsize_Thiscall.md` |
| This report | `docs/agents/task-dual-ab-00404840-r10-report.md` |

---

## Notes

- No Launcher. No parent ledger / partition map edits.  
- Did not write artifacts for non-owned helpers (`00401a40`, `00418700`, `0043fe60`, `00416010`, …).  
- Partition system label `missions-progression` retained as seed; sealed system = **shared MSVC std::list**.  
- Terminal **false**.
