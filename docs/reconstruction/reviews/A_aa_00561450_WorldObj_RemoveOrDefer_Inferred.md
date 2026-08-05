# Review A (reconstruction fidelity): `aa_00561450` WorldObj_RemoveOrDefer_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00561450` |
| **VA** | `0x00561450` |
| **Canonical name** | `WorldObj_RemoveOrDefer_Inferred` (structural) |
| **Ghidra name** | `FUN_00561450` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00561450_WorldObj_RemoveOrDefer_Inferred.md` |
| **System** | npc-ai / spawn / world object management |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Remove / deactivate** a world object from a manager — **or defer** the remove if reentrancy flag `manager+0x12c == 1` (set by enroll `FUN_00560ec0` and similar nested paths).

Parent `CVOGSpawnPoint_SetObjectActiveState` non-NPC disable:

```
if (!desired_active && obj && *(obj+8))
  FUN_00561450(&outByte, obj_ptr);
```

### Branch A — deferred (flag == 1)

1. If deferred queue full (`count@+0xf4 == capacity@+0xf8 & 0x7fffffff`): `FUN_005b3370(this+0xf0, 4)` grow.
2. Push `obj` onto pointer vector at `this+0xf0` / index `+0xf4`.
3. `*(short*)(obj+6)++` — hold ref while deferred.
4. `*outFlag = 0` — signal “not fully removed yet”.
5. Return.

### Branch B — immediate teardown (flag != 1)

1. If `*(this+0x24) > 0`: `FUN_00561320()` (extra manager work).
2. `FUN_0055fbf0(obj)`; `FUN_0062a490(this, obj)`; `FUN_005ffff0(obj)`; `FUN_0055fd80(obj)` — unbind chain (mirror of enroll binds).
3. `*(short*)(obj+6)--`; if refcount hits **0**: `(*obj->vtbl)(1)` — destroy (`operator delete` style vcall with 1).
4. `*outFlag = 1` — fully removed.

**ABI:** `__thiscall` manager; `param_2` = out byte*; `param_3` = object*.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00561450_*`, `reconstructed-exact/FUN_00561450.cpp` |
| Function record | `functions/aa_00561450_FUN_00561450.md` |
| Fresh decompile | Ghidra `batch_decompile` @ `0x00561450` (2026-07-29) ≡ clean |
| Sibling enroll | `FUN_00560ec0` / dual this batch |
| Parent dual | `A_aa_00564700_CVOGSpawnPoint_SetObjectActiveState.md` |
| Callers | spawn/phys: `00591064`, `00564add`, `0053d761`, `004cd8c0`, … (14 sites) |

**Not performed:** disassemble_bytes, Launcher, runtime, unbind-helper duals.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Gate `this+0x12c == 1` → defer queue | **Confirmed** | body |
| Queue at `+0xf0/+0xf4/+0xf8`; grow `005b3370` | **Confirmed** | body |
| Defer path ref++ and `*out=0` | **Confirmed** | body |
| Immediate path unbind quartet + ref-- | **Confirmed** | body |
| Destroy via vtbl[0](1) when ref==0 | **Confirmed** | body |
| `*out=1` on immediate complete | **Confirmed** | body |
| Polarity = remove vs enroll 00560ec0 | **High** | parent disable |
| Product manager / queue English | **Open** | |
| Unbind helper exact roles | **Tentative** | sealed as unbind family |
| clean ≡ raw | **High** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Flag==1 → queue + ref++ + out0 | Yes |
| Else optional 00561320 | Yes |
| Unbind chain | Yes |
| Ref--; destroy if 0; out1 | Yes |

### Recovered CF

```c
// void __thiscall WorldObj_RemoveOrDefer(Manager* m, uint8_t* outDone, Object* obj)
if (m->flag_12c == 1) {
  if (m->qCount == (m->qCap & 0x7fffffff)) GrowQueue(m->qVec, 4);
  m->qVec[m->qCount++] = obj;
  obj->ref6++;
  *outDone = 0;
  return;
}
if (m->field_24 > 0) FUN_00561320();
Unbind_0055fbf0(obj);
NotifyRemove_0062a490(m, obj);
Unbind_005ffff0(obj);
Unbind_0055fd80(obj);
if (--obj->ref6 == 0) obj->vtbl[0](obj, 1);
*outDone = 1;
```

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `CVOGSpawnPoint_SetObjectActiveState` | non-NPC disable |
| Caller | multiple spawn/phys sites | remove |
| Callee | `FUN_005b3370` | queue grow |
| Callee | `FUN_00561320` | conditional manager work |
| Callee | `0055fbf0` / `0062a490` / `005ffff0` / `0055fd80` | unbind / notify |
| Callee | object vtbl[0] | destroy when ref 0 |

---

## 6. Gaps / open

1. Who drains the deferred queue at `+0xf0` after flag clears.
2. Product names; exact unbind helper duals.
3. `FUN_00561320` when `+0x24 > 0`.
4. Runtime deactivate capture.

**Verdict:** **accept-with-gaps** — defer vs immediate remove CF sealed High.
