# Review A (reconstruction fidelity): `aa_004025e0` StdList_PushBack_Val0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004025e0` |
| **VA** | `0x004025e0`–`0x00402611` inclusive last byte (**50 B** / `0x32`) |
| **Canonical name** | `StdList_PushBack_Val0x28_Inferred` |
| **Ghidra name** | `FUN_004025e0` |
| **Review date** | `2026-08-05` (MEGA-059 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_004025e0_StdList_PushBack_Val0x28_Inferred.md` |
| **System** | shared MSVC `std::list` push_back (T size 0x28); seed partition missions-progression |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `analyze_function_complete` + callers/xrefs + `read_memory` + `get_function_by_address`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-shaped **`std::list::push_back` / `_Insert(_Myhead, val)`** for element type size **0x28** (node size **0x30**):

```text
head = list->_Myhead
node = Buynode(head, head->_Prev, val)   // FUN_00403560 → new 0x30 + FUN_00404390
_Incsize(1)                              // FUN_00403600; max 0x6666666
head->_Prev = node
node->_Prev->_Next = node
```

Sole production caller is dualed parent **`CVOGReaction_TransferMap`** (`0x004d37f0`), which pushes a stack-built 0x28-byte record into the embedded list at **`reaction+0xe778`**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004025e0_FUN_004025e0.md` (+ MEGA-059 append) |
| Annotated | `docs/reconstruction/raw/aa_004025e0_FUN_004025e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_PushBack_Val0x28_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004025e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004025e0_FUN_004025e0.md` |
| Named record | `docs/reconstruction/functions/aa_004025e0_StdList_PushBack_Val0x28_Inferred.md` |
| Live | decompile ≡ CF; body hex; RET 4; 1 CALL xref; call-site `EDI+0xe778` |
| Callees live | `FUN_00403560` (new 0x30, RET 0xC); `FUN_00403600` (`"list<T> too long"`, max 0x6666666); `FUN_00404390` (10 dword val copy) |

---

## 3. Signature (sealed)

```c
// ECX = list*; stack const T* (T size 0x28); RET 4; void
void __thiscall StdList_PushBack_Val0x28_Inferred(void *list, const void *value);
```

| Slot | Source | Conf |
|---|---|---|
| list | **ECX** (`MOV ESI,ECX`) | **High** |
| value* | stack `[ESP+4]` after entry (`MOV EAX,[ESP+4]`) | **High** |
| cleanup | **`RET 4`** | **High** |
| T size | **0x28** (buynode 0x30; ctor copies 10 dwords; max=`0xFFFFFFFF/0x28`) | **High** |
| op | **push_back** (insert before `_Myhead`) | **High** |

**Note:** Parent decompile shows `FUN_004025e0(&stack0xffffffd4)` without this — assembly seals `LEA ECX,[EDI+0xe778]` + `PUSH &local_T`.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Load `_Myhead` @ +4 | **Yes** | **High** |
| Buynode(head, head+4 prev, val) | **Yes** | **High** |
| Incsize(1) via thiscall list | **Yes** | **High** |
| `head->_Prev = node` | **Yes** | **High** |
| `node->_Prev->_Next = node` | **Yes** | **High** |
| Single basic block / no branches | **Yes** | **High** |
| Product T English | open | **Inferred** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (`analyze_function_complete`) |
| External callers | `CVOGReaction_TransferMap` only; **xref_count=1** @ `0x004d3893` |
| Site role | after transfer success flag `+0x4f4=1`; push local T into list @ `+0xe778` |
| Callees | `FUN_00403560`, `FUN_00403600` |
| Twin pattern | `StdList_PushPayloadNode` (dword T) — same link CF, different node/incsize |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| MSVC list insert-before-head CF + size++ | **Yes** |
| `"list<T> too long"` via Incsize max matching T=0x28 | **Yes** |
| Node 0x30 / value 10 dwords sealed | **Yes** |
| Distinct from dword PushPayloadNode | **Yes** |
| Product/PDB English for T / list member | **No** |

**Decision:** promote **`StdList_PushBack_Val0x28_Inferred`**. Retire `Named_CalleeOf_CVOGReaction_TransferMap_*`. Reject cookie/epilogue claim. Reject map/set tree insert. Reject CsSList / freelist mislabel.

---

## 7. Gaps / open

1. Product English for the 0x28-byte transfer value type and list member name at `CVOGReaction+0xe778`.
2. Residual duals for buynode `00403560` / ctor `00404390` / Incsize `00403600` (context only here).
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
