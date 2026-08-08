# Review A (reconstruction fidelity): `aa_0082ce20` CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082ce20` |
| **VA** | `0x0082ce20` |
| **Body** | `0x0082ce20`–`0x0082cf28` exclusive (**264 B** / `0x108`); RET @ `0x0082cf27` |
| **Canonical name** | `CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred` |
| **Ghidra name** | `FUN_0082ce20` |
| **Review date** | `2026-08-05` (WQ9L-H2 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0082ce20_CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred.md` |
| **System** | skills-abilities / CVOGMenu owned CNDHash teardown |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (entry/mid/epilogue) + `get_assembly_context` + `batch_decompile` callees/parents. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Derived **member teardown** for product class **CVOGMenu**: if owned CNDHash\* @ **`this+0x534`** is non-null, traversal-lock the hash, walk ordered nodes (head@+0x14, next@+0x14, entry@+8), for each entry lock nested list@entry+8, notify **menu vtbl[+0xbc]** per value, destroy nested owned chain, unlock hash, **scalar-delete** hash (`vtbl[0](1)`), null slot. Does **not** free CVOGMenu `this` and does **not** run `CNDUIDialog` base complete (parent does).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9L-H / H2 re-verify) | `docs/reconstruction/raw/aa_0082ce20_FUN_0082ce20.md` |
| Annotated | `docs/reconstruction/raw/aa_0082ce20_FUN_0082ce20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred.cpp` |
| Twin include | `docs/reconstruction/reconstructed-exact/FUN_0082ce20.cpp` |
| Named record | `docs/reconstruction/functions/aa_0082ce20_CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_0082ce20_FUN_0082ce20.md` |
| Parent dual (context) | `CVOGMenu_CompleteDtor` @ `0x0082d540` (WQ9K-G) |
| Sibling dual (READ-only) | `StdList_Clear_ESI` @ `0x00415e90` (WQ9L-H) |
| Live body | `read_memory` entry / mid-body nested-list / epilogue |

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| ECX | CVOGMenu\* this | entry `8B E9` (`MOV EBP,ECX`); parent `MOV ESI,ECX` then CALL with ECX preserved |
| stack formals | none | bare thiscall helper |
| frame | `SUB ESP,8` | locals: iter_state + out value |
| cleanup | bare **`RET`** | `C3` @ `0x0082cf27` after `ADD ESP,8` |
| return | void | no EAX product |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span + bare RET | **Confirmed** | `read_memory` epilogue `5E 5D 5B 83 C4 08 C3` + `CC` pad |
| ECX = this; hash\* @ +0x534 | **Confirmed** | `MOV ESI,[EBP+0x534]`; null store same slot |
| CNDHash family (TraversalLock strings) | **High** | `HashError:TraversalLock…` / `TraverseToNext…` + `VOG_DEBUG_STOP` |
| Ordered walk head@+0x14 / next@+0x14 / entry@+8 | **Confirmed** | decompile ≡ mid-body bytes |
| Nested list shell @ entry+8 | **Confirmed** | `LEA ESI,[EAX+8]; MOV ECX,ESI` before lock/destroy |
| Notify via menu vtbl[+0xbc] | **Confirmed** | `CALL [EDX+0xbc]`; secondary caller also uses +0xbc |
| Soft lock asserts (no hard abort) | **High** | log + continue; still forces lock / continues walk |
| Scalar-delete hash then null slot | **Confirmed** | `PUSH 1; CALL [EDX]`; `MOV [EBP+0x534],0` |
| Does not free CVOGMenu / base dialog | **Confirmed** | parent chains `CNDUIDialog_CompleteDtor` after |
| Product hash stamp / value_type English | **Open** | `_Inferred` retained |
| vtbl[+0xbc] product method English | **Open** | residual |
| Nested list element type | **Open** | `FUN_00410d60` scalar-deletes nodes; T open |
| Runtime / bit-exact / differential | **Open** | no Launcher; terminal false |

---

## 5. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| if hash@+0x534 == 0: return | **Yes** |
| soft-assert TraversalLock@+0x1d; force = 1 | **Yes** |
| while walk ordered nodes; break on null entry | **Yes** |
| lock nested list; iterate values; notify +0xbc | **Yes** (ECX restored from bytes) |
| unlock nested CS if held; destroy chain | **Yes** |
| unlock hash; scalar-delete; null slot | **Yes** |

### Nested iterate ABI (decompiler repair)

Decompile of this unit elides iter-state ECX for `FUN_004113b0`. Bytes + callee seal:

```text
ECX = &iter_state (stack local, init 0)
stack: list (entry+8), &out_value
return 0 ⇒ more values; non-zero ⇒ done / error
```

---

## 6. Naming gate

- Role = CVOGMenu-owned CNDHash **traverse + notify + scalar-delete** at fixed offset **+0x534**.
- Product class **CVOGMenu** sealed via parent RTTI / complete dtor dual (`PTR_FUN_00a72f6c`, `.?AVCVOGMenu@@`).
- CNDHash family sealed by lock-error strings (not inventing a product hash stamp).
- `_Inferred` kept for open value_type / notify English / exact hash RTTI of slot object.

**Verdict:** **accept-with-gaps**.
