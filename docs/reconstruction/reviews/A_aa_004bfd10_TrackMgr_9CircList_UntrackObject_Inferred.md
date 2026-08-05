# Review A (reconstruction fidelity): `aa_004bfd10` TrackMgr_9CircList_UntrackObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bfd10` |
| **VA** | `0x004bfd10` |
| **Body** | `0x004bfd10`–`0x004bfda1` inclusive (**146 B** / `0x92`); pad `CC` then `FUN_004bfdb0` |
| **Canonical name** | `TrackMgr_9CircList_UntrackObject_Inferred` (**Inferred**); Ghidra `FUN_004bfd10` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_004bfd10_TrackMgr_9CircList_UntrackObject_Inferred.md` |
| **System** | Client object/graphics track manager (host field `+0xE914`) |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `read_memory`, xrefs, `get_assembly_context`, sibling `004bfdb0`, predicate `005c6720` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CF/ABI/`ret 4`/9-bucket unlink sealed; product manager English open |
| **Dual status** | **Present (W37-T)** |

---

## 1. Purpose

**Untrack / remove** the first list node whose **payload** matches a target **object**, from a manager owning **nine** circular doubly-linked list buckets.

```
// __thiscall manager; stack (object*); ret 4; returns 1 if removed else 0
for (i = 0; i < 9; ++i) {
  bucket = manager + 8 + i*0xC;   // head@+0, count@+4
  if (count == 0) continue;
  for (n = head->next; n != head; n = n->next) {
    payload = n->payload;         // node+8
    if (FUN_005c6720(payload, object)) {
      if (n == head) {            // defensive / unreachable under sentinel walk
        if (payload) payload->vtbl[0](1);
        return 1;
      }
      unlink(n);                  // standard prev/next rewire
      operator_delete(n);
      count--;
      if (payload) payload->vtbl[0](1);  // scalar-deleting dtor
      return 1;
    }
  }
}
return 0;
```

Primary consumer (W31-T sealed): `Object_UnloadGraphics_Inferred` (`0x005825d0`) loads  
`manager = *(*(MI_host_via_vb + 0xA8) + 0xE914)` into **ECX**, pushes **MI this**, calls this unit **before** graphics teardown.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra `batch_decompile` `0x004bfd10` (2026-08-04) |
| Complete analysis | 8 xrefs; 5 callers; callees `FUN_005c6720`, `operator_delete` |
| Machine | `read_memory` `0x004bfd10` length 256 → body **146 B** then `CC` |
| Predicate | `decompile_function` `0x005c6720` — identity / TFID-style match |
| Sibling | `FUN_004bfdb0` — same 9-bucket walk; sets `payload+0x51` on match |
| Parent dual | `A_aa_005825d0_Object_UnloadGraphics_Inferred` (manager this wiring) |
| Caller bytes | `get_assembly_context` @ `005825e7`, `00854d6d`, `008d8112` |
| Scaffold | `raw/aa_004bfd10_*`, `reconstructed-exact/FUN_004bfd10.cpp` |

**Not performed:** Launcher, runtime golden, dual of every caller body, parent ledger edits.

---

## 3. Machine seal (`read_memory`)

| Claim | Evidence | Conf |
|---|---|---|
| Saves this; bucket base `lea ebx,[ecx+8]` | `89 4c 24 10` / `8d 59 08` | **Confirmed** |
| Skip empty: `cmp [ebx+4],0` | count at bucket+4 | **Confirmed** |
| Circular walk `n=*head; while n!=head` | `8b 03; 8b 30; 3b f0` + loop `8b 36; 3b 33` | **Confirmed** |
| Match call: `mov ecx,payload; push object; call 005c6720` | `8b 7e 08` … `e8 e1 69 10 00` | **Confirmed** |
| 9 buckets, stride `0xC` | `add ebp,1; add ebx,0xC; cmp ebp,9; jb` | **Confirmed** |
| Fail: `xor al,al; ret 4` | `32 c0` … `c2 04 00` | **Confirmed** |
| Unlink + `operator_delete` **returns** | `e8 …; 83 c4 04` then count-- | **Confirmed** (decompiler wrong) |
| `count--` after free | `83 43 08 ff` with ebx rebased to `this+4+i*12` → bucket+4 | **Confirmed** |
| Payload scalar dtor `push 1; call [vtbl]` | `6a 01; 8b cf; ff 12` | **Confirmed** |
| Success `mov al,1; ret 4` | `b0 01` … `c2 04 00` | **Confirmed** |
| Body 146 B | end @ `0x004bfda1`; next fn `004bfdb0` | **Confirmed** |

Full hex (146 B):

```
5153555657894c241033ed8d59088bff837b040074238b038b303bf0741b8bff8b7e088b442418508bcfe8e169100084c0751b8b363b3375e783c50183c30c83fd0972cc5f5e5d32c05b59c204008b5424108d4c6d003b748a088d5c8a04741c8b46048b0e89088b168b460456894204e89d9afcff83c404834308ff85ff74088b176a018bcfff125f5e5db0015b59c20400
```

---

## 4. Layout contract

### Manager

| Offset | Role |
|---|---|
| `mgr+0x08 + i*0xC + 0` | circular list head/sentinel |
| `mgr+0x08 + i*0xC + 4` | element count (0 → skip bucket) |
| `i ∈ [0,9)` | nine parallel lists |

### List node

| Offset | Role |
|---|---|
| `+0` | next |
| `+4` | prev |
| `+8` | payload* (matched via `005c6720`, owned-deleted on remove) |

---

## 5. Callers / callees

| Direction | Detail |
|---|---|
| Callees | `FUN_005c6720`, `operator_delete`, payload `vtbl[0](1)` |
| Callers | `005825d0` (UnloadGraphics), `00854d20`, `00855810`, `00856380`, `008d80c0` (×4) |
| ECX source | consistently host path → `+0xE914` manager (bytes; decompiler often drops) |

---

## 6. Confidence table

| Claim | Level |
|---|---|
| 9-bucket circular walk | **Confirmed** |
| `__thiscall` + `ret 4` + bool AL | **Confirmed** |
| Match via `005c6720(payload, object)` | **Confirmed** |
| Unlink + free node + count-- + payload dtor | **Confirmed** |
| Decompiler noreturn on delete is wrong | **Confirmed** |
| Role = manager untrack by object match | **High** |
| Product manager / payload class names | **Open** |
| head==node special path meaning | **Tentative** (likely dead under sentinel invariant) |

---

## 7. Gaps

1. Product name for manager at host`+0xE914`.  
2. Payload type / track-entry English.  
3. Bucket index semantics (why 9).  
4. Sibling `004bfdb0` product role.  
5. Runtime / differential.

**Verdict:** **accept-with-gaps**
