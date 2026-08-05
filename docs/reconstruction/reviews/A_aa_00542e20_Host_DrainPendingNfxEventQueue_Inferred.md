# Review A (reconstruction fidelity): `aa_00542e20` Host_DrainPendingNfxEventQueue_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00542e20` |
| **VA** | `0x00542e20`–`0x00543050` (**561 B**) |
| **Canonical name** | `Host_DrainPendingNfxEventQueue_Inferred` |
| **Ghidra name** | `FUN_00542e20` |
| **Review date** | `2026-07-29` (W35-F dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-F) |
| **Counterpart** | `reviews/B_aa_00542e20_Host_DrainPendingNfxEventQueue_Inferred.md` |
| **System** | host pending NFX / special-FX event queue |
| **Evidence pass** | Live decompile + `read_memory` (full prologue/epilogue) + `analyze_function_complete` + caller site bytes @ `0x0094b7c0` + callees |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Host queue drain for pending NFX/events during client frame:

1. While `host+0xf2c != 0`, process front of list `+0xf28`.
2. Readiness via `FUN_004ed310` on node ring.
3. Hash lookup key `node+0x2c` in `host+0xf0c`.
4. Drop / FOR_EVENT bind+fire / NFX master reload + reset.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00542e20_FUN_00542e20.md` (+ W35-F append) |
| Annotated | `docs/reconstruction/raw/aa_00542e20_FUN_00542e20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host_DrainPendingNfxEventQueue_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00542e20.cpp` |
| Function records | `functions/aa_00542e20_FUN_00542e20.md`, `..._Host_DrainPendingNfxEventQueue_Inferred.md` |
| Live | `MOV EBX,ECX`; `RET 4`; caller `MOV ECX,[DAT_00b041fc]; PUSH sessionField` |
| Context | W34-M ResizeZeroFill callee; FxMaster LoadMasterFromXML; Client_AppFrameTick call site |

---

## 3. Signature (sealed)

```c
void Host_DrainPendingNfxEventQueue_Inferred(Host* self /*ECX*/, void* sessionField /*stack*/);
// RET 4
```

| Slot | Source | Conf |
|---|---|---|
| self | **ECX** → EBX | **High** |
| sessionField | Stack (caller push); body unused in decompile | **High** ABI / **Low** use |
| cleanup | `ADD ESP,0x10C; RET 4` | **High** |

Decompiler omits stack formal — **bytes win**.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Empty-queue fast out | **Yes** | **High** |
| Readiness break | **Yes** | **High** |
| Hash miss → unlink+delete | **Yes** | **High** |
| Unbound → FOR_EVENT + vtbl+0x238 + delete | **Yes** | **High** |
| Bound → optional `_nfx.xml` LoadMaster + reset | **Yes** | **High** |
| Post-break FinishRing | **Yes** | **High** |
| Product host English | open | **Med** |

---

## 5. Gaps / open

1. Product/PDB host type for `DAT_00b041fc` + node layout English.
2. Stack `sessionField` semantic use (if any) beyond RET 4 contract.
3. Unowned callee full contracts (`FUN_004ed310` owned W35-A).
4. Client_AppFrameTick clean currently drops ECX global — port note.
5. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
