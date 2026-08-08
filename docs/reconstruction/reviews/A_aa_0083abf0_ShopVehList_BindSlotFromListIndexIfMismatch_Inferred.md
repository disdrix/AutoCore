# Review A (reconstruction fidelity): `aa_0083abf0` ShopVehList_BindSlotFromListIndexIfMismatch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0083abf0` |
| **VA** | `0x0083abf0`–`0x0083ac89` inclusive (**154 B** / `0x9A`) |
| **Canonical name** | `ShopVehList_BindSlotFromListIndexIfMismatch_Inferred` |
| **Ghidra name** | `FUN_0083abf0` |
| **Review date** | `2026-08-05` (WQ9L-J dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9L-J) |
| **Counterpart** | `reviews/B_aa_0083abf0_ShopVehList_BindSlotFromListIndexIfMismatch_Inferred.md` |
| **System** | shopveh list UI — bind slot entity from list index |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory (+ analyze/xrefs/disassemble_function/assembly_context). **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

When five-slot reindex cannot refresh a window cell from an already-correct id (or cannot swap a donor), look up the entity for `list_i` in the host's nested list container and, if the slot is unbound or bound to a different entity id, call `FUN_0083ab90` to bind/refresh (which finishes with `ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred(flag=1)`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9L-J append) | `docs/reconstruction/raw/aa_0083abf0_FUN_0083abf0.md` |
| Annotated | `docs/reconstruction/raw/aa_0083abf0_FUN_0083abf0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ShopVehList_BindSlotFromListIndexIfMismatch_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0083abf0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0083abf0_ShopVehList_BindSlotFromListIndexIfMismatch_Inferred.md` |
| Live | full disasm listing; body hex; 3 CALL xrefs from reindex parent |

---

## 3. Signature (sealed)

```c
// ECX = slot index [0..4]; EDX = list_i; stack host*; void; RET 4
void ShopVehList_BindSlotFromListIndexIfMismatch_Inferred(int slot, int list_i, void *host);
```

| Formal | Source | Conf |
|---|---|---|
| slot | **ECX** (`TEST ECX` / `JL`; callers `MOV ECX,ESI`) | **High** |
| list_i | **EDX** (`TEST EDX` first; callers `MOV EDX,EDI`) | **High** |
| host | stack (`MOV EBP,[ESP+8]` after `PUSH EBP`) | **High** |
| return | void | **High** |
| cleanup | **`RET 4`** (`C2 04 00`) | **High** |

---

## 4. Control flow (authority)

```text
if list_i < 0: return
nested = host+0x508; if nested == 0: return
if slot < 0 || slot >= 5: return
slot_obj = host+0x50c[slot]; if slot_obj == 0: return
if *(nested+0x50) == 0: return
EDI = nested + 0x2c                    // list container
out = 0
if !FUN_00427d20(list_i, &out): return  // EDI=container (reg)
entity = out; if entity == 0: return
id = entity->vtbl[+0x1d4](); if id == 0: return
if slot_obj+0x508 != 0:
  if (slot_obj+0x50c) == entity->vtbl[+0x1d4](): return  // already bound
// mismatch / unbound:
entity_id = entity->vtbl[+0x1d4]()      // leaves EAX for ab90
PUSH host; MOV ECX,slot_obj; CALL FUN_0083ab90
```

| Stage | Match | Conf |
|---|---|---|
| Gates list_i / nested / slot∈[0,5) / slot_obj / +0x50 | disasm `0083abf0`–`0083ac24` | **High** |
| List container EDI = nested+0x2c | `LEA EDI,[EAX+0x2c]` | **High** |
| Lookup FUN_00427d20 | `PUSH &out; PUSH EDX; CALL 00427d20` | **High** |
| Entity id vtbl+0x1d4 (×1–3) | `CALL [EDX/EAX+0x1d4]` | **High** |
| Mismatch bind ab90 | `PUSH EBP; MOV ECX,EBX; CALL 0083ab90` | **High** |
| RET 4 | `5E 5F 5B 5D C2 04 00` | **High** |

---

## 5. Machine bytes (entry / exit)

| Item | Hex / notes |
|---|---|
| Body | `0x0083abf0`–`0x0083ac89` (**154 B** / `0x9A`); pad `CC`×6 then parent `FUN_0083ac90` |
| Entry | `85 D2 55 8B 6C 24 08 0F 8C …` |
| Exit | `5E 5F 5B 5D C2 04 00` |

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers (3 CALL) | `FUN_0083ac90` only @ `0083ad5a`, `0083adb7`, `0083add0` — each `PUSH EBP; MOV ECX,ESI; MOV EDX,EDI` |
| Callees | `FUN_00427d20`, `FUN_0083ab90`, entity vtbl `+0x1d4` |

---

## 7. Gaps

1. Product demangle for host / slot / entity classes.  
2. Dual of `FUN_00427d20` (list-by-index) and `FUN_0083ab90` (bind worker) — not OWN.  
3. Exact meaning of entity vtbl `+0x1d4` (id/handle — GetEntityId-like).  
4. Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path seals ABI (ECX slot + EDX list_i + stack host + RET 4), five gates, list container at nested+0x2c, mismatch bind via `0083ab90`, and sole parent reindex call sites. Residual product English + helper duals → **accept-with-gaps**.
