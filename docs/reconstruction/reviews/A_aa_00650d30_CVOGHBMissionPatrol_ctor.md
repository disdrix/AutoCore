# Review A (reconstruction fidelity): `aa_00650d30` CVOGHBMissionPatrol_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00650d30` |
| **VA** | `0x00650d30` |
| **Body** | `0x00650d30`–`0x00650dd4` (**164 bytes**) |
| **Canonical name** | `CVOGHBMissionPatrol_ctor` |
| **Ghidra name** | `FUN_00650d30` |
| **Review date** | `2026-07-29` (W23-T dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00650d30_CVOGHBMissionPatrol_ctor.md` |
| **System** | missions-progression / mission-patrol HB |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

**In-place construct** a mission-patrol heartbeat on a pre-allocated **0x40-byte** buffer. Parent `CVOGObjectiveRequirement_Patrol_InitActive` allocates, constructs via this unit, enqueues on continent HB list `+0xe4ec`, then `CVOGHBBase_Start`.

| Step | Action |
|------|--------|
| 1 | `CVOGHBBase_ctor(this)` |
| 2 | Install vftable `PTR_FUN_009e52e4` |
| 3 | Copy requirement-derived fields |
| 4 | Type token `this+0x1C = 0xC` |
| 5 | `SetPeriodAndCounter(this, -1000, true)` |
| 6 | MI-adjust optional owner; `AttachOwnerObject` |
| 7 | Pulse `this+0x08 = 1000`; return this |

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00650d30` |
| Bytes | `read_memory` 256 B @ entry — body through `ret 8` |
| Bounds | `get_function_by_address` body `00650d30`–`00650dd4` |
| Callers / callees | `get_function_callers` / `get_function_callees` |
| Vftable | `read_memory` @ `0x009e52e4` (slots include Fn3/Fn6) |
| Parent | `CVOGObjectiveRequirement_Patrol_InitActive` dual |
| Raw / clean | `aa_00650d30_*`, `CVOGHBMissionPatrol_ctor.cpp` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body **164 B**, `ret 8` | **Confirmed** | `read_memory` epilogue `83 c4 10 c2 08 00` |
| thiscall + 2 stack args | **Confirmed** | parent `FUN_00650d30(owner, req)` on new(0x40) |
| Vftable `0x009e52e4` | **Confirmed** | `c7 06 e4 52 9e 00` |
| Type `0xC` at `+0x1C` | **Confirmed** | `c7 46 1c 0c 00 00 00` |
| SetPeriodAndCounter(-1000, true) | **Confirmed** | push 1; push 0xfffffc18; call |
| Pulse `+0x08 = 1000` after attach | **Confirmed** | `c7 46 08 e8 03 00 00` |
| MI owner adjust when non-null | **Confirmed** | `+ *( *(p+4)+4 ) + 4` |
| Sole static caller Patrol_InitActive | **Confirmed** | callers API |
| Product English class name | **Inferred** | family siblings + parent naming |
| Req field / vtbl+0x58 meaning | **Tentative** | offsets sealed; product open |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH frame + base ctor | **Yes** |
| Vftable install | **Yes** |
| Requirement field copies | **Yes** |
| Type 0xC | **Yes** |
| SetPeriodAndCounter(-1000, true) | **Yes** |
| Owner null-check + MI adjust + Attach | **Yes** |
| Pulse 1000; restore ExceptionList; return this | **Yes** |

### Recovered CF

```c
void *CVOGHBMissionPatrol_ctor(void *self, void *owner, int *req) {
  CVOGHBBase_ctor(self);
  *(void **)self = &PTR_FUN_009e52e4;
  self_u32[9]  = (*req->vtbl+0x58)(req);
  self_u32[10] = *(u32 *)(req[1] + 0x10);
  self_u32[0xc] = req[0xc];
  self_u32[0xd] = req[0xd];
  self_u32[0xe] = req[7];
  self_u32[7]   = 0xC;
  CVOGHBBase_SetPeriodAndCounter(self, -1000, true);
  if (owner) owner = owner + *(*(owner+4)+4) + 4;
  CVOGHBBase_AttachOwnerObject(self, owner);
  self_u32[2] = 1000;
  return self;
}
```

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `CVOGObjectiveRequirement_Patrol_InitActive` | alloc 0x40 → ctor → enqueue → Start |
| Callee | `CVOGHBBase_ctor` | base init |
| Callee | `CVOGHBBase_SetPeriodAndCounter` | `+0x0C`/`+0x10` = -1000 |
| Callee | `CVOGHBBase_AttachOwnerObject` | owner at `+0x18` |

---

## 6. Gaps / open

1. Product/PDB demangled class name (MissionPatrol is **family-inferred**).
2. Exact semantic of requirement `vtbl+0x58`, `req[7]`, and TFID-like `req[0xC]/[0xD]`.
3. Runtime / bit-exact / differential.
4. Full vftable slot taxonomy beyond Fn3/Fn6/Tick siblings.

**Verdict:** **accept-with-gaps**
