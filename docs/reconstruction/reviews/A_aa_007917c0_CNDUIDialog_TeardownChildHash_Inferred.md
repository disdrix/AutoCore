# Review A (reconstruction fidelity): `aa_007917c0` CNDUIDialog_TeardownChildHash_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007917c0` |
| **VA** | `0x007917c0`–`0x007918e1` inclusive (**290 B** / `0x122`) |
| **Canonical name** | `CNDUIDialog_TeardownChildHash_Inferred` |
| **Ghidra name** | `FUN_007917c0` |
| **Review date** | `2026-08-05` (WQ9L-I dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9L-I) |
| **Counterpart** | `reviews/B_aa_007917c0_CNDUIDialog_TeardownChildHash_Inferred.md` |
| **System** | CNDUIDialog complete-dtor leaf / child hash teardown |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` @ `0x00792c4d`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory (+ analyze/xrefs/disassemble_function/assembly_context). **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

CNDUIDialog **child-hash teardown leaf** invoked from complete dtor `FUN_00792c20` (`CNDUIDialog_CompleteDtor`) before the parent scalar-deletes owned pointers. If `this+0x4c0` (hash*) is non-null: clear selection, release optional helper at `+0x4b8`, walk the hash under traversal lock, tear down each child entry, erase children from the dialog vector, unlock, clear list shell at `+0x4dc`, **recreate** empty hash buckets (BL=5), set flag `this+0x4c4 = 1`. Does **not** free the hash object or `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9L-I append) | `docs/reconstruction/raw/aa_007917c0_FUN_007917c0.md` |
| Annotated | `docs/reconstruction/raw/aa_007917c0_FUN_007917c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDUIDialog_TeardownChildHash_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_007917c0.cpp` |
| Scaffold (retired) | `docs/reconstruction/reconstructed-exact/Named_VOG_DEBUG_STOP_007917c0.cpp` |
| Live | full disasm listing; entry/exit hex; sole CALL @ `0x00792c4d`; 100+ DATA vtbl xrefs |

### Entry / exit hex (live `read_memory`)

```text
007917c0: 53 55 8B E9 33 DB 39 9D C0 04 00 00 0F 84 0D 01 00 00
          PUSH EBX; PUSH EBP; MOV EBP,ECX; XOR EBX,EBX;
          CMP [EBP+0x4c0],EBX; JZ skip
...
007918d3: 5F C7 85 C4 04 00 00 01 00 00 00 5E 5D 5B C3
          POP EDI; MOV [EBP+0x4c4],1; POP ESI; POP EBP; POP EBX; RET
```

Pad: `CC` ×14 then next fn @ `0x007918f0`.

---

## 3. Signature (sealed)

```c
// ECX = this (CNDUIDialog*); bare RET; void
void __fastcall CNDUIDialog_TeardownChildHash_Inferred(void *self);
```

| Formal | Source | Conf |
|---|---|---|
| self | **ECX** (`MOV EBP,ECX` @ `0x007917c2`) | **High** |
| return | void (EAX not semantic) | **High** |
| cleanup | bare **`C3`** @ `0x007918e1` | **High** |

---

## 4. Control flow (authority)

```text
if [this+0x4c0] == 0: return
vtbl[+0x3c0](0)                         // clear selection / focus
if [this+0x4b8]: vtbl[+0x318](); zero +0x4b8
// HashError:TraversalLock if already locked
hash.lock(+0x1d) = 1
cursor = null
loop:
  // HashError:TraverseToNext if unlocked mid-walk
  cursor = (cursor == null) ? hash.chain(+0x14) : cursor.next(+0x14)
  child = cursor ? cursor.value(+8) : null
  if child == null: break
  if child.vtbl[+0x34]():
    nested = that; if nested.vtbl[+0x3d8](): nested.vtbl[+0x440]()
  child.vtbl[+0x334](0)
  child[+0x2b0] = 0
  FUN_00756be0(this, child)             // ECX=this; stack=child
unlock (+0x1d = 0)
FUN_004133c0: ESI=this+0x4dc, EAX=0, stack 0
FUN_004281d0: EAX=hash, BL=5            // HashError:Recreate
[this+0x4c4] = 1
return
```

| Stage | Match | Conf |
|---|---|---|
| Gate +0x4c0 / early return | `CMP [EBP+0x4c0],EBX; JZ 0x007918df` | **High** |
| vtbl +0x3c0(0) | `PUSH EBX; CALL [EAX+0x3c0]` | **High** |
| helper +0x4b8 / vtbl +0x318 | `CMP [EBP+0x4b8]; CALL [EDX+0x318]; MOV [+0x4b8],0` | **High** |
| HashError lock strings | `PUSH 0xa27cd0` / `0xa15844` (`VOG_DEBUG_STOP`) | **High** |
| chain walk +0x14 / value +8 | `MOV EDI,[ESI+0x14]` / `[EDI+0x14]` / `[EDI+0x8]` | **High** |
| child nested +0x34 / +0x3d8 / +0x440 | disasm `0x00791860`–`0x0079188b` | **High** |
| child release +0x334 / clear +0x2b0 | `CALL [EAX+0x334]`; `MOV [ESI+0x2b0],EBX` | **High** |
| remove via 00756be0 | `PUSH ESI; MOV ECX,EBP; CALL 0x00756be0` | **High** |
| list shell 004133c0 | `LEA ESI,[EBP+0x4dc]; XOR EAX,EAX; CALL 0x004133c0` | **High** |
| hash Recreate 004281d0 | `MOV EAX,[EBP+0x4c0]; MOV BL,5; CALL 0x004281d0` | **High** |
| flag +0x4c4 = 1 | `MOV [EBP+0x4c4],1` | **High** |

---

## 5. Call graph

| Direction | Targets |
|---|---|
| Sole CALL caller | `FUN_00792c20` @ `0x00792c4d` (after vtbl install `0xa98f44`) |
| DATA xrefs | 100+ dialog vtbl slots (inherited method pointer) |
| Callees | `FUN_007a4480`, `FUN_00756be0`, `FUN_004133c0`, `FUN_004281d0`, dialog/child vtbls |

Parent complete dtor **after** this leaf scalar-deletes `+0x4c0` (`PUSH 1; CALL [vtbl]`) — confirms this body does **not** free the hash heap block.

---

## 6. Naming

| Name | Status |
|---|---|
| Ghidra `FUN_007917c0` | sealed |
| Canonical `CNDUIDialog_TeardownChildHash_Inferred` | sealed (HashError strings + dialog complete-dtor parent; product demangle open → `_Inferred`) |
| Scaffold `Named_VOG_DEBUG_STOP_007917c0` | **retired** (debug string is HashError diagnostic, not product class) |

**Reject:** complete-dtor merge with `00792c20`; claim that this frees hash*; thiscall stack-arg formals.

---

## 7. Gaps

- English names for vtbl slots `+0x3c0` / `+0x318` / child `+0x34` / `+0x334` / nested `+0x3d8`/`+0x440`.
- Product type of hash object at `+0x4c0` beyond HashError family.
- Dual residual of `004133c0` / `004281d0` / `00756be0`.
- Runtime / bit-exact / differential.

---

## 8. Verdict

CF, ABI (ECX=this, bare RET), offset map, HashError lock/walk, Recreate (not free), and sole CALL parent sealed live. Product class demangle + vtbl English open → **accept-with-gaps**.
