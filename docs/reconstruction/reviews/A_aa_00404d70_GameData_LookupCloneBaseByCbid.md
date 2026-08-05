# Review A (reconstruction fidelity): `aa_00404d70` GameData_LookupCloneBaseByCbid

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404d70` |
| **VA** | `0x00404d70`–`0x00404d7a` |
| **Canonical name** | `GameData_LookupCloneBaseByCbid` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (CBID clonebase lookup thunk) |
| **Counterpart** | `reviews/B_aa_00404d70_GameData_LookupCloneBaseByCbid.md` |
| **System** | clonebase / game data |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` `0x00404d70` + `read_memory` body + callees/callers/xrefs + call-site bytes (`0x0051a170`, `0x00564f80`). No `disassemble_bytes`. No ledgers / Launcher.

---

## 1. Purpose

Thin **game-data host method**: look up a **clonebase / item definition** by **CBID** in the `CNDHash` stored at `this+0xf10`. Implemented as a **tail-call thunk** into sealed `CNDHash_LookupByKey`.

Primary consumer patterns:
- Item factory (`CVOGReaction_GiveItemByCbid`) — null-check + switch on `def+0x38` type.
- Creature spawn (`CVOGSpawnPoint_CreateCreature`) — requires type `0x12` template.
- Mission collect UI — resolve item def name/fields from req CBID.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00404d70_FUN_00404d70.md` |
| Annotated | `docs/reconstruction/raw/aa_00404d70_FUN_00404d70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GameData_LookupCloneBaseByCbid.cpp` |
| Function record | `docs/reconstruction/functions/aa_00404d70_GameData_LookupCloneBaseByCbid.md` |
| Live Ghidra | decompile + `read_memory` + callers |
| Callee seal | `CNDHash_LookupByKey` `aa_005b0920` |
| Host global | `DAT_00b041fc` @ `0x00b041fc` (call-site ECX) |

---

## 3. Signature

```c
void * __thiscall GameData_LookupCloneBaseByCbid(void *this, uint32_t cbid);
// ECX = host; [esp+4] = cbid; RET 4 via Lookup; EAX = def* | NULL
```

| Item | Evidence |
|---|---|
| Body size | 10 B; range `00404d70`–`00404d7a` |
| Tail JMP | `E9 A5 BB 1A 00` → `0x005b0920` |
| Hash offset | `MOV ECX,[ECX+0xF10]` |
| Host load | GiveItem: `8B 0D FC 41 B0 00` (`DAT_00b041fc`); CreateCreature same |

---

## 4. Control flow (sealed)

```
// this in ECX, cbid already on stack
ECX = *(this + 0xf10)          // CNDHash*
goto CNDHash_LookupByKey       // returns value* or NULL; RET 4
```

No local branches, no SEH, no logging, no allocation.

---

## 5. Machine bytes (`read_memory` @ `0x00404d70`)

```
8B 89 10 0F 00 00    MOV  ECX, [ECX+0xF10]
E9 A5 BB 1A 00       JMP  rel32 → 0x005b0920
CC …                 padding
```

Hex: `8b89100f0000e9a5bb1a00`

---

## 6. Confidence

| Claim | Level |
|---|---|
| Tail thunk CF + bytes | **High** |
| Returns Lookup EAX (not void) | **High** |
| `+0xf10` is CNDHash* | **High** |
| Key = CBID | **High** (usage) |
| Value = clonebase def* | **High** (role from callers) |
| Host product class name | **Probable** |
| Runtime / bit-exact | **Open** |

---

## 7. Gaps (do not block seal)

1. Product class for `DAT_00b041fc`.
2. Whether hash is items-only vs full clonebase multimap (callers span types).
3. Runtime live verification.

---

## Verdict

**accept** — body is a fully sealed 10-byte tail thunk; ABI and `+0xf10` hash role are not ambiguous. Name is role-inferred (`GameData_…`) pending host PDB English.
