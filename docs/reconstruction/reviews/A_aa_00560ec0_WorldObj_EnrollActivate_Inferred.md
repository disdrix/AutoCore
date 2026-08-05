# Review A (reconstruction fidelity): `aa_00560ec0` WorldObj_EnrollActivate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00560ec0` |
| **VA** | `0x00560ec0` |
| **Canonical name** | `WorldObj_EnrollActivate_Inferred` (structural) |
| **Ghidra name** | `FUN_00560ec0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00560ec0_WorldObj_EnrollActivate_Inferred.md` |
| **System** | npc-ai / spawn / world object management |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Activate / enroll** a world object into a manager (`this`): set reentrancy flag, bump manager counters from object kind flag, bind object, bump object refcount, notify.

Parent `CVOGSpawnPoint_SetObjectActiveState` (`0x00564700`) non-NPC arm:

```
if (desired_active && obj_slot != 0) {
  if (*(obj+8) == 0) FUN_00560ec0(obj);  // enroll when not already linked
  FUN_005070d0();
}
```

(Disable path uses sibling `FUN_00561450`.)

Recovered CF:

1. Save `*(this+0x12c)` (`+300`); set `*(this+0x12c) = 1` (reentrancy / deferred-remove flag used by `00561450`).
2. If `*(obj+0x40) == 0`: `counter = *(this+0x130)++` else `counter = *(this+0x134)--` (decompiler shows post-dec value written).
3. `*(obj+0x20) = counter` — stamp sequence / handle index onto object.
4. `FUN_0055e760(obj)`; `FUN_0055fa40(obj)` — bind/link helpers.
5. Restore `*(this+0x12c)`.
6. `*(short*)(obj+6) += 1` — refcount++.
7. `FUN_0062a450(this, obj)` — post-enroll notify.
8. Return `obj`.

**ABI:** `__thiscall` manager + object.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00560ec0_*`, `reconstructed-exact/FUN_00560ec0.cpp` |
| Function record | `functions/aa_00560ec0_FUN_00560ec0.md` |
| Fresh decompile | Ghidra `batch_decompile` @ `0x00560ec0` (2026-07-29) ≡ clean |
| Bytes | `read_memory` 48 B — `movsx` save `[esi+0x12c]`; `mov byte [esi+0x12c],1`; `cmp byte [edi+0x40],0` |
| Parent dual | `A_aa_00564700_CVOGSpawnPoint_SetObjectActiveState.md` |
| Sibling deactivate | `FUN_00561450` (this batch) |
| Callers (xrefs) | spawn/phys/net: `00564ab8`, `005931c0`, `004d8539`… (13 sites) |

**Not performed:** disassemble_bytes, Launcher, runtime, helper duals for 0055e760/0055fa40/0062a450.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| thiscall manager + object | **Confirmed** | ECX + stack |
| Flag `this+0x12c` save/set1/restore | **Confirmed** | bytes + body |
| Branch on `obj+0x40` for +0x130 vs +0x134 | **Confirmed** | body |
| Stamp `obj+0x20` with pre-inc/pre-use counter | **High** | body |
| Refcount at `obj+6` (short) ++ | **Confirmed** | body |
| Used by spawn SetObjectActiveState enable | **High** | parent |
| Product manager class English | **Open** | structural WorldObj |
| Exact counter semantics (free-list vs gen) | **Tentative** | |
| clean ≡ raw | **High** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Save flag; set 1 | Yes |
| +0x40 branch counters | Yes |
| Stamp +0x20; two bind helpers | Yes |
| Restore flag; ref++; notify | Yes |
| Return object | Yes |

### Recovered CF

```c
// Object* __thiscall WorldObj_EnrollActivate(Manager* m, Object* obj)
uint8_t prev = m->flag_12c;
m->flag_12c = 1;
int stamp;
if (obj->byte_40 == 0) stamp = m->cnt_130++;
else                   stamp = m->cnt_134--;  // decompiler: write iVar2 then --
obj->field_20 = stamp;
BindA_0055e760(obj);
BindB_0055fa40(obj);
m->flag_12c = prev;
obj->ref_short_6++;
Notify_0062a450(m, obj);
return obj;
```

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `CVOGSpawnPoint_SetObjectActiveState` | non-NPC enable |
| Caller | multiple phys/spawn/net sites | enroll elsewhere |
| Callee | `FUN_0055e760`, `FUN_0055fa40` | object bind |
| Callee | `FUN_0062a450` | post-enroll |

---

## 6. Gaps / open

1. Product class names for manager / object.
2. Duals for bind helpers and `0062a450`.
3. Why `+0x40` chooses +0x130 vs +0x134 (kind / pool).
4. Runtime activate capture.

**Verdict:** **accept-with-gaps** — enroll CF + flag/refcount sealed; product names Open.
