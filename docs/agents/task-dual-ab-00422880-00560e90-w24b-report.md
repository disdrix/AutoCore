# Dual A/B report — W24-B OWN-ONLY (`aa_00422880`, `aa_00560e90`)

**Date:** 2026-07-29  
**Agent:** W24-B OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00422880`, `0x00560e90`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `reviews/WAVE_2026-07-29_wave24_partition_map.md` → W24-B  

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00422880` OleDb_AllocCtxBlock_Inferred | **accept** — 72 B SEH body + tail: `count*8` `new[]`, HRESULT `S_OK`/`E_OUTOFMEMORY`, `ret 8` |
| `aa_00560e90` WorldObj_RebindActivate_Inferred | **accept** — 34 B: unbind→rebind→`*(obj+0x44)+0x28=1`, thiscall+`ret 8` |

---

## Sealed facts — `0x00422880`

1. **ABI:** `__stdcall` two stack formals `(block*, count)`; **`ret 8`**. Return **HRESULT** in EAX (decompiler `void` understates).

2. **Body:** Ghidra `0x00422880`–`0x004228c7` (**72 bytes**). Logical status epilogue is Ghidra-split **`FUN_004228d1`** (`jmp` after store).

3. **Block layout:** `+0 = void* buf`, `+4 = int32 count`.

4. **Alloc:** `operator_new[](count * 8)` @ `0x00489834` (rel32 **Confirmed**). Pointer zeroed before alloc.

5. **HRESULT:** `(-(buf!=0) & 0x7FF8FFF2) + 0x8007000E` → **`0` / `0x8007000E`**.

6. **Sole caller:** `OleDb_BuildBindingsAllocRow_Inferred` @ `0x00421604` — `push 1; push ebx` when `*ctx==0`.

7. **Name:** `OleDb_AllocCtxBlock_Inferred` — role-sealed **INFERRED**. Ghidra: `FUN_00422880`.

---

## Sealed facts — `0x00560e90`

1. **ABI:** **`__thiscall`** manager in **ECX**; stack `(Object* obj, int unused)`; **`ret 8`**; void.

2. **Body:** `0x00560e90`–`0x00560eb1` (**34 bytes**).

3. **CF:** `FUN_0055fbf0(this, obj)` unbind → `FUN_0055fa40(this, obj)` rebind → `*(uint8*)(*(obj+0x44)+0x28) = 1`.

4. **Second stack formal:** cleaned by `ret 8` but **unread** in body. Callers often stage `1` via `mov byte [esp],1` before `push obj`.

5. **Rel32:** `0055fbf0` and `0055fa40` **Confirmed** via `read_memory`.

6. **Callers:** `CVOGHBRecreateObject_RecreateOwner`, ClientSpecialEvent airlift teardown/setup, `FUN_0053dbb0`, `FUN_004c4880`, `FUN_005f44c0`, and related phys/net sites. Manager often resolved as `*[…+0xA8]+0xE4A4`.

7. **Siblings (not owned):** enroll `00560ec0`, remove `00561450`.

8. **Name:** `WorldObj_RebindActivate_Inferred` — role-sealed **INFERRED**. Ghidra: `FUN_00560e90`.

---

## Gaps

### `00422880`
1. Product typedef for the 8-byte-per-count buffer contents.  
2. Whether any non-OleDb image ever calls with `count != 1`.  
3. Runtime / bit-exact / differential — open.

### `00560e90`
1. Product manager class English and flag name at `sub+0x28`.  
2. Why second formal is staged but unread (ABI sibling consistency vs dead arg).  
3. Full dual of unbind/bind helpers — out of owned scope.  
4. Runtime / bit-exact / differential — open.

---

## Dual A/B

| VA | Review A | Review B | Verdict |
|---|---|---|---|
| `0x00422880` | `reviews/A_aa_00422880_OleDb_AllocCtxBlock_Inferred.md` | `reviews/B_aa_00422880_OleDb_AllocCtxBlock_Inferred.md` | **accept** |
| `0x00560e90` | `reviews/A_aa_00560e90_WorldObj_RebindActivate_Inferred.md` | `reviews/B_aa_00560e90_WorldObj_RebindActivate_Inferred.md` | **accept** |

---

## Files

### `aa_00422880`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00422880_OleDb_AllocCtxBlock_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00422880_OleDb_AllocCtxBlock_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00422880_OleDb_AllocCtxBlock_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00422880_FUN_00422880.md` |
| Clean | `docs/reconstruction/reconstructed-exact/OleDb_AllocCtxBlock_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00422880.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_00422880_FUN_00422880.md` |
| Annotated | `docs/reconstruction/raw/aa_00422880_FUN_00422880.annotated.md` |

### `aa_00560e90`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00560e90_WorldObj_RebindActivate_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00560e90_WorldObj_RebindActivate_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00560e90_WorldObj_RebindActivate_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00560e90_FUN_00560e90.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WorldObj_RebindActivate_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00560e90.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_00560e90_FUN_00560e90.md` |
| Annotated | `docs/reconstruction/raw/aa_00560e90_FUN_00560e90.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00422880-00560e90-w24b-report.md` |

---

## AutoCore impact

### `00422880`
- Client OLE DB residual; only needed if porting accessor/ctx gate logic.
- Preserve **HRESULT** and **`count * 8`** stride; do not treat as void.
- Gate path: only when ctx pointer null; sole retail count is **1**.

### `00560e90`
- After phys body mode restore or HB recreate, **rebind** is unbind+bind+flag — not full enroll.
- Ports that only flip a mode dword without rebind may leave spatial/link sets stale.
- Preserve manager **ECX** + **`ret 8`** stack cleanup when matching retail call frames.
- Do not conflate with `WorldObj_EnrollActivate` (`00560ec0`) counters/refcount.

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x004228d1` | SEH status tail for this alloc (split by Ghidra) |
| `0x00489834` | `operator_new[]` |
| `0x0042139b` | sole caller OleDb binding builder (W23-C sealed) |
| `0x0055fbf0` | unbind helper |
| `0x0055fa40` | bind helper |
| `0x00560ec0` | full enroll activate |
| `0x00561450` | remove / defer |
| `0x005dac00` | HB recreate owner (calls rebind) |
| `0x00979290` / `0x00979310` | airlift teardown/setup |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: `decompile_function` + `read_memory` (+ bounds/callers/callees/xrefs).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean plates avoid bare `undefined4` (fixed-width integers / void*).  
