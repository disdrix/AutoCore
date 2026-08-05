# Review A (reconstruction fidelity): `aa_00989e00` ResourceCache_LookupByName

| Field | Value |
|---|---|
| **Stable ID** | `aa_00989e00` |
| **VA** | `0x00989e00` |
| **Canonical name** | `ResourceCache_LookupByName` (**INFERRED**) |
| **Aliases** | `FUN_00989e00`, named resource / string-handle resolve |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B — Equip nested residual) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00989e00_ResourceCache_LookupByName.md` |
| **System** | graphics resources / equip FX |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Resolve a **named resource handle** into an out-pointer (mesh/FX/effect objects):

1. If `name == null` **or** `name[0] == '\0'`: `*out = DAT_00d1eac0` (global default handle) and return.
2. Else try `FUN_00989b60(name, &local)` (fast path / already-cached).
3. If miss (`cVar2 == 0`):
   - Optional `EnterCriticalSection(this+0x68)` when `*(this+0x80) != 0`
   - `FUN_00996c80(name)` hash key; `FUN_00466da0(local, &key)` map insert/find
   - Optional `LeaveCriticalSection`
4. `*out = **resolved` (first dword of found node)

**Equip path:** `Vehicle_SetEquippedMeleeWeapon` after `FUN_00764030` ctor builds path `"%S%s"` from melee def name + `DAT_00a28904` suffix, then **`FUN_00989e00(out, path)`** and passes handle into gfx vfunc `+0x5c`.

Widely used: `CVOGTacArc_InitializeMesh` (`"NDTacArc.fx"`, tacarc dds), creature graphics, river/shadow FX strings, animation preloads — **global resource cache**, not equip-only.

---

## 2. Calling convention

| Slot | Role |
|------|------|
| **ECX** | resource manager / cache (this) |
| stack0 | `void **out` handle |
| stack1 | `char *name` |
| return | void (`*out` written) |

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00989e00_*`, `reconstructed-exact/FUN_00989e00.cpp` |
| Live decompile | Ghidra 2026-07-29 |
| Parent dual | `A_aa_004fe800` melee FX rebuild |
| Default | `DAT_00d1eac0` |
| CS offsets | `this+0x68` section, `this+0x80` enable flag |
| Hash helpers | `FUN_00989b60`, `FUN_00996c80`, `FUN_00466da0` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Empty → default global | **Yes** |
| Fast path `00989b60` | **Yes** |
| CS-gated map path | **Yes** |
| Write `*out` | **Yes** |
| No equip-specific branch | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name → handle resolve | **High** | body + string callers |
| Thread-safe optional CS | **High** | flag `+0x80` |
| Default empty handle | **High** | `DAT_00d1eac0` |
| Product manager class name | **Tentative** | inferred ResourceCache |
| Exact handle type | **Open** | first dword of node |

---

## 6. Gaps

1. Product type of `DAT_00d1eac0` / handle.
2. Map node layout for `FUN_00466da0`.
3. Runtime open.

**Verdict:** Named resource lookup sealed; equip is one consumer. **accept-with-gaps.**
