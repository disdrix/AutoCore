# Review A (reconstruction fidelity): `aa_00569560` StdMap_InsertWithHint_IntKey_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00569560` |
| **VA** | `0x00569560` |
| **Body span** | `00569560` – `005696c3` (**356 bytes**) |
| **Canonical name** | `StdMap_InsertWithHint_IntKey_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00569560` |
| **Review date** | `2026-07-29` (W21-G dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00569560_StdMap_InsertWithHint_IntKey_Inferred.md` |
| **System** | container / MSVC map insert-with-hint |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

MSVC-style **ordered map/set insert-with-hint by int key**:

1. Empty tree → RB-insert as first node under head.
2. Hint = leftmost / end → direct insert when key order allows.
3. Interior hint → predecessor or successor check; insert with `addLeft` from isnil(`right`).
4. Invalid hint → full **insert-or-find** (`FUN_00569320`) and copy iterator out.

Sibling of sealed `StdMap_InsertOrFindByIntKey_Inferred` @ `0x00569320` (this unit is the **hint path** that *calls* that fallback). Insert physical path throws `"map/set<T> too long"` via `FUN_005690a0`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00569560` |
| Bytes | `read_memory` 256 B @ entry + 100 B @ `0x00569660` — `sub esp,8`; multi `ret 0x0C` |
| Bounds | `get_function_by_address` body `00569560`–`005696c3` |
| Callers | `get_function_callers` → sole `FUN_005697d0` |
| Callees | `FUN_005690a0`, `FUN_00537770`, `FUN_00568200`, `FUN_00569320` |
| Context | decompile parent `005697d0`, insert `005690a0` (plate `"map/set<T> too long"`), fallback dual `00569320` |
| Raw / clean | `aa_00569560_*`, `StdMap_InsertWithHint_IntKey_Inferred.cpp` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| **ECX** | map shell `this` | `mov edi,ecx`; size `[edi+8]`; head `[edi+4]` |
| **`[esp+4]`** | out iterator* | written on all success paths |
| **`[esp+8]`** | hint node* | compared to `*head` / head |
| **`[esp+0xC]`** | `int *pKey` | compare vs `node[3]`; insert payload |
| **Return** | `outIt` (EAX=ESI) | `ret 0x0C` |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body **356 bytes** + `ret 0x0C` | **Confirmed** | bounds + byte count |
| Hinted-insert CF | **High** | decompile ≡ raw; matches MSVC hint pattern |
| Key at `node+0x0C`, isnil `+0x49` | **High** | shared dual family |
| map/set family | **High** | insert plate string in callee |
| Fallback to `00569320` | **Confirmed** | call site ~`005696ad`; dual A notes sole reverse xref |
| Sole parent `005697d0` | **High** | 1 caller |
| Value payload size / domain | **Open** | parent zeros 0xE dwords + key |
| Product English symbol | **Inferred** | `_Tree::_Insert` class |
| Bit-for-bit / runtime / differential | **Open** | deferred |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Empty → insert left of head | Yes |
| Leftmost hint + key &lt; hint.key | Yes |
| End hint + rightmost.key &lt; key | Yes |
| Pred path + isnil(right) addLeft | Yes |
| Succ path (SBORROW4) + isnil(right) | Yes |
| Fallback InsertOrFind → *outIt | Yes |

### Recovered contract

```c
// __thiscall
Node** StdMap_InsertWithHint_IntKey(Map* map, Node** outIt, Node* hint, int* pKey);
// *outIt = inserted or existing node; returns outIt
```

---

## 6. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `FUN_005697d0` | lower-bound + insert → `*it+0x10` value |
| Callee | `FUN_005690a0` | RB insert / rebalance |
| Callee | `FUN_00537770` | Map_Predecessor (dual) |
| Callee | `FUN_00568200` | Map_Successor |
| Callee | `FUN_00569320` | InsertOrFind fallback (dual) |

---

## 7. Gaps / open

1. Owning map value type / full node size (0x4C alloc in factory is strong but not sealed here).
2. Product/PDB symbol string.
3. Runtime / bit-exact / differential.
4. Successor `FUN_00568200` dual seal residual (CF read for context only).

**Verdict:** **accept-with-gaps**
