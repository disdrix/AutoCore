# Review A (reconstruction fidelity): `aa_005614f0` WorldObj_UnbindOrDefer_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005614f0` |
| **VA** | `0x005614f0`–`0x00561571` |
| **Body** | **129 bytes** (`0x81`) |
| **Canonical name** | `WorldObj_UnbindOrDefer_Inferred` |
| **Ghidra name** | `FUN_005614f0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-J) |
| **Counterpart** | `reviews/B_aa_005614f0_WorldObj_UnbindOrDefer_Inferred.md` |
| **System** | world-object unbind / defer |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + callers/xrefs |
| **Verdict** | **accept** |

---

## 1. Purpose

Manager **thiscall** to **unbind** a world object from host/links — **or defer** that unbind when reentrancy flag `manager+0x12c == 1`.

Polarity vs sibling `WorldObj_RemoveOrDefer_Inferred` (`00561450`): same defer queue, but immediate path is **unbind-only** (no remove-notify helpers, no ref--, no destroy). Used when the object must survive for later rehome/reattach (mode-7 leave).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005614f0_FUN_005614f0.md` (+ W30-J append) |
| Annotated | `docs/reconstruction/raw/aa_005614f0_FUN_005614f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WorldObj_UnbindOrDefer_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005614f0.cpp` |
| Function records | scaffold + named |
| Live | decompile ≡ raw stages; epilogue `ret 8`; call site `00561892` |
| Sibling | `A_aa_00561450_WorldObj_RemoveOrDefer_Inferred.md` |
| Parent dual | W29-T SnapshotHostRefsAndUnbind |

**Not performed:** `disassemble_bytes`, Launcher, runtime, dual of nested unbind helpers.

---

## 3. Signature (sealed)

```c
// thiscall; ECX = manager; stack outDone, obj; ret 8; void
void WorldObj_UnbindOrDefer_Inferred(int manager /*ECX*/, uint8_t *outDone, int obj);
```

| Formal | Source | Conf |
|---|---|---|
| manager | ECX (`MOV ESI,ECX`) | **High** |
| outDone | stack arg #1 | **High** |
| obj | stack arg #2 | **High** |
| cleanup | `ret 8` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

| Stage | Match | Conf |
|---|---|---|
| Flag `+0x12c==1` → defer queue | **Yes** | **High** |
| Grow `005b3370(elem 4)` | **Yes** | **High** |
| Defer ref++ / out=0 | **Yes** | **High** |
| Optional `00561320` | **Yes** | **High** |
| `0055fbf0` then `0055f0b0` then `0055fd80` | **Yes** (machine this-ptrs) | **High** |
| Immediate out=1; no destroy | **Yes** | **High** |
| thiscall + ret 8 | **Yes** | **High** |

### Machine this-pointer seal (immediate)

```
PUSH obj; MOV ECX, manager; CALL 0055fbf0
MOV ECX, obj; CALL 0055f0b0
PUSH obj; MOV ECX, manager; CALL 0055fd80
```

Decompiler may drop ECX on some nested calls; clean carries machine CF.

---

## 5. Gaps / open

1. Product English for defer flag / queue drain path shared with RemoveOrDefer.
2. Nested duals of `0055fbf0` / `0055f0b0` / `0055fd80`.
3. Full role of caller `FUN_00561580`.
4. Runtime / bit-exact.

**Verdict:** **accept** — CF/ABI/role sealed; distinct from destroy path.
