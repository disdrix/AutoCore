# Review A (reconstruction fidelity): `aa_00518df0` Skill_InsertCategoryCooldown

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518df0` |
| **VA** | `0x00518df0` |
| **Canonical name** | `Skill_InsertCategoryCooldown` |
| **Review date** | `2026-07-29` (dual residual seal; prior 2026-07-23 scaffold) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00518df0_Skill_InsertCategoryCooldown.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

High-level API `InsertCategoryCooldown(categoryId, durationMs)`: if `categoryId != -1`, builds entry `{key=categoryId, start=g_dwClientTickMs, duration=durationMs}`, lazy-gets owner map via `Skill_GetCategoryCooldownMap(ECX)`, then `Skill_CategoryCooldownMap_Insert` (insert-or-find). Sole static use: item-skill arm inside `Skill_ApplyStatusEffectLocal`.

```
if (cat != -1)
  Map_Insert(GetMap(owner_ECX), {cat, now_ms, durationMs})
// RET 0x8 stdcall; ECX implicit owner
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00518df0_Skill_InsertCategoryCooldown.md` (+ 2026-07-29 append) |
| Annotated | `raw/aa_00518df0_Skill_InsertCategoryCooldown.annotated.md` |
| Clean | `reconstructed-exact/Skill_InsertCategoryCooldown.cpp` |
| Function record | `functions/aa_00518df0_Skill_InsertCategoryCooldown.md` |
| Ghidra re-decompile | `0x00518df0` (2026-07-29) — body ≡ raw |
| Bytes | `read_memory` `0x00518df0`–`0x00518e2e` (`C2 08 00`; load `0x00b041cc`) |
| Global | `g_dwClientTickMs` @ `0x00b041cc` (`audit_globals_in_function`) |
| Callees | GetMap `0x00518d70` @ `0x00518e1c`; Map_Insert `0x0051d2f0` @ `0x00518e23` |
| Callers | `Skill_ApplyStatusEffectLocal` only @ `0x0051ac77` |
| Sibling duals | Map_Insert `A/B_aa_0051d2f0_*`; GetMap `A/B_aa_00518d70_*` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__stdcall` + **`RET 0x8`** | **High** | epilogue `C2 08 00` |
| Signature `(int cat, int durationMs)` | **High** | stack `[esp+1C]/`/`[esp+20]` after prolog |
| Early out `cat == -1` | **High** | `cmp esi,-1` / `je` |
| `start = g_dwClientTickMs` (`0x00b041cc`) | **High** | `A1 CC 41 B0 00` |
| Clock is client **ms** | **High** | global plate; peers use ms windows |
| Entry `{key,start,duration}` 12 B | **High** | stores + Map_Insert value layout |
| GetMap then Map_Insert order | **High** | call sites + `mov ecx,eax` |
| ECX = map owner (not skill) | **High** | phantom ECX + GetMap contract |
| Sole static caller ApplyStatusEffectLocal | **High** | xrefs 2026-07-29 |
| Plate “inserts/**updates**” | **Overstated** | Map_Insert equal-key is find-only |
| Cast-again uses this wrapper | **Falsified** | CastAgain → Map_Insert direct |
| Owner product type name | **Open** | class residual |
| Runtime / bit-exact | Open | matrix policy |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| `sub esp,0x14` / push esi / load cat | **Yes** |
| `cat==-1` → epilogue | **Yes** |
| load now @ `0x00b041cc`; pack start/dur/key | **Yes** |
| push entry, push outPair; GetMap; Map_Insert | **Yes** |
| `pop esi; add esp,0x14; ret 8` | **Yes** |
| No tooltip / grant / network | **Yes** |

---

## 5. Asm-sealed signature + pack

```c
struct CategoryCooldownEntry {
    int32_t  key;        // category id
    uint32_t startTick;  // g_dwClientTickMs
    int32_t  durationMs;
};

// __stdcall RET 8; ECX = map owner (host +0x6c)
void Skill_InsertCategoryCooldown(int nCategoryId, int nDurationMs);
```

---

## 6. Gaps / open

1. Map-owner product class name (cast-side host sealed by role, not C++ type).
2. Runtime capture of item-skill arm (optional; CF byte-sealed).
3. Server category-CD authority parity (out of unit).
4. Bit-exact / image diff (deferred).

**Verdict:** **accept-with-gaps** — ABI, early-out, pack, clock VA, callee order, sole caller **sealed High**; plate “update” **corrected** via Map_Insert dual; owner type name + runtime/diff remain.
