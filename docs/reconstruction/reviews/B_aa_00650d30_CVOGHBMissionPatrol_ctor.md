# Review B (skeptical / adversarial): `aa_00650d30` CVOGHBMissionPatrol_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00650d30` |
| **VA** | `0x00650d30` |
| **Canonical name** | `CVOGHBMissionPatrol_ctor` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W23-T) |
| **Counterpart** | `reviews/A_aa_00650d30_CVOGHBMissionPatrol_ctor.md` |
| **System** | missions-progression / mission-patrol HB |
| **Live tools** | Ghidra `decompile_function` + `read_memory` only |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is a free-function factory (returns new heap) | Parent `operator_new(0x40)` then call with this=buffer; body returns `this` | **Falsified** factory — in-place ctor |
| 2 | Allocates internally | No `operator_new` in callees | **Falsified** |
| 3 | Type token is 0 / skill / cast-again | Writes imm **`0xC`** to `+0x1C` | **Falsified** non-0xC type |
| 4 | Period pulse is set only via SetPeriodAndCounter | SetPeriod writes `+0x0C`/`+0x10`; body later writes **`+0x08=1000`** separately | **Agree split** — two fields |
| 5 | Owner always required | Null-check skips MI adjust; still calls Attach with null | **Falsified** always-required |
| 6 | Owner pointer used as-is (no MI) | Explicit `+ *( *(p+4)+4 ) + 4` when non-null | **Falsified** raw-owner claim |
| 7 | Unrelated to MissionPatrol family | Vftable slots include `0x00650e50` Fn3 / `0x00650de0` Fn6 | **Falsified** unrelated |
| 8 | stdcall / no this | ECX=this; `ret 8` | **Falsified** pure stdcall |
| 9 | Product English name proven | Structural + parent/sibling only | **Agree Open** |
| 10 | Starts the HB (calls Start) | Parent calls Start after enqueue | **Falsified** — ctor only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| In-place ctor + ret this | **Confirmed** | Double-free / wrong ownership port |
| Type 0xC / pulse 1000 / sentinel -1000 | **Confirmed** | Wrong HB schedule in server port |
| Vftable family bind | **High** | Mis-bind tick/end handlers |
| Requirement field product meaning | **Open** | Wrong mission fail/resolve data |
| Class English name | **Open** | Naming only |

---

## 3. Cross-check against raw / live / bytes

Decompile order matches entry hex:

```
push SEH; mov esi,ecx
call CVOGHBBase_ctor
mov [esi], 0x009e52e4
... call [req.vtbl+0x58]; store fields ...
mov [esi+0x1c], 0xC
push 1; push -1000; call SetPeriodAndCounter
test owner; jz skip_mi; lea/adjust; push owner
call AttachOwnerObject
mov [esi+8], 1000
pop; mov eax,esi; add esp,10; ret 8
```

**Trap:** decompiler `param_1` is **this** (not a separate out-buffer). Ports must construct into caller-owned 0x40.

**Trap:** `-1000` is sentinel for `+0x0C`/`+0x10` (SetPeriodAndCounter), **not** the pulse at `+0x08` (which is +1000). Do not collapse these.

**Trap:** owner MI adjust is the complete-object → HB-owner subobject conversion used across HB ctors; dropping it attaches the wrong pointer.

---

## 4. Surviving contract for AutoCore

```c
// Port of CVOGHBMissionPatrol_ctor (aa_00650d30)
// Retail: thiscall; ECX=prealloc 0x40; stack owner, requirement; ret 8; returns this
struct PatrolHb {
  void *vtbl;           // +0x00 → MissionPatrol table
  // ... base ...
  int pulse_ms;         // +0x08 = 1000
  int period_sentinel;  // +0x0C = -1000
  int period_counter;   // +0x10 = -1000
  void *owner;          // +0x18 via AttachOwnerObject
  int type;             // +0x1C = 0x0C
  // +0x24..+0x38 requirement copies
};

void *CVOGHBMissionPatrol_ctor(void *self, void *owner_complete, void *requirement);
```

- Server: allocate patrol HB object (size ≥ 0x40), construct, enqueue on continent HB list, Start — mirror parent `Patrol_InitActive`.
- Do **not** invent fail/complete logic here; that lives in Fn3/Fn6/Tick.
- Keep type **0xC** consistent with `EvaluatePendingObjectives` payload path **0xb** siblings (separate token).

---

## 5. Open questions

1. Product/PDB name.
2. Whether `vtbl+0x58` is GetObjectiveId / GetMissionId / other.
3. Runtime: construct → Start → first tick schedule with period 1000.

**Verdict:** **accept-with-gaps**
