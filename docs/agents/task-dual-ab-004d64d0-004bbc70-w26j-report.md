# Dual A/B report — W26-J OWN `aa_004d64d0` + `aa_004bbc70`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W26-J  
**Scope:** VAs `0x004d64d0`, `0x004bbc70` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / callers / callees / xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004d64d0` CVOGSectorMap_Destructor | **accept-with-gaps** — class/vtbl/counter/ABI + sequential teardown sealed; 0xE920 field English open |
| `aa_004bbc70` COList_Destructor | **accept** — stack ThreadSafeObjectList + dual-hash collect + TakeByCoid drain + owned vdel sealed |

---

## VA `0x004d64d0` — sealed facts

1. **Body:** `0x004d64d0`–`0x004d6c77` (**1960 B**); pad `CC` after `C3`.
2. **ABI:** **thiscall**; ECX=`this`; frame `sub/add esp,8`; **void**; bare `ret`.
3. **Vtbl:** `*this = PTR_FUN_009cc770` (`C7 06 70 C7 9C 00`) — same as sealed ctor `aa_004d8a10`.
4. **Counter:** `_DAT_00b037e4--` (ctor increments).
5. **Class:** **CVOGSectorMap** (product via ctor / `@@new CVOGSectorMap` / object size `0xE920`).
6. **CF:** hash destroy under traversal lock (`FUN_004e3610`) → virtual-delete cascade → PopFront drains → subsystem helpers (`FUN_004e72xx`, `FUN_00497360`, `FUN_004bcbf0`, …) → buffer triples → ret.
7. **Caller (1):** `Catch@0094b325` @ `0x0094b34e` (InitInstance failure: dtor then `operator_delete` on client+`0xe04`).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23); delete-noreturn nesting is decompiler artifact.
9. **Name:** `CVOGSectorMap_Destructor` (Ghidra `FUN_004d64d0`).

### Gaps

- Exhaustive product English for full `0xE920` layout (shared with ctor).  
- Vtbl slot inventory pointing at this body (Catch is sole code xref).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004d64d0_CVOGSectorMap_Destructor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004d64d0_CVOGSectorMap_Destructor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004d64d0_FUN_004d64d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004d64d0_FUN_004d64d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGSectorMap_Destructor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004d64d0.cpp` |
| Function | `docs/reconstruction/functions/aa_004d64d0_FUN_004d64d0.md` |
| Function named | `docs/reconstruction/functions/aa_004d64d0_CVOGSectorMap_Destructor.md` |
| Scratch | `docs/reconstruction/tmp/a_004d64d0.md` |

---

## VA `0x004bbc70` — sealed facts

1. **Body:** `0x004bbc70`–`0x004bbea4` (**565 B**); pad `CC` after `C3`.
2. **ABI:** **thiscall**; ECX=`this`; frame **`0x44`**; **void**; bare `ret`.
3. **Vtbl:** `*this = PTR_FUN_009cb448`; product rdata **`COList::Insert`** adjacent to vtbl.
4. **Scalar dtor:** `FUN_004bd1b0` = this body + optional `operator_delete` if flag&1 (`ret 4`); vtbl[0].
5. **Ctor twin:** `FUN_004bbfb0` same vtbl; `Client_InitInstance` → `DAT_00b04830`.
6. **Stack list:** construct `ThreadSafeObjectList` on stack (`PTR_FUN_009cb368` + ICS at +0x10/+0x28); **not** a member.
7. **CF:** lock-walk hashes `this+4` / `this+8` (next **node+0x20**, payload **+0x0C**); if `obj+0xac≠0` append to stack list → drain PopFront + `ClonedObjectList_TakeByCoid` (`FUN_004bb970`) → vdel slots 6,7,8,9,1,2 → `ThreadSafeObjectList_Dtor(stack)` → free buffer triples 0x13/0xf/0xb.
8. **Caller (1):** `FUN_004bd1b0` only.
9. **Name:** `COList_Destructor` (Ghidra `FUN_004bbc70`).
10. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Hash/vector product field English beyond indices.  
- Exact `sizeof(COList)`.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004bbc70_COList_Destructor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004bbc70_COList_Destructor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004bbc70_FUN_004bbc70.md` |
| Annotated | `docs/reconstruction/raw/aa_004bbc70_FUN_004bbc70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/COList_Destructor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004bbc70.cpp` |
| Function | `docs/reconstruction/functions/aa_004bbc70_FUN_004bbc70.md` |
| Function named | `docs/reconstruction/functions/aa_004bbc70_COList_Destructor.md` |
| Scratch | `docs/reconstruction/tmp/a_004bbc70.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004d64d0` | Sector map teardown must mirror ctor resource ownership: counter `--`, hash destroy under lock, PopFront semantics for embedded lists, subsystem helper order. Do **not** port decompiler delete-noreturn nesting as real CF. |
| `004bbc70` | COList shutdown requires stack scratch list + TakeByCoid detach before child deletes. Hash node next is **+0x20** (not SectorMap’s +0x14 walk). List primitives already dual-sealed (`0040b020` / `004bcbf0` / `004024d0`). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory (+ callers/callees/xrefs). No `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names: CVOGSectorMap from ctor twin; COList from vtbl rdata strings.
