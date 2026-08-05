# Review A (reconstruction fidelity): `aa_00512440` Object_GetRootRaceId

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512440` |
| **VA** | `0x00512440` |
| **Canonical name** | `Object_GetRootRaceId` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_00512440_Object_GetRootRaceId.md` |
| **System** | object / faction |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Leaf helper: given a cloned-object base pointer, **walk the owner chain** at field **`+0xAC`** until the pointer is null, then return the **DWORD at root `+0x10`** typed as `RACE_ID_INFERRED` (faction / race id). Used for proactive AI neutral bail, hostility gating, regen period pick (0/1/2 → 3000 ms), spawn faction apply pairing with writer `FUN_00512460` (not owned).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00512440_Object_GetRootRaceId.md` |
| Annotated | `docs/reconstruction/raw/aa_00512440_Object_GetRootRaceId.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_GetRootRaceId.cpp` |
| Function record | `docs/reconstruction/functions/aa_00512440_Object_GetRootRaceId.md` |
| Live tools | Ghidra `decompile_function`, `read_memory`, `get_function_pcode`, `analyze_function_complete`, `get_enum_values` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__fastcall` / `this` in **ECX** | **High** | Signature + pcode CAST of register offset 4 (ECX) |
| Return in **EAX**, type 4-byte `RACE_ID_INFERRED` | **High** | Type size 4; RETURN copies LOAD into EAX |
| Owner field **`object+0xAC`** (pointer) | **High** | Bytes `8B 81 AC 00 00 00`; pcode `INT_ADD` const `0xac` + LOAD |
| Race/faction field **`object+0x10`** (DWORD) | **High** | Bytes `8B 41 10`; pcode `INT_ADD` const `0x10` + LOAD |
| Walk until owner **NULL**; use **last non-null** as root | **High** | Loop; if first owner null, root = original ECX |
| **No null-check on `pObject`** | **High** | Entry immediately loads `[ecx+0xac]` |
| **Leaf** — no callees | **High** | `callees: []`; ends `C3` ret |
| Body range **`00512440`–`0051245f`** (32 bytes) | **High** | Function bounds + hex decode |
| Clean ≡ decompile control flow | **High** | Same while-walk + return |
| Product name “race id” / faction at +0x10 | **High** | Callers compare to race enum / −100 / ~Human |
| `RACE_HUMAN/BIOMEK/TRIBE = 0/1/2` enum members | **High** | Ghidra enum `RACE_ID_INFERRED` (caller domain; not body) |
| Sentinel **−100** (`0xFFFFFF9C`) = Neutral (caller) | **High** | Live `CVOGHBAIBase_FindTargetToAttack` compares return |
| Sentinel **~0 (−1)** special “NPC” faction (caller) | **Probable** | Hostility path `FUN_005c9450`; NPC.md / tFactions note |
| Null-terminated owner chain always well-formed | **Tentative** | No cycle guard; infinite loop if cycle |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| `eax = *[ecx+0xAC]` | **Yes** |
| if `eax==0` → skip loop | **Yes** (`test/jz`) |
| loop: `ecx=eax; eax=*[ecx+0xAC]; jnz` | **Yes** |
| `eax = *[ecx+0x10]; ret` | **Yes** |
| No invented null-object guard | **Yes** |

### Byte seal (`read_memory` @ `0x00512440`, length 32)

```
8B 81 AC 00 00 00   mov eax, [ecx+0xAC]
85 C0               test eax, eax
74 12               jz  short ret_path     ; 0051245c
8D 9B 00 00 00 00   lea ebx, [ebx+0]       ; alignment nop
8B C8               mov ecx, eax
8B 81 AC 00 00 00   mov eax, [ecx+0xAC]
85 C0               test eax, eax
75 F4               jnz short loop
8B 41 10            mov eax, [ecx+0x10]
C3                  ret
```

Adjacent sibling at **`0x00512460`** (`FUN_00512460`) **writes** `+0x10` along the same `+0xAC` chain (spawn faction apply). Not owned; pairing only.

---

## 5. Gaps / open

1. Product struct field names for `+0xAC` (owner) and `+0x10` (race/faction) beyond offset seal.
2. Full product race enum beyond Human/Biomek/Tribe (other positive ids → 5000 ms regen path).
3. Whether `+0x10` is pure race vs clonebase faction id (docs say both; body is opaque load).
4. Cycle / corrupt-chain behavior (no guard).
5. Runtime / bit-exact vs retail EXE image.
6. Duplicate scaffold records under `FUN_00512440` naming (canonical is `Object_GetRootRaceId`).

**Verdict:** **accept-with-gaps**
