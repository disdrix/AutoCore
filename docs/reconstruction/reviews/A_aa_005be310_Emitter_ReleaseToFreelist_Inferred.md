# Review A (reconstruction fidelity): `aa_005be310` Emitter_ReleaseToFreelist_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005be310` |
| **VA** | `0x005be310`–`0x005be32e` exclusive |
| **Body** | **30** bytes / `0x1e` |
| **Canonical name** | `Emitter_ReleaseToFreelist_Inferred` |
| **Ghidra name** | `FUN_005be310` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-R) |
| **Counterpart** | `reviews/B_aa_005be310_Emitter_ReleaseToFreelist_Inferred.md` |
| **System** | client NDSpecialFX / emitter freelist |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + callers/xrefs + teardown-callee decompile |
| **Verdict** | **accept** |

---

## 1. Purpose

Release an emitter payload to the global freelist:

1. Call heavy body teardown `FUN_005bbc50(this=node)` (bytes rebind ECX = stack node).
2. If node non-null: freelist-push via dword0 next onto `*ECX` head.

Call sites always pass **`ECX = DAT_00b454fc`** (global freelist head). HostTick kill path and ClearChildLists walk of host list `+0x1E0` are primary product consumers.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | full body @ `0x005be310` |
| Body bytes | `read_memory` 64 B @ entry (ends `C2 04 00` + `CC`) |
| Callee | `FUN_005bbc50` decompile (heavy teardown; not OWN) |
| Callers | HostTick `0x004b913b`; ClearChildLists `0x004b85eb`; `FUN_004a34f0` ×7 — all `B9 FC 54 B4 00` |
| Raw / annotated / clean | W30-R updated |

**Not performed:** Launcher, runtime golden, product demangle, `disassemble_bytes`.

---

## 3. Signature (sealed)

```c
// __thiscall; ECX = freelist head*; stack Emitter*; RET 4; void
void Emitter_ReleaseToFreelist_Inferred(Emitter **head, Emitter *node);
```

| Formal | Source | Conf |
|---|---|---|
| this / ECX | freelist head* (`DAT_00b454fc` at sites) | **High** |
| node | Stack[0x4] after push | **High** |
| cleanup | `RET 4` | **High** |
| return | void | **High** |

---

## 4. Control flow checklist

| Stage | Match | Conf |
|---|---|---|
| Save freelist head in EDI; node in ESI | **Yes** | **High** |
| Rebind ECX = node; call teardown | **Yes** | **High** |
| Null skip freelist push only | **Yes** | **High** |
| dword0 freelist push | **Yes** | **High** |
| ret 4 | **Yes** | **High** |
| Three caller families, shared freelist | **Yes** | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 30 B / ret 4 | **Confirmed** | `read_memory` |
| Teardown then freelist push | **Confirmed** | decomp ≡ bytes |
| ECX is freelist not host | **Confirmed** | `mov ecx, 0x00B454FC` at sites |
| Teardown child ECX = node | **Confirmed** | `8B CE` before call |
| Product English | **Inferred** | `_Inferred` |
| Full teardown semantics | **Open** | W30-S owns `FUN_005bbc50` |
| Runtime | **Open** | matrix |

---

## 6. Gaps

1. Product/PDB English.  
2. Nested `FUN_005bbc50` not OWN (W30-S).  
3. Null-node teardown reachability.  
4. Runtime / bit-exact / differential — open.

---

## 7. Verdict

Fidelity pass **accepts** sealed freelist-release helper with global head + teardown callee → **accept**.
