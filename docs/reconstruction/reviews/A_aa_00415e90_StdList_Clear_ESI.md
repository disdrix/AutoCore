# Review A (reconstruction fidelity): `aa_00415e90` StdList_Clear_ESI

| Field | Value |
|---|---|
| **Stable ID** | `aa_00415e90` |
| **VA** | `0x00415e90` |
| **Body** | `0x00415e90`–`0x00415ec6` exclusive (**54** B / `0x36`) |
| **Canonical name** | `StdList_Clear_ESI` |
| **Ghidra name** | `FUN_00415e90` |
| **Review date** | `2026-08-05` (WQ9L-H OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00415e90_StdList_Clear_ESI.md` |
| **System** | shared `client::stdlist` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

ESI-entry MSVC `std::list` **clear**: re-ring sentinel next/prev to self, `_Mysize=0`, free every former element node with `operator_delete`. Does not free list shell or sentinel.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9L-H re-verify) | `docs/reconstruction/raw/aa_00415e90_FUN_00415e90.md` |
| Annotated | `docs/reconstruction/raw/aa_00415e90_FUN_00415e90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_Clear_ESI.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00415e90.cpp` |
| Function record | `docs/reconstruction/functions/aa_00415e90_StdList_Clear_ESI.md` |
| Live body | `read_memory` full 54 B |
| Parent | dual `CNDUIDialog_CompleteDtor` @ `0x00792c20` (WQ9K-G) |
| ECX twin | dual `StdList_Clear_Inferred` @ `0x00404060` |

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| ESI | list* | entry `MOV ECX,[ESI+4]`; dialog `LEA ESI,[EDI+0x4dc]` |
| stack formals | none | no args |
| cleanup | bare **`RET`** | `C3` @ `0x00415ec5` |
| return | void | no EAX product |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span + bare RET | **Confirmed** | bytes end free-loop + `5F C3` |
| ESI=list* ABI | **Confirmed** | entry + dialog/00402280 sites |
| Re-ring head next/prev; size@+8=0 | **Confirmed** | decompile ≡ bytes |
| Multi-node free loop | **Confirmed** | `read_memory` loop; decompiler truncated |
| Sentinel not freed here | **Confirmed** | loop stops at head; parent may free head |
| No value/element dtor | **High** | only `operator_delete` |
| Element product type | **Open** | site-dependent |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 5. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| head = *(list+4); first = *head | **Yes** |
| *head = head; head->prev = head | **Yes** |
| *(list+8) = 0 | **Yes** |
| while first != head: delete; first = next | **Yes** (bytes; decomp shows one delete) |
| no free(list) | **Yes** |

---

## 6. Naming gate

- Role = std::list clear sealed (layout + free-loop + twin ECX form).
- ESI qualifier distinguishes VA from `0x00404060`.
- Product demangle of `list<T>` open — name stays register-qualified clear, not inventing T.

**Verdict:** **accept-with-gaps**.
