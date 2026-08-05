# Review A (reconstruction fidelity): `aa_0092ce90` Client_RefreshMissionRelatedUi

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092ce90` |
| **VA** | `0x0092ce90` |
| **Canonical name** | `Client_RefreshMissionRelatedUi` (role; PDB unknown) |
| **Ghidra name** | `FUN_0092ce90` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0092ce90_Client_RefreshMissionRelatedUi.md` |
| **System tag** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0092ce90_FUN_0092ce90.md` |
| Annotated | `docs/reconstruction/raw/aa_0092ce90_FUN_0092ce90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0092ce90.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_RecvObjectiveState_0092ce90.cpp` |
| Function record | `docs/reconstruction/functions/aa_0092ce90_FUN_0092ce90.md` |
| Sibling dual | `A/B_aa_0092ce50_Client_HideMissionDialogIfOpen.md` |
| Parent residual | `reviews/a_00809460.md` (RecvObjectiveState) |
| Live Ghidra | `decompile_function 0x0092ce90`, `read_memory` 96 B prologue, `analyze_function_complete`, callers/xrefs |

**Purpose:** Post-mutation mission UI sync. Two fixed client panel slots only — no mission state math.

```text
// EDI = client context (thiscall ECX on each widget)
p = *(client + 0x107c)
if p && p->vtbl[+0xd0]() && p->vtbl[+0x3d8]():
    p->vtbl[+0x448]()

p = *(client + 0x10b8)
if p && p->vtbl[+0xd0]() && p->vtbl[+0x3d8]():
    *(byte*)(p + 0x520) = 1   // dirty; not vcall
```

Assembly confirms byte store `MOV BYTE PTR [ESI+0x520], 1` (not `int* + 0x148` as sole evidence — decompiler pointer scale is correct for dword ptr).

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Leaf: no named callees; only vtable / store | **High** | `callees:[]`; disasm ends `POP ESI; RET` |
| Client context in **EDI** | **High** | `unaff_EDI`; `MOV ESI,[EDI+0x107c]` / `+0x10b8` |
| Widget thiscall: **ECX** = panel before each vcall | **High** | `MOV ECX,ESI` before each `CALL [EAX/EDX+imm]` |
| Slot `client+0x107c` = mission UI root | **High** | Same as HideMissionDialogIfOpen / RecvObjectiveState |
| Gate `vtbl+0xd0` → bool | **High** (role open) | AL test; not present on Hide sibling |
| Gate `vtbl+0x3d8` → visible-style bool | **High** | Shared UI pattern |
| Action `vtbl+0x448` on primary only | **High** | Product name open (refresh vs hide tension — see gaps) |
| Secondary `client+0x10b8` dirty `@+0x520` | **High** | Assembly-sealed offset |
| **Not** EvaluatePending / CompleteObjective | **High** | Body + residual seal |
| Post-mutation UI sync role | **High** | 10 call sites across mission/inventory paths |
| Original PDB symbol | Open | Role name only |

---

## 3. Control flow: clean ≡ raw ≡ live decompile

| Stage | Match |
|---|---|
| Null-check `+0x107c` → `+0xd0` → `+0x3d8` → `+0x448` | **Yes** |
| Null-check `+0x10b8` → `+0xd0` → `+0x3d8` → byte `+0x520=1` | **Yes** |
| No other stores / calls / loops | **Yes** |
| Size ~0x60 bytes; `PUSH ESI` / `POP ESI` frame | **Yes** (`read_memory`) |

---

## 4. Callers (sealed list, 10 xrefs)

| Caller | VA | Context (high level) |
|---|---|---|
| `Client_RecvObjectiveState` | `0x00809460` | After 0x2071 slot write + toast mask |
| `Client_RecvInventoryAddItem` | `0x008151a0` | Post loot add |
| `Client_RecvInventoryDropResponse` | `0x00813730` | Drop path (2 call sites in same fn) |
| `FUN_00810170` | `0x00810170` | After `Client_RefreshOpenMissionUiWindows` |
| `FUN_008136b0` | `0x008136b0` | Drop-related; after `RefreshOpenMissionUiWindows` |
| `FUN_0093c3b0` | `0x0093c3b0` | Client helper |
| `FUN_00946c00` | `0x00946c00` | UI event switch case (case float-bit 5) |
| `FUN_00952bc0` | `0x00952bc0` | After `RefreshOpenMissionUiWindows` |
| `FUN_00955010` | `0x00955010` | Inventory/mission UI companion |

Several callers pair this with `Client_RefreshOpenMissionUiWindows` (`0x0093a940`) — broader multi-slot walk, then this dual-panel helper.

Sibling: `Client_HideMissionDialogIfOpen` @ `0x0092ce50` — same `+0x107c`, uses ESI for client, **no** `+0xd0` / **no** `+0x10b8`, calls `+0x448` **and** `+0x34c` when visible.

---

## 5. Gaps

1. Product/class names for widgets at `client+0x107c` and `+0x10b8`.
2. Exact meaning of `vtbl+0xd0` (active / ready / attached).
3. Exact meaning of `vtbl+0x448` — Hide dual labels “hide”; RecvObjectiveState / RefreshOpenMissionUiWindows use same offset as content refresh. Same base slot; product name still open.
4. What consumes dirty byte `panel+0x520` (deferred paint path).
5. Runtime / bit-exact / image diff open.
6. PDB original symbol open.

**Verdict:** Control flow and role sealed. **accept-with-gaps** — UI product names and `+0x448` semantics remain open; mission completion scheduling **not** this function.
