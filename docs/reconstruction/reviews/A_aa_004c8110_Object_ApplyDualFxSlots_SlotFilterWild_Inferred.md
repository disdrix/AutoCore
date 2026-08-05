# Review A (reconstruction fidelity): `aa_004c8110` Object_ApplyDualFxSlots_SlotFilterWild_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c8110` |
| **VA** | `0x004c8110` |
| **Body** | `0x004c8110`–`0x004c81e5` (214 bytes) |
| **Canonical name** | `Object_ApplyDualFxSlots_SlotFilterWild_Inferred` |
| **Prior scaffold** | `FUN_004c8110` |
| **Review date** | `2026-07-29` (W25-D dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004c8110_Object_ApplyDualFxSlots_SlotFilterWild_Inferred.md` |
| **System** | client-fx / dual effect-slot apply |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Apply owned-bit7 FX toggle for **two effect pointer slots** using slot-filter wild pack `(0, effect, 1, -1)` via table-pair fan-out + local host* vector, then **tail-chain** sibling apply `FUN_00584330`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x004c8110` |
| Bytes | `read_memory` 256 B — dual blocks, calls, tail jmp |
| Bounds | `get_function_by_address` `004c8110`–`004c81e5` |
| Callees | `00583f10`, `004b7030`, `00584330` |
| Callers | xrefs MI thunks `004cce83`, `0053bc49` |
| Nested seals | W24-D `004b7030`; this dual `00583f10` |
| Chain peek | decompile `00584330` (context only; not owned) |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| thiscall `mov esi,ecx` | **Confirmed** | |
| Slots `-0x27c` / `-0x280` | **Confirmed** | |
| `00583f10` this = `self-0x4c0` | **Confirmed** | `lea ecx` |
| Arg pack `(0, effect, 1, -1)` | **Confirmed** | push order |
| Local vector `-0x3c4/-0x3c0` | **Confirmed** | |
| `004b7030` host = *it | **Confirmed** | `mov ecx,[edi]` |
| Tail jmp `00584330` @ `self-0x430` | **Confirmed** | rel32 |
| Product slot English | **Inferred** | |
| Chain full dual | Out of scope | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Gate effect A | Yes |
| Fan-out A + local hosts A | Yes |
| Gate effect B | Yes |
| Fan-out B + local hosts B | Yes |
| Tail chain | Yes |

### 4.1 Sealed contract

```
// thiscall; tail jmp
void Object_ApplyDualFxSlots_SlotFilterWild_Inferred(void *self);

// for effect in {*(self-0x27c), *(self-0x280)} if non-null:
//   ForEachHostPtrTablePair(self-0x4c0, 0, effect, 1, -1)
//   for host in local_vector: ForEachOwnedBit7(host, 0, effect, 1, -1)
// jmp FUN_00584330(self-0x430)
```

---

## 5. Gaps / open

1. Product class / dual-slot member names.
2. Full dual of `FUN_00584330` (sibling; filter char 0 path).
3. Semantic mapping of effect* into want_stop (forwarded).
4. Runtime / bit-exact / differential.

**Verdict:** **accept**
