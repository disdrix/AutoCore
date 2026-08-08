# Review A (reconstruction fidelity): `aa_0051a120` Faction_LookupById

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051a120` |
| **VA** | `0x0051a120`–`0x0051a16a` exclusive end `0x0051a16b` (**75 B** / `0x4B`) |
| **Canonical name** | `Faction_LookupById` |
| **Ghidra name** | `FUN_0051a120` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9R-G) |
| **Counterpart** | `reviews/B_aa_0051a120_Faction_LookupById.md` |
| **System** | game-data / faction table |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Faction-id → faction record\*** lookup in a global open-hash table:

1. Reject `(int)id < 0` → NULL.
2. If `DAT_00b04320 == 0`, lazy-load via `FUN_005197b0` (faction table builder; WQ9R-F).
3. Bucket: `*(DAT_00b04324 + (DAT_00b0431c & id)*4)`; chain head at `bucket+4`.
4. Walk nodes: key `@+0x10`, next `@+0x0C`; on match return **value `@+0x08`** (pointer, not deref).
5. Miss → NULL.

Caller seal:

- `FUN_00614380`: NULL → **`"UNDEFINED FACTION: %i"`**; hit uses `record+4` as display name.
- `FUN_00612df0`: NULL → **`"UNKNOWN: %i"`**; hit uses `record+4`; `*record` type 9/10 ⇒ Creatures label.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9R-G append) | `docs/reconstruction/raw/aa_0051a120_FUN_0051a120.md` |
| Annotated | `docs/reconstruction/raw/aa_0051a120_FUN_0051a120.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Faction_LookupById.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051a120.cpp` |
| Reject alias | `Named_CalleeOf_Drive_Vehicles_0051a120.cpp` (scaffold; too narrow) |
| Live body bytes | full 75 B via `read_memory` |
| Init peer | `FUN_005197b0` loads 0x64-byte rows + `FUN_0051e5d0` insert |
| Sibling contrast | `FUN_00519d20` different globals + returns `*value`; `FUN_0051a0e0` → `CNDHash_LookupByKey` |

---

## 3. Signature (sealed)

```c
// cdecl; stack factionId; bare RET
void* Faction_LookupById(uint32_t factionId);
```

| Formal | Source | Conf |
|---|---|---|
| factionId | `[esp+4]` after push (`8B 74 24 08`) | **High** |
| return | EAX = record* or NULL | **High** |
| cleanup | `5E C3` | **High** (cdecl) |

---

## 4. Control flow fidelity

| Stage | Match | Conf |
|---|---|---|
| Negative id gate | **Yes** (`test esi,esi; jl`) | **High** |
| Lazy `FUN_005197b0` | **Yes** | **High** |
| Mask + bucket + chain head +4 | **Yes** (bytes) | **High** |
| Key/next/value offsets | **Yes** | **High** |
| Return value@+8 not *value | **Yes** | **High** |
| Faction role (caller strings) | **Yes** | **High** |
| Product record type name | open | — |

**Clean ≡ raw CF.** Full body sealed by `read_memory` hex.

---

## 5. Machine bytes (`read_memory`)

| Region | Bytes / note |
|---|---|
| Entry | `56 8B 74 24 08 85 F6 7C 39` |
| Ready gate | `83 3D 20 43 B0 00 00 75 05 E8 …` → `FUN_005197b0` |
| Mask/buckets | `A1 1C 43 B0 00` / `8B 0D 24 43 B0 00` / `23 C6` |
| Exits | `5E C3` (miss/neg), `8B 40 08 5E C3` (hit) |
| Size | **75 B**; pad `CC` |

**No `disassemble_bytes` used.**

---

## 6. Confidence table

| Claim | Level |
|---|---|
| Faction lookup role | **High** (caller string) |
| cdecl + stack id | **High** |
| Hash node offsets | **High** |
| Lazy init dependency on `005197b0` | **High** |
| Record field English beyond name@+4 | **Tentative** |
| `DAT_00b04320` count vs bool | **Probable** (tested `==0` only) |
| Runtime / bit-exact | **Open** |

---

## 7. Verdict

**accept-with-gaps** — leaf lookup CF/ABI/globals/caller-sealed faction role complete; product record layout English open.
