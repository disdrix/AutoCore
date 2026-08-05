# Review A (reconstruction fidelity): `aa_00518ca0` Skill_InsertActiveCastBinding_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518ca0` |
| **VA** | `0x00518ca0`–`0x00518ce4` (**0x44** bytes; `ret 0x14`) |
| **Canonical name** | `Skill_InsertActiveCastBinding_Inferred` |
| **Ghidra name** | `FUN_00518ca0` |
| **Prior alias** | `Named_CalleeOf_Skill_Skill_d_has_invalid_frequency_d_00518ca0` (**reject**) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity (OWN-ONLY dual W24-H Path A) |
| **Counterpart** | `reviews/B_aa_00518ca0_Skill_InsertActiveCastBinding_Inferred.md` |
| **System** | skills-abilities |
| **Live tools** | `decompile_function`, `read_memory`, `get_function_by_address`, callers/callees/xrefs |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

**Tools note:** No `disassemble_bytes`. No Launcher. No parent ledgers.

---

## 1. Purpose

**Insert** an active-cast **skillId → TFID16** binding into the map at **mapOwner+0x68**:

```c
// __thiscall  ret 0x14
void Skill_InsertActiveCastBinding_Inferred(
    void *mapOwner, int skillId,
    uint32_t tfid0, uint32_t tfid1, uint32_t tfid2, uint32_t tfid3);
```

1. Frame `sub esp,0x18`; pack key @+0, **skip +4**, TFID dwords @+8…+0x14.
2. `map = FUN_00518c20(mapOwner)` — unary lazy getter (sibling leave-FUN dual).
3. `FUN_004cbe20(map, &outPair, &local)` — map insert-or-find; out discarded.
4. `add esp,0x18; ret 0x14`.

Sole static caller: `Skill_HB_FireTail_FxTargetAndPeriodStamp` @ `0x00578c55` when target `vtbl+0x214` returns non-null and `HB+0x639 & 0x02`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `decompile_function` @ `0x00518ca0` ≡ raw 2026-07-23 |
| Live bytes | `read_memory` full body 0x44 + epilogue `C2 14 00` |
| Call site | `read_memory` `0x00578bf0`… — `sub esp,10` TFID copy, `push skillId`, ECX formula, call |
| Map getter dual | `aa_00518c20` leave-FUN |
| Lookup / Clear duals | TFID16 @ node+0x18; find/erase family |
| Parent FireTail dual | `aa_00578b30` residual named this as open callee |
| Raw / clean | `raw/aa_00518ca0_*`, `reconstructed-exact/FUN_00518ca0.cpp` + named plate |

---

## 3. Authoritative body (bytes)

```text
00518ca0  SUB  ESP, 0x18
00518ca3  MOV  EAX, [ESP+0x1C]        ; skillId
00518ca7  MOV  EDX, [ESP+0x20]        ; tfid0
00518cab  MOV  [ESP], EAX             ; local+0 = key
00518cae  MOV  EAX, [ESP+0x24]        ; tfid1
00518cb2  MOV  [ESP+8], EDX           ; local+8 = tfid0  (GAP at +4)
00518cb6  MOV  EDX, [ESP+0x28]        ; tfid2
00518cba  MOV  [ESP+0xC], EAX
00518cbe  MOV  EAX, [ESP+0x2C]        ; tfid3
00518cc2  MOV  [ESP+0x10], EDX
00518cc6  LEA  EDX, [ESP]             ; &local
00518cc9  MOV  [ESP+0x14], EAX
00518ccd  PUSH EDX                    ; insert value*
00518cce  LEA  EAX, [ESP+0x24]        ; out-pair discard slot
00518cd2  PUSH EAX
00518cd3  CALL FUN_00518c20           ; ECX still = mapOwner
00518cd8  MOV  ECX, EAX               ; map*
00518cda  CALL FUN_004cbe20
00518cdf  ADD  ESP, 0x18
00518ce2  RET  0x14
```

ECX not written between entry and `CALL FUN_00518c20` → **entry ECX = mapOwner** (Confirmed).

---

## 4. Layout

### Insert local / node pair

| Off (local / pair) | Node off | Field |
|---|---|---|
| +0 | +0x10 | skillId key |
| +4 | +0x14 | pad (unwritten here) |
| +8…+0x14 | +0x18…+0x24 | TFID16 |

### Map (via getter)

| Off | Field |
|---|---|
| owner+0x68 | map* (lazy) |
| map+4 | head |
| map+8 | size |

---

## 5. Naming

| Candidate | Decision |
|---|---|
| `Skill_InsertActiveCastBinding_Inferred` | **Accept** — role High from map family + sole FireTail insert site; no product string → `_Inferred` |
| `FUN_00518ca0` | scaffold alias |
| `Named_CalleeOf_Skill_…frequency…` | **Reject** — frequency string lives in parent FireTail, not this VA |

---

## 6. Confidence

| Claim | Level |
|---|---|
| CF dual A ≡ raw ≡ live decompile | **Confirmed** |
| `ret 0x14` + five stack dwords | **Confirmed** |
| ECX mapOwner | **Confirmed** |
| Callees get-map + insert | **Confirmed** |
| Sole xref FireTail | **Confirmed** |
| TFID value @ node+0x18 | **High** (Lookup/Clear) |
| Product symbol | **Open** |
| Pad @+4 readers | **Open** |
| Runtime / bit-exact / diff | **Open** |

**Verdict:** **accept-with-gaps.**
