# Review A (reconstruction fidelity): `aa_00538ab0` DisciplineDefMap_ExactFindByIntKey_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538ab0` |
| **VA** | `0x00538ab0`–`0x00538b17` |
| **Canonical name (Ghidra)** | `FUN_00538ab0` |
| **Proposed name** | `DisciplineDefMap_ExactFindByIntKey_Inferred` |
| **Review date** | `2026-08-05` (R13-037 OWN-ONLY dual A; dual start 2686) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00538ab0_DisciplineDefMap_ExactFindByIntKey_Inferred.md` |
| **System** | `skills-abilities` (partition parent `0x0052b040`) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **ordered-map exact find** for the process-global **DisciplineDef** tree:

1. Load head = `*(this+4)`; root = `head[1]`; candidate = head.
2. While root/cursor isnil byte `@+0x20d` is clear: if `node.key (+0x0C) < *pKey` go **right** (`+8`); else candidate = node, go **left** (`*node`).
3. If candidate ≠ head **and** `candidate.key <= *pKey` → `*pOut = candidate` (**exact hit** under walk invariant).
4. Else → `*pOut = head` (**miss** / end; image end often `DAT_00b045b4`).

**Read-only leaf** — no insert/erase/allocation/callees. Primary consumers: try-copy `FUN_0052b040`, prereq helper `FUN_0052b140`, and seven other DisciplineDef map accessors — all hardcode map header **`0x00b045b0`**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00538ab0` |
| Complete analysis | `analyze_function_complete` (xrefs/callers/callees/disasm/locals) |
| Assembly | `disassemble_function` (body through dual `RET 8`; **not** `disassemble_bytes`) |
| Bytes | `read_memory` 128 B @ entry — nil `80 B8 0D 02 00 00 00`, dual `C2 08 00`, pad `CC` |
| Callers / xrefs | `get_function_callers` (9) + `get_xrefs_to` (9 UNCONDITIONAL_CALL) |
| Parent call site | `disassemble_function` / `read_memory` @ `0x0052b040` (`MOV ECX,0xb045b0`; `MOV EAX,[EAX]` after call) |
| Sibling call sites | `read_memory` @ `0x0052b150`, `0x0052d040` — same `B9 B0 45 B0 00` |
| Parent dual | `A\|B_aa_0052b040_DisciplineDefMap_TryCopyPayloadById_Inferred` |
| Family contrast | SkillDefMap `0x00418890`; Map exact `0x0051c150`; nearby `0x00538a40` |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact|functions` for `aa_00538ab0` |

**Not performed:** `disassemble_bytes` primary, Launcher, runtime Confirmed, parent ledger edits, other VAs dualled.

---

## 3. Signature

```c
void *__thiscall DisciplineDefMap_ExactFindByIntKey_Inferred(
    void *mapHeader /* ECX */,
    void **pOutNode /* stack0 */,
    const int *pKey /* stack1 */);
// RET 8; *pOutNode = node* or end; EAX = pOutNode on return
```

| Item | Evidence |
|---|---|
| Convention | dual `RET 0x8` @ `0x00538b00` / `0x00538b15`; thiscall uses `ECX+4` |
| Nil | `CMP BYTE PTR [EAX+0x20d],0` (`80 B8 0D 02 00 00 00`) |
| Key | walk `CMP [EAX+0xC],ESI`; gate `CMP ECX,[EDX+0xC]` + signed `JL` miss |
| Body size | **104 B** (`0x68`); pad `CC` @ `0x00538b18` |
| Map hardcode (callers) | `MOV ECX,0xb045b0` before every static CALL |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| head = `*(this+4)`; root = `head[1]` | **Yes** |
| lower_bound walk on int key / nil+0x20d | **Yes** |
| exact gate `cand≠head && key<=search` | **Yes** |
| miss writes head; hit writes candidate | **Yes** |
| no callees / no map mutation | **Yes** |
| thiscall + RET 8 (not cdecl/stdcall bare) | **Yes** |

### Recovered CF

```c
Node *end  = *(this + 4);
Node *cand = end;
Node *cur  = end->_Parent;           // end[1]
if (cur->_Isnil == 0) {              // +0x20d
  do {
    if (cur->_Key < *pKey)           // +0x0C
      cur = cur->_Right;             // +0x08
    else {
      cand = cur;
      cur  = cur->_Left;             // +0x00
    }
  } while (cur->_Isnil == 0);
}
if (cand != end && cand->_Key <= *pKey)
  *pOut = cand;
else
  *pOut = end;
// return pOut (EAX)
```

### Layout (sealed)

| Off | Role |
|----:|------|
| map `0x00b045b0` | header (callers); head/end ptr at `+4` (= `DAT_00b045b4` symbol) |
| node `+0x0C` | int key |
| node `+0x10` | payload base (0x1FC DisciplineDef — parent/sibling consumers) |
| node `+0x20D` | isnil |

### Family (do not merge)

| Helper | Nil | Key | Op |
|---|---|---|---|
| **This `0x00538ab0`** | **`+0x20d`** | **`+0x0C`** | **exact (in-body walk)** |
| SkillDefMap `0x00418890` | `+0x641` | `+0x0C` | exact via separate lower_bound |
| `0x0051c150` | `+0x29` | `+0x10` | exact |
| `0x00538a40` | `+0x49` | `+0x10` | exact (different tree) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI thiscall + RET 8 | **High** | disasm + bytes + caller prologues |
| Nil `+0x20d` / key `+0x0C` / L/R links | **High** | immediate operands |
| Exact find (not open lower_bound API) | **High** | post-walk `<=` gate |
| Map = DisciplineDef `@0x00b045b0` | **High** | all 9 static callers |
| Distinct from SkillDefMap | **High** | nil/header/payload differ |
| Product method English | **Open** | `_Inferred` hygiene |
| Full node schema beyond key/links/nil | **Open** | payload size from parent dual |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 6. Gaps / open

1. Product/PDB DisciplineDef map method English.  
2. Full node field schema beyond key / children / nil / `+0x10` payload base.  
3. Whether non-static paths could pass a different header with identical geometry (none in image xrefs).  
4. Runtime Confirmed / differential / cold map contents.

**Verdict:** **accept-with-gaps** — CF/ABI/layout/domain High; product English + full schema + runtime open.
