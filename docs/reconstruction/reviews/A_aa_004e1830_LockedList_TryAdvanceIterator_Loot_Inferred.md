# Review A (reconstruction fidelity): `aa_004e1830` LockedList_TryAdvanceIterator_Loot_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e1830` |
| **VA** | `0x004e1830` |
| **Body** | `0x004e1830`–`0x004e18dc` (**172 bytes**) |
| **Canonical name** | `LockedList_TryAdvanceIterator_Loot_Inferred` |
| **Ghidra name** | `FUN_004e1830` |
| **Review date** | `2026-07-29` (W23-T dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004e1830_LockedList_TryAdvanceIterator_Loot_Inferred.md` |
| **System** | combat-loot / locked list walk |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

**Advance a locked list cursor by one node** under the list's critical section, for loot/weapon table walks:

```
thiscall LockedList_TryAdvanceIterator_Loot_Inferred(list*, int* cursor, uint32_t* outPayload) → uint
```

| Return | Meaning |
|--------|---------|
| `0` | Node available: `*cursor` advanced/seeded, `*outPayload` = `node+4` |
| `1` | Exhausted (or empty start) |
| `0x80070005` | Flag `list+0x28==0` **or** `TryEnterCriticalSection` failed |

**Twin:** `List_IterateNext` / `LockedList_TryAdvanceIterator_Inferred` @ `0x004022a0` — same CF and offsets; twin installs SEH, this copy does not.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x004e1830` |
| Twin decompile | Ghidra `0x004022a0` (CF compare) |
| Bytes | `read_memory` 256 B @ entry — through `ret 8` / `0x80070005` exit |
| Bounds | `get_function_by_address` body `004e1830`–`004e18dc` |
| Callers | `get_function_callers` → `004d5c10`, `0050a7d0`, `0050aa80` |
| Parent context | `KillLoot_RollTableItems_Inferred` dual |
| Raw / clean | `aa_004e1830_*`, `LockedList_TryAdvanceIterator_Loot_Inferred.cpp` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body **172 B**, all exits `ret 8` | **Confirmed** | `read_memory` |
| Flag gate `list+0x28` | **Confirmed** | `80 7e 28 00` |
| CS at `list+4`, TryEnter IAT | **Confirmed** | `8d 6e 04; ff 15 a0 61 9c 00` |
| Head `list+0x1C`; payload `node+4`; next `node+8` | **Confirmed** | decompile + twin |
| Returns 0 / 1 / `0x80070005` | **Confirmed** | all paths |
| No SEH frame | **Confirmed** | prologue push ebx/ebp/esi/edi only |
| Twin of `0x004022a0` CF | **High** | live side-by-side |
| Loot domain from callers | **Probable** | kill-loot / weapon-group |
| Product list class name | **Open** | same family as inventory twin likely |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Require `+0x28 != 0` else `0x80070005` | **Yes** |
| `TryEnterCriticalSection(list+4)` fail → `0x80070005` | **Yes** |
| `*cursor==0`: seed head, payload head+4 or 0; return `(head==0)` | **Yes** |
| Else next=`cursor+8`; non-null → advance, payload next+4, return 0 | **Yes** |
| Else clear cursor/payload, return 1 | **Yes** |
| Leave CS on all success paths | **Yes** |
| No membership mutation | **Yes** |

### Layout (sealed offsets)

| Off | Role |
|----:|------|
| `list+4` | `CRITICAL_SECTION` |
| `list+0x1C` | head node ptr |
| `list+0x28` | traversal-lock flag (must be set) |
| `node+4` | payload out |
| `node+8` | next node |

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `KillLoot_RollTableItems_Inferred` `0x0050aa80` | kill loot table row walk |
| Caller | `FUN_0050a7d0` | loot residual |
| Caller | `FUN_004d5c10` | weapon-from-group residual |
| Callee | `TryEnterCriticalSection` | non-blocking lock |
| Callee | `LeaveCriticalSection` | unlock |

---

## 6. Gaps / open

1. Product English container type (`client::list` vs dedicated loot list).
2. Why a second copy without SEH (COMDAT / TU residual).
3. Runtime golden: lock → walk all rows → unlock wrapper.
4. Full taxonomy if more callers appear beyond the three sealed sites.

**Verdict:** **accept-with-gaps**
