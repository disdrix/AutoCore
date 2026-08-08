# Review A (reconstruction fidelity): `aa_00402c40` CNDHash_TraversalLock_Set_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402c40` |
| **VA** | `0x00402c40`–`0x00402c69` |
| **Canonical name (Ghidra)** | `FUN_00402c40` |
| **Proposed name** | `CNDHash_TraversalLock_Set_Inferred` |
| **Review date** | `2026-08-05` (MEGA-110 OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00402c40_CNDHash_TraversalLock_Set_Inferred.md` |
| **System** | interaction-activation (shared CNDHash primitive; partition parent `0x0091b8d0`) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

---

## 1. Purpose

Shared **CNDHash TraversalLock set** leaf:

1. If `*(hash+0x1d) != 0` → soft-log `"HashError:TraversalLock, already locked for traversal"` then `"VOG_DEBUG_STOP"` via `FUN_007a4480`.
2. **Always** store `*(hash+0x1d) = 1`.
3. Return (void, bare RET).

No node walk, free, CriticalSection, or throw. Enables ordered hash traversal (e.g. dualed `CNDHash_TraverseToNext` @ `0x00411900`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00402c40` |
| Complete analysis | `analyze_function_complete` (xrefs/callers/callees/disasm/locals) |
| Assembly | `disassemble_function` (14 insns; **not** `disassemble_bytes`) |
| Bytes | `read_memory` 48 B @ entry — hex seal + `CC` pad |
| Strings | `read_memory` @ `0x00a27cd0`, `0x00a15844`; `search_strings` HashError family |
| Callers / xrefs | `get_function_callers` (21) + `get_xrefs_to` (30 UNCONDITIONAL_CALL) |
| Call-site ABI | `disassemble_function` on `Client_UpdateNpcInteractIcons` / `FUN_004bae00` |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_00402c40` |

**Not performed:** `disassemble_bytes` primary, Launcher, runtime Confirmed, parent ledgers.

---

## 3. Signature

```c
void __fastcall CNDHash_TraversalLock_Set_Inferred(int hash /* ECX */);
// bare RET; void
```

| Item | Evidence |
|---|---|
| Convention | `MOV ESI,ECX` entry; bare `RET` @ `0x00402c69`; no stack formals |
| Flag @ `+0x1d` | `CMP byte [ESI+0x1d],0` / `MOV byte [ESI+0x1d],1` |
| Soft log | two `CALL FUN_007a4480` + `ADD ESP,0x10` only on already-locked path |
| Body size | 42 B (`0x2A`); pad `CC` before next function `0x00402c70` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Flag≠0 → dual log then fall through | **Yes** |
| Always set flag=1 | **Yes** |
| No throw / no CS / no iterate | **Yes** |
| ECX = hash (call-site sealed) | **Yes** |

### Layout (sealed)

| Off | Role |
|----:|------|
| `hash+0x1d` | TraversalLock flag (byte) |

### Call-site samples

| Site | ECX source | Follow-on |
|---|---|---|
| `0x0091bb77` `Client_UpdateNpcInteractIcons` | ESI = `*(client+0x548)` hash | `CNDHash_TraverseToNext` |
| `0x004bae17` / `0x004bae41` `FUN_004bae00` | `[this+4]` / `[this+8]` hash | walk then **inline** `+0x1d=0` unlock |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI + flag offset | **High** | bytes + disasm + decompile identical |
| Soft re-lock (log + force) | **High** | no early RET on locked path |
| Role = Hash TraversalLock set | **High** | string + CNDHash_TraverseToNext pairing |
| Name `CNDHash_*` class tag | **High (role)** | dualed TraverseToNext family; product method English open → `_Inferred` |
| Distinct from List_TraversalLock | **High** | different offsets / no CS |
| Reject Named_VOG_DEBUG_STOP identity | **High** | assert string only |
| Product method English | **Open** | `_Inferred` hygiene |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 6. Gaps / open

1. Product/PDB method name on CNDHash.  
2. Shared unlock helper (if any) — many sites inline clear.  
3. Runtime Confirmed / differential.

**Verdict:** **accept** — CF/ABI/strings/callers High; only product English + runtime open.
